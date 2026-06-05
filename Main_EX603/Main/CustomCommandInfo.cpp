#include "StdAfx.h"
#include "CustomCommandInfo.h"
#include "Defines.h"
#include "Interface.h"
#include "Central.h"
#include "User.h"
// -------------------------------------------------------------------------------

CCustomCommandInfo gCustomCommandInfo;
// -------------------------------------------------------------------------------

CCustomCommandInfo::CCustomCommandInfo()
{
	this->Init();
}
// -------------------------------------------------------------------------------

CCustomCommandInfo::~CCustomCommandInfo()
{
	// ----
}
// -------------------------------------------------------------------------------

void CCustomCommandInfo::Init() // OK
{
	for(int n=0;n < MAX_CUSTOM_COMMAND;n++)
	{
		this->m_CustomCommandInfo[n].Index = -1;
	}
	this->Count = 0;
	this->Page = 0;
}

void CCustomCommandInfo::Load(CUSTOM_COMMAND_INFO* info) // OK
{
	for(int n=0;n < MAX_CUSTOM_COMMAND;n++)
	{
		this->SetInfo(info[n]);
	}
}

void CCustomCommandInfo::SetInfo(CUSTOM_COMMAND_INFO info) // OK
{
	if(info.Index < 0 || info.Index >= MAX_CUSTOM_COMMAND)
	{
		return;
	}
	this->Count = info.Index+1;
	this->m_CustomCommandInfo[info.Index] = info;
}

CUSTOM_COMMAND_INFO* CCustomCommandInfo::GetInfo(int index) // OK
{
	if(index < 0 || index >= MAX_CUSTOM_COMMAND)
	{
		return 0;
	}

	if(this->m_CustomCommandInfo[index].Index != index)
	{
		return 0;
	}

	return &this->m_CustomCommandInfo[index];
}

int next = 0;
int prev = 0;

// Variáveis estáticas para controlar o estado do clique nas setas
static bool nextArrowClicked = false;
static bool prevArrowClicked = false;

void CCustomCommandInfo::DrawCommandWindow()
{
    if (!gInterface.Data[eCommand_MAIN].OnShow)
    {
        return;
    }

    pSetCursorFocus = true; // Certifique-se de que esta variável está corretamente declarada

    // ----
    float MainWidth = 230.0f;
    float MainHeight = 320.0f;

    // Variáveis estáticas para manter o estado entre as chamadas
    static bool isDragging = false;
    static POINT dragStartPoint;
    static float windowPosX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
    static float windowPosY = ((MAX_WIN_HEIGHT - 51) / 2) - (MainHeight / 2);

    float StartX = windowPosX;
    float StartY = windowPosY;
    float StartBody = StartY;
    float MainCenter = StartX + (MainWidth / 3);
    float ButtonX = MainCenter - (29.0f / 2);
    // ----

    DWORD Color = eGray100;

    // Variáveis para detectar se o mouse está sobre componentes interativos
    bool isOverInteractiveComponent = false;

    // Definição das coordenadas e dimensões das setas
    float arrowWidth = 20.0f;  // Largura da seta
    float arrowHeight = 20.0f; // Altura da seta

    // Ajuste das posições das setas
    float nextArrowX = StartX + MainWidth - arrowWidth - 5.0f; // Seta "próxima" a 5 pixels da borda direita
    float nextArrowY = StartY + 80.0f;

    float prevArrowX = StartX - 5.0f; // Seta "anterior" a 5 pixels à esquerda da janela
    float prevArrowY = StartY + 80.0f;

    // Garante que prevArrowX não seja menor que zero (opcional)
    if (prevArrowX < 0)
        prevArrowX = 0;

    // Obtenha o estado atual dos botões do mouse
    bool leftMouseButtonDown = (GetAsyncKeyState(VK_LBUTTON) & 0x8000) != 0;

    // Verifica se o mouse está sobre as setas
    if (pCheckMouseOver(nextArrowX, nextArrowY, arrowWidth, arrowHeight))
    {
        isOverInteractiveComponent = true;

        if (!leftMouseButtonDown && nextArrowClicked)
        {
            next = 1;
            nextArrowClicked = false;
        }
        else if (leftMouseButtonDown && !nextArrowClicked)
        {
            nextArrowClicked = true;
        }
    }
    else
    {
        nextArrowClicked = false;
    }

    if (pCheckMouseOver(prevArrowX, prevArrowY, arrowWidth, arrowHeight))
    {
        isOverInteractiveComponent = true;

        if (!leftMouseButtonDown && prevArrowClicked)
        {
            prev = 1;
            prevArrowClicked = false;
        }
        else if (leftMouseButtonDown && !prevArrowClicked)
        {
            prevArrowClicked = true;
        }
    }
    else
    {
        prevArrowClicked = false;
    }

    // Lógica de arraste - captura em todo o layout da janela, exceto componentes interativos
    if ((pCheckMouseOver(StartX, StartY, MainWidth, MainHeight) && !isOverInteractiveComponent) || isDragging)
    {
        if (leftMouseButtonDown)
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

                // Limita a posição X dentro dos limites da tela
                if (windowPosX < 0)
                    windowPosX = 0;
                else if (windowPosX > MAX_WIN_WIDTH - MainWidth)
                    windowPosX = MAX_WIN_WIDTH - MainWidth;

                // Limita a posição Y dentro dos limites da tela
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

    // Atualiza a página se as setas forem clicadas
    if (next == 1)
    {
        this->Page++;
        next = 0; // Reseta a variável

        // Limita a página ao máximo disponível
        int maxPages = (this->Count + 24) / 25 - 1;
        if (this->Page > maxPages)
            this->Page = maxPages;
    }

    if (prev == 1)
    {
        this->Page--;
        prev = 0; // Reseta a variável

        // Impede que a página seja menor que zero
        if (this->Page < 0)
            this->Page = 0;
    }

    // Desenha a janela na posição atualizada
    gCentral.PrintDropBox(StartX, StartY, MainWidth, MainHeight, 0, 0);
    // ----
    gInterface.DrawFormat(eGold, (int)StartX + 10, (int)StartBody + 10, 210, 3, "Commands");

    // Divisor
    pDrawGUI(71520, StartX + (MainWidth / 2) - (200 / 2), StartY + 35, 200, 1);

    // Desenha as setas de navegação
    if (this->Page < ((this->Count + 24) / 25 - 1))
    {
        gInterface.DrawGUI(eNextCommand, nextArrowX, nextArrowY);
    }
    else
    {
        gInterface.ResetDrawIMG(eNextCommand);
    }

    if (this->Page > 0)
    {
        gInterface.DrawGUI(ePrevCommand, prevArrowX, prevArrowY);
    }
    else
    {
        gInterface.ResetDrawIMG(ePrevCommand);
    }

    for (int i = (25 * Page); i < (25 * Page) + 25; i++)
    {
        if (this->m_CustomCommandInfo[i].Index == -1)
        {
            continue;
        }

        switch (this->m_CustomCommandInfo[i].Color)
        {
        case 1: Color = eGold; break;
        case 2: Color = eWhite; break;
        case 3: Color = eOrange; break;
        case 4: Color = eRed2; break;
        case 5: Color = eExcellent; break;
        case 6: Color = eYellow; break;
        case 7: Color = eSocket; break;
        default: Color = eGold; break;
        }

        int x = i - (25 * Page);

        gInterface.DrawFormat(Color, (int)StartX + 18, (int)StartY + 50 + (x * 10), 100, 1, this->m_CustomCommandInfo[i].Command);

        pDrawColorText(this->m_CustomCommandInfo[i].Description, (int)StartX + 112, (int)StartY + 50 + (x * 10), 100, 0, Color, 0, 1);
    }

    // Divisor
    pDrawGUI(71520, StartX + (MainWidth / 2) - (200 / 2), StartY + 285, 200, 1);
}







void CCustomCommandInfo::OpenCommandWindow()
{

	if (gInterface.Data[eCommand_MAIN].OnShow == true)
	{
		gInterface.Data[eCommand_MAIN].OnShow = false;
		
		if(gProtect.m_MainInfo.CustomInterfaceType != 3 || gProtect.m_MainInfo.CustomInterfaceType != 4)
		{
			pSetCursorFocus = false;
		}
		return;
	}

	DWORD CurrentTick	= GetTickCount();
	DWORD Delay			= (CurrentTick - gInterface.Data[eRankPANEL_MAIN].EventTick);

	if(Delay < 1500 )
	{
		gInterface.Data[eCommand_MAIN].OnShow = false;
		return;
	}

	gInterface.CloseCustomWindow();
	gInterface.Data[eCommand_MAIN].EventTick = GetTickCount();
	gInterface.Data[eCommand_MAIN].OnShow = true;
	
	if(gProtect.m_MainInfo.CustomInterfaceType != 3 || gProtect.m_MainInfo.CustomInterfaceType != 4)
	{
		pSetCursorFocus = false;
	}

}

bool CCustomCommandInfo::EventCommandWindow_Close(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eCommand_CLOSE].EventTick);
	// ----
	if (!gInterface.Data[eCommand_MAIN].OnShow || !gInterface.IsWorkZone(eCommand_CLOSE))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eCommand_CLOSE].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eCommand_CLOSE].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eCommand_CLOSE].EventTick = GetTickCount();
	gInterface.Data[eCommand_MAIN].OnShow = false;
	
	if(gProtect.m_MainInfo.CustomInterfaceType != 3 || gProtect.m_MainInfo.CustomInterfaceType != 4)
	{
		pSetCursorFocus = false;
	}
	// ----
	return false;
}

bool CCustomCommandInfo::CommandNext(DWORD Event)
{
	DWORD CurrentTick	= GetTickCount();
	DWORD Delay			= (CurrentTick - gInterface.Data[eNextCommand].EventTick);
	DWORD Delay2		= (CurrentTick - gInterface.Data[ePrevCommand].EventTick);

	if( !gInterface.Data[eCommand_MAIN].OnShow  || next == -1)
	{
		return false;
	}
	
	if( !gInterface.IsWorkZone(eNextCommand))
	{
		return false;
	}

	if( Event == WM_LBUTTONDOWN )
	{
		gInterface.Data[eNextCommand].OnClick = true;
		return true;
	}


	if( Delay < 100 || Delay2 < 100 )
	{
		return false;
	}
	
	gInterface.Data[eNextCommand].OnClick = false;
	
	this->Page++;
	
	gInterface.Data[eNextCommand].EventTick = GetTickCount();
	

	return true;
}

bool CCustomCommandInfo::CommandPrev(DWORD Event)
{
	DWORD CurrentTick	= GetTickCount();
	DWORD Delay			= (CurrentTick - gInterface.Data[ePrevCommand].EventTick);
	DWORD Delay2		= (CurrentTick - gInterface.Data[eNextCommand].EventTick);

	if( !gInterface.Data[eCommand_MAIN].OnShow || prev == -1)
	{
		return false;
	}
	
	if( !gInterface.IsWorkZone(ePrevCommand) )
	{
		return false;
	}

	if( Event == WM_LBUTTONDOWN )
	{
		gInterface.Data[ePrevCommand].OnClick = true;
		return true;
	}

	if( Delay < 100 || Delay2 < 100 )
	{
		return false;
	}
	
	gInterface.Data[ePrevCommand].OnClick = false;
	
	gInterface.Data[ePrevCommand].EventTick = GetTickCount();

	this->Page--;
	
	return true;
}