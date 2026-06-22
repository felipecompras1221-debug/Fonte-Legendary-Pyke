#pragma once

#define max_ceffect					3000
#define PetCreateEffect			((int(__cdecl*)(int a4, int a5, int a6, vec3_t color, int a8, int a9, __int16 a10, __int16 a11, __int16 a12, __int16 a13, float a14, __int16 a1)) 0x006D9070)
#define PetCreateParticle2		((int(__cdecl*)(int a1, vec3_t Bone1, int a3, vec3_t color, int a5, float size, int a7)) 0x0074CD30)
#define PetTransformPosition		((int(__thiscall*)(int This, int a2, vec3_t WorldPos, vec3_t Bone1, bool a5)) 0x00545030)
#define PetCreateSprite			((int(__cdecl*)(int a1, vec3_t Bone1, float size, vec3_t color, int ObjPos, float, int)) 0x00771310)
#define PetBoneTransform		*(int*)0x7BC09C0
#define PetDrawRenderObjectR		((void(__cdecl*)(int a1, int a2, int a3, int a4)) 0x005DE260)
#define PetJoint(x)				((0x30 * x) + 0x7BC08A0)

struct PET_EFFECT_CUSTOM
{
	int Index;
	int ItemIndex;
	int Join;
	int TypeEffect;
	int EffectCode;
	float EffectSize;
	int LargeRand;
	float ColorR;
	float ColorG;
	float ColorB;
};

class cCEffectPet
{
public:
	cCEffectPet();
	virtual ~cCEffectPet();
	void Init();
	void Load(PET_EFFECT_CUSTOM* info);
	void static addEffect(int a1, int a2, int a3, int a4); // OK
public:
	std::vector<PET_EFFECT_CUSTOM> m_PetCEffect;

}; extern cCEffectPet gCustomCEffectPet;