#include "stdafx.h"
#include "NewUiInterface.h"
#include "Defines.h"
#include "TMemory.h"
#include "User.h"
#include "Offset.h"
#include "Import.h"
#include "Util.h"
#include "Protect.h"
#include "Interface.h"
#include "Controller.h"

__declspec(naked) void DrawAGPosition1()
{
	static float AGPositionW = 14.0f;
	static float AGPositionH = 43.0f;
	static float AGPositionX = 485.5f;
	static float AGPositionY = 433.7f;
	static DWORD AGPosition_buff = 0x008102AD;
	_asm
	{	
	FLD DWORD PTR DS:[AGPositionW]
	FSTP DWORD PTR SS:[EBP-0x18]
	FLD DWORD PTR DS:[AGPositionH]
	FSTP DWORD PTR SS:[EBP-0x14]
	FLD DWORD PTR DS:[AGPositionX]
	FSTP DWORD PTR SS:[EBP-0x10]
	FLD DWORD PTR DS:[AGPositionY]
	FSTP DWORD PTR SS:[EBP-0x0C]
	jmp [AGPosition_buff]
	}
}
__declspec(naked) void DrawSDPosition1()
{
	static float SDPositionW = 14.0f;
	static float SDPositionH = 43.0f;
	static float SDPositionX = 142.0f;
	static float SDPositionY = 433.7f;
	static DWORD SDPosition_buff = 0x0081057D;
	_asm
	{	
	FLD DWORD PTR DS:[SDPositionW]
	FSTP DWORD PTR SS:[EBP-0x20]
	FLD DWORD PTR DS:[SDPositionH]
	FSTP DWORD PTR SS:[EBP-0x1C]
	FLD DWORD PTR DS:[SDPositionX]
	FSTP DWORD PTR SS:[EBP-0x10]
	FLD DWORD PTR DS:[SDPositionY]
	FSTP DWORD PTR SS:[EBP-0x0C] 
	jmp [SDPosition_buff]
	}
}
//--------------------------------------------
__declspec(naked) void DrawMANAPosition1()
{
	static float MANAPositionW = 52.0f;
	static float MANAPositionH = 60.0f;
	static float MANAPositionX = 430.7f;
	static float MANAPositionY = 417.0f;
	static DWORD MANAPosition_buff = 0x0080FFD0;
	_asm
	{	
	FLD DWORD PTR DS:[MANAPositionW]
	FSTP DWORD PTR SS:[EBP-0x20]
	FLD DWORD PTR DS:[MANAPositionX]
	FSTP DWORD PTR SS:[EBP-0x0C]
	FLD DWORD PTR DS:[MANAPositionH]
	FSTP DWORD PTR SS:[EBP-0x1C]
	FLD DWORD PTR DS:[MANAPositionY]
	FSTP DWORD PTR SS:[EBP-0x8]
	jmp [MANAPosition_buff]
	}
}
__declspec(naked) void DrawHPPosition1()
{
	static float HPPositionW = 52.0f;
	static float HPPositionH = 51.0f;
	static float HPPositionX = 163.0f;
	static float HPPositionY = 428.0f;
	static DWORD HPPosition_buff = 0x0080FD7C;
	_asm
	{             
	FLD DWORD PTR DS:[HPPositionW]
	FSTP DWORD PTR SS:[EBP-0x20]
	FLD DWORD PTR DS:[HPPositionX]
	FSTP DWORD PTR SS:[EBP-0x0C]
	FLD DWORD PTR DS:[HPPositionH]
	FSTP DWORD PTR SS:[EBP-0x1C]
	FLD DWORD PTR DS:[HPPositionY]
	FSTP DWORD PTR SS:[EBP-0x8]
	jmp [HPPosition_buff]
	}
}
//--------------------------------------------
__declspec(naked) void DrawUsingSkillPosition1()
{
	static float UsingSkillPositionX = 311.0f;
	static float UsingSkillPositionY = 447.0f;
	static float UsingSkillPositionW = 20.0f;
	static float UsingSkillPositionH = 28.0f;
	static DWORD UsingSkillPosition_buff = 0x00813900;
	_asm
	{
	FLD DWORD PTR DS:[UsingSkillPositionX]
	FSTP DWORD PTR SS:[EBP-0x8]
	FLD DWORD PTR DS:[UsingSkillPositionY]
	FSTP DWORD PTR SS:[EBP-0x4]
	FLD DWORD PTR DS:[UsingSkillPositionW]
	FSTP DWORD PTR SS:[EBP-0x18]
	FLD DWORD PTR DS:[UsingSkillPositionH]
	FSTP DWORD PTR SS:[EBP-0x14]
	jmp [UsingSkillPosition_buff]
	}
}
__declspec(naked) void DrawSkillClickPosition1()
{
	static float SkillClickPositionX = 310.0f;
	static float SkillClickPositionY = 445.0f;
	static float SkillClickPositionW = 25.0f;
	static float SkillClickPositionH = 32.0f;
	static DWORD SkillClickPosition_buff = 0x00812734;
	_asm
	{
	FLD DWORD PTR DS:[SkillClickPositionX]
	FSTP DWORD PTR SS:[EBP-0x8]
	FLD DWORD PTR DS:[SkillClickPositionY]
	FSTP DWORD PTR SS:[EBP-0x4]
	FLD DWORD PTR DS:[SkillClickPositionW]
	FSTP DWORD PTR SS:[EBP-0x20]
	FLD DWORD PTR DS:[SkillClickPositionH]
	FSTP DWORD PTR SS:[EBP-0x1C]
	jmp [SkillClickPosition_buff]
	}
}
//--------------------------------------------
__declspec(naked) void DrawSkillBarDrawPosition1()
{
	static float SkillBarDrawPositionX = 222.0f;
	static float SkillBarDrawPositionY = 480.0f;
	static float SkillBarDrawPositionW = 160.0f;
	static float SkillBarDrawPositionH = 38.0f;
	static DWORD SkillBarDrawPosition_buff = 0x00812968;
	_asm
	{	
	FLD DWORD PTR DS:[SkillBarDrawPositionX]
	FSTP DWORD PTR SS:[EBP-0x8]
	FLD DWORD PTR DS:[SkillBarDrawPositionY]
	FSTP DWORD PTR SS:[EBP-0x4]
	FLD DWORD PTR DS:[SkillBarDrawPositionW]
	FSTP DWORD PTR SS:[EBP-0x20]
	FLD DWORD PTR DS:[SkillBarDrawPositionH]
	FSTP DWORD PTR SS:[EBP-0x1C]
	jmp [SkillBarDrawPosition_buff]
	}
}
//--------------------------------------------
__declspec(naked) void DrawSkillSwitchDraw1()
{
	
	static float SkillSwitchDrawX = 385.0f;
	static float SkillSwitchDrawY = 350.0f;
	static float SkillSwitchDrawW = 32.0f;
	static float SkillSwitchDrawH = 38.0f;
	static float SkillSwitchDrawMW = 385.0f;
	static DWORD SkillSwitchDraw_buff = 0x008139CA;

	_asm
	{
		FLD DWORD PTR DS:[SkillSwitchDrawX]
		FSTP DWORD PTR SS:[EBP-0x8]
		FLD DWORD PTR DS:[SkillSwitchDrawY]
		FSTP DWORD PTR SS:[EBP-0x4]	
		FLD DWORD PTR DS:[SkillSwitchDrawW]
		FSTP DWORD PTR SS:[EBP-0x18]
		FLD DWORD PTR DS:[SkillSwitchDrawH]
		FSTP DWORD PTR SS:[EBP-0x14]
		FLD DWORD PTR DS:[SkillSwitchDrawMW]
		FSTP DWORD PTR SS:[EBP-0x24]
		jmp [SkillSwitchDraw_buff]

	}
}
__declspec(naked) void DrawSkillSwitchClick1()
{
	static float SkillSwitchDrawX = 385.0f;
	static float SkillSwitchDrawY = 350.0f;
	static float SkillSwitchDrawW = 32.0f;
	static float SkillSwitchDrawH = 38.0f;
	static float SkillSwitchDrawMW = 385.0f;
	static DWORD SkillSwitchClick_buff = 0x00812D69;

	_asm
	{
		FLD DWORD PTR DS:[SkillSwitchDrawX]
		FSTP DWORD PTR SS:[EBP-0x8]
		FLD DWORD PTR DS:[SkillSwitchDrawY]
		FSTP DWORD PTR SS:[EBP-0x4]
		FLD DWORD PTR DS:[SkillSwitchDrawW]
		FSTP DWORD PTR SS:[EBP-0x20]
		FLD DWORD PTR DS:[SkillSwitchDrawH]
		FSTP DWORD PTR SS:[EBP-0x1C]
		FLD DWORD PTR DS:[SkillSwitchDrawMW]
		FSTP DWORD PTR SS:[EBP-0x14]
		jmp [SkillSwitchClick_buff]
	}
}
//--------------------------------------------
__declspec(naked) void RavenSkillPos1()
{
	static float SkillRavenDrawX = 353.0f;
	static float SkillRavenDrawY = 312.0f;
	static DWORD SkillRavenDraw_buff = 0x00813CCE;

	_asm
	{
		FLD DWORD PTR DS:[SkillRavenDrawX]
		FSTP DWORD PTR SS:[EBP-0x8]
		FLD DWORD PTR DS:[SkillRavenDrawY]
		FSTP DWORD PTR SS:[EBP-0x4]
		jmp [SkillRavenDraw_buff]
	}
}

__declspec(naked) void RavenSkillClicPos1()
{
	static float SkillRavenClicDrawX = 353.0f;
	static float SkillRavenClicDrawY = 312.0f;
	static DWORD SkillRavenClicDraw_buff = 0x008130BC;

	_asm
	{
		FLD DWORD PTR DS:[SkillRavenClicDrawX]
		FSTP DWORD PTR SS:[EBP-0x8]
		FLD DWORD PTR DS:[SkillRavenClicDrawY]
		FSTP DWORD PTR SS:[EBP-0x4]
		jmp [SkillRavenClicDraw_buff]
	}
}
	
//--------------------------------------------
__declspec(naked) void DrawQPosition11()
{
	static float BarNumberY = 443.0f;
	static DWORD QPosition1_buff = 0x00895A4F;
	_asm
	{
	FLD DWORD PTR DS:[BarNumberY]
	FSTP DWORD PTR SS:[ESP]
	jmp [QPosition1_buff]
	}
}
__declspec(naked) void DrawQPosition21()
{
	static float QPosition2X = 230.0f;
	static DWORD QPosition2_buff = 0x00895A59;
	_asm
	{
	FLD DWORD PTR DS:[QPosition2X]
	FSTP DWORD PTR SS:[ESP]
	jmp [QPosition2_buff]
	}
}
__declspec(naked) void DrawQPosition31()
{
	static float BarPotionY = 453.0f;
	static DWORD QPosition3_buff = 0x00895A63;

	_asm
	{
		FLD DWORD PTR DS : [BarPotionY]
		FSTP DWORD PTR SS : [ESP]
		jmp[QPosition3_buff]
	}
}
__declspec(naked) void DrawQPosition41()
{
	static float QPosition4X = 222.0f;
	static DWORD QPosition4_buff = 0x00895A6D;

	_asm
	{
		FLD DWORD PTR DS : [QPosition4X]
		FSTP DWORD PTR SS : [ESP]
		jmp[QPosition4_buff]
	}
}
__declspec(naked) void DrawWPosition11()
{
	static float BarNumberY = 443.0f;
	static DWORD WPosition1_buff = 0x00895AC4;
	_asm
	{
	FLD DWORD PTR DS:[BarNumberY]
	FSTP DWORD PTR SS:[ESP]
	jmp [WPosition1_buff]
	}
}
__declspec(naked) void DrawWPosition21()
{
	static float WPosition2X = 261.0f;
	static DWORD WPosition2_buff = 0x00895ACE;
	_asm
	{
	FLD DWORD PTR DS:[WPosition2X]
	FSTP DWORD PTR SS:[ESP]
	jmp [WPosition2_buff]
	}
}
__declspec(naked) void DrawWPosition31()
{
	static float BarPotionY = 453.0f;
	static DWORD WPosition3_buff = 0x00895AD8;

	_asm
	{
		FLD DWORD PTR DS : [BarPotionY]
		FSTP DWORD PTR SS : [ESP]
		jmp[WPosition3_buff]
	}
}
__declspec(naked) void DrawWPosition41()
{
	static float WPosition4X = 250.0f;
	static DWORD WPosition4_buff = 0x00895AE2;

	_asm
	{
		FLD DWORD PTR DS : [WPosition4X]
		FSTP DWORD PTR SS : [ESP]
		jmp[WPosition4_buff]
	}
}
__declspec(naked) void DrawEPosition11()
{
	static float BarNumberY = 443.0f;
	static DWORD EPosition1_buff = 0x00895B39;
	_asm
	{
	FLD DWORD PTR DS:[BarNumberY]
	FSTP DWORD PTR SS:[ESP]
	jmp [EPosition1_buff]
	}
}
__declspec(naked) void DrawEPosition21()
{
	static float EPosition2X = 287.0f;
	static DWORD EPosition2_buff = 0x00895B43;
	_asm
	{
	FLD DWORD PTR DS:[EPosition2X]
	FSTP DWORD PTR SS:[ESP]
	jmp [EPosition2_buff]
	}
}
__declspec(naked) void DrawEPosition31()
{
	static float BarPotionY = 453.0f;
	static DWORD EPosition3_buff = 0x00895B4D;

	_asm
	{
		FLD DWORD PTR DS : [BarPotionY]
		FSTP DWORD PTR SS : [ESP]
		jmp[EPosition3_buff]
	}
}
__declspec(naked) void DrawEPosition41()
{
	static float EPosition4X = 278.0f;
	static DWORD EPosition4_buff = 0x00895B57;
	_asm
	{
	FLD DWORD PTR DS:[EPosition4X]
	FSTP DWORD PTR SS:[ESP]
	jmp [EPosition4_buff]
	}
}
__declspec(naked) void DrawNopRShortKey11()
{
	static DWORD RButtonAddress = 0x00895C0C;
	_asm{jmp RButtonAddress}
}
__declspec(naked) void DrawHPNumberPosition11()
{
	gInterface.DrawCoord1();
	static float HPNumberPositionX = 38.0f;
	static DWORD HPNumberPosition_buff = 0x0080FF1E;
	_asm
	{
	FADD DWORD PTR DS:[HPNumberPositionX]
	FSTP DWORD PTR SS:[EBP-0x19C]
	FLD DWORD PTR SS:[EBP-0x19C]
	jmp [HPNumberPosition_buff]
	}
}
__declspec(naked) void DrawMasterButton11()
{
	static DWORD MasterButtonAddress1 = 0x0077ED20;
	_asm
	{
		jmp [MasterButtonAddress1]
	}
}
__declspec(naked) void DrawHelperAll1()
{
	static DWORD HelperStopAddress1 = 0x007D28B4;
	_asm
	{
		jmp [HelperStopAddress1]
	}
}

//---------------------------------------------
//EXP
__declspec(naked) void DrawEXP11()
{
	static double Ancho = 221.0f;
	static double Alto = 432.5f;
	static double AnchoTex = 198.0f;
	static double AltoTex = 5.8f;
	static DWORD EXP1_buff = 0x00811408;
	
	_asm
	{
		FLD QWORD PTR DS:[Ancho]
		FSTP QWORD PTR SS:[EBP-0x10]
		FLD QWORD PTR DS:[Alto]
		FSTP QWORD PTR SS:[EBP-0x8]
		FLD DWORD PTR SS:[EBP-0x1B0]
		FMUL QWORD PTR DS:[AnchoTex]
		FSTP QWORD PTR SS:[EBP-0x28]
		FLD QWORD PTR DS:[AltoTex]
		FSTP QWORD PTR SS:[EBP-0x20]
		jmp [EXP1_buff]
	}
}

__declspec(naked) void DrawEXP21()
{
	static double Ancho = 221.0f;
	static double Alto = 432.5f;
	static double AnchoTex = 198.0f;
	static double AltoTex = 5.8f;
	static DWORD EXP2_buff = 0x00811552;
	_asm
	{
		FLD QWORD PTR DS:[Ancho]
		FSTP QWORD PTR SS:[EBP-0x10]
		FLD QWORD PTR DS:[Alto]
		FSTP QWORD PTR SS:[EBP-0x8]
		FLD DWORD PTR SS:[EBP-0x1C4]
		FMUL QWORD PTR DS:[AnchoTex]
		FSTP QWORD PTR SS:[EBP-0x28]
		FLD QWORD PTR DS:[AltoTex]
		FSTP QWORD PTR SS:[EBP-0x20]
		jmp [EXP2_buff]
	}
}

__declspec(naked) void DrawEXP31()
{
	static double Ancho = 221.0f;
	static double Alto = 432.5f;
	static double AnchoTex = 198.0f;
	static double AltoTex = 5.8f;
	static DWORD EXP3_buff = 0x00811719;
	
	_asm
	{
		FLD QWORD PTR DS:[Ancho]
		FSTP QWORD PTR SS:[EBP-0x10]
		FLD QWORD PTR DS:[Alto]
		FSTP QWORD PTR SS:[EBP-0x8]
		FLD DWORD PTR SS:[EBP-0x1B0]
		FMUL QWORD PTR DS:[AnchoTex]
		FSTP QWORD PTR SS:[EBP-0x28]
		FLD QWORD PTR DS:[AltoTex]
		FSTP QWORD PTR SS:[EBP-0x20]
		jmp [EXP3_buff]
	}
}

__declspec(naked) void DrawEXP41()
{
	static double Ancho = 221.0f;
	static double Alto = 432.5f;
	static double AnchoTex = 198.0f;
	static double AltoTex = 5.8f;
	static DWORD EXP4_buff = 0x0081181F;
	
	_asm
	{
		FLD QWORD PTR DS:[Ancho]
		FSTP QWORD PTR SS:[EBP-0x10]
		FLD QWORD PTR DS:[Alto]
		FSTP QWORD PTR SS:[EBP-0x8]
		FLD QWORD PTR DS:[AnchoTex]
		FSTP QWORD PTR SS:[EBP-0x28]
		FLD QWORD PTR DS:[AltoTex]
		FSTP QWORD PTR SS:[EBP-0x20]
		FLD QWORD PTR SS:[EBP-0x20]
		jmp [EXP4_buff]
	}
}

//EXP MASTER
__declspec(naked) void DrawEXPMASTER11()
{
	static double Ancho = 221.0f;
	static double Alto = 432.5f;
	static double AltoTex = 5.8f;
	static double AnchoTex = 198.0f;
	static DWORD EXPMASTER1_buff = 0x00810B6E;
	
	_asm
	{
		FLD QWORD PTR DS:[Ancho]
		FSTP QWORD PTR SS:[EBP-0x10]
		FLD QWORD PTR DS:[Alto]
		FSTP QWORD PTR SS:[EBP-0x8]
		FLD QWORD PTR SS:[EBP-0x58]
		FMUL QWORD PTR DS:[AnchoTex]
		FSTP QWORD PTR SS:[EBP-0x28]
		FLD QWORD PTR DS:[AltoTex]
		FSTP QWORD PTR SS:[EBP-0x20]
		jmp [EXPMASTER1_buff]
	}
}

__declspec(naked) void DrawEXPMASTER21()
{
	static double Ancho = 221.0f;
	static double Alto = 432.5f;
	static double AnchoTex = 198.0f;
	static double AltoTex = 5.8f;
	static DWORD EXPMASTER2_buff = 0x00810CB5;
	
	_asm
	{
		FLD QWORD PTR DS:[Ancho]
		FSTP QWORD PTR SS:[EBP-0x10]
		FLD QWORD PTR DS:[Alto]
		FSTP QWORD PTR SS:[EBP-0x8]
		FLD QWORD PTR SS:[EBP-0x88]
		FMUL QWORD PTR DS:[AnchoTex]
		FSTP QWORD PTR SS:[EBP-0x28]
		FLD QWORD PTR DS:[AltoTex]
		FSTP QWORD PTR SS:[EBP-0x20]
		jmp [EXPMASTER2_buff]
	}
}

__declspec(naked) void DrawEXPMASTER31()
{
	static double Ancho = 221.0f;
	static double Alto = 432.5f;
	static double AnchoTex = 198.0f;
	static double AltoTex = 5.8f;
	static DWORD EXPMASTER3_buff = 0x00810E79;
	
	_asm
	{
		FLD QWORD PTR DS:[Ancho]
		FSTP QWORD PTR SS:[EBP-0x10]
		FLD QWORD PTR DS:[Alto]
		FSTP QWORD PTR SS:[EBP-0x8]
		FLD QWORD PTR SS:[EBP-0x58]
		FMUL QWORD PTR DS:[AnchoTex]
		FSTP QWORD PTR SS:[EBP-0x28]
		FLD QWORD PTR DS:[AltoTex]
		FSTP QWORD PTR SS:[EBP-0x20]
		jmp [EXPMASTER3_buff]
	}
}

__declspec(naked) void DrawEXPMASTER41()
{
	static double Ancho = 221.0f;
	static double Alto = 432.5f;
	static double AnchoTex = 198.0f;
	static double AltoTex = 5.8f;
	static DWORD EXPMASTER4_buff = 0x00810F73;
	
	_asm
	{
		FLD QWORD PTR DS:[Ancho]
		FSTP QWORD PTR SS:[EBP-0x10]
		FLD QWORD PTR DS:[Alto]
		FSTP QWORD PTR SS:[EBP-0x8]
		FLD QWORD PTR DS:[AnchoTex]
		FSTP QWORD PTR SS:[EBP-0x28]
		FLD QWORD PTR DS:[AltoTex]
		FSTP QWORD PTR SS:[EBP-0x20]
		jmp [EXPMASTER4_buff]
	}
}

__declspec(naked) void DrawInterfaceS2DisableR1()
{
	static DWORD RButtonAddress = 0x00895C0C;
	_asm{jmp RButtonAddress}
}


bool isWorkZone1(int a1, int a2, int a3, int a4)
{
	
	if (gInterface.CheckWindow(ObjWindow::Inventory)){
		a3 -= 190;
		
	}
	if (gInterface.CheckWindow(ObjWindow::ExpandInventory)
		|| gInterface.CheckWindow(ObjWindow::ExpandWarehouse)){
		a3 -= 190;
	}
	if (gInterface.CheckWindow(ObjWindow::Warehouse)
		|| gInterface.CheckWindow(ObjWindow::Trade)
		|| gInterface.CheckWindow(ObjWindow::ChaosBox)){
		a3 -= 190;
	}
	else if (gInterface.CheckWindow(ObjWindow::Character)){
		a3 -= 190;
	}
	return pCursorX < a3 && pCursorY < a4;
}


//
__declspec(naked) void BackInventory1()
{
	static DWORD BoxColorContinue_buff = 0x0077FDAC;

	_asm
	{
	PUSH 255
	PUSH 199
	PUSH 110
	PUSH 30
	JMP [BoxColorContinue_buff]
	}
}
//

__declspec(naked) void PointInventory1()
{
	static DWORD BoxColorContinue_buff = 0x0077FD98;

	_asm
	{
	PUSH 255
	PUSH 0
	PUSH 0
	PUSH 0
	JMP [BoxColorContinue_buff]
	}
}
//Character
int RemakeCharacterWindow1(int a1)
{
  int v42; // ST24_4@1
  float green; // ST08_4@1
  float red; // ST04_4@1
  
  v42 = a1;
  green = (double)*(signed int *)(a1 + 20);
  red =   (double)*(signed int *)(a1 + 16);
  pDrawGUI(71352, red, green, 190.0, 433.0);
  		if(*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x74) > 0)
		{
		pDrawGUI(0x700020, 558, 57, 65.0, 11.0);
		}
//
  int DL = pGetCharClass(*(BYTE *)(oUserPreviewStruct + 19));
  if ( DL == 4 )
  {
  green = (double)*(signed int *)(a1 + 20);
  red = (double)*(signed int *)(a1 + 16);
  pDrawGUI(71291, red, green, 190.0, 433.0);
  		if(*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x74) > 0)
		{
		pDrawGUI(0x700020, 558, 57, 65.0, 11.0);
		}
  }

  int Class = pGetCharClass(*(BYTE *)(oUserPreviewStruct + 19));
  if ( Class == 3 || Class == 5 || Class == 6)
  {
  green = (double)*(signed int *)(a1 + 20);
  red = (double)*(signed int *)(a1 + 16);
  pDrawGUI(71292, red, green, 190.0, 433.0);
  		if(*(WORD*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x74) > 0)
		{
		pDrawGUI(0x700020, 558, 57, 65.0, 11.0);
		}
  }
//
  return a1;
}
//===========================
//-- SkillRenderizado
//===========================
bool Render_SkillFullMouser1(DWORD a1)
{
	bool result; // al@2
	unsigned __int8 v5; // ST4F_1@3
	int v62; // [sp+Ch] [bp-54h]@1
	int v64; // [sp+18h] [bp-48h]@84
	unsigned __int16 v66; // [sp+24h] [bp-3Ch]@53
	signed int v67; // [sp+2Ch] [bp-34h]@40
	signed int v68; // [sp+30h] [bp-30h]@40
	unsigned __int16 v69; // [sp+38h] [bp-28h]@76
	float v70; // [sp+40h] [bp-20h]@5
	float v71; // [sp+40h] [bp-20h]@28
	float v72; // [sp+40h] [bp-20h]@40
	float v73; // [sp+40h] [bp-20h]@73
	float v74; // [sp+40h] [bp-20h]@116
	float v75; // [sp+44h] [bp-1Ch]@5
	float v76; // [sp+44h] [bp-1Ch]@28
	float v77; // [sp+44h] [bp-1Ch]@73
	char v78; // [sp+4Bh] [bp-15h]@73
	float v79; // [sp+4Ch] [bp-14h]@73
	signed int v80; // [sp+50h] [bp-10h]@73
	int v81; // [sp+54h] [bp-Ch]@73
	float v82; // [sp+58h] [bp-8h]@5
	float v83; // [sp+58h] [bp-8h]@28
	float v84; // [sp+58h] [bp-8h]@40
	float v85; // [sp+58h] [bp-8h]@85
	float v86; // [sp+58h] [bp-8h]@116
	float v87; // [sp+5Ch] [bp-4h]@5
	float v88; // [sp+5Ch] [bp-4h]@28
	float v89; // [sp+5Ch] [bp-4h]@40
	float v90; // [sp+5Ch] [bp-4h]@73
	float v91; // [sp+5Ch] [bp-4h]@116*/
	signed int j; // [sp+10h] [bp-50h]@116
	signed int i; // [sp+20h] [bp-40h]@73

	v62 = a1;
	if ( pCheckEffectPlayer((DWORD *)(*(DWORD *)0x7BC4F04 + 1260), 98) )
	{
		*(BYTE *)(v62 + 64) = 0;
		result = 1;
	}
	else
	{
		v5 = *(BYTE *)(*(DWORD *)0x8128AC8 + 118);
		*(BYTE *)(v62 + 65) = 0;
		if ( (signed int)v5 > 0 )
		{
			//-- skill en uso
			v82 = 310.0;
			v87 = 445.0f;
			v70 = 25.0f;
			v75 = 32.0f;
			if ( *(DWORD *)(v62 + 80) || *(BYTE *)0x8793384 || pCheckMouseOver(v82, v87, v70, v75) != 1 )
			{
				if ( *(DWORD *)(v62 + 80) != 1 || *(BYTE *)0x8793384 || pCheckMouseOver(v82, v87, v70, v75) )
				{
					if ( *(DWORD *)(v62 + 80) != 1 || *(BYTE *)0x8793384 != 1 && *(BYTE *)0x8793380 != 1 || pCheckMouseOver(v82, v87, v70, v75) != 1 )
					{
						if ( *(DWORD *)(v62 + 80) != 2 || *(BYTE *)0x8793384 || *(BYTE *)0x8793380 )
						{
							if ( *(DWORD *)(v62 + 80) == 1 )
							{
								*(BYTE *)(v62 + 65) = 1;
								*(DWORD *)(v62 + 68) = *(BYTE *)(*(DWORD *)0x7BC4F04 + 50);
								*(DWORD *)(v62 + 72) = v82 - 5.0;
								*(DWORD *)(v62 + 76) = v87;
								result = 0;
							}
							else if ( *(DWORD *)(v62 + 80) == 2 )
							{
								result = 0;
							}
							else
							{
								//-- DrawSkill Bar
								v83 = 330.0;
								v88 = 480.0f;
								v71 = 100.0;
								v76 = 20.0;
								if ( *(DWORD *)(v62 + 80) || *(BYTE *)0x8793384 || pCheckMouseOver(v83, v88, v71, v76) != 1 )
								{
									if ( *(DWORD *)(v62 + 80) != 3 || *(BYTE *)0x8793384 || pCheckMouseOver(v83, v88, v71, v76) )
									{
										if ( *(DWORD *)(v62 + 80) != 3 || *(BYTE *)0x8793384 != 1 || pCheckMouseOver(v83, v88, v71, v76) != 1 )
										{
										//-- DrawSkill Bar Slot 5
											v84 = 315.0;
											v89 = 480.0f;
											v72 = 20.0;
											v68 = 0;
											v67 = *(BYTE *)(v62 + 20) != 1 ? 1 : 6;
											while ( v68 < 5 )
											{
												v84 = v84 + v72;
												if ( v67 == 10 )
													v67 = 0;
												if ( pCheckMouseOver(v84, v89, v72, (float)32.0) == 1 )
												{
													if ( *(DWORD *)(v62 + 4 * v67 + 24) == -1 )
													{
														if ( *(DWORD *)(v62 + 80) == 3 )
														{
															*(BYTE *)(v62 + 65) = 0;
															*(DWORD *)(v62 + 68) = -1;
														}
														if ( *(DWORD *)(v62 + 80) == 4 && !*(BYTE *)0x8793384 )
															*(DWORD *)(v62 + 80) = 0;
													}
													else
													{
														v66 = *(WORD *)(*(DWORD *)0x8128AC8 + 2 * *(DWORD *)(v62 + 4 * v67 + 24) + 120);
														if ( v66 && ((signed int)v66 < 67 || (signed int)v66 > 72) && *(BYTE *)(*(DWORD *)0x8128ABC + 88 * v66 + 55) != 3 )
														{
															if ( *(DWORD *)(v62 + 80) == 3 )
															{
																*(BYTE *)(v62 + 65) = 1;
																*(DWORD *)(v62 + 68) = *(DWORD *)(v62 + 4 * v67 + 24);
																*(DWORD *)(v62 + 72) = v84 - 5.0;
																*(DWORD *)(v62 + 76) = v89;
																return 1;
															}
															if ( *(DWORD *)(v62 + 80) == 4 && !*(BYTE *)0x8793384 )
															{
																if ( *(DWORD *)(v62 + 68) == *(DWORD *)(v62 + 4 * v67 + 24) )
																{
																	*(DWORD *)(v62 + 80) = 0;
																	*(WORD *)(v62 + 84) = *(WORD *)(*(DWORD *)0x8128AC8 + 2 * *(BYTE *)(*(DWORD *)0x7BC4F04 + 50) + 120);
																	*(BYTE *)(*(DWORD *)0x7BC4F04 + 50) = *(BYTE *)(v62 + 4 * v67 + 24);
																	PlayBuffer(25, 0, 0);
																	return 0;
																}
																*(DWORD *)(v62 + 80) = 0;
															}
														}
													}
												}
												++v68;
												++v67;
											}
											if ( *(DWORD *)(v62 + 80) == 4 )
											{
												//-- DrawSkill Bar
												if ( *(BYTE *)0x8793384 || pCheckMouseOver((float)330.0, (float)480.0f, (float)100.0, (float)32.0))
												{
													result = 0;
												}
												else
												{
													*(DWORD *)(v62 + 80) = 0;
													result = 1;
												}
											}
											else if ( *(BYTE *)(v62 + 64) )
											{
												//-- SkillBarSwitch
												v80 = 0;
												v78 = 0;
												v90 = 390.0;//-- y
												v73 = 32.0;//-- w
												v77 = 38.0;//-- h
												v79 = 302.0;//-- x
												v81 = *(DWORD *)(v62 + 80);
												for ( i = 0; i < 150; ++i )
												{
													v69 = *(WORD *)(*(DWORD *)0x8128AC8 + 2 * i + 120);
													if ( v69 && ((signed int)v69 < 67 || (signed int)v69 > 72) && *(BYTE *)(*(DWORD *)0x8128ABC + 88 * v69 + 55) != 3 )
													{
														if ( v80 == 11 )
															v90 = v90 - v77;
														if ( v80 >= 11 )
														{
															if ( v80 < 11 || v80 > 21 )
																v85 = v79 - v73 * 11.0 + (double)(v80 - 21) * v73;
															else
																v85 = v79 - v73 * 6.0 + (double)(v80 - 10) * v73;
														}
														else
														{
															v64 = v80 / 2;
															if ( v80 % 2 )
																v85 = v79 - (double)(v64 + 1) * v73;
															else
																v85 = (double)v64 * v73 + v79;
														}
														++v80;
														if ( pCheckMouseOver(v85, v90, v73, v77) == 1 )
														{
															v78 = 1;
															if ( !*(DWORD *)(v62 + 80) && !*(BYTE *)0x8793384 )
															{
																*(DWORD *)(v62 + 80) = 5;
																break;
															}
														}
														if ( *(DWORD *)(v62 + 80) == 5 && *(BYTE *)0x8793384 == 1 )
														{
															if ( pCheckMouseOver(v85, v90, v73, v77) == 1 )
															{
																*(DWORD *)(v62 + 80) = 6;
																break;
															}
														}
														if ( *(DWORD *)(v62 + 80) == 5 && !*(BYTE *)0x8793384 )
														{
															if ( pCheckMouseOver(v85, v90, v73, v77) == 1 )
															{
																*(BYTE *)(v62 + 65) = 1;
																*(DWORD *)(v62 + 68) = i;
																*(DWORD *)(v62 + 72) = v85;
																*(DWORD *)(v62 + 76) = v90;
															}
														}
														if ( *(DWORD *)(v62 + 80) == 6 && !*(BYTE *)0x8793384 && *(DWORD *)(v62 + 68) == i )
														{
															if ( pCheckMouseOver(v85, v90, v73, v77) == 1 )
															{
																*(DWORD *)(v62 + 80) = 0;
																*(WORD *)(v62 + 84) = *(WORD *)(*(DWORD *)0x8128AC8 + 2 * *(BYTE *)(*(DWORD *)0x7BC4F04 + 50) + 120);
																*(BYTE *)(*(DWORD *)0x7BC4F04 + 50) = i;
																*(BYTE *)(v62 + 64) = 0;
																PlayBuffer(25, 0, 0);
																return 0;
															}
														}
													}
												}
												if ( v81 == *(DWORD *)(v62 + 80) )
												{
													if ( *(DWORD *)(*(DWORD *)0x7BC4F04 + 676) )
													{
														//-- SkillFixRaven
														v86 = 270.0;
														v91 = 350.0;
														v74 = 32.0;
														for ( j = 150; j < 154; ++j )
														{
															if ( pCheckMouseOver(v86, v91, v74, (float)38.0) == 1 )
															{
																v78 = 1;
																if ( !*(DWORD *)(v62 + 80) && !*(BYTE *)0x8793384 )
																{
																	*(DWORD *)(v62 + 80) = 5;
																	return 1;
																}
																if ( *(DWORD *)(v62 + 80) == 5 && *(BYTE *)0x8793384 == 1 )
																{
																	*(DWORD *)(v62 + 80) = 6;
																	return 0;
																}
																if ( *(DWORD *)(v62 + 80) == 5 )
																{
																	*(BYTE *)(v62 + 65) = 1;
																	*(DWORD *)(v62 + 68) = j;
																	*(DWORD *)(v62 + 72) = v86;
																	*(DWORD *)(v62 + 76) = v91;
																}
																if ( *(DWORD *)(v62 + 80) == 6 && !*(BYTE *)0x8793384 && *(DWORD *)(v62 + 68) == j )
																{
																	*(DWORD *)(v62 + 80) = 0;
																	*(WORD *)(v62 + 84) = *(WORD *)(*(DWORD *)0x8128AC8 + 2 * *(BYTE *)(*(DWORD *)0x7BC4F04 + 50) + 120);
																	*(BYTE *)(*(DWORD *)0x7BC4F04 + 50) = j;
																	*(BYTE *)(v62 + 64) = 0;
																	PlayBuffer(25, 0, 0);
																	return 0;
																}
															}
															v86 = v86 + v74;
														}
													}
													if ( v78 || *(DWORD *)(v62 + 80) != 5 )
													{
														if ( v78 || *(BYTE *)0x8793384 || *(DWORD *)(v62 + 80) != 6 )
														{
															if ( *(DWORD *)(v62 + 80) == 6 )
															{
																if ( *(BYTE *)0x8793384 )
																{
																	result = 0;
																}
																else
																{
																	*(DWORD *)(v62 + 80) = 0;
																	result = 1;
																}
															}
															else
															{
																result = 1;
															}
														}
														else
														{
															*(DWORD *)(v62 + 80) = 0;
															result = 0;
														}
													}
													else
													{
														*(DWORD *)(v62 + 80) = 0;
														result = 1;
													}
												}
												else
												{
													result = !*(DWORD *)(v62 + 80) || *(DWORD *)(v62 + 80) == 5;
												}
											}
											else
											{
												result = 1;
											}
										}
										else
										{
											*(DWORD *)(v62 + 80) = 4;
											result = 0;
										}
									}
									else
									{
										*(DWORD *)(v62 + 80) = 0;
										result = 1;
									}
								}
								else
								{
									*(DWORD *)(v62 + 80) = 3;
									result = 1;
								}
							}
						}
						else
						{
							if ( pCheckMouseOver(v82, v87, v70, v75) == 1 )
							{
								*(BYTE *)(v62 + 64) = *(BYTE *)(v62 + 64) == 0;
								PlayBuffer(25, 0, 0);
								*(DWORD *)(v62 + 80) = 0;
								result = 0;
							}
							else
							{
								*(DWORD *)(v62 + 80) = 0;
								result = 1;
							}
						}
					}
					else
					{
						*(DWORD *)(v62 + 80) = 2;
						result = 0;
					}
				}
				else
				{
					*(DWORD *)(v62 + 80) = 0;
					result = 1;
				}
			}
			else
			{
				*(DWORD *)(v62 + 80) = 1;
				result = 1;
			}
		}
		else
		{
			result = 1;
		}
	}
	return result;
}

void RenderSkill_Raven1(DWORD *a1)
{
	float v4; // ST18_4@7
	float v5; // ST14_4@7
	int v6; // [sp+18h] [bp-18h]@1
	signed int i; // [sp+1Ch] [bp-14h]@2
	float v8; // [sp+20h] [bp-10h]@2
	float v9; // [sp+24h] [bp-Ch]@2
	float v10; // [sp+28h] [bp-8h]@2
	float v11; // [sp+2Ch] [bp-4h]@2

	v6 = *(DWORD *)a1;
	if ( *(DWORD *)(*(DWORD *)0x7BC4F04 + 676) )
	{
		v10 = 270.0;//X
		v11 = 350.0;//Y
		v8 = 32.0;
		v9 = 38.0;
		for ( i = 150; i < 154; ++i )
		{
			if ( i == *(BYTE *)(*(DWORD *)0x7BC4F04 + 50) )
				pDrawGUI(31313, v10, v11, v8, v9);
			else
				pDrawGUI(31312, v10, v11, v8, v9);
			v4 = v11 + 6.0;
			v5 = v10 + 6.0;
			RenderShowSkill(a1, i, v5, v4, 20.0, 28.0);
			v10 = v10 + v8;
		}
	}
}
//--
void Render_Funcion_772EA01(int ThisR1)
{
	static DWORD Addr1 = 0x00815040;
	static DWORD Addr2_Call = 0x00772EA0;
	static DWORD This = 0x00772EA0;

	This = ThisR1;

	_asm
	{
		PUSH 0                              ; /Arg5 = 00000000
		PUSH 0                              ; |Arg4 = 00000000
		MOV ECX,This                        ; |
		PUSH ECX                            ; |Arg3
		PUSH Addr1                          ; |Arg2 = 00815040
		PUSH ECX                            ; |Arg1
		FLD DWORD PTR DS:[0xD2CA40]         ; |
		FSTP DWORD PTR SS:[ESP]             ; |
		MOV EDX,This                        ; |
		MOV ECX,DWORD PTR DS:[EDX + 0x10]   ; |
		CALL Addr2_Call                     ; \main1.00772EA0
	}
}
//probando
char Render_SkillBarSwitch1(int This)
{
	float v4; // ST18_4@26
	float v5; // ST14_4@26
	int v7; // [sp+28h] [bp-34h]@1
	int v8; // [sp+30h] [bp-2Ch]@15
	char v9; // [sp+37h] [bp-25h]@9
	float v10; // [sp+38h] [bp-24h]@3
	signed int v11; // [sp+3Ch] [bp-20h]@3
	signed int v12; // [sp+40h] [bp-1Ch]@6
	float v13; // [sp+44h] [bp-18h]@3
	float v14; // [sp+48h] [bp-14h]@3
	signed int i; // [sp+50h] [bp-Ch]@3
	float v16; // [sp+54h] [bp-8h]@16
	float v17; // [sp+58h] [bp-4h]@3

	v7 = This;

	if ( (signed int)*(BYTE *)(*(DWORD *)0x8128AC8 + 118) > 0 && *(BYTE *)(v7 + 64) == 1 )
	{
		v17 = 390.0;//Y
		v13 = 32.0;
		v14 = 38.0;
		v10 = 302.0;//X
		v11 = 0;

		for ( i = 0; i < 150; ++i )
		{
			v12 = *(WORD *)(*(DWORD *)0x8128AC8 + 2 * i + 120);

			if ( *(WORD *)(*(DWORD *)0x8128AC8 + 2 * i + 120) && (v12 < 67 || v12 > 72) )
			{
				v9 = *(BYTE *)(*(DWORD *)0x8128ABC + 88 * v12 + 55);
				if ( v9 != 1 && v9 != 3 )
				{
					if ( v11 == 11 )
					{
						v17 = v17 - v14;
					}
					if ( v11 >= 11 )
					{
						if ( v11 < 11 || v11 > 21 )
						{
							v16 = v10 - v13 * 11.0 + (double)(v11 - 21) * v13;
						}
						else
						{
							v16 = v10 - v13 * 6 + (double)(v11 - 10) * v13;
						}
					}
					else
					{
						v8 = v11 / 2;
						if ( v11 % 2 )
						{
							v16 = v10 - (double)(v8 + 1) * v13;
						}
						else
						{
							v16 = (double)v8 * v13 + v10;
						}
					}
					
					++v11;

					if ( i == *(BYTE *)(*(DWORD *)0x7BC4F04 + 50) )//-- Seleccionado
					{
						pDrawGUI(31313, v16, v17, v13, v14);
					}
					else
					{
						pDrawGUI(31312, v16, v17, v13, v14);
					}
					v4 = v17 + 6.0;
					v5 = v16 + 6.0;
					RenderShowSkill((DWORD *)This, i, v5, v4, 20.0, 28.0);
				}
			}
		}
		RenderSkill_Raven1((DWORD *)This);
	}

	if ( *(BYTE *)(This + 65) == 1 && *(DWORD *)(This + 16) )
	{
		Render_Funcion_772EA01(This);
		*(BYTE *)(This + 65) = 0;
	}
	return 1;
}

__declspec(naked) void ChatFix()
{
	static DWORD ChatFix_buff = 0x00787BAD;
	_asm
	{
		FLD DWORD PTR DS : [0xD43849]
		jmp[ChatFix_buff]
	}
}

//Move Flechas
__declspec(naked) void MoveTextArrow1()
{
	static DWORD Addr_main = 0x007DF898;
	static DWORD MOVEY = -5;

	_asm
	{
		MOV ECX, DWORD PTR SS : [EBP - 0x4]
			ADD ECX, MOVEY; |
			PUSH ECX; / Arg2
			MOV EDX, DWORD PTR SS : [EBP - 0x8]; |
			MOV EAX, DWORD PTR DS : [EDX + 0x10]; |
			PUSH EAX; | Arg1
			MOV ECX, DWORD PTR SS : [EBP - 0x8]; |
			JMP[Addr_main]
	}
}
	//-------------------------------------------------------------------
_declspec(naked) void GuildWarPosition1()
{
   static DWORD ReturnAdress = 0x00777026;   
   _asm
   {
      ADD ECX,-230 //POS X
      MOV DWORD PTR SS:[EBP-0x4],ECX
      MOV EDX,DWORD PTR SS:[EBP-0x90]
      MOV EAX,DWORD PTR DS:[EDX+0x14]
      ADD EAX,-354 //POS Y
      MOV DWORD PTR SS:[EBP-0x8C],EAX
      MOV ECX,DWORD PTR DS:[0xE8C58C]
      JMP [ReturnAdress]
   }
}
//------------------------------------------
__declspec(naked) void ChatWindowDisplay1() // OK
{
	static DWORD ChatWindowDisplayAddress1 = 0x00788A80;
	static DWORD ChatWindowDisplayAddress2 = 0x0078B0C1;

	__asm
	{
		Mov al, Byte Ptr Ds : [Ecx + 0x158]
		test al, al
		JE UPPERCHAT
		Mov Dword Ptr Ds : [Ecx + 0x124], 180
		Mov Dword Ptr Ds : [Ecx + 0x128], 410
		JMP FUNCTION
	UPPERCHAT:
		Mov Dword Ptr Ds : [Ecx + 0x124], 0
		Mov Dword Ptr Ds : [Ecx + 0x128], 150
	FUNCTION:
		Mov Ecx, Dword Ptr Ss : [Ebp - 0x04]
		Call[ChatWindowDisplayAddress1]
		Jmp[ChatWindowDisplayAddress2]
	}
}
//-> Fix Skill Tooltip Position
__declspec(naked) void ToolTipSkill()
{
	static DWORD SkillRavenClicDraw_buff = 0x00813C25;

	_asm
	{
		PUSH ECX
		MOV EDX, DWORD PTR SS : [EBP - 0x04]
		MOV EAX, DWORD PTR DS : [EDX + 0x4C]
		SUB EAX, 0x1B
		PUSH EAX
		MOV ECX, DWORD PTR SS : [EBP - 0x04]
		MOV EDX, DWORD PTR DS : [ECX + 0x48]
		ADD EDX, 0x0F
		jmp[SkillRavenClicDraw_buff]
	}
}

int StackNumberPotion(float x, float y, int number)
{
	return RenderNumber(x, y, number, 0.9);
}

//--------------------------------------------
DWORD Slot;
__declspec(naked) void ShadowCheck1()
{
	static DWORD jmpBack = 0x007DB30F;

	__asm
	{
		mov     eax, [ebp - 0x1C]
		movzx   ecx, byte ptr[eax + 0x60]
		mov		Slot, ecx
		jmp     [jmpBack]
	}
}
void ItemBox(DWORD ID, float x, float y, float w, float h)
{
	RenderBitmap(31072, x, y, w, h, 0, 0, 1.0, 1.0, 1, 1, 0.0);

	switch (Slot)
	{
		case 0:
		break;
		case 1:
			glColor4f(1.0, 1.0, 0.0, 0.30000001);//glColor4f(1.0, 1.0, 0.0, 0.60000001);
		break;
		case 2:
			glColor4f(1.0, 0.66000003, 0.0, 0.30000001);//glColor4f(1.0, 0.66000003, 0.0, 0.60000001);
		break;
		case 3:
			glColor4f(0.89000001, 0.10900001, 0.10900001, 0.30000001);//glColor4f(1.0, 0.33000001, 0.0, 0.60000001);
		break;
		case 4:
			glColor4f(1.0, 0.0, 0.0, 0.40000001);
		break;
		case 5:
			glColor4f(1.0, 0.2, 0.1, 0.40000001);
		break;
		default:
			RenderBitmap(31071, x, y, w, h, 0, 0, 1.0, 1.0, 1, 1, 0.0);
		break;
	}

	if(Slot >= 1 && Slot <= 5)
	{
		pSetBlend(true);
		pDrawBarForm(x, y, w, h, 0.0, 0);
		pGLSwitchBlend();
		pGLSwitch();
		glColor3f(1.0, 1.0, 1.0);
	}

	Slot = -1;
}
//


void DowngradeInventoryWindows1(DWORD id, float x, float y, float w, float h)
{
	//BeginBitmap();
	//glColor4f(1.0, 1.0, 1.0, 0.7); //Bota isso antes da imagem
	pDrawGUI(51533, x, y, w, h);
	//glColor4f(1.0, 1.0, 1.0, 1.0); //Bota isso depois da imagem
	//EndOpengl();
}

void DowngradeLoadWindows1(DWORD id, float x, float y, float w, float h)
{
	//BeginBitmap();
	//glColor4f(1.0, 1.0, 1.0, 0.7); //Bota isso antes da imagem
	pDrawGUI(51533, x, y, w, h);
	//glColor4f(1.0, 1.0, 1.0, 1.0); //Bota isso depois da imagem
	//EndOpengl();
}

void DowngradeStoreLoadWindows1(DWORD id, float x, float y, float w, float h)
{
	//BeginBitmap();
	//glColor4f(1.0, 1.0, 1.0, 0.7); //Bota isso antes da imagem
	pDrawGUI(51533, x, y, w, h);
	//glColor4f(1.0, 1.0, 1.0, 1.0); //Bota isso depois da imagem
	//EndOpengl();
}

void DowngradeLoadWindowsNone1(DWORD id, float x, float y, float w, float h)
{
	//BeginBitmap();
	//glColor4f(1.0, 1.0, 1.0, 0.7); //Bota isso antes da imagem
	pDrawGUI(51522, x, y, w, h);
	//glColor4f(1.0, 1.0, 1.0, 1.0); //Bota isso depois da imagem
	//EndOpengl();
}

//Fix Interface Party
__declspec(naked) void PartyWindowsMove2()
{
	static DWORD PartyWindows_Buff = 0x0084B965;
	static DWORD X;
	if (gProtect.m_MainInfo.CustomInterfaceType == 5)
	{
		X = 79;//<<Cord Base

		if (gInterface.CheckWindow(13) && gInterface.CheckWindow(8)
			|| gInterface.CheckWindow(12)
			|| gInterface.CheckWindow(9)
			|| gInterface.CheckWindow(7)
			|| gInterface.CheckWindow(14)
			|| gInterface.CheckWindow(15)
			|| gInterface.CheckWindow(60)
			|| gInterface.CheckWindow(76))
		{
			X = 459;
		}
		else
		{
			if (gInterface.CheckWindow(27))
			{
				X = 459;
			}
			else
			{
				if (gInterface.CheckWindow(13)
					|| gInterface.CheckWindow(3)
					|| gInterface.CheckWindow(21)
					|| gInterface.CheckWindow(6)
					|| gInterface.CheckWindow(22)
					|| gInterface.CheckWindow(23)
					|| gInterface.CheckWindow(24)
					|| gInterface.CheckWindow(4)
					|| gInterface.CheckWindow(16)
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
					|| gInterface.CheckWindow(74))
				{
					X = 269;
				}
				else
				{
					if (gInterface.CheckWindow(79))
					{
						if (gInterface.CheckWindow(80))
						{
							X = 459;
						}
						else
						{
							X = 269;
						}
					}
				}
			}
		}

		if (gInterface.CheckWindow(13) && gInterface.CheckWindow(16))
		{
			X = 459;
		}

		if (gInterface.CheckWindow(77))
		{
			if (gInterface.CheckWindow(Warehouse) ||
				gInterface.CheckWindow(ChaosBox) ||
				gInterface.CheckWindow(Store) ||
				gInterface.CheckWindow(OtherStore))
			{

			}
			else
			{
				X = 459;
			}
		}
		else if (gInterface.CheckWindow(78))
		{
			X = 459;
		}

		_asm
		{
			MOV EDX, DWORD PTR SS : [EBP + 0x8] ; |
			SUB EDX, X; |
			PUSH EDX; | Arg1
			JMP PartyWindows_Buff; |
		}
	}

	else if (gProtect.m_MainInfo.CustomInterfaceType == 5)
	{
		X = 79;//<<Cord Base

		if (gInterface.CheckWindow(13) && gInterface.CheckWindow(Character)
			|| gInterface.CheckWindow(8)
			|| gInterface.CheckWindow(12)
			|| gInterface.CheckWindow(9)
			|| gInterface.CheckWindow(7)
			|| gInterface.CheckWindow(14)
			|| gInterface.CheckWindow(15)
			|| gInterface.CheckWindow(60)
			|| gInterface.CheckWindow(76))
		{
			X = 459;
		}
		else
		{
			if (gInterface.CheckWindow(16) && (gInterface.CheckWindow(4) || gInterface.CheckWindow(69)))
			{
				X = 459;
			}
			else
			{
				if (gInterface.CheckWindow(16) && gInterface.CheckWindow(11))
				{
					X = 459;
				}
				else
				{
					if (gInterface.CheckWindow(27))
					{
						X = 459;
					}
					else
					{
						if (gInterface.CheckWindow(13)
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
							|| gInterface.CheckWindow(74))
						{
							X = 269;
						}
						else
						{
							if (gInterface.CheckWindow(79))
							{
								if (gInterface.CheckWindow(80))
								{
									X = 459;
								}
								else
								{
									X = 269;
								}
							}
						}
					}
				}
			}
		}

		if (gInterface.CheckWindow(77))
		{
			if (gInterface.CheckWindow(Warehouse) ||
				gInterface.CheckWindow(ChaosBox) ||
				gInterface.CheckWindow(Store) ||
				gInterface.CheckWindow(OtherStore) ||
				gInterface.CheckWindow(Character))
			{

			}
			else
			{
				X = 459;
			}
		}
		else if (gInterface.CheckWindow(78))
		{
			X = 459;
		}

		_asm
		{
			MOV EDX, DWORD PTR SS : [EBP + 0x8] ; |
			SUB EDX, X; |
			PUSH EDX; | Arg1
			JMP PartyWindows_Buff; |
		}
	}
}

signed int JCGetScreenWidth()
{
	signed int v52; // [sp+0h] [bp-4h]@11

	v52 = CGetScreenWidth2();

	return v52;
}

signed int JCWinIngame()
{
	return 640;
}

void Master_back(DWORD a1, float a2, float a3, float a4, float a5) {
	pDrawGUI(a1, a2, a3, a4, 428);
}

bool CheckMouseWindow(int x, int y, int w, int h)
{
	if (pCheckWindow(pWindowThis(), 78))
	{
		x = 70;
		w = 380;
	}
	return pCheckMouseOver(x, y, w, h);
}

//Victor
void NewInterface()
{
	//-- Chat Fix position
	SetRange((LPVOID)0x00787BA7, 5, ASM::NOP);
	SetJmp((LPVOID)0x00787BA7, ChatFix);

	//-> Fix Skill Tooltip Position
	SetCompleteHook(0xE9, 0x00813C11, &ToolTipSkill);

	//-> Size of Potions Number
	SetCompleteHook(0xE9, 0x00895600, &StackNumberPotion);

	//-- Windows Command
	SetCompleteHook(0xE8, 0x0078E6D6, &DowngradeLoadWindows1);
	SetCompleteHook(0xE8, 0x0078E70A, &DowngradeLoadWindowsNone1);
	SetCompleteHook(0xE8, 0x0078E74A, &DowngradeLoadWindowsNone1);
	SetCompleteHook(0xE8, 0x0078E79C, &DowngradeLoadWindowsNone1);
	SetCompleteHook(0xE8, 0x0078E7E2, &DowngradeLoadWindowsNone1);

	//-- Windows Helper
	SetCompleteHook(0xE8, 0x007F65A6, &DowngradeLoadWindows1);
	SetCompleteHook(0xE8, 0x007F65E6, &DowngradeLoadWindowsNone1);
	SetCompleteHook(0xE8, 0x007F6638, &DowngradeLoadWindowsNone1);
	SetCompleteHook(0xE8, 0x007F66A2, &DowngradeLoadWindowsNone1);
	SetCompleteHook(0xE8, 0x007F66FA, &DowngradeLoadWindowsNone1);
	//-- Windows MuHelper2
	SetCompleteHook(0xE8, 0x0080C848, &DowngradeLoadWindows1);
	SetCompleteHook(0xE8, 0x0080C87C, &DowngradeLoadWindowsNone1);
	SetCompleteHook(0xE8, 0x0080C8BC, &DowngradeLoadWindowsNone1);
	SetCompleteHook(0xE8, 0x0080C90E, &DowngradeLoadWindowsNone1);
	SetCompleteHook(0xE8, 0x0080C954, &DowngradeLoadWindowsNone1);
	//-- Windows Desconocido1
	SetCompleteHook(0xE8, 0x00845956, &DowngradeLoadWindows1);
	SetCompleteHook(0xE8, 0x0084598A, &DowngradeLoadWindowsNone1);
	SetCompleteHook(0xE8, 0x008459C7, &DowngradeLoadWindowsNone1);
	SetCompleteHook(0xE8, 0x00845A10, &DowngradeLoadWindowsNone1);
	SetCompleteHook(0xE8, 0x00845A4F, &DowngradeLoadWindowsNone1);
	//-- Windows Desconocido2
	SetCompleteHook(0xE8, 0x007C6BCC, &DowngradeLoadWindows1);
	SetCompleteHook(0xE8, 0x007C6C06, &DowngradeLoadWindowsNone1);
	SetCompleteHook(0xE8, 0x007C6C49, &DowngradeLoadWindowsNone1);
	SetCompleteHook(0xE8, 0x007C6C98, &DowngradeLoadWindowsNone1);
	SetCompleteHook(0xE8, 0x007C6CDD, &DowngradeLoadWindowsNone1);
	//-- Windows Desconocido3
	SetCompleteHook(0xE8, 0x007C7D0C, &DowngradeLoadWindows1);
	SetCompleteHook(0xE8, 0x007C7D46, &DowngradeLoadWindowsNone1);
	SetCompleteHook(0xE8, 0x007C7D89, &DowngradeLoadWindowsNone1);
	SetCompleteHook(0xE8, 0x007C7DD8, &DowngradeLoadWindowsNone1);
	SetCompleteHook(0xE8, 0x007C7E1D, &DowngradeLoadWindowsNone1);
	//-- Windows Desconocido4
	SetCompleteHook(0xE8, 0x00850966, &DowngradeLoadWindows1);
	SetCompleteHook(0xE8, 0x0085099A, &DowngradeLoadWindowsNone1);
	SetCompleteHook(0xE8, 0x008509D7, &DowngradeLoadWindowsNone1);
	SetCompleteHook(0xE8, 0x00850A20, &DowngradeLoadWindowsNone1);
	SetCompleteHook(0xE8, 0x00850A5F, &DowngradeLoadWindowsNone1);
	//-- Windows Desconocido5								    
	SetCompleteHook(0xE8, 0x00852476, &DowngradeLoadWindows1);   
	SetCompleteHook(0xE8, 0x008524AA, &DowngradeLoadWindowsNone1);
	SetCompleteHook(0xE8, 0x008524E7, &DowngradeLoadWindowsNone1);
	SetCompleteHook(0xE8, 0x00852530, &DowngradeLoadWindowsNone1);
	SetCompleteHook(0xE8, 0x0085256F, &DowngradeLoadWindowsNone1);
	//-- Windows Desconocido6								   
	SetCompleteHook(0xE8, 0x008540B6, &DowngradeLoadWindows1);  
	SetCompleteHook(0xE8, 0x008540EA, &DowngradeLoadWindowsNone1);
	SetCompleteHook(0xE8, 0x00854127, &DowngradeLoadWindowsNone1);
	SetCompleteHook(0xE8, 0x00854170, &DowngradeLoadWindowsNone1);
	SetCompleteHook(0xE8, 0x008541AF, &DowngradeLoadWindowsNone1);
	//-- Windows Desconocido7								   
	SetCompleteHook(0xE8, 0x00868052, &DowngradeLoadWindows1);  
	SetCompleteHook(0xE8, 0x0086808C, &DowngradeLoadWindowsNone1);
	SetCompleteHook(0xE8, 0x008680D5, &DowngradeLoadWindowsNone1);
	SetCompleteHook(0xE8, 0x00868130, &DowngradeLoadWindowsNone1);
	SetCompleteHook(0xE8, 0x0086817B, &DowngradeLoadWindowsNone1);
	//-- Windows Desconocido8								    
	SetCompleteHook(0xE8, 0x0087F886, &DowngradeLoadWindows1);   
	SetCompleteHook(0xE8, 0x0087F8BA, &DowngradeLoadWindowsNone1);
	SetCompleteHook(0xE8, 0x0087F8F7, &DowngradeLoadWindowsNone1);
	SetCompleteHook(0xE8, 0x0087F940, &DowngradeLoadWindowsNone1);
	SetCompleteHook(0xE8, 0x0087F97F, &DowngradeLoadWindowsNone1);
	//-- Windows Desconocido9 NPC CASTLE SIEGE				    
	SetCompleteHook(0xE8, 0x00882F52, &DowngradeLoadWindows1 );   
	SetCompleteHook(0xE8, 0x00882F8C, &DowngradeLoadWindowsNone1);
	SetCompleteHook(0xE8, 0x00882FD5, &DowngradeLoadWindowsNone1);
	SetCompleteHook(0xE8, 0x00883030, &DowngradeLoadWindowsNone1);
	SetCompleteHook(0xE8, 0x0088307B, &DowngradeLoadWindowsNone1);
	//-- Windows NPC Lugar									   
	SetCompleteHook(0xE8, 0x00893102, &DowngradeLoadWindows1);  
	SetCompleteHook(0xE8, 0x0089313C, &DowngradeLoadWindowsNone1);
	SetCompleteHook(0xE8, 0x00893185, &DowngradeLoadWindowsNone1);
	SetCompleteHook(0xE8, 0x008931E0, &DowngradeLoadWindowsNone1);
	SetCompleteHook(0xE8, 0x0089322B, &DowngradeLoadWindowsNone1);
	//-- Windows Guard NPC									    
	SetCompleteHook(0xE8, 0x008812A2, &DowngradeLoadWindows1);   
	SetCompleteHook(0xE8, 0x008812DC, &DowngradeLoadWindowsNone1);
	SetCompleteHook(0xE8, 0x00881325, &DowngradeLoadWindowsNone1);
	SetCompleteHook(0xE8, 0x00881380, &DowngradeLoadWindowsNone1);
	SetCompleteHook(0xE8, 0x008813CB, &DowngradeLoadWindowsNone1);
	//-- Windows NPC Senior									    
	SetCompleteHook(0xE8, 0x00879EE2, &DowngradeLoadWindows1);   
	SetCompleteHook(0xE8, 0x00879F1C, &DowngradeLoadWindowsNone1);
	SetCompleteHook(0xE8, 0x00879F65, &DowngradeLoadWindowsNone1);
	SetCompleteHook(0xE8, 0x00879FC0, &DowngradeLoadWindowsNone1);
	SetCompleteHook(0xE8, 0x0087A00B, &DowngradeLoadWindowsNone1);
	//-- Windows BloodCastle								    
	SetCompleteHook(0xE8, 0x008747B6, &DowngradeLoadWindows1);   
	SetCompleteHook(0xE8, 0x008747F0, &DowngradeLoadWindowsNone1);
	SetCompleteHook(0xE8, 0x0087483C, &DowngradeLoadWindowsNone1);
	SetCompleteHook(0xE8, 0x008748A0, &DowngradeLoadWindowsNone1);
	SetCompleteHook(0xE8, 0x008748F2, &DowngradeLoadWindowsNone1);
	//-- Windows DevilSquare								    
	SetCompleteHook(0xE8, 0x008781BC, &DowngradeLoadWindows1);   
	SetCompleteHook(0xE8, 0x008781F0, &DowngradeLoadWindowsNone1);
	SetCompleteHook(0xE8, 0x00878230, &DowngradeLoadWindowsNone1);
	SetCompleteHook(0xE8, 0x00878282, &DowngradeLoadWindowsNone1);
	SetCompleteHook(0xE8, 0x008782C8, &DowngradeLoadWindowsNone1);
	//-- Windows Pet										    
	SetCompleteHook(0xE8, 0x0084D01A, &DowngradeLoadWindows1);   
	SetCompleteHook(0xE8, 0x0084D05A, &DowngradeLoadWindowsNone1);
	SetCompleteHook(0xE8, 0x0084D0AC, &DowngradeLoadWindowsNone1);
	SetCompleteHook(0xE8, 0x0084D116, &DowngradeLoadWindowsNone1);
	SetCompleteHook(0xE8, 0x0084D16E, &DowngradeLoadWindowsNone1);
	//-- Windows Party										    
	SetCompleteHook(0xE8, 0x0084A546, &DowngradeLoadWindows1);   
	SetCompleteHook(0xE8, 0x0084A57A, &DowngradeLoadWindowsNone1);
	SetCompleteHook(0xE8, 0x0084A5BA, &DowngradeLoadWindowsNone1);
	SetCompleteHook(0xE8, 0x0084A60C, &DowngradeLoadWindowsNone1);
	SetCompleteHook(0xE8, 0x0084A652, &DowngradeLoadWindowsNone1);
	//-- Windows ChaosMachine								    
	SetCompleteHook(0xE8, 0x0082CA22, &DowngradeLoadWindows1);   
	SetCompleteHook(0xE8, 0x0082CB4B, &DowngradeLoadWindowsNone1);
	SetCompleteHook(0xE8, 0x0082CB00, &DowngradeLoadWindowsNone1);
	SetCompleteHook(0xE8, 0x0082CAA5, &DowngradeLoadWindowsNone1);
	SetCompleteHook(0xE8, 0x0082CA5C, &DowngradeLoadWindowsNone1);
	////-- Windows Store										    
	//SetCompleteHook(0xE8, 0x00841E49, &DowngradeStoreLoadWindows1);
	//SetCompleteHook(0xE8, 0x00841E7D, &DowngradeLoadWindowsNone1);
	//SetCompleteHook(0xE8, 0x00841EBA, &DowngradeLoadWindowsNone1);
	//SetCompleteHook(0xE8, 0x00841F03, &DowngradeLoadWindowsNone1);
	//SetCompleteHook(0xE8, 0x00841F42, &DowngradeLoadWindowsNone1);
	////-- Windows Store Other PJ								    
	//SetCompleteHook(0xE8, 0x0084F406, &DowngradeLoadWindows1);   
	//SetCompleteHook(0xE8, 0x0084F43A, &DowngradeLoadWindowsNone1);
	//SetCompleteHook(0xE8, 0x0084F477, &DowngradeLoadWindowsNone1);
	//SetCompleteHook(0xE8, 0x0084F4C0, &DowngradeLoadWindowsNone1);
	//SetCompleteHook(0xE8, 0x0084F4FF, &DowngradeLoadWindowsNone1);
	//-- Windows Baul										    
	SetCompleteHook(0xE8, 0x00857946, &DowngradeLoadWindows1);   
	SetCompleteHook(0xE8, 0x0085797A, &DowngradeLoadWindowsNone1);
	SetCompleteHook(0xE8, 0x008579B7, &DowngradeLoadWindowsNone1);
	SetCompleteHook(0xE8, 0x00857A00, &DowngradeLoadWindowsNone1);
	SetCompleteHook(0xE8, 0x00857A3F, &DowngradeLoadWindowsNone1);
	//-- Windows Baul Ext.									   
	SetCompleteHook(0xE8, 0x008567E6, &DowngradeLoadWindows1);  
	SetCompleteHook(0xE8, 0x0085681A, &DowngradeLoadWindowsNone1);
	SetCompleteHook(0xE8, 0x00856857, &DowngradeLoadWindowsNone1);
	SetCompleteHook(0xE8, 0x008568A0, &DowngradeLoadWindowsNone1);
	SetCompleteHook(0xE8, 0x008568DF, &DowngradeLoadWindowsNone1);
	//-- Windows Inventory									    
	SetCompleteHook(0xE8, 0x00836EF6, &DowngradeInventoryWindows1);
	SetCompleteHook(0xE8, 0x00836F2A, &DowngradeLoadWindowsNone1);
	SetCompleteHook(0xE8, 0x00836F67, &DowngradeLoadWindowsNone1);
	SetCompleteHook(0xE8, 0x00836FB0, &DowngradeLoadWindowsNone1);
	SetCompleteHook(0xE8, 0x00836FEF, &DowngradeLoadWindowsNone1);
	//-- Windows Inventory Ext.								   
	SetCompleteHook(0xE8, 0x007D55A6, &DowngradeLoadWindows1); 
	SetCompleteHook(0xE8, 0x007D55DA, &DowngradeLoadWindowsNone1);
	SetCompleteHook(0xE8, 0x007D5617, &DowngradeLoadWindowsNone1);
	SetCompleteHook(0xE8, 0x007D5660, &DowngradeLoadWindowsNone1);
	SetCompleteHook(0xE8, 0x007D569F, &DowngradeLoadWindowsNone1);
	//-- Windows Shop.										    
	SetCompleteHook(0xE8, 0x008470A6, &DowngradeLoadWindows1);   
	SetCompleteHook(0xE8, 0x008470DA, &DowngradeLoadWindowsNone1);
	SetCompleteHook(0xE8, 0x00847117, &DowngradeLoadWindowsNone1);
	SetCompleteHook(0xE8, 0x00847160, &DowngradeLoadWindowsNone1);
	SetCompleteHook(0xE8, 0x0084719F, &DowngradeLoadWindowsNone1);
	//-- Windows GuildMarker								    
	SetCompleteHook(0xE8, 0x007D1786, &DowngradeLoadWindows1);  
	SetCompleteHook(0xE8, 0x007D17BA, &DowngradeLoadWindowsNone1);
	SetCompleteHook(0xE8, 0x007D17F7, &DowngradeLoadWindowsNone1);
	SetCompleteHook(0xE8, 0x007D1840, &DowngradeLoadWindowsNone1);
	SetCompleteHook(0xE8, 0x007D187F, &DowngradeLoadWindowsNone1);
	//-- Windows Guild User									   
	SetCompleteHook(0xE8, 0x007CB6F6, &DowngradeLoadWindows1);  
	SetCompleteHook(0xE8, 0x007CB72A, &DowngradeLoadWindowsNone1);
	SetCompleteHook(0xE8, 0x007CB767, &DowngradeLoadWindowsNone1);
	SetCompleteHook(0xE8, 0x007CB7B0, &DowngradeLoadWindowsNone1);
	SetCompleteHook(0xE8, 0x007CB7EF, &DowngradeLoadWindowsNone1);
															   
	//-- Windows Gens-Quest									   
	SetCompleteHook(0xE8, 0x00843826, &DowngradeLoadWindows1); 
	SetCompleteHook(0xE8, 0x0084385A, &DowngradeLoadWindowsNone1);
	SetCompleteHook(0xE8, 0x00843897, &DowngradeLoadWindowsNone1);
	SetCompleteHook(0xE8, 0x008438E0, &DowngradeLoadWindowsNone1);
	SetCompleteHook(0xE8, 0x0084391F, &DowngradeLoadWindowsNone1);
	//-- Windows Quest (T)									   
	SetCompleteHook(0xE8, 0x0083EA46, &DowngradeLoadWindows1); 
	SetCompleteHook(0xE8, 0x0083EA7A, &DowngradeLoadWindowsNone1);
	SetCompleteHook(0xE8, 0x0083EAB7, &DowngradeLoadWindowsNone1);
	SetCompleteHook(0xE8, 0x0083EB00, &DowngradeLoadWindowsNone1);
	SetCompleteHook(0xE8, 0x0083EB3F, &DowngradeLoadWindowsNone1);
	//-- Windows Trade										   
	SetCompleteHook(0xE8, 0x008643B6, &DowngradeLoadWindows1);  
	SetCompleteHook(0xE8, 0x008643EA, &DowngradeLoadWindowsNone1);
	SetCompleteHook(0xE8, 0x00864427, &DowngradeLoadWindowsNone1);
	SetCompleteHook(0xE8, 0x00864470, &DowngradeLoadWindowsNone1);
	SetCompleteHook(0xE8, 0x008644AF, &DowngradeLoadWindowsNone1);
	//
	//Move Guild War
	SetCompleteHook(0xE9, 0x00777008, &GuildWarPosition1);
	MemorySet(0x00776FE4,0x90,0x5);
	
	//Flechas
	SetCompleteHook(0xE9, 0x007DF88A, &MoveTextArrow1);

		//MemorySet(0x007A8330,0x90,0x198);	// MENU ESC TRANSPARENTE
		SetByte((DWORD)(0x0078DDF1+3),60);	//MEMUS SYSTEM - MENU D POSICION CENTRAL
//-------------------------------------------------------------------			
		
//--//-----------------------------------------------------------------	
	//Elimina El Chaos Machine  380
	//MemorySet(0x007AA3BA,0x90,0x5);
	//MemorySet(0x007AA39C,0x90,0x5);
	//MemorySet(0x007AA9B3,0x90,0x5);
//--//-----------------------------------------------------------------	
	//SetDword((PVOID)(0x007AA2F4+2),190);// BOTON CHAOS WEAPON POSITION Y
	//SetByte((PVOID)(0x007AA292+2),120); //BOTON REGULAR COMBINATION POSITION Y
	//SetByte((PVOID)(0x007AA669+2),50); //TEXTOS COMO POSITION Y	  
//--//-----------------------------------------------------------------		
	SetDword((PVOID)(0x007D0EF6+1),350); //POSIÇÃO Y GUILD MASTER BUTTONS PART1
	SetDword((PVOID)(0x007D0F5D+1),350); //POSIÇÃO Y GUILD MASTER BUTTONS PART1
	SetByte((PVOID)(0x007D0F05+2),43); //POSIÇÃO X GUILD MASTER BUTTONS PART1
	SetByte((PVOID)(0x007D0F6C+2),88); //POSIÇÃO X GUILD MASTER BUTTONS PART1
	SetDword((PVOID)(0x007D11DE+2),350); //POSIÇÃO Y GUILD MASTER BUTTONS PART2
	SetDword((PVOID)(0x007D1249+2),350); //POSIÇÃO Y GUILD MASTER BUTTONS PART2
	SetByte((PVOID)(0x007D11EE+2),43); //POSIÇÃO X GUILD MASTER BUTTONS PART2
	SetByte((PVOID)(0x007D1259+2),88); //POSIÇÃO X GUILD MASTER BUTTONS PART2
//--//-----------------------------------------------------------------	
	//MemorySet(0x0087500F,0x90,0x5);		//Blood Text
	//SetByte((PVOID)(0x008743FC+3),7);	//Blood Button Master
	//SetByte((PVOID)(0x00874D54+6),7);	//Blood Button Master
//--//-----------------------------------------------------------------
	MemorySet(0x0040A7EF,0x90,0x5);		//Remover Button Menu SelectServer
   	MemorySet(0x0040A87E,0x90,0x5);		//Remover Button Crédits SelectServer		
	//SetByte((PVOID)(0x00877EDC+3),6);	//Remover DevilScare Master
	//MemorySet(0x00878B5F,0x90,0x5);		//Remover DevilScare Master
//--//-----------------------------------------------------------------	
	//SetCompleteHook(0xE9,0x007E4CA4,0x007E4D16);	//Remover ChaosCastle Master
	//SetByte((PVOID)(0x007E4CB9+1),0);	//Cambia el número del chaos
//--//-----------------------------------------------------------------		
	SetByte((DWORD)(0x00834D93+1),0x52);//  REPAIR (R)
	SetDword((DWORD)(0x00788A2B+2),314);//DIMENSIONAMENTO DA TELA PRETA DOWNGRADE
	SetRange((LPVOID)0x00D46C8C,5,ASM::NOP);		//-> Remove Interface [Socket Option]
	SetRange((LPVOID)0x00D46C84,5,ASM::NOP);		//-> Remove Interface [Set Option]
//-------------------------------------------------------------------	
	MemorySet(0x00895B8D,0x90,0x7E); //Disable R option
	SetCompleteHook(0xE9,0x00895B8D,&DrawInterfaceS2DisableR1);
//-------------------------------------------------------------------	
	SetRange((LPVOID)0x0080F270, 0x4D1, ASM::NOP);//-> Interface -> Draw Button
//-------------------------------------------------------------------	
	SetByte((PVOID)(0x008137AF + 3), 0);
	SetByte((PVOID)(0x008119A7), 0xEB);
	SetRange((LPVOID)0x00811AC0, 0xAC, ASM::NOP);
//--------------------------DrawMANAPosition-----------------------------------------	
	SetRange((LPVOID)0x0080FFAF, 0x24, ASM::NOP);
	SetOp((LPVOID)0x0080FFAF, (LPVOID)DrawMANAPosition1, ASM::JMP);
//------------------------------DrawHPPosition-------------------------------------	
	SetRange((LPVOID)0x0080FD5B, 0x24, ASM::NOP);
	SetOp((LPVOID)0x0080FD5B, (LPVOID)DrawHPPosition1, ASM::JMP);
//---------------------------------DrawAGPosition----------------------------------	
	SetRange((LPVOID)0x0081028C, 0x24, ASM::NOP);
	SetOp((LPVOID)0x0081028C, (LPVOID)DrawAGPosition1, ASM::JMP);
//----------------------------------DrawSDPosition---------------------------------		
	SetRange((LPVOID)0x0081055C, 0x24, ASM::NOP);
	SetOp((LPVOID)0x0081055C, (LPVOID)DrawSDPosition1, ASM::JMP);	
//------------------------------DrawHPNumberPosition-------------------------------------	
	SetRange((LPVOID)0x0080FF12, 0x12, ASM::NOP);
	SetOp((LPVOID)0x0080FF12, (LPVOID)DrawHPNumberPosition11, ASM::JMP);
//-------------------------------------------------------------------	
	SetCompleteHook(0xE9, 0x008126C0, &Render_SkillFullMouser1);
	SetCompleteHook(0xE9, 0x00813970, &Render_SkillBarSwitch1);

	SetRange((LPVOID)0x008138DF, 0x24, ASM::NOP);
	SetOp((LPVOID)0x008138DF, (LPVOID)DrawUsingSkillPosition1, ASM::JMP);
//-------------------------------------------------------------------	
	SetRange((LPVOID)0x00812713, 0x24, ASM::NOP);
	SetOp((LPVOID)0x00812713, (LPVOID)DrawSkillClickPosition1, ASM::JMP);
//------------//-------------------------------------------------------	
	SetRange((LPVOID)0x00812947, 0x24, ASM::NOP);
	SetOp((LPVOID)0x00812947, (LPVOID)DrawSkillBarDrawPosition1, ASM::JMP);
//-------------------------------------------------------------------	
	SetRange((LPVOID)0x008139A0, 0x2D, ASM::NOP);
	SetOp((LPVOID)0x008139A0, (LPVOID)DrawSkillSwitchDraw1, ASM::JMP);
//-------------------------------------------------------------------	
	SetRange((LPVOID)0x00812D3F, 0x2D, ASM::NOP);
	SetOp((LPVOID)0x00812D3F, (LPVOID)DrawSkillSwitchClick1, ASM::JMP);

//-------------------------------------------------------------------	
	//SetRange((LPVOID)0x0077EC97, 0x88, ASM::NOP);
	//SetOp((LPVOID)0x0077EC97, (LPVOID)DrawMasterButton, ASM::JMP);
//-------------------------------------------------------------------	
	//->Q
	SetRange((LPVOID)0x00895A49, 0x9, ASM::NOP);
	SetOp((LPVOID)0x00895A49, (LPVOID)DrawQPosition11, ASM::JMP);
	//-
	SetRange((LPVOID)0x00895A53, 0x9, ASM::NOP);
	SetOp((LPVOID)0x00895A53, (LPVOID)DrawQPosition21, ASM::JMP);
	//-
	SetRange((LPVOID)0x00895A5D, 0x9, ASM::NOP);
	SetOp((LPVOID)0x00895A5D, (LPVOID)DrawQPosition31, ASM::JMP);
	//-
	SetRange((LPVOID)0x00895A67, 0x9, ASM::NOP);
	SetOp((LPVOID)0x00895A67, (LPVOID)DrawQPosition41, ASM::JMP);
	//->W
	SetRange((LPVOID)0x00895ABE, 0x9, ASM::NOP);
	SetOp((LPVOID)0x00895ABE, (LPVOID)DrawWPosition11, ASM::JMP);
	//-
	SetRange((LPVOID)0x00895AC8, 0x9, ASM::NOP);
	SetOp((LPVOID)0x00895AC8, (LPVOID)DrawWPosition21, ASM::JMP);
	//-
	SetRange((LPVOID)0x00895AD2, 0x9, ASM::NOP);
	SetOp((LPVOID)0x00895AD2, (LPVOID)DrawWPosition31, ASM::JMP);
	//-
	SetRange((LPVOID)0x00895ADC, 0x9, ASM::NOP);
	SetOp((LPVOID)0x00895ADC, (LPVOID)DrawWPosition41, ASM::JMP);
	//->E
	SetRange((LPVOID)0x00895B33, 0x9, ASM::NOP);
	SetOp((LPVOID)0x00895B33, (LPVOID)DrawEPosition11, ASM::JMP);
	//-
	SetRange((LPVOID)0x00895B3D, 0x9, ASM::NOP);
	SetOp((LPVOID)0x00895B3D, (LPVOID)DrawEPosition21, ASM::JMP);
	//-
	SetRange((LPVOID)0x00895B47, 0x9, ASM::NOP);
	SetOp((LPVOID)0x00895B47, (LPVOID)DrawEPosition31, ASM::JMP);
	//-
	SetRange((LPVOID)0x00895B51, 0x9, ASM::NOP);
	SetOp((LPVOID)0x00895B51, (LPVOID)DrawEPosition41, ASM::JMP);
	//----------------------------------
	//EXP
	SetRange((LPVOID)0x008113DE, 5, ASM::NOP);
	SetOp((LPVOID)0x008113DE, (LPVOID)DrawEXP11, ASM::JMP);
	SetRange((LPVOID)0x00811528, 5, ASM::NOP);
	SetOp((LPVOID)0x00811528, (LPVOID)DrawEXP21, ASM::JMP);
	SetRange((LPVOID)0x008116EF, 5, ASM::NOP);
	SetOp((LPVOID)0x008116EF, (LPVOID)DrawEXP31, ASM::JMP);
	SetRange((LPVOID)0x008117F8, 5, ASM::NOP);
	SetOp((LPVOID)0x008117F8, (LPVOID)DrawEXP41, ASM::JMP);
	//------------------------------------------------------------------------------
	//EXPMASTER
	SetRange((LPVOID)0x00810B47, 5, ASM::NOP);
	SetOp((LPVOID)0x00810B47, (LPVOID)DrawEXPMASTER11, ASM::JMP);
	SetRange((LPVOID)0x00810C8B, 5, ASM::NOP);
	SetOp((LPVOID)0x00810C8B, (LPVOID)DrawEXPMASTER21, ASM::JMP);
	SetRange((LPVOID)0x00810E52, 5, ASM::NOP);
	SetOp((LPVOID)0x00810E52, (LPVOID)DrawEXPMASTER31, ASM::JMP);
	SetRange((LPVOID)0x00810F4F, 5, ASM::NOP);
	SetOp((LPVOID)0x00810F4F, (LPVOID)DrawEXPMASTER41, ASM::JMP);
	SetRange((LPVOID)0x00810B7F, 5, ASM::NOP);
	//------------------------------------------------------------------------------
	SetDouble(0x00D461C8, 198);				//-> Experience Bar Max Size
	SetDouble(0x00D461C0, 425);				//-> Exp Number Position X
	SetDouble(0x00D461B8, 431);			//-> Exp Number Position Y
	
	SetFloat(0x00D43220, 0x00);					//-> Top buff icons Size X
	SetFloat(0x00D43224, 0x00);					//-> Top buff icons Size Y
	SetDword(0x004D9746 + 3,480);		//deshabilita el background
	//----------------------------------------------------------------------
	Slot = -1;
	SetCompleteHook(0xE9, 0x0077FDA4, &BackInventory1);
	SetCompleteHook(0xE9, 0x0077FD87, &PointInventory1);

	/**/
	SetCompleteHook(0xE8, 0x0077F7EE, &RemakeCharacterWindow1);
	SetDword((PVOID)(0x0077E935 + 1), 51290);
	SetByte((PVOID)(0x0077E94A + 1), 24);
	SetByte((PVOID)(0x0077E94C + 1), 24);
	SetByte((PVOID)(0x0077E957 + 2), 117);
	SetByte((PVOID)(0x0077E964 + 1), 130);
	SetDword((PVOID)(0x0077E97E + 1), 51290);
	SetByte((PVOID)(0x0077E996 + 1), 24);
	SetByte((PVOID)(0x0077E998 + 1), 24);
	SetByte((PVOID)(0x0077E9A3 + 2), 172);
	SetByte((PVOID)(0x0077E9B3 + 2), 130);
	SetDword((PVOID)(0x0077E9D1 + 1), 51290);
	SetByte((PVOID)(0x0077E9E9 + 1), 24);
	SetByte((PVOID)(0x0077E9EB + 1), 24);
	SetByte((PVOID)(0x0077E9F6 + 1), 237);
	SetByte((PVOID)(0x0077EA05 + 2), 130);
	SetDword((PVOID)(0x0077EA23 + 1), 51290);
	SetByte((PVOID)(0x0077EA3B + 1), 24);
	SetByte((PVOID)(0x0077EA3D + 1), 24);
	SetByte((PVOID)(0x0077EA48 + 2), 292);
	SetByte((PVOID)(0x0077EA58 + 1), 130);
	SetDword((PVOID)(0x0077EA75 + 1), 51290);
	SetByte((PVOID)(0x0077EA8D + 1), 24);
	SetByte((PVOID)(0x0077EA8F + 1), 24);
	SetByte((PVOID)(0x0077EA9A + 2), 347);
	SetByte((PVOID)(0x0077EAAA + 2), 130);
	SetByte((PVOID)(0x007801D9 + 1), 4);
	SetByte((PVOID)(0x007801DD + 1), 42);
	SetByte((PVOID)(0x00780217 + 1), 2);
	SetByte((PVOID)(0x0078023A + 2), 56);
	SetByte((PVOID)(0x0078190D + 1), 4);
	SetByte((PVOID)(0x00781911 + 1), 42);
	SetByte((PVOID)(0x0078194E + 1), 2);
	SetByte((PVOID)(0x00781973 + 2), 56);
	SetByte((PVOID)(0x007830EF + 1), 4);
	SetByte((PVOID)(0x007830F3 + 1), 42);
	SetByte((PVOID)(0x00783130 + 1), 2);
	SetByte((PVOID)(0x00783155 + 2), 56);
	SetByte((PVOID)(0x00782D15 + 1), 4);
	SetByte((PVOID)(0x00782D19 + 1), 42);
	SetByte((PVOID)(0x00782D56 + 1), 2);
	SetByte((PVOID)(0x00782D7C + 2), 56);
	SetByte((PVOID)(0x00782D15 + 1), 4);
	SetByte((PVOID)(0x00782D19 + 1), 42);
	SetByte((PVOID)(0x00782D56 + 1), 2);
	SetByte((PVOID)(0x00782D7C + 2), 56);
	SetByte((PVOID)(0x00784B6D + 1), 4);
	SetByte((PVOID)(0x00784B71 + 1), 42);
	SetByte((PVOID)(0x00784BAE + 1), 2);
	SetByte((PVOID)(0x00784BD4 + 2), 56);
	//-------------------------------------------------------------------	
/*		NEW MOVE DOWNGRADE SYSTEM			*/
		//SetCompleteHook(0xE9,0x00832862, 0x00832897);	//DISABLE GENS BATTLE (BATTLE ZONE MOVE (M))
		//MemorySet(0x00832CF2,0x90,0x5);
		//SetByte((PVOID)(0x00832C44+2),5);				//BARRA AMARELA REDIMENSIONADA
		//////TELA M EM RESOLUÇÃO 800
		//SetByte((PVOID)(0x00830C77+2),34);
		//SetByte((PVOID)(0x00830C86+2),94);
		//SetByte((PVOID)(0x00830C98+2),139);
		//SetByte((PVOID)(0x00830C6A+3),148);				//LARGURA
		//SetDword((PVOID)(0x00830D49),400);				//DIMENSIONAMENTO DO MOVE
		//////TAMANHO DO MOVE - OTIMIZAÇÃO DE TAMANHO
		//SetByte((0x00830D64+2),50);
		//SetByte((0x00830D67+2),55);						//REGULA O TAMANHO DO MOVE
		//SetByte((0x00830E55+2),50);
		//SetByte((0x0083245B+2),50);
		//SetByte((0x00830ED3+2),50);
		//SetByte((0X00830FD6+2),50);
		////RETIRA IMAGENS DO MOVE
		//MemorySet(0x008325D4, 0x90, 0x05);
		//MemorySet(0x00832639, 0x90, 0x05); 
		//MemorySet(0x0083268F, 0x90, 0x05);
		//MemorySet(0x008326D7, 0x90, 0x05);
		//MemorySet(0x00832757, 0x90, 0x05);
		//MemorySet(0x00832794, 0x90, 0x05);  
		/*	NEW MOVE DOWNGRADE SYSTEM */	
//===========================================================
//===========================================================
	SetRange((LPVOID)0x006E899D, 5, ASM::NOP);
	SetRange((LPVOID)0x007126FA, 5, ASM::NOP);
	SetRange((LPVOID)0x005B768F, 5, ASM::NOP);
	SetRange((LPVOID)0x005B770C, 5, ASM::NOP);
	
	SetDouble((PVOID)(0x00D27AF8), 0.5);	
	SetFloat((PVOID)(0x00D461A4), 471);
//===========================================================
//===========================================================


	SetCompleteHook(0xE8, 0x00857746, &CheckMouseWindow); //-- baul check
//--
	SetCompleteHook(0xE8, 0x005B6180, &JCGetScreenWidth);
	//--
	SetCompleteHook(0xE8, 0x0040F2E9, &JCWinIngame); //-- Camara General Renderizado
	SetCompleteHook(0xE8, 0x004D714E, &JCWinIngame); //-- Camara General Renderizado
	SetCompleteHook(0xE8, 0x004D79E7, &JCWinIngame); //-- Camara General Renderizado
	SetCompleteHook(0xE8, 0x004D9756, &JCWinIngame); //-- Camara General Renderizado
	//--
	SetCompleteHook(0xE8, 0x005DB4D5, &JCWinIngame); //-- Camara General Renderizado
	SetCompleteHook(0xE8, 0x005DB1AA, &JCWinIngame); //-- Camara General Renderizado
	SetCompleteHook(0xE8, 0x005DB22F, &JCWinIngame); //-- Camara General Renderizado
	SetCompleteHook(0xE8, 0x005DB322, &JCWinIngame); //-- Camara General Renderizado
	SetCompleteHook(0xE8, 0x005DB3A7, &JCWinIngame); //-- Camara General Renderizado
	SetCompleteHook(0xE8, 0x005DB46D, &JCWinIngame); //-- Camara General Renderizado
	SetCompleteHook(0xE8, 0x005DB4AD, &JCWinIngame); //-- Camara General Renderizado
	SetCompleteHook(0xE8, 0x005DB534, &JCWinIngame); //-- Camara General Renderizado
	SetCompleteHook(0xE8, 0x005DB5C4, &JCWinIngame); //-- Camara General Renderizado
	SetCompleteHook(0xE8, 0x005DB628, &JCWinIngame); //-- Camara General Renderizado
	SetCompleteHook(0xE8, 0x005DB68C, &JCWinIngame); //-- Camara General Renderizado
	SetCompleteHook(0xE8, 0x005DB6ED, &JCWinIngame); //-- Camara General Renderizado
	SetCompleteHook(0xE8, 0x008605BF, &JCWinIngame); //-- load character
	//-
	SetCompleteHook(0xE8, 0x005B8344, &JCGetScreenWidth); //-- check cursor attack
	SetCompleteHook(0xE8, 0x0047FFF4, &JCGetScreenWidth); //-- Load MapName In-game
	SetCompleteHook(0xE8, 0x0048007C, &JCGetScreenWidth); //-- Load MapName In-game
	SetCompleteHook(0xE8, 0x004F2A6C, &JCGetScreenWidth); //-- algo del raven
	SetCompleteHook(0xE8, 0x004F2B55, &JCGetScreenWidth); //-- algo del raven
	SetCompleteHook(0xE8, 0x005B4956, &JCGetScreenWidth);
	SetCompleteHook(0xE8, 0x005B9E22, &JCGetScreenWidth);
	SetCompleteHook(0xE8, 0x005BAFE5, &JCGetScreenWidth);
	SetCompleteHook(0xE8, 0x007D453E, &JCGetScreenWidth);
	SetCompleteHook(0xE8, 0x007DF2D9, &JCGetScreenWidth);
	SetCompleteHook(0xE8, 0x007DFD4B, &JCGetScreenWidth);
	SetCompleteHook(0xE8, 0x007DFD54, &JCGetScreenWidth);
	SetCompleteHook(0xE8, 0x007DFD68, &JCGetScreenWidth);
	SetCompleteHook(0xE8, 0x007F3F87, &JCGetScreenWidth);
	SetCompleteHook(0xE8, 0x007F4A63, &JCGetScreenWidth);
	SetCompleteHook(0xE8, 0x007FAC46, &JCGetScreenWidth);
	SetCompleteHook(0xE8, 0x008346F6, &JCGetScreenWidth);
	SetCompleteHook(0xE8, 0x0085F90C, &JCGetScreenWidth);

	SetOp((LPVOID)0x0081A146, (LPVOID)Master_back, ASM::CALL); //0081A146 1.04e	//00819FF6 1.04d
	SetOp((LPVOID)0x0081A199, (LPVOID)Master_back, ASM::CALL); //0081A199 1.04e //0081A049 1.04d


//===========================================================
	//Login_back.tga
	SetDword(0x006311B6+1,(DWORD)"Custom\\Interface\\Gfx\\Menu\\login_back.tga");
	//Login_me.tga
	SetDword(0x006311D6+1,(DWORD)"Custom\\Interface\\Gfx\\Menu\\Login_me.tga");
	

//	//newui_item_box
	SetDword(0x007D991A+1,(DWORD)"Custom\\Interface\\Gfx\\Menu\\newui_item_box.tga");
	//newui_item_boots
	SetDword(0x00836B7A+1,(DWORD)"Custom\\Interface\\Gfx\\Menu\\newui_item_boots.tga");
	////newui_item_cap
	SetDword(0x00836B9A+1,(DWORD)"Custom\\Interface\\Gfx\\Menu\\newui_item_cap.tga");
	////newui_item_fairy
	SetDword(0x00836BBA+1,(DWORD)"Custom\\Interface\\Gfx\\Menu\\newui_item_fairy.tga");
//	

//	//newui_item_gloves
	SetDword(0x00836C5A+1,(DWORD)"Custom\\Interface\\Gfx\\Menu\\newui_item_gloves.tga");
	//newui_item_lower
	SetDword(0x00836C7A+1,(DWORD)"Custom\\Interface\\Gfx\\Menu\\newui_item_lower.tga");
	//newui_item_ring
	SetDword(0x00836C9A+1,(DWORD)"Custom\\Interface\\Gfx\\Menu\\newui_item_ring.tga");
	//newui_item_necklace
	SetDword(0x00836CBA+1,(DWORD)"Custom\\Interface\\Gfx\\Menu\\newui_item_necklace.tga");
	////newui_item_wing
	//SetDword(0x00836BDA+1,(DWORD)"Custom\\Interface\\Gfx\\Menu\\newui_item_wing.tga");
	//newui_item_weapon(L)
	SetDword(0x00836BFA+1,(DWORD)"Custom\\Interface\\Gfx\\Menu\\newui_item_weapon(L).tga");
	//newui_item_weapon(R)
	SetDword(0x00836C1A+1,(DWORD)"Custom\\Interface\\Gfx\\Menu\\newui_item_weapon(R).tga");
	////newui_item_upper
	SetDword(0x00836C3A+1,(DWORD)"Custom\\Interface\\Gfx\\Menu\\newui_item_upper.tga");

	//-- PartyBar
	SetJmp((LPVOID)0x0084B95E, PartyWindowsMove2);



	SetDword(0x00784DAA+1,(DWORD)"Custom\\Interface\\none.tga");
	//SetDword(0x007D993A+1,(DWORD)"Custom\\Interface\\none.tga");
	//SetDword(0x0084B33A+1,(DWORD)"Custom\\Interface\\none.tga");
	SetDword(0x0084E79A+1,(DWORD)"Custom\\Interface\\none.tga");
	SetDword(0x00879C0A+1,(DWORD)"Custom\\Interface\\none.tga");
	SetDword(0x008804EA+1,(DWORD)"Custom\\Interface\\none.tga");
	SetDword(0x00882D2A+1,(DWORD)"Custom\\Interface\\none.tga");
	//--
	SetDword(0x00784DCA+1,(DWORD)"Custom\\Interface\\none.tga");
	//SetDword(0x007D995A+1,(DWORD)"Custom\\Interface\\none.tga");
	//SetDword(0x0084B35A+1,(DWORD)"Custom\\Interface\\none.tga");
	SetDword(0x0084E7BA+1,(DWORD)"Custom\\Interface\\none.tga");
	SetDword(0x00879C2A+1,(DWORD)"Custom\\Interface\\none.tga");
	SetDword(0x0088050A+1,(DWORD)"Custom\\Interface\\none.tga");
	SetDword(0x00882D4A+1,(DWORD)"Custom\\Interface\\none.tga");
	//--
	SetDword(0x00784DEA+1,(DWORD)"Custom\\Interface\\none.tga");
	//SetDword(0x007D997A+1,(DWORD)"Custom\\Interface\\none.tga");
	//SetDword(0x0084B37A+1,(DWORD)"Custom\\Interface\\none.tga");
	SetDword(0x0084E7DA+1,(DWORD)"Custom\\Interface\\none.tga");
	SetDword(0x00879C4A+1,(DWORD)"Custom\\Interface\\none.tga");
	SetDword(0x0088052A+1,(DWORD)"Custom\\Interface\\none.tga");
	SetDword(0x00882D6A+1,(DWORD)"Custom\\Interface\\none.tga");
	//--
	SetDword(0x00784E0A+1,(DWORD)"Custom\\Interface\\none.tga");
	//SetDword(0x007D999A+1,(DWORD)"Custom\\Interface\\none.tga");
	//SetDword(0x0084B39A+1,(DWORD)"Custom\\Interface\\none.tga");
	SetDword(0x0084E7FA+1,(DWORD)"Custom\\Interface\\none.tga");
	SetDword(0x00879C6A+1,(DWORD)"Custom\\Interface\\none.tga");
	SetDword(0x0088054A+1,(DWORD)"Custom\\Interface\\none.tga");
	SetDword(0x00882D8A+1,(DWORD)"Custom\\Interface\\none.tga");
	//--
	SetDword(0x00784E4A+1,(DWORD)"Custom\\Interface\\none.tga");
	SetDword(0x007CDE0A+1,(DWORD)"Custom\\Interface\\none.tga");
	//SetDword(0x007D99DA+1,(DWORD)"Custom\\Interface\\none.tga");
	SetDword(0x0084B3DA+1,(DWORD)"Custom\\Interface\\none.tga");
	SetDword(0x0084E83A+1,(DWORD)"Custom\\Interface\\none.tga");
	SetDword(0x00879CAA+1,(DWORD)"Custom\\Interface\\none.tga");
	SetDword(0x0088058A+1,(DWORD)"Custom\\Interface\\none.tga");
	SetDword(0x00882DCA+1,(DWORD)"Custom\\Interface\\none.tga");
	SetDword(0x008842CA+1,(DWORD)"Custom\\Interface\\none.tga");
	//--
	SetDword(0x00784E6A+1,(DWORD)"Custom\\Interface\\none.tga");
	SetDword(0x007CDE2A+1,(DWORD)"Custom\\Interface\\none.tga");
	//SetDword(0x007D99FA+1,(DWORD)"Custom\\Interface\\none.tga");
	SetDword(0x0084B3FA+1,(DWORD)"Custom\\Interface\\none.tga");
	SetDword(0x0084E85A+1,(DWORD)"Custom\\Interface\\none.tga");
	SetDword(0x00879CCA+1,(DWORD)"Custom\\Interface\\none.tga");
	SetDword(0x008805AA+1,(DWORD)"Custom\\Interface\\none.tga");
	SetDword(0x00882DEA+1,(DWORD)"Custom\\Interface\\none.tga");
	SetDword(0x008842EA+1,(DWORD)"Custom\\Interface\\none.tga");
	//--
	SetDword(0x00784E8A+1,(DWORD)"Custom\\Interface\\none.tga");
	SetDword(0x007CDE4A+1,(DWORD)"Custom\\Interface\\none.tga");
	//SetDword(0x007D9A1A+1,(DWORD)"Custom\\Interface\\none.tga");
	SetDword(0x0084B41A+1,(DWORD)"Custom\\Interface\\none.tga");
	SetDword(0x0084E87A+1,(DWORD)"Custom\\Interface\\none.tga");
	SetDword(0x00879CEA+1,(DWORD)"Custom\\Interface\\none.tga");
	SetDword(0x008805CA+1,(DWORD)"Custom\\Interface\\none.tga");
	SetDword(0x00882E0A+1,(DWORD)"Custom\\Interface\\none.tga");
	SetDword(0x0088430A+1,(DWORD)"Custom\\Interface\\none.tga");
	//--
	SetDword(0x00784E2A+1,(DWORD)"Custom\\Interface\\none.tga");
	SetDword(0x007CDDEA+1,(DWORD)"Custom\\Interface\\none.tga");
	//SetDword(0x007D99BA+1,(DWORD)"Custom\\Interface\\none.tga");
	SetDword(0x0084B3BA+1,(DWORD)"Custom\\Interface\\none.tga");
	SetDword(0x0084E81A+1,(DWORD)"Custom\\Interface\\none.tga");
	SetDword(0x00879C8A+1,(DWORD)"Custom\\Interface\\none.tga");
	SetDword(0x0088056A+1,(DWORD)"Custom\\Interface\\none.tga");
	SetDword(0x00882DAA+1,(DWORD)"Custom\\Interface\\none.tga");
	SetDword(0x008842AA+1,(DWORD)"Custom\\Interface\\none.tga");
}