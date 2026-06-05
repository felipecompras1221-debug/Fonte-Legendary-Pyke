#include "stdafx.h"
#include "HealthBar.h"
#include "Offset.h"
#include "Util.h"
#include "Object.h"
#include "User.h"
#include "Defines.h"
#include "MonsterHpBar.h"
#include "Import.h"
#include "CustomRankUser.h"
#include "Common.h"
#include "Monster.h"
#include "MonsterBar.h"

NEW_HEALTH_BAR gNewHealthBar[MAX_MAIN_VIEWPORT];

void ClearNewHealthBar() // OK
{
	for (int n = 0; n < MAX_MAIN_VIEWPORT; n++)
	{
		gNewHealthBar[n].index = 0xFFFF;
		gNewHealthBar[n].type = 0;
		gNewHealthBar[n].rate = 0;
	}
}

void InsertNewHealthBar(PMSG_NEW_HEALTH_RECV* lpInfo) // OK
{
	for (int n = 0; n < MAX_MAIN_VIEWPORT; n++)
	{
		if (gNewHealthBar[n].index == 0xFFFF)
		{
			gNewHealthBar[n].index = lpInfo->index;
			gNewHealthBar[n].type = lpInfo->type;
			gNewHealthBar[n].rate = lpInfo->rate;
			gNewHealthBar[n].monsterid = lpInfo->monsterid;
			gNewHealthBar[n].Life = lpInfo->Life;
			gNewHealthBar[n].MaxLife = lpInfo->MaxLife;
			gNewHealthBar[n].Level = lpInfo->Level;
			gNewHealthBar[n].Reset = lpInfo->Reset;
			gNewHealthBar[n].Shield = lpInfo->Shield;
			gNewHealthBar[n].MaxShield = lpInfo->MaxShield;
			gNewHealthBar[n].SDrate = lpInfo->SDrate;
			gNewHealthBar[n].isSameGuild = lpInfo->isSameGuild;
			gNewHealthBar[n].HaveGuild = lpInfo->HaveGuild;
			//gNewHealthBar[n].Rank = lpInfo->Rank;

			if (lpInfo->type == emPlayer && lpInfo->HaveGuild)
			{
				memcpy(gNewHealthBar[n].GuildName, lpInfo->GuildName, sizeof(gNewHealthBar[n].GuildName));
				char kek[65];

				for (int i = 0; i < 32; i++)
				{
					sprintf(&kek[i * 2], "%02x", lpInfo->Mark[i]);
				}
				kek[64] = '\0';

				for (int i = 0; i < 64; i++)
				{
					if (kek[i] >= 97)
					{
						gNewHealthBar[n].Mark[i] = (int)kek[i] - 87;
					}
					else
					{
						gNewHealthBar[n].Mark[i] = (int)kek[i] - 48;
					}
					//atoi(kek[i]);
					//g_Console.AddMessage(5,"%d",(int)kek[i]);
				}

				//g_Console.AddMessage(5,"Logo setted!");
			}
			return;
		}
	}
}

NEW_HEALTH_BAR* GetNewHealthBar(WORD index, BYTE type) // OK
{
	for (int n = 0; n < MAX_MAIN_VIEWPORT; n++)
	{
		if (gNewHealthBar[n].index != 0xFFFF)
		{
			if (gNewHealthBar[n].index == index && gNewHealthBar[n].type == type)
			{
				return &gNewHealthBar[n];
			}
		}
	}

	return 0;
}

void DrawHealthBar()
{
	if (HideHPMonster == 0)
	{

	}

	if (HideHPMonster == 1)
	{
		//if (!gServerInfo.get()->m_hp_bar)
	//{
		((void(*)())0x005BA770)();
		//	return;
		//}
		/*if (!gServerInfo.m_HPBar)
		{
			return;
		}*/
		//gConsole.AddMessage(5,"HPBAR");
		//((void(*)())0x005BA770)();

		//ItemEquip();

		int PosX, PosY;
		float LifeBarWidth = 66.95;
		//char LifeDisplay[20];
		VAngle Angle;

		for (int n = 0; n < MAX_MAIN_VIEWPORT; n++)
		{
			lpViewObj lpObj = &*(ObjectPreview*)pGetPreviewStruct(pPreviewThis(), n);
			lpViewObj lpTarget = gObjUser.lpViewTarget;

			//g_Console.AddMessage(5,lpTarget->Name);

			bool isTarget = 1;

			if (!lpTarget || (lpTarget->m_Model.ObjectType != emMonster && lpTarget->m_Model.ObjectType != emPlayer) || !lpTarget->m_Model.Unknown4 || lpTarget->aIndex != lpObj->aIndex)
			{
				isTarget = 0;
			}

			if (!lpObj)
			{
				continue;
			}

			if (lpObj->m_Model.Unknown4 == 0)
			{
				continue;
			}

			NEW_HEALTH_BAR* lpNewHealthBar = GetNewHealthBar(lpObj->aIndex, lpObj->m_Model.ObjectType);

			if (lpNewHealthBar == 0)
			{
				continue;
			}

			int LifePercent = lpNewHealthBar->rate / 10;
			float BarWidth = (((66.95 - 1) / 100.0f) * lpNewHealthBar->rate) - 1;
			float SDBarWidth = (((66.95 - 1) / 100.0f) * lpNewHealthBar->SDrate) - 1;

			Angle.X = lpObj->m_Model.VecPos.X;
			Angle.Y = lpObj->m_Model.VecPos.Y;
			Angle.Z = lpObj->m_Model.VecPos.Z + lpObj->m_Model.Unknown216.Z + 100.0;

			pGetPosFromAngle(&Angle, &PosX, &PosY);
			PosX -= (int)floor(LifeBarWidth / (double)2.0);

			pSetBlend(true);

			DWORD Color = Color4f(255, 255, 255, 100);
			Color = Color4f(255, 255, 255, 255);

			//=========================================================================================================================================
			//                                      LOCAL DO LIFE BAR MONSTRO 01 - STATIC LIFE
			//=========================================================================================================================================

			if (HPMonster == 0)
			{
				if (lpObj->m_Model.ObjectType == emMonster)
				{


					float BarWidth = (((80.95 - 1) / 100.0f) * lpNewHealthBar->rate) - 1;
					glColor4f(0.0, 0.0, 0.0, 0.7);

					if (!isTarget)
					{
						pDrawBarForm((float)(PosX - 17), (float)(PosY - 12), 96.95, 20, 0.0, 0); // Фон для имени
					}

					glColor4f(RGBTOGLFLOAT(0), RGBTOGLFLOAT(0), RGBTOGLFLOAT(0), 0.6); // COR DO FUNDO LIFE BAR - RGB
					pDrawBarForm((float)(PosX - 10), (float)(PosY - 1.5), 82.95, 6, 0.0, 0); // Фон хпбара

					// COR DO LIFE BAR -  RGB
					glColor3f(0, 174, 0);

					pDrawBarForm((float)(PosX)-8.0, (float)(PosY)+0.0f, BarWidth, 3, 0.0, 0); // LIFE BAR [ALTURA]

					if (!isTarget)
					{
						DrawInterfaceText(lpObj->Name, PosX - 1, PosY - 11, 66.95, 1, eWhite, 9, 3); // Драв имени
					}

				}


				//=========================================================================================================================================
				//=========================================================================================================================================

				//=========================================================================================================================================
				//                                      LOCAL DO LIFE BAR MONSTRO 02 - LIFE MOUSE OVER
				//=========================================================================================================================================

				if (lpObj->m_Model.ObjectType == emMonster)
				{
					float BarWidth = (((80.95 - 1) / 100.0f) * lpNewHealthBar->rate) - 1;
					glColor4f(9.0f, 0.0f, 0.0f, 0.24f);

					if (!isTarget)
					{
						pDrawBarForm((float)(PosX - 1), (float)(PosY - 12), 66.95, 10, 0.0, 0); // Фон для имени
					}
					else
					{
						pDrawBarForm((float)(PosX - 17), (float)(PosY - 22), 96.95, 28, 0.0, 0); // COR DO FUNDO [LARGURA, ALTURA]
					}

					glColor4f(RGBTOGLFLOAT(0), RGBTOGLFLOAT(0), RGBTOGLFLOAT(0), 0.6); // COR DO FUNDO LIFE BAR - RGB
					pDrawBarForm((float)(PosX - 10), (float)(PosY - 1.5), 82.95, 6, 0.0, 0); // Фон хпбара

					// COR DO LIFE BAR -  RGB
					glColor3f(0, 174, 0);

					pDrawBarForm((float)(PosX)-8.0, (float)(PosY)+0.0f, BarWidth, 3, 0.0, 0); // LIFE BAR [ALTURA]

					if (!isTarget)
					{
						DrawInterfaceText(lpObj->Name, PosX - 1, PosY - 11, 66.95, 1, eWhite, 9, 3); // Драв имени
					}
					else
					{
						char Text1[50];
						glColor4f(0.0f, 0.0f, 8.0f, 0.24f);
						pDrawBarForm((float)(PosX - 17), (float)(PosY - 30), 96.95, 7, 0.0, 0); // COR DO FUNDO [LARGURA, ALTURA]
						sprintf(Text1, "-Ґ- [LEVEL %d] -Ґ-", lpNewHealthBar->Level);
						pDrawColorText(Text1, PosX - 7, PosY - 30, 80, 1, Color, 9, 3);



						char Text[100];
						//char HP[20];
						//char MaxHP[20];
						//strcpy(HP, this->GetHPValue((int)lpNewHealthBar->Life));
						//strcpy(MaxHP, this->GetHPValue((int)lpNewHealthBar->MaxLife));
						//AQUI MUDA O LEVEL DO MONSTRO
						sprintf(Text, "HP: %s/%s", ParseReducedValue((int)lpNewHealthBar->Life), ParseReducedValue((int)lpNewHealthBar->MaxLife));

						DrawInterfaceText(lpObj->Name, PosX - 1, PosY - 21, 67, 1, eWhite, 9, 3); // Драв имени
						DrawInterfaceText(Text, PosX - 1, PosY - 11, 67, 1, eWhite, 9, 3); // Драв инфы
					}
				}
			}
			//=========================================================================================================================================
			//=========================================================================================================================================

			if (lpNewHealthBar->type == emPlayer/* && istarget*/)
			{

				bool isPartyMember = IsPartyMember(n);
				if (!isTarget && !isPartyMember && !lpNewHealthBar->isSameGuild)
				{
					continue;
				}

				//gConsole.AddMessage(5, "Istarget = %d", isTarget);
				if (isPartyMember)
				{
					glColor4f(RGBTOGLFLOAT(63), RGBTOGLFLOAT(124), RGBTOGLFLOAT(204), 0.9); // Цвет фона для имени
				}
				else if (lpNewHealthBar->isSameGuild)
				{
					glColor4f(RGBTOGLFLOAT(18), RGBTOGLFLOAT(226), RGBTOGLFLOAT(131), 0.9); // Цвет фона для имени
				}
				else
				{
					glColor4f(RGBTOGLFLOAT(0), RGBTOGLFLOAT(0), RGBTOGLFLOAT(0), 0.6); // Цвет фона для имени
				}

				if (!isTarget)
				{
					//pDrawBarForm((float)(PosX - 1), (float)(PosY - 12), 66.95, 10, 0.0, 0); // Фон для имени
				}
				else
				{
					pDrawBarForm((float)(PosX - 1), (float)(PosY + 12), 66.95, 12, 0.0, 0); // BarForm PLayer Name
				}
				if (isTarget)
				{
					glColor4f(RGBTOGLFLOAT(0), RGBTOGLFLOAT(0), RGBTOGLFLOAT(0), 0.6); // Цвет фона для хпбара
					pDrawBarForm((float)(PosX - 1), (float)(PosY - 1.5), 66.95, 6, 0.0, 0); // Фон хпбара
					pDrawBarForm((float)(PosX - 1), (float)(PosY + 5), 66.95, 6, 0.0, 0); // Фон SD

					glColor4f(RGBTOGLFLOAT(255), RGBTOGLFLOAT(ABS(((255.0f / 100.0f) * lpNewHealthBar->rate) - 255.0f)), RGBTOGLFLOAT(0), 0.8); // Цвет ХП Бара

					pDrawBarForm((float)(PosX), (float)(PosY), BarWidth, 3, 0.0, 0); // ХпБар

					glColor4f(RGBTOGLFLOAT(255), RGBTOGLFLOAT((255.0f / 100.0f) * lpNewHealthBar->SDrate), RGBTOGLFLOAT(0), 0.8); // Цвет SD Бара

					pDrawBarForm((float)(PosX), (float)(PosY + 7), SDBarWidth, 2.5, 0.0, 0); // SD Бар
				}
				if (!isTarget)
				{
					if (lpNewHealthBar->isSameGuild)
					{
						//DrawInterfaceText(lpObj->Name, PosX - 1, PosY - 11, 66.95, 1, eBlack, 9, 3); // Драв имени
					}
					else
					{
						//DrawInterfaceText(lpObj->Name, PosX - 1, PosY - 11, 66.95, 1, eWhite, 9, 3); // PARTY NAME 
					}
				}
				else
				{
					char Text[100];
					//char HP[20];
					//char MaxHP[20];
					//strcpy(HP, this->GetHPValue((int)lpNewHealthBar->Life));
					//strcpy(MaxHP, this->GetHPValue((int)lpNewHealthBar->MaxLife));
					sprintf(Text, "Lvl: %d R: %d", lpNewHealthBar->Level, lpNewHealthBar->Reset);

					if (lpNewHealthBar->isSameGuild)
					{
						//DrawInterfaceText(lpObj->Name, PosX - 1, PosY + 23, 67, 1, eBlack, 9, 3); // Драв имени
						DrawInterfaceText(Text, PosX - 1, PosY + 13, 67, 1, eBlack, 9, 3); // Драв инфы
					}
					else
					{
						//DrawInterfaceText(lpObj->Name, PosX - 1, PosY + 23, 67, 1, eWhite, 9, 3); // Text Name player
						DrawInterfaceText(Text, PosX - 1, PosY + 13, 67, 1, eWhite, 9, 3); // Драв инфы
					}
				}
			}
			else
			{
				CUSTOM_HPBAR* HpBarEx = gMonsterHpBar.GetHpBar(lpNewHealthBar->monsterid);

				if (lpNewHealthBar->type == emPlayer/* && istarget*/)
				{
					if (HPMonster == 0)
					{
						glColor4f(RGBTOGLFLOAT(0), RGBTOGLFLOAT(0), RGBTOGLFLOAT(0), 0.6); // Цвет фона для хпбара
						pDrawBarForm((float)(PosX), (float)(PosY - 1.5), 70, 5, 0.0, 0); // Фон хпбара
						pDrawBarForm((float)(PosX), (float)(PosY + 5), 70, 5, 0.0, 0); // Фон SD

						glColor4f(RGBTOGLFLOAT(255), RGBTOGLFLOAT(ABS(((255.0f / 100.0f) * lpNewHealthBar->rate) - 255.0f)), RGBTOGLFLOAT(0), 0.8); // Цвет ХП Бара

						pDrawBarForm((float)(PosX + 1), (float)(PosY), BarWidth, 3, 0.0, 0); // ХпБар

						glColor4f(RGBTOGLFLOAT(255), RGBTOGLFLOAT((255.0f / 100.0f) * lpNewHealthBar->SDrate), RGBTOGLFLOAT(0), 0.8); // Цвет SD Бара

						pDrawBarForm((float)(PosX + 1), (float)(PosY + 7), SDBarWidth, 3, 0.0, 0); // SD Бар
					}
				}
				else
				{
					MONSTERBAR_DATA* HpBarEx = gMonsterBar.GetHPBar(lpNewHealthBar->monsterid);

					if (HpBarEx == 0)
					{
						//glColor4f(RGBTOGLFLOAT(0), RGBTOGLFLOAT(0), RGBTOGLFLOAT(0), 0.6); // Цвет фона для имени

						if (HPMonster == 1)
						{
							glColor4f(RGBTOGLFLOAT(0), RGBTOGLFLOAT(0), RGBTOGLFLOAT(0), 0.6); // Цвет фона для хпбара
							pDrawBarForm((float)(PosX + 13), (float)(PosY - 1.5), 69.5, 6, 0.0, 0); // Фон хпбара

							// COR DO LIFE BAR -  RGB
							glColor4f(RGBTOGLFLOAT(255), RGBTOGLFLOAT(ABS(((255.0f / 100.0f) * lpNewHealthBar->rate) - 255.0f)), RGBTOGLFLOAT(0), 0.8); // Цвет ХП Бара

							pDrawBarForm((float)(PosX + 15), (float)(PosY), BarWidth, 3, 0.0, 0); // HP MOB BAR RED

							//DrawInterfaceText(lpObj->Name, PosX - 1, PosY - 11, 66.95, 1, eWhite, 9, 3); // Драв имени

							char Text[100];

							sprintf(Text, "Level: %d HP: %s/%s", lpNewHealthBar->Level, ParseReducedValue((int)lpNewHealthBar->Life), ParseReducedValue((int)lpNewHealthBar->MaxLife));

							DrawInterfaceText(lpObj->Name, PosX - 1, PosY - 21, 100, 1, eGold, 9, 3); // Драв имени

							for (int h = 0; h < MAX_NAME_COLOR; h++)
							{
								int color[MAX_NAME_COLOR];
								color[h] = Color4f(gCustomMonsterNameColor.m_CustomMonsterColorInfo[h].Red, gCustomMonsterNameColor.m_CustomMonsterColorInfo[h].Green, gCustomMonsterNameColor.m_CustomMonsterColorInfo[h].Blue, gCustomMonsterNameColor.m_CustomMonsterColorInfo[h].Alpha);
								if (lpObj->ID == gCustomMonsterNameColor.m_CustomMonsterColorInfo[h].Class)
								{
									pDrawColorText(lpObj->Name, PosX - 1, PosY - 21, 100, 1, color[h], 9, 3); //
									break;
								}
							}

							DrawInterfaceText(Text, PosX - 1, PosY - 11, 100, 1, eWhite, 9, 3); // Драв инфы
						}
					}
					else
					{
						if (HPMonster == 1)
						{
							glColor4f(RGBTOGLFLOAT(HpBarEx->Red), RGBTOGLFLOAT(HpBarEx->Green), RGBTOGLFLOAT(HpBarEx->Blue), HpBarEx->Opacity); // Цвет фона для имени

							pDrawBarForm((float)(PosX + 14), (float)(PosY - 22), 70, 30, 0.0, 0); // Фон для имени

							glColor4f(RGBTOGLFLOAT(0), RGBTOGLFLOAT(0), RGBTOGLFLOAT(0), 0.6); // Цвет фона для хпбара
							pDrawBarForm((float)(PosX + 14), (float)(PosY - 1.5), 70, 5, 0.0, 0); // Фон хпбара

							glColor4f(RGBTOGLFLOAT(255), RGBTOGLFLOAT(ABS(((255.0f / 100.0f) * lpNewHealthBar->rate) - 255.0f)), RGBTOGLFLOAT(0), 0.8); // Цвет ХП Бара

							pDrawBarForm((float)(PosX + 14), (float)(PosY), BarWidth, 3, 0.0, 0); // ХпБар

							//DrawInterfaceText(lpObj->Name, PosX - 1, PosY - 1, 66.95, 1, eWhite, 9, 3); // Драв имени
							//DrawInterfaceText(HpBarEx->Text, PosX - 1, PosY - 11, 66.95, 1, eWhite, 9, 3); // Драв имени
							char Text[100];
							/*char HP[20];
							char MaxHP[20];
							strcpy(HP, GetHPValue((int)lpNewHealthBar->Life));
							strcpy(MaxHP, GetHPValue((int)lpNewHealthBar->MaxLife));*/
							sprintf(Text, "Level: %d HP: %s/%s", lpNewHealthBar->Level, ParseReducedValue((int)lpNewHealthBar->Life), ParseReducedValue((int)lpNewHealthBar->MaxLife));

							//DrawInterfaceText(HpBarEx->Text, PosX - 1, PosY - 31, 66.95, 1, eWhite, 9, 3); // Драв сабимени
							DrawInterfaceText(lpObj->Name, PosX - 1, PosY - 21, 100, 1, eGold, 9, 3); // Драв имени
							DrawInterfaceText(Text, PosX - 1, PosY - 11, 100, 1, eWhite, 9, 3); // Драв инфы
						}
					}
				}
			}





			pGLSwitch();
		}

		gCustomRankUser.DrawInfo();

		pGLSwitch();

		glColor3f(1.0, 1.0, 1.0);
	}
}

/*void DrawNewHealthBar() // OK
{
	((void(*)())0x005BA770)();

	int PosX, PosY, LifeProgress;
	float LifeBarWidth = 38.0f;
	char LifeDisplay[20];
	VAngle Angle;

	for(int n=0;n < MAX_MAIN_VIEWPORT;n++)
	{
		DWORD ViewportAddress = ((DWORD(__thiscall*)(void*,DWORD))0x0096A4C0)(((void*(*)())0x00402BC0)(),n);

		if(!ViewportAddress)
		{
			continue;
		}

		if(*(BYTE*)(ViewportAddress+0x30C) == 0)
		{
			continue;
		}

		NEW_HEALTH_BAR* lpNewHealthBar = GetNewHealthBar(*(WORD*)(ViewportAddress+0x7E),*(BYTE*)(ViewportAddress+0x320));

		if(lpNewHealthBar == 0)
		{
			continue;
		}

		int LifePercent = lpNewHealthBar->rate/10;

		Angle.X = *(float*)(ViewportAddress+0x404);

		Angle.Y = *(float*)(ViewportAddress+0x408);

		Angle.Z = *(float*)(ViewportAddress+0x40C) + *(float*)(ViewportAddress+0x3E8) + 100.0f;

		pGetPosFromAngle(&Angle, &PosX, &PosY);

		PosX -= (int)floor(LifeBarWidth / (double)2.0);

		if((pCursorX >= PosX) && (pCursorX <= (float)PosX + LifeBarWidth) && (pCursorY >= PosY - 2) && (pCursorY < PosY + 6))
		{
			wsprintf(LifeDisplay, "HP : %d0%%", LifePercent);
			pSetTextColor(pTextThis(), 0xFF, 0xE6, 0xD2, 0xFF);
			pDrawText(pTextThis(), PosX, PosY - 6, LifeDisplay, 0, 0, (LPINT)1, 0);
		}

		pSetBlend(true);

		glColor4f(0.0, 0.0, 0.0, 0.5);
		pDrawBarForm((float)(PosX + 1), (float)(PosY + 1), LifeBarWidth + 4.0f, 5.0f, 0.0f, 0);
		pGLSwitchBlend();

		glColor3f(0.2f, 0.0, 0.0);
		pDrawBarForm((float)PosX, (float)PosY, LifeBarWidth + 4.0f, 5.0f, 0.0, 0);

		glColor3f(0.19607843f, 0.039215688f, 0.0);
		pDrawBarForm((float)(PosX + 2), (float)(PosY + 2), LifeBarWidth, 1.0f, 0.0, 0);

		if(LifePercent > 10)
		{
			LifeProgress = 10;
		}
		else
		{
			LifeProgress = LifePercent;
		}

		glColor3f(0.98039216f, 0.039215688f, 0.0);

		for(int i = 0; i < LifeProgress; i++)
		{
			pDrawBarForm((float)(i * 4 + PosX + 2), (float)(PosY + 2), 3.0, 2.0, 0.0, 0);
		}

		pGLSwitch();
	}

	pGLSwitch();

	glColor3f(1.0, 1.0, 1.0);
}*/

bool IsPartyMember(int ViewportID)
{
#if (_NEW_PARTY_SYSTEM_ == TRUE )
	for (int PartySlot = 0; PartySlot < g_Party.PartyMemberCount; PartySlot++)
#else
	for (int PartySlot = 0; PartySlot < pPartyMemberCount; PartySlot++)
#endif
	{
		PartyList PartyMember = *(PartyList*)((char*)&pPartyListStruct + sizeof(PartyList) * PartySlot);
		//lpViewObj lpPartyObj	= &*(ObjectPreview*)pGetPreviewStruct(pPreviewThis(), PartyMember.ViewportID);
		if (ViewportID == PartyMember.ViewportID)
		{
			return true;
		}
	}

	return false;
}