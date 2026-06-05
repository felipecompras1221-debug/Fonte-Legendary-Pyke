#include "stdafx.h"
#include "FullViewMode.h"
#include "Util.h"
#include "TMemory.h"

cFullViewMode gFullViewMode;

//Todo código pego na internet pode ser melhorado e corrigido.
//Esse aqui estava feio, fora de ordem. Pesado nas funções. FUI

void FullViewModeInit()
{
	gFullViewMode.Hidden = false;
}

void NewUISystemUpdate()
{
	if (pIsKeyRelease(VK_F11)) 
	{
		gFullViewMode.Hidden = !gFullViewMode.Hidden;
		if (gFullViewMode.Hidden)
		{
			gFullViewMode.BackupHeight = *(DWORD*)(0x004D9746 + 3);
			SetDword(0x004D9746 + 3, 480);
		}
		else 
		{
			SetDword(0x004D9746 + 3, gFullViewMode.BackupHeight);
		}
	}
	if (gFullViewMode.Hidden == false)
	{
		((void(__thiscall*)(DWORD)) 0x00860AC0)(((DWORD(*)()) 0x861110)());
	}
}

void NewUISystemRender()
{
	if (gFullViewMode.Hidden == false)
	{
		((void(__thiscall*)(DWORD)) 0x00860B10)(((DWORD(*)()) 0x861110)());
	}
}

void RenderInfomation()
{
	if (gFullViewMode.Hidden == false)
	{
		((void(*)()) 0x004D5EC0)();
	}
}

void RenderCursor()
{
	if (gFullViewMode.Hidden == false)
	{
		((void(*)()) 0x005BB0B0)();
	}
}

void cFullViewMode::Load()
{
	FullViewModeInit();
	SetCompleteHook(0xE8, 0x004D9344, &NewUISystemUpdate);
	SetCompleteHook(0xE8, 0x004D9CC2, &NewUISystemRender);
	SetCompleteHook(0xE8, 0x004D9CCC, &RenderInfomation);
	SetCompleteHook(0xE8, 0x004D9CDB, &RenderCursor); //remove it if you want to render the cursor
}