#include "stdafx.h"
#include "DailyReward.h"
#include "Import.h"
#include "CustomFont.h"
#include <ctime>
#include "Interface.h"
#include "Defines.h"
cDailyReward DailyReward;

cDailyReward::cDailyReward()
{
    this->Init();
}

cDailyReward::~cDailyReward()
{
}

void cDailyReward::Init()
{
    this->SetWindow(false);
    this->SetRect(120, 70, 400, 255);
    this->SetTitle("Daily Reward", 0xc1c1c1ff, 0x0, 1);
    this->SelectedDay = 1;
}

unsigned char last_day_of_month(int year, unsigned char month) {
    return month != 2 ? ((month ^ (month >> 3))) | 30 :
        year % 4 ? 29 : 28;
}

void cDailyReward::ClearDayGift()
{
    this->DayInfo = false;
    this->Type = -1;
    this->Level = 0;
    this->Ex = 0;
    this->Zen = 0;
    this->Wcoin = 0;
}
int ImgTag100 = 0;
void cDailyReward::DrawIcon() //focus move box daily
{

    if (gInterface.CheckWindow(CashShop)
        || gInterface.CheckWindow(SkillTree)
        || gInterface.CheckWindow(FullMap)
        || gInterface.CheckWindow(MoveList)
        || gInterface.CheckWindow(ExpandInventory)
        || gInterface.CheckWindow(Store)
        || gInterface.CheckWindow(Inventory)
        || gInterface.CheckWindow(Character)
        || gInterface.CheckWindow(CommandWindow)
        || gInterface.CheckWindow(Guild)
        || gInterface.CheckWindow(Quest)
        || gInterface.CheckWindow(MuHelper)
        || gInterface.CheckWindow(Party)
        || gInterface.CheckWindow(Trade)
        || gInterface.CheckWindow(Warehouse)
        || gInterface.CheckWindow(NPC_Dialog)
        || gInterface.CheckWindow(GensInfo)
        || gInterface.CheckWindow(ExpandWarehouse))
    {
        return;
    }
    int j;

    if (!Blink)
    {
        return;
    }

    CustomFont.Draw(CustomFont.FontNormal, 543, 60, 0xffffffff, 0x00000050, 0, 0, 3, "Daily Reward"); //Move Daily Reward - 70 lados - 60 arriba
    int speed = 2, r = 0;
    if (ImgTag100 >= 25 * speed) ImgTag100 = 0;

    r = floor((float)ImgTag100 / (float)speed);

    RenderBitmap(531026, 550, 30, 102.4 / 2, 93.4 / 2, (r % 5) * 102.4 / 512.0, (r - (r % 5)) / 5 * 93.4 / 512.0, 102.4 / 512.0, 93.4 / 512.0, 0, 1, 0.0);
    ImgTag100++; //Move Box Daily -- 80 lados -- 30 Ariba+Abajo


    if (IsWorkZone(550, 30,40, 40, false))
    {
        if (pIsKeyRelease(VK_LBUTTON) && IsOnWindow())
            DailyReward.ToggleWindow(true);

    }


    if (IsWorkZone(550, 30,40, 40, false))
    {
        pSetCursorFocus = true;
    }
    else pSetCursorFocus = false;

}

void cDailyReward::Draw()
{

    if (pPlayerState < GameProcess)
    {
        return;
    }
    if (gInterface.CheckWindow(ObjWindow::CashShop)
        || gInterface.CheckWindow(ObjWindow::FriendList)
        || gInterface.CheckWindow(ObjWindow::MoveList)
        || gInterface.CheckWindow(ObjWindow::Party)
        || gInterface.CheckWindow(ObjWindow::Quest)
        || gInterface.CheckWindow(ObjWindow::NPC_Devin)
        || gInterface.CheckWindow(ObjWindow::Guild)
        || gInterface.CheckWindow(ObjWindow::Trade)
        || gInterface.CheckWindow(ObjWindow::Warehouse)
        || gInterface.CheckWindow(ObjWindow::ChaosBox)
        || gInterface.CheckWindow(ObjWindow::CommandWindow)
        || gInterface.CheckWindow(ObjWindow::PetInfo)
        || gInterface.CheckWindow(ObjWindow::Shop)
        || gInterface.CheckWindow(ObjWindow::Inventory)
        || gInterface.CheckWindow(ObjWindow::Store)
        || gInterface.CheckWindow(ObjWindow::OtherStore)
        || gInterface.CheckWindow(ObjWindow::Character)
        || gInterface.CheckWindow(ObjWindow::DevilSquare)
        || gInterface.CheckWindow(ObjWindow::BloodCastle)
        || gInterface.CheckWindow(ObjWindow::CreateGuild)
        || gInterface.CheckWindow(ObjWindow::GuardNPC)
        || gInterface.CheckWindow(ObjWindow::SeniorNPC)
        || gInterface.CheckWindow(ObjWindow::GuardNPC2)
        || gInterface.CheckWindow(ObjWindow::CastleGateSwitch)
        || gInterface.CheckWindow(ObjWindow::CatapultNPC)
        || gInterface.CheckWindow(ObjWindow::CrywolfGate)
        || gInterface.CheckWindow(ObjWindow::IllusionTemple)
        || gInterface.CheckWindow(ObjWindow::HeroList)
        || gInterface.CheckWindow(ObjWindow::ChatWindow)
        || gInterface.CheckWindow(ObjWindow::FastMenu)
        || gInterface.CheckWindow(ObjWindow::Options)
        || gInterface.CheckWindow(ObjWindow::Help)
        || gInterface.CheckWindow(ObjWindow::FastDial)
        || gInterface.CheckWindow(ObjWindow::SkillTree)
        || gInterface.CheckWindow(ObjWindow::GoldenArcher1)
        || gInterface.CheckWindow(ObjWindow::GoldenArcher2)
        || gInterface.CheckWindow(ObjWindow::LuckyCoin1)
        || gInterface.CheckWindow(ObjWindow::LuckyCoin2)
        || gInterface.CheckWindow(ObjWindow::NPC_Duel)
        || gInterface.CheckWindow(ObjWindow::NPC_Titus)
        || gInterface.CheckWindow(ObjWindow::CashShop)
        || gInterface.CheckWindow(ObjWindow::Lugard)
        || gInterface.CheckWindow(ObjWindow::QuestList1)
        || gInterface.CheckWindow(ObjWindow::QuestList2)
        || gInterface.CheckWindow(ObjWindow::Jerint)
        || gInterface.CheckWindow(ObjWindow::FullMap)
        || gInterface.CheckWindow(ObjWindow::NPC_Dialog)
        || gInterface.CheckWindow(ObjWindow::GensInfo)
        || gInterface.CheckWindow(ObjWindow::NPC_Julia)
        || gInterface.CheckWindow(ObjWindow::NPC_ChaosMix)
        || gInterface.CheckWindow(ObjWindow::ExpandInventory)
        || gInterface.CheckWindow(ObjWindow::ExpandWarehouse)
        || gInterface.CheckWindow(ObjWindow::MuHelper)
        )
    {

        this->CloseWindow(true);
    }

    if (!CheckWindow())
    {
        DrawIcon();
        return;
    }
    this->DrawBase();

    tm today;
    time_t ltime;
    time(&ltime);
    localtime_s(&today, &ltime);

    char* DoW[] = { "DOM", "SEG", "TER", "QUA", "QUI", "SEX", "SAB" };

    float sW = 35, sH = 38;
    int i, v1, v2, v3, v4, v5;
    v3 = this->FWday;
    v4 = this->MaxDay;
    for (i = 0; i < 7; i++)
    {
        CustomFont.Draw(CustomFont.FontNormal, x + 15 + sW * i, y + 40, 0xf6ffa8ff, 0x2e6cab50, sW - 2, 0, 3, DoW[i]); // Seg, ter, qua.. etc
    }
    if (Loaded)
    {
        for (i = v3; i < (v3 + v4); i++)
        {
            v1 = i % cDR_SPLIT_DAY;
            v2 = (i - v1) / cDR_SPLIT_DAY;
            v5 = i - v3 + 1;
            //
            if (SelectedDay == v5)
            {
                CustomFont.Draw(CustomFont.FontNormal, x + 15 + sW * v1, y + 52 + v2 * sH, 0xffffffff, 0xf6ffa850, sW - 2, sH - 1, 3, " "); //ao apertar
            }
            if (SelectedDay == v5 && State[v5 - 1] == 0) //selecting
            {
                RenderBitmap(531020, x + 8 + sW * v1 + (sW - 16) / 2, y + 50 + v2 * sH, 45, 45, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
            }
            else if (IsWorkZone(x + 15 + sW * v1, y + 52 + v2 * sH, sW - 2, sH - 2, true))
            {
                RenderBitmap(531020, x + 8 + sW * v1 + (sW - 16) / 2, y + 50 + v2 * sH, 45, 45, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
                if (pIsKeyRelease(VK_LBUTTON))
                {
                    SelectedDay = v5;
                    if (State[v5 - 1] == 0)
                    {
                        this->SendRequest(0x01, SelectedDay);
                        this->ClearDayGift();
                    }
                }
            }
            else if (State[v5 - 1] == 0) //
            {
                RenderBitmap(531020, x + 8 + sW * v1 + (sW - 16) / 2, y + 50 + v2 * sH, 45, 45, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
            }
            else
            {
                RenderBitmap(531021, x + 8 + sW * v1 + (sW - 16) / 2, y + 50 + v2 * sH, 45, 45, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
            }
            CustomFont.Draw(CustomFont.FontNormal, x + 15 + sW * v1, y + 52 + v2 * sH + sH - 13, 0xffffffff, (v5) != today.tm_mday ? 0x00000050 : 0x00ff007f, sW - 2, 12, 3, "%d", v5);
        }

        if (SelectedDay != 0)
        {
            if (State[SelectedDay - 1] != 0)
            {
                CustomFont.Draw(CustomFont.FontNormal, x + 265, y + 100, 0xffffffff, 0x00FF0050, 125, 0, 3, "CONCLUIDO");
				CustomFont.Draw(CustomFont.FontNormal, x + 265, y + 110, 0xffffffff, 0x00000050, 125, 0, 3, "Esta recompensa foi resgatada,");
				CustomFont.Draw(CustomFont.FontNormal, x + 265, y + 120, 0xffffffff, 0x00000050, 125, 0, 3, "continue jogando todos os dias");
				CustomFont.Draw(CustomFont.FontNormal, x + 265, y + 130, 0xffffffff, 0x00000050, 125, 0, 3, "para resgatar mais recompensas!");
            }
            else if (DayInfo)
            {
				CustomFont.Draw(CustomFont.FontNormal, x + 259, y + 49, 0xffffffff, 0x00000050, 131, 191, 3, " ");

				CustomFont.Draw(CustomFont.FontNormal, x + 260, y + 50, 0xFFFFFFFF, 0x00FF0050, 129, 0, 3, Text);
				CustomFont.Draw(CustomFont.FontNormal, x + 260, y + 62, 0xffffffff, 0xffffff30, 129, 0, 3, "Wc: %d", Wcoin);
                CustomFont.Draw(CustomFont.FontNormal, x + 260, y + 74, 0xffffffff, 0xffffff30, 129, 0, 3, "Zen : %d", Zen);

                //CustomFont.Draw(CustomFont.FontNormal, x + 260, y + 80, 0xffffffff, 0x00000050, 129, 0, 3, Text);

				//CustomFont.Draw(CustomFont.FontNormal, x + 260, y + 201, 0xffffffff, 0x00FF0050, 129, 32, 3, " ");

				if (SelectedDay < today.tm_mday)
                {
                    this->DrawButton(32331, x - 5 + 74 * 4, y + h - 50, 73, 27, 128.0, 128.0, DailyReward.RecvGiftAction);
                    CustomFont.Draw(CustomFont.FontNormal, x - 5 + 74 * 4, y + h - 42.5, 0xffffffff, 0x0, 73, 0, 3, "Indisponivel");
                }

                else if (SelectedDay == today.tm_mday)
                {
                    this->DrawButton(32331, x - 5 + 74 * 4, y + h - 50, 73, 27, 128.0, 128.0, DailyReward.RecvGiftAction);
                    CustomFont.Draw(CustomFont.FontNormal, x - 5 + 74 * 4, y + h - 42.5, 0xffffffff, 0x0, 73, 0, 3, "Resgatar");
                }

				else if (SelectedDay > today.tm_mday)
                {
                    this->DrawButton(32331, x - 5 + 74 * 4, y + h - 50, 73, 27, 128.0, 128.0, DailyReward.RecvGiftAction);
                    CustomFont.Draw(CustomFont.FontNormal, x - 5 + 74 * 4, y + h - 42.5, 0xffffffff, 0x0, 73, 0, 3, "Em breve");
                }

                //CustomFont.Draw(CustomFont.FontNormal, x + 280, y + 100, 0xffffffff, 0x00000050, 90, 90, 3, " ");

				if(this->Type < 2960) // Armas
					gInterface.DrawItem2(x + 280, y + 100, 70, 85, this->Type, this->Level, this->Ex, 0, 0);
				else if(this->Type >= 6144 && this->Type < 6444) // Asas
					gInterface.DrawItem2(x + 280, y + 100, 90, 90, this->Type, this->Level, this->Ex, 0, 0);
				else // outros
					gInterface.DrawItem2(x + 280, y + 100, 90, 65, this->Type, this->Level, this->Ex, 0, 0);


                if (IsWorkZone(x + 280, y + 100, 90, 90, true))
                {
                    gInterface.DrawItemToolTipText((void*)&Item, *(int*)0x879340C, *(int*)0x8793410 + 25);
                    glColor3f(1, 1, 1);
                    pSetBlend(false);
                }
            }
            else
            {
                CustomFont.Draw(CustomFont.FontNormal, x + 260, y + 50, 0xffffffff, 0x00000050, 130, 0, 3, "Sem informações...", Wcoin);
            }
        }
    }
    else
    {
        CustomFont.Draw(CustomFont.FontNormal, x + 60, y + 50, 0xffffffff, 0x00000050, 200, 0, 3, "Sem informações...");
    }
}

bool cDailyReward::AllowedGift()
{
    return Loaded && State[SelectedDay - 1] == 0 && SelectedDay <= CurDay;
}
void cDailyReward::SendRequest(BYTE type, int value)
{
    PMSG_DAILY_REWARD_SEND pRequest;
    pRequest.h.set((LPBYTE)&pRequest, 0xFB, 0x02, sizeof(pRequest));
    pRequest.Type = type;
    pRequest.Value = value;
    DataSend((LPBYTE)&pRequest, pRequest.h.size);
}

void cDailyReward::RecvGiftAction(LPVOID pClass)
{
    cDailyReward* This = (cDailyReward*)pClass;

    if (This->AllowedGift())
    {
        This->SendRequest(0x02, This->SelectedDay);
    }
}

void cDailyReward::OnOpen()
{
    this->Loaded = false;
    this->DayInfo = false;
    this->SendRequest(0x0, 0x0);
}
void cDailyReward::OnClose()
{
}

void cDailyReward::ToggleWindow(bool mode)
{
    SetWindow(!CheckWindow(), mode);
}
void cDailyReward::OpenWindow(bool mode)
{
    SetWindow(true, mode);
}
void cDailyReward::CloseWindow(bool mode)
{
    SetWindow(false, mode);
}
void cDailyReward::SetWindow(bool state, bool mode)
{
    this->Drawing = state;
    if (mode)
        CheckWindow() ? OnOpen() : OnClose();
}

void cDailyReward::GCRecvUserInfo(BYTE* a)
{
    PMSG_DAILY_REWARD_USER_INFO_RECV* Data = (PMSG_DAILY_REWARD_USER_INFO_RECV*)a;
    this->CurDay = Data->CurDay;
    this->MaxDay = Data->MaxDay;
    this->FWday = Data->FWday;
    this->Timer = Data->Timer;

    for (int i = 0; i < 31; i++)
    {
        this->State[i] = Data->State[i];
    }

    if (State[CurDay - 1] == 0)
    {
        Blink = true;
    }
    else
    {
        Blink = false;
    }

    Loaded = true;
}

int cDailyReward::CheckItemInfo(signed int a1)
{
    if (a1 > 3092)
    {
        if (a1 > 4661)
        {
            if (a1 > 5685 || a1 < 5676 && (a1 < 5164 || a1 > 5173))
                return 0;
        }
        else if (a1 < 4652 && (a1 > 4149 || a1 < 4140 && (a1 < 3628 || a1 > 3637)))
        {
            return 0;
        }

        return 1;
    }

    if (a1 >= 3089)
        return 1;

    if (a1 > 2071)
    {
        if (a1 != 2580 && (a1 <= 2589 || a1 > 2592))
            return 0;
        return 1;
    }

    if (a1 == 2071 || a1 <= 1041 && (a1 >= 1040 || a1 >= 26 && a1 <= 28))
        return 1;

    return 0;
}

void cDailyReward::GCRecvDayInfo(BYTE* a)
{
    PMSG_DAILY_REWARD_DAY_INFO_RECV* Data = (PMSG_DAILY_REWARD_DAY_INFO_RECV*)a;

    DayInfo = true;
    if (Data->Type != -1)
    {
        this->Type = Data->Type;

        DWORD dwAddress;
        int a5;
        int a6;
        int a7;
        int a8;
        int a9;
        DWORD a10;

        dwAddress = (DWORD)&this->Item;

        *(WORD *)dwAddress = Data->Type;
        a5 = Data->Dur;
        *(BYTE *)(dwAddress + 22) = a5;
        a6 = Data->Item[3];
        *(BYTE *)(dwAddress + 23) = a6;
        a7 = Data->Item[4];
        *(BYTE *)(dwAddress + 24) = a7;
        a8 = Data->Item[5];
        *(BYTE *)(dwAddress + 97) = (a8 & 2) >> 1 > 0;
        *(BYTE *)(dwAddress + 98) = (a8 & 4) >> 2 > 0;
        *(BYTE *)(dwAddress + 73) = 16 * (a8 & 8) >> 7 > 0;
        a9 = Data->Item[6];
        *(WORD *)(dwAddress + 69) = (a9 & 0xF0) >> 4;
        *(WORD *)(dwAddress + 71) = a9 & 0xF;

        a10 = (DWORD)&Data->Item[7];

        if (a10)
        {
            *(BYTE *)(dwAddress + 79) = 5;

            for (int i = 0; i < 5; ++i)
                *(BYTE *)(i + dwAddress + 74) = *(BYTE *)(i + a10);

            for (int j = 0; j < 5; ++j)
            {
                if (*(BYTE *)(j + a10) == 255)
                {
                    *(BYTE *)(dwAddress + 79) = j;
                    break;
                }

                if (*(BYTE *)(j + a10) == 254)
                {
                    *(BYTE *)(j + dwAddress + 80) = -1;
                }
                else
                {
                    *(BYTE *)(j + dwAddress + 80) = *(BYTE *)(j + a10) % 50;
                    *(BYTE *)(j + dwAddress + 85) = *(BYTE *)(j + a10) / 50 + 1;
                }
            }

            if (this->CheckItemInfo(*(WORD *)dwAddress))
            {
                *(BYTE *)(dwAddress + 90) = a9;
                *(WORD *)(dwAddress + 69) = 0;
                *(WORD *)(dwAddress + 71) = 0;
            }
            else
            {
                *(BYTE *)(dwAddress + 90) = -1;
            }
        }
        else
        {
            *(BYTE *)(dwAddress + 79) = 0;
        }

        *(BYTE *)(dwAddress + 96) = 0;
        *(DWORD *)(dwAddress + 103) = 1;

        if (Data->PeriodTime)
        {
            this->Item.PeriodItem = 1;
            this->Item.ExpireDateConvert = Data->PeriodTime;
        }

        ((void(__cdecl*)(ObjectItem * lpItem, BYTE Option, BYTE Special, BYTE Value)) 0x58B910)(&this->Item, Data->Item[1], Data->Item[3], Data->Item[4]);
    }
    this->Zen = Data->Zen;
    this->Wcoin = Data->Wcoin;
    memcpy_s(Text, 100, Data->Text, 100);
}
