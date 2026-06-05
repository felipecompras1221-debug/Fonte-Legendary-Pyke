#include "stdafx.h"
#include "Common.h"
#include "CustomCommandInfo.h"
#include "CustomEventTime.h"
#include "CustomRanking.h"
#include "Interface.h"
#include "Import.h"
#include "Reconnect.h"
#include "TMemory.h"
#include "Defines.h"
#include "OffTrade.h"
#include "Protect.h"
#include "Protocol.h"
#include "PrintPlayer.h"
#include "User.h"
#include "Util.h"
#include "array.h"
#include "Offset.h"
#include "StatsAdvance.h"
#include "CustomCloak.h"
#include "ChatExpanded.h"
#include "Camera.h"
#include "TrayModeNew.h"
#include "Controller.h"
#include "postInterface.h"
#include "Ruud.h"
#include "Inter3.h"
#include "InterEx.h"
#include "Central.h"
#include "NPCRuud.h"
#include "ExQuestWinSystem.h"
#include "Achievements.h"
#include "NewInterface.h"
#include "ResetSystem.h"
#include "GrandResetSystem.h"
#include "ServerInfo.h"
#include "ChangeClass.h"
#include "PartySearch.h"
#include "PartySearchSettings.h"
#include "MuHelper.h"
#include "WindowsStruct.h"
#include "CustomRankUser.h"
#include "MiniMap.h"
#include "GLFont.h"
#include "NewUiInterface.h"
#include "DailyReward.h"
#include "Item.h"
#include "CustomFont.h"
#include "screen.h"
#include "Layout.h"
#include <Windows.h>  // Necessário para GetAsyncKeyState

Interface gInterface;

Interface::Interface()
{
}

Interface::~Interface()
{
}
void Interface::RenderObjectSystem()
{
	if(gProtect.m_MainInfo.MonitorMS == 1){
		gInterface.lastReport = GetTickCount();
		gInterface.frameCount = 0;
	}
	if(gProtect.m_MainInfo.MonitorFPS == 1){
		gInterface.iniciador = 1;
	}

	this->BindObject(eMenu_MAIN, 0x7A5A, 222, 292, -1, -1);
	this->BindObject(eMenu_TITLE, 0x7A63, 230, 67, -1, -1);
	this->BindObject(eMenu_CLOSE, 0x7EC5, 36, 29, -1, -1);
	this->BindObject(eMenu_FRAME, 0x7A58, 230, 15, -1, -1);
	this->BindObject(eMenu_FOOTER, 0x7A59, 230, 50, -1, -1);
	this->BindObject(eMenu_DIV, 0x7A62, 223, 21, -1, -1);
	this->BindObject(eMenu_OPT1, 0x7A5E, 107.1f, 29, -1, -1);
	this->BindObject(eMenu_OPT2, 0x7A5E, 107.1f, 29, -1, -1);
	this->BindObject(eMenu_OPT3, 0x7A5E, 107.1f, 29, -1, -1);
	this->BindObject(eMenu_OPT4, 0x7A5E, 107.1f, 29, -1, -1);
	this->BindObject(eMenu_OPT5, 0x7A5E, 107.1f, 29, -1, -1);
	this->BindObject(eMenu_OPT6, 0x7A5E, 107.1f, 29, -1, -1);
	this->BindObject(eMenu_OPT20, 0x7A5E, 107.1f, 29, -1, -1);
	//--
	this->BindObject(eTIME, 30847, 131, 70, -10, 359);
	this->BindObject(eFlag01, 0x7880, 78, 78, -1, -1);
	this->BindObject(eFlag02, 0x7881, 78, 78, -1, -1);
	this->BindObject(eFlag03, 0x7882, 78, 78, -1, -1);
	this->BindObject(eFlag04, 0x7883, 78, 78, -1, -1);
	this->BindObject(eFlag05, 0x7884, 78, 78, -1, -1);
	this->BindObject(eFlag06, 0x7885, 78, 78, -1, -1);
	this->BindObject(eFlag07, 0x7886, 78, 78, -1, -1);
	this->BindObject(eFlag08, 0x7887, 78, 78, -1, -1);
	this->BindObject(eFlag09, 0x7888, 78, 78, -1, -1);
	this->BindObject(eFlag10, 0x7889, 78, 78, -1, -1);
	this->BindObject(eFlag11, 0x7890, 78, 78, -1, -1);
	this->BindObject(eFlag12, 0x7891, 78, 78, -1, -1);
	this->BindObject(eFlag13, 0x7892, 78, 78, -1, -1);
	this->BindObject(eFlag14, 0x7893, 78, 78, -1, -1);
	this->BindObject(eFlag15, 0x7894, 78, 78, -1, -1);
	this->BindObject(eFlag16, 0x7895, 78, 78, -1, -1);
	this->BindObject(eFlag17, 0x7896, 78, 78, -1, -1);
	this->BindObject(eFlag18, 0x7897, 78, 78, -1, -1);
	this->BindObject(eFlag19, 0x7898, 78, 78, -1, -1);
	this->BindObject(eFlag20, 0x7899, 78, 78, -1, -1);
	this->BindObject(eFlag21, 0x7900, 78, 78, -1, -1);
	this->BindObject(eFlag22, 0x7901, 78, 78, -1, -1);
	//--
	this->BindObject(eRanking, 0x7902, 179, 27, -1, -1);
	this->BindObject(eSAMPLEBUTTON, 0x7903, 25, 40, -1, -1);
	this->BindObject(eSAMPLEBUTTON2, 0x7904, 25, 40, -1, -1);
	//--
	this->BindObject(eVip_MAIN, 0x7A5A, 222, 300, 205, -1);
	this->BindObject(eVip_TITLE, 0x7A63, 230, 67, -1, -1);
	this->BindObject(eVip_FRAME, 0x7A58, 230, 15, -1, -1);
	this->BindObject(eVip_FOOTER, 0x7A59, 230, 50, -1, -1);
	this->BindObject(eVip_DIV, 0x7A62, 223, 21, -1, -1);
	this->BindObject(eVip_CLOSE, 0x7EC5, 36, 29, -1, -1);
	this->BindObject(eVip_BRONZE, 0x7A5E, 108, 29, -1, -1);
	this->BindObject(eVip_SILVER, 0x7A5E, 108, 29, -1, -1);
	this->BindObject(eVip_GOLD, 0x7A5E, 108, 29, -1, -1);
	this->BindObject(eVip_PLATINUM, 0x7A5E, 108, 29, -1, -1);
	this->BindObject(eVip_STATUS, 0x7A5E, 108, 29, -1, -1);
	
	//--
	this->BindObject(eCommand_MAIN, 0x7A5A, 222, 300, 205, -1);
	this->BindObject(eCommand_TITLE, 0x7A63, 230, 67, -1, -1);
	this->BindObject(eCommand_FRAME, 0x7A58, 230, 15, -1, -1);
	this->BindObject(eCommand_FOOTER, 0x7A59, 230, 50, -1, -1);
	this->BindObject(eCommand_DIV, 0x7A62, 223, 21, -1, -1);
	this->BindObject(eCommand_CLOSE, 0x7EC5, 36, 29, -1, -1);
	//--
	this->BindObject(eRanking_MAIN, 0x7A5A, 222, 300, 205, -1);
	this->BindObject(eRanking_CLOSE, 0x7EC5, 36, 29, -1, -1);
	//--
	this->BindObject(eEventTime_MAIN, 0x7A5A, 222, 300, 205, -1);
	this->BindObject(eEventTime_CLOSE, 0x7EC5, 36, 29, -1, -1);
	//--
	this->BindObject(eCONFIRM_MAIN, 0x7A5A, 222, 120, 205, -1);
	this->BindObject(eCONFIRM_TITLE, 0x7A63, 230, 67, -1, -1);
	this->BindObject(eCONFIRM_FRAME, 0x7A58, 230, 15, -1, -1);
	this->BindObject(eCONFIRM_FOOTER, 0x7A59, 230, 50, -1, -1);
	this->BindObject(eCONFIRM_DIV, 0x7A62, 223, 21, -1, -1);
	this->BindObject(eCONFIRM_BTN_OK, 0x7A5B, 54, 30, -1, -1);
	this->BindObject(eCONFIRM_BTN_CANCEL, 0x7A5C, 54, 30, -1, -1);
	this->BindObject(eLogo, 0x7905, 150, 114, -1, -1);
	//Custom Store
	if( gProtect.m_MainInfo.CustomInterfaceType == 3 )
	{
		this->BindObject(eOFFTRADE_JoB, 51522, 40, 17, -1, -1);
		this->BindObject(eOFFTRADE_JoS, 51522, 40, 17, -1, -1);
		this->BindObject(eOFFTRADE_JoC, 51522, 40, 17, -1, -1);
		this->BindObject(eOFFTRADE_WCC, 51522, 40, 17, -1, -1);
		this->BindObject(eOFFTRADE_WCP, 51522, 40, 17, -1, -1);
		this->BindObject(eOFFTRADE_WCG, 51522, 40, 17, -1, -1);
		this->BindObject(eOFFTRADE_OPEN, 51522, 108, 30, -1, -1);
	}
	else
	{
		this->BindObject(eOFFTRADE_JoB, 0x7908, 40, 19, -1, -1);
		this->BindObject(eOFFTRADE_JoS, 0x7908, 40, 19, -1, -1);
		this->BindObject(eOFFTRADE_JoC, 0x7908, 40, 19, -1, -1);
		this->BindObject(eOFFTRADE_WCC, 0x7908, 40, 19, -1, -1);
		this->BindObject(eOFFTRADE_WCP, 0x7908, 40, 19, -1, -1);
		this->BindObject(eOFFTRADE_WCG, 0x7908, 40, 19, -1, -1);
		this->BindObject(eOFFTRADE_OPEN, 0x7BFD, 108, 30, -1, -1);
	}
	//-- custom
	this->BindObject(eSTORE_CLOSE, 0x7BFD, 108, 30, -1, -1);
	//Minimap
	this->BindObject(ePLAYER_POINT, 31460, 3, 3, -1, -1);
	this->BindObject(eNULL_MAP, 31461, 128, 128, -1, -1);
	this->BindObject(eLORENCIA_MAP, 31462, 128, 128, -1, -1);
	this->BindObject(eDUNGEON_MAP, 31463, 128, 128, -1, -1);
	this->BindObject(eDEVIAS_MAP, 31464, 128, 128, -1, -1);
	this->BindObject(eNORIA_MAP, 31465, 128, 128, -1, -1);
	this->BindObject(eLOSTTOWER_MAP, 31466, 128, 128, -1, -1);
	this->BindObject(eSTADIUM_MAP, 61465, 128, 128, -1, -1);
	this->BindObject(eATLANS_MAP, 31467, 128, 128, -1, -1);
	this->BindObject(eTarkan_MAP, 31468, 128, 128, -1, -1);
	this->BindObject(eElbeland_MAP, 31469, 128, 128, -1, -1);
	this->BindObject(eICARUS_MAP, 31470, 128, 128, -1, -1);
	this->BindObject(eLANDOFTRIALS_MAP, 31461, 128, 128, -1, -1);
	this->BindObject(eAIDA_MAP, 31472, 128, 128, -1, -1);
	this->BindObject(eCRYWOLF_MAP, 31473, 128, 128, -1, -1);
	this->BindObject(eKANTRU_MAP, 31474, 128, 128, -1, -1);
	this->BindObject(eKANTRU3_MAP, 31475, 128, 128, -1, -1);
	this->BindObject(eBARRACKS_MAP, 31476, 128, 128, -1, -1);
	this->BindObject(eCALMNESS_MAP, 31477, 128, 128, -1, -1);
	this->BindObject(eRAKLION_MAP, 31478, 128, 128, -1, -1);
	this->BindObject(eVULCANUS_MAP, 31479, 128, 128, -1, -1);
	this->BindObject(eKALRUTAN_MAP, 31480, 128, 128, -1, -1);
	this->BindObject(eKALRUTAN2_MAP, 31481, 128, 128, -1, -1);
	this->BindObject(eNextCommand, 31659, 17, 18, -1, -1);
	this->BindObject(ePrevCommand, 31658, 17, 18, -1, -1);
	this->BindObject(eNextEvent, 31659, 17, 18, -1, -1);
	this->BindObject(ePrevEvent, 31658, 17, 18, -1, -1);
	this->BindObject(eCamera3DInit, 31659, 17, 18, -1, -1);
	this->BindObject(eCamera3DSwitch, 31659, 17, 18, -1, -1);
	this->Data[eTIME].OnShow = true;
	if(gProtect.m_MainInfo.CustomInterfaceType == 3 || gProtect.m_MainInfo.CustomInterfaceType == 4)
	{
		this->BindObject(ButtonSettings, 51522, 19, 19, -1, -1);
		this->BindObject(ButtonStart, 51522, 19, 19, -1, -1);
		this->BindObject(ButtonStop, 51522, 19, 19, -1, -1);
	}
	else
	{
		this->BindObject(ButtonSettings, 31761, 18, 13.3, -1, -1);
		this->BindObject(ButtonStart, 31762, 18, 13.3, -1, -1);
		this->BindObject(ButtonStop, 31763, 18, 13.3, -1, -1);
	}
	this->BindObject(ButtonStartAttack, 31593, 15, 15, -15, -15);
	//--
	this->BindObject(eJewelOfBank, 51522, 230.0, 270.0, -1, -1);
	this->BindObject(eJewelOfBankPush, 71521, 59, 28, -1, -1);
	this->BindObject(eJewelOfBankRemove, 71521, 59, 28, -1, -1);
	this->BindObject(eJewelOfBankClose, 71521, 59, 28, -1, -1);

	switch(gProtect.m_MainInfo.CustomInterfaceType)
	{
	case 1:
	case 2:
		//--
		/*if (gProtect.m_MainInfo.CustomMenuType == 1)
		{
			this->BindObject(eMenu, 0x7906, 102, 29, -1, -1);
		}
		else
		{*/
			this->BindObject(eMenu, 0x7906, 16, 12, -1, -1);
			this->BindObject(eMenuBG, 0x7907, 36, 18, 174, 0);
		//}
		/*//-- Interface MiniMapa 97/99
		//this->BindObject(MINIMAP_FRAME, 31608, 154, 162, -10, 359);
		this->BindObject(MINIMAP_TIME_FRAME, 31609, 134.0, 37.0, -10, 359);
		this->BindObject(MINIMAP_BUTTOM, 31617, 38.0f, 24.0f, -10, 569);*/
		//---
		if(gProtect.m_MainInfo.CustomInterfaceType == 1||gProtect.m_MainInfo.CustomInterfaceType == 2)
		{
		this->BindObject(eDragonLeft, 2337, 108.0, 45.0, 0.0, 383.5);
		this->BindObject(eDragonRight, 2336, 108.0, 45.0, 532.0, 383.5);
		this->BindObject(eParty, iNewParty, 25, 25, 348, 449);
		this->BindObject(eCharacter, iNewCharacter, 25, 25, 379, 449);
		this->BindObject(eInventory, iNewInventory, 25, 25, 409, 449);
		this->BindObject(eFriend, iNewWinpush, 52, 18, 581, 432);
		this->BindObject(eGuild, iNewGuild, 52, 18, 581, 454);
		}
		//-> Custom Interface S2
		if(gProtect.m_MainInfo.CustomInterfaceType == 2){
		this->BindObject(eFastMenu, iNewFastMenu, 53, 19, 5, 432);
		}
		break;
	case 3:
	case 4:
		this->BindObject(eButton1, 61525, 43.0f, 17.0f, -43.0f, -17.0f);
		this->BindObject(eButton2, 61525, 43.0f, 17.0f, -43.0f, -17.0f);
		this->BindObject(eButton3, 61525, 43.0f, 17.0f, -43.0f, -17.0f);
		this->BindObject(eButton4, 61525, 43.0f, 17.0f, -43.0f, -17.0f);
		this->BindObject(eButton5, 61525, 43.0f, 17.0f, -43.0f, -17.0f);

		/*if (gProtect.m_MainInfo.CustomMenuType == 1)
		{
			this->BindObject(eMenu, 0x7906, 102, 29, -1, -1);
		}
		else
		{*/
			this->BindObject(eMenu, 51522, 19, 19, -1, -1);
			this->BindObject(eMenuBG, 51522, 36, 18, 174, 0);
		//}
		//Ex700
		this->BindObject(chatbackground, 51545, 300.0f, 128.0f, -10, 569);
		this->BindObject(eShop, 51522, 19.5f, 19.5f, -1, -1);
		this->BindObject(eCharacter, 51522, 19.5f, 19.5f, -1, -1);
		this->BindObject(eInventory, 51522, 19.5f, 19.5f, -1, -1);
		this->BindObject(eQuest, 51522, 19.5f, 19.5f, -1, -1);
		this->BindObject(eCommunity, 51522, 19.5f, 19.5f, -1, -1);
		this->BindObject(eSystem, 51522, 19.5f, 19.5f, -1, -1);
		break;
	default:
		/*if (gProtect.m_MainInfo.CustomMenuType == 1)
		{
			this->BindObject(eMenu, 0x7906, 102, 29, -1, -1);
		}
		else
		{*/
			this->BindObject(eMenu, 0x7906, 16, 12, -1, -1);
			this->BindObject(eMenuBG, 0x7907, 36, 18, 174, 0);
		//}
		break;
	}
	if(gProtect.m_MainInfo.InventoryUPGRADE == 1)
	{
		this->BindObject(eMoney1, 0x7909, 75, 13, -1, -1);
		this->BindObject(eMoney2, 0x7910, 75, 13, -1, -1);
		this->BindObject(eMoney3, 0x7911, 45, 13, -1, -1);
	}

	this->BindObject(OBJECT_RESET_MAIN, 0x7A5A, 222, 303, -1, -1);
	this->BindObject(OBJECT_RESET_TITLE, 0x7A63, 230, 67, -1, -1);
	this->BindObject(OBJECT_RESET_FRAME, 0x7A58, 230, 15, -1, -1);
	this->BindObject(OBJECT_RESET_FOOTER, 0x7A59, 230, 50, -1, -1);
	this->BindObject(OBJECT_RESET_DIV, 0x7A62, 223, 21, -1, -1);
	this->BindObject(OBJECT_RESET_INFO_BG, 0x7AA3, 170, 21, -1, -1);
	this->BindObject(OBJECT_RESET_MONEY_BG, 0x7A89, 170, 26, -1, -1);
	this->BindObject(OBJECT_RESET_CLOSE, 0x7EC5, 36, 29, -1, -1);
	this->BindObject(OBJECT_RESET_FINISH, 0x7A5E, 106, 29, -1, -1);

	this->BindObject(OBJECT_GRESET_MAIN, 0x7A5A, 222, 303, -1, -1);
	this->BindObject(OBJECT_GRESET_TITLE, 0x7A63, 230, 67, -1, -1);
	this->BindObject(OBJECT_GRESET_FRAME, 0x7A58, 230, 15, -1, -1);
	this->BindObject(OBJECT_GRESET_FOOTER, 0x7A59, 230, 50, -1, -1);
	this->BindObject(OBJECT_GRESET_DIV, 0x7A62, 223, 21, -1, -1);
	this->BindObject(OBJECT_GRESET_INFO_BG, 0x7AA3, 170, 21, -1, -1);
	this->BindObject(OBJECT_GRESET_MONEY_BG, 0x7A89, 170, 26, -1, -1);
	this->BindObject(OBJECT_GRESET_CLOSE, 0x7EC5, 36, 29, -1, -1);
	this->BindObject(OBJECT_GRESET_FINISH, 0x7A5E, 128, 29, -1, -1);

	this->BindObject(eCHANGINGCLASS_MAIN, 0x7A5A, 222, 303, -1, -1);
	this->BindObject(eCHANGINGCLASS_TITLE, 0x7A63, 230, 67, -1, -1);
	this->BindObject(eCHANGINGCLASS_FRAME, 0x7A58, 230, 15, -1, -1);
	this->BindObject(eCHANGINGCLASS_FOOTER, 0x7A59, 230, 50, -1, -1);
	this->BindObject(eCHANGINGCLASS_DIV, 0x7A62, 223, 21, -1, -1);
	this->BindObject(eCHANGINGCLASS_CLOSE, 0x7EC5, 36, 29, -1, -1);
	this->BindObject(eCHANGINGCLASS_INFOBG, 0x7AA3, 170, 21, -1, -1);
	this->BindObject(eCHANGINGCLASS_MONEYBG, 0x7A89, 170, 26, -1, -1);
	this->BindObject(eCHANGINGCLASS_DW, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eCHANGINGCLASS_DK, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eCHANGINGCLASS_ELF, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eCHANGINGCLASS_MG, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eCHANGINGCLASS_DL, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eCHANGINGCLASS_SUM, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eCHANGINGCLASS_RF, 0x7A5E, 106, 29, -1, -1);

	this->BindObject(ePARTYSETTINGS_MAIN, 0x7A5A, 222, 345, -1, -1);
	this->BindObject(ePARTYSETTINGS_TITLE, 0x7A63, 230, 67, -1, -1);
	this->BindObject(ePARTYSETTINGS_FRAME, 0x7A58, 230, 15, -1, -1);
	this->BindObject(ePARTYSETTINGS_FOOTER, 0x7A59, 230, 50, -1, -1);
	this->BindObject(ePARTYSETTINGS_DIV, 0x7A62, 223, 21, -1, -1);
	this->BindObject(ePARTYSETTINGS_CLOSE, 0x7EC5, 36, 29, -1, -1);
	this->BindObject(ePARTYSETTINGS_SYSTEM_ACTIVE, 0x7BAE, 15, 15, -1, -1);
	this->BindObject(ePARTYSETTINGS_ONLY_GUILD, 0x7BAE, 15, 15, -1, -1);
	this->BindObject(ePARTYSETTINGS_ONE_CLASS, 0x7BAE, 15, 15, -1, -1);
	this->BindObject(ePARTYSETTINGS_DARK_WIZARD, 0x7BAE, 15, 15, -1, -1);
	this->BindObject(ePARTYSETTINGS_DARK_KNIGHT, 0x7BAE, 15, 15, -1, -1);
	this->BindObject(ePARTYSETTINGS_ELF, 0x7BAE, 15, 15, -1, -1);
	this->BindObject(ePARTYSETTINGS_MAGIC_GLADIATOR, 0x7BAE, 15, 15, -1, -1);
	this->BindObject(ePARTYSETTINGS_DARK_LORD, 0x7BAE, 15, 15, -1, -1);
	this->BindObject(ePARTYSETTINGS_SUMMONER, 0x7BAE, 15, 15, -1, -1);
	this->BindObject(ePARTYSETTINGS_RAGE_FIGHTER, 0x7BAE, 15, 15, -1, -1);
	this->BindObject(ePARTYSETTINGS_LEVEL_MINUS, 0x7C0D, 16, 15, -1, -1);
	this->BindObject(ePARTYSETTINGS_LEVEL_PLUS, 0x7AA4, 16, 15, -1, -1);
	this->BindObject(ePARTYSETTINGS_OK, 0x7A5B, 54, 30, -1, -1);

	this->BindObject(ePARTYSEARCH_MAIN, 0x7A5A, 222, 345, -1, -1);
	this->BindObject(ePARTYSEARCH_TITLE, 0x7A63, 230, 67, -1, -1);
	this->BindObject(ePARTYSEARCH_FRAME, 0x7A58, 230, 15, -1, -1);
	this->BindObject(ePARTYSEARCH_FOOTER, 0x7A59, 230, 50, -1, -1);
	this->BindObject(ePARTYSEARCH_DIV, 0x7A62, 223, 21, -1, -1);
	this->BindObject(ePARTYSEARCH_CLOSE, 0x7EC5, 36, 29, -1, -1);
	this->BindObject(ePARTYSEARCH_LEFT, 0x7E56, 20, 23, -1, -1);
	this->BindObject(ePARTYSEARCH_RIGHT, 0x7E57, 20, 23, -1, -1);

	this->BindObject(eNEWS_MAIN, 0x7A5A, 222, 303, -1, -1);
	this->BindObject(eNEWS_TITLE, 0x7A63, 230, 67, -1, -1);
	this->BindObject(eNEWS_FRAME, 0x7A58, 230, 15, -1, -1);
	this->BindObject(eNEWS_FOOTER, 0x7A59, 230, 50, -1, -1);
	this->BindObject(eNEWS_DIV, 0x7A62, 223, 21, -1, -1);
	this->BindObject(eNEWS_INFOBG, 0x787D, 170, 21, -1, -1);
	this->BindObject(eNEWS_CLOSE, 0x7EC5, 36, 29, -1, -1);
	this->BindObject(eNEWS_BACK, 0x7A5E, 128, 29, -1, -1);

	this->BindObject(eLayout_BACK, 31658, 17, 18, -1, -1);
	this->BindObject(eLayout_FORWARD, 31659, 17, 18, -1, -1);

	this->BindObject(eNextWare, 31659, 17, 18, -1, -1);
	this->BindObject(ePrevWare, 31658, 17, 18, -1, -1);
	this->BindObject(eWAREHOUSE_MAIN, 0x7A5A, 222, 211, -1, -1);
	this->BindObject(eWAREHOUSE_TITLE, 0x7A63, 230, 67, -1, -1);
	this->BindObject(eWAREHOUSE_FRAME, 0x7A58, 230, 15, -1, -1);
	this->BindObject(eWAREHOUSE_FOOTER, 0x7A59, 230, 50, -1, -1);
	this->BindObject(eWAREHOUSE_DIV, 0x7A62, 223, 21, -1, -1);
	this->BindObject(eWAREHOUSE_CLOSE, 0x7EC5, 36, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM1, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM2, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM3, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM4, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM5, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM6, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM7, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM8, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM9, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM10, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM11, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM12, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM13, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM14, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM15, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM16, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM17, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM18, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM19, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM20, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM21, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM22, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM23, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM24, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM25, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM26, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM27, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM28, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM29, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM30, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM31, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM32, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM33, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM34, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM35, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM36, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM37, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM38, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM39, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM40, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM41, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM42, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM43, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM44, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM45, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM46, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM47, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM48, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM49, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM50, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM51, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM52, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM53, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM54, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM55, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM56, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM57, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM58, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM59, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM60, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM61, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM62, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM63, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM64, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM65, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM66, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM67, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM68, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM69, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM70, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM71, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM72, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM73, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM74, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM75, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM76, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM77, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM78, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM79, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM80, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM81, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM82, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM83, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM84, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM85, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM86, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM87, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM88, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM89, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM90, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM91, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM92, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM93, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM94, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM95, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM96, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM97, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM98, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM99, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM100, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM101, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM102, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM103, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM104, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM105, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM106, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM107, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM108, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM109, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM110, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM111, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM112, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM113, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM114, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM115, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM116, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM117, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM118, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM119, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM120, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM121, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM122, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM123, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM124, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM125, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM126, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM127, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM128, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM129, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM130, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM131, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM132, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM133, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM134, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM135, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM136, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM137, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM138, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM139, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM140, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM141, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM142, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM143, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM144, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM145, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM146, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM147, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM148, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM149, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM150, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM151, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM152, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM153, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM154, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM155, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM156, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM157, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM158, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM159, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM160, 0x7A5E, 106, 29, -1, -1);

	this->BindObject(eSTATSADD_MAIN, 0x7A5A, 222, 226, -1, -1);
	this->BindObject(eSTATSADD_TITLE, 0x7A63, 230, 67, -1, -1);
	this->BindObject(eSTATSADD_FRAME, 0x7A58, 230, 15, -1, -1);
	this->BindObject(eSTATSADD_FOOTER, 0x7A59, 230, 50, -1, -1);
	this->BindObject(eSTATSADD_CLOSE, 0x7EC5, 36, 29, -1, -1);
	this->BindObject(eSTATSADD_TEXTBOX01, 400004, 170, 21, -1, -1);
	this->BindObject(eSTATSADD_STATBOX01, 0x7AA3, 170, 21, -1, -1);
	this->BindObject(eSTATSADD_STATBOX02, 0x7AA3, 170, 21, -1, -1);
	this->BindObject(eSTATSADD_STATBOX03, 0x7AA3, 170, 21, -1, -1);
	this->BindObject(eSTATSADD_STATBOX04, 0x7AA3, 170, 21, -1, -1);
	this->BindObject(eSTATSADD_STATBOX05, 0x7AA3, 170, 21, -1, -1);
	this->BindObject(eSTATSADD_BTN_OK, 0x7A5B, 54, 30, -1, -1);
	this->BindObject(eSTATSADD_STEP10, 0x7BAE, 15, 15, -1, -1);
	this->BindObject(eSTATSADD_STEP100, 0x7BAE, 15, 15, -1, -1);
	this->BindObject(eSTATSADD_STEP1000, 0x7BAE, 15, 15, -1, -1);

	this->BindObject(eCHARINFO_BTN_STAT, 0x7AA4, 16, 15, -1, -1);

	gNewInterface.Load();

	gAchievements.BindImages();
	g_ExWinQuestSystem.BindImages();

	SetRange((LPVOID)0x00842086, 5, ASM::NOP);
	SetRange((LPVOID)0x0084234F, 5, ASM::NOP);
	SetRange((LPVOID)0x008423C3, 5, ASM::NOP);
	SetOp((LPVOID)oLoadSomeForm_Call, this->LoadImages, ASM::CALL);
	SetOp((LPVOID)oDrawInterface_Call, this->Work, ASM::CALL);

	if (gProtect.m_MainInfo.CustomInterfaceType == 5)
	{
		this->BindObject(eMain, 31293, 960, 160, 50, 388);
		this->BindObject(eParty, iNewParty, 23, 30, 340, 449);
		this->BindObject(eCharacter, iNewCharacter, 23, 30, 370, 449);
		this->BindObject(eInventory, iNewInventory, 23, 30, 400, 449);
		this->BindObject(eGuild, iNewGuild, 40, 18, 523, 461);
	}

	if(gProtect.m_MainInfo.InventoryUPGRADE == 1)
	{
		SetRange((LPVOID)0x00835116, 5, ASM::NOP);
		SetOp((LPVOID)0x00835116, this->DrawZenAndRud, ASM::CALL);
	}
}


void Interface::DrawItemToolTipText(void* item, int x, int y) {
	static DWORD mem = 0;
	//static DWORD ItemToolTipAdress1 = 0x00861110; //1.04D-> 0x00860FC0
	//static DWORD ItemToolTipAdress2 = 0x00861AA0; //1.04D-> 0x00861950
	//static DWORD ItemToolTipAdress3 = 0x007E3E30; //1.04D-> 0x007E3CE0
	_asm {
		PUSH 0
		PUSH 0
		PUSH 0
		PUSH item
		PUSH y
		PUSH x
		MOV mem, 0x00861110
		CALL mem
		MOV ECX, EAX
		MOV mem, 0x00861AA0
		CALL mem
		MOV ECX, EAX
		MOV mem, 0x007E3E30
		CALL mem
	}

}

void Interface::DrawZenAndRud(int a1, int a2, int a3, int a4)
{
	int v10;
	int v11;
	DWORD v23;
	v10 = *(DWORD*)(a1 + 40);
	v11 = *(DWORD*)(a1 + 36);
	v23 = *(DWORD*)(*(DWORD*)0x8128AC4 + 5956);
	*(float*)(0x00D24E88); //Width

	char MoneyBuff1[50], MoneyBuff2[50], MoneyBuff3[50], MoneyBuff4[50], MoneyBuff5[50], test[50];
	ZeroMemory(MoneyBuff1, sizeof(MoneyBuff1));
	ZeroMemory(MoneyBuff2, sizeof(MoneyBuff2));
	ZeroMemory(MoneyBuff3, sizeof(MoneyBuff3));
	ZeroMemory(MoneyBuff4, sizeof(MoneyBuff4));
	ZeroMemory(MoneyBuff5, sizeof(MoneyBuff5));

	pGetMoneyFormat(v23, MoneyBuff1, 0);
	pGetMoneyFormat(Coin3, MoneyBuff2, 0);
	pGetMoneyFormat(Coin1, MoneyBuff3, 0);
	pGetMoneyFormat(Coin2, MoneyBuff4, 0);
	pGetMoneyFormat(Ruud, MoneyBuff5, 0);

	gInterface.DrawFormat(eWhite, v11, v10 + 12, 190, 3, pGetTextLine(pTextLineThis, 223));
	//--
	float X1 = 357.f;
	float X2 = 442.f;

	if (pCheckWindow(pWindowThis(), Character)) {
		X1 -= 190.f;
		X2 -= 190.f;
	}
	gInterface.DrawGUI(eMoney1, v11 + 18, v10 + 365);
	//pSetFont(pTextThis(), (int)pFontBold);
	//pSetTextColor(pTextThis(), 255, 255, 255, 255); //-- eWhite 
	//pDrawText(pTextThis(), 357, 355 + 10, "Zen", 230, 0, (LPINT)3, 0);
	CustomFont.Draw(CustomFont.FontBold16, X1, 355 + 10, 0xFFFFFFFF, 0, 230, 0, 3, "Zen");
	pSetFont(pTextThis(), (int)pFontBold);
	pSetTextColor(pTextThis(), 255, 255, 255, 255);
	gInterface.DrawFormat(eRed, v11 + 40, v10 + 367, 50, 3, "%s", MoneyBuff1);
	//--
	gInterface.DrawGUI(eMoney2, v11 + 102, v10 + 365);
	//pSetFont(pTextThis(), (int)pFontBold);
	//pSetTextColor(pTextThis(), 255, 105, 25, 255); //-- eOrange
	//pDrawText(pTextThis(), 442, 355 + 10, "GP", 230, 0, (LPINT)3, 0);
	CustomFont.Draw(CustomFont.FontBold16, X2, 355 + 10, 0xFF6919FF, 0, 230, 0, 3, "GP");
	pSetFont(pTextThis(), (int)pFontBold);
	pSetTextColor(pTextThis(), 255, 105, 25, 255); //-- eOrange
	gInterface.DrawFormat(eWhite, v11 + 128, v10 + 367, 45, 4, "%s", MoneyBuff2);
	//--
	gInterface.DrawGUI(eMoney2, v11 + 18, v10 + 378);
	//pSetFont(pTextThis(), (int)pFontBold);
	//pSetTextColor(pTextThis(), 0xACu, 0xFFu, 0x38u, 0xFFu); //-- eShinyGreen
	//pDrawText(pTextThis(), 357, 368 + 10, "WC", 230, 0, (LPINT)3, 0);
	CustomFont.Draw(CustomFont.FontBold16, X1, 368 + 10, 0xACFF38FF, 0, 230, 0, 3, "WC");
	pSetFont(pTextThis(), (int)pFontBold);
	pSetTextColor(pTextThis(), 0xACu, 0xFFu, 0x38u, 0xFFu); //-- eShinyGreen
	gInterface.DrawFormat(eGold, v11 + 38, v10 + 381, 50, 4, "%s", MoneyBuff3);
	//--
	gInterface.DrawGUI(eMoney2, v11 + 102, v10 + 378);
	//pSetFont(pTextThis(), (int)pFontBold);
	//pSetTextColor(pTextThis(), 36, 242, 252, 250); //-- eBlue250
	//pDrawText(pTextThis(), 442, 368 + 10, "WP", 230, 0, (LPINT)3, 0);
	CustomFont.Draw(CustomFont.FontBold16, X2, 368 + 10, 0x24F2FCFA, 0, 230, 0, 3, "WP");
	pSetFont(pTextThis(), (int)pFontBold);
	pSetTextColor(pTextThis(), 36, 242, 252, 250); //-- eBlue250
	gInterface.DrawFormat(eBlue, v11 + 128, v10 + 381, 45, 4, "%s", MoneyBuff4);
}

void Interface::LoadModels()
{
	pLoadModel(406, "Data\\Custom\\Bmd\\VIP1\\", "musign", -1);
	pLoadTexture(406, "Custom\\Bmd\\VIP1\\", 0x2901, 0x2600, 1);
	pLoadModel(407, "Data\\Custom\\Bmd\\VIP2\\", "musign", -1);
	pLoadTexture(407, "Custom\\Bmd\\VIP2\\", 0x2901, 0x2600, 1);
	pLoadModel(408, "Data\\Custom\\Bmd\\VIP3\\", "musign", -1);
	pLoadTexture(408, "Custom\\Bmd\\VIP3\\", 0x2901, 0x2600, 1);
	// ----
	pInitModelData2();
}

void Interface::LoadImages()
{
	//-- Welcome message
	//pDrawMessage(gCustomMessage.GetMessage(69), 0);
	//pDrawMessage(gCustomMessage.GetMessage(70), 1);
	pLoadSomeForm();
	//--
	// CAMERA 3D
	pLoadImage("Custom\\Interface\\CameraUI_BG.tga", 0x787A, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\Interface\\CameraUI_Switch.tga", 0x787B, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\Interface\\CameraUI_Reset.tga", 0x787C, 0x2601, 0x2900, 1, 0);
	//--
	if(gProtect.m_MainInfo.InventoryUPGRADE == 1)
	{
		pLoadImage("Custom\\Interface\\Money\\item_money.tga", 0x7909, 0x2601, 0x2901, 1, 0);
		pLoadImage("Custom\\Interface\\Money\\item_money2.tga", 0x7910, 0x2601, 0x2901, 1, 0);
		pLoadImage("Custom\\Interface\\Money\\item_money3.tga", 0x7911, 0x2601, 0x2901, 1, 0);
	}
	//
	pLoadImage("Custom\\Interface\\Rank01.tga", 0x7880, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank02.tga", 0x7881, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank03.tga", 0x7882, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank04.tga", 0x7883, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank05.tga", 0x7884, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank06.tga", 0x7885, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank07.tga", 0x7886, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank08.tga", 0x7887, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank09.tga", 0x7888, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank10.tga", 0x7889, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank11.tga", 0x7890, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank12.tga", 0x7891, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank13.tga", 0x7892, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank14.tga", 0x7893, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank15.tga", 0x7894, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank16.tga", 0x7895, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank17.tga", 0x7896, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank18.tga", 0x7897, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank19.tga", 0x7898, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank20.tga", 0x7899, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank21.tga", 0x7900, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank22.tga", 0x7901, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Ranking.tga", 0x7902, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Next.tga", 0x7903, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Previous.tga", 0x7904, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\MU-logo.tga", 0x7905, 0x2601, 0x2901, 1, 0);

	if (gProtect.m_MainInfo.CustomMenuType == 1)
	{
		pLoadImage("Custom\\Interface\\Menu1.tga", 0x7906, 0x2601, 0x2901, 1, 0);
	}
	else
	{
		pLoadImage("Custom\\Interface\\Menu2.tga", 0x7906, 0x2601, 0x2901, 1, 0);
		pLoadImage("Custom\\Interface\\Menu_BG.tga", 0x7907, 0x2601, 0x2901, 1, 0);
	}
	pLoadImage("Custom\\Interface\\Button.tga", 0x7908, 0x2601, 0x2900,1,0);
	//MiniMap
	pLoadImage("Custom\\Maps\\PlayerPoint.jpg", 31460, 0x2600, 0x2900, 1, 0);
	pLoadImage("Custom\\Interface\\none.tga", 31461, 0x2601, 0x2900, 1, 0);
	//--
	//--Interface MiniMap 97/99/S2/S6
	if(MiniMapType == 0)
	{
	pLoadImage("Custom\\Maps\\edBtUcx_old.tga", 31463, 0x2601, 0x2900, 1, 0); //-- Dungeon
	pLoadImage("Custom\\Maps\\timeold.tga", 31458, 0x2601, 0x2900, 1, 0); //-- Dungeon
	}
	//--Interface MiniMap ex700/Legends
	if(MiniMapType == 1)
	{
	pLoadImage("Custom\\Maps\\edBtUcx.tga", 31463, 0x2601, 0x2900, 1, 0); //-- Dungeon
	pLoadImage("Custom\\Maps\\time700.tga", 31458, 0x2601, 0x2900, 1, 0); //-- Dungeon
	}
	//--
	pLoadImage("Custom\\Maps\\edBtUcx_2.tga", 31464, 0x2601, 0x2900, 1, 0); //-- Dungeon
	pLoadImage("Custom\\Maps\\edBtUcx_1.tga", 31459, 0x2601, 0x2900, 1, 0); //-- Dungeon
	pLoadImage("Custom\\Maps\\YYB6BUk.tga", 31465, 0x2601, 0x2900, 1, 0); //-- Dungeon
	pLoadImage("Custom\\Maps\\mini_map_ui_blacksmith.tga", 31466, 0x2601, 0x2900, 1, 0); //-- Dungeon
	pLoadImage("Custom\\Maps\\mini_map_ui_Potion.tga", 31467, 0x2601, 0x2900, 1, 0); //-- Dungeon
	pLoadImage("Custom\\Maps\\mini_map_ui_baul.tga", 31468, 0x2601, 0x2900, 1, 0); //-- Dungeon
	pLoadImage("Custom\\Maps\\mini_map_ui_Que.tga", 31469, 0x2601, 0x2900, 1, 0); //-- Dungeon
	pLoadImage("Custom\\Maps\\mini_map_ui_monsterred.tga", 31471, 0x2601, 0x2900, 1, 0); //-- Dungeon Red
	pLoadImage("Custom\\Maps\\mini_map_ui_monsterblue.tga", 31472, 0x2601, 0x2900, 1, 0); //-- Dungeon Blue
	pLoadImage("Custom\\Maps\\mini_map_ui_monstergold.tga", 31473, 0x2601, 0x2900, 1, 0); //-- Dungeon Gold


	pLoadImage("Interface\\mini_map_ui_party.tga", 61520, 0x2601, 0x2901, 1, 0); //esquina abajo derecha

	//Login Remake 99b
	pLoadImage("Logo\\0Account_new.tga", 95124, 0x2601, 0x2900, 1, 0);
	pLoadImage("Logo\\0On_Botton.jpg", 95125, 0x2601, 0x2900, 1, 0);
	pLoadImage("Logo\\0On_Botton2.jpg", 95126, 0x2601, 0x2900, 1, 0);
	//--

	if(gProtect.m_MakeViewTRSData.TooltipS15 == 1)
	{
		//-- itemtooltip
		pLoadImage("Interface\\GFx\\tooltip_bg01.tga", 61511, 0x2601, 0x2901, 1, 0); //esquina arriba izquierda
		pLoadImage("Interface\\GFx\\tooltip_bg02.tga", 61512, 0x2601, 0x2901, 1, 0);
		pLoadImage("Interface\\GFx\\tooltip_bg03.tga", 61513, 0x2601, 0x2901, 1, 0); //esquina arriba derecha
		pLoadImage("Interface\\GFx\\tooltip_bg04.tga", 61514, 0x2601, 0x2901, 1, 0);
		pLoadImage("Interface\\GFx\\tooltip_bg06.tga", 61515, 0x2601, 0x2901, 1, 0);
		pLoadImage("Interface\\GFx\\tooltip_bg07.tga", 61516, 0x2601, 0x2901, 1, 0); //esquina abajo izquierda
		pLoadImage("Interface\\GFx\\tooltip_bg08.tga", 61517, 0x2601, 0x2901, 1, 0);
		pLoadImage("Interface\\GFx\\tooltip_bg09.tga", 61518, 0x2601, 0x2901, 1, 0); //esquina abajo derecha
	}
	//-- itemtooltip
	pLoadImage("Interface\\GFx\\popupbg01.tga", 71511, 0x2601, 0x2901, 1, 0); //esquina arriba izquierda
	pLoadImage("Interface\\GFx\\popupbg02.tga", 71512, 0x2601, 0x2901, 1, 0);
	pLoadImage("Interface\\GFx\\popupbg03.tga", 71513, 0x2601, 0x2901, 1, 0); //esquina arriba derecha
	pLoadImage("Interface\\GFx\\popupbg04.tga", 71514, 0x2601, 0x2901, 1, 0);
	pLoadImage("Interface\\GFx\\popupbg06.tga", 71515, 0x2601, 0x2901, 1, 0);
	pLoadImage("Interface\\GFx\\popupbg07.tga", 71516, 0x2601, 0x2901, 1, 0); //esquina abajo izquierda
	pLoadImage("Interface\\GFx\\popupbg08.tga", 71517, 0x2601, 0x2901, 1, 0);
	pLoadImage("Interface\\GFx\\popupbg09.tga", 71518, 0x2601, 0x2901, 1, 0); //esquina abajo derecha
	//--
	pLoadImage("Interface\\GFx\\popup_line_m.tga", 71519, 0x2601, 0x2901, 1, 0); //esquina abajo derecha
	pLoadImage("Interface\\GFx\\popup_line_s.tga", 71520, 0x2601, 0x2901, 1, 0); //esquina abajo derecha
	//--
	pLoadImage("Interface\\GFx\\Render_buttom_1.tga", 71521, 0x2601, 0x2901, 1, 0); //esquina abajo derecha
	pLoadImage("Interface\\GFx\\Render_buttom_2.tga", 71522, 0x2601, 0x2901, 1, 0); //esquina abajo derecha
	pLoadImage("Interface\\GFx\\Render_buttom_3.tga", 71524, 0x2601, 0x2901, 1, 0); //esquina abajo derecha
	//--
	pLoadImage("Interface\\GFx\\RenderBits_Sound.tga", 71523, 0x2601, 0x2901, 1, 0); //esquina abajo derecha
	pLoadImage("Interface\\GFx\\newui_option_volume01.tga", 31596, 0x2601, 0x2901, 1, 0); //esquina abajo derecha
	pLoadImage("Interface\\GFx\\newui_option_volume02.tga", 31597, 0x2601, 0x2901, 1, 0); //esquina abajo derecha
	//--
	//Party Bar 97/99/S2/S6
	if(MiniMapType == 0)
	{
	LoadBitmapA("Custom\\Party\\PartyBar.tga", 81525, GL_LINEAR, GL_CLAMP, 1, 0);
	pLoadImage("Custom\\Party\\newui_Party_Back.tga", 81520, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Party\\newui_Party_flag.tga", 81521, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Party\\newui_Party_HpBar.jpg", 81522, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Party\\newui_Party_ManaBar.jpg", 81523, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Party\\newui_Party_X.tga", 81524, 0x2601, 0x2901, 1, 0);
	}
	//--
	//--Party Bar ex700/Legends
	if(MiniMapType == 1)
	{
	LoadBitmapA("Custom\\Party\\Ex700\\PartyBar.tga", 81525, GL_LINEAR, GL_CLAMP, 1, 0);
    pLoadImage("Custom\\Party\\Ex700\\newui_Party_Back.tga", 81520, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Party\\Ex700\\newui_Party_flag.tga", 81521, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Party\\Ex700\\newui_Party_HpBar.jpg", 81522, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Party\\Ex700\\newui_Party_ManaBar.jpg", 81523, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Party\\Ex700\\newui_Party_X.tga", 81524, 0x2601, 0x2901, 1, 0);
	}

	//--
	LoadBitmapA("Interface\\newui_number1.tga", 31337, 9729, 10496, 1, 0);

	//Interface Minimapa 97/99
	//LoadBitmapA("Interface\\newui_SW_Minimap_Frame.tga", 31608, GL_LINEAR, GL_CLAMP, 1, 0);
	if(gProtect.m_MainInfo.CustomInterfaceType == 0 || gProtect.m_MainInfo.CustomInterfaceType == 1 || gProtect.m_MainInfo.CustomInterfaceType == 2 
		|| gProtect.m_MainInfo.CustomInterfaceType == 3 || gProtect.m_MainInfo.CustomInterfaceType == 4 || gProtect.m_MainInfo.CustomInterfaceType == 5)
	{
	LoadBitmapA("Interface\\newui_SW_Time_Frame.tga", 31609, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Interface\\newui_SW_MiniMap_Bt_clearness.jpg", 31617, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Interface\\GFx\\InventoryFrame_RuudShop.tga", 61560, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Interface\\GFx\\Menu_RuudShopFrame.tga", 61561, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Interface\\GFx\\Menu_Button03.tga", 61562, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Interface\\GFx\\ex700\\newSytemButton.tga", 61542, GL_LINEAR, GL_CLAMP, 1, 0);
	}
	//-- Pet Bar ex700/Legends
	if(MiniMapType == 1)
	{
	LoadBitmapA("Interface\\GFx\\winPet_I1.tga", 61545, GL_LINEAR, GL_CLAMP, 1, 0);
	}
	//-- Pet Bar 97/99/S2/S6
	if(MiniMapType == 0)
	{
	LoadBitmapA("Custom\\Party\\winPet_I1.tga", 61545, GL_LINEAR, GL_CLAMP, 1, 0);
	}
	//--
	switch(gProtect.m_MainInfo.CustomInterfaceType) 
	{
	case 1:
	case 2:
	if(gProtect.m_MainInfo.CustomInterfaceType == 1||gProtect.m_MainInfo.CustomInterfaceType == 2){
		//--
		LoadBitmapA("Custom\\InterfaceS2\\Item_Back01.tga", 61522, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\Interface\\none.tga", 51522, GL_LINEAR, GL_CLAMP, 1, 0);
		//--
		LoadBitmapA("Custom\\InterfaceS2\\DragonRight.tga", 2336, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\DragonLeft.tga", 2337, GL_LINEAR, GL_CLAMP, 1, 0);
		//--
		if(gProtect.m_MainInfo.CustomInterfaceType == 1)
		{
			LoadBitmapA("Custom\\InterfaceS2\\Menu_left97.jpg", 31292, GL_LINEAR, GL_CLAMP, 1, 0); //replace
			LoadBitmapA("Custom\\Interface\\none.tga", 31300, GL_LINEAR, GL_CLAMP, 1, 0);
		}else
		{
			LoadBitmapA("Custom\\InterfaceS2\\Menu_left.jpg", 31292, GL_LINEAR, GL_CLAMP, 1, 0); //replace
			LoadBitmapA("Custom\\InterfaceS2\\Menu_SD.jpg", 31300, GL_LINEAR, GL_CLAMP, 1, 0);
		}
		
		LoadBitmapA("Custom\\InterfaceS2\\Menu_right.jpg", 31294, GL_LINEAR, GL_CLAMP, 1, 0); //replace
		LoadBitmapA("Custom\\InterfaceS2\\Menu_middle.jpg", 31293, GL_LINEAR, GL_CLAMP, 1, 0); //replace
		//--
		LoadBitmapA("Custom\\InterfaceS2\\Menu_Red.jpg", 0x7A42, GL_LINEAR, GL_CLAMP, 1, 0);//replace
		LoadBitmapA("Custom\\InterfaceS2\\Menu_Green.jpg", 0x7A41, GL_LINEAR, GL_CLAMP, 1, 0);//replace
		LoadBitmapA("Custom\\InterfaceS2\\Menu_Blue.jpg", 0x7A40, GL_LINEAR, GL_CLAMP, 1, 0);//replace
		LoadBitmapA("Custom\\InterfaceS2\\Menu_AG.jpg", 31299, GL_LINEAR, GL_CLAMP, 1, 0);
		//--
		LoadBitmapA("Custom\\InterfaceS2\\Boton\\Menu_fastmenu.jpg", iNewFastMenu, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\Interface\\none.tga", 31295, GL_LINEAR, GL_CLAMP, 1, 0); //replace
		LoadBitmapA("Custom\\InterfaceS2\\Boton\\Menu_Inventory.jpg", iNewInventory, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\Boton\\Menu_Character.jpg", iNewCharacter, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\Boton\\Menu_Party.jpg", iNewParty, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\Boton\\Menu_friend.jpg", iNewWinpush, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\Boton\\Menu_guild.jpg", iNewGuild, GL_LINEAR, GL_CLAMP, 1, 0);
		//--
		LoadBitmapA("Custom\\InterfaceS2\\skillboxR.jpg", 0x700003, 0x2601, 0x2901, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\newui_skill.jpg", 31308, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\newui_skill2.jpg", 31309, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\newui_skill3.jpg", 31311, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\newui_command.jpg", 31310, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\newui_non_skill.jpg", 31314, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\newui_non_skill2.jpg", 31315, GL_LINEAR, GL_CLAMP, 1, 0); 
		LoadBitmapA("Custom\\InterfaceS2\\newui_non_skill3.jpg", 31317, GL_LINEAR, GL_CLAMP, 1, 0); 
		//--
		LoadBitmapA("Custom\\InterfaceS2\\newui_skillbox.jpg", 31312, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\newui_skillbox2.jpg", 31313, GL_LINEAR, GL_CLAMP, 1, 0);
		//--
		//Interface Character
		LoadBitmapA("Custom\\InterfaceS2\\Menu\\Stats.jpg", 31352, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\Menu\\StatsDL.jpg", 51291, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\Menu\\Stats2.jpg", 51292, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\Menu\\Level_box.jpg", 35353, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\Menu\\Level_button.jpg", 51290, GL_LINEAR, GL_CLAMP, 1, 0);
		//-- chat
		LoadBitmapA("Custom\\InterfaceS2\\chat\\nis_vframe.jpg", 51551, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\chat\\nis_rsframe.tga", 51552, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\chat\\nis_rsframe_up.jpg", 51553, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\chat\\nis_rsframe_m.jpg", 51554, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\chat\\nis_rsframe_down.jpg", 51555, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\chat\\nis_hframe.jpg", 31275, 9729, 10496, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\Chat\\dialogue1.tga", 51530, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\Chat\\dialogue2.tga", 51531, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\Chat\\dialogue2_1.jpg", 51532, GL_LINEAR, GL_CLAMP, 1, 0);
	}
		break;
	case 3:
		/*//--
		LoadBitmapA("Interface\\GFx\\ex700\\InventoryFrame_I1.tga", 61522, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\InventoryFrame_I2.tga", 61523, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\InventoryFrame_I3.tga", 61524, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\Frame_I3.tga", 61526, GL_LINEAR, GL_CLAMP, 1, 0); //-- All Window
		LoadBitmapA("Interface\\GFx\\ex700\\InventoryFrame_I4.tga", 61527, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\Draw_money.tga", 61528, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\button_close.tga", 61529, GL_LINEAR, GL_CLAMP, 1, 0);
		//--
		LoadBitmapA("Interface\\GFx\\ex700\\CharacterInfoFrame_I1.tga", 61532, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\newui_chainfo_btn_level.tga", 61533, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\ButtonCharacterInfo.tga", 61535, GL_LINEAR, GL_CLAMP, 1, 0);
		//--
		LoadBitmapA("Interface\\GFx\\ex700\\CharacterInfoFrame_I2.tga", 61538, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\BaulFrame_I1.tga", 61539, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\BaulFrame_I2.tga", 61540, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\ShopFrame_I1.tga", 61541, GL_LINEAR, GL_CLAMP, 1, 0);
		//LoadBitmapA("Interface\\GFx\\ex700\\newSytemButton.tga", 61542, GL_LINEAR, GL_CLAMP, 1, 0); //Boton Shop Ruud
		LoadBitmapA("Interface\\GFx\\ex700\\ShopFrame_I2.tga", 61543, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\StoreFrame_I1.tga", 61544, GL_LINEAR, GL_CLAMP, 1, 0);*/
		//--
		LoadBitmapA("Interface\\GFx\\ex700\\Main_IE.tga", 31293, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\Main_IE_Exp.tga", 59000, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\Main_I1.tga", 31296, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\Main_I4.jpg", 31300, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\Main_I5.jpg", 31299, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\newui_skillbox2.tga", 31313, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\newui_skillbox.tga", 31312, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\Main_Skillbox.tga", 51500, GL_LINEAR, GL_CLAMP, 1, 0);

		LoadBitmapA("Interface\\GFx\\ex700\\guege_mp.tga", 31296, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\guege_mp_1.tga", 51501, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\guege_hp_green.tga", 31297, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\guege_hp.tga", 31298, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\guege_hp_1.tga", 51502, GL_LINEAR, GL_CLAMP, 1, 0);
		goto LOAD_GFX;
	case 4:
		LoadBitmapA("Interface\\GFx\\Legends\\Main_IE.tga", 31293, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\Legends\\Main_I3.tga", 31298, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\Legends\\guege_mp.tga", 31296, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\Legends\\guege_mp_1.tga", 51501, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\Legends\\guege_hp_green.tga", 31297, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\Legends\\guege_hp.tga", 31298, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\Legends\\guege_hp_1.tga", 51502, GL_LINEAR, GL_CLAMP, 1, 0);

		LoadBitmapA("Interface\\GFx\\Legends\\Main_I5.jpg", 31299, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\Legends\\Main_I4.jpg", 31300, GL_LINEAR, GL_CLAMP, 1, 0);
		//--
		LoadBitmapA("Interface\\GFx\\Legends\\newui_skillbox2.tga", 31313, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\Legends\\newui_skillbox.tga", 31312, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\Legends\\Main_Skillbox.tga", 51500, GL_LINEAR, GL_CLAMP, 1, 0);
LOAD_GFX:
		LoadBitmapA("Interface\\GFx\\Buttom_empty_small.tga", 61525, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\newui_number1.tga", 6829, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\chat_bg01.tga", 61550, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\chat_bg02.tga", 61551, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\chat_bg03.tga", 61534, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\Chat_I5.tga", 61548, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\newui_chat_back.tga", 61549, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\Main_IE_Buttons.tga", 0x901, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\skill_render.tga", 61546, GL_LINEAR, GL_CLAMP, 1, 0);
		//LoadBitmapA("Interface\\GFx\\winPet_I1.tga", 61545, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\item_pbtnbg.tga", 61547, GL_LINEAR, GL_CLAMP, 1, 0);
		/*//-- Folder MacroUI
		LoadBitmapA("Interface\\GFx\\MacroUI\\MacroUI_Main.tga", 51550, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\MacroUI\\MacroUI_BSetup.tga", 51546, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\MacroUI\\MacroUI_BStart.tga", 51547, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\MacroUI\\MacroUI_Stop.tga", 51548, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\MacroUI\\MacroUI_Bar.jpg", 51549, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\MacroUI\\MacroUI_Menu.tga", 51553, GL_LINEAR, GL_CLAMP, 1, 0);*/
		//-- Botones del Main
		LoadBitmapA("Custom\\Interface\\none.tga", 31303, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\Interface\\none.tga", 31304, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\Interface\\none.tga", 31305, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\Interface\\none.tga", 31306, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\Interface\\none.tga", 31307, GL_LINEAR, GL_CLAMP, 1, 0);
		//--
		LoadBitmapA("Custom\\Interface\\none.tga", 51522, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\Interface\\none.tga", 31294, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\Interface\\none.tga", 31295, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\Interface\\none.tga", 31292, GL_LINEAR, GL_CLAMP, 1, 0);
		break;
	}//--Finaliza
	if(gProtect.m_MainInfo.CustomInterfaceType == 3 || gProtect.m_MainInfo.CustomInterfaceType == 4)
	{
		//--
		LoadBitmapA("Interface\\GFx\\ex700\\InventoryFrame_I1.tga", 61522, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\InventoryFrame_I2.tga", 61523, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\InventoryFrame_I3.tga", 61524, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\Frame_I3.tga", 61526, GL_LINEAR, GL_CLAMP, 1, 0); //-- All Window
		LoadBitmapA("Interface\\GFx\\ex700\\Frame_I3_E.tga", 61536, GL_LINEAR, GL_CLAMP, 1, 0); //-- Windows Party/Pet/Gens and Others
		LoadBitmapA("Interface\\GFx\\ex700\\Frame_I3_C.tga", 61558, GL_LINEAR, GL_CLAMP, 1, 0); //-- Window Chaos Mix
		LoadBitmapA("Interface\\GFx\\ex700\\InventoryFrame_I4.tga", 61527, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\Draw_money.tga", 61528, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\button_close.tga", 61529, GL_LINEAR, GL_CLAMP, 1, 0);
		//--
		LoadBitmapA("Interface\\GFx\\ex700\\CharacterInfoFrame_I1.tga", 61532, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\newui_chainfo_btn_level.tga", 61533, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\ButtonCharacterInfo.tga", 61535, GL_LINEAR, GL_CLAMP, 1, 0);
		//--
		LoadBitmapA("Interface\\GFx\\ex700\\CharacterInfoFrame_I2.tga", 61538, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\BaulFrame_I1.tga", 61539, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\BaulFrame_I2.tga", 61540, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\ShopFrame_I1.tga", 61541, GL_LINEAR, GL_CLAMP, 1, 0);
		//LoadBitmapA("Interface\\GFx\\ex700\\newSytemButton.tga", 61542, GL_LINEAR, GL_CLAMP, 1, 0); //Boton Shop Ruud
		LoadBitmapA("Interface\\GFx\\ex700\\ShopFrame_I2.tga", 61543, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\StoreFrame_I1.tga", 61544, GL_LINEAR, GL_CLAMP, 1, 0);
	}
	//LoadBitmapA("Custom\\Interface\\TimeBar.tga", 0x787F, 0x2601, 0x2901, 1, 0);
	//-- MuHelper ex700
	if(gProtect.m_MainInfo.MuHelperType == 1)
	{
	//-- Folder MacroUI
	LoadBitmapA("Interface\\GFx\\MacroUI\\MacroUI_Main.tga", 51550, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Interface\\GFx\\MacroUI\\MacroUI_BSetup.tga", 51546, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Interface\\GFx\\MacroUI\\MacroUI_BStart.tga", 51547, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Interface\\GFx\\MacroUI\\MacroUI_Stop.tga", 51548, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Interface\\GFx\\MacroUI\\MacroUI_Bar.jpg", 51549, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Interface\\GFx\\MacroUI\\MacroUI_Menu.tga", 51553, GL_LINEAR, GL_CLAMP, 1, 0);
	}
	//RuudCoin Interface S6/97/S2/Legends
	if(gProtect.m_MainInfo.CustomInterfaceType == 0 || gProtect.m_MainInfo.CustomInterfaceType == 1 
		|| gProtect.m_MainInfo.CustomInterfaceType == 2 || gProtect.m_MainInfo.CustomInterfaceType == 5)
	{
	LoadBitmapA("Custom\\Interface\\RuudHeadOld.tga", 0x7877, 0x2601, 0x2901,1,0);
	}
	else if (gProtect.m_MainInfo.CustomInterfaceType == 3 ||gProtect.m_MainInfo.CustomInterfaceType == 4)
	{
	LoadBitmapA("Custom\\Interface\\RuudHeadLegends.tga", 0x7877, 0x2601, 0x2901,1,0);
	}
	//TimerBar
	LoadBitmapA("Custom\\Interface\\TimeBarex700.tga", 0x7878, 0x2601, 0x2901,1,0);
	LoadBitmapA("Custom\\Interface\\TimeBar.tga", 0x7879, 0x2601, 0x2901,1,0);

	//DailyReward
	pLoadImage("Custom\\Desig\\dong.tga", 531020, GL_LINEAR, GL_REPEAT, 1, 0);
	pLoadImage("Custom\\Desig\\mo.tga", 531021, GL_LINEAR, GL_REPEAT, 1, 0);
	pLoadImage("Custom\\Desig\\giftboxnotice.tga", 531026, GL_LINEAR, GL_REPEAT, 1, 0);
	//==================================================================================

	if( gProtect.m_MainInfo.DisableEffectRemake == 0 )
	{
		pLoadImage("Effect\\flare01.jpg", 52002, GL_LINEAR, GL_REPEAT, 1, 0);
		pLoadImage("Effect\\flareRed.jpg", 52230, GL_LINEAR, GL_REPEAT, 1, 0);
		pLoadImage("Effect\\JointLaser01.jpg", 52224, GL_LINEAR, GL_REPEAT, 1, 0);
		pLoadImage("Effect\\hikorora.jpg", 52379, GL_LINEAR, GL_REPEAT, 1, 0);
		pLoadImage("Effect\\flareBlue.jpg", 52229, GL_LINEAR, GL_REPEAT, 1, 0);
		pLoadImage("Effect\\bostar3_R.jpg", 32614, GL_LINEAR, GL_REPEAT, 1, 0);
		pLoadImage("Effect\\line_of_big_R.jpg", 32772, GL_LINEAR, GL_REPEAT, 1, 0);
		pLoadImage("Effect\\flare01.jpg", 42134, GL_LINEAR, GL_REPEAT, 1, 0);
	}
	//--
	if(gProtect.m_MainInfo.DisableCustomCloack == 0)
	{
		gCloak.LoadTexture();
	}

	if (gProtect.m_MainInfo.CustomInterfaceType == 5)
	{
		pLoadImage("Custom\\Interfaceold\\none.tga", 51522, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interfaceold\\none.tga", 31292, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interfaceold\\none.tga", 0x7A48, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interfaceold\\none.tga", 31294, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interfaceold\\none.tga", 31295, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interfaceold\\none.tga", 0x7A4A, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interfaceold\\Main_Menu_Master.tga", 31293, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interfaceold\\Menu_Red.tga", 0x7A42, GL_LINEAR, GL_CLAMP, 1, 0);//replace
		pLoadImage("Custom\\Interfaceold\\Menu_Green.tga", 0x7A41, GL_LINEAR, GL_CLAMP, 1, 0);//replace
		pLoadImage("Custom\\Interfaceold\\Menu_Blue.tga", 0x7A40, GL_LINEAR, GL_CLAMP, 1, 0);//replace
		pLoadImage("Custom\\Interfaceold\\Main_I4.jpg", 31300, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interfaceold\\Main_I5.jpg", 31299, GL_LINEAR, GL_CLAMP, 1, 0);
		//
		//InterfaceMenu 97d
		pLoadImage("Custom\\Interfaceold\\Item_Back01.jpg", 51533, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interfaceold\\Menu\\Stats.jpg", 71352, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interfaceold\\Menu\\StatsDL.jpg", 71291, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interfaceold\\Menu\\Stats2.jpg", 71292, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interfaceold\\Menu\\Level_box.jpg", 35353, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interfaceold\\Menu\\Level_button.jpg", 51290, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interfaceold\\Menu\\ePointback.jpg", 0x700020, 0x2601, 0x2901, 1, 0);
		pLoadImage("Custom\\Interfaceold\\newui_skillbox.jpg", 31312, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interfaceold\\newui_skillbox2.jpg", 31313, GL_LINEAR, GL_CLAMP, 1, 0);
		//
		pLoadImage("Custom\\Interfaceold\\Boton\\Menu_Inventory.tga", iNewInventory1, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interfaceold\\Boton\\Menu_Character.tga", iNewCharacter1, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interfaceold\\Boton\\Menu_Party.tga", iNewParty1, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\Interfaceold\\Boton\\Menu_guild.tga", iNewGuild1, GL_LINEAR, GL_CLAMP, 1, 0);
	}

	pLoadImage("Custom\\Interface\\Title.tga", 400001, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\Interface\\PartySearch_Title.tga", 400002, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\Interface\\Info_Block.tga", 400003, 0x2601, 0x2900, 1, 0);

	pLoadImage("Custom\\Interface\\newui_cha_textbox01.tga", 400004, 0x2601, 0x2900, 1, 0);

	pLoadImage("Logo\\Mu-logo_g.jpg",  531019, GL_LINEAR, GL_REPEAT, 1, 0);
	pLoadImage("Logo\\Mu-logo.tga",  531018, GL_LINEAR, GL_REPEAT, 1, 0);

	pLoadImage("Custom\\Interface\\NewsBoard_Title.tga", 0x787D, 0x2601, 0x2900, 1, 0);

	#if(JEWELBANKVER2)
	pLoadImage("Interface\\newui_SW_Minimap_Bt_group.tga", 31618, 0x2601, 0x2900, 1, 0);
#endif
	gAchievements.LoadImages();
	g_ExWinQuestSystem.ImageLoad();
	//--
	pLoadSomeForm();
}

void Interface::WindowsKG(){
	if (gProtect.m_MainInfo.CustomInterfaceType >= 0){
		char interaltas[500];
		if (gInterface.validar == 0){
			if (gInterface.ultimo_Ping > 0){
				sprintf_s(interaltas, sizeof(interaltas), " %s || Player: %s || Level: %d || Reset: %d || WCoins: %d || || WCPCoins: %d || GPCoins: %d || RuudCoins: %d", gProtect.m_MainInfo.WindowName, gObjUser.lpPlayer->Name, gObjUser.lpPlayer->Level, ViewReset, Coin1, Coin2, Coin3, Ruud);
			}
			else{
				sprintf_s(interaltas, sizeof(interaltas), " %s || Player: %s || Level: %d || Reset: %d || WCoins: %d || WCPCoins: %d || GPCoins: %d || RuudCoins: %d", gProtect.m_MainInfo.WindowName, gObjUser.lpPlayer->Name, gObjUser.lpPlayer->Level, ViewReset, Coin1, Coin2, Coin3, Ruud);
			}
			SetWindowText(pGameWindow, interaltas);
		}
	}
}

void Interface::BindObject(short MonsterID, DWORD ModelID, float Width, float Height, float X, float Y)
{
	this->Data[MonsterID].EventTick	= 0;
	this->Data[MonsterID].OnClick	= false;
	this->Data[MonsterID].OnShow	= false;
	this->Data[MonsterID].ModelID	= ModelID;
	this->Data[MonsterID].Width		= Width;
	this->Data[MonsterID].Height	= Height;
	this->Data[MonsterID].X			= X;
	this->Data[MonsterID].Y			= Y;
	this->Data[MonsterID].MaxX		= X + Width;
	this->Data[MonsterID].MaxY		= Y + Height;
	this->Data[MonsterID].Attribute	= 0;
}

void Interface::DrawGUI(short ObjectID, float PosX, float PosY)
{
	if( this->Data[ObjectID].X == -1 || this->Data[ObjectID].Y == -1 )
	{
		this->Data[ObjectID].X		= PosX;
		this->Data[ObjectID].Y		= PosY;
		this->Data[ObjectID].MaxX	= PosX + this->Data[ObjectID].Width;
		this->Data[ObjectID].MaxY	= PosY + this->Data[ObjectID].Height;
	}

	pDrawGUI(this->Data[ObjectID].ModelID, PosX, PosY,this->Data[ObjectID].Width, this->Data[ObjectID].Height);
}

void Interface::DrawGUI2(short ObjectID, float PosX, float PosY)
{
	this->Data[ObjectID].X		= PosX;
	this->Data[ObjectID].Y		= PosY;
	this->Data[ObjectID].MaxX	= PosX + this->Data[ObjectID].Width;
	this->Data[ObjectID].MaxY	= PosY + this->Data[ObjectID].Height;

	pDrawGUI(this->Data[ObjectID].ModelID, PosX, PosY,this->Data[ObjectID].Width, this->Data[ObjectID].Height);
}

void Interface::DrawGUI3(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY)
{
	this->Data[ObjectID].X		= PosX;
	this->Data[ObjectID].Y		= PosY;
	this->Data[ObjectID].MaxX	= PosX + this->Data[ObjectID].Width;
	this->Data[ObjectID].MaxY	= PosY + this->Data[ObjectID].Height;

	RenderBitmap(this->Data[ObjectID].ModelID, PosX, PosY,this->Data[ObjectID].Width, this->Data[ObjectID].Height,0,0,ScaleX,ScaleY,1,1,0);
}

void Interface::DrawIMG(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY)
{
	if( this->Data[ObjectID].X == -1 || this->Data[ObjectID].Y == -1 )
	{
		this->Data[ObjectID].X		= PosX;
		this->Data[ObjectID].Y		= PosY;
		this->Data[ObjectID].MaxX	= PosX + this->Data[ObjectID].Width;
		this->Data[ObjectID].MaxY	= PosY + this->Data[ObjectID].Height;
	}

	RenderBitmap(this->Data[ObjectID].ModelID, PosX, PosY,this->Data[ObjectID].Width, this->Data[ObjectID].Height,0,0,ScaleX,ScaleY,1,1,0);
}

void Interface::ResetDrawIMG(short ObjectID)
{
	if( this->Data[ObjectID].X != -1 || this->Data[ObjectID].Y != -1 )
	{
		this->Data[ObjectID].X		= -1;
		this->Data[ObjectID].Y		= -1;
		this->Data[ObjectID].MaxX	= -1;
		this->Data[ObjectID].MaxY	= -1;
	}
}



void Interface::Work()
{
	//-- Advance Status Custom Low Interfaces
	if(gProtect.m_MainInfo.CustomInterfaceType == 0 || gProtect.m_MainInfo.CustomInterfaceType == 1 || gProtect.m_MainInfo.CustomInterfaceType == 2 
		|| gProtect.m_MainInfo.CustomInterfaceType == 4 || gProtect.m_MainInfo.CustomInterfaceType == 5)
	{
		if(gProtect.m_MainInfo.DisableAdvance == 0)
		{
			g_StatsAdvance.DrawInfo();
		}
	}
	//--

	//daily reward
	if (gProtect.m_MainInfo.DailyReward == 1)
	{
		DailyReward.Draw();

		bool focus1 = false;

		focus1 = DailyReward.CheckRect();

		if (focus1)
		{
			if (!pSetCursorFocus)
			{
				pSetCursorFocus = true;
			}

		}
	}

	//--Bar MiniMap
	if(gProtect.m_MainInfo.CustomInterfaceType == 0 || gProtect.m_MainInfo.CustomInterfaceType == 1 || gProtect.m_MainInfo.CustomInterfaceType == 2 
		|| gProtect.m_MainInfo.CustomInterfaceType == 3 || gProtect.m_MainInfo.CustomInterfaceType == 4 || gProtect.m_MainInfo.CustomInterfaceType == 5)
	{
	if( gRenderMap.DataMap.ModelID != -1 && MiniMap )
	{
			gInterface.MiniMapMini();
		}
	}
	//--
	//--Bar Pet
	//if(gProtect.m_MainInfo.CustomInterfaceType == 0 || gProtect.m_MainInfo.CustomInterfaceType == 1 || gProtect.m_MainInfo.CustomInterfaceType == 2 
	//	|| gProtect.m_MainInfo.CustomInterfaceType == 3 || gProtect.m_MainInfo.CustomInterfaceType == 4 || gProtect.m_MainInfo.CustomInterfaceType == 5)
	//{
	//	if ( *(DWORD *)(*(DWORD *)0x7BC4F04 + 676) != 0 || *(DWORD *)(*(DWORD *)0x7BC4F04 + 556) != 65535)
	//	{
	//		gCRenderEx700.BarPetMuun();
	//	}
	//}
	//--
	gObjUser.Refresh();

	jCRenderRuud.CheckOpen();
	
	if(gObjUser.lpViewPlayer->WeaponFirstSlot >= ITEM2(4,0) && gObjUser.lpViewPlayer->WeaponFirstSlot <= ITEM2(4,255)
		||gObjUser.lpViewPlayer->WeaponSecondSlot >= ITEM2(4,0) && gObjUser.lpViewPlayer->WeaponSecondSlot <= ITEM2(4,255))
	{
		gInterface.PetY = 38.0f;
		
	}
	else
	{
		gInterface.PetY = 26.0f;
	}

	if(gObjUser.lpViewPlayer->PetSlot!= -1)
	{
		gInterface.PetX = 61.0f;
	}else
	{
		gInterface.PetX = 0;
	}

	if(gProtect.m_MainInfo.CustomInterfaceType == 1 || gProtect.m_MainInfo.CustomInterfaceType == 2)
	{	gInterface.DrawInterfaceDragonLS3();
		gInterface.DrawInterfaceDragonRS3();
	}

	gInterface.DrawMiniMap();

	gCustomRanking.DrawRankPanelWindow();

	gCustomEventTime.DrawEventTimePanelWindow();
	
	ReconnectMainProc();

	gInterface.DrawVipWindow();

	gInterface.DrawMenu();

	gInterface.DrawMenuOpen();

	gCustomCommandInfo.DrawCommandWindow();

	gInterface.DrawConfirmOpen();

	g_ExWinQuestSystem.DrawMiniInfo();

	gNewInterface.Work();

	gInterface.DrawNewsWindow();

	gscreen.DrawPanelWindow();

	gLayout.UpdateLayoutPanelWindow();
	gLayout.DrawLayoutPanelWindow();

	gAchievements.Draw();
	g_ExWinQuestSystem.Draw();
	gGrandResetSystem.draw_grand_reset_system();
	gResetSystem.draw_reset_system();

	gInterface.DrawChangingClassWindow();
	gInterface.DrawWarehouseWindow();
	gInterface.DrawStatsAddWindow();

	gInterface.DrawPartySettingsWindow();
	gInterface.DrawPartySearchWindow();

	gInterface.WindowsKG();

	#if(JEWELBANKVER2)
	gInterface.DrawWindowJewelBankVer2();

#endif

	if(gProtect.m_MainInfo.CustomInterfaceType == 3 || gProtect.m_MainInfo.CustomInterfaceType == 4)
	{
		gInterface.DrawInterfaceCustom();
	}

	pDrawInterface();

	if (gProtect.m_MainInfo.CustomInterfaceType == 5)
	{
		gInterface.DrawInterfaceCustom1();
		gInterface.DrawInterfaceMenu1();
	}


	if(gProtect.m_MainInfo.CustomInterfaceType == 1 || gProtect.m_MainInfo.CustomInterfaceType == 2)
	{
		
		if(gProtect.m_MainInfo.CustomInterfaceType == 1)
		{
			gInterface.DrawInterface97Menu();
		}
		if(gProtect.m_MainInfo.CustomInterfaceType == 2)
		{
			gInterface.DrawInterfaceS2Menu();
		}
	}

	if( GetForegroundWindow() == pGameWindow )
	{
		if (GetKeyState(VK_SNAPSHOT) < 0) 
		{
			gInterface.DrawLogo(1); 
		}
		if (GetKeyState(VK_END) & 0x4000) 
		{
			if((GetTickCount()-gInterface.Data[eVip_MAIN].EventTick) > 300)
			{
				if (gInterface.CheckVipWindow())
				{
					gInterface.Data[eVip_MAIN].EventTick = GetTickCount();
					gInterface.CloseVipWindow();
				}
				else
				{
					gInterface.Data[eVip_MAIN].EventTick = GetTickCount();
					gInterface.CloseCustomWindow();
					gInterface.OpenVipWindow();
				}
			}
		}
		/*if (GetKeyState('H') & 0x4000) 
		{
			gAchievements.CGWindowOpen();
			//gCustomEventTime.OpenWindow();
		}
		if (GetKeyState('O') & 0x4000) 
		{
			g_ExWinQuestSystem.SwitchStatsWindowState();
			//gInterface.OpenConfig(0);
		}
		if (GetKeyState(VK_UP) & 0x4000) 
		{
			gResetSystem.SwitchStatsWindowState();
			//gInterface.OpenConfig(1);
		}
		else if (GetKeyState(VK_DOWN) & 0x4000) 
		{
			gInterface.Data[eCHANGINGCLASS_MAIN].Open();
			//gInterface.OpenConfig(1);
		}
		if (GetKeyState('J') & 0x4000) 
		{
			gInterface.SwitchPartySettingsWindowState();
		}*/
		if (GetKeyState('Y') & 0x4000 && GetTickCount() >= gCustomRanking.OpenTestDelay + 250)
		{
			if (GetForegroundWindow() == pGameWindow && !gInterface.CheckWindow(ObjWindow::ChatWindow))
			{
				DailyReward.ToggleWindow(true);
				gCustomRanking.OpenTestDelay = GetTickCount();
			}
		}
		if (GetKeyState('J') & 0x4000)
		{
			//gCustomJewelBank.OpenWindow();
			gInterface.OnOffWindowBank();
		}
		if (GetKeyState(VK_F6) & 0x4000) 
		{
			gInterface.SwitchChatExpand();
		}
		if (GetKeyState(VK_F8) & 0x4000) 
		{
			gCustomRanking.OpenWindow();
		}
		if (GetKeyState(VK_F10) & 0x4000) 
		{
			gInterface.SwitchCamera();
		}
		if (GetKeyState(VK_F11) & 0x4000) 
		{
			gInterface.CameraInit();
		}
		if (GetKeyState(VK_F12) & 0x4000) 
		{
			if( gTrayMode.TempWindowProc == NULL )
			{
				gTrayMode.TempWindowProc = SetWindowLong(pGameWindow, GWL_WNDPROC, (long)gController.Window);
			}
			// ----
			gTrayMode.SwitchState();
		}
		if (GetKeyState(VK_ESCAPE) < 0) 
		{
			if (gInterface.Data[eCommand_MAIN].OnShow == true)
			{
				gInterface.Data[eCommand_MAIN].OnShow = false;
				
	if(gProtect.m_MainInfo.CustomInterfaceType != 3 || gProtect.m_MainInfo.CustomInterfaceType != 4)
	{
		pSetCursorFocus = false;
	}
			}

			if (gInterface.Data[eRankPANEL_MAIN].OnShow == true)
			{
				gInterface.Data[eRankPANEL_MAIN].OnShow = false;
				
	if(gProtect.m_MainInfo.CustomInterfaceType != 3 || gProtect.m_MainInfo.CustomInterfaceType != 4)
	{
		pSetCursorFocus = false;
	}
			}

			if (gInterface.Data[eEventTimePANEL_MAIN].OnShow == true)
			{
				gInterface.Data[eEventTimePANEL_MAIN].OnShow = false;
				
	if(gProtect.m_MainInfo.CustomInterfaceType != 3 || gProtect.m_MainInfo.CustomInterfaceType != 4)
	{
		pSetCursorFocus = false;
	}
			}

			if (gInterface.CheckVipWindow())
			{
				gInterface.CloseVipWindow();
			}

			if (gInterface.CheckMenuWindow())
			{
				gInterface.CloseMenuWindow();
			}
		}
	}

//	gCRuudShop.RuudShop();

	gInterface.DrawLogo(0);
}

void Interface::SwitchMiniMap()
{
	if((GetTickCount() - gInterface.Data[eNULL_MAP].EventTick) < 1000 ||this->CheckWindow(ChatWindow))
	{
		return;
	}

	gInterface.Data[eNULL_MAP].EventTick = GetTickCount();

	if (MiniMap != 0)
	{
		gInterface.DrawMessage(1, "MiniMap Window [OFF]");
		MiniMap = 0;
		WritePrivateProfileStringA("Graphics","MiniMap","0","./Settings.ini");
	}
	else 
	{
		gInterface.DrawMessage(1, "MiniMap Window [ON]");
		MiniMap = 1;
		WritePrivateProfileStringA("Graphics","MiniMap","1","./Settings.ini");
	}
}

int Interface::DrawFormat(DWORD Color, int PosX, int PosY, int Width, int Align, LPCSTR Text, ...)
{
	char Buff[2048];
	int BuffLen	= sizeof(Buff)-1;
	ZeroMemory(Buff, BuffLen);
	
	va_list args;
	va_start(args, Text);
	int Len	= vsprintf_s(Buff, BuffLen, Text, args);
	va_end(args);
	
	int LineCount = 0;
	
	char * Line = strtok(Buff, "\n");
	
	while( Line != NULL )
	{
		pDrawColorText(Line, PosX, PosY, Width, 0, Color, 0, Align);
		PosY += 10;
		Line = strtok(NULL, "\n");
	}
	
	return PosY;
}

bool Interface::CheckWindow(int WindowID)
{
	return pCheckWindow(pWindowThis(), WindowID);
}
int Interface::CloseWindow(int WindowID)
{
	return pCloseWindow(pWindowThis(), WindowID);
}
int Interface::OpenWindow(int WindowID)
{
	return pOpenWindow(pWindowThis(), WindowID);
}

bool Interface::IsWorkZone2(float X, float Y, float MaxX, float MaxY)
{
	if ((gObjUser.m_CursorX < X || gObjUser.m_CursorX > MaxX)
		|| (gObjUser.m_CursorY < Y || gObjUser.m_CursorY > MaxY))
	{
		return false;
	}
	// ----
	return true;
}
bool Interface::IsWorkZone41(float x, float y, float x2, float y2)
{
	bool result = GetForegroundWindow() == pGameWindow && pCursorX >= x && pCursorX <= x + x2 && pCursorY >= y && pCursorY <= y + y2;
	return result;
}
bool Interface::IsWorkZone69(float x, float y, float x2, float y2)
{
	return pCursorX >= x && pCursorX <= x + x2 && pCursorY >= y && pCursorY <= y + y2; //GetForegroundWindow() == pGameWindow &&
}

bool Interface::IsWorkZone(short ObjectID)
{
	if( (pCursorX < this->Data[ObjectID].X || pCursorX > this->Data[ObjectID].MaxX) || (pCursorY < this->Data[ObjectID].Y || pCursorY > this->Data[ObjectID].MaxY) )
		return false;

	return true;
}

bool Interface::IsWorkZone1(short ObjectID)
{
	float PosX = this->Data[ObjectID].X;
	float MaxX = PosX + this->Data[ObjectID].Width;

	if (ObjectID == eSAMPLEBUTTON
		|| ObjectID == eMenuBG
		|| ObjectID == eMenu
		)
	{
		PosX = this->GetResizeX(ObjectID);
		MaxX = PosX + this->Data[ObjectID].Width;
	}

	if ((gObjUser.m_CursorX < PosX || gObjUser.m_CursorX > MaxX) || (gObjUser.m_CursorY < this->Data[ObjectID].Y || gObjUser.m_CursorY > this->Data[ObjectID].MaxY))
		return false;

	return true;
}

bool Interface::IsWorkZone1(float X, float Y, float MaxX, float MaxY)
{
	if ((gObjUser.m_CursorX < X || gObjUser.m_CursorX > MaxX) || (gObjUser.m_CursorY < Y || gObjUser.m_CursorY > MaxY))
		return false;

	return true;
}

float Interface::GetResizeX(short ObjectID)
{
	if( pWinWidth == 800 )
	{
		return this->Data[ObjectID].X + 16.0;
	}
	else if( pWinWidth != 1024 )
	{
		return this->Data[ObjectID].X - 16.0;
	}
	
	return this->Data[ObjectID].X;
}

int Interface::DrawToolTip(int X, int Y, LPCSTR Text, ...)
{
	char Buff[2048];
	int BuffLen	= sizeof(Buff);
	ZeroMemory(Buff, BuffLen);
	
	va_list args;
	va_start(args, Text);
	int Len	= vsprintf_s(Buff, BuffLen, Text, args);
	va_end(args);
	
	return pDrawToolTip(X, Y, Buff);
}

int Interface::DrawMessage(int Mode, LPCSTR Text, ...)
{
	char Buff[2048];
	int BuffLen	= sizeof(Buff);
	ZeroMemory(Buff, BuffLen);
	// ----
	va_list args;
	va_start(args, Text);
	int Len	= vsprintf_s(Buff, BuffLen, Text, args);
	va_end(args);
	// ----
	return pDrawMessage(Buff, Mode);
}

void Interface::DrawVipWindow()
{

	if( !this->Data[eVip_MAIN].OnShow )
	{
		return;
	}

	pSetCursorFocus = true; // Certifique-se de que esta variável está corretamente declarada

	if( gProtect.m_MainInfo.EnableVipShop != 1 )
	{
		this->CloseVipWindow();
		return;
	}

	if (this->CheckWindow(ObjWindow::MoveList) || this->CheckWindow(ObjWindow::CashShop) || this->CheckWindow(ObjWindow::SkillTree) || this->CheckWindow(ObjWindow::FullMap)
		||  (this->CheckWindow(Inventory) 
		&& this->CheckWindow(ExpandInventory) 
		&& this->CheckWindow(Store)) 
		||  (this->CheckWindow(Inventory) 
		&& this->CheckWindow(Warehouse) 
		&& this->CheckWindow(ExpandWarehouse)) )
	{
		CloseVipWindow();
		return;
	}

	// ----
	float MainWidth			= 230.0;
	float MainHeight		= 320.0;
	float StartBody			= ((MAX_WIN_HEIGHT - 51) / 2) - (MainHeight / 2);
	float StartY			= ((MAX_WIN_HEIGHT - 51) / 2) - (MainHeight / 2);
	float StartX			= (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
	float MainCenter		= StartX + (MainWidth / 3);
	float ButtonX			= MainCenter - (float)(29.0 / 2);
	// ----
	gCentral.PrintDropBox(StartX, StartY, MainWidth, MainHeight, 0, 0);
	// ----
	this->DrawFormat(eGold, (int)StartX + 10, (int)StartBody + 10, 210, 3, gCustomMessage.GetMessage(5));
	int LineY = this->DrawFormat(eWhite, (int)StartX + 30, (int)StartBody + 35, 210, 1, gCustomMessage.GetMessage(6), gObjUser.lpPlayer->Name);
	LineY = this->DrawFormat(eGold, (int)StartX + 30, (int)LineY, 210, 1, gCustomMessage.GetMessage(14));
	LineY = this->DrawFormat(eWhite, (int)StartX + 30, (int)LineY, 210, 1, gCustomMessage.GetMessage(7));
	LineY = this->DrawFormat(eWhite, (int)StartX + 30, (int)LineY, 210, 1, gCustomMessage.GetMessage(8));
	//--
	pDrawGUI(71520, StartX + (MainWidth / 2) - (200 / 2), StartBody + 85, 200, 1); //-- Divisor
	//--
	this->DrawFormat(eGold, (int)StartX + 30, (int)StartBody + 95 - 2, 210, 1, "Plan");
	this->DrawFormat(eGold, (int)StartX + 80, (int)StartBody + 95 - 2 , 210, 1, "Exp");
	this->DrawFormat(eGold, (int)StartX + 130, (int)StartBody + 95 - 2, 210, 1, "Drop");
	this->DrawFormat(eGold, (int)StartX + 170, (int)StartBody + 95 - 2, 210, 1, "Time");
	// ----

	if (gProtect.m_MainInfo.VipTypes < 1 || gProtect.m_MainInfo.VipTypes > 3)
	{
		gProtect.m_MainInfo.VipTypes = 3;
	}

	for( int i = 0; i < (int)gProtect.m_MainInfo.VipTypes; i++ )
	{
		this->DrawFormat(eWhite, (int)StartX + 30, (int)StartBody + 110 + (12 * i) - 5, 210, 1, gCustomBuyVip.m_CustomBuyVipInfo[i].VipName);
		// ----
		this->DrawFormat(eWhite, (int)StartX + 80, (int)StartBody + 110 + (12 * i) - 5, 210, 1, "+%d%%", gCustomBuyVip.m_CustomBuyVipInfo[i].Exp);
		// ----
		this->DrawFormat(eWhite, (int)StartX + 130, (int)StartBody + 110 + (12 * i) - 5, 210, 1, "+%d%%", gCustomBuyVip.m_CustomBuyVipInfo[i].Drop);
		// ----
		this->DrawFormat(eWhite, (int)StartX + 170, (int)StartBody + 110 + (12 * i) - 5, 210, 1, "%d day(s)", gCustomBuyVip.m_CustomBuyVipInfo[i].Days);

		pDrawGUI(0x7B5E, StartX + 30, StartBody + 110 + (12 * i) + 9 - 5, 82.0, 2.0);
		pDrawGUI(0x7B5E, StartX + 30 + 82, StartBody + 110 + (12 * i) + 9 - 5, 82.0, 2.0);
	}

	if (gProtect.m_MainInfo.VipTypes > 0)
	{
	// ---- bronze start 
	if (IsWorkZone(eVip_BRONZE))
	{
		if (this->Data[eVip_BRONZE].OnClick)
			this->DrawButton(eVip_BRONZE, StartX + 64, 220, 0, 58);
		else
			this->DrawButton(eVip_BRONZE, StartX + 64, 220, 0, 29);
		// ----
		this->DrawFormat(eGold, (int)StartX + 30, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(10));
		this->DrawFormat(eGold, (int)StartX + 70, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(11), gCustomBuyVip.m_CustomBuyVipInfo[0].Coin1);
		this->DrawFormat(eGold, (int)StartX + 120, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(12), gCustomBuyVip.m_CustomBuyVipInfo[0].Coin2);
		this->DrawFormat(eGold, (int)StartX + 160, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(13), gCustomBuyVip.m_CustomBuyVipInfo[0].Coin3);
	}
	else
		this->DrawButton(eVip_BRONZE, StartX + 64, 220, 0, 0);
	// ----
	this->DrawFormat(eWhite, (int)StartX + 90, 220 + 9, 160, 1, gCustomMessage.GetMessage(9),gCustomBuyVip.m_CustomBuyVipInfo[0].VipName);
	// ---- bronze end ------------------------------------
	}

	if (gProtect.m_MainInfo.VipTypes > 1)
	{
	// ---- Silver start ------------------------------------
	if (IsWorkZone(eVip_SILVER))
	{
		if (this->Data[eVip_SILVER].OnClick)
			this->DrawButton(eVip_SILVER, StartX + 64, 250, 0, 58);
		else
			this->DrawButton(eVip_SILVER, StartX + 64, 250, 0, 29);
		// ----
		this->DrawFormat(eGold, (int)StartX + 30, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(10));
		this->DrawFormat(eGold, (int)StartX + 70, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(11), gCustomBuyVip.m_CustomBuyVipInfo[1].Coin1);
		this->DrawFormat(eGold, (int)StartX + 120, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(12), gCustomBuyVip.m_CustomBuyVipInfo[1].Coin2);
		this->DrawFormat(eGold, (int)StartX + 160, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(13), gCustomBuyVip.m_CustomBuyVipInfo[1].Coin3);
	}
	else
		this->DrawButton(eVip_SILVER, StartX + 64, 250, 0, 0);

	this->DrawFormat(eWhite, (int)StartX + 90, 250 + 9, 160, 1, gCustomMessage.GetMessage(9),gCustomBuyVip.m_CustomBuyVipInfo[1].VipName);
	// ---- silver end ------------------------------------
	}

	if (gProtect.m_MainInfo.VipTypes > 2)
	{
	// ---- gold start ------------------------------------
	if (IsWorkZone(eVip_GOLD))
	{
		if (this->Data[eVip_GOLD].OnClick)
			this->DrawButton(eVip_GOLD, StartX + 64, 280, 0, 58);
		else
			this->DrawButton(eVip_GOLD, StartX + 64, 280, 0, 29);
		// ----
		this->DrawFormat(eGold, (int)StartX + 30, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(10));
		this->DrawFormat(eGold, (int)StartX + 70, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(11), gCustomBuyVip.m_CustomBuyVipInfo[2].Coin1);
		this->DrawFormat(eGold, (int)StartX + 120, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(12), gCustomBuyVip.m_CustomBuyVipInfo[2].Coin2);
		this->DrawFormat(eGold, (int)StartX + 160, (int)StartBody + 142, 210, 1, gCustomMessage.GetMessage(13), gCustomBuyVip.m_CustomBuyVipInfo[2].Coin3);
	}
	else
		this->DrawButton(eVip_GOLD, StartX + 64, 280, 0, 0);

	this->DrawFormat(eWhite, (int)StartX + 90, 280 + 9, 160, 1, gCustomMessage.GetMessage(9),gCustomBuyVip.m_CustomBuyVipInfo[2].VipName);
	// ---- gold end ------------------------------------
	}

	pDrawGUI(71520, StartX + (MainWidth / 2) - (200 / 2), 280 + 55, 200, 1); //-- Divisor
}


bool Interface::EventVipWindow_Close(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eVip_CLOSE].EventTick);
	// ----
	if (!this->Data[eVip_MAIN].OnShow || !IsWorkZone(eVip_CLOSE))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eVip_CLOSE].OnClick = true;
		return true;
	}
	// ----
	this->Data[eVip_CLOSE].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eVip_CLOSE].EventTick = GetTickCount();
	this->CloseVipWindow();
	// ----
	return false;
}
// ----------------------------------------------------------------------------------------------

bool Interface::EventVipWindow_Bronze(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eVip_BRONZE].EventTick);
	// ----
	if (!this->Data[eVip_MAIN].OnShow || !IsWorkZone(eVip_BRONZE))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eVip_BRONZE].OnClick = true;
		return true;
	}
	// ----
	this->Data[eVip_BRONZE].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eVip_BRONZE].EventTick = GetTickCount();
	gCustomBuyVip.BuyStatus(1);
	this->CloseVipWindow();
	// ----
	return false;
}
// ----------------------------------------------------------------------------------------------

bool Interface::EventVipWindow_Silver(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eVip_SILVER].EventTick);
	// ----
	if (!this->Data[eVip_MAIN].OnShow || !IsWorkZone(eVip_SILVER))
	{
		return false;
	}
	if (gProtect.m_MainInfo.VipTypes < 2)
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eVip_SILVER].OnClick = true;
		return true;
	}
	// ----
	this->Data[eVip_SILVER].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eVip_SILVER].EventTick = GetTickCount();
	gCustomBuyVip.BuyStatus(2);
	this->CloseVipWindow();
	// ----
	return false;
}

// ----------------------------------------------------------------------------------------------
bool Interface::EventVipWindow_Gold(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eVip_GOLD].EventTick);
	// ----
	if (!this->Data[eVip_MAIN].OnShow || !IsWorkZone(eVip_GOLD))
	{
		return false;
	}
	if (gProtect.m_MainInfo.VipTypes < 3)
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eVip_GOLD].OnClick = true;
		return true;
	}
	// ----
	this->Data[eVip_GOLD].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eVip_GOLD].EventTick = GetTickCount();
	gCustomBuyVip.BuyStatus(3);
	this->CloseVipWindow();
	// ----
	return false;
}
// ----------------------------------------------------------------------------------------------

bool Interface::EventVipWindow_Main(DWORD Event)
{
	this->EventVipWindow_Close(Event);
	this->EventVipWindow_Bronze(Event);
	this->EventVipWindow_Silver(Event);
	this->EventVipWindow_Gold(Event);
	// ----
	return true;
}

float Interface::DrawRepeatGUI(short MonsterID, float X, float Y, int Count)
{
	float StartY = Y;
	// ----
	for( int i = 0; i < Count; i++ )
	{
		pDrawGUI(this->Data[MonsterID].ModelID, X, StartY,
			this->Data[MonsterID].Width, this->Data[MonsterID].Height);
		// ----
		StartY += this->Data[MonsterID].Height;
	}
	// ----
	return StartY;
}

float Interface::DrawRepeatGUIScale(short MonsterID, float X, float Y,float ScaleX, float ScaleY, int Count)
{
	float StartY = Y;
	// ----
	for( int i = 0; i < Count; i++ )
	{
		this->DrawIMG(this->Data[MonsterID].ModelID, X, StartY,ScaleX,ScaleY);
		// ----
		StartY += this->Data[MonsterID].Height;
	}
	// ----
	return StartY;
}

void Interface::DrawButton(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY)
{
	if( this->Data[ObjectID].X == -1 || this->Data[ObjectID].Y == -1 )
	{
		this->Data[ObjectID].X = PosX;
		this->Data[ObjectID].Y = PosY;
		this->Data[ObjectID].MaxX = PosX + this->Data[ObjectID].Width;
		this->Data[ObjectID].MaxY = PosY + this->Data[ObjectID].Height;
	}
	// ----
	pDrawButton(this->Data[ObjectID].ModelID, PosX, PosY,
		this->Data[ObjectID].Width, this->Data[ObjectID].Height, ScaleX, ScaleY);
}

void Interface::DrawButtonRender(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY)
{
	this->Data[ObjectID].X = PosX;
	this->Data[ObjectID].Y = PosY;
	this->Data[ObjectID].MaxX = PosX + this->Data[ObjectID].Width;
	this->Data[ObjectID].MaxY = PosY + this->Data[ObjectID].Height;
	// ----
	pDrawButton(this->Data[ObjectID].ModelID, PosX, PosY,
		this->Data[ObjectID].Width, this->Data[ObjectID].Height, ScaleX, ScaleY);
}

void Interface::DrawColoredGUI(short ObjectID, float X, float Y, DWORD Color)
{
	if( this->Data[ObjectID].X == -1 || this->Data[ObjectID].Y == -1 )
	{
		this->Data[ObjectID].X		= X;
		this->Data[ObjectID].Y		= Y;
		this->Data[ObjectID].MaxX	= X + this->Data[ObjectID].Width;
		this->Data[ObjectID].MaxY	= Y + this->Data[ObjectID].Height;
	}
	// ----
	pDrawColorButton(this->Data[ObjectID].ModelID, X, Y, 
		this->Data[ObjectID].Width, this->Data[ObjectID].Height, 0, 0, Color);
}

void Interface::DrawLogo(bool active)
{
	if (gProtect.m_MainInfo.PrintLogo != 0)
	{

		if (active == 1)
		{
			this->Data[eLogo].EventTick = GetTickCount()+1500;
		}

		if (gInterface.Data[eLogo].EventTick > GetTickCount())
		{
			if (gProtect.m_MainInfo.PrintLogo == 1)
			{
				this->DrawGUI(eLogo, 10, 10);
			}

			if (gProtect.m_MainInfo.PrintLogo == 2)
			{
				this->DrawGUI(eLogo, MAX_WIN_WIDTH - 160, 10);

			}

			if (gProtect.m_MainInfo.PrintLogo == 3)
			{
				this->DrawGUI(eLogo, 10, MAX_WIN_HEIGHT - 144);
			}

			if (gProtect.m_MainInfo.PrintLogo == 4)
			{
				this->DrawGUI(eLogo, MAX_WIN_WIDTH - 160, MAX_WIN_HEIGHT - 144);
			}

			if (gProtect.m_MainInfo.PrintLogo == 5)
			{
				this->DrawGUI(eLogo, (MAX_WIN_WIDTH/2)-(150/2), (MAX_WIN_HEIGHT/2)-(114/2));
			}
		}
	}
}

void Interface::DrawMenu()
{
	if (gProtect.m_MainInfo.CustomMenuSwitch != 1)
	{
		return;
	}

	if (this->Data[eMenu].OnShow)
	{
		this->Data[eMenu].OnShow = false;
	}

	if (this->CheckWindow(ObjWindow::MoveList) || this->CheckWindow(ObjWindow::CashShop) || this->CheckWindow(ObjWindow::SkillTree) || this->CheckWindow(ObjWindow::FullMap)
		||  (this->CheckWindow(Inventory) 
		&& this->CheckWindow(ExpandInventory) 
		&& this->CheckWindow(Store))
		||  (this->CheckWindow(Inventory) 
		&& this->CheckWindow(ExpandInventory) 
		&& this->CheckWindow(Character))
		||  (this->CheckWindow(Inventory) 
		&& this->CheckWindow(Warehouse) 
		&& this->CheckWindow(ExpandWarehouse)) )
	{
		CloseMenuWindow();
		return;
	}
	
	this->Data[eMenu].OnShow = true;
}

bool Interface::EventDrawMenu_Open(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eMenu].EventTick);
	// ----
	if (!this->Data[eMenu].OnShow || !IsWorkZone(eMenu))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		
	if(gProtect.m_MainInfo.CustomInterfaceType != 3 || gProtect.m_MainInfo.CustomInterfaceType != 4)
	{
		pSetCursorFocus = false;
	}
		this->Data[eMenu].OnClick = true;
		return true;
	}
	// ----
	this->Data[eMenu].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	
	// ----
	this->Data[eMenu].EventTick = GetTickCount();
	
	if (CheckMenuWindow())
	{
		CloseMenuWindow();
	}
	else
	{
		CloseCustomWindow();
		OpenMenuWindow();
	}
	// ----
	return false;
}

void Interface::DrawMenuOpen()
{
	if (gProtect.m_MainInfo.CustomMenuSwitch != 1 || !this->Data[eMenu_MAIN].OnShow || pCheckWindow(pWindowThis(), 35))
	{
		return;
	}

	pSetCursorFocus = true; // Certifique-se de que esta variável está corretamente declarada

	float MainWidth = 230.0;
	float MainHeight = 270.0;
	float StartY = ((MAX_WIN_HEIGHT - 51) / 2) - (MainHeight / 2);
	float StartX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
	float MainCenter = StartX + (MainWidth / 3);
	float ButtonX = MainCenter - (float)(29.0 / 2);
	//--
	this->Data[eMenu_MAIN].MaxX = StartX + MainWidth;
	this->Data[eMenu_MAIN].MaxY = StartY + MainHeight;

	gCentral.PrintDropBox(StartX, StartY, MainWidth, MainHeight, 0, 0);

	pSetFont(pTextThis(), (int)pFontBigBold);
	pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0);
	pSetTextColor(pTextThis(), 240, 240, 240, 255); //-- eWhite
	pDrawText(pTextThis(), StartX + 10, StartY + 10, "Menu Option", 210, 0, (LPINT)3, 0);

	if(gProtect.m_MainInfo.EnableCoinStatus == 1)
	{
		this->DrawFormat(eGold, (int)StartX + 10, (int)StartY + 35, 210, 3, gCustomMessage.GetMessage(50));

		this->DrawFormat(eWhite, (int)StartX + 25, (int)StartY + 55, 40, 1, gCustomMessage.GetMessage(51));
		this->DrawFormat(eGold, (int)StartX + 50, (int)StartY + 55, 40, 1, "%d",Coin1);

		this->DrawFormat(eWhite, (int)StartX + 90, (int)StartY + 55, 40, 1, gCustomMessage.GetMessage(52));
		this->DrawFormat(eGold, (int)StartX + 115, (int)StartY + 55, 40, 1, "%d",Coin2);

		this->DrawFormat(eWhite, (int)StartX + 153, (int)StartY + 55, 40, 1, gCustomMessage.GetMessage(53));
		this->DrawFormat(eGold, (int)StartX + 176, (int)StartY + 55, 40, 1, "%d",Coin3);

		this->DrawFormat(eWhite, (int)StartX + 153, (int)StartY + 40, 40, 1, gCustomMessage.GetMessage(93));
		this->DrawFormat(eGold, (int)StartX + 176, (int)StartY + 40, 40, 1, "%d", Ruud);
	}
	else
	{
		this->DrawFormat(eGold, (int)StartX + 10, (int)StartY + 45, 210, 3, gCustomMessage.GetMessage(54));
	}

	pDrawGUI(71520, StartX + (MainWidth / 2) - (200 / 2), StartY + 75, 200, 1); //-- Divisor
	float CurrentMove;
	int BtCount = -1;
	int BtStart = StartY + 88;
	int BtDistance	= 28;

	if (gProtect.m_MainInfo.EnableEventTimeButton == 1){
		BtCount++;
	}else{	
		BtStart	-= 27;
	}
	if (gProtect.m_MainInfo.EnableVipShopButton == 1){
		BtCount++;
	}
	if (gProtect.m_MainInfo.EnableRankingButton == 1){
		BtCount++;
	}
	if (gProtect.m_MainInfo.EnableCommandButton == 1){
		BtCount++;
	}
	if (gProtect.m_MainInfo.EnableAchievementsButton == 1){
		BtCount++;
	}
	if (gProtect.m_MainInfo.EnablePartySettingsButton == 1){
		BtCount++;
	}
	if (gProtect.m_MainInfo.EnableChangeClassButton == 1){
		BtCount++;
	}

	if (BtCount == 6){
		BtStart     += -15;
	}
	if (BtCount == 5){
		BtStart     += 0;
    }
	if (BtCount == 4){
		BtStart		+= 15;
	}
	if (BtCount == 3){
		BtStart		+= 30;
	}
	if (BtCount == 2){
		BtStart		+= 45;
	}
	if (BtCount == 1){
		BtStart		+= 60;
	}

	//Horario eventos
	float eButtonOPX;
	eButtonOPX = StartX + 60;

	if (gProtect.m_MainInfo.EnableEventTimeButton == 1){	
	if (IsWorkZone(eMenu_OPT1))
	{
		if (this->Data[eMenu_OPT1].OnClick)
			this->DrawButton(eMenu_OPT1, eButtonOPX, BtStart, 0, 58);
		else
			this->DrawButton(eMenu_OPT1, eButtonOPX, BtStart, 0, 29);
		// ----
	}
	else
		this->DrawButton(eMenu_OPT1, eButtonOPX, BtStart, 0, 0);

	this->DrawFormat(eWhite, eButtonOPX, BtStart + 9, 108, 3, gCustomMessage.GetMessage(25));
	}

	//Comprar vip
	if (gProtect.m_MainInfo.EnableVipShopButton == 1)
	{
	
	BtStart += BtDistance;

	if (IsWorkZone(eMenu_OPT2))
	{
		if (this->Data[eMenu_OPT2].OnClick)
			this->DrawButton(eMenu_OPT2, eButtonOPX, BtStart, 0, 58);
		else
			this->DrawButton(eMenu_OPT2, eButtonOPX, BtStart, 0, 29);
		// ----
	}
	else
		this->DrawButton(eMenu_OPT2, eButtonOPX, BtStart, 0, 0);

	this->DrawFormat(eWhite, eButtonOPX, BtStart + 9, 108, 3, gCustomMessage.GetMessage(26));
	}

	//Ranking
	if (gProtect.m_MainInfo.EnableRankingButton == 1)
	{
	BtStart += BtDistance;

	if (IsWorkZone(eMenu_OPT3))
	{
		if (this->Data[eMenu_OPT3].OnClick)
			this->DrawButton(eMenu_OPT3, eButtonOPX, BtStart, 0, 58);
		else
			this->DrawButton(eMenu_OPT3, eButtonOPX, BtStart, 0, 29);
		// ----
	}
	else
		this->DrawButton(eMenu_OPT3, eButtonOPX, BtStart, 0, 0);

	this->DrawFormat(eWhite, eButtonOPX, BtStart + 9, 108, 3, gCustomMessage.GetMessage(27));
	}

	if (gProtect.m_MainInfo.EnableCommandButton == 1)
	{
	//Commandos
	BtStart += BtDistance;

	if (IsWorkZone(eMenu_OPT4))
	{
		if (this->Data[eMenu_OPT4].OnClick)
			this->DrawButton(eMenu_OPT4, eButtonOPX, BtStart, 0, 58);
		else
			this->DrawButton(eMenu_OPT4, eButtonOPX, BtStart, 0, 29);
		// ----
	}
	else
		this->DrawButton(eMenu_OPT4, eButtonOPX, BtStart, 0, 0);

	this->DrawFormat(eWhite, eButtonOPX, BtStart + 9, 108, 3, gCustomMessage.GetMessage(28));
	}

	if (gProtect.m_MainInfo.EnablePartySettingsButton == 1)
	{
	//Party Settings
	BtStart += BtDistance;

	if (IsWorkZone(eMenu_OPT5))
	{
		if (this->Data[eMenu_OPT5].OnClick)
			this->DrawButton(eMenu_OPT5, eButtonOPX, BtStart, 0, 58);
		else
			this->DrawButton(eMenu_OPT5, eButtonOPX, BtStart, 0, 29);
		// ----
	}
	else
		this->DrawButton(eMenu_OPT5, eButtonOPX, BtStart, 0, 0);

	if(gProtect.m_MainInfo.EnablePartySettingsButton == 1){
	    this->DrawFormat(eWhite, eButtonOPX, BtStart + 9, 108, 3, "Party Settings");
	}else{
		this->DrawFormat(eWhite, eButtonOPX, BtStart + 9, 108, 3, "Party Settings");
	}
	}

	if (gProtect.m_MainInfo.EnableChangeClassButton == 1)
	{
	//Change Class
	BtStart += BtDistance;

	if (IsWorkZone(eMenu_OPT6))
	{
		if (this->Data[eMenu_OPT6].OnClick)
			this->DrawButton(eMenu_OPT6, eButtonOPX, BtStart, 0, 58);
		else
			this->DrawButton(eMenu_OPT6, eButtonOPX, BtStart, 0, 29);
		// ----
	}
	else
		this->DrawButton(eMenu_OPT6, eButtonOPX, BtStart, 0, 0);

	this->DrawFormat(eWhite, eButtonOPX, BtStart + 9, 108, 3, "Change Class");
	}

	if (gProtect.m_MainInfo.EnableAchievementsButton == 1)
	{
	//Option
	BtStart += BtDistance;

	if (IsWorkZone(eMenu_OPT20))
	{
		if (this->Data[eMenu_OPT20].OnClick)
			this->DrawButton(eMenu_OPT20, eButtonOPX, BtStart, 0, 58);
		else
			this->DrawButton(eMenu_OPT20, eButtonOPX, BtStart, 0, 29);
		// ----
	}
	else
		this->DrawButton(eMenu_OPT20, eButtonOPX, BtStart, 0, 0);

	this->DrawFormat(eWhite, eButtonOPX, BtStart + 9, 108, 3, gCustomMessage.GetMessage(44));
	}
}

bool Interface::EventDrawMenu_Close(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eMenu_CLOSE].EventTick);
	// ----
	if (!this->Data[eMenu_MAIN].OnShow || !IsWorkZone(eMenu_CLOSE))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eMenu_CLOSE].OnClick = true;
		return true;
	}
	// ----
	this->Data[eMenu_CLOSE].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eMenu_CLOSE].EventTick = GetTickCount();
	this->CloseMenuWindow();
	// ----
	return false;
}
// ----------------------------------------------------------------------------------------------

bool Interface::EventDrawMenu_Op1(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eMenu_OPT1].EventTick);
	// ----
	if (!this->Data[eMenu_MAIN].OnShow || !IsWorkZone(eMenu_OPT1))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eMenu_OPT1].OnClick = true;
		return true;
	}
	// ----
	this->Data[eMenu_OPT1].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eMenu_OPT1].EventTick = GetTickCount();

	this->CloseMenuWindow();

	gCustomEventTime.OpenWindow();
	// ----
	return false;
}

bool Interface::EventDrawMenu_Op2(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eMenu_OPT2].EventTick);
	// ----
	if (!this->Data[eMenu_MAIN].OnShow || !IsWorkZone(eMenu_OPT2))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eMenu_OPT2].OnClick = true;
		return true;
	}
	// ----
	this->Data[eMenu_OPT2].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eMenu_OPT2].EventTick = GetTickCount();

	this->CloseCustomWindow();

	this->OpenVipWindow();
	// ----
	return false;
}

bool Interface::EventDrawMenu_Op3(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eMenu_OPT3].EventTick);
	// ----
	if (!this->Data[eMenu_MAIN].OnShow || !IsWorkZone(eMenu_OPT3))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eMenu_OPT3].OnClick = true;
		return true;
	}
	// ----
	this->Data[eMenu_OPT3].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eMenu_OPT3].EventTick = GetTickCount();

	this->CloseMenuWindow();

	gCustomRanking.OpenWindow();
	// ----
	return false;
}

bool Interface::EventDrawMenu_Op4(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eMenu_OPT4].EventTick);
	// ----
	if (!this->Data[eMenu_MAIN].OnShow || !IsWorkZone(eMenu_OPT4))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eMenu_OPT4].OnClick = true;
		return true;
	}
	// ----
	this->Data[eMenu_OPT4].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eMenu_OPT4].EventTick = GetTickCount();

	this->CloseMenuWindow();

	gCustomCommandInfo.OpenCommandWindow();
	// ----
	return false;
}

bool Interface::EventDrawMenu_Op5(DWORD Event){
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eMenu_OPT5].EventTick);
	if (!this->Data[eMenu_MAIN].OnShow || !IsWorkZone(eMenu_OPT5)){
		return false;
	}
	if (Event == WM_LBUTTONDOWN){
		this->Data[eMenu_OPT5].OnClick = true;
		return true;
	}
	this->Data[eMenu_OPT5].OnClick = false;;
	if (Delay < 500){
		return false;
	}
	this->Data[eMenu_OPT5].EventTick = GetTickCount();
	this->CloseMenuWindow();
	gInterface.SwitchPartySettingsWindowState();
	return false;
}

bool Interface::EventDrawMenu_Op6(DWORD Event){
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eMenu_OPT6].EventTick);
	if (!this->Data[eMenu_MAIN].OnShow || !IsWorkZone(eMenu_OPT6)){
		return false;
	}
	if (Event == WM_LBUTTONDOWN){
		this->Data[eMenu_OPT6].OnClick = true;
		return true;
	}
	this->Data[eMenu_OPT6].OnClick = false;;
	if (Delay < 500){
		return false;
	}
	this->Data[eMenu_OPT6].EventTick = GetTickCount();
	this->CloseMenuWindow();
	gInterface.Data[eCHANGINGCLASS_MAIN].Open();
	return false;
}

bool Interface::EventDrawMenu_Op20(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eMenu_OPT20].EventTick);
	// ----
	if (!this->Data[eMenu_MAIN].OnShow || !IsWorkZone(eMenu_OPT20))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eMenu_OPT20].OnClick = true;
		return true;
	}
	// ----
	this->Data[eMenu_OPT20].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eMenu_OPT20].EventTick = GetTickCount();

	this->CloseMenuWindow();

	gAchievements.CGWindowOpen();
	// ----
	return false;
}



bool Interface::MiniMapCheck()
{
	bool visual = false;

	if ( gInterface.CheckWindow(13) && gInterface.CheckWindow(Character)
    || gInterface.CheckWindow(8)
    || gInterface.CheckWindow(12)
    || gInterface.CheckWindow(9)
    || gInterface.CheckWindow(7)
    || gInterface.CheckWindow(14)
    || gInterface.CheckWindow(15)
    || gInterface.CheckWindow(60)
    || gInterface.CheckWindow(76) )
	{
		visual = true;
	}
	else
	{
		if ( gInterface.CheckWindow(16) && (gInterface.CheckWindow(4)||gInterface.CheckWindow(69)) )
		{
			visual = true;
		}
		else
		{
			if ( gInterface.CheckWindow(16) && gInterface.CheckWindow(11) )
			{
				visual = true;
			}
			else
			{
				if ( gInterface.CheckWindow(27) )
				{
					visual = true;
				}
				else
				{
					if ( gInterface.CheckWindow(13)
					|| gInterface.CheckWindow(16)
					|| gInterface.CheckWindow(3)
					|| gInterface.CheckWindow(21)
					|| gInterface.CheckWindow(6)
					|| gInterface.CheckWindow(22)
					|| gInterface.CheckWindow(23)
					|| gInterface.CheckWindow(24)
					|| gInterface.CheckWindow(4)
					|| gInterface.CheckWindow(18)
					|| gInterface.CheckWindow(10)
					|| gInterface.CheckWindow(5)
					|| gInterface.CheckWindow(25)
					|| gInterface.CheckWindow(26)
					|| gInterface.CheckWindow(19)
					|| gInterface.CheckWindow(20)
					|| gInterface.CheckWindow(58)
					|| gInterface.CheckWindow(59)
					|| gInterface.CheckWindow(62)
					|| gInterface.CheckWindow(73)
					|| gInterface.CheckWindow(68)
					|| gInterface.CheckWindow(69)
					|| gInterface.CheckWindow(70)
					|| gInterface.CheckWindow(66)
					|| gInterface.CheckWindow(75)
					|| gInterface.CheckWindow(74) )
					{
						visual = true;
					}
					else
					{
						if ( gInterface.CheckWindow(79) )
						{
							if ( gInterface.CheckWindow(80) )
							{
								visual = true;
							}
							else
							{
								visual = true;
							}	
						}
					}
				}
			}
		}
	}
  
	if ( gInterface.CheckWindow(77) )
	{
		if ( gInterface.CheckWindow(Warehouse) ||
			gInterface.CheckWindow(ChaosBox) ||
			gInterface.CheckWindow(Store) ||
			gInterface.CheckWindow(OtherStore) ||
			gInterface.CheckWindow(Character))
		{
			visual = true;
		}
		else
		{
			visual = true;
		}
	}
	else if ( gInterface.CheckWindow(78) )
	{
			visual = true;
	}
	return visual;
}

bool Interface::CombinedChecks()
{
	if ((this->CheckWindow(Inventory)
		&& this->CheckWindow(ExpandInventory)
		&& this->CheckWindow(Store)) ||
		(this->CheckWindow(Inventory)
		&& this->CheckWindow(Warehouse)
		&& this->CheckWindow(ExpandWarehouse)) ||
		(this->CheckWindow(Inventory)
		&& this->CheckWindow(Character)
		&& this->CheckWindow(Store)))
		return true;
	return false;
}

/*bool Interface::CheckMap()
{
	switch(gObjUser.m_MapNumber)
	{
		case eMapNumber::Lorencia:
			return false;
			break;
		case eMapNumber::Dungeon:
			return false;
			break;
		case eMapNumber::Devias:
			return false;
			break;
		case eMapNumber::Noria:
			return false;
			break;
		case eMapNumber::LostTower:
			return false;
			break;
		case eMapNumber::Stadium:
			return false;
		case eMapNumber::Atlans:
			return false;
			break;
		case eMapNumber::Tarkan:
			return false;
			break;
		case eMapNumber::Elbeland:
			return false;
			break;
		case eMapNumber::Icarus:
			return false;
			break;
		case eMapNumber::Trials:
			return false;
			break;
		case eMapNumber::Aida:
			return false;
			break;
		case eMapNumber::Crywolf:
			return false;
			break;
		case eMapNumber::Kanturu1:
			return false;
			break;
		case eMapNumber::Kanturu3:
			return false;
			break;
		case eMapNumber::Barracks:
			return false;
			break;
		case eMapNumber::Calmness:
			return false;
			break;
		case eMapNumber::Raklion:
			return false;
			break;
		case eMapNumber::Vulcanus:
			return false;
			break;
		case eMapNumber::Karutan1:
			return false;
			break;
		case eMapNumber::Karutan2:
			return false;
			break;
		default:
			return true;
			break;
	}
}*/

void Interface::CloseCustomWindow()
{
	this->CloseMenuWindow();
	this->CloseVipWindow();
	this->Data[eRankPANEL_MAIN].OnShow		= false;
	this->Data[eEventTimePANEL_MAIN].OnShow = false;
	this->Data[eCommand_MAIN].OnShow		= false;
	
	if(gProtect.m_MainInfo.CustomInterfaceType != 3 || gProtect.m_MainInfo.CustomInterfaceType != 4)
	{
		pSetCursorFocus = false;
	}
}

void Interface::DrawItem(float PosX, float PosY, float Width, float Height, int ItemID, int Level, int Excl, int Anc, bool OnMouse)
{

	if (this->CheckWindow(ObjWindow::MoveList) || this->CheckWindow(ObjWindow::CashShop) || this->CheckWindow(ObjWindow::SkillTree) || this->CheckWindow(ObjWindow::FullMap)
		||  (this->CheckWindow(Inventory) 
		&& this->CheckWindow(ExpandInventory) 
		&& this->CheckWindow(Store)) 
		||  (this->CheckWindow(Inventory) 
		&& this->CheckWindow(Warehouse) 
		&& this->CheckWindow(ExpandWarehouse)) )
	{
		return;
	}

	pSetBlend(true);
	glMatrixMode(0x1701);
	glPushMatrix();
	glLoadIdentity();

	sub_6363D0_Addr(0, 0, *(GLsizei*)MAIN_RESOLUTION_X, *(GLsizei*)MAIN_RESOLUTION_Y);

	float v2 = *(float*)MAIN_RESOLUTION_X / *(float*)MAIN_RESOLUTION_Y;

	if (ItemID == 406)
	{
		sub_6358A0_Addr(0.4, v2, *(float*)0xE61E38, *(float*)0xE61E3C); //tamanho do bmd
	}
	else if (ItemID == 407)
	{
		sub_6358A0_Addr(0.5, v2, *(float*)0xE61E38, *(float*)0xE61E3C); //tamanho do bmd
	}
	else
	{
		sub_6358A0_Addr(0.7, v2, *(float*)0xE61E38, *(float*)0xE61E3C); //tamanho do bmd
	}

	glMatrixMode(0x1700);
	glPushMatrix();
	glLoadIdentity();

	sub_635830_Addr((LPVOID)0x87933A0); 
	sub_635DE0_Addr();
	sub_635E40_Addr();

	glClear(0x100);

	VAngle v45;

	unsigned __int8 v44 = 1; //0 = parado / 1 = girando

	sub_6359B0_Addr(PosX, PosY, (int)&v45, 0); //posição do bmd
	sub_5CA0D0_Addr(ItemID, Level, Excl, Anc, (int)&v45, v44, 0); //funão que mostra o BMD
	
	sub_636720_Addr();

	glMatrixMode(0x1700);
	glPopMatrix();
	glMatrixMode(0x1701);
	glPopMatrix();

	sub_637770_Addr();

	glColor3f(1,1,1);
	pSetBlend(false);
}

void testfunc()
{
	glMatrixMode(0x1700u);
	glPopMatrix();
	glMatrixMode(0x1701u);
	glPopMatrix();
}

void Interface::DrawItem2(float PosX, float PosY, float Width, float Height, int ItemID, int Level, int Excl, int Anc, bool OnMouse) {
	glMatrixMode(0x1701);
	glPushMatrix();
	glLoadIdentity();
	sub_6363D0_Addr(0, 0, *(GLsizei*)0x00E61E58, *(GLsizei*)0x00E61E5C);
	float v2 = *(float*)0x00E61E58 / *(float*)0x00E61E5C;
	sub_6358A0_Addr(1.0, v2, *(float*)0xE61E38, *(float*)0xE61E3C);
	glMatrixMode(0x1700);
	glPushMatrix();
	glLoadIdentity();
	sub_635830_Addr((LPVOID)0x87933A0);
	sub_635DE0_Addr();
	sub_635E40_Addr();
	pDrawItemModel(PosX, PosY, Width, Height, ItemID, Level, Excl, Anc, OnMouse);
	testfunc();
	glColor3f(1, 1, 1);
	pSetBlend(false);
}

void Interface::DrawConfirmOpen()
{
	if(!this->CheckWindow(Shop) && this->Data[eCONFIRM_MAIN].OnShow == true)
	{
		this->Data[eCONFIRM_MAIN].OnShow = false;
	}

	if ((GetTickCount() - this->Data[eCONFIRM_BTN_OK].EventTick) < 100)
	{
		this->Data[eCONFIRM_MAIN].OnShow = false;
	}

	if ((GetTickCount() - this->Data[eCONFIRM_BTN_CANCEL].EventTick) < 100)
	{
		this->Data[eCONFIRM_MAIN].OnShow = false;
	}

	if( !this->Data[eCONFIRM_MAIN].OnShow )
	{
		return;
	}

	float StartX;
	if( gProtect.m_MainInfo.CustomInterfaceType == 3 )
	{
		StartX = 205.0f;
	}
	else
	{
		StartX = 25.0f;
	}

	float MainWidth			= 230.0;
	float MainHeight		= 130.0;
	float StartBody			= 90.0;
	float StartY			= 90.0;
	
	float MainCenter		= StartX + (MainWidth / 3);
	float ButtonX			= MainCenter - (float)(29.0 / 2);

	gCentral.PrintDropBox(StartX, StartY, MainWidth, MainHeight, 0, 0);

	this->DrawFormat(eGold, (int)StartX + 10, (int)StartBody + 10, 210, 3, gCustomMessage.GetMessage(66));

	this->DrawFormat(eGold, (int)StartX + 10, (int)StartBody + 40, 210, 3, gCustomMessage.GetMessage(67));

	this->DrawButton(eCONFIRM_BTN_OK, (int)StartX+40, (int)StartBody + 70, 0, 0);

	if( this->IsWorkZone(eCONFIRM_BTN_OK) )
	{
		int ScaleY = 30;
		// ----
		if( this->Data[eCONFIRM_BTN_OK].OnClick )
		{
			ScaleY = 60;
		}
		// ----
		this->DrawButton(eCONFIRM_BTN_OK, (int)StartX+40, (int)StartBody + 70, 0, ScaleY);
	}

	this->DrawButton(eCONFIRM_BTN_CANCEL, (int)StartX+140, (int)StartBody + 70, 0, 0);

	if( this->IsWorkZone(eCONFIRM_BTN_CANCEL) )
	{
		int ScaleY = 30;
		// ----
		if( this->Data[eCONFIRM_BTN_CANCEL].OnClick )
		{
			ScaleY = 60;
		}
		// ----
		this->DrawButton(eCONFIRM_BTN_CANCEL, (int)StartX+140, (int)StartBody + 70, 0, ScaleY);
	}

}


bool Interface::EventConfirm_OK(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eCONFIRM_BTN_OK].EventTick);
	// ----
	if (!this->Data[eCONFIRM_MAIN].OnShow || !IsWorkZone(eCONFIRM_BTN_OK))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eCONFIRM_BTN_OK].OnClick = true;
		return true;
	}
	// ----
	this->Data[eCONFIRM_BTN_OK].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eCONFIRM_BTN_OK].EventTick = GetTickCount();

	PMSG_ITEM_BUY_RECV pMsg;

	pMsg.header.set(0xF3, 0xED,sizeof(pMsg));

	pMsg.slot = this->ConfirmSlot;

	DataSend((BYTE*)&pMsg,pMsg.header.size);

	this->Data[eCONFIRM_MAIN].OnShow = false;
	
	if(gProtect.m_MainInfo.CustomInterfaceType != 3 || gProtect.m_MainInfo.CustomInterfaceType != 4)
	{
		pSetCursorFocus = false;
	}
	// ----
	return false;
}

bool Interface::EventConfirm_CANCEL(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eCONFIRM_BTN_CANCEL].EventTick);
	// ----
	if (!this->Data[eCONFIRM_MAIN].OnShow || !IsWorkZone(eCONFIRM_BTN_CANCEL))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eCONFIRM_BTN_CANCEL].OnClick = true;
		return true;
	}
	// ----
	this->Data[eCONFIRM_BTN_CANCEL].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eCONFIRM_BTN_CANCEL].EventTick = GetTickCount();

	this->Data[eCONFIRM_MAIN].OnShow = false;

	if(gProtect.m_MainInfo.CustomInterfaceType != 3 || gProtect.m_MainInfo.CustomInterfaceType != 4)
	{
		pSetCursorFocus = false;
	}
	// ----
	return false;
}

//-- advance
void Interface::DrawBarForm(float PosX, float PosY, float Width, float Height, GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha)
{
	pSetBlend(true);
	glColor4f((GLfloat)0.0, (GLfloat)0.0, (GLfloat)0.0, (float)0.8);
	pDrawBarForm(PosX, PosY, Width, Height, 0.0f, 0);
	pGLSwitchBlend();
	pGLSwitch();
	glColor3f(1.0, 1.0, 1.0);
	pSetBlend(false);
}
// ----------------------------------------------------------------------------------------------
bool Interface::CheckWindowEx(int WindowID)
{
	if (WindowID < 0 || WindowID > MAX_WINDOW_EX)
	{
		return 0;
	}
	return this->WindowEx[WindowID];
}

//---- cosas peladas

void Interface::UPDATE_FPS(){
	gInterface.frameCount++;
	if (GetTickCount() - gInterface.lastReport >= 1000)
	{
		gInterface.frameRate = gInterface.frameCount / ((GetTickCount() - gInterface.lastReport) / 1000);
		sprintf(gInterface.FPS_REAL, "FPS: %d", gInterface.frameRate);
		gInterface.lastReport = GetTickCount();
		gInterface.frameCount = 0;
	}

	if (this->MiniMapCheck() || this->CombinedChecks() || this->CheckWindow(FullMap) || this->CheckWindow(FriendList) || this->CheckWindow(SkillTree) || this->CheckWindow(CashShop) )
	{
		return;
	}

	this->DrawFormat(eGold, 600, 5, 80, 1, gInterface.FPS_REAL);
}

void Interface::guiMonitore(){
	if (this->MiniMapCheck() || this->CombinedChecks() || this->CheckWindow(FullMap) || this->CheckWindow(FriendList) || this->CheckWindow(SkillTree) || this->CheckWindow(CashShop))
	{
		return;
	}
	pSetBlend(true);
	glColor4f((GLfloat)0.0, (GLfloat)0.0, (GLfloat)0.0, (float)0.8);
	pDrawBarForm(460.0, 0.0, 180.0, 20.0, 0.0f, 0);
	pGLSwitchBlend();
	pGLSwitch();
	glColor3f(1.0, 1.0, 1.0);
	pSetBlend(false);
}

void Interface::DrawPing()
{
	gInterface.msPing = GetTickCount() - gInterface.lastSend;
	gInterface.iniciador = 3;
}

struct PMSG_PING
{
	PBMSG_HEAD h;
};

void Interface::SendPingRecv()
{
	if(gInterface.iniciador == 1)
	{
		PMSG_PING pMsgPing;
		pMsgPing.h.set(0x80,sizeof(pMsgPing));
		gInterface.lastSend = GetTickCount();
		DataSend((BYTE*)&pMsgPing,sizeof(pMsgPing));
		gInterface.iniciador=2;
	}
	else if(gInterface.iniciador == 3)
	{
		if (GetTickCount() >= gInterface.lastSend + 1000){
			PMSG_PING pMsgPing;
			pMsgPing.h.set(0x80,sizeof(pMsgPing));
			gInterface.lastSend = GetTickCount();
			DataSend((BYTE*)&pMsgPing,sizeof(pMsgPing));
			gInterface.iniciador=2;
		}
	}

	if (this->MiniMapCheck() || this->CombinedChecks() || this->CheckWindow(FullMap) || this->CheckWindow(FriendList) || this->CheckWindow(SkillTree) || this->CheckWindow(CashShop))
	{
		return;
	}
	sprintf(gInterface.ServerRTT, "RTT: %d ms", gInterface.msPing);
	sprintf(gInterface.ServerPing, "PING: %d ms", (gInterface.msPing/2));
	// ----
	gInterface.validar=0;

	if(gInterface.msPing > 0){
		//----
		this->DrawFormat(eGold, 470, 5, 120, 1, gInterface.ServerRTT);
		this->DrawFormat(eGold, 530, 5, 120, 1, gInterface.ServerPing);
		//--
		sprintf(gInterface.ultimoRTT, gInterface.ServerRTT);
		sprintf(gInterface.ultimoPing, gInterface.ServerPing);
		//--
		gInterface.ultimo_RTT = gInterface.msPing;
		gInterface.validar=1;
	}

	if(gInterface.validar==0)
	{
		if(gInterface.ultimo_RTT > 0)
		{
			this->DrawFormat(eGold, 470, 5, 80, 1, gInterface.ultimoRTT);
			this->DrawFormat(eGold, 530, 5, 120, 1, gInterface.ultimoPing);
		}
		else
		{
			this->DrawFormat(eGold, 470, 5, 120, 1, gInterface.ServerRTT);
			this->DrawFormat(eGold, 530, 5, 120, 1, gInterface.ServerPing);
		}
	}
}

void Interface::SwitchChatExpand()
{

	if((GetTickCount() - gInterface.Data[chatbackground].EventTick) < 1000 ||this->CheckWindow(ChatWindow))
	{
		return;
	}

	gInterface.Data[chatbackground].EventTick = GetTickCount();

	if (SeparateChat != 0)
	{
		gInterface.DrawMessage(1, "Chat Window Separate [OFF]");
		SeparateChat = 0;
		WritePrivateProfileStringA("Setting","SeparateChat","0","./Settings.ini");
	}
	else 
	{
		gInterface.DrawMessage(1, "Chat Window Separate [ON]");
		SeparateChat = 1;
		WritePrivateProfileStringA("Setting","SeparateChat","1","./Settings.ini");
	}
	gChatExpanded.Switch();
}

void Interface::OpenConfig(int type)
{
	if(type == 0)
	{
		if( (GetTickCount() - gInterface.Data[ePLAYER_POINT].EventTick) < 400 
			|| this->CheckWindow(ChatWindow) 
			|| this->CheckWindow(MuHelper) 
			|| this->CheckWindow(Inventory) 
			|| this->CheckWindow(Store) 
			|| this->CheckWindow(Character) 
			|| this->CheckWindow(CreateGuild) )
		{
			return;
		}

		gInterface.Data[ePLAYER_POINT].EventTick = GetTickCount();

		if (pCheckWindow(pWindowThis(), 35))
		{
			pCloseWindow(pWindowThis(), 35);
		}
		else 
		{
			pOpenWindow(pWindowThis(), 35);
		}
	}
	else if(type = 1 )
	{
		if( (GetTickCount() - gInterface.Data[ePLAYER_POINT].EventTick) < 400 || OpenSwicthSkill == 0)
		{
			return;
		}

		gInterface.Data[ePLAYER_POINT].EventTick = GetTickCount();

		if (SkillPage == 1)
		{
			SkillPage = 2;
		}
		else
		{
			SkillPage = 1;
		}
	}

	PlayBuffer(25, 0, 0);
}
//-- SwitchCamera
void Interface::SwitchCamera()
{
	if( (GetTickCount() - gInterface.Data[eCamera3DSwitch].EventTick) < 1000 )
	{
		return;
	}

	if( pMapNumber == 62 )
	{
		gInterface.DrawMessage(1, "Camera3D not available for this map");
		gCamera.Restore();
	}

	gInterface.Data[eCamera3DSwitch].EventTick = GetTickCount();

	gCamera.Toggle();

	if (gCamera.getEnabled())
	{
		gInterface.DrawMessage(1, "Camera3D [ON]");
	}
	else
	{
		gInterface.DrawMessage(1, "Camera3D [OFF]");
	}
}
//-- CameraInit
void Interface::CameraInit(){

	if((GetTickCount() - gInterface.Data[eCamera3DInit].EventTick) < 1000 )
	{
		return;
	}

	gInterface.Data[eCamera3DInit].EventTick = GetTickCount();

	if (gCamera.getEnabled())
	{
		gInterface.DrawMessage(1, "Camera Restore [DEFAULT]");
		gCamera.Restore();
	}
}

bool Interface::Button(DWORD Event, int WinID, int ButtonID, bool Type)
{
	if (!this->IsWorkZone(ButtonID))
	{
		return false;
	}

	if (Type == true)
	{
		if (!this->Data[ButtonID].Attribute)
		{
			return false;
		}
	}

	// ----
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[ButtonID].EventTick);
	// ----

	if (Event == WM_LBUTTONDOWN  && this->Data[ButtonID].OnClick == false)
	{
		this->Data[ButtonID].OnClick = true;
	}

	if (Event == WM_LBUTTONUP && this->Data[ButtonID].OnClick == true)
	{
		this->Data[ButtonID].OnClick = false;
		return true;
	}
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[ButtonID].OnClick = false;
	// ----
	this->Data[ButtonID].EventTick = GetTickCount();
	// ----
	return false;
}

void Interface::DrawInterfaceS2Menu()
{
	if (IsWorkZone(eParty))
	{
		this->DrawToolTip(345, 420, "Party");
	}
	if (this->CheckWindow(Party))
	{
		gInterface.DrawButton(eParty, 348, 451, 0.0, 0.0);
	}
	if (IsWorkZone(eCharacter))
	{
		this->DrawToolTip(375, 420, "Character");
	}
	if (this->CheckWindow(Character))
	{
		gInterface.DrawButton(eCharacter, 378.5f, 451, 0.0, 0.0);
	}
	if (IsWorkZone(eInventory))
	{
		this->DrawToolTip(405, 420, "Inventory");
	}
	if (this->CheckWindow(Inventory))
	{
		gInterface.DrawButton(eInventory, 409, 451, 0.0, 0.0);
	}
	if (IsWorkZone(eShop))
	{
		this->DrawToolTip(430, 420, "CashShop");
	}
	if (this->CheckWindow(CashShop))
	{
		gInterface.DrawButton(eShop, 439.5f, 451, 0.0, 0.0);
	}
	if (IsWorkZone(eFriend))
	{
		this->DrawToolTip(580, 420, "Friends");
	}
	if (this->CheckWindow(FriendList))
	{
		gInterface.DrawButton(eFriend, 581, 433, 0.0, 0.0);
	}
	if (IsWorkZone(eGuild))
	{
		this->DrawToolTip(580, 444, "Guild");
	}
	if (this->CheckWindow(Guild))
	{
		gInterface.DrawButton(eGuild, 581, 457, 0.0, 0.0);
	}
	if (IsWorkZone(eFastMenu))
	{
		this->DrawToolTip(13, 420, "System");
	}
	if (this->CheckWindow(FastMenu))
	{
		gInterface.DrawButton(eFastMenu, 6, 433, 0.0, 0.0);
	}
}
//--------------------------------------
void Interface::DrawInterface97Menu()
{
	if (IsWorkZone(eParty))
	{
		this->DrawToolTip(345, 420, "Party");
	}
	if (this->CheckWindow(Party))
	{
		gInterface.DrawButton(eParty, 348, 451, 0.0, 0.0);
	}
	if (IsWorkZone(eCharacter))
	{
		this->DrawToolTip(375, 420, "Character");
	}
	if (this->CheckWindow(Character))
	{
		gInterface.DrawButton(eCharacter, 378.5f, 451, 0.0, 0.0);
	}
	if (IsWorkZone(eInventory))
	{
		this->DrawToolTip(405, 420, "Inventory");
	}
	if (this->CheckWindow(Inventory))
	{
		gInterface.DrawButton(eInventory, 409, 451, 0.0, 0.0);
	}
	if (IsWorkZone(eShop))
	{
		this->DrawToolTip(430, 420, "CashShop");
	}
	if (this->CheckWindow(CashShop))
	{
		gInterface.DrawButton(eShop, 439.5f, 451, 0.0, 0.0);
	}
	if (IsWorkZone(eFriend))
	{
		this->DrawToolTip(580, 420, "Friends");
	}
	if (this->CheckWindow(FriendList))
	{
		gInterface.DrawButton(eFriend, 581, 433, 0.0, 0.0);
	}
	if (IsWorkZone(eGuild))
	{
		this->DrawToolTip(580, 444, "Guild");
	}
	if (this->CheckWindow(Guild))
	{
		gInterface.DrawButton(eGuild, 581, 457, 0.0, 0.0);
	}
}
//--------------------------------------
void Interface::EventNewInterface_All(DWORD Event){
	DWORD CurrentTick = GetTickCount();
	if (this->CheckWindow(ChaosBox))
	{
		return;
	}
	
	if (IsWorkZone(eFastMenu))
	{
		DWORD Delay = (CurrentTick - this->Data[eFastMenu].EventTick);
		if (Event == WM_LBUTTONDOWN) {
			this->Data[eFastMenu].OnClick = true;
			return;
		}
		this->Data[eFastMenu].OnClick = false;
		if (Delay < 500) {
			return;
		}
		this->Data[eFastMenu].EventTick = GetTickCount();
		if (this->CheckWindow(FastMenu)) {
				this->CloseWindow(FastMenu);
		}
		else {
			this->OpenWindow(FastMenu);
		}
	}
	else if (IsWorkZone(eParty))
	{
		DWORD Delay = (CurrentTick - this->Data[eParty].EventTick);
		if (Event == WM_LBUTTONDOWN) {
			this->Data[eParty].OnClick = true;
			return;
		}
		this->Data[eParty].OnClick = false;
		if (Delay < 500) {
			return;
		}
		this->Data[eParty].EventTick = GetTickCount();
		if (this->CheckWindow(Party)) {
			this->CloseWindow(Party);
		}
		else {
			this->OpenWindow(Party);
		}
	}
	
	else if (IsWorkZone(eCharacter))
	{
		DWORD Delay = (CurrentTick - this->Data[eCharacter].EventTick);
		if (Event == WM_LBUTTONDOWN) {
			this->Data[eCharacter].OnClick = true;
			return;
		}
		this->Data[eCharacter].OnClick = false;
		if (Delay < 500) {
			return;
		}
		this->Data[eCharacter].EventTick = GetTickCount();
		if (this->CheckWindow(Character)) {
			this->CloseWindow(Character);
		}
		else {
			this->OpenWindow(Character);
		}
	}
	else if (IsWorkZone(eInventory))
	{
		DWORD Delay = (CurrentTick - this->Data[eInventory].EventTick);
		if (Event == WM_LBUTTONDOWN) {
			this->Data[eInventory].OnClick = true;
			return;
		}
		this->Data[eInventory].OnClick = false;
		if (Delay < 500) {
			return;
		}
		this->Data[eInventory].EventTick = GetTickCount();
		if (this->CheckWindow(Inventory)) {
			this->CloseWindow(Inventory);
		}
		else {
			this->OpenWindow(Inventory);
		}
	}
	else if (IsWorkZone(eFriend))
	{
		DWORD Delay = (CurrentTick - this->Data[eFriend].EventTick);
		if (Event == WM_LBUTTONDOWN) {
			this->Data[eFriend].OnClick = true;
			return;
		}
		this->Data[eFriend].OnClick = false;
		if (Delay < 500) {
			return;
		}
		this->Data[eFriend].EventTick = GetTickCount();
		if (this->CheckWindow(FriendList)) {
			this->CloseWindow(FriendList);
		}
		else {
			this->OpenWindow(FriendList);
		}
	}
	else if (IsWorkZone(eGuild))
	{
		DWORD Delay = (CurrentTick - this->Data[eGuild].EventTick);
		if (Event == WM_LBUTTONDOWN) {
			this->Data[eGuild].OnClick = true;
			return;
		}
		this->Data[eGuild].OnClick = false;
		if (Delay < 500) {
			return;
		}
		this->Data[eGuild].EventTick = GetTickCount();
		if (this->CheckWindow(Guild)) {
			this->CloseWindow(Guild);
		}
		else {
			this->OpenWindow(Guild);
		}
	}
}
void Interface::EventNewInterface97_All(DWORD Event){
	DWORD CurrentTick = GetTickCount();
	if (this->CheckWindow(ChaosBox))
	{
		return;
	}
	
	if (IsWorkZone(eParty))
	{
		DWORD Delay = (CurrentTick - this->Data[eParty].EventTick);
		if (Event == WM_LBUTTONDOWN) {
			this->Data[eParty].OnClick = true;
			return;
		}
		this->Data[eParty].OnClick = false;
		if (Delay < 500) {
			return;
		}
		this->Data[eParty].EventTick = GetTickCount();
		if (this->CheckWindow(Party)) {
			this->CloseWindow(Party);
		}
		else {
			this->OpenWindow(Party);
		}
	}
	
	else if (IsWorkZone(eCharacter))
	{
		DWORD Delay = (CurrentTick - this->Data[eCharacter].EventTick);
		if (Event == WM_LBUTTONDOWN) {
			this->Data[eCharacter].OnClick = true;
			return;
		}
		this->Data[eCharacter].OnClick = false;
		if (Delay < 500) {
			return;
		}
		this->Data[eCharacter].EventTick = GetTickCount();
		if (this->CheckWindow(Character)) {
			this->CloseWindow(Character);
		}
		else {
			this->OpenWindow(Character);
		}
	}
	else if (IsWorkZone(eInventory))
	{
		DWORD Delay = (CurrentTick - this->Data[eInventory].EventTick);
		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eInventory].OnClick = true;
			return;
		}
		this->Data[eInventory].OnClick = false;
		if (Delay < 500)
		{
			return;
		}
		this->Data[eInventory].EventTick = GetTickCount();
		if (this->CheckWindow(Inventory))
		{
			this->CloseWindow(Inventory);
		}
		else {
			this->OpenWindow(Inventory);
		}
	}
	else if (IsWorkZone(eFriend))
	{
		DWORD Delay = (CurrentTick - this->Data[eFriend].EventTick);
		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eFriend].OnClick = true;
			return;
		}
		this->Data[eFriend].OnClick = false;
		if (Delay < 500)
		{
			return;
		}
		this->Data[eFriend].EventTick = GetTickCount();
		if (this->CheckWindow(FriendList))
		{
			this->CloseWindow(FriendList);
		}
		else {
			this->OpenWindow(FriendList);
		}
	}
	else if (IsWorkZone(eGuild))
	{
		DWORD Delay = (CurrentTick - this->Data[eGuild].EventTick);
		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eGuild].OnClick = true;
			return;
		}
		this->Data[eGuild].OnClick = false;
		if (Delay < 500)
		{
			return;
		}
		this->Data[eGuild].EventTick = GetTickCount();
		if (this->CheckWindow(Guild))
		{
			this->CloseWindow(Guild);
		}
		else {
			this->OpenWindow(Guild);
		}
	}
}

void Interface::DrawInterfaceDragonLS3()
{
	/*if(this->CheckWindow(ObjWindow::CashShop)
		|| this->CheckWindow(ObjWindow::FullMap)
		|| this->CheckWindow(ObjWindow::SkillTree)
		|| this->CheckWindow(ObjWindow::MoveList)
		|| this->Data[eTIME].OnShow
		)
	{
		return;
	}*/
	//-> Disable Move List
	if(this->CheckWindow(ObjWindow::CashShop)
		|| this->CheckWindow(ObjWindow::FullMap) 
		//|| this->CheckWindow(ObjWindow::ChatWindow) 
		|| this->CheckWindow(ObjWindow::SkillTree)
		//|| this->CheckWindow(ObjWindow::MoveList)
		)
	{
		return;
	}
	if (jCRenderRuud.OpeningRuud)
	{
		return;
	}

	this->DrawGUI(eDragonLeft, this->Data[eDragonLeft].X, this->Data[eDragonLeft].Y);
}

void Interface::DrawInterfaceDragonRS3()
{	
	if (this->CheckWindow(ObjWindow::FriendList) || this->CheckWindow(ObjWindow::Party) || this->CheckWindow(ObjWindow::Quest) || this->CheckWindow(ObjWindow::Guild)
	||  (this->CheckWindow(CommandWindow) || this->CheckWindow(Inventory) || this->CheckWindow(Character) || this->CheckWindow(FastMenu) || this->CheckWindow(SkillTree)
	|| this->CheckWindow(CashShop) || this->CheckWindow(FullMap) || this->CheckWindow(MuHelper)) || pMapNumber == 39 //Kanturu
		|| pMapNumber == 58 //Selupam
		|| pMapNumber == 64 //Duel Arena
		|| pMapNumber == 65 //Doppelganger
		|| pMapNumber == 66 //Doppelganger
		|| pMapNumber == 67 //Doppelganger
		|| pMapNumber == 68 //Doppelganger
		|| pMapNumber == 69 //Imperial Guardian
		|| pMapNumber == 70 //Imperial Guardian
		|| pMapNumber == 71 //Imperial Guardian
		|| pMapNumber == 72 //Imperial Guardian
		|| pMapNumber == 11	//Blood Castle
		|| pMapNumber == 12	//Blood Castle
		|| pMapNumber == 13	//Blood Castle
		|| pMapNumber == 14	//Blood Castle
		|| pMapNumber == 15	//Blood Castle
		|| pMapNumber == 16	//Blood Castle
		|| pMapNumber == 17	//Blood Castle
		|| pMapNumber == 52	//Blood Castle
		|| pMapNumber == 9	//Devil Square
		|| pMapNumber == 32	//Devil Square
		|| pMapNumber == 18	//Chaos Castle
		|| pMapNumber == 19	//Chaos Castle
		|| pMapNumber == 20	//Chaos Castle
		|| pMapNumber == 21	//Chaos Castle
		|| pMapNumber == 22	//Chaos Castle
		|| pMapNumber == 23	//Chaos Castle
		|| pMapNumber == 53	//Chaos Castle
		|| pMapNumber == 45	//Illusion Temple
		|| pMapNumber == 46	//Illusion Temple
		|| pMapNumber == 47	//Illusion Temple
		|| pMapNumber == 48	//Illusion Temple
		|| pMapNumber == 49	//Illusion Temple
		|| pMapNumber == 50	//Illusion Temple
		|| pMapNumber == 18	//Chaos Castle
		|| pMapNumber == 19	//Chaos Castle
		|| pMapNumber == 20	//Chaos Castle
		|| pMapNumber == 21	//Chaos Castle
		|| pMapNumber == 22	//Chaos Castle
		|| pMapNumber == 23	//Chaos Castle
		|| pMapNumber == 53	//Chaos Castle
		|| pMapNumber == 34 //Crywolf
		|| pMapNumber == 30 //Valley/CastleSiege
		|| pMapNumber == 65 /*DuelArena*/)
	{
		return;
	}
		this->DrawGUI(eDragonRight, this->Data[eDragonRight].X, this->Data[eDragonRight].Y);
}

void Interface::DrawCoord()
{
	gObjUser.Refresh();

	if (*(DWORD*)MAIN_SCREEN_STATE == 5)
	{
		glColor3f(1.0f, 1.0f, 1.0f);
		pDrawInterfaceNumBer(22, 461, gObjUser.lpViewPlayer->MapPosX, 1);
		pDrawInterfaceNumBer(46, 461, gObjUser.lpViewPlayer->MapPosY, 1);

	}
}

void Interface::DrawStatsAddWindow()
{
	if (!this->Data[eSTATSADD_MAIN].OnShow)
	{
		return;
	}

	int ObjectCount = 4;
	if ((gObjUser.lpPlayer->Class & 7) == 4)
	{
		ObjectCount = 5;
	}

	char szCharNames[5][32] =
	{
		"Strength:",
		"Agility:",
		"Vitality:",
		"Energy:",
		"Command:",
	};

	int ObjectIDs[5] =
	{
		eSTATSADD_STATBOX01,
		eSTATSADD_STATBOX02,
		eSTATSADD_STATBOX03,
		eSTATSADD_STATBOX04,
		eSTATSADD_STATBOX05,
	};

	if (this->Data[eSTATSADD_MAIN].ByClose == false)
	{
		if (this->Data[eSTATSADD_MAIN].OpenedValue < 0)
		{
			this->Data[eSTATSADD_MAIN].OpenedValue += this->Data[eSTATSADD_MAIN].Speed;

			if (this->Data[eSTATSADD_MAIN].OpenedValue >= -150)
			{
				this->Data[eSTATSADD_MAIN].Speed = 15;
			}

			if (this->Data[eSTATSADD_MAIN].OpenedValue > 0)
			{
				this->Data[eSTATSADD_MAIN].OpenedValue = 0;
			}
		}
	}
	else
	{
		if (this->Data[eSTATSADD_MAIN].OpenedValue > -226)
		{
			this->Data[eSTATSADD_MAIN].OpenedValue -= this->Data[eSTATSADD_MAIN].Speed;

			if (this->Data[eSTATSADD_MAIN].OpenedValue <= -150)
			{
				this->Data[eSTATSADD_MAIN].Speed = 20;
			}

			if (this->Data[eSTATSADD_MAIN].OpenedValue <= -226)
			{
				//this->Data[eSTATSADD_MAIN].OpenedValue = 100;
				this->Data[eSTATSADD_MAIN].Close();

				this->Data[eSTATSADD_STEP10].Attribute = 0;
				this->Data[eSTATSADD_STEP100].Attribute = 0;
				this->Data[eSTATSADD_STEP1000].Attribute = 0;
				for (int i = 0; i<ObjectCount; i++)
				{
					this->Data[ObjectIDs[i]].Attribute = false;
				}
			}
		}
	}
	pSetCursorFocus = true;
	float MainWidth = 230.0;
	float StartY = 198;
	float StartX = this->Data[eSTATSADD_MAIN].OpenedValue;
	float MainCenter = StartX + (MainWidth / 3);
	float ButtonX = MainCenter - (29.0 / 2);
	// ----
	this->DrawAnimatedGUI(eSTATSADD_MAIN, StartX, StartY + 2);
	this->DrawAnimatedGUI(eSTATSADD_TITLE, StartX, StartY);
	StartY = this->DrawRepeatGUI(eSTATSADD_FRAME, StartX, StartY + 67.0, 8);
	this->DrawAnimatedGUI(eSTATSADD_FOOTER, StartX, StartY);
	this->DrawAnimatedGUI(eSTATSADD_CLOSE, StartX + MainWidth - this->Data[eSTATSADD_CLOSE].Width, this->Data[eSTATSADD_MAIN].Y - 2);
	// ----

	// ----
	if (this->IsWorkZone(eSTATSADD_CLOSE))
	{
		DWORD Color = eGray100;
		// ----
		if (this->Data[eSTATSADD_CLOSE].OnClick)
		{
			Color = eGray150;
		}
		// ----
		this->DrawColoredGUI(eSTATSADD_CLOSE, this->Data[eSTATSADD_CLOSE].X, this->Data[eSTATSADD_CLOSE].Y, Color);
		this->DrawToolTip(this->Data[eSTATSADD_CLOSE].X + 5, this->Data[eSTATSADD_CLOSE].Y + 25, "Close");
	}
	// ----
	DWORD StatPoints = ViewPoint;

	for (int i = 0; i<ObjectCount; i++)
	{
		StatPoints -= atoi(this->Data[ObjectIDs[i]].StatValue);
	}
	// ----
	this->DrawFormat(eGold, StartX + 10, this->Data[eSTATSADD_MAIN].Y + 8, 210, 3, "Add Points");

	this->DrawAnimatedGUI(eSTATSADD_TEXTBOX01, ButtonX - 35, this->Data[eSTATSADD_MAIN].Y + 28);
	this->DrawFormat(eWhite, StartX - 40, this->Data[eSTATSADD_MAIN].Y + 34, 210, 3, "Free Points:");

	char Value[50];
	ZeroMemory(Value, sizeof(Value));
	pGetMoneyFormat((double)StatPoints, Value, 0);
	GetFormat(Value, ',', ' ');

	////console.Log("", "Point %d Value %s",StatPoints,Value);

	this->DrawFormat(eWhite, StartX + 45, this->Data[eSTATSADD_MAIN].Y + 34, 210, 3, "%s", Value);

	this->DrawFormat(eWhite, StartX + 10, this->Data[eSTATSADD_MAIN].Y + 55, 210, 3, "Please set where you want add free points");

	this->DrawFormat(eWhite, StartX + 30, this->Data[eSTATSADD_MAIN].Y + 69, 30, 3, "Step value:");

	this->DrawFormat(eWhite, StartX + 80, this->Data[eSTATSADD_MAIN].Y + 70, 10, 3, "10");
	this->DrawFormat(eWhite, StartX + 120, this->Data[eSTATSADD_MAIN].Y + 70, 15, 3, "100");
	this->DrawFormat(eWhite, StartX + 162, this->Data[eSTATSADD_MAIN].Y + 70, 20, 3, "1000");

	if (this->Data[eSTATSADD_STEP10].Attribute == true)
	{
		this->DrawAnimatedButton(eSTATSADD_STEP10, StartX + 90, this->Data[eSTATSADD_MAIN].Y + 66, 0, 15);
	}
	else
	{
		this->DrawAnimatedButton(eSTATSADD_STEP10, StartX + 90, this->Data[eSTATSADD_MAIN].Y + 66, 0, 0);
	}

	if (this->Data[eSTATSADD_STEP100].Attribute == true)
	{
		this->DrawAnimatedButton(eSTATSADD_STEP100, StartX + 135, this->Data[eSTATSADD_MAIN].Y + 66, 0, 15);
	}
	else
	{
		this->DrawAnimatedButton(eSTATSADD_STEP100, StartX + 135, this->Data[eSTATSADD_MAIN].Y + 66, 0, 0);
	}

	if (this->Data[eSTATSADD_STEP1000].Attribute == true)
	{
		this->DrawAnimatedButton(eSTATSADD_STEP1000, StartX + 180, this->Data[eSTATSADD_MAIN].Y + 66, 0, 15);
	}
	else
	{
		this->DrawAnimatedButton(eSTATSADD_STEP1000, StartX + 180, this->Data[eSTATSADD_MAIN].Y + 66, 0, 0);
	}

	if (this->Data[eSTATSADD_MAIN].FirstLoad == true)
	{
		this->Data[eSTATSADD_STATBOX01].Attribute = 1;
	}

	for (int i = 0; i<ObjectCount; i++)
	{
		if (this->Data[eSTATSADD_MAIN].FirstLoad == true)
		{
			sprintf(this->Data[ObjectIDs[i]].StatValue, "0");
			this->Data[eSTATSADD_STEP100].Attribute = true;
		}
		this->DrawAnimatedGUI(ObjectIDs[i], ButtonX - 35, this->Data[eSTATSADD_MAIN].Y + 63 + ((i + 1) * 21));
		this->DrawFormat(eWhite, StartX - 38, this->Data[eSTATSADD_MAIN].Y + 69 + ((i + 1) * 21), 210, 3, szCharNames[i]);
		this->DrawFormat(eWhite, StartX + 45, this->Data[eSTATSADD_MAIN].Y + 69 + ((i + 1) * 21), 210, 3, this->Data[ObjectIDs[i]].StatValue);
	}

	for (int i = 0; i<ObjectCount; i++)
	{
		if (this->Data[ObjectIDs[i]].Attribute == 1)
		{
			DWORD Color = eGray100;
			this->DrawColoredAnimatedGUI(ObjectIDs[i], ButtonX - 35, this->Data[eSTATSADD_MAIN].Y + 63 + ((i + 1) * 21), Color);
		}
	}

	this->DrawAnimatedButton(eSTATSADD_BTN_OK, StartX + 85, this->Data[eSTATSADD_MAIN].Y + 194, 0, 0);

	if (this->IsWorkZone(eSTATSADD_BTN_OK))
	{
		int ScaleY = 30;
		// ----
		if (this->Data[eSTATSADD_BTN_OK].OnClick)
		{
			ScaleY = 60;
		}
		// ----
		this->DrawAnimatedButton(eSTATSADD_BTN_OK, StartX + 85, this->Data[eSTATSADD_MAIN].Y + 194, 0, ScaleY);
	}

	//login_me
	//newui_button_cancel
	//newui_button_ok
	if (this->Data[eSTATSADD_MAIN].FirstLoad == true)
	{
		this->Data[eSTATSADD_MAIN].FirstLoad = false;
	}
}
// ----------------------------------------------------------------------------------------------

void Interface::EventStatsAddWindow(DWORD Event)
{
	this->EventStatsAddWindow_Close(Event);
}

void Interface::EventStatsAddWindow_Close(DWORD Event)
{
	if (!this->Data[eSTATSADD_MAIN].OnShow)
	{
		return;
	}

	DWORD CurrentTick = GetTickCount();

	int ObjectIDs[8] =
	{
		eSTATSADD_STATBOX01,
		eSTATSADD_STATBOX02,
		eSTATSADD_STATBOX03,
		eSTATSADD_STATBOX04,
		eSTATSADD_STATBOX05,
		eSTATSADD_STEP10,
		eSTATSADD_STEP100,
		eSTATSADD_STEP1000,
	};

	int ObjectCount = 4;
	if ((gObjUser.lpPlayer->Class & 7) == 4)
	{
		ObjectCount = 5;
	}

	for (int i = 0; i<ObjectCount; i++)
	{
		if (IsWorkZone(ObjectIDs[i]))
		{
			DWORD Delay = (CurrentTick - this->Data[ObjectIDs[i]].EventTick);
			// ----
			if (Event == WM_LBUTTONDOWN)
			{
				this->Data[ObjectIDs[i]].OnClick = true;
				return;
			}
			// ----
			this->Data[ObjectIDs[i]].OnClick = false;
			// ----
			if (Delay < 500)
			{
				return;
			}
			this->Data[ObjectIDs[i]].EventTick = GetTickCount();

			for (int j = 0; j<ObjectCount; j++)
			{
				this->Data[ObjectIDs[j]].Attribute = 0;
			}

			this->Data[ObjectIDs[i]].Attribute = 1;
		}
	}

	for (int i = 5; i<8; i++)
	{
		if (IsWorkZone(ObjectIDs[i]))
		{
			DWORD Delay = (CurrentTick - this->Data[ObjectIDs[i]].EventTick);
			// ----
			if (Event == WM_LBUTTONDOWN)
			{
				this->Data[ObjectIDs[i]].OnClick = true;
				return;
			}
			// ----
			this->Data[ObjectIDs[i]].OnClick = false;
			// ----
			if (Delay < 500)
			{
				return;
			}
			this->Data[ObjectIDs[i]].EventTick = GetTickCount();

			for (int j = 5; j<8; j++)
			{
				this->Data[ObjectIDs[j]].Attribute = 0;
			}

			this->Data[ObjectIDs[i]].Attribute = 1;
		}
	}


	if (IsWorkZone(eSTATSADD_BTN_OK))
	{
		DWORD Delay = (CurrentTick - this->Data[eSTATSADD_BTN_OK].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eSTATSADD_BTN_OK].OnClick = true;
			return;
		}
		// ----
		this->Data[eSTATSADD_BTN_OK].OnClick = false;
		// ----
		if (Delay < 500)
		{
			return;
		}
		// ----
		this->Data[eSTATSADD_BTN_OK].EventTick = GetTickCount();
		Data[eSTATSADD_MAIN].CloseAnimated(15);
		PMSG_UPDATE_STATS_SEND pMsg;
		pMsg.Str = atoi(this->Data[eSTATSADD_STATBOX01].StatValue);
		pMsg.Agi = atoi(this->Data[eSTATSADD_STATBOX02].StatValue);
		pMsg.Vit = atoi(this->Data[eSTATSADD_STATBOX03].StatValue);
		pMsg.Ene = atoi(this->Data[eSTATSADD_STATBOX04].StatValue);
		pMsg.Com = 0;
		if (ObjectCount == 5)
		{
			pMsg.Com = atoi(this->Data[eSTATSADD_STATBOX05].StatValue);
		}
		CGSendStatsAdd(pMsg);
	}

	if (IsWorkZone(eSTATSADD_CLOSE))
	{
		DWORD Delay = (CurrentTick - this->Data[eSTATSADD_CLOSE].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eSTATSADD_CLOSE].OnClick = true;
			return;
		}
		// ----
		this->Data[eSTATSADD_CLOSE].OnClick = false;
		// ----
		if (Delay < 500)
		{
			return;
		}
		// ----
		this->Data[eSTATSADD_CLOSE].EventTick = GetTickCount();
		Data[eSTATSADD_MAIN].CloseAnimated(15);
	}

	// ----
	return;
}

// ----------------------------------------------------------------------------------------------

void Interface::DrawChangingClassWindow()
{
	if (!this->Data[eCHANGINGCLASS_MAIN].OnShow)
	{
		return;
	}

	pSetCursorFocus = true;
	// ----
	DWORD ItemNameColor = eWhite;
	float MainWidth = 230.0;
	float MainHeight = 313.0;
	float StartY = 100.0;
	float StartX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
	float MainCenter = StartX + (MainWidth / 3);
	float ButtonX = MainCenter - (29.0 / 2);
	// ----
	this->DrawGUI(eCHANGINGCLASS_MAIN, StartX, StartY + 2);
	this->DrawGUI(eCHANGINGCLASS_TITLE, StartX, StartY);
	StartY = this->DrawRepeatGUI(eCHANGINGCLASS_FRAME, StartX, StartY + 67.0, 13);
	this->DrawGUI(eCHANGINGCLASS_FOOTER, StartX, StartY);
	this->DrawGUI(eCHANGINGCLASS_CLOSE, StartX + MainWidth - this->Data[eCHANGINGCLASS_CLOSE].Width, this->Data[eCHANGINGCLASS_TITLE].Height + this->Data[eCHANGINGCLASS_CLOSE].Height + 2);
	// ----
	if (this->IsWorkZone(eCHANGINGCLASS_CLOSE))
	{
		DWORD Color = eGray100;
		// ----
		if (this->Data[eCHANGINGCLASS_CLOSE].OnClick)
		{
			Color = eGray150;
		}
		// ----
		this->DrawColoredGUI(eCHANGINGCLASS_CLOSE, this->Data[eCHANGINGCLASS_CLOSE].X, this->Data[eCHANGINGCLASS_CLOSE].Y, Color);
		this->DrawToolTip(this->Data[eCHANGINGCLASS_CLOSE].X + 5, this->Data[eCHANGINGCLASS_CLOSE].Y + 25, "Close");
	}
	// ----
	this->DrawFormat(eGold, StartX + 10, 110, 210, 3, "Changing Class System");
	// ----
	if (gChangeClass.m_PriceType == 0)
	{
		this->DrawFormat(eGold, StartX + 30, 355, 210, 1, "Required Zen:");
	}
	else if (gChangeClass.m_PriceType == 1)
	{
		this->DrawFormat(eGold, StartX + 30, 355, 210, 1, "Required %s:", gCustomMessage.GetMessage(6));
	}
	else if (gChangeClass.m_PriceType == 2)
	{
		this->DrawFormat(eGold, StartX + 30, 355, 210, 1, "Required %s:", gCustomMessage.GetMessage(7));
	}
	else if (gChangeClass.m_PriceType == 3)
	{
		this->DrawFormat(eGold, StartX + 30, 355, 210, 1, "Required %s:", gCustomMessage.GetMessage(13));
	}
	else if (gChangeClass.m_PriceType == 4)
	{
		this->DrawFormat(eGold, StartX + 30, 355, 210, 1, "Required %s:", gCustomMessage.GetMessage(14));
	}
	//this->DrawFormat(eGold, StartX + 30, 355, 210, 1, "Required Credits:");
	this->DrawGUI(eCHANGINGCLASS_MONEYBG, StartX + 30, 365);
	// ----
	char MoneyBuff[50], MoneyBuff2[50];
	ZeroMemory(MoneyBuff, sizeof(MoneyBuff));
	ZeroMemory(MoneyBuff2, sizeof(MoneyBuff2));
	// ----
	//if( gObjUser.m_CreditsCount
	//	< gChangeClass.m_Price )
	//{
	//	pGetMoneyFormat((double)gChangeClass.m_Price, 
	//		MoneyBuff, 0);
	//	pGetMoneyFormat((double)gChangeClass.m_Price - gObjUser.m_CreditsCount, 
	//		MoneyBuff2, 0);
	//	this->DrawFormat(eRed, StartX + 70, 369, 170, 1, "%s\n(Need still %s)", 
	//		MoneyBuff, MoneyBuff2);
	//}
	//else
	//{
	pGetMoneyFormat((double)gChangeClass.m_Price,
		MoneyBuff, 0);
	this->DrawFormat(eGold, StartX + 70, 372, 70, 1, "%s",
		MoneyBuff);
	//}
	// ----
	/*this->DrawFormat(eRed, StartX + 10, 330, 210, 3, "Warning!", MoneyBuff, MoneyBuff2);
	this->DrawFormat(eBlue, StartX + 10, 338, 210, 3, "Before make changing class need remove all items from inventory", MoneyBuff, MoneyBuff2);*/
	// ----
	this->DrawGUI(eCHANGINGCLASS_DW, ButtonX - 57, this->Data[eCHANGINGCLASS_MAIN].Y + 30);
	//this->DrawFormat(eWhite, StartX - 45, this->Data[eCHANGINGCLASS_MAIN].Y + 40, 210, 3, "Dark Wizard class");
	this->DrawFormat(eWhite, StartX - 45, this->Data[eCHANGINGCLASS_MAIN].Y + 40, 210, 3, "%s class", pGetTextLine(pTextLineThis, 20));
	//pGetTextLine
	// ----
	this->DrawGUI(eCHANGINGCLASS_DK, ButtonX + 52, this->Data[eCHANGINGCLASS_MAIN].Y + 30);
	this->DrawFormat(eWhite, StartX + 62, this->Data[eCHANGINGCLASS_MAIN].Y + 40, 210, 3, "%s class", pGetTextLine(pTextLineThis, 21));
	// ----
	this->DrawGUI(eCHANGINGCLASS_ELF, ButtonX - 57, this->Data[eCHANGINGCLASS_MAIN].Y + 60);
	this->DrawFormat(eWhite, StartX - 45, this->Data[eCHANGINGCLASS_MAIN].Y + 70, 210, 3, "%s class", pGetTextLine(pTextLineThis, 22));
	// ----
	this->DrawGUI(eCHANGINGCLASS_MG, ButtonX + 52, this->Data[eCHANGINGCLASS_MAIN].Y + 60);
	this->DrawFormat(eWhite, StartX + 62, this->Data[eCHANGINGCLASS_MAIN].Y + 70, 210, 3, "%s class", pGetTextLine(pTextLineThis, 23));
	// ----
	this->DrawGUI(eCHANGINGCLASS_DL, ButtonX - 57, this->Data[eCHANGINGCLASS_MAIN].Y + 90);
	this->DrawFormat(eWhite, StartX - 45, this->Data[eCHANGINGCLASS_MAIN].Y + 100, 210, 3, "%s class", pGetTextLine(pTextLineThis, 24));
	// ----
	if (gProtect.m_MainInfo.CharsCount >= 6)
	{
		this->DrawGUI(eCHANGINGCLASS_SUM, ButtonX + 52, this->Data[eCHANGINGCLASS_MAIN].Y + 90);
		this->DrawFormat(eWhite, StartX + 62, this->Data[eCHANGINGCLASS_MAIN].Y + 100, 210, 3, "%s class", pGetTextLine(pTextLineThis, 1687));
	}
	// ----
	if (gProtect.m_MainInfo.CharsCount >= 7)
	{
		this->DrawGUI(eCHANGINGCLASS_RF, ButtonX, this->Data[eCHANGINGCLASS_MAIN].Y + 120);
		this->DrawFormat(eWhite, StartX + 8, this->Data[eCHANGINGCLASS_MAIN].Y + 130, 210, 3, "%s class", pGetTextLine(pTextLineThis, 3150));
	}
	// ----
	this->DrawGUI(eCHANGINGCLASS_DIV, StartX, this->Data[eCHANGINGCLASS_MAIN].Y + 212);
	// ----
	this->Data[eCHANGINGCLASS_DW].Attribute = true;
	this->Data[eCHANGINGCLASS_DK].Attribute = true;
	this->Data[eCHANGINGCLASS_ELF].Attribute = true;
	this->Data[eCHANGINGCLASS_MG].Attribute = true;
	this->Data[eCHANGINGCLASS_DL].Attribute = true;
	this->Data[eCHANGINGCLASS_SUM].Attribute = true;
	this->Data[eCHANGINGCLASS_RF].Attribute = true;
	// ----
	if (IsWorkZone(eCHANGINGCLASS_DW))
	{
		DWORD Color = eGray100;
		// ----
		if (this->Data[eCHANGINGCLASS_DW].OnClick)
		{
			Color = eGray150;
		}
		// ----
		this->DrawColoredGUI(eCHANGINGCLASS_DW, this->Data[eCHANGINGCLASS_DW].X, this->Data[eCHANGINGCLASS_DW].Y, Color);
	}
	if (IsWorkZone(eCHANGINGCLASS_DK))
	{
		DWORD Color = eGray100;
		// ----
		if (this->Data[eCHANGINGCLASS_DK].OnClick)
		{
			Color = eGray150;
		}
		// ----
		this->DrawColoredGUI(eCHANGINGCLASS_DK, this->Data[eCHANGINGCLASS_DK].X, this->Data[eCHANGINGCLASS_DK].Y, Color);
	}
	if (IsWorkZone(eCHANGINGCLASS_ELF))
	{
		DWORD Color = eGray100;
		// ----
		if (this->Data[eCHANGINGCLASS_ELF].OnClick)
		{
			Color = eGray150;
		}
		// ----
		this->DrawColoredGUI(eCHANGINGCLASS_ELF, this->Data[eCHANGINGCLASS_ELF].X, this->Data[eCHANGINGCLASS_ELF].Y, Color);
	}
	if (IsWorkZone(eCHANGINGCLASS_MG))
	{
		DWORD Color = eGray100;
		// ----
		if (this->Data[eCHANGINGCLASS_MG].OnClick)
		{
			Color = eGray150;
		}
		// ----
		this->DrawColoredGUI(eCHANGINGCLASS_MG, this->Data[eCHANGINGCLASS_MG].X, this->Data[eCHANGINGCLASS_MG].Y, Color);
	}
	if (IsWorkZone(eCHANGINGCLASS_DL))
	{
		DWORD Color = eGray100;
		// ----
		if (this->Data[eCHANGINGCLASS_DL].OnClick)
		{
			Color = eGray150;
		}
		// ----
		this->DrawColoredGUI(eCHANGINGCLASS_DL, this->Data[eCHANGINGCLASS_DL].X, this->Data[eCHANGINGCLASS_DL].Y, Color);
	}
	if (IsWorkZone(eCHANGINGCLASS_SUM))
	{
		if (gProtect.m_MainInfo.CharsCount >= 6)
		{
			DWORD Color = eGray100;
			// ----
			if (this->Data[eCHANGINGCLASS_SUM].OnClick)
			{
				Color = eGray150;
			}
			// ----
			this->DrawColoredGUI(eCHANGINGCLASS_SUM, this->Data[eCHANGINGCLASS_SUM].X, this->Data[eCHANGINGCLASS_SUM].Y, Color);
		}
	}
	if (IsWorkZone(eCHANGINGCLASS_RF))
	{
		if (gProtect.m_MainInfo.CharsCount >= 7)
		{
			DWORD Color = eGray100;
			// ----
			if (this->Data[eCHANGINGCLASS_RF].OnClick)
			{
				Color = eGray150;
			}
			// ----
			this->DrawColoredGUI(eCHANGINGCLASS_RF, this->Data[eCHANGINGCLASS_RF].X, this->Data[eCHANGINGCLASS_RF].Y, Color);
		}
	}

}
// ----------------------------------------------------------------------------------------------

bool Interface::EventChangingClassWindow_Main(DWORD Event)
{
	this->EventChangingClassWindow_Close(Event);
	this->EventChangingClassWindow_DW(Event);
	this->EventChangingClassWindow_DK(Event);
	this->EventChangingClassWindow_ELF(Event);
	this->EventChangingClassWindow_MG(Event);
	this->EventChangingClassWindow_DL(Event);
	this->EventChangingClassWindow_SUM(Event);
	this->EventChangingClassWindow_RF(Event);
	return true;
}
// ----------------------------------------------------------------------------------------------

bool Interface::EventChangingClassWindow_Close(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eCHANGINGCLASS_CLOSE].EventTick);
	// ----
	if (!this->Data[eCHANGINGCLASS_MAIN].OnShow || !IsWorkZone(eCHANGINGCLASS_CLOSE))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eCHANGINGCLASS_CLOSE].OnClick = true;
		return true;
	}
	// ----
	this->Data[eCHANGINGCLASS_CLOSE].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eCHANGINGCLASS_CLOSE].EventTick = GetTickCount();
	this->Data[eCHANGINGCLASS_MAIN].Close();
	// ----
	return false;
}
// ----------------------------------------------------------------------------------------------

bool Interface::EventChangingClassWindow_DW(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eCHANGINGCLASS_DW].EventTick);

	//DWORD DelayUserPanel = (GetTickCount() - this->Data[eUSERSPANEL_CHANGINGCLASS].EventTick);
	//if (DelayUserPanel < 500)
	//{
	//	/////console.Log("", "return");
	//	return false;
	//}
	// ----
	if (!this->Data[eCHANGINGCLASS_MAIN].OnShow || !IsWorkZone(eCHANGINGCLASS_DW)
		|| !this->Data[eCHANGINGCLASS_DW].Attribute)
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eCHANGINGCLASS_DW].OnClick = true;
		return true;
	}
	// ----
	this->Data[eCHANGINGCLASS_DW].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eCHANGINGCLASS_DW].EventTick = GetTickCount();
	//gChangingClassSystem.ReqResetFinishDW();
	gChangeClass.SendChangeClass(0);
	// ----
	return false;
}
bool Interface::EventChangingClassWindow_DK(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eCHANGINGCLASS_DK].EventTick);

	//DWORD DelayUserPanel = (GetTickCount() - this->Data[eUSERSPANEL_CHANGINGCLASS].EventTick);
	//if (DelayUserPanel < 500)
	//{
	//	////console.Log("", "return");
	//	return false;
	//}
	// ----
	if (!this->Data[eCHANGINGCLASS_MAIN].OnShow || !IsWorkZone(eCHANGINGCLASS_DK)
		|| !this->Data[eCHANGINGCLASS_DK].Attribute)
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eCHANGINGCLASS_DK].OnClick = true;
		return true;
	}
	// ----
	this->Data[eCHANGINGCLASS_DK].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eCHANGINGCLASS_DK].EventTick = GetTickCount();
	//gChangingClassSystem.ReqResetFinishDK();
	gChangeClass.SendChangeClass(16);
	// ----
	return false;
}
bool Interface::EventChangingClassWindow_ELF(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eCHANGINGCLASS_ELF].EventTick);

	//DWORD DelayUserPanel = (GetTickCount() - this->Data[eUSERSPANEL_CHANGINGCLASS].EventTick);
	//if (DelayUserPanel < 500)
	//{
	//	////console.Log("", "return");
	//	return false;
	//}
	// ----
	if (!this->Data[eCHANGINGCLASS_MAIN].OnShow || !IsWorkZone(eCHANGINGCLASS_ELF)
		|| !this->Data[eCHANGINGCLASS_ELF].Attribute)
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eCHANGINGCLASS_ELF].OnClick = true;
		return true;
	}
	// ----
	this->Data[eCHANGINGCLASS_ELF].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eCHANGINGCLASS_ELF].EventTick = GetTickCount();
	//gChangingClassSystem.ReqResetFinishELF();
	gChangeClass.SendChangeClass(32);
	// ----
	return false;
}
bool Interface::EventChangingClassWindow_MG(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eCHANGINGCLASS_MG].EventTick);
	// ----
	if (!this->Data[eCHANGINGCLASS_MAIN].OnShow || !IsWorkZone(eCHANGINGCLASS_MG)
		|| !this->Data[eCHANGINGCLASS_MG].Attribute)
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eCHANGINGCLASS_MG].OnClick = true;
		return true;
	}
	// ----
	this->Data[eCHANGINGCLASS_MG].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eCHANGINGCLASS_MG].EventTick = GetTickCount();
	//gChangingClassSystem.ReqResetFinishMG();
	gChangeClass.SendChangeClass(48);
	// ----
	return false;
}
bool Interface::EventChangingClassWindow_DL(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eCHANGINGCLASS_DL].EventTick);
	// ----
	if (!this->Data[eCHANGINGCLASS_MAIN].OnShow || !IsWorkZone(eCHANGINGCLASS_DL)
		|| !this->Data[eCHANGINGCLASS_DL].Attribute)
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eCHANGINGCLASS_DL].OnClick = true;
		return true;
	}
	// ----
	this->Data[eCHANGINGCLASS_DL].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eCHANGINGCLASS_DL].EventTick = GetTickCount();
	//gChangingClassSystem.ReqResetFinishDL();
	gChangeClass.SendChangeClass(64);
	// ----
	return false;
}
bool Interface::EventChangingClassWindow_SUM(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eCHANGINGCLASS_SUM].EventTick);
	// ----
	if (gProtect.m_MainInfo.CharsCount<6)
	{
		return false;
	}
	// ----
	if (!this->Data[eCHANGINGCLASS_MAIN].OnShow || !IsWorkZone(eCHANGINGCLASS_SUM)
		|| !this->Data[eCHANGINGCLASS_SUM].Attribute)
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eCHANGINGCLASS_SUM].OnClick = true;
		return true;
	}
	// ----
	this->Data[eCHANGINGCLASS_SUM].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eCHANGINGCLASS_SUM].EventTick = GetTickCount();
	//gChangingClassSystem.ReqResetFinishSUM();
	gChangeClass.SendChangeClass(80);
	// ----
	return false;
}
bool Interface::EventChangingClassWindow_RF(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eCHANGINGCLASS_RF].EventTick);
	// ----
	if (gProtect.m_MainInfo.CharsCount<7)
	{
		return false;
	}
	// ----
	if (!this->Data[eCHANGINGCLASS_MAIN].OnShow || !IsWorkZone(eCHANGINGCLASS_RF)
		|| !this->Data[eCHANGINGCLASS_RF].Attribute)
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eCHANGINGCLASS_RF].OnClick = true;
		return true;
	}
	// ----
	this->Data[eCHANGINGCLASS_RF].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eCHANGINGCLASS_RF].EventTick = GetTickCount();
	//gChangingClassSystem.ReqResetFinishRF();
	gChangeClass.SendChangeClass(96);
	// ----
	return false;
}

void Interface::SwitchPartySettingsWindowState()
{
	if (gPartySearch.CanOpenSettings[ViewAccountLevel] == false)
	{
		return;
	}

	Data[ePARTYSETTINGS_MAIN].OnShow == true ? Data[ePARTYSETTINGS_MAIN].Close() : Data[ePARTYSETTINGS_MAIN].Open();
}

void Interface::DrawPartySettingsWindow()
{
	if (!this->Data[ePARTYSETTINGS_MAIN].OnShow)
	{
		return;
	}

	pSetCursorFocus = true;
	// ----
	float MainWidth = 230.0;
	float MainHeight = 313.0;
	float StartY = 50.0;
	float StartX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
	float MainCenter = StartX + (MainWidth / 3);
	float ButtonX = MainCenter - (29.0 / 2);
	// ----
	this->DrawGUI(ePARTYSETTINGS_MAIN, StartX, StartY + 2);
	this->DrawGUI(ePARTYSETTINGS_TITLE, StartX, StartY);
	StartY = this->DrawRepeatGUI(ePARTYSETTINGS_FRAME, StartX, StartY + 67.0, 16);
	this->DrawGUI(ePARTYSETTINGS_FOOTER, StartX, StartY);
	this->DrawGUI(ePARTYSETTINGS_CLOSE, StartX + MainWidth - this->Data[ePARTYSETTINGS_CLOSE].Width + 2, 49);
	// ----
	if (this->IsWorkZone(ePARTYSETTINGS_CLOSE))
	{
		DWORD Color = eGray100;
		// ----
		if (this->Data[ePARTYSETTINGS_CLOSE].OnClick)
		{
			Color = eGray150;
		}
		// ----
		this->DrawColoredGUI(ePARTYSETTINGS_CLOSE, this->Data[ePARTYSETTINGS_CLOSE].X, this->Data[ePARTYSETTINGS_CLOSE].Y, Color);
		this->DrawToolTip(this->Data[ePARTYSETTINGS_CLOSE].X + 5, this->Data[ePARTYSETTINGS_CLOSE].Y + 25, "Close");
	}
	// ----
	this->DrawFormat(eGold, StartX + 10, 60, 210, 3, "Party Search Settings");
	///////////////////////////////////////////ACTIVE SYSTEM///////////////////////////////////////////
	this->DrawFormat(eWhite, StartX + 40, this->Data[ePARTYSETTINGS_MAIN].Y + 33, 200, 1, "Active System");

	if (gPartySearchSettings.m_SystemActive == false)
	{
		this->DrawButton(ePARTYSETTINGS_SYSTEM_ACTIVE, ButtonX + 110, this->Data[ePARTYSETTINGS_MAIN].Y + 30, 0, 0);
	}
	else
	{
		this->DrawButton(ePARTYSETTINGS_SYSTEM_ACTIVE, ButtonX + 110, this->Data[ePARTYSETTINGS_MAIN].Y + 30, 0, 15);
	}
	this->DrawGUI(ePARTYSETTINGS_DIV, StartX, this->Data[ePARTYSETTINGS_MAIN].Y + 40); // Äåëèòåëü áîëüøîé
	/////////////////////////////////////////ACTIVE SYSTEM END/////////////////////////////////////////

	/////////////////////////////////////////////MAX LEVEL/////////////////////////////////////////////
	this->DrawFormat(eWhite, StartX + 40, this->Data[ePARTYSETTINGS_MAIN].Y + 60, 200, 1, "Max Level");
	this->DrawGUI(ePARTYSETTINGS_DIV, StartX, this->Data[ePARTYSETTINGS_MAIN].Y + 67); // Äåëèòåëü áîëüøîé

	/*int x = GetPrivateProfileIntA("Graphics", "X", 0, "./Settings.ini");
	int y = GetPrivateProfileIntA("Graphics", "Y", 0, "./Settings.ini");
	int w = GetPrivateProfileIntA("Graphics", "W", 0, "./Settings.ini");
	int h = GetPrivateProfileIntA("Graphics", "H", 0, "./Settings.ini");*/
	this->DrawToolTip(StartX + 174, this->Data[ePARTYSETTINGS_MAIN].Y + 62, "%d", gPartySearchSettings.m_Level);

	if (gPartySearchSettings.m_SystemActive == 0)
	{
		this->DrawColoredButton(ePARTYSETTINGS_LEVEL_MINUS, StartX + 150, this->Data[ePARTYSETTINGS_MAIN].Y + 57, 0, 0, eGray150); // 
	}
	else
	{
		this->DrawButton(ePARTYSETTINGS_LEVEL_MINUS, StartX + 150, this->Data[ePARTYSETTINGS_MAIN].Y + 57, 0, 0); // 

		if (this->IsWorkZone(ePARTYSETTINGS_LEVEL_MINUS))
		{
			if (this->Data[ePARTYSETTINGS_LEVEL_MINUS].OnClick)
			{
				this->DrawButton(ePARTYSETTINGS_LEVEL_MINUS, StartX + 150, this->Data[ePARTYSETTINGS_MAIN].Y + 57, 0, 16);
			}
		}
	}

	if (gPartySearchSettings.m_SystemActive == 0)
	{
		this->DrawColoredButton(ePARTYSETTINGS_LEVEL_PLUS, StartX + 193, this->Data[ePARTYSETTINGS_MAIN].Y + 57, 0, 0, eGray150); //
	}
	else
	{
		this->DrawButton(ePARTYSETTINGS_LEVEL_PLUS, StartX + 193, this->Data[ePARTYSETTINGS_MAIN].Y + 57, 0, 0); //

		if (this->IsWorkZone(ePARTYSETTINGS_LEVEL_PLUS))
		{
			if (this->Data[ePARTYSETTINGS_LEVEL_PLUS].OnClick)
			{
				this->DrawButton(ePARTYSETTINGS_LEVEL_PLUS, StartX + 193, this->Data[ePARTYSETTINGS_MAIN].Y + 57, 0, 16);
			}
		}
	}

	///////////////////////////////////////////MAX LEVEL END///////////////////////////////////////////

	///////////////////////////////////////////////GUILD///////////////////////////////////////////////

	this->DrawFormat(eWhite, StartX + 40, this->Data[ePARTYSETTINGS_MAIN].Y + 87, 200, 1, "Only Guild");

	if (gPartySearchSettings.m_SystemActive)
	{
		if (gPartySearchSettings.m_OnlyGuild == false)
		{
			this->DrawButton(ePARTYSETTINGS_ONLY_GUILD, ButtonX + 110, this->Data[ePARTYSETTINGS_MAIN].Y + 83, 0, 0);
		}
		else
		{
			this->DrawButton(ePARTYSETTINGS_ONLY_GUILD, ButtonX + 110, this->Data[ePARTYSETTINGS_MAIN].Y + 83, 0, 15);
		}
	}
	else
	{
		this->DrawButton(ePARTYSETTINGS_ONLY_GUILD, ButtonX + 110, this->Data[ePARTYSETTINGS_MAIN].Y + 83, 0, 30);
	}

	pDrawGUI(0x7B5E, StartX + 30, this->Data[ePARTYSETTINGS_MAIN].Y + 100, 82.0, 2.0); // Äåëèòåëü ìåëêèé 1
	pDrawGUI(0x7B5E, StartX + 30 + 82, this->Data[ePARTYSETTINGS_MAIN].Y + 100, 82.0, 2.0); // Äåëèòåëü ìåëêèé 2

	this->DrawFormat(eWhite, StartX + 40, this->Data[ePARTYSETTINGS_MAIN].Y + 109, 200, 1, "Only One Class");

	if (gPartySearchSettings.m_SystemActive)
	{
		if (gPartySearchSettings.m_OneClass == false)
		{
			this->DrawButton(ePARTYSETTINGS_ONE_CLASS, ButtonX + 110, this->Data[ePARTYSETTINGS_MAIN].Y + 105, 0, 0);
		}
		else
		{
			this->DrawButton(ePARTYSETTINGS_ONE_CLASS, ButtonX + 110, this->Data[ePARTYSETTINGS_MAIN].Y + 105, 0, 15);
		}
	}
	else
	{
		this->DrawButton(ePARTYSETTINGS_ONE_CLASS, ButtonX + 110, this->Data[ePARTYSETTINGS_MAIN].Y + 105, 0, 30);
	}

	this->DrawGUI(ePARTYSETTINGS_DIV, StartX, this->Data[ePARTYSETTINGS_MAIN].Y + 115);// 94 // Äåëèòåëü áîëüøîé
	/////////////////////////////////////////////GUILD END/////////////////////////////////////////////
	char szCharNames[7][32] =
	{
		"Dark Wizard",
		"Dard Knight",
		"Elf",
		"Magic Gladiator",
		"Dark Lord",
		"Summoner",
		"Rage Fighter"
	};

	int ObjectIDs[7] =
	{
		ePARTYSETTINGS_DARK_WIZARD,
		ePARTYSETTINGS_DARK_KNIGHT,
		ePARTYSETTINGS_ELF,
		ePARTYSETTINGS_MAGIC_GLADIATOR,
		ePARTYSETTINGS_DARK_LORD,
		ePARTYSETTINGS_SUMMONER,
		ePARTYSETTINGS_RAGE_FIGHTER
	};

	for (int i = 0; i<gProtect.m_MainInfo.CharsCount; i++)
	{
		this->DrawFormat(eWhite, StartX + 40, this->Data[ePARTYSETTINGS_MAIN].Y + 135 + (i * 22), 200, 1, szCharNames[i]);

		bool ClassValue = 0;
		switch (i)
		{
		case 0:
			ClassValue = gPartySearchSettings.m_DarkWizard;
			break;
		case 1:
			ClassValue = gPartySearchSettings.m_DarkKnight;
			break;
		case 2:
			ClassValue = gPartySearchSettings.m_Elf;
			break;
		case 3:
			ClassValue = gPartySearchSettings.m_MagicGladiator;
			break;
		case 4:
			ClassValue = gPartySearchSettings.m_DarkLord;
			break;
		case 5:
			ClassValue = gPartySearchSettings.m_Summoner;
			break;
		case 6:
			ClassValue = gPartySearchSettings.m_RageFighter;
			break;
		}

		if (gPartySearchSettings.m_SystemActive)
		{
			if (ClassValue == false)
			{
				this->DrawButton(ObjectIDs[i], ButtonX + 110, this->Data[ePARTYSETTINGS_MAIN].Y + 131 + (i * 22), 0, 0);
			}
			else
			{
				this->DrawButton(ObjectIDs[i], ButtonX + 110, this->Data[ePARTYSETTINGS_MAIN].Y + 131 + (i * 22), 0, 15);
			}
		}
		else
		{
			this->DrawButton(ObjectIDs[i], ButtonX + 110, this->Data[ePARTYSETTINGS_MAIN].Y + 131 + (i * 22), 0, 30);
		}

		pDrawGUI(0x7B5E, StartX + 30, this->Data[ePARTYSETTINGS_MAIN].Y + 148 + (i * 22), 82.0, 2.0); // Äåëèòåëü ìåëêèé 1
		pDrawGUI(0x7B5E, StartX + 30 + 82, this->Data[ePARTYSETTINGS_MAIN].Y + 148 + (i * 22), 82.0, 2.0); // Äåëèòåëü ìåëêèé 2
	}

	/*int x = GetPrivateProfileIntA("Graphics", "X", 0, "./Settings.ini");
	int y = GetPrivateProfileIntA("Graphics", "Y", 0, "./Settings.ini");
	int w = GetPrivateProfileIntA("Graphics", "W", 0, "./Settings.ini");
	int h = GetPrivateProfileIntA("Graphics", "H", 0, "./Settings.ini");*/

	this->DrawGUI(ePARTYSETTINGS_DIV, StartX, this->Data[ePARTYSETTINGS_MAIN].Y + 290); // Äåëèòåëü áîëüøîé

	//if (gPartySearchSettings.m_SystemActive)
	//{
	this->DrawButton(ePARTYSETTINGS_OK, StartX + this->Data[ePARTYSETTINGS_MAIN].Width / 2 - this->Data[ePARTYSETTINGS_OK].Width / 2, this->Data[ePARTYSETTINGS_MAIN].Y + 310, 0, 0);

	if (this->IsWorkZone(ePARTYSETTINGS_OK))
	{
		int ScaleY = 30;
		// ----
		if (this->Data[ePARTYSETTINGS_OK].OnClick)
		{
			ScaleY = 60;
		}
		// ----
		this->DrawButton(ePARTYSETTINGS_OK, StartX + this->Data[ePARTYSETTINGS_MAIN].Width / 2 - this->Data[ePARTYSETTINGS_OK].Width / 2, this->Data[ePARTYSETTINGS_MAIN].Y + 310, 0, ScaleY);
	}
	//}

}
// ----------------------------------------------------------------------------------------------

bool Interface::EventPartySettingsWindow_Main(DWORD Event)
{
	this->EventPartySettingsWindow_Close(Event);
	this->EventPartySettingsWindow_All(Event);
	// ----
	// ----
	return true;
}
// ----------------------------------------------------------------------------------------------

bool Interface::EventPartySettingsWindow_All(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	//DWORD Delay			= (CurrentTick - this->Data[eDIABLO_CLOSE].EventTick);
	if (!this->Data[ePARTYSETTINGS_MAIN].OnShow)
	{
		return false;
	}

	if (IsWorkZone(ePARTYSETTINGS_SYSTEM_ACTIVE))
	{
		DWORD Delay = (CurrentTick - this->Data[ePARTYSETTINGS_SYSTEM_ACTIVE].EventTick);

		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[ePARTYSETTINGS_SYSTEM_ACTIVE].OnClick = true;
			return true;
		}
		// ----
		this->Data[ePARTYSETTINGS_SYSTEM_ACTIVE].OnClick = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		// ----
		this->Data[ePARTYSETTINGS_SYSTEM_ACTIVE].EventTick = GetTickCount();
		gPartySearchSettings.m_SystemActive ^= 1;

		for (int i = 0; i<gProtect.m_MainInfo.CharsCount; i++)
		{
			gPartySearchSettings.m_SystemActive == true ? gPartySearchSettings.SetClassValue(i, true) : gPartySearchSettings.SetClassValue(i, false);
			//gPartySearchSettings.ChangeClassValue(i);
		}
	}

	if (IsWorkZone(ePARTYSETTINGS_LEVEL_MINUS))
	{
		if (gPartySearchSettings.m_SystemActive == 0)
		{
			return false;
		}

		DWORD Delay = (CurrentTick - this->Data[ePARTYSETTINGS_LEVEL_MINUS].EventTick);

		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[ePARTYSETTINGS_LEVEL_MINUS].OnClick = true;
			return false;
		}
		// ----
		this->Data[ePARTYSETTINGS_LEVEL_MINUS].OnClick = false;
		// ----
		if (Delay < 200)
		{
			return false;
		}
		// ----
		this->Data[ePARTYSETTINGS_LEVEL_MINUS].EventTick = GetTickCount();

		gPartySearchSettings.m_Level -= 10;
		if (gPartySearchSettings.m_Level <= 0)
		{
			gPartySearchSettings.m_Level = 0;
		}
	}

	if (IsWorkZone(ePARTYSETTINGS_LEVEL_PLUS))
	{
		if (gPartySearchSettings.m_SystemActive == 0)
		{
			return false;
		}

		DWORD Delay = (CurrentTick - this->Data[ePARTYSETTINGS_LEVEL_PLUS].EventTick);

		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[ePARTYSETTINGS_LEVEL_PLUS].OnClick = true;
			return false;
		}
		// ----
		this->Data[ePARTYSETTINGS_LEVEL_PLUS].OnClick = false;
		// ----
		if (Delay < 200)
		{
			return false;
		}
		// ----
		this->Data[ePARTYSETTINGS_LEVEL_PLUS].EventTick = GetTickCount();

		gPartySearchSettings.m_Level += 10;
		if (gPartySearchSettings.m_Level >= 400)
		{
			gPartySearchSettings.m_Level = 400;
		}
	}

	if (IsWorkZone(ePARTYSETTINGS_ONLY_GUILD))
	{
		DWORD Delay = (CurrentTick - this->Data[ePARTYSETTINGS_ONLY_GUILD].EventTick);

		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[ePARTYSETTINGS_ONLY_GUILD].OnClick = true;
			return true;
		}
		// ----
		this->Data[ePARTYSETTINGS_ONLY_GUILD].OnClick = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		// ----
		this->Data[ePARTYSETTINGS_ONLY_GUILD].EventTick = GetTickCount();
		gPartySearchSettings.m_OnlyGuild ^= 1;
	}

	if (IsWorkZone(ePARTYSETTINGS_ONE_CLASS))
	{
		DWORD Delay = (CurrentTick - this->Data[ePARTYSETTINGS_ONE_CLASS].EventTick);

		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[ePARTYSETTINGS_ONE_CLASS].OnClick = true;
			return true;
		}
		// ----
		this->Data[ePARTYSETTINGS_ONE_CLASS].OnClick = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		// ----
		this->Data[ePARTYSETTINGS_ONE_CLASS].EventTick = GetTickCount();
		gPartySearchSettings.m_OneClass ^= 1;

		for (int i = 0; i<gProtect.m_MainInfo.CharsCount; i++)
		{
			gPartySearchSettings.m_OneClass == false ? gPartySearchSettings.SetClassValue(i, true) : gPartySearchSettings.SetClassValue(i, false);
			//gPartySearchSettings.ChangeClassValue(i);
		}
	}

	if (IsWorkZone(ePARTYSETTINGS_OK))
	{
		/*if (gPartySearchSettings.m_SystemActive == 0)
		{
		return false;
		}*/

		DWORD Delay = (CurrentTick - this->Data[ePARTYSETTINGS_OK].EventTick);

		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[ePARTYSETTINGS_OK].OnClick = true;
			return false;
		}
		// ----
		this->Data[ePARTYSETTINGS_OK].OnClick = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		// ----
		this->Data[ePARTYSETTINGS_OK].EventTick = GetTickCount();
		gPartySearchSettings.CGSendPartySearchAdd();
		this->SwitchPartySettingsWindowState();
	}

	int ObjectIDs[7] =
	{
		ePARTYSETTINGS_DARK_WIZARD,
		ePARTYSETTINGS_DARK_KNIGHT,
		ePARTYSETTINGS_ELF,
		ePARTYSETTINGS_MAGIC_GLADIATOR,
		ePARTYSETTINGS_DARK_LORD,
		ePARTYSETTINGS_SUMMONER,
		ePARTYSETTINGS_RAGE_FIGHTER
	};

	for (int i = 0; i<gProtect.m_MainInfo.CharsCount; i++)
	{
		if (IsWorkZone(ObjectIDs[i]))
		{
			DWORD Delay = (CurrentTick - this->Data[ObjectIDs[i]].EventTick);

			if (Event == WM_LBUTTONDOWN)
			{
				this->Data[ObjectIDs[i]].OnClick = true;
				return true;
			}
			// ----
			this->Data[ObjectIDs[i]].OnClick = false;
			// ----
			if (Delay < 500)
			{
				return false;
			}
			// ----
			this->Data[ObjectIDs[i]].EventTick = GetTickCount();
			gPartySearchSettings.ChangeClassValue(i);

			if (gPartySearchSettings.m_OneClass == true)
			{
				gPartySearchSettings.m_OneClass = false;
			}
		}
	}
	return false;
}

bool Interface::EventPartySettingsWindow_Close(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[ePARTYSETTINGS_CLOSE].EventTick);
	// ----
	if (!this->Data[ePARTYSETTINGS_MAIN].OnShow || !IsWorkZone(ePARTYSETTINGS_CLOSE))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[ePARTYSETTINGS_CLOSE].OnClick = true;
		return true;
	}
	// ----
	this->Data[ePARTYSETTINGS_CLOSE].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[ePARTYSETTINGS_CLOSE].EventTick = GetTickCount();
	this->Data[ePARTYSETTINGS_MAIN].Close();
	// ----
	return false;
}
// ----------------------------------------------------------------------------------------------
void Interface::DrawPartySearchWindow()
{
	if (!this->Data[ePARTYSEARCH_MAIN].OnShow)
	{
		return;
	}

	pSetCursorFocus = true;
	// ----
	float MainWidth = 230.0;
	float MainHeight = 313.0;
	float StartY = 50.0;
	float StartX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
	float MainCenter = StartX + (MainWidth / 3);
	float ButtonX = MainCenter - (29.0 / 2);
	// ----
	this->DrawGUI(ePARTYSEARCH_MAIN, StartX, StartY + 2);
	this->DrawGUI(ePARTYSEARCH_TITLE, StartX, StartY);
	StartY = this->DrawRepeatGUI(ePARTYSEARCH_FRAME, StartX, StartY + 67.0, 16);
	this->DrawGUI(ePARTYSEARCH_FOOTER, StartX, StartY);
	this->DrawGUI(ePARTYSEARCH_CLOSE, StartX + MainWidth - this->Data[ePARTYSEARCH_CLOSE].Width + 2, 49);
	// ----
	if (this->IsWorkZone(ePARTYSEARCH_CLOSE))
	{
		DWORD Color = eGray100;
		// ----
		if (this->Data[ePARTYSEARCH_CLOSE].OnClick)
		{
			Color = eGray150;
		}
		// ----
		this->DrawColoredGUI(ePARTYSEARCH_CLOSE, this->Data[ePARTYSEARCH_CLOSE].X, this->Data[ePARTYSEARCH_CLOSE].Y, Color);
		this->DrawToolTip(this->Data[ePARTYSEARCH_CLOSE].X + 5, this->Data[ePARTYSEARCH_CLOSE].Y + 25, "Close");
	}
	// ----
	this->DrawFormat(eGold, StartX + 10, 60, 210, 3, "Party Search");
	// ----
	int x = GetPrivateProfileIntA("Graphics", "X", 0, "./Settings.ini");
	int y = GetPrivateProfileIntA("Graphics", "Y", 0, "./Settings.ini");
	//int w = GetPrivateProfileIntA("Graphics", "W", 0, "./Settings.ini");
	//int h = GetPrivateProfileIntA("Graphics", "H", 0, "./Settings.ini");
	// ----
	this->DrawFormat(eWhite, StartX + 20, this->Data[ePARTYSEARCH_MAIN].Y + 34, 20, 1, "Status:");

	if (gPartySearchSettings.m_SystemActive == false)
	{
		this->DrawFormat(eRed, StartX + 42, this->Data[ePARTYSEARCH_MAIN].Y + 34, 20, 1, "OFF");
	}
	else
	{
		this->DrawFormat(eShinyGreen, StartX + 42, this->Data[ePARTYSEARCH_MAIN].Y + 34, 20, 1, "ON");
	}

	// ----
	this->DrawGUI(ePARTYSETTINGS_DIV, StartX, this->Data[ePARTYSEARCH_MAIN].Y + 40); // Äåëèòåëü áîëüøîé
	// ----
	this->DrawFormat(eWhite, StartX + 5, this->Data[ePARTYSEARCH_MAIN].Y + 56, 50, 3, "Player");
	// ----
	this->DrawFormat(eWhite, StartX + 45, this->Data[ePARTYSEARCH_MAIN].Y + 56, 50, 3, "Map");
	// ----
	this->DrawFormat(eWhite, StartX + 95, this->Data[ePARTYSEARCH_MAIN].Y + 56, 50, 3, "X");
	// ----
	this->DrawFormat(eWhite, StartX + 115, this->Data[ePARTYSEARCH_MAIN].Y + 56, 50, 3, "Y");
	// ----
	this->DrawFormat(eWhite, StartX + 140, this->Data[ePARTYSEARCH_MAIN].Y + 56, 50, 3, "Count");
	// ----
	this->DrawFormat(eWhite, StartX + 170, this->Data[ePARTYSEARCH_MAIN].Y + 56, 50, 3, "Join");
	// ----
	this->DrawGUI(ePARTYSETTINGS_DIV, StartX, this->Data[ePARTYSEARCH_MAIN].Y + 60); // Äåëèòåëü áîëüøîé
	// ----
	if (gPartySearch.CountPages>1)
	{
		this->DrawFormat(eGold, StartX + 104, 379, 20, 3, "%d/%d", gPartySearch.Page + 1, gPartySearch.CountPages);
	}

	if (gPartySearch.Page + 1 > 1)
	{
		this->DrawButton(ePARTYSEARCH_LEFT, StartX + 73, 372, 0, 0);
	}

	if (gPartySearch.Page + 1 < gPartySearch.CountPages)
	{
		this->DrawButton(ePARTYSEARCH_RIGHT, StartX + 73 + 60, 372, 0, 0);
	}

	int DrawnItems = 0;

	for (int i = 0; i<gPartySearch.ListsCount; i++)
	{
		if (DrawnItems >= 10)
		{
			break;
		}

		PARTYLIST* info = gPartySearch.GetPartyList(i + (10 * gPartySearch.Page));

		if (info == 0)
		{
			continue;
		}

		pDrawGUI(400002, StartX + 10, this->Data[ePARTYSEARCH_MAIN].Y + 80 + (20 * i), 170, 21);

		this->DrawFormat(eYellow, StartX + 15, this->Data[ePARTYSEARCH_MAIN].Y + 86 + (20 * i), 50, 1, info->Name);

		this->DrawFormat(eWhite, StartX + 45, this->Data[ePARTYSEARCH_MAIN].Y + 86 + (20 * i), 50, 3, gObjUser.GetMapName(info->Map));

		this->DrawFormat(eWhite, StartX + 95, this->Data[ePARTYSEARCH_MAIN].Y + 86 + (20 * i), 50, 3, "%d", info->X);

		this->DrawFormat(eWhite, StartX + 115, this->Data[ePARTYSEARCH_MAIN].Y + 86 + (20 * i), 50, 3, "%d", info->Y);

		this->DrawFormat(eWhite, StartX + 140, this->Data[ePARTYSEARCH_MAIN].Y + 86 + (20 * i), 50, 3, "%d / 5", info->Count);

		pDrawGUI(400003, StartX + 178, this->Data[ePARTYSEARCH_MAIN].Y + 80 + (i * 20), 22, 19);

		if (info->ButtonActive == true)
		{
			pDrawButton(0x7AA4, StartX + 203, this->Data[ePARTYSEARCH_MAIN].Y + 82 + (i * 20), 16, 15, 0, 0);
		}

		int X = StartX + 203;
		int Y = this->Data[ePARTYSEARCH_MAIN].Y + 82 + (i * 20);
		int MaxX = X + 16;
		int MaxY = Y + 15;

		if (info->ButtonActive == true)
		{
			if (IsWorkZone2(X, Y, MaxX, MaxY))
			{
				pDrawColorButton(0x7AA4, X, Y, 16, 15, 0, 16, eGray100);
				//pDrawButton(0x7AA4, X, Y,16, 15, 0, 16);
			}
		}

		DrawnItems++;
	}

	DrawnItems = 0;

	for (int i = 0; i<gPartySearch.ListsCount; i++)
	{
		if (DrawnItems >= 10)
		{
			break;
		}

		PARTYLIST* info = gPartySearch.GetPartyList(i + (10 * gPartySearch.Page));

		if (info == 0)
		{
			continue;
		}

		int X = StartX + 178;
		int Y = this->Data[ePARTYSEARCH_MAIN].Y + 80 + (i * 20);
		int MaxX = X + 22;
		int MaxY = Y + 19;

		if (IsWorkZone2(X, Y, MaxX, MaxY))
		{
			char szText[2048];
			sprintf(szText, "Need to Party:\n_____________________\nLevel:%d", info->Level);

			if (info->DarkWizard == true)
			{
				strcat(szText, "\nDark Wizard");
			}
			if (info->DarkKnight == true)
			{
				strcat(szText, "\nDark Knight");
			}
			if (info->Elf == true)
			{
				strcat(szText, "\nElf");
			}
			if (info->MagicGladiator == true)
			{
				strcat(szText, "\nMagic Gladiator");
			}
			if (info->DarkLord == true)
			{
				strcat(szText, "\nDark Lord");
			}
			if (info->Summoner == true)
			{
				strcat(szText, "\nSummoner");
			}
			if (info->RageFighter == true)
			{
				strcat(szText, "\nRage Fighter");
			}
			if (info->OnlyGuild == true)
			{
				strcat(szText, "\nOnly Guild");
			}

			strcat(szText, "\n_____________________");

			this->DrawToolTipEx(eWhite, StartX + 230, this->Data[ePARTYSEARCH_MAIN].Y + 62 + (i * 20), 100, 30, 3, szText);
		}

		DrawnItems++;
	}

	if (gPartySearch.Page + 1 > 1)
	{
		if (IsWorkZone(ePARTYSEARCH_LEFT))
		{
			if (this->Data[ePARTYSEARCH_LEFT].OnClick)
			{
				this->DrawButton(ePARTYSEARCH_LEFT, StartX + 73, 372, 0, 46);
				return;
			}
			this->DrawButton(ePARTYSEARCH_LEFT, StartX + 73, 372, 0, 23);
		}
	}
	if (gPartySearch.Page + 1 < gPartySearch.CountPages)
	{
		if (IsWorkZone(ePARTYSEARCH_RIGHT))
		{
			if (this->Data[ePARTYSEARCH_RIGHT].OnClick)
			{
				this->DrawButton(ePARTYSEARCH_RIGHT, StartX + 73 + 60, 372, 0, 46);
				return;
			}
			this->DrawButton(ePARTYSEARCH_RIGHT, StartX + 73 + 60, 372, 0, 23);
		}
	}
}

void Interface::EventPartySearchWindow_All(DWORD Event)
{
	float StartX = (MAX_WIN_WIDTH / 2) - (230.0 / 2);
	DWORD CurrentTick = GetTickCount();
	//DWORD Delay			= (CurrentTick - this->Data[eDIABLO_CLOSE].EventTick);
	if (!this->Data[ePARTYSEARCH_MAIN].OnShow)
	{
		return;
	}

	if (IsWorkZone(ePARTYSEARCH_CLOSE))
	{
		DWORD Delay = (CurrentTick - this->Data[ePARTYSEARCH_CLOSE].EventTick);

		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[ePARTYSEARCH_CLOSE].OnClick = true;
			return;
		}
		// ----
		this->Data[ePARTYSEARCH_CLOSE].OnClick = false;
		// ----
		if (Delay < 500)
		{
			return;
		}
		// ----
		this->Data[ePARTYSEARCH_CLOSE].EventTick = GetTickCount();
		this->SwitchPartySearchWindowState();
	}
	if (IsWorkZone(ePARTYSEARCH_LEFT) && gPartySearch.Page + 1 > 1)
	{
		DWORD Delay = (CurrentTick - this->Data[ePARTYSEARCH_LEFT].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[ePARTYSEARCH_LEFT].OnClick = true;
			return;
		}
		// ----
		this->Data[ePARTYSEARCH_LEFT].OnClick = false;
		// ----
		if (Delay < 100)
		{
			return;
		}
		// ----
		this->Data[ePARTYSEARCH_LEFT].EventTick = GetTickCount();
		// ----
		gPartySearch.Page--;
		//gPartySearch.DrawnItems = 0;
	}
	if (IsWorkZone(ePARTYSEARCH_RIGHT) && gPartySearch.Page + 1 < gPartySearch.CountPages)
	{
		DWORD Delay = (CurrentTick - this->Data[ePARTYSEARCH_RIGHT].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[ePARTYSEARCH_RIGHT].OnClick = true;
			return;
		}
		// ----
		this->Data[ePARTYSEARCH_RIGHT].OnClick = false;
		// ----
		if (Delay < 100)
		{
			return;
		}
		// ----
		this->Data[ePARTYSEARCH_RIGHT].EventTick = GetTickCount();
		// ----
		gPartySearch.Page++;
		//gPartySearch.DrawnItems = 0;
	}

	int DrawnItems = 0;

	for (int i = 0; i<gPartySearch.ListsCount; i++)
	{
		if (DrawnItems >= 10)
		{
			break;
		}
		//pDrawButton(0x7AA4, StartX + 203, this->Data[ePARTYSEARCH_MAIN].Y + 82+(i*20),16, 15, 0, 0);
		if (IsWorkZone2(StartX + 203, this->Data[ePARTYSEARCH_MAIN].Y + 82 + (i * 20), StartX + 203 + 16, this->Data[ePARTYSEARCH_MAIN].Y + 82 + (i * 20) + 15))
		{
			DWORD Delay = (CurrentTick - this->Data[ePARTYSEARCH_RIGHT].EventTick);
			// ----
			if (Event == WM_LBUTTONDOWN)
			{
				this->Data[ePARTYSEARCH_RIGHT].OnClick = true;
				return;
			}
			// ----
			this->Data[ePARTYSEARCH_RIGHT].OnClick = false;
			// ----
			if (Delay < 100)
			{
				return;
			}
			// ----
			if (gPartySearch.gPartyList[i + (10 * gPartySearch.Page)].ButtonActive == false)
			{
				return;
			}
			// ----
			this->Data[ePARTYSEARCH_RIGHT].EventTick = GetTickCount();
			// ----
			gPartySearch.SendPartyRequest(i + (10 * gPartySearch.Page));
			////console.Log("", "Map = %s", pGetMapName(info->Map));
		}
	}
}

bool Interface::ControlTextBox(KBDLLHOOKSTRUCT Hook)
{
	if (this->Data[eSTATSADD_MAIN].OnShow)
	{
		char Value[20];
		int IsBackspace = false;
		int IsDelete = false;
		int IsTab = false;
		int IsArrowUp = false;
		int IsArrowDown = false;
		int IsArrowLeft = false;
		int IsArrowRight = false;

		int Step = 100;

		if (this->Data[eSTATSADD_STEP10].Attribute == true)
		{
			Step = 10;
		}
		else if (this->Data[eSTATSADD_STEP100].Attribute == true)
		{
			Step = 100;
		}
		else if (this->Data[eSTATSADD_STEP1000].Attribute == true)
		{
			Step = 1000;
		}

		int ObjectCount = 4;
		if ((gObjUser.lpPlayer->Class & 7) == 4)
		{
			ObjectCount = 5;
		}

		int SelectedIndex = 0;

		if (Hook.vkCode == VK_BACK)
		{
			IsBackspace = true;
		}
		else if (Hook.vkCode == VK_DELETE)
		{
			IsDelete = true;
		}
		else if (Hook.vkCode == VK_TAB)
		{
			IsTab = true;
		}
		else if (Hook.vkCode == VK_UP)
		{
			IsArrowUp = true;
		}
		else if (Hook.vkCode == VK_DOWN)
		{
			IsArrowDown = true;
		}
		else if (Hook.vkCode == VK_LEFT)
		{
			IsArrowLeft = true;
		}
		else if (Hook.vkCode == VK_RIGHT)
		{
			IsArrowRight = true;
		}
		else if ((Hook.vkCode >= 0x30 && Hook.vkCode <= 0x39) || (Hook.vkCode >= 0x60 && Hook.vkCode <= 0x69))
		{
			int Symbol = GetSymbolFromVK(Hook.vkCode);
			if (Symbol == 0)
			{
				return 1;
			}
			char buff[10];
			sprintf(buff, "%c", Symbol);
			strcpy_s(Value, buff);
			////console.Log("", buff);
			//int Value = atoi(buff);
		}
		else
		{
			return 1;
		}
		int ObjectIDs[5] =
		{
			eSTATSADD_STATBOX01,
			eSTATSADD_STATBOX02,
			eSTATSADD_STATBOX03,
			eSTATSADD_STATBOX04,
			eSTATSADD_STATBOX05,
		};

		for (int i = 0; i<ObjectCount; i++)
		{
			if (this->Data[ObjectIDs[i]].Attribute == 1)
			{
				SelectedIndex = i;
				if (IsBackspace == true)
				{
					this->Data[ObjectIDs[i]].StatValue[strlen(this->Data[ObjectIDs[i]].StatValue) - 1] = '\0';

					if (strlen(this->Data[ObjectIDs[i]].StatValue) == 0)
					{
						strcpy_s(this->Data[ObjectIDs[i]].StatValue, "0");
					}
					break;
				}
				else if (IsDelete == true)
				{
					strcpy_s(this->Data[ObjectIDs[i]].StatValue, "0");
				}
				else if (IsTab == true)
				{
					this->Data[ObjectIDs[i]].Attribute = 0;

					if (i == ObjectCount - 1)
					{
						this->Data[ObjectIDs[0]].Attribute = 1;
					}
					else
					{
						this->Data[ObjectIDs[i + 1]].Attribute = 1;
					}
					break;
				}
				else if (IsArrowUp == true)
				{
					if (i > 0)
					{
						this->Data[ObjectIDs[i]].Attribute = 0;
						this->Data[ObjectIDs[i - 1]].Attribute = 1;
					}
					break;
				}
				else if (IsArrowDown == true)
				{
					if (i < ObjectCount - 1)
					{
						this->Data[ObjectIDs[i]].Attribute = 0;
						this->Data[ObjectIDs[i + 1]].Attribute = 1;
					}
					break;
				}
				else if (IsArrowLeft == true)
				{
					int val = atoi(this->Data[ObjectIDs[i]].StatValue);
					val -= Step;
					if (val < 0)
					{
						val = 0;
					}
					//strcpy_s(this->Data[ObjectIDs[i]].StatValue, "0");
					sprintf_s(this->Data[ObjectIDs[i]].StatValue, "%d", val);
					break;
				}
				else if (IsArrowRight == true)
				{
					int val = atoi(this->Data[ObjectIDs[i]].StatValue);
					val += Step;
					if (val > 65535)
					{
						val = 65535;
					}
					sprintf_s(this->Data[ObjectIDs[i]].StatValue, "%d", val);
					break;
				}
				else
				{
					if (strlen(this->Data[ObjectIDs[i]].StatValue)<8)
					{
						if (!strcmp(this->Data[ObjectIDs[i]].StatValue, "0"))
						{
							strcpy_s(this->Data[ObjectIDs[i]].StatValue, Value);
						}
						else
						{
							strcat_s(this->Data[ObjectIDs[i]].StatValue, Value);
						}
					}
				}
			}
		}

		int StatPoints = 0;

		for (int i = 0; i<ObjectCount; i++)
		{
			if (i == SelectedIndex)
			{
				continue;
			}
			StatPoints += atoi(this->Data[ObjectIDs[i]].StatValue);
		}

		if (StatPoints + atoi(this->Data[ObjectIDs[SelectedIndex]].StatValue) > ViewPoint)
		{
			char buff[20];
			sprintf(buff, "%d", ViewPoint - StatPoints);
			strcpy_s(this->Data[ObjectIDs[SelectedIndex]].StatValue, buff);
		}

		if (atoi(this->Data[ObjectIDs[SelectedIndex]].StatValue) > gServerInfo.get_max_stat_point(ViewAccountLevel))
		{
			char buff[20];
			sprintf(buff, "%d", gServerInfo.get_max_stat_point(ViewAccountLevel));
			strcpy_s(this->Data[ObjectIDs[SelectedIndex]].StatValue, buff);
		}
		return 1;
	}

	return 0;
}

void Interface::EventCharacterWindow(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	if (!this->CheckWindow(Character))
	{
		return;
	}
	// ----
	if (IsWorkZone(eCHARINFO_BTN_STAT))
	{
		DWORD Delay = (CurrentTick - this->Data[eCHARINFO_BTN_STAT].EventTick);

		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eCHARINFO_BTN_STAT].OnClick = true;
			return;
		}
		// ----
		this->Data[eCHARINFO_BTN_STAT].OnClick = false;
		// ----
		if (Delay < 500)
		{
			return;
		}
		// ----
		this->Data[eCHARINFO_BTN_STAT].EventTick = GetTickCount();
		this->SwitchStatsWindowState();
	}
}

void Interface::DrawAnimatedGUI(short ObjectID, float PosX, float PosY)
{
	this->Data[ObjectID].X = PosX;
	this->Data[ObjectID].Y = PosY;
	this->Data[ObjectID].MaxX = PosX + this->Data[ObjectID].Width;
	this->Data[ObjectID].MaxY = PosY + this->Data[ObjectID].Height;
	// ----
	pDrawGUI(this->Data[ObjectID].ModelID, PosX, PosY,
		this->Data[ObjectID].Width, this->Data[ObjectID].Height);
}

void Interface::DrawAnimatedButton(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY)
{
	//if (this->Data[ObjectID].X == -1 || this->Data[ObjectID].Y == -1)
	//{
	this->Data[ObjectID].X = PosX;
	this->Data[ObjectID].Y = PosY;
	this->Data[ObjectID].MaxX = PosX + this->Data[ObjectID].Width;
	this->Data[ObjectID].MaxY = PosY + this->Data[ObjectID].Height;
	//}
	// ----
	pDrawButton(this->Data[ObjectID].ModelID, PosX, PosY,
		this->Data[ObjectID].Width, this->Data[ObjectID].Height, ScaleX, ScaleY);
}

void Interface::DrawColoredAnimatedGUI(short ObjectID, float X, float Y, DWORD Color)
{
	this->Data[ObjectID].X = X;
	this->Data[ObjectID].Y = Y;
	this->Data[ObjectID].MaxX = X + this->Data[ObjectID].Width;
	this->Data[ObjectID].MaxY = Y + this->Data[ObjectID].Height;
	// ----
	pDrawColorButton(this->Data[ObjectID].ModelID, X, Y,
		this->Data[ObjectID].Width, this->Data[ObjectID].Height, 0, 0, Color);
}

void Interface::DrawColoredButton(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY, DWORD Color)
{
	if (this->Data[ObjectID].X == -1 || this->Data[ObjectID].Y == -1)
	{
		this->Data[ObjectID].X = PosX;
		this->Data[ObjectID].Y = PosY;
		this->Data[ObjectID].MaxX = PosX + this->Data[ObjectID].Width;
		this->Data[ObjectID].MaxY = PosY + this->Data[ObjectID].Height;
	}
	// ----
	pDrawColorButton(this->Data[ObjectID].ModelID, PosX, PosY,
		this->Data[ObjectID].Width, this->Data[ObjectID].Height, ScaleX, ScaleY, Color);
}

int Interface::DrawToolTipEx(DWORD Color, int PosX, int PosY, int Width, int Height, int Align, LPCSTR Text, ...)
{
	char Buff[2048];
	char Buff2[2048];
	int BuffLen = sizeof(Buff);
	ZeroMemory(Buff, BuffLen);
	// ----
	va_list args;
	va_start(args, Text);
	int Len = vsprintf_s(Buff, BuffLen, Text, args);
	va_end(args);
	// ----

	int LineCount = 0;

	strcpy(Buff2, Buff);

	char* Line = strtok(Buff2, "\n");
	// ----
	while (Line != NULL)
	{
		LineCount++;
		Line = strtok(NULL, "\n");
	}

	pSetBlend(true);
	glColor4f(0.0, 0.0, 0.0, 1.0);
	pDrawBarForm(PosX, PosY, Width, LineCount * 10, 0.0f, 0);
	pGLSwitchBlend();
	pGLSwitch();

	glColor3f(1.0, 1.0, 1.0);
	pSetBlend(false);

	this->DrawText(eWhite, PosX, PosY, Width, Align, Buff);
	return 0;
}

void Interface::DrawText(DWORD Color, int PosX, int PosY, int Width, int Align, LPCSTR Text, ...) // OK
{
	char Buff[2048];
	const int BuffLen = sizeof(Buff) - 1;
	ZeroMemory(Buff, BuffLen);

	va_list args;
	va_start(args, Text);
	vsprintf_s(Buff, BuffLen, Text, args);
	va_end(args);

	char * Line = strtok(Buff, "\n");

	while (Line != nullptr)
	{
		DrawInterfaceText(Line, PosX, PosY, Width, 0, Color, 0, Align);
		PosY += 10;
		Line = strtok(NULL, "\n");
	}
}

bool Interface::ButtonEx(DWORD Event, int ButtonID, bool Type)
{
	if (!this->IsWorkZone(ButtonID))
	{
		return false;
	}

	if (Type == true)
	{
		if (!this->Data[ButtonID].Attribute)
		{
			return false;
		}
	}

	// ----
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[ButtonID].EventTick);
	// ----

	if (Event == WM_LBUTTONDOWN && this->Data[ButtonID].OnClick == false)
	{
		this->Data[ButtonID].OnClick = true;
		//return false;
	}

	if (Event == WM_LBUTTONUP && this->Data[ButtonID].OnClick == true)
	{
		this->Data[ButtonID].OnClick = false;
		return true;
	}
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[ButtonID].OnClick = false;
	// ----
	this->Data[ButtonID].EventTick = GetTickCount();
	// ----
	return false;
}

void Interface::DrawMessageBox(LPCSTR Text, ...)
{
	char Buff[2048];
	int BuffLen = sizeof(Buff);
	ZeroMemory(Buff, BuffLen);
	// ----
	va_list args;
	va_start(args, Text);
	int Len = vsprintf_s(Buff, BuffLen, Text, args);
	va_end(args);

	CharTest v15;

	LPCSTR pText = Buff;
	sub_409A50_addr(&v15, (int)pText);
	pOpenInfoBox1(&v15, -1);
	sub_409AD0_Addr((LPVOID)&v15);
}

bool Interface::IsWorkZone(float X, float Y, float MaxX, float MaxY, bool a5)
{
	if (a5) 
	{
		if ((pCursorX < X || pCursorX > X + MaxX) || (pCursorY < Y || pCursorY > Y + MaxY))
		return false;
		return true;
	}
	if ((pCursorX < X || pCursorX > MaxX) || (pCursorY < Y || pCursorY > MaxY))
	return false;
	return true;
}

signed int __cdecl ColorMoneyRuud(unsigned int a1)
{
	signed int color1 = eWhite; // eax@2

	if(a1 >= 1000 && a1 < 1000000)
	{
		color1 = eShinyGreen;
	}
	else if(a1 >= 1000000 && a1 < 10000000)
	{
		color1 = eGold;
	}
	else if(a1 >= 1000000 && a1 < 100000000)
	{
		color1 = eOrange;
	}
	else if(a1 >= 100000000)
	{
		color1 = eRed;
	}
	return color1;
}

//-- Shop Ruud
void InventoryWindows(DWORD id, float x, float y, float w, float h)
{
	if(gProtect.m_MainInfo.CustomInterfaceType >= 0 && gProtect.m_MainInfo.CustomInterfaceType <= 5)
	{
	//-- NPC RUUD
	//=============================
	jCRenderRuud.OpenRuud();
	//=============================
	pDrawGUI(id, x, y, w, h);
	
	if(gProtect.m_MainInfo.CustomInterfaceType >= 0 && gProtect.m_MainInfo.CustomInterfaceType <= 5)
	{
		if(gInterface.CheckWindow(ObjWindow::CashShop) 
		//||gInterface.CheckWindow(ObjWindow::FriendList)
		||gInterface.CheckWindow(ObjWindow::MoveList)
		//|| gInterface.CheckWindow(ObjWindow::Party)
		//|| gInterface.CheckWindow(ObjWindow::Quest)
		//|| gInterface.CheckWindow(ObjWindow::NPC_Devin)
		//|| gInterface.CheckWindow(ObjWindow::Guild)	
		//|| gInterface.CheckWindow(ObjWindow::Trade)
		|| gInterface.CheckWindow(ObjWindow::Warehouse)
		|| gInterface.CheckWindow(ObjWindow::ChaosBox)
		//|| gInterface.CheckWindow(ObjWindow::CommandWindow)
		//|| gInterface.CheckWindow(ObjWindow::PetInfo)
		|| gInterface.CheckWindow(ObjWindow::Shop)
		//|| gInterface.CheckWindow(ObjWindow::Inventory)
		|| gInterface.CheckWindow(ObjWindow::Store)
		|| gInterface.CheckWindow(ObjWindow::OtherStore)
		|| gInterface.CheckWindow(ObjWindow::Character)
		//|| gInterface.CheckWindow(ObjWindow::DevilSquare)
		//|| gInterface.CheckWindow(ObjWindow::BloodCastle)
		//|| gInterface.CheckWindow(ObjWindow::CreateGuild)
		//|| gInterface.CheckWindow(ObjWindow::GuardNPC)
		//|| gInterface.CheckWindow(ObjWindow::SeniorNPC)
		//|| gInterface.CheckWindow(ObjWindow::GuardNPC2)
		//|| gInterface.CheckWindow(ObjWindow::CastleGateSwitch)
		//|| gInterface.CheckWindow(ObjWindow::CatapultNPC)
		//|| gInterface.CheckWindow(ObjWindow::CrywolfGate)
		//|| gInterface.CheckWindow(ObjWindow::IllusionTemple)
		//|| gInterface.CheckWindow(ObjWindow::HeroList)
	    //|| gInterface.CheckWindow(ObjWindow::ChatWindow)
		//|| gInterface.CheckWindow(ObjWindow::FastMenu)
		//|| gInterface.CheckWindow(ObjWindow::Options)	
		|| gInterface.CheckWindow(ObjWindow::Help)
		//|| gInterface.CheckWindow(ObjWindow::FastDial)
		|| gInterface.CheckWindow(ObjWindow::SkillTree)
		//|| gInterface.CheckWindow(ObjWindow::GoldenArcher1)
		//|| gInterface.CheckWindow(ObjWindow::GoldenArcher2)
		//|| gInterface.CheckWindow(ObjWindow::LuckyCoin1)
		//|| gInterface.CheckWindow(ObjWindow::LuckyCoin2)
		//|| gInterface.CheckWindow(ObjWindow::NPC_Duel)
		//|| gInterface.CheckWindow(ObjWindow::NPC_Titus)
		|| gInterface.CheckWindow(ObjWindow::CashShop)
		|| gInterface.CheckWindow(ObjWindow::Lugard)
		//|| gInterface.CheckWindow(ObjWindow::QuestList1)
		//|| gInterface.CheckWindow(ObjWindow::QuestList2)
		|| gInterface.CheckWindow(ObjWindow::Jerint)
		|| gInterface.CheckWindow(ObjWindow::FullMap)
		//|| gInterface.CheckWindow(ObjWindow::NPC_Dialog)
		//|| gInterface.CheckWindow(ObjWindow::GensInfo)
		|| gInterface.CheckWindow(ObjWindow::NPC_Julia)
		|| gInterface.CheckWindow(ObjWindow::NPC_ChaosMix)
		|| gInterface.CheckWindow(ObjWindow::ExpandInventory)
		|| gInterface.CheckWindow(ObjWindow::ExpandWarehouse)
		|| gInterface.CheckWindow(ObjWindow::MuHelper))
		{
			return;
		}
		//-- Ruud Coin Interface 97/99/S2/S6/Legends
		int x, y;
		char v10[255]; // ST24_4@1
		unsigned int v23; // [sp+128h] [bp-4h]@1
		char v22[260]; // [sp+24h] [bp-108h]@1
		int v15; // ST18_4@1
		int v639; // ST18_4@1

		x = 400;
		y = 400;
		
		ZeroMemory(v22, sizeof(v22));
		pGetMoneyFormat(Ruud, v22, 0);
		v15 = ColorMoneyRuud(Ruud);
		SetTextColorByHDC(pTextThis(), v15);

		if(gProtect.m_MainInfo.CustomInterfaceType == 0 || gProtect.m_MainInfo.CustomInterfaceType == 1 || gProtect.m_MainInfo.CustomInterfaceType == 2
			|| gProtect.m_MainInfo.CustomInterfaceType == 5)
		{
			RenderBitmap(0x7877, x - 52, y + 10, 120, 20, 0, 0, 0.5, 0.5, 0.5, 1, 0);
			gInterface.DrawFormat(eBlack, x - 33, y + 16, 20, 1, "Ruud");
			gInterface.DrawFormat(eOrange, x - 19, y + 16, 50, 4, "%s", v22);
		}
		/*else if(gProtect.m_MainInfo.CustomInterfaceType == 3 || gProtect.m_MainInfo.CustomInterfaceType == 4)
		{
			RenderBitmap(0x7877, x + 93, y + 28, 120, 20, 0, 0, 0.5, 0.5, 0.5, 1, 0);
			gInterface.DrawFormat(eBlack, x + 112, y + 35, 20, 1, "Ruud");
			gInterface.DrawFormat(eOrange, x + 126, y + 35, 50, 4, "%s", v22);
			}*/
		}
	}
}
//-- EXP Bar
int sub_895600(float x, float y, int number)
{
	if(gProtect.m_MainInfo.CustomInterfaceType >= 0 && gProtect.m_MainInfo.CustomInterfaceType <= 5)
	{
	int result; // eax@1

	pSetBlend( 1 );

	result = CRenderNumberEx(x, y, number, ( pWinWidthReal <= 1.6 ) ? 1.0 : 0.90, 31337);

	return result;
	}
}
//--
//--Pet HPBar Activado
DWORD VKBUTTON_DELAY;
void CEx700::BarPetMuun()
{
		if(gInterface.CheckWindow(ObjWindow::CashShop) 
		//||gInterface.CheckWindow(ObjWindow::FriendList)
		||gInterface.CheckWindow(ObjWindow::MoveList)
		//|| gInterface.CheckWindow(ObjWindow::Party)
		//|| gInterface.CheckWindow(ObjWindow::Quest)
		//|| gInterface.CheckWindow(ObjWindow::NPC_Devin)
		//|| gInterface.CheckWindow(ObjWindow::Guild)	
		//|| gInterface.CheckWindow(ObjWindow::Trade)
		//|| gInterface.CheckWindow(ObjWindow::Warehouse)
		//|| gInterface.CheckWindow(ObjWindow::ChaosBox)
		//|| gInterface.CheckWindow(ObjWindow::CommandWindow)
		//|| gInterface.CheckWindow(ObjWindow::PetInfo)
		|| gInterface.CheckWindow(ObjWindow::Shop)
		//|| gInterface.CheckWindow(ObjWindow::Inventory)
		//|| gInterface.CheckWindow(ObjWindow::Store)
		//|| gInterface.CheckWindow(ObjWindow::OtherStore)
		|| gInterface.CheckWindow(ObjWindow::Character)
		//|| gInterface.CheckWindow(ObjWindow::DevilSquare)
		//|| gInterface.CheckWindow(ObjWindow::BloodCastle)
		//|| gInterface.CheckWindow(ObjWindow::CreateGuild)
		//|| gInterface.CheckWindow(ObjWindow::GuardNPC)
		//|| gInterface.CheckWindow(ObjWindow::SeniorNPC)
		//|| gInterface.CheckWindow(ObjWindow::GuardNPC2)
		//|| gInterface.CheckWindow(ObjWindow::CastleGateSwitch)
		//|| gInterface.CheckWindow(ObjWindow::CatapultNPC)
		//|| gInterface.CheckWindow(ObjWindow::CrywolfGate)
		//|| gInterface.CheckWindow(ObjWindow::IllusionTemple)
		//|| gInterface.CheckWindow(ObjWindow::HeroList)
	    //|| gInterface.CheckWindow(ObjWindow::ChatWindow)
		//|| gInterface.CheckWindow(ObjWindow::FastMenu)
		//|| gInterface.CheckWindow(ObjWindow::Options)	
		|| gInterface.CheckWindow(ObjWindow::Help)
		//|| gInterface.CheckWindow(ObjWindow::FastDial)
		|| gInterface.CheckWindow(ObjWindow::SkillTree)
		//|| gInterface.CheckWindow(ObjWindow::GoldenArcher1)
		//|| gInterface.CheckWindow(ObjWindow::GoldenArcher2)
		//|| gInterface.CheckWindow(ObjWindow::LuckyCoin1)
		//|| gInterface.CheckWindow(ObjWindow::LuckyCoin2)
		//|| gInterface.CheckWindow(ObjWindow::NPC_Duel)
		//|| gInterface.CheckWindow(ObjWindow::NPC_Titus)
		|| gInterface.CheckWindow(ObjWindow::CashShop)
		|| gInterface.CheckWindow(ObjWindow::Lugard)
		//|| gInterface.CheckWindow(ObjWindow::QuestList1)
		//|| gInterface.CheckWindow(ObjWindow::QuestList2)
		|| gInterface.CheckWindow(ObjWindow::Jerint)
		|| gInterface.CheckWindow(ObjWindow::FullMap)
		//|| gInterface.CheckWindow(ObjWindow::NPC_Dialog)
		//|| gInterface.CheckWindow(ObjWindow::GensInfo)
		|| gInterface.CheckWindow(ObjWindow::NPC_Julia)
		|| gInterface.CheckWindow(ObjWindow::NPC_ChaosMix))
		//|| gInterface.CheckWindow(ObjWindow::ExpandInventory)
		//|| gInterface.CheckWindow(ObjWindow::ExpandWarehouse)
		//|| gInterface.CheckWindow(ObjWindow::MuHelper))
	{
		return;
	}
	if (jCRenderRuud.OpeningRuud)
	{
		return;
	}

	if(gProtect.m_MainInfo.CustomInterfaceType >= 0 && gProtect.m_MainInfo.CustomInterfaceType <= 5)
	{
	int y = 31;
	int x = 20;

	RenderBitmap(61545, 2, y + 6, Return2X(TransForX(59)), ReturnY(TransForY(16)), 0.0, 0.0, 0.75,0.1678999364, 1, 1, 0); //-- Barra
	//-- TitleName
	pSetFont(pTextThis(), (int) pFontBold);
	pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0);
	pSetTextColor(pTextThis(), 240, 240, 240, 255);
	pDrawText(pTextThis(), x + 4, y + 9, "Pet", 148.0, 0, (LPINT)1, 0);

	if(pCheckMouseOver( Return2X(TransForX(61)), y + ReturnY(TransForY(6)), Return2X(TransForX(14)), ReturnY(TransForY(14))))
	{
		if(pCursorX >= Return2X(TransForX(61)))
		{
		pSetCursorFocus = true;
		}
	}

	if(MinimizarPet == 0)
	{
		if(CheckButtonPressed( Return2X(TransForX(61)), y + ReturnY(TransForY(6)), Return2X(TransForX(14)), ReturnY(TransForY(14))))
		{
			RenderBitmap(61545, Return2X(TransForX(61)), y + ReturnY(TransForY(6)), Return2X(TransForX(14)), ReturnY(TransForY(14)), 0.6000000238, 0.4131799936, 0.1090999693, 0.09779000282,1, 1, 0); //-- Boton Minimizar
			if( GetTickCount() >= VKBUTTON_DELAY + 200 )
			{
				MinimizarPet = 1;
				VKBUTTON_DELAY = GetTickCount();
			}
		}
		else
		{
			RenderBitmap(61545, Return2X(TransForX(61)), y + ReturnY(TransForY(6)), Return2X(TransForX(14)), ReturnY(TransForY(14)), 0.4829999804, 0.4131799936, 0.1090999693, 0.09779000282,1, 1, 0); //-- Boton Minimizar
		}
	}
	else
	{
		if(CheckButtonPressed( Return2X(TransForX(61)), y + ReturnY(TransForY(6)), Return2X(TransForX(14)), ReturnY(TransForY(14))))
		{
			RenderBitmap(61545, Return2X(TransForX(61)), y + ReturnY(TransForY(6)), Return2X(TransForX(14)), ReturnY(TransForY(14)), 0.1289999783, 0.4131799936, 0.1090999693, 0.09779000282,1, 1, 0); //-- Boton Minimizar
			if( GetTickCount() >= VKBUTTON_DELAY + 200 )
			{
				MinimizarPet = 0;
				VKBUTTON_DELAY = GetTickCount();
			}
		}
		else
			{
			RenderBitmap(61545, Return2X(TransForX(61)), y + ReturnY(TransForY(6)), Return2X(TransForX(14)), ReturnY(TransForY(14)), 0.01299999934, 0.4131799936, 0.1090999693, 0.09779000282,1, 1, 0); //-- Boton Minimizar
			}
		}
	}
}
//--
//--Spirit BarHP Activado
void PetSpiritHP(signed int x, signed int y, int nameIndex, signed int hp, signed int hpmax, char a9)
{
		if(gInterface.CheckWindow(ObjWindow::CashShop) 
		//||gInterface.CheckWindow(ObjWindow::FriendList)
		||gInterface.CheckWindow(ObjWindow::MoveList)
		//|| gInterface.CheckWindow(ObjWindow::Party)
		//|| gInterface.CheckWindow(ObjWindow::Quest)
		//|| gInterface.CheckWindow(ObjWindow::NPC_Devin)
		//|| gInterface.CheckWindow(ObjWindow::Guild)	
		//|| gInterface.CheckWindow(ObjWindow::Trade)
		//|| gInterface.CheckWindow(ObjWindow::Warehouse)
		//|| gInterface.CheckWindow(ObjWindow::ChaosBox)
		//|| gInterface.CheckWindow(ObjWindow::CommandWindow)
		//|| gInterface.CheckWindow(ObjWindow::PetInfo)
		|| gInterface.CheckWindow(ObjWindow::Shop)
		//|| gInterface.CheckWindow(ObjWindow::Inventory)
		//|| gInterface.CheckWindow(ObjWindow::Store)
		//|| gInterface.CheckWindow(ObjWindow::OtherStore)
		|| gInterface.CheckWindow(ObjWindow::Character)
		//|| gInterface.CheckWindow(ObjWindow::DevilSquare)
		//|| gInterface.CheckWindow(ObjWindow::BloodCastle)
		//|| gInterface.CheckWindow(ObjWindow::CreateGuild)
		//|| gInterface.CheckWindow(ObjWindow::GuardNPC)
		//|| gInterface.CheckWindow(ObjWindow::SeniorNPC)
		//|| gInterface.CheckWindow(ObjWindow::GuardNPC2)
		//|| gInterface.CheckWindow(ObjWindow::CastleGateSwitch)
		//|| gInterface.CheckWindow(ObjWindow::CatapultNPC)
		//|| gInterface.CheckWindow(ObjWindow::CrywolfGate)
		//|| gInterface.CheckWindow(ObjWindow::IllusionTemple)
		//|| gInterface.CheckWindow(ObjWindow::HeroList)
	    //|| gInterface.CheckWindow(ObjWindow::ChatWindow)
		//|| gInterface.CheckWindow(ObjWindow::FastMenu)
		//|| gInterface.CheckWindow(ObjWindow::Options)	
		|| gInterface.CheckWindow(ObjWindow::Help)
		//|| gInterface.CheckWindow(ObjWindow::FastDial)
		|| gInterface.CheckWindow(ObjWindow::SkillTree)
		//|| gInterface.CheckWindow(ObjWindow::GoldenArcher1)
		//|| gInterface.CheckWindow(ObjWindow::GoldenArcher2)
		//|| gInterface.CheckWindow(ObjWindow::LuckyCoin1)
		//|| gInterface.CheckWindow(ObjWindow::LuckyCoin2)
		//|| gInterface.CheckWindow(ObjWindow::NPC_Duel)
		//|| gInterface.CheckWindow(ObjWindow::NPC_Titus)
		|| gInterface.CheckWindow(ObjWindow::CashShop)
		|| gInterface.CheckWindow(ObjWindow::Lugard)
		//|| gInterface.CheckWindow(ObjWindow::QuestList1)
		//|| gInterface.CheckWindow(ObjWindow::QuestList2)
		|| gInterface.CheckWindow(ObjWindow::Jerint)
		|| gInterface.CheckWindow(ObjWindow::FullMap)
		//|| gInterface.CheckWindow(ObjWindow::NPC_Dialog)
		//|| gInterface.CheckWindow(ObjWindow::GensInfo)
		|| gInterface.CheckWindow(ObjWindow::NPC_Julia)
		|| gInterface.CheckWindow(ObjWindow::NPC_ChaosMix))
		//|| gInterface.CheckWindow(ObjWindow::ExpandInventory)
		//|| gInterface.CheckWindow(ObjWindow::ExpandWarehouse)
		//|| gInterface.CheckWindow(ObjWindow::MuHelper))
	{
		return;
	}
	if (jCRenderRuud.OpeningRuud)
	{
		return;
	}

	if(gProtect.m_MainInfo.CustomInterfaceType >= 0 && gProtect.m_MainInfo.CustomInterfaceType <= 5)
	{
	y += ( *(DWORD *)(*(DWORD *)0x7BC4F04 + 556) != 65535 ) ? 8 : 5;

	if( MinimizarPet == 0 )
		{
		RenderBitmap(61545, 2, y + 22, Return2X(TransForX( 74 )), ReturnY(TransForY( 24 )), 0.0, 0.1731800437, 0.75, 0.2378999293,1, 1, 0); //-- Fondo

		pSetTextColor(pTextThis(), 0xFFu, 0xFFu, 0xFFu, 0xFFu);
		pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0);
		pDrawText(pTextThis(), 5, y + 27, (LPCTSTR)nameIndex, 0, 0, (LPINT) 1, 0);

		int v15 = (double)hp / (double)hpmax * 69.0;

		pSetBlend(1);
		glColor4f(0.4274, 0.0313, 0.1254, 0.798);

		pDrawBarForm(4, y + 38, Return2X(TransForX( v15 )), 4, 0, 0);
		pGLSwitch();
		pSetBlend(0);
		glColor4f(1.0, 1.0, 1.0, 1.0);
		}
	}
}
//--

void Interface::RenderObjectSystem2()
{
	if(gProtect.m_MainInfo.CustomInterfaceType >= 0 && gProtect.m_MainInfo.CustomInterfaceType <= 5)
	{
	//-- Shop Ruud Activado
	//-- Number Stack
	SetCompleteHook(0xE9, 0x00895600, &sub_895600);
	//-- Windows Inventory Ruud
	SetCompleteHook(0xE8, 0x00836EF6, &InventoryWindows);
	}
	//--
	//--Spirit BarHP Activado
	if(gProtect.m_MainInfo.CustomInterfaceType >= 0 && gProtect.m_MainInfo.CustomInterfaceType <= 5)
	{
	SetCompleteHook(0xE8, 0x007E020C, &PetSpiritHP); //-- PAJARRACO
	SetCompleteHook(0xE8, 0x007E0298, &PetSpiritHP);//-- PAJARRACO
	}
	//--
}

//-------------------------------------------------------------------------------------------------------

void Interface::DrawInterfaceCustom1() {//	

	gInterface.DrawIMG(eMain, 36, 415, 1.5, 2.0);
}

void Interface::DrawInterfaceMenu1()
{
	if (IsWorkZone(eParty))
	{
		this->DrawToolTip(345, 420, "Party (P)");
	}
	if (this->CheckWindow(Party))
	{
		gInterface.DrawButton(eParty, 342, 448, 0.0, 0.0);
	}
	if (IsWorkZone(eCharacter))
	{
		this->DrawToolTip(375, 420, "Character (C)");
	}
	if (this->CheckWindow(Character))
	{
		gInterface.DrawButton(eCharacter, 371.5f, 448, 0.0, 0.0);
	}
	if (IsWorkZone(eInventory))
	{
		this->DrawToolTip(405, 420, "Inventory (I-V)");
	}
	if (this->CheckWindow(Inventory))
	{
		gInterface.DrawButton(eInventory, 399, 448, 0.0, 0.0);
	}
	if (IsWorkZone(eShop))
	{
		this->DrawToolTip(430, 420, "CashShop");
	}
	if (this->CheckWindow(CashShop))
	{
		gInterface.DrawButton(eShop, 442.5f, 450, 0.0, 0.0);
	}
	if (IsWorkZone(eFriend))
	{
		this->DrawToolTip(580, 420, "Friends");
	}
	if (this->CheckWindow(FriendList))
	{
		gInterface.DrawButton(eFriend, 581, 433, 0.0, 0.0);
	}
	if (IsWorkZone(eGuild))
	{
		this->DrawToolTip(580, 444, "Guild (G)");
	}
	if (this->CheckWindow(Guild))
	{
		gInterface.DrawButton(eGuild, 529, 460, 0.0, 0.0);
	}
}

void Interface::DrawCoord1()
{
	gObjUser.Refresh();

	if (*(DWORD*)MAIN_SCREEN_STATE == 5)
	{
		glColor3f(1.0f, 1.0f, 1.0f);
		pDrawInterfaceNumBer(86, 466, gObjUser.lpViewPlayer->MapPosX, 0.96);
		pDrawInterfaceNumBer(102, 466, gObjUser.lpViewPlayer->MapPosY, 0.96);

	}
}

int Wnext = 0;
bool Interface::WareNext(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eNextWare].EventTick);
	DWORD Delay2 = (CurrentTick - gInterface.Data[ePrevWare].EventTick);

	if (!gInterface.Data[eWAREHOUSE_MAIN].OnShow || Wnext == -1)
	{
		return false;
	}

	if (!gInterface.IsWorkZone(eNextWare))
	{
		return false;
	}

	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eNextWare].OnClick = true;
		return true;
	}


	if (Delay < 100 || Delay2 < 100)
	{
		return false;
	}

	gInterface.Data[eNextWare].OnClick = false;

	this->Page++;

	gInterface.Data[eNextWare].EventTick = GetTickCount();


	return true;
}

int Wprev = 0;
bool Interface::WarePrev(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[ePrevWare].EventTick);
	DWORD Delay2 = (CurrentTick - gInterface.Data[eNextWare].EventTick);

	if (!gInterface.Data[eWAREHOUSE_MAIN].OnShow || Wprev == -1)
	{
		return false;
	}

	if (!gInterface.IsWorkZone(ePrevWare))
	{
		return false;
	}

	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[ePrevWare].OnClick = true;
		return true;
	}

	if (Delay < 100 || Delay2 < 100)
	{
		return false;
	}

	gInterface.Data[ePrevWare].OnClick = false;

	gInterface.Data[ePrevWare].EventTick = GetTickCount();

	this->Page--;

	return true;
}
//-------------------------------------------------------------------------------------------------------
#include "CMacroUIEx.h"
#include "UIController.h"
#include "CBUtil.h"
#include "NewsBoard.h"
#if(JEWELBANKVER2)


#define GET_ITEM(x,y) (((x)*MAX_ITEM_TYPE)+(y))

int PageBank = 0;
int MaxPerPageBank = 8;
static void BPagePrevAction(LPVOID pClass)
{
	if (GetTickCount() < gCMacroUIEx.JEWELBANK_WINDOW->lastActionTime + 300) return;
	gCMacroUIEx.JEWELBANK_WINDOW->lastActionTime = GetTickCount();
	
	if (PageBank > 0)
	{
		PageBank--;
	}
	//pDrawMessage("-",1);
}
static void BPageNextAction(LPVOID pClass)
{
	if (GetTickCount() < gCMacroUIEx.JEWELBANK_WINDOW->lastActionTime + 300) return;
	gCMacroUIEx.JEWELBANK_WINDOW->lastActionTime = GetTickCount();
	
	if (PageBank < (gInterface.mCListItemBank.size() / MaxPerPageBank))
	{
		PageBank++;
	}
	//	pDrawMessage("+", 1);
}
float FixYItemBMD(int ItemIndex)
{

	switch (ItemIndex)
	{
	case 6159:
	{
				 return 6.f;
	}
		break;
	case 7199:
	{
				 return 9.5f;
	}
		break;
	default:
		break;
	}
	return 0;
}
void NewBankSendGS(int Type, int SelectIndex)
{
	if ((GetTickCount() - gCMacroUIEx.JEWELBANK_WINDOW->lastActionTime) < 300)
	{
		return;
	}
	//==Tham Gia Than Ma
	REQUEST_RUTGUIBANK pMsg;
	pMsg.header.set(0xFB, 0x21, sizeof(pMsg));
	pMsg.TypeSend = Type;
	pMsg.IndexList = SelectIndex;
	DataSend((LPBYTE)&pMsg, pMsg.header.size);

	//gCMacroUIEx.JEWELBANK_WINDOW->lastActionTime = GetTickCount();
}





void Interface::DrawWindowJewelBankVer2()
{
	if (gCMacroUIEx.JEWELBANK_WINDOW->onShow == false)
	{
		if (PageBank) PageBank = 0;
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
		//|| gInterface.CheckWindow(ObjWindow::Inventory)
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
		|| gInterface.CheckWindow(ObjWindow::MuHelper))
	{

		if (gCMacroUIEx.JEWELBANK_WINDOW->onShow == true)
		{
			gCMacroUIEx.JEWELBANK_WINDOW->onShow = false;
			pSetCursorFocus = false;
			return;
		}
	}

	gInterface.OpenWindow(ObjWindow::Inventory);

	if (gInterface.mCListItemBank.empty())
	{
		gCMacroUIEx.JEWELBANK_WINDOW->onShow = false;
	}



	const BYTE state[3] = { 0, 1, 2 };
	float CuaSoW = gCMacroUIEx.JEWELBANK_WINDOW->Width;
	float CuaSoH = gCMacroUIEx.JEWELBANK_WINDOW->Height;

	float StartX = gCMacroUIEx.JEWELBANK_WINDOW->X;
	float StartY = gCMacroUIEx.JEWELBANK_WINDOW->Y;
	float CenterX = StartX + (CuaSoW / 2);
	float MaxY = StartY + CuaSoH;
	/*float MainCenter = setPosCenterY(320.0);
	float ButtonX = MainCenter - (29.0 / 2);*/

	gCMacroUIEx.DrawWindowBG(gCMacroUIEx.JEWELBANK_WINDOW, "BANCO DE JOIAS");

	//gCentral.PrintDropBox(StartX, StartY, 270, 320, 0, 0);  //Quadro transparente
	//CustomFont.DrawMultipleColor(CustomFont.FontBold, (int)StartX+180 , (int)StartY+ 1, 0x0, 0, 0, 10, "Ruleta Rusa");

	CustomFont.Draw((HFONT)pFontNormal, StartX, StartY + 45, 0xFF6600FF, 0x0, CuaSoW, 0, 3, "Clique no botão (Enviar) para enviar as joias para o banco");
	CustomFont.Draw((HFONT)pFontNormal, StartX, StartY + 45 + 15, 0xFF6600FF, 0x0, CuaSoW, 0, 3, "* O Auto Pick deposita automaticamente no banco quando retirado");

	float StartXItem = StartX + 10;
	float StartYItem = StartY + 75;

	CustomFont.Draw((HFONT)pFontNormal, StartXItem + 36 + 100 + 70, StartYItem + 15, 0xFFFFFFFF, 0xD69015A9, 138, 0, 3, "Retirar as Joias");
	CustomFont.Draw((HFONT)pFontNormal, StartXItem + 36 + 100 + 70 + 138, StartYItem + 15, 0xFFFFFFFF, 0x15D6C9A9, 40, 0, 3, "Enviar Pedras");
	CustomFont.Draw((HFONT)pFontNormal, StartXItem + 36 + 100 + 70 + 138 + 40, StartYItem + 15, 0xFFFFFFFF, 0x9C15D6A9, 40, 0, 3, "Auto Pick");
	float KhoangCach = 25;
	//for (int n = 0; n < MaxPerPage; n++)
	for (int n = 0, r = (PageBank * MaxPerPageBank); n < MaxPerPageBank && r < gInterface.mCListItemBank.size(); r++)
	{
		int ItemIndex = gInterface.mCListItemBank[r].ItemIndex;
		int ItemLevel = gInterface.mCListItemBank[r].ItemLevel;


		ItemBmdStruct is = *(ItemBmdStruct*)(*(DWORD*)0x8128AC0 + sizeof(ItemBmdStruct)* ItemIndex);
		int size = max(is.ItemWidth, is.ItemHeight);

		float itemScale = 1.0;
		float addY = FixYItemBMD(ItemIndex);
		int nCount = 0;

		if (n % 2)
		{
			gInterface.DrawBarForm(StartXItem, (StartYItem + (n * KhoangCach)) + 25, CuaSoW - 20, 20, 0.0, 0.0, 0.0, 0.3);//bg
		}
		else
		{
			gInterface.DrawBarForm(StartXItem, (StartYItem + (n * KhoangCach)) + 25, CuaSoW - 20, 20, 0.0, 0.0, 0.0, 0.6);//bg
		}
		gCBUtil.DrawItem3D(StartXItem, (StartYItem + (n * KhoangCach) + addY), 45, 45, ItemIndex, SET_ITEMOPT_LEVEL(ItemLevel), 0, 0, 0, itemScale);//bmd
		CustomFont.Draw((HFONT)pFontNormal, StartXItem + 36, (StartYItem + (n * KhoangCach)) + 28, 0xFFFFFFA9, 0x0, 100, 0, 3, BGetItemName3(ItemIndex, SET_ITEMOPT_LEVEL(ItemLevel))); //Name
		CustomFont.Draw((HFONT)pFontNormal, StartXItem + 36 + 100, (StartYItem + (n * KhoangCach)) + 28, 0xFFDD00A9, 0x0, 60, 0, 3, "x%d", gInterface.mCListItemBank[r].ItemCount); //so luong
		//==ButtonRut 1
		if (UIController.BButton(31618, StartXItem + 36 + 100 + 70 + (28 * nCount), (StartYItem + (n * KhoangCach)) + 25, 25, 22, 25, 22, 3, state))
		{
			NewBankSendGS(eRut1, r);
		}
		CustomFont.Draw((HFONT)pFontNormal, StartXItem + 36 + 100 + 70 + (28 * nCount++), (StartYItem + (n * KhoangCach)) + 30, 0xFFFFFFBE, 0x0, 26, 0, 3, "1");

		//==ButtonRut 10
		if (UIController.BButton(31618, StartXItem + 36 + 100 + 70 + (28 * nCount), (StartYItem + (n * KhoangCach)) + 25, 25, 22, 25, 22, 3, state))
		{
			NewBankSendGS(eRut10, r);
		}
		CustomFont.Draw((HFONT)pFontNormal, StartXItem + 36 + 100 + 70 + (28 * nCount++), (StartYItem + (n * KhoangCach)) + 30, 0xFFFFFFBE, 0x0, 26, 0, 3, "10");
		//==ButtonRut 20
		if (UIController.BButton(31618, StartXItem + 36 + 100 + 70 + (28 * nCount), (StartYItem + (n * KhoangCach)) + 25, 25, 22, 25, 22, 3, state))
		{
			NewBankSendGS(eRut20, r);
		}
		CustomFont.Draw((HFONT)pFontNormal, StartXItem + 36 + 100 + 70 + (28 * nCount++), (StartYItem + (n * KhoangCach)) + 30, 0xFFFFFFBE, 0x0, 26, 0, 3, "20");
		//==ButtonRut 30
		if (UIController.BButton(31618, StartXItem + 36 + 100 + 70 + (28 * nCount), (StartYItem + (n * KhoangCach)) + 25, 25, 22, 25, 22, 3, state))
		{
			NewBankSendGS(eRut30, r);
		}
		CustomFont.Draw((HFONT)pFontNormal, StartXItem + 36 + 100 + 70 + (28 * nCount++), (StartYItem + (n * KhoangCach)) + 30, 0xFFFFFFBE, 0x0, 26, 0, 3, "30");
		//==ButtonRut All
		if (UIController.BButton(31618, StartXItem + 36 + 100 + 70 + (28 * nCount), (StartYItem + (n * KhoangCach)) + 25, 25, 22, 25, 22, 3, state))
		{
			NewBankSendGS(eRutAll, r);
		}
		CustomFont.Draw((HFONT)pFontNormal, StartXItem + 36 + 100 + 70 + (28 * nCount++), (StartYItem + (n * KhoangCach)) + 30, 0xFFFFFFBE, 0x0, 26, 0, 3, "***");
		//==ButtonGui All
		if (UIController.BButton(31617, StartXItem + 36 + 100 + 70 + (28 * nCount), (StartYItem + (n * KhoangCach)) + 25, 38, 23, 38, 23, 3, state))
		{
			NewBankSendGS(eGuiAll, r);
		}
		CustomFont.Draw((HFONT)pFontNormal, StartXItem + 36 + 100 + 70 + (28 * nCount++), (StartYItem + (n * KhoangCach)) + 30, 0xFFFFFFBE, 0x0, 38, 0, 3, "Enviar");
		//==Auto Pick
		if (gCBUtil.RenderCheckBox(StartXItem + 36 + 100 + 70 + (28 * nCount) + 20, (StartYItem + (n * KhoangCach)) + 28, 0xFFCC00C8, gInterface.mCListItemBank[r].AutoPick, ""))
		{
			NewBankSendGS(eAutoPick, r);
		}
		n++;
	}
	//Next Page
	RenderBitmap(32344, CenterX - (60 / 2), MaxY - 40, 60.f, 22.f, 0, 0, 80.f / 128.f, 30.f / 34.f, 1, 1, 0.0);

	CustomFont.Draw(CustomFont.FontBold, CenterX - (60 / 2), MaxY - 40 + 5, 0xffffffff, 0x0, 60, 0, 3, "%d / %d", PageBank + 1, (gInterface.mCListItemBank.size() / MaxPerPageBank) + 1);
	//

	//
	UIController.Button(32345, CenterX - (60 / 2) - 26, MaxY - 40, 20, 22, 20, 22, 3, state, BPagePrevAction);
	UIController.Button(32346, CenterX + (60 / 2) + 6, MaxY - 40, 20, 22, 20, 22, 3, state, BPageNextAction);



}//===Func calal Open or Offf Window
void Interface::OnOffWindowBank()
{
	if ((GetTickCount() - gCMacroUIEx.JEWELBANK_WINDOW->lastActionTime) < 500)
	{
		return;
	}
	gCMacroUIEx.JEWELBANK_WINDOW->lastActionTime = GetTickCount();
	gCMacroUIEx.JEWELBANK_WINDOW->onShow ^= 1;
}
#endif

// --- Estado global da janela News (compartilhado entre desenho e eventos) --- //
static float sNewsWindowPosX = 0.0f;  // Posição atual (X) da janela
static float sNewsWindowPosY = 0.0f;  // Posição atual (Y) da janela
static bool  sNewsWindowInitialized = false;
static bool  sNewsWindowDragging = false;
static float sNewsWindowDragOffsetX = 0.0f;
static float sNewsWindowDragOffsetY = 0.0f;

// Variáveis estáticas para controlar o estado de clique dos botões
static bool closeBtnPressed = false;
static bool backBtnPressed = false;

//=========================================================================
// Função de desenho da janela de News
//=========================================================================
void Interface::DrawNewsWindow()
{
	if (!gInterface.Data[eNEWS_MAIN].OnShow)
		return;

	// Garante que o cursor esteja ativo enquanto a janela estiver visível
	pSetCursorFocus = true;

	float MainWidth = 230.0f;
	float MainHeight = 313.0f;

	// Inicializa a posição da janela na primeira execução
	if (!sNewsWindowInitialized)
	{
		sNewsWindowPosX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
		sNewsWindowPosY = 100.0f;
		sNewsWindowInitialized = true;
	}

	// Usa a posição atualizada da janela
	float StartX = sNewsWindowPosX;
	float StartY = sNewsWindowPosY;

	// Limita a posição da janela para não ultrapassar a tela
	if (StartX < 0) StartX = 0;
	if (StartY < 0) StartY = 0;
	if (StartX + MainWidth > MAX_WIN_WIDTH) StartX = MAX_WIN_WIDTH - MainWidth;
	if (StartY + MainHeight > MAX_WIN_HEIGHT) StartY = MAX_WIN_HEIGHT - MainHeight;

	// ---------------------------------------------------------------
	// Controle de Drag & Drop – a janela poderá ser movida se o
	// clique ocorrer na área do layout que não esteja sobre um controle interativo.
	// ---------------------------------------------------------------
	if (!sNewsWindowDragging &&
		(pCursorX >= StartX && pCursorX <= (StartX + MainWidth) &&
			pCursorY >= StartY && pCursorY <= (StartY + MainHeight)))
	{
		// Verifica se o clique ocorreu sobre algum elemento interativo:
		bool interactiveZone = false;

		// Aqui NÃO usamos IsWorkZone1(index) para os botões, pois queremos usar
		// os retângulos calculados dinamicamente.
		if (IsWorkZone1(StartX + MainWidth - this->Data[eNEWS_CLOSE].Width,
			StartY + this->Data[eNEWS_TITLE].Height + this->Data[eNEWS_CLOSE].Height + 2,
			StartX + MainWidth,
			StartY + this->Data[eNEWS_TITLE].Height + 2 * this->Data[eNEWS_CLOSE].Height + 2))
			interactiveZone = true;

		// Verificação dos itens da lista de notícias (área interativa)
		for (int i = 0; i < gNewsBoard.m_LoadedCount; i++)
		{
			if (IsWorkZone1(StartX + 30, StartY + 40 + (i * 21),
				StartX + 200, StartY + 60 + (i * 21)))
			{
				interactiveZone = true;
				break;
			}
		}

		// Se não estiver sobre um controle interativo, inicia o drag
		if (!interactiveZone && (GetAsyncKeyState(VK_LBUTTON) & 0x8000))
		{
			sNewsWindowDragOffsetX = pCursorX - StartX;
			sNewsWindowDragOffsetY = pCursorY - StartY;
			sNewsWindowDragging = true;
		}
	}

	// Enquanto estiver arrastando, atualiza as coordenadas da janela
	if (sNewsWindowDragging)
	{
		if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
		{
			StartX = pCursorX - sNewsWindowDragOffsetX;
			StartY = pCursorY - sNewsWindowDragOffsetY;

			// Limita a posição da janela para não ultrapassar a tela
			if (StartX < 0) StartX = 0;
			if (StartY < 0) StartY = 0;
			if (StartX + MainWidth > MAX_WIN_WIDTH) StartX = MAX_WIN_WIDTH - MainWidth;
			if (StartY + MainHeight > MAX_WIN_HEIGHT) StartY = MAX_WIN_HEIGHT - MainHeight;
		}
		else
		{
			sNewsWindowDragging = false;
		}
		sNewsWindowPosX = StartX;
		sNewsWindowPosY = StartY;
	}

	// ---------------------------------------------------------------
	// Desenho do layout – todas as posições são calculadas com base em StartX e StartY
	// para se moverem junto com a janela
	// ---------------------------------------------------------------
	float MainCenter, ButtonX;

	if (gProtect.m_MainInfo.CustomInterfaceType == 3)
	{
		if (!this->Data[eNEWS_MAIN].OnShow)
			return;

		MainCenter = StartX + (MainWidth / 3);
		ButtonX = MainCenter - (29.0f / 2);

		// Desenho do cabeçalho, footer e fundo
		this->DrawGUI(eNEWS_TITLE, StartX, StartY);
		this->DrawGUI(eNEWS_FOOTER, StartX, StartY);
		gCentral.PrintDropBox(StartX, StartY, MainWidth, MainHeight, 0, 0);

		// --- Botão CLOSE ---
		float closeX = StartX + MainWidth - this->Data[eNEWS_CLOSE].Width;
		float closeY = StartY + this->Data[eNEWS_TITLE].Height - 64; // <-- aqui esta onde muda a posição Y do botão Close
		// Atualiza os dados internos do botão Close
		this->Data[eNEWS_CLOSE].X = closeX;
		this->Data[eNEWS_CLOSE].Y = closeY;
		// Desenha o botão Close
		this->DrawGUI(eNEWS_CLOSE, closeX, closeY);

		// Verifica se o cursor está dentro do retângulo do botão Close
		if (IsWorkZone1(closeX, closeY,
			closeX + this->Data[eNEWS_CLOSE].Width,
			closeY + this->Data[eNEWS_CLOSE].Height))
		{
			DWORD Color = eGray100;
			if (this->Data[eNEWS_CLOSE].OnClick)
				Color = eGray150;
			this->DrawColoredGUI(eNEWS_CLOSE, closeX, closeY, Color);
			this->DrawToolTip(closeX + 5, closeY + 25, "Close");
		}

		// --- Evento do botão CLOSE ---
		if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
		{
			if (IsWorkZone1(closeX, closeY,
				closeX + this->Data[eNEWS_CLOSE].Width,
				closeY + this->Data[eNEWS_CLOSE].Height))
			{
				closeBtnPressed = true;
				this->Data[eNEWS_CLOSE].OnClick = true;
			}
		}
		else // Se o botão é liberado...
		{
			if (closeBtnPressed)
			{
				closeBtnPressed = false;
				// Ação: fecha o layout de News
				this->CloseNewsWindow();
			}
			this->Data[eNEWS_CLOSE].OnClick = false;
		}

		this->DrawFormat(eGold, StartX + 10, StartY + 10, 210, 3, "News Board");

		if (this->Data[eNEWS_MAIN].Attribute == 0)
		{
			// Desenha os itens da lista de notícias
			for (int i = 0; i < gNewsBoard.m_LoadedCount; i++)
			{
				this->DrawGUI(eNEWS_INFOBG, StartX + 30, StartY + 40 + (i * 21));
				if (IsWorkZone1(StartX + 30, StartY + 40 + (i * 21),
					StartX + 200, StartY + 60 + (i * 21)))
				{
					this->DrawColoredGUI(eNEWS_INFOBG, StartX + 30, StartY + 40 + (i * 21),
						pMakeColor(255, 204, 20, 200));
				}
				this->DrawFormat(eGold, StartX + 18, StartY + 42 + (i * 21),
					65, 3, gNewsBoard.m_Data[i].Title.Date);
				this->DrawFormat(eOrange, StartX + 18, StartY + 48 + (i * 21),
					65, 3, gNewsBoard.m_Data[i].Title.Time);
				this->DrawFormat(eWhite, StartX + 80, StartY + 45 + (i * 21),
					190, 1, gNewsBoard.m_Data[i].Title.Text);
			}
			this->DrawFormat(eBlue, StartX + 8, StartY + 30, 210, 3,
				"Last refresh: %d min. ago", gNewsBoard.m_LastRefreshMin);
		}
		else
		{
			BYTE ID = this->Data[eNEWS_MAIN].Attribute - 10;

			this->DrawGUI(eNEWS_INFOBG, StartX + 30, StartY + 40);
			this->DrawFormat(eGold, StartX + 18, StartY + 42, 65, 3, gNewsBoard.m_Data[ID].Title.Date);
			this->DrawFormat(eOrange, StartX + 18, StartY + 48, 65, 3, gNewsBoard.m_Data[ID].Title.Time);
			this->DrawFormat(eWhite, StartX + 80, StartY + 45, 190, 1, gNewsBoard.m_Data[ID].Title.Text);
			this->DrawFormat(eWhite, StartX + 15, StartY + 70, 200, 1, gNewsBoard.m_Data[ID].Text);

			// --- Botão BACK (detail view) ---
			float backX = ButtonX;
			float backY = StartY + 251; // Posição fixa para o botão Back
			this->DrawGUI(eNEWS_BACK, backX, backY);
			this->Data[eNEWS_BACK].X = backX;
			this->Data[eNEWS_BACK].Y = backY;
			this->DrawFormat(eWhite, StartX + 8, backY + 10, 210, 3, "Back");
			this->DrawGUI(eNEWS_DIV, StartX, StartY + 231);

			// Verifica se o cursor está exatamente dentro da área do botão Back
			if (IsWorkZone1(backX, backY,
				backX + this->Data[eNEWS_BACK].Width,
				backY + this->Data[eNEWS_BACK].Height))
			{
				DWORD Color = eGray100;
				if (this->Data[eNEWS_BACK].OnClick)
					Color = eGray150;
				this->DrawColoredGUI(eNEWS_BACK, backX, backY, Color);
			}
			// --- Evento do botão BACK ---
			if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
			{
				if (IsWorkZone1(backX, backY,
					backX + this->Data[eNEWS_BACK].Width,
					backY + this->Data[eNEWS_BACK].Height))
				{
					backBtnPressed = true;
					this->Data[eNEWS_BACK].OnClick = true;
				}
			}
			else
			{
				if (backBtnPressed)
				{
					backBtnPressed = false;
					// Ação: retorna da tela de detalhe para a lista
					this->Data[eNEWS_MAIN].Attribute = 0;
				}
				this->Data[eNEWS_BACK].OnClick = false;
			}

			this->DrawFormat(eBlue, StartX + 8, StartY + 30, 210, 3,
				"Last page refresh: %d min. ago", gNewsBoard.m_Data[ID].LastRefreshMin);
		}
	}
	else  // Layout padrão
	{
		if (!this->Data[eNEWS_MAIN].OnShow)
			return;

		MainCenter = StartX + (MainWidth / 3);
		ButtonX = MainCenter - (29.0f / 2);

		this->DrawGUI(eNEWS_MAIN, StartX, StartY + 2);
		this->DrawGUI(eNEWS_TITLE, StartX, StartY);
		float newFrameY = this->DrawRepeatGUI(eNEWS_FRAME, StartX, StartY + 67.0, 13);
		this->DrawGUI(eNEWS_FOOTER, StartX, newFrameY);

		// --- Botão CLOSE ---
		float closeX = StartX + MainWidth - this->Data[eNEWS_CLOSE].Width;
		float closeY = StartY + this->Data[eNEWS_TITLE].Height - 64; // <-- aqui esta onde muda a posição Y do botão Close
		this->Data[eNEWS_CLOSE].X = closeX;
		this->Data[eNEWS_CLOSE].Y = closeY;
		this->DrawGUI(eNEWS_CLOSE, closeX, closeY);
		if (IsWorkZone1(closeX, closeY,
			closeX + this->Data[eNEWS_CLOSE].Width,
			closeY + this->Data[eNEWS_CLOSE].Height))
		{
			DWORD Color = eGray100;
			if (this->Data[eNEWS_CLOSE].OnClick)
				Color = eGray150;
			this->DrawColoredGUI(eNEWS_CLOSE, closeX, closeY, Color);
			this->DrawToolTip(closeX + 5, closeY + 25, "Close");
		}

		// --- Evento do botão CLOSE ---
		if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
		{
			if (IsWorkZone1(closeX, closeY,
				closeX + this->Data[eNEWS_CLOSE].Width,
				closeY + this->Data[eNEWS_CLOSE].Height))
			{
				closeBtnPressed = true;
				this->Data[eNEWS_CLOSE].OnClick = true;
			}
		}
		else
		{
			if (closeBtnPressed)
			{
				closeBtnPressed = false;
				// Fecha o layout News
				this->CloseNewsWindow();
			}
			this->Data[eNEWS_CLOSE].OnClick = false;
		}

		this->DrawFormat(eGold, StartX + 10, StartY + 10, 210, 3, "News Board");

		if (this->Data[eNEWS_MAIN].Attribute == 0)
		{
			for (int i = 0; i < gNewsBoard.m_LoadedCount; i++)
			{
				this->DrawGUI(eNEWS_INFOBG, StartX + 30, StartY + 40 + (i * 21));
				if (IsWorkZone1(StartX + 30, StartY + 40 + (i * 21),
					StartX + 200, StartY + 60 + (i * 21)))
				{
					this->DrawColoredGUI(eNEWS_INFOBG, StartX + 30, StartY + 40 + (i * 21),
						pMakeColor(255, 204, 20, 200));
				}
				this->DrawFormat(eGold, StartX + 18, StartY + 42 + (i * 21),
					65, 3, gNewsBoard.m_Data[i].Title.Date);
				this->DrawFormat(eOrange, StartX + 18, StartY + 48 + (i * 21),
					65, 3, gNewsBoard.m_Data[i].Title.Time);
				this->DrawFormat(eWhite, StartX + 80, StartY + 45 + (i * 21),
					190, 1, gNewsBoard.m_Data[i].Title.Text);
			}
			this->DrawFormat(eBlue, StartX + 8, StartY + 30, 210, 3,
				"Last refresh: %d min. ago", gNewsBoard.m_LastRefreshMin);
		}
		else
		{
			BYTE ID = this->Data[eNEWS_MAIN].Attribute - 10;
			this->DrawGUI(eNEWS_INFOBG, StartX + 30, StartY + 40);
			this->DrawFormat(eGold, StartX + 18, StartY + 42, 65, 3, gNewsBoard.m_Data[ID].Title.Date);
			this->DrawFormat(eOrange, StartX + 18, StartY + 48, 65, 3, gNewsBoard.m_Data[ID].Title.Time);
			this->DrawFormat(eWhite, StartX + 80, StartY + 45, 190, 1, gNewsBoard.m_Data[ID].Title.Text);
			this->DrawFormat(eWhite, StartX + 15, StartY + 70, 200, 1, gNewsBoard.m_Data[ID].Text);

			// --- Botão BACK (layout padrão) ---
			float backX = ButtonX;
			float backY = newFrameY + 10;
			this->DrawGUI(eNEWS_BACK, backX, backY);
			this->Data[eNEWS_BACK].X = backX;
			this->Data[eNEWS_BACK].Y = backY;
			this->DrawFormat(eWhite, StartX + 8, backY + 10, 210, 3, "Back");
			this->DrawGUI(eNEWS_DIV, StartX, newFrameY - 10);

			if (IsWorkZone1(backX, backY,
				backX + this->Data[eNEWS_BACK].Width,
				backY + this->Data[eNEWS_BACK].Height))
			{
				DWORD Color = eGray100;
				if (this->Data[eNEWS_BACK].OnClick)
					Color = eGray150;
				this->DrawColoredGUI(eNEWS_BACK, backX, backY, Color);
			}
			// --- Evento do botão BACK ---
			if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
			{
				if (IsWorkZone1(backX, backY,
					backX + this->Data[eNEWS_BACK].Width,
					backY + this->Data[eNEWS_BACK].Height))
				{
					backBtnPressed = true;
					this->Data[eNEWS_BACK].OnClick = true;
				}
			}
			else
			{
				if (backBtnPressed)
				{
					backBtnPressed = false;
					// Ação: retorna da tela de detalhe para a lista
					this->Data[eNEWS_MAIN].Attribute = 0;
				}
				this->Data[eNEWS_BACK].OnClick = false;
			}
			this->DrawFormat(eBlue, StartX + 8, StartY + 30, 210, 3,
				"Last page refresh: %d min. ago", gNewsBoard.m_Data[ID].LastRefreshMin);
		}
	}
}

//=========================================================================
// Funções de eventos – utilizam as posições atualizadas para o cálculo das zonas clicáveis
//=========================================================================

bool Interface::EventNewsWindow_Main(DWORD Event)
{
	float MainWidth = 230.0f;
	float MainHeight = 313.0f;
	// Usa as posições atualizadas da janela
	float StartX = sNewsWindowPosX;
	float StartY = sNewsWindowPosY;

	// Verifica cliques na lista de notícias
	for (int i = 0; i < gNewsBoard.m_LoadedCount; i++)
	{
		if (this->IsWorkZone1(StartX + 30, StartY + 40 + (i * 21),
			StartX + 200, StartY + 60 + (i * 21)))
		{
			if (Event == WM_LBUTTONDOWN && this->Data[eNEWS_MAIN].Attribute == 0)
			{
				// Aqui está a mudança principal: definimos o atributo e requisitamos
				// o item, mas não retornamos imediatamente
				this->Data[eNEWS_MAIN].Attribute = i + 10;
				gNewsBoard.ReqOpenItem(i);
				return true; // Retorna true para indicar que o evento foi processado
			}
		}
	}

	// Não chame diretamente estes eventos aqui
	// Deixe o sistema de eventos principal lidar com eles
	// this->EventNewsWindow_Close(Event);
	// this->EventNewsWindow_Back(Event);

	return true;
}

// Modifique a função EventNewsWindow_Close para:
bool Interface::EventNewsWindow_Close(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = CurrentTick - this->Data[eNEWS_CLOSE].EventTick;

	if (!this->Data[eNEWS_MAIN].OnShow || !IsWorkZone(eNEWS_CLOSE))
		return false;

	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eNEWS_CLOSE].OnClick = true;
		return true;
	}

	if (Event == WM_LBUTTONUP && this->Data[eNEWS_CLOSE].OnClick)
	{
		this->Data[eNEWS_CLOSE].OnClick = false;

		if (Delay < 500)
			return false;

		this->Data[eNEWS_CLOSE].EventTick = GetTickCount();
		this->Data[eNEWS_MAIN].Attribute = 0;
		this->CloseNewsWindow();
		return true;
	}

	return false;
}

//=========================================================================
// Função de evento para o botão Back – as coordenadas são recalculadas de acordo
// com a posição atual da janela para que o clique seja reconhecido em qualquer local.
//=========================================================================
bool Interface::EventNewsWindow_Back(DWORD Event)
{
	if (!this->Data[eNEWS_MAIN].OnShow || this->Data[eNEWS_MAIN].Attribute == 0)
		return false;

	float MainWidth = 230.0f;
	float StartX = sNewsWindowPosX;
	float StartY = sNewsWindowPosY;
	float MainCenter = StartX + (MainWidth / 3);
	float ButtonX = MainCenter - (29.0f / 2);

	// Calcular a posição do botão Back com base no tipo de interface
	float backX, backY;
	if (gProtect.m_MainInfo.CustomInterfaceType == 3) {
		backX = ButtonX;
		backY = StartY + 251;
	}
	else {
		// Para o layout padrão, precisamos calcular a posição Y corretamente
		// Esta é uma aproximação, ajuste conforme necessário
		float newFrameY = StartY + 67.0 + (13 * 18); // Estimativa da posição do frame
		backX = ButtonX;
		backY = newFrameY + 10;
	}

	// Verifica se o clique está na área do botão Back
	if (!IsWorkZone1(backX, backY,
		backX + this->Data[eNEWS_BACK].Width,
		backY + this->Data[eNEWS_BACK].Height))
		return false;

	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eNEWS_BACK].OnClick = true;
		return true;
	}

	if (Event == WM_LBUTTONUP && this->Data[eNEWS_BACK].OnClick)
	{
		this->Data[eNEWS_BACK].OnClick = false;
		this->Data[eNEWS_MAIN].Attribute = 0;
		return true;
	}

	return false;
}



