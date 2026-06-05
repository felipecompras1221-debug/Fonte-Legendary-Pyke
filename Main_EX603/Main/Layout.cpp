#include "stdafx.h"
#include "layout.h"
#include "Interface.h"
#include "Central.h"
#include "Defines.h"
#include "Import.h"
#include "CustomFont.h"
#include "Defines2.h"
#include <vector>
#include <string>
#include <fstream>
#include <windows.h> // Para DWORD, GetTickCount(), VK_F4, etc.
#include <cstdarg> // Para va_start e va_end

// Inicializa o gLayout e as variáveis de drag dentro da classe
CLayout::CLayout()
{
    // Construtor vazio. Caso necessite, adicione inicializações aqui.
}

CLayout gLayout;

void CLayout::UpdateLayoutPanelWindow()
{
    // Variável estática para controlar o estado da tecla F4
    static bool isF4Pressed = false;
    bool currentF4State = (GetAsyncKeyState(VK_F4) & 0x8000) != 0;

    if (currentF4State && !isF4Pressed)
    {
        // Alterna a flag de exibição do painel
        gInterface.Data[eLayout_MAIN].OnShow = !gInterface.Data[eLayout_MAIN].OnShow;

        // Adiciona o som ao abrir ou fechar com F4
        PlayBuffer(25, 0, 0);

        isF4Pressed = true;
    }
    else if (!currentF4State)
    {
        isF4Pressed = false;
    }
}

int CLayout::DrawToolTip(int X, int Y, LPCSTR Text, ...)
{
    // Como estamos tendo problemas com va_start/va_end, vamos usar uma solução mais simples
    // Definir diretamente a cor do texto para branco antes de chamar pDrawToolTip
    pSetTextColor(pTextThis(), 255, 255, 255, 255); // Branco brilhante
    
    // Desenha o tooltip diretamente com o texto fornecido
    int result = pDrawToolTip(X, Y, Text);
    
    return result;
}

// Variáveis globais para controle de páginas
int currentPage = 0;
int maxPages = 5; // Número total de páginas disponíveis
DWORD lastButtonClickTime = 0; // Tempo do último clique nos botões
const DWORD clickDelay = 300; // Delay entre cliques em milissegundos

// Variáveis globais para controle do drag e da posição do painel
bool   m_isDragging = false;
POINT  m_dragStartPoint;
float m_windowPosX = (MAX_WIN_WIDTH - 230.0f) / 2;
float m_windowPosY = (MAX_WIN_HEIGHT - 240.0f) / 2;

// Variável para controlar o tempo do último clique no botão de menu
DWORD lastMenuButtonClickTime = 0;
const DWORD menuClickDelay = 300; // Delay entre cliques em milissegundos

// Variável para controlar o tempo do último clique no botão de opções
DWORD lastOptionButtonClickTime = 0;
const DWORD optionClickDelay = 300; // Delay entre cliques em milissegundos

// ID do objeto de interface para o botão de menu
short eLayoutButtonMenu = 12350; // Usando um ID não usado
// ID do objeto de interface para o botão de opções
short eLayoutButtonOption = 12351; // Usando um ID não usado

void CLayout::DrawLayoutPanelWindow()
{
    // Se o painel não estiver para ser exibido, sai da função
    if (!gInterface.Data[eLayout_MAIN].OnShow)
        return;

    // Garante o foco do cursor
    pSetCursorFocus = true;

    // Variáveis para controle de clique e tempo
    bool isLeftButtonDown = (GetAsyncKeyState(VK_LBUTTON) & 0x8000) != 0;
    DWORD currentTime = GetTickCount();

    // Dimensões fixas do painel
    const float MainWidth = 230.0f;
    const float MainHeight = 240.0f;

    // Lógica para drag and drop
    if (pCheckMouseOver(m_windowPosX, m_windowPosY, MainWidth, MainHeight) || m_isDragging)
    {
        if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
        {
            if (!m_isDragging)
            {
                m_isDragging = true;
                m_dragStartPoint.x = pCursorX;
                m_dragStartPoint.y = pCursorY;
            }
            else
            {
                float deltaX = pCursorX - m_dragStartPoint.x;
                float deltaY = pCursorY - m_dragStartPoint.y;

                m_windowPosX += deltaX;
                m_windowPosY += deltaY;

                if (m_windowPosX < 0)
                    m_windowPosX = 0;
                else if (m_windowPosX > MAX_WIN_WIDTH - MainWidth)
                    m_windowPosX = MAX_WIN_WIDTH - MainWidth;

                if (m_windowPosY < 0)
                    m_windowPosY = 0;
                else if (m_windowPosY > MAX_WIN_HEIGHT - MainHeight)
                    m_windowPosY = MAX_WIN_HEIGHT - MainHeight;

                m_dragStartPoint.x = pCursorX;
                m_dragStartPoint.y = pCursorY;
            }
        }
        else
        {
            m_isDragging = false;
        }
    }
    else
    {
        m_isDragging = false;
    }

    // Desenha o painel flutuante na posição atual
    gCentral.PrintDropBox(m_windowPosX, m_windowPosY, MainWidth, MainHeight, 0, 0);

    // Define a posição base para o texto
    float StartX = m_windowPosX;
    float StartY = m_windowPosY;

    // --- Botão de menu ---
    // Mostrar o botão apenas na página 5 (índice 4)
    if (currentPage == 4)
    {
        // Definindo as dimensões e posição do botão menu
        float menuButtonWidth = 107.1f; // Mesma largura do botão Menu Option
        float menuButtonHeight = 29.0f; // Mesma altura do botão Menu Option
        float menuButtonX = m_windowPosX + (MainWidth / 2) - (menuButtonWidth / 2);
        float menuButtonY = m_windowPosY + 5.0f; // Posicionado mais acima

        // Vinculando o objeto de botão de menu (apenas uma vez)
        static bool buttonBound = false;
        if (!buttonBound) {
            gInterface.BindObject(eLayoutButtonMenu, 0x7A5E, menuButtonWidth, menuButtonHeight, -1, -1);
            gInterface.BindObject(eLayoutButtonOption, 0x7A5E, menuButtonWidth, menuButtonHeight, -1, -1);
            buttonBound = true;
        }

        // Desenhando o botão do menu
        bool isHovered = pCheckMouseOver(menuButtonX, menuButtonY, menuButtonWidth, menuButtonHeight);

        // Verificando se está sobre o botão
        if (isHovered)
        {
            if (isLeftButtonDown && (currentTime - lastMenuButtonClickTime > menuClickDelay))
            {
                // Desenhando o botão com estilo de clique
                pDrawButton(0x7A5E, menuButtonX, menuButtonY, menuButtonWidth, menuButtonHeight, 0, 58);

                // Marca o tempo do clique
                lastMenuButtonClickTime = currentTime;

                // Reproduz som ao clicar
                PlayBuffer(25, 0, 0);

                // Fecha o painel de layout
                //gInterface.Data[eLayout_MAIN].OnShow = false;

                // aqui abre menu option
                //if (!gInterface.CheckMenuWindow())
                //{
                //    gInterface.CloseCustomWindow();
                //    gInterface.OpenMenuWindow();
                //}
            }
            else
            {
                // Desenhando o botão com estilo de hover
                pDrawButton(0x7A5E, menuButtonX, menuButtonY, menuButtonWidth, menuButtonHeight, 0, 29);
                this->DrawToolTip(menuButtonX + 5, menuButtonY - 15, "Abrir Menu");
            }
        }
        else
        {
            // Desenhando o botão normal
            pDrawButton(0x7A5E, menuButtonX, menuButtonY, menuButtonWidth, menuButtonHeight, 0, 0);
        }

        // Desenha o texto "MENU" no botão
        pSetTextColor(pTextThis(), 255, 255, 255, 255); // Define a cor do texto como branco brilhante
        gInterface.DrawFormat(eWhite, menuButtonX, menuButtonY + 9, menuButtonWidth, 3, "MENU");

        // ----- Botão Option -----
        // Posicionando o botão Option abaixo do botão Menu
        float optionButtonWidth = 107.1f;
        float optionButtonHeight = 29.0f;
        float optionButtonX = m_windowPosX + (MainWidth / 2) - (optionButtonWidth / 2);
        float optionButtonY = menuButtonY + menuButtonHeight + 5.0f; // 5 pixels abaixo do botão menu

        // Desenhando o botão de opções
        bool isOptionHovered = pCheckMouseOver(optionButtonX, optionButtonY, optionButtonWidth, optionButtonHeight);

        // Verificando se está sobre o botão
        if (isOptionHovered)
        {
            if (isLeftButtonDown && (currentTime - lastOptionButtonClickTime > optionClickDelay))
            {
                // Desenhando o botão com estilo de clique
                pDrawButton(0x7A5E, optionButtonX, optionButtonY, optionButtonWidth, optionButtonHeight, 0, 58);

                // Marca o tempo do clique
                lastOptionButtonClickTime = currentTime;

                // Reproduz som ao clicar
                PlayBuffer(25, 0, 0);

                // Aqui você pode adicionar a funcionalidade que deseja quando o botão for clicado
                // Por exemplo, abrir uma janela de configurações ou opções
                // Por enquanto, apenas fecha o layout como exemplo
                //gInterface.Data[eLayout_MAIN].OnShow = false;
            }
            else
            {
                // Desenhando o botão com estilo de hover
                pDrawButton(0x7A5E, optionButtonX, optionButtonY, optionButtonWidth, optionButtonHeight, 0, 29);
                this->DrawToolTip(optionButtonX + 5, optionButtonY - 15, "Configurações");
            }
        }
        else
        {
            // Desenhando o botão normal
            pDrawButton(0x7A5E, optionButtonX, optionButtonY, optionButtonWidth, optionButtonHeight, 0, 0);
        }

        // Desenha o texto "OPTION" no botão
        pSetTextColor(pTextThis(), 255, 255, 255, 255); // Define a cor do texto como branco brilhante
        gInterface.DrawFormat(eWhite, optionButtonX, optionButtonY + 9, optionButtonWidth, 3, "OPTION");
    }

    // Cria vetores de linhas de texto para cada página

    // Página 1
    std::vector<std::string> textos1;
    textos1.push_back("SEJA BEM VINDO AO MUONLINE");
    textos1.push_back("O continente de MU era glorioso e vasto,");
    textos1.push_back("Quando Kundun surgiu, trazendo o caos mortal.");
    textos1.push_back("Heróis lutaram com força e magia.");
    textos1.push_back("Criaturas sombrias espalharam terror.");

    // Página 2
    std::vector<std::string> textos2;
    textos2.push_back("GUIA DE CLASSES");
    textos2.push_back("SM: Mestre da magia elemental.");
    textos2.push_back("BK: Guerreiro poderoso em combate corpo a corpo.");
    textos2.push_back("Elf: Arqueira ágil com habilidades de suporte.");
    textos2.push_back("MG: Híbrido de força física e poderes mágicos.");
    textos2.push_back("as trevas estavam corruptas");

    // Página 3
    std::vector<std::string> textos3;
    textos3.push_back("MAPAS DE MU ONLINE");
    textos3.push_back("Lorencia: Cidade inicial e principal.");
    textos3.push_back("Noria: Lar dos elfos e seres másticos.");
    textos3.push_back("Davias: Deserto habitado por criaturas perigosas.");
    textos3.push_back("Atlans: Reino subaquático de monstros exóticos.");
    textos3.push_back("as vezes podemos alcançar");

    // Página 4
    std::vector<std::string> textos4;
    textos4.push_back("EVENTOS ESPECIAIS");
    textos4.push_back("Blood Castle: Desafie os guardiões.");
    textos4.push_back("Devil Square: Arena de monstros.");
    textos4.push_back("Chaos Castle: Sobreviva contra monstros.");
    textos4.push_back("Golden Invasion: Lute contra monstros dourados.");
    textos4.push_back("venha vamos correr para alcançar");

    // Página 5
    std::vector<std::string> textos5;

    std::vector<std::vector<std::string>> textosPages;
    textosPages.push_back(textos1);
    textosPages.push_back(textos2);
    textosPages.push_back(textos3);
    textosPages.push_back(textos4);
    textosPages.push_back(textos5);

    // Vetor com os tamanhos (em pontos) para cada linha
    std::vector<int> fontSizes;
    fontSizes.push_back(20);
    fontSizes.push_back(16);
    fontSizes.push_back(16);
    fontSizes.push_back(16);
    fontSizes.push_back(16);

    // Para este exemplo, as linhas da página serão sempre desenhadas com "Segoe UI" (ou outra fonte caso desejado)
    // Se for necessário utilizar fontes diferentes para cada linha, crie um vetor adicional (veja exemplos anteriores)

    // Define o espaçamento vertical entre as linhas
    float linhaAltura = 30.0f;

    // Escolhe o texto da página atual
    std::vector<std::string> textos = textosPages[currentPage];

    // Para cada linha, cria e aplica uma fonte personalizada com o tamanho correspondente e desenha o texto
    for (size_t i = 0; i < textos.size(); i++)
    {
        HFONT hCustomFont = CreateFontA(
            -fontSizes[i],   // Tamanho da fonte (em pontos)
            0,               // Largura: ajuste automático
            0,               // Escapamento
            0,               // Orientação
            FW_BOLD,         // Peso: negrito
            FALSE,           // Não itálico
            FALSE,           // Sem sublinhado
            FALSE,           // Sem tachado
            DEFAULT_CHARSET,
            OUT_TT_PRECIS,
            CLIP_DEFAULT_PRECIS,
            CLEARTYPE_QUALITY,
            DEFAULT_PITCH | FF_DONTCARE,
            "Segoe UI"       // Nome da fonte
        );

        if (hCustomFont)
        {
            pSetFont(pTextThis(), (int)hCustomFont);
            pSetBkColor(pTextThis(), 0, 0, 0, 0); // Define a cor de fundo como transparente
            pSetTextColor(pTextThis(), 255, 255, 255, 255); // Define a cor do texto como branco brilhante
            pDrawText(pTextThis(), StartX - 16, StartY + 10 + i * linhaAltura,
                (LPCTSTR)textos[i].c_str(), 260, 0, (LPINT)3, 0);
            DeleteObject(hCustomFont);
        }
    }

    // Botões de navegação (avançar e voltar)
    float buttonWidth = 20.0f;
    float buttonHeight = 20.0f;

    float backButtonX = m_windowPosX + 10.0f;
    float backButtonY = m_windowPosY + MainHeight - 30.0f;

    float forwardButtonX = m_windowPosX + MainWidth - 30.0f;
    float forwardButtonY = m_windowPosY + MainHeight - 30.0f;

    // Botão de voltar (se não estiver na primeira página)
    if (currentPage > 0)
    {
        gInterface.DrawGUI(eLayout_BACK, backButtonX, backButtonY);

        if (pCheckMouseOver(backButtonX, backButtonY, buttonWidth, buttonHeight))
        {
            this->DrawToolTip(backButtonX + 5, backButtonY - 15, "Anterior");

            if (isLeftButtonDown && (currentTime - lastButtonClickTime > clickDelay))
            {
                currentPage--;
                lastButtonClickTime = currentTime;
                PlayBuffer(25, 0, 0);
            }
        }
    }

    // Botão de avançar (se não estiver na última página)
    if (currentPage < maxPages - 1)
    {
        gInterface.DrawGUI(eLayout_FORWARD, forwardButtonX, forwardButtonY);

        if (pCheckMouseOver(forwardButtonX, forwardButtonY, buttonWidth, buttonHeight))
        {
            this->DrawToolTip(forwardButtonX + 5, forwardButtonY - 15, "Próximo");

            if (isLeftButtonDown && (currentTime - lastButtonClickTime > clickDelay))
            {
                currentPage++;
                lastButtonClickTime = currentTime;
                PlayBuffer(25, 0, 0);
            }
        }
    }

    // Desenha o indicador de página com uma fonte fixa para não ser alterado ao passar o mouse sobre as setas
    HFONT hFixedFont = CreateFontA(
        -16,                     // Tamanho fixo da fonte
        0,
        0,
        0,
        FW_BOLD,
        FALSE,
        FALSE,
        FALSE,
        DEFAULT_CHARSET,
        OUT_TT_PRECIS,
        CLIP_DEFAULT_PRECIS,
        CLEARTYPE_QUALITY,
        DEFAULT_PITCH | FF_DONTCARE,
        "Segoe UI"              // Fonte fixa ("Segoe UI")
    );

    if (hFixedFont)
    {
        pSetFont(pTextThis(), (int)hFixedFont);
        char pageText[50];
        sprintf_s(pageText, "Página %d/%d", currentPage + 1, maxPages);
        pSetBkColor(pTextThis(), 0, 0, 0, 0); // Define a cor de fundo como transparente
        pSetTextColor(pTextThis(), 255, 255, 255, 255); // Define a cor do texto como branco brilhante
        pDrawText(pTextThis(), m_windowPosX + MainWidth / 2 - 40, m_windowPosY + MainHeight - 30,
            (LPCTSTR)pageText, 80, 0, (LPINT)3, 0);
        DeleteObject(hFixedFont);
    }

    // --- Botão de fechar ---
    float closeButtonX = m_windowPosX + MainWidth - 20;
    float closeButtonY = m_windowPosY - 10;

    gInterface.DrawGUI(eMenu_CLOSE, closeButtonX, closeButtonY);

    if (pCheckMouseOver(closeButtonX, closeButtonY, 36, 29))
    {
        this->DrawToolTip(closeButtonX + 5, closeButtonY + 25, "Close");
    }

    if (pCheckMouseOver(closeButtonX, closeButtonY, 36, 29) && (GetAsyncKeyState(VK_LBUTTON) & 0x8000))
    {
        // Adiciona o som ao fechar com o botão de fechar
        PlayBuffer(25, 0, 0);

        gInterface.Data[eLayout_MAIN].OnShow = false;
    }
}
