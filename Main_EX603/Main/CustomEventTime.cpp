#include "stdafx.h"
#include "CustomEventTime.h"
#include "CustomMessage.h"
#include "Defines.h"
#include "HealthBar.h"
#include "Interface.h"
#include "Util.h"
#include "Object.h"
#include "Import.h"
#include "Central.h"

CCustomEventTime::CCustomEventTime()
{
}

CCustomEventTime gCustomEventTime;

void CCustomEventTime::Load(CUSTOM_EVENT_INFO* info) // OK
{
	for(int n=0;n < MAX_EVENTTIME;n++)
	{
		this->SetInfo(info[n]);
	}
}

void CCustomEventTime::SetInfo(CUSTOM_EVENT_INFO info) // OK
{
	if(info.Index < 0 || info.Index >= MAX_EVENTTIME)
	{
		return;
	}

	this->m_CustomEventInfo[info.Index] = info;
}

void CCustomEventTime::ClearCustomEventTime() // OK
{
	for(int n=0;n < MAX_EVENTTIME;n++)
	{
		gCustomEventTime[n].time = -1;
	}
	this->count				= 0;
	this->EventTimeEnable	= 0;
}

void CCustomEventTime::GCReqEventTime(PMSG_CUSTOM_EVENTTIME_RECV* lpMsg) // OK
{
	this->count = lpMsg->count;

	for(int n=0;n < lpMsg->count;n++)
	{
		CUSTOM_EVENTTIME_DATA* lpInfo = (CUSTOM_EVENTTIME_DATA*)(((BYTE*)lpMsg)+sizeof(PMSG_CUSTOM_EVENTTIME_RECV)+(sizeof(CUSTOM_EVENTTIME_DATA)*n));

		this->gCustomEventTime[n].index = lpInfo->index;
		this->gCustomEventTime[n].time = lpInfo->time;

		if (this->gCustomEventTime[n].index >= 28 && this->gCustomEventTime[n].time != -1) this->Arena = 1;
	}

	this->EventTimeEnable = 1;
}

bool CheckMouseIn(float x, float y, float width, float height)
{
    float mouseX = pCursorX;
    float mouseY = pCursorY;
    return (mouseX >= x && mouseX <= x + width && mouseY >= y && mouseY <= y + height);
}

int NextEvent = 0;
int PreventEvent = 0;

void CCustomEventTime::DrawEventTimePanelWindow()
{
    if (!gInterface.Data[eEventTimePANEL_MAIN].OnShow)
    {
        return;
    }

    pSetCursorFocus = true; // Certifique-se de que esta variável está corretamente declarada

    // Variáveis estáticas para controle de arraste e clique
    static bool isDragging = false;
    static float dragOffsetX = 0.0f;
    static float dragOffsetY = 0.0f;
    static bool wasLeftMouseButtonDown = false;

    // Variáveis estáticas para controle de tempo dos cliques nos botões
    static DWORD lastNextEventClickTime = 0;
    static DWORD lastPrevEventClickTime = 0;
    const DWORD clickDelay = 800; // Tempo mínimo entre cliques em milissegundos

    // Posição do mouse
    float mouseX = pCursorX;
    float mouseY = pCursorY;

    // Tamanho da janela
    float MainWidth = 230.0f;
    float MainHeight = 240.0f;

    // Posição inicial da janela (estática para manter entre chamadas)
    static float StartX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
    static float StartY = ((MAX_WIN_HEIGHT - 51) / 2) - (MainHeight / 2);

    float MainCenter = StartX + (MainWidth / 3);
    float ButtonX = MainCenter - (29.0f / 2);

    // Checar se o mouse está sobre a janela para iniciar o arraste
    if (CheckMouseIn(StartX, StartY, MainWidth, MainHeight))
    {
        if ((GetAsyncKeyState(VK_LBUTTON) & 0x8000) && !isDragging)
        {
            isDragging = true;
            dragOffsetX = mouseX - StartX;
            dragOffsetY = mouseY - StartY;
        }
    }

    // Atualizar posição da janela durante o arraste
    if (isDragging)
    {
        StartX = mouseX - dragOffsetX;
        StartY = mouseY - dragOffsetY;

        // Impedir que a janela saia da tela
        if (StartX < 0) StartX = 0;
        if (StartY < 0) StartY = 0;
        if (StartX + MainWidth > MAX_WIN_WIDTH) StartX = MAX_WIN_WIDTH - MainWidth;
        if (StartY + MainHeight > MAX_WIN_HEIGHT) StartY = MAX_WIN_HEIGHT - MainHeight;
    }

    // Parar o arraste quando o botão do mouse for liberado
    if (!(GetAsyncKeyState(VK_LBUTTON) & 0x8000))
    {
        isDragging = false;
    }

    // Desenhar a janela
    gCentral.PrintDropBox(StartX, StartY, MainWidth, MainHeight, 0, 0);

    DWORD Color = eGray100;

    // Variáveis para detectar cliques nos botões
    bool isLeftMouseButtonDown = (GetAsyncKeyState(VK_LBUTTON) & 0x8000);

    // Cálculo do número total de páginas
    int eventsPerPage = 14;
    int totalEvents = this->count;
    int MaxPages = (totalEvents + eventsPerPage - 1) / eventsPerPage;

    // Garantir que a página atual esteja dentro dos limites
    if (this->Page >= MaxPages)
    {
        this->Page = MaxPages - 1;
    }
    if (this->Page < 0)
    {
        this->Page = 0;
    }

    DWORD currentTime = GetTickCount();

    // Botão de próximo evento
    float nextEventX = StartX + MainWidth - 38;
    float nextEventY = StartY + 110;

    if (this->Page < MaxPages - 1)
    {
        gInterface.DrawGUI(eNextEvent, nextEventX, nextEventY);

        // Tornar o botão clicável
        if (CheckMouseIn(nextEventX, nextEventY, gInterface.Data[eNextEvent].Width, gInterface.Data[eNextEvent].Height))
        {
            // Mudar o cursor para indicar que é clicável
            pSetCursorFocus = true;

            // Verificar se houve um clique (transição de pressionado para liberado)
            if (wasLeftMouseButtonDown && !isLeftMouseButtonDown)
            {
                // Verificar se o tempo mínimo entre cliques já passou
                if (currentTime - lastNextEventClickTime >= clickDelay)
                {
                    // Ação ao clicar no botão
                    this->Page++;
                    lastNextEventClickTime = currentTime;
                }
            }
        }
        else
        {
            // Resetar o tempo se o mouse não estiver sobre o botão
            lastNextEventClickTime = currentTime;
        }
    }
    else
    {
        gInterface.ResetDrawIMG(eNextEvent);
    }

    // Botão de evento anterior
    float prevEventX = StartX + 10;
    float prevEventY = StartY + 110;

    if (this->Page > 0)
    {
        gInterface.DrawGUI(ePrevEvent, prevEventX, prevEventY);

        // Tornar o botão clicável
        if (CheckMouseIn(prevEventX, prevEventY, gInterface.Data[ePrevEvent].Width, gInterface.Data[ePrevEvent].Height))
        {
            // Mudar o cursor para indicar que é clicável
            pSetCursorFocus = true;

            // Verificar se houve um clique (transição de pressionado para liberado)
            if (wasLeftMouseButtonDown && !isLeftMouseButtonDown)
            {
                // Verificar se o tempo mínimo entre cliques já passou
                if (currentTime - lastPrevEventClickTime >= clickDelay)
                {
                    // Ação ao clicar no botão
                    this->Page--;
                    lastPrevEventClickTime = currentTime;
                }
            }
        }
        else
        {
            // Resetar o tempo se o mouse não estiver sobre o botão
            lastPrevEventClickTime = currentTime;
        }
    }
    else
    {
        gInterface.ResetDrawIMG(ePrevEvent);
    }

    // Atualizar o estado do botão esquerdo do mouse
    wasLeftMouseButtonDown = isLeftMouseButtonDown;

    // Título da janela
    gInterface.DrawFormat(eGold, (int)StartX + 10, (int)StartY + 10, 210, 3, "Events");

    // Linha divisória
    pDrawGUI(71520, StartX + (MainWidth / 2) - (200 / 2), StartY + 35, 200, 1); //-- Divisor

    if (this->EventTimeEnable == 1)
    {
        gInterface.DrawFormat(eGold, StartX + 60, StartY + 47, 52, 1, "Event:");
        gInterface.DrawFormat(eGold, StartX + 145, StartY + 47, 52, 1, "Time:");

        if ((GetTickCount() - this->EventTimeTickCount) > 1000)
        {
            for (int i = 0; i < this->count; i++)
            {
                if (this->gCustomEventTime[i].time > 0)
                {
                    this->gCustomEventTime[i].time -= 1;
                }
            }
            this->EventTimeTickCount = GetTickCount();
        }

        char text1[20];
        char text2[30];
        int totalseconds;
        int hours;
        int minutes;
        int seconds;
        int days;

        int line = 0;

        int startEvent = eventsPerPage * this->Page;
        int endEvent = startEvent + eventsPerPage;

        if (endEvent > this->count)
        {
            endEvent = this->count;
        }

        for (int i = startEvent; i < endEvent; i++)
        {
            if (this->gCustomEventTime[i].time <= -1)
            {
                // Evento desabilitado
                continue;
            }
            else if (this->gCustomEventTime[i].time == 0)
            {
                sprintf(text2, "Online");
            }
            else
            {
                totalseconds = this->gCustomEventTime[i].time;
                hours = totalseconds / 3600;
                minutes = (totalseconds / 60) % 60;
                seconds = totalseconds % 60;

                if (hours > 23)
                {
                    days = hours / 24;
                    sprintf(text2, "%d day(s)+", days);
                }
                else
                {
                    sprintf(text2, "%02d:%02d:%02d", hours, minutes, seconds);
                }
            }

            if (this->gCustomEventTime[i].time <= -1)
            {
                Color = eRed2;
            }
            else if (this->gCustomEventTime[i].time == 0 || this->gCustomEventTime[i].time < 300)
            {
                Color = eExcellent;
            }
            else
            {
                Color = eYellow;
            }

            gInterface.DrawFormat(eWhite, StartX + 40, StartY + 65 + line, 100, 1, this->m_CustomEventInfo[i].Name);
            gInterface.DrawFormat(Color, StartX + 145, StartY + 65 + line, 52, 1, text2);

            line += 12;
        }
    }
    else
    {
        // Animação de carregamento
        const char* loadingTexts[] = { "Loading .", "Loading ..", "Loading ...", "Loading ....", "Loading ....." };
        int loadingStage = this->EventTimeLoad % 5;
        gInterface.DrawFormat(eGold, StartX + 60, StartY + 120, 100, 1, loadingTexts[loadingStage]);
        this->EventTimeLoad++;
    }

    // Linha divisória inferior
    pDrawGUI(71520, StartX + (MainWidth / 2) - (200 / 2), StartY + 210, 200, 1); //-- Divisor
}


bool CCustomEventTime::EventEventTimeWindow_Close(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eEventTime_CLOSE].EventTick);
	// ----
	if (!gInterface.Data[eEventTimePANEL_MAIN].OnShow || !gInterface.IsWorkZone(eEventTime_CLOSE))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eEventTime_CLOSE].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eEventTime_CLOSE].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eEventTime_CLOSE].EventTick = GetTickCount();
	gInterface.Data[eEventTimePANEL_MAIN].OnShow = false;
	
	if(gProtect.m_MainInfo.CustomInterfaceType != 3 || gProtect.m_MainInfo.CustomInterfaceType != 4)
	{
		pSetCursorFocus = false;
	}
	// ----
	return false;
}

void CCustomEventTime::OpenWindow()
{

	if (gInterface.CheckWindow(ObjWindow::CreateGuild) || gInterface.CheckWindow(ObjWindow::ChatWindow) || gInterface.CheckWindow(ObjWindow::FriendList) || gInterface.CheckWindow(ObjWindow::NPC_Dialog) || gInterface.CheckWindow(ObjWindow::MuHelper) || gInterface.CheckWindow(ObjWindow::Store)  || gInterface.CheckWindow(ObjWindow::Warehouse) || gInterface.CheckWindow(ObjWindow::Trade) || gInterface.CheckWindow(ObjWindow::CashShop))
	{
		return;
	}

	if((GetTickCount() - gInterface.Data[eEventTimePANEL_MAIN].EventTick) < 500 )
	{
		return;
	}

	gInterface.Data[eEventTimePANEL_MAIN].EventTick = GetTickCount();


	if (gInterface.Data[eEventTimePANEL_MAIN].OnShow == true)
	{
		gInterface.Data[eEventTimePANEL_MAIN].OnShow = false;
		
		if(gProtect.m_MainInfo.CustomInterfaceType != 3 || gProtect.m_MainInfo.CustomInterfaceType != 4)
		{
			pSetCursorFocus = false;
		}
		return;
	}

	gInterface.CloseCustomWindow();

	this->ClearCustomEventTime();

	PMSG_CUSTOM_EVENTTIME_SEND pMsg;

	pMsg.header.set(0xF3, 0xE8,sizeof(pMsg));

	DataSend((BYTE*)&pMsg,pMsg.header.size);
	gInterface.Data[eEventTimePANEL_MAIN].OnShow = true;
	
	if(gProtect.m_MainInfo.CustomInterfaceType != 3 || gProtect.m_MainInfo.CustomInterfaceType != 4)
	{
		pSetCursorFocus = false;
	}

}

bool CCustomEventTime::EventNext(DWORD Event)
{
	DWORD CurrentTick	= GetTickCount();
	DWORD Delay			= (CurrentTick - gInterface.Data[eNextEvent].EventTick);
	DWORD Delay2		= (CurrentTick - gInterface.Data[ePrevEvent].EventTick);

	if( !gInterface.Data[eEventTimePANEL_MAIN].OnShow || NextEvent == -1)
	{
		return false;
	}
	
	if( !gInterface.IsWorkZone(eNextEvent) )
	{
		return false;
	}

	if( Event == WM_LBUTTONDOWN )
	{
		gInterface.Data[eNextEvent].OnClick = true;
		return true;
	}

	if( Delay < 100 || Delay2 < 100 )
	{
		return false;
	}
	
	gInterface.Data[eNextEvent].OnClick = false;
	
	this->Page++;
	
	gInterface.Data[eNextEvent].EventTick = GetTickCount();
	

	return true;
}

bool CCustomEventTime::EventPrev(DWORD Event)
{
	DWORD CurrentTick	= GetTickCount();
	DWORD Delay			= (CurrentTick - gInterface.Data[ePrevEvent].EventTick);
	DWORD Delay2		= (CurrentTick - gInterface.Data[eNextEvent].EventTick);

	if( !gInterface.Data[eEventTimePANEL_MAIN].OnShow || PreventEvent == -1)
	{
		return false;
	}
	
	if( !gInterface.IsWorkZone(ePrevEvent) )
	{
		return false;
	}

	if( Event == WM_LBUTTONDOWN )
	{
		gInterface.Data[ePrevEvent].OnClick = true;
		return true;
	}

	if( Delay < 100 || Delay2 < 100 )
	{
		return false;
	}
	
	gInterface.Data[ePrevEvent].OnClick = false;
	
	gInterface.Data[ePrevEvent].EventTick = GetTickCount();

	this->Page--;
	
	return true;
}