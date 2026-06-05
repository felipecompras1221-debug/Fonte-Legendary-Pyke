#pragma once

#define MAX_CUSTOM_MONSTERGLOW 100

struct CUSTOM_MONSTERGLOW_INFO
{
	int Index;
	int	MonsterID;
	int Golden;
	float GlowColorR;
	float GlowColorG;
	float GlowColorB;
};

class cCustomGlow
{
public:
	cCustomGlow();
	virtual ~cCustomGlow();
	void Init();
	void Load(char* path);
	void SetInfo(CUSTOM_MONSTERGLOW_INFO info);
public:
	CUSTOM_MONSTERGLOW_INFO m_CustomGlowInfo[MAX_CUSTOM_MONSTERGLOW];
};

extern cCustomGlow gCustomMonsterGlow;