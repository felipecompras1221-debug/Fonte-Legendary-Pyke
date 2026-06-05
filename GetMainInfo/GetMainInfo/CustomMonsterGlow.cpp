#include "stdafx.h"
#include "CustomMonsterGlow.h"
#include "MemScript.h"

cCustomGlow gCustomMonsterGlow;

cCustomGlow::cCustomGlow()
{
	this->Init();
}

cCustomGlow::~cCustomGlow()
{
	
}

void cCustomGlow::Init()
{
	for (int n = 0; n < MAX_CUSTOM_MONSTERGLOW; n++)
	{
		this->m_CustomGlowInfo[n].Index = -1;
	}
}

void cCustomGlow::Load(char * path)
{
	CMemScript* lpMemScript = new CMemScript;

	int Index = 0;

	if(lpMemScript == 0)
	{
		printf(MEM_SCRIPT_ALLOC_ERROR,path);
		return;
	}

	if(lpMemScript->SetBuffer(path) == 0)
	{
		printf(lpMemScript->GetLastError());
		delete lpMemScript;
		return;
	}

	this->Init();

	try
	{
		while(true)
		{
			if(lpMemScript->GetToken() == TOKEN_END)
			{
				break;
			}

			if(strcmp("end",lpMemScript->GetString()) == 0)
			{
				break;
			}

			CUSTOM_MONSTERGLOW_INFO info;

			info.Index = Index++;

			info.MonsterID = lpMemScript->GetNumber();

			info.Golden = lpMemScript->GetAsNumber();
			//--
			info.GlowColorR = (lpMemScript->GetAsFloatNumber());

			info.GlowColorG = (lpMemScript->GetAsFloatNumber());

			info.GlowColorB = (lpMemScript->GetAsFloatNumber());

			this->SetInfo(info);
		}
	}
	catch(...)
	{
		printf(lpMemScript->GetLastError());
	}

	delete lpMemScript;
}

void cCustomGlow::SetInfo(CUSTOM_MONSTERGLOW_INFO info)
{
	if(info.Index < 0 || info.Index >= MAX_CUSTOM_MONSTERGLOW)
	{
		return;
	}

	this->m_CustomGlowInfo[info.Index] = info;
}