#pragma once
#define pDrawInterfaceNumBer   ((double(__stdcall*)(float X, float Y, int num, float size)) 0x854FE0)
#define RenderShowSkill	((int(__thiscall*)(DWORD * This, int Skill, float X, float Y, float W, float H)) 0x00813DC0)
#define RenderNumber ((float(__cdecl*)(float x, float y, int iNum, float fScale)) 0x00791000)
#define DisplayInfoBarCharacter				((int(__fastcall*)(int a1, int a2, signed int a3, signed int a4, char a5)) 0x416640)
#define BeginOpengl							((void(__cdecl*)(GLint x, int a2, GLsizei width, GLsizei height)) 0x00636480)

#define CGetScreenWidth2			((signed int(*)()) 0x005C6E80)
#define pCheckMouseOver				((bool(__cdecl*)(int a1, int a2, int a3, int a4)) 0x00790B10)



enum iInterface1
{
   iNewCharacter1 = 0x7A48,
   iNewInventory1 = 0x7A49,
   iNewWinpush1 = 0x7A4A,
   iNewFastMenu1 = 0x7A4B,
   iNewSkillBox1 = 0x7A50,
   iNewParty1 = 0x910,
   iNewGuild1 = 0x904,
};

void		NewInterface();
