#pragma once

typedef unsigned __int64 QWORD;

#define WIN32_LEAN_AND_MEAN

#define _WIN32_WINNT _WIN32_WINNT_WINXP

#define VERSION	"1.0.0.0"

// System Include
#include <windows.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <winsock2.h>
#include <Mmsystem.h>
#include <time.h>
#include <gl\GL.h>
#include <gl\GLU.h>
#include "detours.h"
#include <Shellapi.h>
#include <vector>
#include <map>
#include <Windows.h>
#include <algorithm>
#include <winioctl.h>
#include <algorithm>
//--MaxGameInstances Main.exe
#include <tlhelp32.h>
#include <tchar.h>

#define va_start _crt_va_start
#define va_arg _crt_va_arg
#define va_end _crt_va_end

#pragma comment(lib,"ws2_32.lib")
#pragma comment(lib,"Winmm.lib")
#pragma comment(lib,"glu32.lib")
#pragma comment(lib,"Opengl32.lib")
#pragma comment(lib,"detours.lib")
#pragma comment(lib,"cg.lib")
#pragma comment(lib,"cgGL.lib")
#pragma comment(lib,"wzMUQuiz.lib")

#define PREMIUN	1
#define MAX_CHAT_TYPE1			10

#define MAX_CUSTOM_GLOVES	50
#define MAX_CUSTOM_BOW		50
#define MAX_PET_ITEM		300
#define MAX_CUSTOMCLOAK		20
	

#define MAX_CUSTOM_WING			100
#define MAX_REMAKE_EFFECT		100
#define MAX_CUSTOM_ITEM_INFO	1000
#define MAX_POSITION_ITEM		1000
//--
#define MAX_CUSTOPETEFFECT			2000
#define MAX_DYNAMIC_WING_EFFECT		5000
#define MAX_CUSTOM_WING_EFFECT		5000

#define UPDATE 15

#define ADD_PARTY_LEADER 0

#define LODWORD(h)					((DWORD)(__int64(h) & __int64(0xffffffff)))

#ifndef RANK_DYNAMIC_EX
#define RANK_DYNAMIC_EX	1
#endif

#define SLOTPET 1
#define JEWELBANKVER2		1
