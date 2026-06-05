#pragma once

#define pIsKeyNone				((bool(__cdecl*)(int)) 0x791030)
#define pIsKeyRelease			((bool(__cdecl*)(int)) 0x791050)
#define pIsKeyPress				((bool(__cdecl*)(int)) 0x791070)
#define pIsKeyRepeat			((bool(__cdecl*)(int)) 0x791090)

class cFullViewMode
{
public:
	void Load();

	bool Hidden;
	int  BackupHeight;
private:

};
extern cFullViewMode gFullViewMode;