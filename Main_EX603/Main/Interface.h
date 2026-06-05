#pragma once

#include "stdafx.h"
#include "import.h"
#include "Protect.h"

#define MAX_OBJECT 	600
#define MAX_WIN_WIDTH 640
#define MAX_WIN_HEIGHT 480
#define MAX_WINDOW_EX 100

#define pDrawInterfaceNumBer   ((double(__stdcall*)(float X, float Y, int num, float size)) 0x854FE0)

#define GMT (24 + (gProtect.m_MainInfo.TIME_GMT))

enum ObjectID
{
	eFlag01=1,
	eFlag02,
	eFlag03,
	eFlag04,
	eFlag05,
	eFlag06,
	eFlag07,
	eFlag08,
	eFlag09,
	eFlag10,
	eFlag11,
	eFlag12,
	eFlag13,
	eFlag14,
	eFlag15,
	eFlag16,
	eFlag17,
	eFlag18,
	eFlag19,
	eFlag20,
	eFlag21,
	eFlag22,
	eTIME,
	eRankPANEL_MAIN,
	eRanking,
	eSAMPLEBUTTON,
	eSAMPLEBUTTON2,
	eVip_MAIN,
	eVip_TITLE,
	eVip_FRAME,
	eVip_FOOTER,
	eVip_DIV,
	eVip_CLOSE,
	eVip_BRONZE,
	eVip_SILVER,
	eVip_GOLD,
	eVip_PLATINUM,
	eVip_STATUS,
	eRanking_MAIN,
	eRanking_CLOSE,
	eRanking_TITLE,
	eRanking_FRAME,
	eRanking_FOOTER,
	eLogo,
	eEventTimePANEL_MAIN,
	eEventTime_MAIN,
	eEventTime_TITLE,
	eEventTime_CLOSE,
	eEventTime_FRAME,
	eEventTime_FOOTER,
	eMenu,
	eMenuBG,
	eMenu_MAIN,
	eMenu_TITLE,
	eMenu_FRAME,
	eMenu_FOOTER,
	eMenu_DIV,
	eMenu_CLOSE,
	eMenu_OPT1,
	eMenu_OPT2,
	eMenu_OPT3,
	eMenu_OPT4,
	eMenu_OPT5,
	eMenu_OPT6,
	eMenu_OPT20,
	eCommand_MAIN,
	eCommand_TITLE,
	eCommand_FRAME,
	eCommand_FOOTER,
	eCommand_DIV,
	eCommand_CLOSE,
	eOFFTRADE_JoB,
	eOFFTRADE_JoS,
	eOFFTRADE_JoC,
	eOFFTRADE_WCC,
	eOFFTRADE_WCP,
	eOFFTRADE_WCG,
	eOFFTRADE_OPEN,
	//Minimap
	ePLAYER_POINT,
	eNULL_MAP,
	eLORENCIA_MAP,
	eDUNGEON_MAP,
	eDEVIAS_MAP,
	eNORIA_MAP,
	eLOSTTOWER_MAP,
	eSTADIUM_MAP,
	eATLANS_MAP,
	eTarkan_MAP,
	eElbeland_MAP,
	eICARUS_MAP,
	eLANDOFTRIALS_MAP,
	eAIDA_MAP,
	eCRYWOLF_MAP,
	eKANTRU_MAP,
	eKANTRU3_MAP,
	eBARRACKS_MAP,
	eCALMNESS_MAP,
	eRAKLION_MAP,
	eVULCANUS_MAP,
	eKALRUTAN_MAP,
	eKALRUTAN2_MAP,
	eCONFIRM_MAIN,
	eCONFIRM_BTN_OK,
	eCONFIRM_BTN_CANCEL,
	eCONFIRM_TITLE,
	eCONFIRM_FRAME,
	eCONFIRM_FOOTER,
	eCONFIRM_DIV,
	eNextCommand,
	ePrevCommand,
	eNextEvent,
	ePrevEvent,
	ePrevWare,
	eNextWare,
//Ex700
	eMainEx700,
	eQuest,
	eCommunity,
	eSystem,
	//--custom
	eSTORE_CLOSE,
	ex_INFO_2,
	eADVANCE_STAT_INFO,
	//--s2
	eMainS2right,
	eMainS2middle,
	eMainS2left,
	eSkillBox,
	eDragonLeft,
	eDragonRight,
	eMain,
	eCharacter,
	eInventory,
	eParty,
	eFriend,
	eFastMenu,
	eShop,
	eGuild,
	eCommandWindow,
	//--custom money
	eMoney1,
	eMoney2,
	eMoney3,
	CharacterSelect,
	CharacterSelect_Button1,
	CharacterSelect_Button2,
	CharacterSelect_Button3,
	CharacterSelect_Button4,
	CharacterSelect_Button5,
	CharacterCreate_Button1,
	CharacterCreate_Button2,
	CharacterCreate_Button3,
	CharacterCreate_Button4,
	CharacterCreate_Button5,
	CharacterCreate_Button6,
	CharacterCreate_Button7,
	CharacterCreate_SEND,
	CharacterCreate_CANCEL,
	//chat
	chatbackground,
	MINIMAP_FRAME,
	MINIMAP_TIME_FRAME,
	MINIMAP_BUTTOM,
	ButtonSettings,
	ButtonStart,
	ButtonStop,
	ButtonStartAttack,
	eCamera3DInit,
	eCamera3DSwitch,
	strucMoveInv,
	eMainEx700Exp,
	RuudShopListIzq,
	RuudShopListDer,
	RuudShopWindow,
	RuudShopExit,
	eButton1,
	eButton2,
	eButton3,
	eButton4,
	eButton5,
	eJewelOfBank,
	eJewelOfBankPush,
	eJewelOfBankRemove,
	eJewelOfBankClose,

	OBJECT_RESET_MAIN,
	OBJECT_RESET_TITLE,
	OBJECT_RESET_FRAME,
	OBJECT_RESET_FOOTER,
	OBJECT_RESET_DIV,
	OBJECT_RESET_INFO_BG,
	OBJECT_RESET_MONEY_BG,
	OBJECT_RESET_CLOSE,
	OBJECT_RESET_FINISH,
	OBJECT_GRESET_MAIN,
	OBJECT_GRESET_TITLE,
	OBJECT_GRESET_FRAME,
	OBJECT_GRESET_FOOTER,
	OBJECT_GRESET_DIV,
	OBJECT_GRESET_INFO_BG,
	OBJECT_GRESET_MONEY_BG,
	OBJECT_GRESET_CLOSE,
	OBJECT_GRESET_FINISH,

	OBJECT_ACHIEVEMENTS_MAIN,
	OBJECT_ACHIEVEMENTS_PROGRESS_BG,
	OBJECT_ACHIEVEMENTS_PANEL,
	OBJECT_ACHIEVEMENTS_CLOSE,
	OBJECT_ACHIEVEMENTS_MISSIONS,
	OBJECT_ACHIEVEMENTS_DAMAGE,
	OBJECT_ACHIEVEMENTS_DEFENSE,
	OBJECT_ACHIEVEMENTS_LIFE,
	OBJECT_ACHIEVEMENTS_EXCELLENT,
	OBJECT_ACHIEVEMENTS_CRITICAL,

	OBJECT_WIN_QUEST_MAIN,
	OBJECT_WIN_QUEST_TITLE,
	OBJECT_WIN_QUEST_FRAME,
	OBJECT_WIN_QUEST_FOOTER,
	OBJECT_WIN_QUEST_DIV,
	OBJECT_WIN_QUEST_CLOSE,
	OBJECT_WIN_QUEST_TAB,
	OBJECT_WIN_QUEST_TAB1,
	OBJECT_WIN_QUEST_TAB2,
	OBJECT_WIN_QUEST_TAB3,
	OBJECT_WIN_QUEST_FINISH,
	OBJECT_WIN_QUEST_COUNT1,
	OBJECT_WIN_QUEST_COUNT2,
	OBJECT_WIN_QUEST_COUNT3,
	OBJECT_WIN_QUEST_INFOBG,
	OBJECT_WIN_QUEST_INFOBG2,
	OBJECT_WIN_QUEST_LINE1,
	OBJECT_WIN_QUEST_POINT1,
	OBJECT_WIN_QUEST_INFO,
	OBJECT_WIN_QUEST_INFOBG3,

	eCHANGINGCLASS_MAIN,
	eCHANGINGCLASS_TITLE,
	eCHANGINGCLASS_FRAME,
	eCHANGINGCLASS_FOOTER,
	eCHANGINGCLASS_DIV,
	eCHANGINGCLASS_INFOBG,
	eCHANGINGCLASS_MONEYBG,
	eCHANGINGCLASS_CLOSE,
	eCHANGINGCLASS_DW,
	eCHANGINGCLASS_DK,
	eCHANGINGCLASS_ELF,
	eCHANGINGCLASS_MG,
	eCHANGINGCLASS_DL,
	eCHANGINGCLASS_SUM,
	eCHANGINGCLASS_RF,

	ePARTYSETTINGS_MAIN,
	ePARTYSETTINGS_TITLE,
	ePARTYSETTINGS_FRAME,
	ePARTYSETTINGS_FOOTER,
	ePARTYSETTINGS_DIV,
	ePARTYSETTINGS_CLOSE,
	ePARTYSETTINGS_SYSTEM_ACTIVE,
	ePARTYSETTINGS_ONLY_GUILD,
	ePARTYSETTINGS_ONE_CLASS,
	ePARTYSETTINGS_DARK_WIZARD,
	ePARTYSETTINGS_DARK_KNIGHT,
	ePARTYSETTINGS_ELF,
	ePARTYSETTINGS_MAGIC_GLADIATOR,
	ePARTYSETTINGS_DARK_LORD,
	ePARTYSETTINGS_SUMMONER,
	ePARTYSETTINGS_RAGE_FIGHTER,
	ePARTYSETTINGS_LEVEL_MINUS,
	ePARTYSETTINGS_LEVEL_PLUS,
	ePARTYSETTINGS_OK,
	ePARTYSEARCH_LEFT,
	ePARTYSEARCH_RIGHT,

	ePARTYSEARCH_MAIN,
	ePARTYSEARCH_TITLE,
	ePARTYSEARCH_FRAME,
	ePARTYSEARCH_FOOTER,
	ePARTYSEARCH_DIV,
	ePARTYSEARCH_CLOSE,

	eNEWS_MAIN,
	eNEWS_TITLE,
	eNEWS_FRAME,
	eNEWS_FOOTER,
	eNEWS_DIV,
	eNEWS_INFOBG,
	eNEWS_CLOSE,
	eNEWS_BACK,

	ePanelWindow,
	eLayout_MAIN,
	eLayout_CLOSE,
	eLayout_BACK,
	eLayout_FORWARD,

	eWAREHOUSE,
	eWAREHOUSE1,
	eWAREHOUSE_MAIN,
	eWAREHOUSE_TITLE,
	eWAREHOUSE_FRAME,
	eWAREHOUSE_FOOTER,
	eWAREHOUSE_DIV,
	eWAREHOUSE_CLOSE,
	eWAREHOUSE_NUM1,
	eWAREHOUSE_NUM2,
	eWAREHOUSE_NUM3,
	eWAREHOUSE_NUM4,
	eWAREHOUSE_NUM5,
	eWAREHOUSE_NUM6,
	eWAREHOUSE_NUM7,
	eWAREHOUSE_NUM8,
	eWAREHOUSE_NUM9,
	eWAREHOUSE_NUM10,
	eWAREHOUSE_NUM11,
	eWAREHOUSE_NUM12,
	eWAREHOUSE_NUM13,
	eWAREHOUSE_NUM14,
	eWAREHOUSE_NUM15,
	eWAREHOUSE_NUM16,
	eWAREHOUSE_NUM17,
	eWAREHOUSE_NUM18,
	eWAREHOUSE_NUM19,
	eWAREHOUSE_NUM20,
	eWAREHOUSE_NUM21,
	eWAREHOUSE_NUM22,
	eWAREHOUSE_NUM23,
	eWAREHOUSE_NUM24,
	eWAREHOUSE_NUM25,
	eWAREHOUSE_NUM26,
	eWAREHOUSE_NUM27,
	eWAREHOUSE_NUM28,
	eWAREHOUSE_NUM29,
	eWAREHOUSE_NUM30,
	eWAREHOUSE_NUM31,
	eWAREHOUSE_NUM32,
	eWAREHOUSE_NUM33,
	eWAREHOUSE_NUM34,
	eWAREHOUSE_NUM35,
	eWAREHOUSE_NUM36,
	eWAREHOUSE_NUM37,
	eWAREHOUSE_NUM38,
	eWAREHOUSE_NUM39,
	eWAREHOUSE_NUM40,
	eWAREHOUSE_NUM41,
	eWAREHOUSE_NUM42,
	eWAREHOUSE_NUM43,
	eWAREHOUSE_NUM44,
	eWAREHOUSE_NUM45,
	eWAREHOUSE_NUM46,
	eWAREHOUSE_NUM47,
	eWAREHOUSE_NUM48,
	eWAREHOUSE_NUM49,
	eWAREHOUSE_NUM50,
	eWAREHOUSE_NUM51,
	eWAREHOUSE_NUM52,
	eWAREHOUSE_NUM53,
	eWAREHOUSE_NUM54,
	eWAREHOUSE_NUM55,
	eWAREHOUSE_NUM56,
	eWAREHOUSE_NUM57,
	eWAREHOUSE_NUM58,
	eWAREHOUSE_NUM59,
	eWAREHOUSE_NUM60,
	eWAREHOUSE_NUM61,
	eWAREHOUSE_NUM62,
	eWAREHOUSE_NUM63,
	eWAREHOUSE_NUM64,
	eWAREHOUSE_NUM65,
	eWAREHOUSE_NUM66,
	eWAREHOUSE_NUM67,
	eWAREHOUSE_NUM68,
	eWAREHOUSE_NUM69,
	eWAREHOUSE_NUM70,
	eWAREHOUSE_NUM71,
	eWAREHOUSE_NUM72,
	eWAREHOUSE_NUM73,
	eWAREHOUSE_NUM74,
	eWAREHOUSE_NUM75,
	eWAREHOUSE_NUM76,
	eWAREHOUSE_NUM77,
	eWAREHOUSE_NUM78,
	eWAREHOUSE_NUM79,
	eWAREHOUSE_NUM80,
	eWAREHOUSE_NUM81,
	eWAREHOUSE_NUM82,
	eWAREHOUSE_NUM83,
	eWAREHOUSE_NUM84,
	eWAREHOUSE_NUM85,
	eWAREHOUSE_NUM86,
	eWAREHOUSE_NUM87,
	eWAREHOUSE_NUM88,
	eWAREHOUSE_NUM89,
	eWAREHOUSE_NUM90,
	eWAREHOUSE_NUM91,
	eWAREHOUSE_NUM92,
	eWAREHOUSE_NUM93,
	eWAREHOUSE_NUM94,
	eWAREHOUSE_NUM95,
	eWAREHOUSE_NUM96,
	eWAREHOUSE_NUM97,
	eWAREHOUSE_NUM98,
	eWAREHOUSE_NUM99,
	eWAREHOUSE_NUM100,
	eWAREHOUSE_NUM101,
	eWAREHOUSE_NUM102,
	eWAREHOUSE_NUM103,
	eWAREHOUSE_NUM104,
	eWAREHOUSE_NUM105,
	eWAREHOUSE_NUM106,
	eWAREHOUSE_NUM107,
	eWAREHOUSE_NUM108,
	eWAREHOUSE_NUM109,
	eWAREHOUSE_NUM110,
	eWAREHOUSE_NUM111,
	eWAREHOUSE_NUM112,
	eWAREHOUSE_NUM113,
	eWAREHOUSE_NUM114,
	eWAREHOUSE_NUM115,
	eWAREHOUSE_NUM116,
	eWAREHOUSE_NUM117,
	eWAREHOUSE_NUM118,
	eWAREHOUSE_NUM119,
	eWAREHOUSE_NUM120,
	eWAREHOUSE_NUM121,
	eWAREHOUSE_NUM122,
	eWAREHOUSE_NUM123,
	eWAREHOUSE_NUM124,
	eWAREHOUSE_NUM125,
	eWAREHOUSE_NUM126,
	eWAREHOUSE_NUM127,
	eWAREHOUSE_NUM128,
	eWAREHOUSE_NUM129,
	eWAREHOUSE_NUM130,
	eWAREHOUSE_NUM131,
	eWAREHOUSE_NUM132,
	eWAREHOUSE_NUM133,
	eWAREHOUSE_NUM134,
	eWAREHOUSE_NUM135,
	eWAREHOUSE_NUM136,
	eWAREHOUSE_NUM137,
	eWAREHOUSE_NUM138,
	eWAREHOUSE_NUM139,
	eWAREHOUSE_NUM140,
	eWAREHOUSE_NUM141,
	eWAREHOUSE_NUM142,
	eWAREHOUSE_NUM143,
	eWAREHOUSE_NUM144,
	eWAREHOUSE_NUM145,
	eWAREHOUSE_NUM146,
	eWAREHOUSE_NUM147,
	eWAREHOUSE_NUM148,
	eWAREHOUSE_NUM149,
	eWAREHOUSE_NUM150,
	eWAREHOUSE_NUM151,
	eWAREHOUSE_NUM152,
	eWAREHOUSE_NUM153,
	eWAREHOUSE_NUM154,
	eWAREHOUSE_NUM155,
	eWAREHOUSE_NUM156,
	eWAREHOUSE_NUM157,
	eWAREHOUSE_NUM158,
	eWAREHOUSE_NUM159,
	eWAREHOUSE_NUM160,

	eSTATSADD_MAIN,
	eSTATSADD_TITLE,
	eSTATSADD_FRAME,
	eSTATSADD_FOOTER,
	eSTATSADD_CLOSE,
	eSTATSADD_TEXTBOX01,
	eSTATSADD_STATBOX01,
	eSTATSADD_STATBOX02,
	eSTATSADD_STATBOX03,
	eSTATSADD_STATBOX04,
	eSTATSADD_STATBOX05,
	eSTATSADD_BTN_OK,
	eSTATSADD_STEP10,
	eSTATSADD_STEP100,
	eSTATSADD_STEP1000,

	eCHARINFO_BTN_STAT,

	eMAX_VALUE,

	//Siempre tiene que ser el último de la lista.
	eJewelBank_WITHDRAW,
};

//========================================================================================================================================
// Advanced Stats
//========================================================================================================================================
enum ObjWindowsEx
{
	exWinNews = 1,
	exWinReset = 2,
	exWinGrandReset = 3,
	exWinRanking = 4,
	exWinDonate = 5,
	exWinPremium = 6,
	exWinMiniMenu = 7,
	exWinSettings = 8,
	exWinPTSearchMaster = 9,
	exWinPTSearchUser = 10,
	exWinPersonalSearch = 12,
	exWinPersonalPrice = 13,
	exWinNPCBuffer,
	exWinSmithy,
	exWinSmithyCheck,
	exWinCheckOffAfk,
	exWinMarriage,
	exWinAddPoints,
	exWinAddResetPoint,
	exWinCustomMenu,
	exWinCustomMenuChangeClass,
	exWinDungeonSiege,
	exWinTeamVsTeam,
	exWinTeamVsTeamStatistic,
	exWinAchievements,
	exWinAchievementsPower,
	exWinTeleport,
	exWinTeleportEvo,
	exWinResetRage,
	exWinDonateCheck,
	exWinPKClear,
	exWinAccWarning,
	exWinAccMenu,
	exWinAccOption,
	exWinAccPC,
	exWinAccMessage,
	exWinAccNumber,
	exWinReferralMenu,
	exWinReferralSystem,
	exWinReferralSystem2,
	exWinQuest,
	exWinLottery,
	exWinItemMarket,
	exWinItemMarket2,
	exWinMenuV3,
	exWinStatsAdvance,
};

struct InterfaceElement
{
	DWORD	ModelID;
	float	Width;
	float	Height;
	float	X;
	float	Y;
	float	MaxX;
	float	MaxY;
	DWORD	EventTick;
	bool	OnClick;
	bool	OnShow;
	BYTE	Attribute;
	long	OpenedValue;
	BYTE	Speed;
	char	StatValue[20];
	bool	ByClose;
	bool	FirstLoad;
	
	float  curX;
    float	curY;
    bool	Hover;
	void Open()
	{
		this->OnShow = true; pSetCursorFocus = true;
		this->ByClose = false;
	};

	void Open(int Value, int Speed)
	{
		this->OnShow = true; pSetCursorFocus = true;
		this->OpenedValue = Value;
		this->Speed = Speed;
		this->ByClose = false;
		this->FirstLoad = true;
	};

	void Close()
	{
		this->OnShow = false;
		pSetCursorFocus = false;
		this->ByClose = false;
	};

	void Close(int Value, int Speed)
	{
		this->OnShow = false; pSetCursorFocus = false;
		this->OpenedValue = Value;
		this->Speed = Speed;
		this->ByClose = false;
	}

	void CloseAnimated(int Speed)
	{
		pSetCursorFocus = false;
		//this->OpenedValue = Value;
		this->Speed = Speed;
		this->ByClose = true;
	}

	bool Check()
	{
		return this->OnShow;
	}
};

#if(JEWELBANKVER2)
enum TypeRutGuiBank
{
	eRut1,
	eRut10,
	eRut20,
	eRut30,
	eRutAll,
	eGuiAll,
	eAutoPick,

};

#endif
#if(JEWELBANKVER2)
struct USER_BANK_DATA
{
	int ItemIndex;
	int ItemLevel;
	int ItemCount;
	int AutoPick;
	void Clear()
	{
		ItemIndex = -1;
		ItemLevel = 0;
		ItemCount = 0;
		AutoPick = 0;
	}
};
//==== Packer Rut Gui Ngoc
struct REQUEST_RUTGUIBANK
{
	PSBMSG_HEAD header; // C3:F3:03
	BYTE TypeSend;
	short IndexList;
};
#endif

class Interface
{
public:
	int ConfirmSlot;
	float PetY;
	float PetX;
	int lastReport;
	int frameCount;
	int frameRate;
	char FPS_REAL[30];
	void UPDATE_FPS();
	void guiMonitore();
	int iniciador;
	int msPing;
	int lastSend;
	int validar;
	char ServerPing[50];
	char ultimoPing[50];
	int ultimo_Ping;
	char ServerRTT[50];
	char ultimoRTT[50];
	int ultimo_RTT;
	InterfaceElement Data[MAX_OBJECT];
	int Page;
	int Count;
public:
	Interface();
	virtual ~Interface();
	void RenderObjectSystem();
	void RenderObjectSystem2();
	bool WareNext(DWORD Event);
	bool WarePrev(DWORD Event);
	static void LoadImages();
	static void LoadModels();
	static void Work();
//--
//-- System Windows
	void OpenVipWindow(){ this->Data[eVip_MAIN].OnShow = true; };
	void CloseVipWindow() { this->Data[eVip_MAIN].OnShow = false; }
	bool CheckVipWindow() { return this->Data[eVip_MAIN].OnShow; };
	void DrawVipWindow();
	bool EventVipWindow_Main(DWORD Event);
	bool EventVipWindow_Close(DWORD Event);
	bool EventVipWindow_Bronze(DWORD Event);
	bool EventVipWindow_Silver(DWORD Event);
	bool EventVipWindow_Gold(DWORD Event);
	bool EventVipWindow_Platinum(DWORD Event);
	bool EventVipWindow_StatusVip(DWORD Event);
	//--
	void DrawMenu();
	bool EventDrawMenu_Open(DWORD Event);
	void OpenMenuWindow() { this->Data[eMenu_MAIN].OnShow = true; };
	void CloseMenuWindow() {this->Data[eMenu_MAIN].OnShow = false; };
	bool CheckMenuWindow() { return this->Data[eMenu_MAIN].OnShow; };
	void DrawMenuOpen();
	bool EventDrawMenu_Close(DWORD Event);
	bool EventDrawMenu_Op1(DWORD Event);
	bool EventDrawMenu_Op2(DWORD Event);
	bool EventDrawMenu_Op3(DWORD Event);
	bool EventDrawMenu_Op4(DWORD Event);
	bool EventDrawMenu_Op5(DWORD Event);
	bool EventDrawMenu_Op6(DWORD Event);
	bool EventDrawMenu_Op20(DWORD Event);
	//--
	void DrawConfirmOpen();
	bool EventConfirm_OK(DWORD Event);
	bool EventConfirm_CANCEL(DWORD Event);
	void        WindowsKG();
//-- Funtions
	void BindObject(short ObjectID, DWORD ModelID, float Width, float Height, float X, float Y);
	void DrawGUI(short ObjectID, float PosX, float PosY);
	void DrawGUI2(short ObjectID, float PosX, float PosY);
	void DrawGUI3(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY);
	int DrawFormat(DWORD Color, int PosX, int PosY, int Width, int Align, LPCSTR Text, ...);
	void DrawIMG(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY);
	void ResetDrawIMG(short ObjectID);
	int DrawMessage(int Mode, LPCSTR Text, ...);
	void DrawItem(float PosX, float PosY, float Width, float Height, int ItemID, int Level, int Excl, int Anc, bool OnMouse);
	void DrawItem2(float PosX, float PosY, float Width, float Height, int ItemID, int Level, int Excl, int Anc, bool OnMouse);
	bool CheckWindow(int WindowID);
	int CloseWindow(int WindowID);
	int OpenWindow(int WindowID);
	bool IsWorkZone2(float X, float Y, float MaxX, float MaxY);
	bool IsWorkZone41(float x, float y, float x2, float y2);
	bool IsWorkZone69(float, float, float, float);
	bool IsWorkZone(short ObjectID);
	bool IsWorkZone1(short ObjectID);
	bool IsWorkZone1(float X, float Y, float MaxX, float MaxY);
	float GetResizeX(short ObjectID);
	int DrawToolTip(int X, int Y, LPCSTR Text, ...);
	float DrawRepeatGUI(short MonsterID, float X, float Y, int Count);
	float DrawRepeatGUIScale(short MonsterID, float X, float Y,float ScaleX, float ScaleY, int Count);
	void DrawColoredGUI(short ObjectID, float X, float Y, DWORD Color);
	void DrawButton(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY);
	void DrawButtonRender(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY);
	void DrawLogo(bool active);
	void CloseCustomWindow();
	//Mini Map
	void DrawMiniMap();
	bool MiniMapCheck();
	bool CombinedChecks();
	bool CheckMap();
	void SwitchMiniMap();
	// ex700
	void DrawInterfaceCustom();
	// s2
	void DrawInterfaceS2Menu();
	void DrawInterface97Menu();
	void EventNewInterface_All(DWORD Event);
	void EventNewInterface97_All(DWORD Event);
	void DrawCoord();
	void DrawInterfaceDragonLS3();
	void DrawInterfaceDragonRS3();
	// old interface
	void DrawInterfaceCustom1();
	void DrawInterfaceMenu1();
	void DrawCoord1();
	// Advanced Stats
	bool WindowEx[MAX_WINDOW_EX];
	bool CheckWindowEx(int WindowID);
	void DrawBarForm(float PosX,float PosY,float Width,float Height,GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
	//--
	void OpenConfig(int type);
	void SwitchCamera();
	void SwitchChatExpand();
	void CameraInit();
	bool Button(DWORD Event, int WinID, int ButtonID, bool Type);
	void DrawPing();
	void SendPingRecv();

	static void DrawItemToolTipText(void* item, int x, int y);
	static void DrawZenAndRud(int a1, int a2, int a3, int a4);

	void		OpenNewsWindow() { this->Data[eNEWS_MAIN].OnShow = true; pSetCursorFocus = true; };
	void		CloseNewsWindow() { this->Data[eNEWS_MAIN].OnShow = false; pSetCursorFocus = false; };
	bool		CheckNewsWindow() { return this->Data[eNEWS_MAIN].OnShow; };
	void		DrawNewsWindow();
	bool		EventNewsWindow_Main(DWORD Event);
	bool		EventNewsWindow_Close(DWORD Event);
	bool		EventNewsWindow_Back(DWORD Event);

	void		DrawWarehouseUI();
	void		EventWarehouseUI(DWORD Event);
	// ----
	void		DrawWarehouseWindow();
	void		EventWarehouseWindow_Main(DWORD Event);
	void		EventWarehouseWindow_Close(DWORD Event);
	// ----
	void		DrawStatsAddWindow();
	void		EventStatsAddWindow(DWORD Event);
	void		EventStatsAddWindow_Close(DWORD Event);
	void		SwitchStatsWindowState() { (Data[eSTATSADD_MAIN].OnShow == true) ? Data[eSTATSADD_MAIN].CloseAnimated(15) : Data[eSTATSADD_MAIN].Open(-226, 20); };
	// ----
	void		DrawChangingClassWindow();
	bool		EventChangingClassWindow_Main(DWORD Event);
	bool		EventChangingClassWindow_Close(DWORD Event);
	bool		EventChangingClassWindow_DW(DWORD Event);
	bool		EventChangingClassWindow_DK(DWORD Event);
	bool		EventChangingClassWindow_ELF(DWORD Event);
	bool		EventChangingClassWindow_MG(DWORD Event);
	bool		EventChangingClassWindow_DL(DWORD Event);
	bool		EventChangingClassWindow_SUM(DWORD Event);
	bool		EventChangingClassWindow_RF(DWORD Event);
	// ----
	void		DrawPartySettingsWindow();
	void		SwitchPartySettingsWindowState();
	bool		EventPartySettingsWindow_Main(DWORD Event);
	bool		EventPartySettingsWindow_Close(DWORD Event);
	bool		EventPartySettingsWindow_All(DWORD Event);
	// ----
	void		DrawPartySearchWindow();
	void		SwitchPartySearchWindowState() { (Data[ePARTYSEARCH_MAIN].OnShow == true) ? Data[ePARTYSEARCH_MAIN].Close() : Data[ePARTYSEARCH_MAIN].Open(); };
	void		EventPartySearchWindow_All(DWORD Event);
	// ----
	bool		ControlTextBox(KBDLLHOOKSTRUCT Hook);
	void		EventCharacterWindow(DWORD Event);

	void		DrawAnimatedGUI(short ObjectID, float X, float Y);
	void		DrawAnimatedButton(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY);
	void		DrawColoredAnimatedGUI(short ObjectID, float X, float Y, DWORD Color);
	void		DrawColoredButton(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY, DWORD Color);
	int			DrawToolTipEx(DWORD Color, int PosX, int PosY, int Width, int Height, int Align, LPCSTR Text, ...);
	void		DrawText(DWORD Color, int PosX, int PosY, int Width, int Align, LPCSTR Text, ...);
	bool		ButtonEx(DWORD Event, int ButtonID, bool Type);
	void		DrawMessageBox(LPCSTR Text, ...);
	//-- Party Bar ex700
	void		BarPartyNew();
	//-- Minimizar MiniMapa
	void		MiniMapMini();
	//-- Mover MiniMapa
	bool		IsWorkZone(float X, float Y, float MaxX, float MaxY, bool a5 = false);

	#if(JEWELBANKVER2)
	//bool RenderCheckBox(float PosX, float PosY, DWORD TextColor, bool Checkis, LPCSTR Text, ...);
	//void DrawItem3D(float PosX, float PosY, float Width, float Height, int ItemID, int Level, int ExtOption, int Ancient, bool PickUp, float Scale = 1.0f, bool Center = true);
	void DrawWindowJewelBankVer2();
	std::vector<USER_BANK_DATA> mCListItemBank;
	void OnOffWindowBank();

	bool IsMouseOver(float x, float y, float width, float height);

	bool IsMouseClicked();
	
#endif
	DWORD LockMouseMoveClick;
private:
	
};

void InitAllSeason();

extern Interface gInterface;