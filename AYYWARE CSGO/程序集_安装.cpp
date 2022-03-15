/*
Syn's Payhake Framework for Insanity & Razor
*/

#define _CRT_SECURE_NO_WARNINGS
#define strenc( s ) ( s )

#include "Hacks.h"
#include "Interfaces.h"
#include "声明_绘制引擎.h"
#include "变量声明_Tab.h"



类型_透视 Esp;
类型_杂项 Visuals;
类型_自动瞄准 RageBot;


void Hacks::安装外挂()
{
	Esp.Init();
	Visuals.Init();
	RageBot.Init();


	hackManager.安装(&Esp);
	hackManager.安装(&Visuals);
	hackManager.安装(&RageBot);
	hackManager.激活();
}


////////NEU/////////
void DiLight()
{
	IClientEntity *pLocal = hackManager.pLocal();

	RECT scrn = Render::取屏幕大小();

	// Loop through all active entitys
	for (int i = 0; i < Interfaces::EntList->GetHighestEntityIndex(); i++)
	{
		// Get the entity
		IClientEntity *pEntity = Interfaces::EntList->GetClientEntity(i);
		player_info_t pinfo;

		// The entity isn't some laggy peice of shit or something
		if (pEntity &&  pEntity != pLocal)
		{
			//
			if (Interfaces::Engine->取玩家信息(i, &pinfo) && pEntity->是否可用() && !pEntity->IsDormant())
			{
				dlight_t* pElight = Interfaces::Dilight->CL_AllocElight(i);
				pElight->origin = pEntity->GetOrigin() + Vector(0.0f, 0.0f, 35.0f);
				pElight->radius = 1000.0f;
				pElight->color.b = 0;
				pElight->color.g = 0;
				pElight->color.r = 255;
				pElight->die = Interfaces::Globals->curtime + 0.05f;
				pElight->decay = pElight->radius / 5.0f;
				pElight->key = i;

				dlight_t* pDlight = Interfaces::Dilight->CL_AllocDlight(i);
				pDlight->origin = pEntity->GetOrigin();
				pDlight->radius = 1000.0f;
				pDlight->color.b = 0;
				pDlight->color.g = 0;
				pDlight->color.r = 255;
				pDlight->die = Interfaces::Globals->curtime + 0.05f;
				pDlight->decay = pDlight->radius; // / 5.0f;
				pDlight->key = i;
			}
		}
	}
}

void Hacks::DrawHacks()
{
	IClientEntity *pLocal = hackManager.pLocal();

	void Hooked__PlaySoundCSGO(const char* fileName);

	hackManager.Draw();
	//--------------------------------
		
}


//---------------------------------------------------------------------//
HackManager hackManager;

// Register a new hack
void HackManager::安装(CHack* hake)
{
	Hacks.push_back(hake);
	hake->Init();
}

// Draw all the hakes
void HackManager::Draw()
{
	if (!是否激活)
		return;

	// Grab the local player for drawing related hacks
	pLocalInstance = Interfaces::EntList->GetClientEntity(Interfaces::Engine->取本人基址());
	if (!pLocalInstance) return;

	for (auto &hack : Hacks)
	{
		hack->Draw();
	}
}

// Handle all the move hakes
void HackManager::Move(CUserCmd *pCmd,bool &bSendPacket)
{
	if (!是否激活)
		return;

	// Grab the local player for move related hacks
	pLocalInstance = Interfaces::EntList->GetClientEntity(Interfaces::Engine->取本人基址());
	if (!pLocalInstance) return;

	for (auto &hack : Hacks)
	{
		hack->Move(pCmd,bSendPacket); // 
	}
}

IClientEntity* HackManager::pLocal()
{
	return pLocalInstance;
}


void HackManager::激活()
{
	是否激活 = true;
}