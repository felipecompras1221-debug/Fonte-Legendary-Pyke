#include "stdafx.h"
#include "Defines.h"
#include "Interface.h"
#include "Offset.h"
#include "Protect.h"
#include "Util.h"
#include "HealthBar.h"
#include "Offset.h"
#include "Object.h"
#include "PrintPlayer.h"
#include "Interface.h"
#include "Import.h"
#include "GLFont.h"

#include "CustomRankUser.h"

CCustomRankUser::CCustomRankUser()
{
}

CCustomRankUser gCustomRankUser;

#if(RANK_DYNAMIC_EX)
/*//======================================
int ImgTagEx = 52800; //Rank Dynamic
int ImgTagEx1 = 52860; //Rank Dynamic
int ImgTagEx2 = 52920; //Rank Dynamic
int ImgTagEx3 = 52980; //Rank Dynamic
int ImgTagEx4 = 53040; //Rank Dynamic
int ImgTagEx5 = 53100; //Rank Dynamic
int ImgTagEx6 = 53160; //Rank Dynamic
int ImgTagEx7 = 53220; //Rank Dynamic
int ImgTagEx8 = 53280; //Rank Dynamic
int ImgTagEx9 = 53340; //Rank Dynamic
int ImgTagEx10 = 53400; //Rank Dynamic
int ImgTagEx11 = 53460; //Rank Dynamic
//int ImgTagEx12 = 33520; //Rank Dynamic
int ImgTagEx13 = 53519; //Rank Dynamic*/
//======================================
#endif

void CCustomRankUser::DrawInfo()
{
	VAngle Angle;
	// ---
	int PosX, PosY;

	for(int n=0;n < MAX_MAIN_VIEWPORT;n++)
	{
		DWORD ViewportAddress = ((DWORD(__thiscall*)(void*,DWORD))0x0096A4C0)(((void*(*)())0x00402BC0)(),n);

		if(!ViewportAddress)
		{
			continue;
		}

		int index = *(WORD*)(ViewportAddress+0x7E);

		char* name = (char*)(ViewportAddress+0x38);

		if(this->m_Data[index].m_Enabled == false)
		{
			continue;
		}

		if(*(BYTE*)(ViewportAddress+0x30C) == 0)
		{
			continue;
		}

		if(*(BYTE*)(ViewportAddress+0xE) == 0 && gProtect.m_MainInfo.RankUserOnlyOnSafeZone != 0)
		{
			continue;
		}

		if((((pMapNumber)<18)?0:((pMapNumber)>23)?(((pMapNumber)==53)?1:0):1) == 1) //Disable in Chaos Castle
		{
			continue;
		}

		// ---

		Angle.X = *(float*)(ViewportAddress+0x404);

		Angle.Y = *(float*)(ViewportAddress+0x408);

		Angle.Z = *(float*)(ViewportAddress+0x40C) + *(float*)(ViewportAddress+0x3E8) + 100.0f;

		pGetPosFromAngle(&Angle, &PosX, &PosY);
		// ---
		PosX -= 42;

		if (gProtect.m_MainInfo.RankUserShowOverHead != 0)
		{
		//Rank Title
		#if(RANK_DYNAMIC_EX)		
			//======================================
			//int ImgTag = 0; //Rank Dynamic
			//======================================
						glColor3f(1.0, 1.0, 1.0);
						pSetBlend(true);
						glColor3f(1.0, 1.0, 1.0);
						pSetBlend(true);
						switch (this->m_Data[index].m_Rank+1)
				{
			//===============================================================================
					case 1:
							CFont.FontColor(99, 91, 88, 255);
							CFont.PaintFont((float)PosX+43, (float)PosY -73, gCustomMessage.GetMessage(71), 0, 8);
					break;
			//===============================================================================
					case 2:
							CFont.FontColor(117, 105, 100, 255);
							CFont.PaintFont((float)PosX+43, (float)PosY -73, gCustomMessage.GetMessage(72), 0, 8);
					break;
			//===============================================================================
					case 3:
							CFont.FontColor(89, 71, 66, 255);
							CFont.PaintFont((float)PosX+43, (float)PosY -73, gCustomMessage.GetMessage(73), 0, 8);
					break;
			//===============================================================================	
					case 4:
							CFont.FontColor(161, 86, 51, 255);
							CFont.PaintFont((float)PosX+43, (float)PosY -73, gCustomMessage.GetMessage(74), 0, 8);
					break;
			//===============================================================================
					case 5:
							CFont.FontColor(227, 172, 109, 255);
							CFont.PaintFont((float)PosX+43, (float)PosY -73, gCustomMessage.GetMessage(75), 0, 8);
					break;
			//===============================================================================	
					case 6:
							CFont.FontColor(186, 64, 45, 255);
							CFont.PaintFont((float)PosX+43, (float)PosY -73, gCustomMessage.GetMessage(76), 0, 8);
					break;
			//===============================================================================	
					case 7:
							CFont.FontColor(195, 205, 217, 255);
							CFont.PaintFont((float)PosX+43, (float)PosY -73, gCustomMessage.GetMessage(77), 0, 8);
					break;
			//===============================================================================	
					case 8:
							CFont.FontColor(240, 211, 115, 255);
							CFont.PaintFont((float)PosX+43, (float)PosY -73, gCustomMessage.GetMessage(78), 0, 8);
					break;
			//===============================================================================	
					case 9:
							CFont.FontColor(111, 76, 207, 255);
							CFont.PaintFont((float)PosX+43, (float)PosY -73, gCustomMessage.GetMessage(79), 0, 8);
					break;	
			//===============================================================================	
					case 10:
							CFont.FontColor(20, 137, 204, 255);
							CFont.PaintFont((float)PosX+43, (float)PosY -73, gCustomMessage.GetMessage(80), 0, 8);
					break;
			//===============================================================================	
					case 11:
							CFont.FontColor(179, 8, 5, 255);
							CFont.PaintFont((float)PosX+43, (float)PosY -73, gCustomMessage.GetMessage(81), 0, 8);
					break;		
			//===============================================================================	
					case 12:
							CFont.FontColor(197, 206, 232, 255);
							CFont.PaintFont((float)PosX+43, (float)PosY -73, gCustomMessage.GetMessage(82), 0, 8);
					break;		
			//===============================================================================
					case 13:
							CFont.FontColor(120, 189, 214, 255);
							CFont.PaintFont((float)PosX+43, (float)PosY -73, gCustomMessage.GetMessage(83), 0, 8);
					break;	
			//===============================================================================	
					case 14:
							CFont.FontColor(204, 165, 94, 255);
							CFont.PaintFont((float)PosX+43, (float)PosY -73, gCustomMessage.GetMessage(84), 0, 8);
					break;	
			//===============================================================================	
					case 15:
							CFont.FontColor(146, 111, 217, 255);
							CFont.PaintFont((float)PosX+43, (float)PosY -73, gCustomMessage.GetMessage(85), 0, 8);
					break;	
			//===============================================================================	
					case 16:
							CFont.FontColor(120, 48, 186, 255);
							CFont.PaintFont((float)PosX+43, (float)PosY -73, gCustomMessage.GetMessage(86), 0, 8);
					break;	
			//===============================================================================	
					case 17:
							CFont.FontColor(173, 19, 5, 255);
							CFont.PaintFont((float)PosX+43, (float)PosY -73, gCustomMessage.GetMessage(87), 0, 8);
					break;		
			//===============================================================================	
					case 18:
							CFont.FontColor(219, 42, 26, 255);
							CFont.PaintFont((float)PosX+43, (float)PosY -73, gCustomMessage.GetMessage(88), 0, 8);
					break;		
			//===============================================================================
					case 19:
							CFont.FontColor(235, 214, 202, 255);
							CFont.PaintFont((float)PosX+43, (float)PosY -73, gCustomMessage.GetMessage(89), 0, 8);
					break;	
			//===============================================================================	
					case 20:
							CFont.FontColor(245, 231, 223, 255);
							CFont.PaintFont((float)PosX+43, (float)PosY -73, gCustomMessage.GetMessage(90), 0, 8);
					break;
			//===============================================================================
					case 21:
							CFont.FontColor(240, 215, 149, 255);
							CFont.PaintFont((float)PosX+43, (float)PosY -73, gCustomMessage.GetMessage(91), 0, 8);
					break;
			//=================================================================================================================================	
			//=================================================================================================================================
					case 22:
							CFont.FontColor(242, 228, 170, 255);
							CFont.PaintFont((float)PosX+42, (float)PosY -72, gCustomMessage.GetMessage(92), 0, 8);
					break;
			//=================================================================================================================================	
						}
			//======================================
		#endif
		//--Rank Oficial
			pSetBlend(true);
			glColor3f(1.0, 1.0, 1.0);
			//-- Imagen Rank
			pDrawImage(gInterface.Data[this->m_Data[index].m_Rank+1].ModelID, (float)PosX+24, (float)PosY -68, 60.0, 60.0,0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
			this->DrawFormat(eAncient,  PosX + 38, PosY - 72, 60, 1, "%s", this->m_Data[index].m_Vip);
			//--
			pGLSwitchBlend();
			pGLSwitch();
			glColor3f(1.0, 1.0, 1.0);
			pSetBlend(false);
		}
		// ---
		if((pCursorX >= PosX) && ((float)pCursorX <= (float)PosX + 50) && (pCursorY >= PosY + 20) && (pCursorY < PosY + 85))
		{

			/*if (gProtect.m_MainInfo.RankUserType != 4 && gProtect.m_MainInfo.RankUserShowOverHead != 0)
			{
				pSetBlend(true);
				//glColor4f((GLfloat)1.0, (GLfloat)1.0, (GLfloat)1.0, (float)1.0);
				//pDrawBarForm((float)(PosX + 2), (float)(PosY - 76), 75, 10, 0.0f, 0);
				glColor3f(0.4, 0.4, 0.4);
				pGLSwitchBlend();
				RenderBitmap(gInterface.Data[this->m_Data[index].m_Rank + 1].ModelID, (float)PosX+2, (float)PosY -105, 80, 80, 0, 0.0, 1, 1, 1, 1, 0);
				//pDrawImage(gInterface.Data[this->m_Data[index].m_Rank+1].ModelID, (float)PosX+24, (float)PosY -95, 60.0, 60.0,0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				//gInterface.DrawIMG(this->m_Data[index].m_Rank+1, (float)PosX+24, (float)PosY -95,1.5,1.5);
				pGLSwitch();
				glColor3f(1.0, 1.0, 1.0);
				pSetBlend(false);

				//this->DrawFormat(eGold, PosX+7, PosY -75, 70, 3, "%s", this->m_Data[index].szTitleRank);

			}*/

			if( gProtect.m_MainInfo.RankUserNeedAltKey != 0 && !(GetKeyState(VK_MENU) & 0x8000) )
			{
				continue;
			}

		pSetBlend(true);

		//gInterface.DrawItem(PosX+45,PosY-30,4,4,10,SET_ITEMOPT_LEVEL(0),0,0,0);

		char classename[20] = {0};

		switch(this->m_Data[index].m_Classe)
		{
			case 1:
				sprintf(classename, "Soul Master");
				break;
			case 2:
				sprintf(classename, "Grand Master");
				break;
			case 16:
				sprintf(classename, "Dark Knight");
				break;
			case 17:
				sprintf(classename, "Blade Knight");
				break;
			case 18:
				sprintf(classename, "Blade Master");
				break;
			case 32:
				sprintf(classename, "Fairy Elf");
				break;
			case 33:
				sprintf(classename, "Muse Elf");
				break;
			case 34:
				sprintf(classename, "High Elf");
				break;
			case 48:
				sprintf(classename, "Magic Gladiator");
				break;
			case 50:
				sprintf(classename, "Duel Master");
				break;
			case 64:
				sprintf(classename, "Dark Lord");
				break;
			case 66:
				sprintf(classename, "Lord Emperor");
				break;
			case 80:
				sprintf(classename, "Summoner");
				break;
			case 81:
				sprintf(classename, "Bloody Summoner");
				break;
			case 82:
				sprintf(classename, "Dimension Master");
				break;
			case 96:
				sprintf(classename, "Rage Fighter");
				break;
			case 98:
				sprintf(classename, "Fist Master");
				break;
			default:
				sprintf(classename, "Dark Wizard");
				break;
		}

			if (gProtect.m_MainInfo.RankUserType == 2)
			{
				glColor4f(0.0, 0.0, 0.0, 0.8);
				pDrawBarForm((float)(PosX+40), (float)(PosY - 8), 135.0f, 80.0f, 0.0f, 0);
				pGLSwitchBlend();

				this->DrawFormat(eRed2,		 PosX + 60, PosY - 4, 90, 3, "Rank: %s", this->m_Data[index].szTitleRank);
		
				this->DrawFormat(eWhite,  PosX + 60, PosY + 8, 15, 1, "Lvl:");
				this->DrawFormat(eWhite,  PosX + 60, PosY + 18, 15, 1, "Str:");
				this->DrawFormat(eWhite,  PosX + 60, PosY + 28, 15, 1, "Agi:");
				this->DrawFormat(eWhite,  PosX + 60, PosY + 38, 15, 1, "Vit:");
				this->DrawFormat(eWhite,  PosX + 60, PosY + 48, 15, 1, "Ene:");
				this->DrawFormat(eWhite,  PosX + 60, PosY + 58, 15, 1, "Com:");

				this->DrawFormat(eGold,  PosX + 80, PosY +  8, 45, 1, "%d ", this->m_Data[index].m_Level);
				this->DrawFormat(eGold,  PosX + 80, PosY + 18, 45, 1, "%d ", this->m_Data[index].m_For);
				this->DrawFormat(eGold,  PosX + 80, PosY + 28, 45, 1, "%d ", this->m_Data[index].m_Agi);
				this->DrawFormat(eGold,  PosX + 80, PosY + 38, 45, 1, "%d ", this->m_Data[index].m_Vit);
				this->DrawFormat(eGold,  PosX + 80, PosY + 48, 45, 1, "%d ", this->m_Data[index].m_Ene);
				this->DrawFormat(eGold,  PosX + 80, PosY + 58, 45, 1, "%d ", this->m_Data[index].m_Com);

				int posM = 0;

				if(gProtect.m_MainInfo.RankUserShowReset != 0)
				{
					this->DrawFormat(eWhite,  PosX + 120, PosY + 8, 25, 1,  "Resets:");
					this->DrawFormat(eGold,  PosX + 147, PosY + 8, 37, 1,  "%d", this->m_Data[index].m_Resets);
				}
				else
				{
					posM -= 10;
				}

				if(gProtect.m_MainInfo.RankUserShowMasterReset != 0)
				{
					this->DrawFormat(eWhite,  PosX + 120, PosY + 18 + posM, 25, 1, gCustomMessage.GetMessage(68));
					this->DrawFormat(eGold,  PosX + 147, PosY + 18 + posM, 37, 1, "%d", this->m_Data[index].m_MResets);
				}
				else
				{
					posM -= 10;
				}

				this->DrawFormat(eWhite,  PosX + 120, PosY + 28 + posM, 25, 1, "Kills:");
				this->DrawFormat(eWhite,  PosX + 120, PosY + 38 + posM, 25, 1, "Deaths:");
				this->DrawFormat(eGold,  PosX + 147, PosY + 28 + posM, 37, 1, "%d", this->m_Data[index].m_Kills);
				this->DrawFormat(eGold,  PosX + 147, PosY + 38 + posM, 37, 1, "%d", this->m_Data[index].m_Deads);

				this->DrawFormat(eAncient,  PosX + 120, PosY + 48 + posM, 60, 1, "%s", this->m_Data[index].m_Vip);
				this->DrawFormat(eOrange,  PosX + 120, PosY + 58 + posM, 60, 1, "%s", classename);

			}
			else if (gProtect.m_MainInfo.RankUserType == 1)
			{

				glColor4f(0.0, 0.0, 0.0, 0.8);
				pDrawBarForm((float)(PosX+40), (float)(PosY - 8), 120.0f, 80.0f, 0.0f, 0);
				pGLSwitchBlend();

				this->DrawFormat(eWhite,  PosX + 50, PosY - 2, 15, 1, "Lvl:");

				int posM = 0;

				if(gProtect.m_MainInfo.RankUserShowReset != 0)
				{
					this->DrawFormat(eWhite,  PosX + 50, PosY + 8, 25, 1,  "Resets:");
					this->DrawFormat(eGold,  PosX + 87, PosY + 8, 37, 1,  "%d", this->m_Data[index].m_Resets);
				}
				else
				{
					posM -= 10;
				}

				if(gProtect.m_MainInfo.RankUserShowMasterReset != 0)
				{
					this->DrawFormat(eWhite,  PosX + 50, PosY + 18 + posM, 25, 1, gCustomMessage.GetMessage(68));
					this->DrawFormat(eGold,  PosX + 87, PosY + 18 + posM, 37, 1, "%d", this->m_Data[index].m_MResets);
				}
				else
				{
					posM -= 10;
				}

				this->DrawFormat(eWhite,  PosX + 50, PosY + 28 + posM, 25, 1, "Kills:");
				this->DrawFormat(eWhite,  PosX + 50, PosY + 38 + posM, 25, 1, "Deaths:");

				this->DrawFormat(eGold,  PosX + 87, PosY - 2, 45, 1, "%d ", this->m_Data[index].m_Level);
				this->DrawFormat(eGold,  PosX + 87, PosY + 28 + posM, 37, 1, "%d", this->m_Data[index].m_Kills);
				this->DrawFormat(eGold,  PosX + 87, PosY + 38 + posM, 37, 1, "%d", this->m_Data[index].m_Deads);

				this->DrawFormat(eAncient,  PosX + 50, PosY + 48 + posM, 60, 1, "%s", this->m_Data[index].m_Vip);
				this->DrawFormat(eOrange,  PosX + 50, PosY + 58 + posM, 60, 1, "%s", classename);

				this->DrawFormat(eGold, PosX + 100, PosY -5, 70, 3, "%s", this->m_Data[index].szTitleRank);
				this->DrawFormat(eGold, PosX + 100, PosY + 59, 70, 3, "%s", name);

				gInterface.DrawIMG(this->m_Data[index].m_Rank+1, PosX + 110, PosY + 9,1,1);
			}
			else if (gProtect.m_MainInfo.RankUserType == 3)
			{

				glColor4f((GLfloat)0.0, (GLfloat)0.0, (GLfloat)0.0, (float)0.8);
				pDrawBarForm((float)(PosX+40), (float)(PosY - 5), 80.0f, 85.0f, 0.0f, 0);
				pGLSwitchBlend();

				this->DrawFormat(eSocket, PosX + 40, PosY - 4, 80, 3, "INFO");

				this->DrawFormat(eWhite,  PosX + 50, PosY +8, 15, 1, "Lvl:");

				int posM = 0;

				if(gProtect.m_MainInfo.RankUserShowReset != 0)
				{
					this->DrawFormat(eWhite,  PosX + 50, PosY + 18, 25, 1,  "Resets:");
					this->DrawFormat(eGold,  PosX + 87, PosY + 18, 37, 1,  "%d", this->m_Data[index].m_Resets);
				}
				else
				{
					posM -= 10;
				}

				if(gProtect.m_MainInfo.RankUserShowMasterReset != 0)
				{
					this->DrawFormat(eWhite,  PosX + 50, PosY + 28 + posM, 25, 1, gCustomMessage.GetMessage(68));
					this->DrawFormat(eGold,  PosX + 87, PosY + 28 + posM, 37, 1, "%d", this->m_Data[index].m_MResets);
				}
				else
				{
					posM -= 10;
				}

				this->DrawFormat(eWhite,  PosX + 50, PosY + 38 + posM, 25, 1, "Kills:");
				this->DrawFormat(eWhite,  PosX + 50, PosY + 48 + posM, 25, 1, "Deaths:");

				this->DrawFormat(eGold,  PosX + 87, PosY + 8, 45, 1, "%d ", this->m_Data[index].m_Level);
				this->DrawFormat(eGold,  PosX + 87, PosY + 38 + posM, 37, 1, "%d", this->m_Data[index].m_Kills);
				this->DrawFormat(eGold,  PosX + 87, PosY + 48 + posM, 37, 1, "%d", this->m_Data[index].m_Deads);

				this->DrawFormat(eAncient,  PosX + 50, PosY + 58 + posM, 60, 1, "%s", this->m_Data[index].m_Vip);
				this->DrawFormat(eOrange,  PosX + 50, PosY + 68 + posM, 60, 1, "%s", classename);
			}
			else if (gProtect.m_MainInfo.RankUserType == 4)
			{

				this->DrawFormat(eWhite180, PosX+0, PosY -105, 80, 3, "%s", this->m_Data[index].szTitleRank);
				//-- Imagen Rank
				pDrawImage(gInterface.Data[this->m_Data[index].m_Rank+1].ModelID, (float)PosX+24, (float)PosY -68, 60.0, 60.0,0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				//--
			}
			else if (gProtect.m_MainInfo.RankUserType == 5)
			{
			glColor4f((GLfloat)0.0, (GLfloat)0.0, (GLfloat)0.0, (float)0.4);
			pDrawBarForm((float)(PosX + 60), (float)(PosY + 15), 120.0f, 50.0f, 0.0f, 0);
			pGLSwitchBlend();
			this->DrawFormat(eRed2, PosX + 70, PosY + 18, 90, 3, "Rank: %s", this->m_Data[index].szTitleRank);
			this->DrawFormat(eWhite, PosX + 60, PosY + 29, 115, 3, "Level: %d | Resets: %d", this->m_Data[index].m_Level, this->m_Data[index].m_Resets);
			this->DrawFormat(eWhite, PosX + 60, PosY + 38, 115, 3, "Kills:    %d | Deaths:  %d", this->m_Data[index].m_Kills, this->m_Data[index].m_Deads);
			this->DrawFormat(eWhite, PosX + 60, PosY + 51, 115, 3, "MResets:    %d", this->m_Data[index].m_MResets);

			pDrawImage(gInterface.Data[this->m_Data[index].m_Rank + 1].ModelID, (float)PosX + 99, (float)PosY - 15, 50.0, 50.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);

			}
			else 
			{
				glColor4f(0.0, 0.0, 0.0, 0.8);
				pDrawBarForm((float)(PosX+40), (float)(PosY - 8), 185.0f, 80.0f, 0.0f, 0);
				pGLSwitchBlend();

				this->DrawFormat(eRed2,		 PosX + 60, PosY - 6, 105, 3, "Character Status:");
		
				this->DrawFormat(eWhite,  PosX + 60, PosY + 8, 15, 1, "Lvl:");
				this->DrawFormat(eWhite,  PosX + 60, PosY + 18, 15, 1, "Str:");
				this->DrawFormat(eWhite,  PosX + 60, PosY + 28, 15, 1, "Agi:");
				this->DrawFormat(eWhite,  PosX + 60, PosY + 38, 15, 1, "Vit:");
				this->DrawFormat(eWhite,  PosX + 60, PosY + 48, 15, 1, "Ene:");
				this->DrawFormat(eWhite,  PosX + 60, PosY + 58, 15, 1, "Com:");

				this->DrawFormat(eGold,  PosX + 80, PosY +  8, 45, 1, "%d ", this->m_Data[index].m_Level);
				this->DrawFormat(eGold,  PosX + 80, PosY + 18, 45, 1, "%d ", this->m_Data[index].m_For);
				this->DrawFormat(eGold,  PosX + 80, PosY + 28, 45, 1, "%d ", this->m_Data[index].m_Agi);
				this->DrawFormat(eGold,  PosX + 80, PosY + 38, 45, 1, "%d ", this->m_Data[index].m_Vit);
				this->DrawFormat(eGold,  PosX + 80, PosY + 48, 45, 1, "%d ", this->m_Data[index].m_Ene);
				this->DrawFormat(eGold,  PosX + 80, PosY + 58, 45, 1, "%d ", this->m_Data[index].m_Com);

				int posM = 0;

				if(gProtect.m_MainInfo.RankUserShowReset != 0)
				{
					this->DrawFormat(eWhite,  PosX + 120, PosY + 8, 25, 1,  "Resets:");
					this->DrawFormat(eGold,  PosX + 147, PosY + 8, 37, 1,  "%d", this->m_Data[index].m_Resets);	
				}
				else
				{
					posM -= 10;
				}

				if(gProtect.m_MainInfo.RankUserShowMasterReset != 0)
				{
					this->DrawFormat(eWhite,  PosX + 120, PosY + 18 + posM, 25, 1, gCustomMessage.GetMessage(68));
					this->DrawFormat(eGold,  PosX + 147, PosY + 18 + posM, 37, 1, "%d", this->m_Data[index].m_MResets);
				}
				else
				{
					posM -= 10;
				}

				this->DrawFormat(eWhite,  PosX + 120, PosY + 28 + posM, 25, 1, "Kills:");
				this->DrawFormat(eWhite,  PosX + 120, PosY + 38 + posM, 25, 1, "Deaths:");
				this->DrawFormat(eGold,  PosX + 147, PosY + 28 + posM, 37, 1, "%d", this->m_Data[index].m_Kills);
				this->DrawFormat(eGold,  PosX + 147, PosY + 38 + posM, 37, 1, "%d", this->m_Data[index].m_Deads);

				this->DrawFormat(eAncient,  PosX + 120, PosY + 48 + posM, 60, 1, "%s", this->m_Data[index].m_Vip);
				this->DrawFormat(eOrange,  PosX + 120, PosY + 58 + posM, 60, 1, "%s", classename);

				this->DrawFormat(eGold, PosX + 133, PosY -5, 126, 3, "%s", this->m_Data[index].szTitleRank);
				this->DrawFormat(eGold, PosX + 5, PosY - 6, 126, 3, "%s", name);

				//-- Imagen Rank al pasar mouse
				gInterface.DrawIMG(this->m_Data[index].m_Rank+1, PosX + 170, PosY + 4,1,1);
				//--
			}
		
		}
		else
		{
		}

		pGLSwitch();
	}
	// ---
	pGLSwitch();
	// ---
	glColor3f(1.0, 1.0, 1.0);
}

int CCustomRankUser::DrawFormat(DWORD Color, int PosX, int PosY, int Width, int Align, LPCSTR Text, ...)
{
	char Buff[2048] = {0};
	// ---
	int BuffLen = sizeof(Buff)-1;
	// ---
	ZeroMemory(Buff, BuffLen);
	// ---
	va_list args;
	// ---
	va_start(args, Text);
	// ---
	int Len = vsprintf_s(Buff, BuffLen, Text, args);
	// ---
	va_end(args);
	// ---
	int LineCount = 0;
	// ---
	char * Line = strtok(Buff, "\n");
	// ---
	while(Line != NULL)
	{
		pDrawColorText(Line, PosX, PosY, Width, 5, Color, 9, Align);
		// ---
		PosY += 10;
		// ---
		Line = strtok(NULL, "\n");
	}
	// ---
	return PosY;
}

void CCustomRankUser::Test() // OK
{
	((void(*)())0x00576E40)();
	// ---
	gCustomRankUser.DrawInfo();
	// ---
	int PosX, PosY, LifeProgress, ShieldProgress;
	// ---
	float LifeBarWidth = 38.0f;
	// ---
	char LifeDisplay[20];
	// ---
	VAngle Angle;
	// --
	CPreviewManager * gPreview = new CPreviewManager;

	for(int n=0;n < MAX_MAIN_VIEWPORT;n++)
	{

		gPreview->ObjSelect(n, pObjPreviewThis); // -> Coletar Informações da ObjPreview

		DWORD ViewportAddress = ((DWORD(__thiscall*)(void*,DWORD))0x0096A4C0)(((void*(*)())0x00402BC0)(),n);

		if(!ViewportAddress)
		{
			continue;
		}


		if(*(BYTE*)(ViewportAddress+0x268) == 0 || *(BYTE*)(ViewportAddress+0x0E) == 1)
		{
			continue;
		}
	}
}
void CCustomRankUser::GCReqRankLevelUser(PMSG_CUSTOM_RANKUSER * aRecv)
{
	if(aRecv == NULL)
	{
		return;
	}
	// ---
	this->m_Data[aRecv->iIndex].m_Enabled = true;
	this->m_Data[aRecv->iIndex].m_Level = aRecv->iLevel;
	this->m_Data[aRecv->iIndex].m_Resets = aRecv->iReset;
	this->m_Data[aRecv->iIndex].m_MResets = aRecv->iMReset;
	this->m_Data[aRecv->iIndex].m_Kills = aRecv->iKills;
	this->m_Data[aRecv->iIndex].m_Deads = aRecv->iDeads;
	this->m_Data[aRecv->iIndex].m_For = aRecv->iFor;
	this->m_Data[aRecv->iIndex].m_Agi = aRecv->iAgi;	
	this->m_Data[aRecv->iIndex].m_Ene = aRecv->iEne;
	this->m_Data[aRecv->iIndex].m_Vit = aRecv->iVit;
	this->m_Data[aRecv->iIndex].m_Com = aRecv->iCom;
	this->m_Data[aRecv->iIndex].m_Classe = aRecv->iClasse;
	this->m_Data[aRecv->iIndex].m_Rank = aRecv->iRank;
	// ---
	memcpy(this->m_Data[aRecv->iIndex].szTitleRank, aRecv->szName, sizeof(this->m_Data[aRecv->iIndex].szTitleRank));
	memcpy(this->m_Data[aRecv->iIndex].m_Vip, aRecv->iVip, sizeof(this->m_Data[aRecv->iIndex].m_Vip));
}

bool CPreviewManager::ObjCheck(int index, int pThis)
{
	if(pThis == NULL)
	{
		return false;
	}
	// ---
	if(!CS_GET_STRUCT(index, pThis))
	{
		return false;
	}
	// ---
	return true;
}

bool CPreviewManager::ObjSelect(int index, int pThis)
{
	if(pThis == NULL)
	{
		return false;
	}
	// ---
	this->Index = *(WORD*)(CS_GET_STRUCT(index, pThis) + 86);
	this->Live = *(BYTE*)(CS_GET_STRUCT(index, pThis) + 616);
	this->Type = *(BYTE*)(CS_GET_STRUCT(index, pThis) + 634);
	this->IsSafeZone = *(BYTE*)(CS_GET_STRUCT(index, pThis) + 14);
	// ---
	this->Angle.X = *(float*)(CS_GET_STRUCT(index, pThis) + 864);
	this->Angle.Y = *(float*)(CS_GET_STRUCT(index, pThis) + 868);
	this->Angle.Z = *(float*)(CS_GET_STRUCT(index, pThis) + 872) + *(float*)(CS_GET_STRUCT(index, pThis) + 836) + 100.0f;
	// ---
	return true;
}