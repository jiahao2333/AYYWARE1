/*
Syn's AyyWare Framework 2015
*/

#include "变量声明_Tab.h"
#include "声明_绘制引擎.h"
#include "Utilities.h"
#include <time.h>
#include "Interfaces.h"




void 类型_杂项::Init()
{
	// Idk
}

// Don't really need to do anything in here
void 类型_杂项::Move(CUserCmd *pCmd, bool &bSendPacket) {}
// Main ESP Drawing loop
void 类型_杂项::Draw()
{
	// Crosshair
	if (Menu::Window.RadarTab.十字准心.取状态 ())
		绘制准心();

	// Recoil Crosshair
	if (Menu::Window.RadarTab.弹道准心.取状态())
	{
		绘制弹道准心();
	}
	if (Menu::Window.RadarTab.NameSteal.取状态())
	{
		NameSteal();
	}
}


// Draw a basic crosshair
void 类型_杂项::绘制准心()
{
	// Crosshair
	RECT View = Render::取屏幕大小();
	int MidX = View.right / 2;
	int MidY = View.bottom / 2;
	Render::绘制直线(MidX - 11, MidY - 1,22,3, Color(0, 0, 0, 255));
	Render::绘制直线(MidX - 1, MidY - 11, 3, 22, Color(0, 0, 0, 255));
	Render::绘制直线(MidX - 10, MidY, 20, 1, Color(0, 255, 0, 255));
	Render::绘制直线(MidX, MidY - 10, 1, 20, Color(0, 255, 0, 255));

}



// Recoil crosshair
void 类型_杂项::绘制弹道准心()
{

	IClientEntity* pLocal = hackManager.pLocal();

	Vector ViewAngles;
	Interfaces::Engine->取游戏瞄准角度(ViewAngles);
	ViewAngles += pLocal->localPlayerExclusive()->GetAimPunchAngle() * 2.f;

	Vector fowardVec;
	AngleVectors(ViewAngles, &fowardVec);
	fowardVec *= 10000;

	// Get ray start / end
	Vector start = pLocal->GetOrigin() + pLocal->GetViewOffset();
	Vector end = start + fowardVec, endScreen;

	if (Render::矩阵转换(end, endScreen) && pLocal->是否可用())
	{
		Render::绘制线条(endScreen.x - 4, endScreen.y - 4, endScreen.x + 4, endScreen.y + 4, Color(0, 255, 0, 255));
		Render::绘制线条(endScreen.x + 4, endScreen.y - 4, endScreen.x - 4, endScreen.y + 4, Color(0, 255, 0, 255));
		Render::绘制线条(endScreen.x - 2, endScreen.y - 2, endScreen.x + 2, endScreen.y + 2, Color(0, 0, 0, 200));
		Render::绘制线条(endScreen.x + 2, endScreen.y - 2, endScreen.x - 2, endScreen.y + 2, Color(0, 0, 0, 200));
	}
}








static __declspec(naked) void __cdecl Invoke_NET_SetConVar(void* pfn, const char* cvar, const char* value)
{
	__asm
	{
		push    ebp
		mov     ebp, esp
		and esp, 0FFFFFFF8h
		sub     esp, 44h
		push    ebx
		push    esi
		push    edi
		mov     edi, cvar
		mov     esi, value
		jmp     pfn
	}
}





void DECLSPEC_NOINLINE NET_SetConVar(const char* value, const char* cvar)
{
	static DWORD setaddr = Utilities::内存操作::查找内存_字节集("engine.dll", (PBYTE)"\x8D\x4C\x24\x1C\xE8\x00\x00\x00\x00\x56", "xxxxx????x");
	if (setaddr != 0)
	{
		void* pvSetConVar = (char*)setaddr;
		Invoke_NET_SetConVar(pvSetConVar, cvar, value);
	}
}

//给后来维护者看 这是改名
//void change_name(const char* name)
//{
//	ConVar* nameConvar = Interfaces::CVar->FindVar("name");
//	*(int*)((DWORD)&nameConvar->fnChangeCallback + 0xC) = 0;
//	nameConvar->ConVar::SetValue(name);
//}

//这是另一种方法的改名
void change_name(const char* name)
{
	if (Interfaces::Engine->是否在游戏() && Interfaces::Engine->IsConnected())
		NET_SetConVar(name, "name");
}

//偷名要配合改名使用
void 类型_杂项::NameSteal()
{
	const char* spamFix = "\n\xAD\xAD\xAD";//先改一次这个名字才可以无限改名
	change_name(spamFix);
	static clock_t start_t = clock();
	double timeSoFar = (double)(clock() - start_t) / CLOCKS_PER_SEC;
	if (timeSoFar < 0.001)
		return;

	std::vector < std::string > Names;

	for (int i = 0; i < Interfaces::EntList->GetHighestEntityIndex(); i++)
	{

		IClientEntity* entity = Interfaces::EntList->GetClientEntity(i);

		player_info_t pInfo;

		if (entity && hackManager.pLocal()->GetTeamNum() == entity->GetTeamNum() && entity != hackManager.pLocal())
		{
			ClientClass* cClass = (ClientClass*)entity->GetClientClass();

			if (cClass->m_ClassID == (int)对象ID::CCSPlayer)
			{
				if (Interfaces::Engine->取玩家信息(i, &pInfo))
				{
					if (!strstr(pInfo.name, "GOTV"))
						Names.push_back(pInfo.name);
				}
			}
		}
	}

	static bool wasSpamming = true;

	int randomIndex = rand() % Names.size();
	char buffer[128];
	sprintf_s(buffer, "%s ", Names[randomIndex].c_str());

	if (wasSpamming)
	{
		change_name(buffer);
	}
	else
	{
		change_name("p$i 1337");
	}

	start_t = clock();

}