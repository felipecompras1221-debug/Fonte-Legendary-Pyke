#include "stdafx.h"
#include "screen.h"
#include "Interface.h"
#include "Defines.h"
#include "Central.h"
#include "Import.h"
#include "CustomFont.h"
#include "Defines2.h"
#include <vector>
#include <string>
#include <windows.h> // Para DWORD e GetTickCount()
#include <fstream>

// Velocidade do slider (em pixels por frame)
const float sliderSpeed = 10.0f;

// Delay para iniciar a digitação do texto completo (em milissegundos)
const DWORD delayTextoCompleto = 2020; // 2 segundos

Cscreen::Cscreen()
{
}

Cscreen gscreen;

// Variável para definir quantas vezes a janela deve abrir
int maxDisplays = 2; // Altere este valor para decidir quantas vezes a janela abre

// Variável para manter o controle de quantas vezes a janela foi exibida
int displayCount = 0;

// Função para ler o contador de um arquivo
void ReadDisplayCount()
{
    std::ifstream infile("Data//display_count.dat");
    if (infile.is_open())
    {
        infile >> displayCount;
        infile.close();
    }
}

// Função para escrever o contador em um arquivo
void WriteDisplayCount()
{
    std::ofstream outfile("Data//display_count.dat", std::ios::trunc);
    if (outfile.is_open())
    {
        outfile << displayCount;
        outfile.close();
    }
}

// Variáveis globais existentes...
bool isDragging = false;
POINT dragStartPoint;
// Inicializa a posição fora da tela para que ela deslize da esquerda para a direita.
float windowPosX = -300.0f;
float windowPosY = (MAX_WIN_HEIGHT / 2) - (390.0f / 2);

std::vector<std::string> textos;
size_t currentLine = 0;
size_t indiceTexto = 0;
DWORD tempoAnterior = 0;
DWORD intervaloDigitacao = 50; // Intervalo entre cada letra (em milissegundos)

// Controle da animação de fechamento
bool animationFinished = false;
DWORD animationEndTime = 0;
DWORD displayDuration = 6300; // Tempo que a janela permanece visível após a animação (em milissegundos)

void Cscreen::DrawPanelWindow()
{
    // Variável local para garantir que o slider seja executado somente uma vez.
    static bool sliderCompleted = false;

    // Variáveis estáticas para controlar o atraso da digitação
    static bool textDelayComplete = false;
    static DWORD panelStartTime = 0;

    // Ler o contador atual ao iniciar o jogo.
    static bool initialized = false;
    if (!initialized)
    {
        // Ler o contador de exibição do arquivo.
        ReadDisplayCount();

        // Verificar se a janela já foi exibida o número máximo de vezes.
        if (displayCount >= maxDisplays)
        {
            // Não exibir a janela novamente.
            gInterface.Data[ePanelWindow].OnShow = false;
            return;
        }

        // Exibir a janela.
        gInterface.Data[ePanelWindow].OnShow = true;

        // Inicializar os textos.
        textos.clear();
        textos.push_back("O continente de MU era glorioso e vasto,");
        textos.push_back("Quando Kundun surgiu, trazendo o caos mortal.");
        textos.push_back("Heróis lutaram com força e magia.");
        textos.push_back("Criaturas sombrias espalharam terror.");
        textos.push_back("Agora a guerra eterna decide o destino final.");
        textos.push_back("Decida seu lado gens: Vanert ou Duprian.");

        // Resetar as variáveis de controle para a digitação.
        currentLine = 0;
        indiceTexto = 0;
        tempoAnterior = GetTickCount();
        animationFinished = false;
        animationEndTime = 0;

        // Inicia o timer do atraso
        panelStartTime = GetTickCount();
        textDelayComplete = false;

        initialized = true;
    }

    // Se a janela não estiver visível, retorna.
    if (!gInterface.Data[ePanelWindow].OnShow)
    {
        return;
    }

    pSetCursorFocus = true; // Certifique-se de que esta variável está corretamente declarada.

    // Atualiza a posição para o slider da esquerda para a direita somente uma vez.
    float destPosX = (MAX_WIN_WIDTH / 2) - (300.0f / 2);
    if (!isDragging && !sliderCompleted && windowPosX < destPosX)
    {
        windowPosX += sliderSpeed;
        if (windowPosX >= destPosX)
        {
            windowPosX = destPosX;
            sliderCompleted = true;
        }
    }

    float MainWidth = 300.0f;
    float MainHeight = 350.0f;
    float StartX = windowPosX;
    float StartY = windowPosY;
    float StartBody = StartY + 50.0f;

    // Fechar a janela após o tempo definido e incrementar o contador.
    if (animationFinished)
    {
        DWORD tempoAtual = GetTickCount();
        if (tempoAtual - animationEndTime > displayDuration)
        {
            // Fecha a janela.
            gInterface.Data[ePanelWindow].OnShow = false;

            // Incrementa o contador e salva no arquivo.
            displayCount++;
            WriteDisplayCount();
        }
    }

    // Lógica para arrastar a janela.
    if (pCheckMouseOver(StartX, StartY, MainWidth, MainHeight) || isDragging)
    {
        if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
        {
            if (!isDragging)
            {
                isDragging = true;
                dragStartPoint.x = pCursorX;
                dragStartPoint.y = pCursorY;
            }
            else
            {
                float deltaX = pCursorX - dragStartPoint.x;
                float deltaY = pCursorY - dragStartPoint.y;

                windowPosX += deltaX;
                windowPosY += deltaY;

                // Limita a posição X dentro dos limites da tela.
                if (windowPosX < 0)
                    windowPosX = 0;
                else if (windowPosX > MAX_WIN_WIDTH - MainWidth)
                    windowPosX = MAX_WIN_WIDTH - MainWidth;

                // Limita a posição Y dentro dos limites da tela.
                if (windowPosY < 0)
                    windowPosY = 0;
                else if (windowPosY > MAX_WIN_HEIGHT - MainHeight)
                    windowPosY = MAX_WIN_HEIGHT - MainHeight;

                dragStartPoint.x = pCursorX;
                dragStartPoint.y = pCursorY;
            }
        }
        else
        {
            isDragging = false;
        }
    }
    else
    {
        isDragging = false;
    }

    // Desenha a área principal.
    gCentral.PrintDropBox(StartX, StartY, MainWidth, MainHeight, 0, 0);

    // Configurar a fonte personalizada com qualidade de anti-aliasing.
    HFONT hCustomFont = CreateFontA(
        -20,                // Altura da fonte (use negativo para altura em pontos)
        0,                  // Largura (0 para calcular automaticamente)
        0,                  // Escapamento
        0,                  // Orientação
        FW_BOLD,            // Peso da fonte (negrito)
        FALSE,              // Itálico
        FALSE,              // Sublinhado
        FALSE,              // Tachado
        DEFAULT_CHARSET,    // Conjunto de caracteres padrão
        OUT_TT_PRECIS,      // Precisão de saída para fontes TrueType
        CLIP_DEFAULT_PRECIS,
        CLEARTYPE_QUALITY,  // Qualidade de fonte com ClearType
        DEFAULT_PITCH | FF_DONTCARE,
        "Segoe UI"          // Nome da fonte (use uma fonte TrueType)
    );

    if (hCustomFont)
    {
        // Aplicar a fonte personalizada.
        pSetFont(pTextThis(), (int)hCustomFont);
        // Definir a cor do texto (branco).
        pSetTextColor(pTextThis(), 255, 255, 255, 255);

        // Posições iniciais do texto.
        float posX = StartX + 20.0f;
        float posY = StartY + 120.0f;
        float linhaAltura = 20.0f;

        // Verifica se já passou o tempo determinado para iniciar a digitação
        if (!textDelayComplete)
        {
            if (GetTickCount() - panelStartTime >= delayTextoCompleto)
            {
                textDelayComplete = true;
                // Reinicia o timer da digitação
                tempoAnterior = GetTickCount();
            }
        }

        // Loop para cada linha de texto com efeito de digitação.
        for (size_t i = 0; i < textos.size(); ++i)
        {
            if (i < currentLine)
            {
                // Linha já foi completamente digitada: mostrar a linha completa.
                pDrawText(pTextThis(), posX, posY + (i * linhaAltura), (char*)textos[i].c_str(), 280, 0, (LPINT)0, 0);
            }
            else if (i == currentLine)
            {
                // Se o atraso para digitar ainda não foi concluído, não atualiza a digitação.
                if (textDelayComplete)
                {
                    DWORD tempoAtual = GetTickCount();
                    if (tempoAtual - tempoAnterior > intervaloDigitacao && indiceTexto < textos[i].length())
                    {
                        indiceTexto++;
                        tempoAnterior = tempoAtual;
                    }
                }

                // Obter a substring atual a ser exibida.
                std::string textoParcial = textos[i].substr(0, indiceTexto);
                // Desenhar o texto parcial.
                pDrawText(pTextThis(), posX, posY + (i * linhaAltura), (char*)textoParcial.c_str(), 280, 0, (LPINT)0, 0);

                // Se a linha foi completamente digitada, passa para a próxima.
                if (indiceTexto >= textos[i].length())
                {
                    currentLine++;
                    indiceTexto = 0;
                    tempoAnterior = GetTickCount(); // Resetar o tempo para a próxima linha

                    // Se todas as linhas foram digitadas, marca o final da animação.
                    if (currentLine >= textos.size())
                    {
                        animationFinished = true;
                        animationEndTime = GetTickCount();
                    }
                }
            }
        }

        // Liberar a fonte personalizada após o uso.
        DeleteObject(hCustomFont);
    }

    // Desenha uma mensagem de boas-vindas.
    CustomFont.DrawMultipleColor(CustomFont.FontSize20, (int)StartX + 20, (int)StartBody - 20,
        0x0, 0, 0, 10, "Seja bem-vindo ao Mu Archangel");

    // Desenha o título.
    pSetFont(pTextThis(), (int)pFontBigBold);
    pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0);
    pSetTextColor(pTextThis(), 240, 240, 240, 255);
    pDrawText(pTextThis(), StartX + 20, StartY + 90, "====== UM BREVE RESUMO ======", 260, 0, (LPINT)3, 0);

    // Desenha os divisores.
    pDrawGUI(71520, StartX + (MainWidth / 2) - 100.0f, StartBody + 35.0f, 200.0f, 1.0f);
    pDrawGUI(71520, StartX + (MainWidth / 2) - 100.0f, StartBody + 210.0f, 200.0f, 1.0f);

    // Fechar a janela após o tempo determinado.
    if (animationFinished)
    {
        DWORD tempoAtual = GetTickCount();
        if (tempoAtual - animationEndTime > displayDuration)
        {
            // Fecha a janela.
            gInterface.Data[ePanelWindow].OnShow = false;
        }
    }
}
