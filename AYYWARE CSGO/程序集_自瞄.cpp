/*
Syn's AyyWare Framework 2015
*/

#include "变量声明_Tab.h"
#include "声明_绘制引擎.h"

void 类型_自动瞄准::Move(CUserCmd *pCmd, bool &bSendPacket)
{

}
void 类型_自动瞄准::Init()
{
	是否能开枪 = false;
	自瞄锁定 = false;
	对象ID = -1;
}

void 类型_自动瞄准::Draw()
{
	IClientEntity* pLocalEntity = (IClientEntity*)Interfaces::EntList->GetClientEntity(Interfaces::Engine->取本人基址());
	if (!pLocalEntity)
		return;


	// Aimbot
	if (Menu::Window.AimBotTab.自动瞄准.取状态())
		子程序_自动瞄准();

	if (Menu::Window.AimBotTab.自动扳机.取状态())
	{
		int id = *(int*)((DWORD)pLocalEntity + 0xB3E4);

		if (id > 0 && id < 64)
		{
			IClientEntity* pEntity = (IClientEntity*)Interfaces::EntList->GetClientEntity(id);
			if (pEntity && pEntity->是否可用() && pEntity->GetTeamNum() != hackManager.pLocal()->GetTeamNum())
			{
				mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
				mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
			}
		}
	}
}








void 类型_自动瞄准::子程序_自动瞄准()
{
	IClientEntity* pTarget = nullptr;
	IClientEntity* pLocal = hackManager.pLocal();
	bool 是否寻找瞄准对象 = true;
	//自瞄锁定 = false;

	if (自瞄锁定 && 对象ID >= 0 && HitBox >= 0)
	{
		pTarget = Interfaces::EntList->GetClientEntity(对象ID);
		if (pTarget && 判断目标是否符合要求(pTarget))
		{
			HitBox = 取瞄准部位(pTarget);
			if (HitBox >= 0)
			{
				Vector ViewOffset = pLocal->GetOrigin() + pLocal->GetViewOffset();
				Vector View;
				Interfaces::Engine->取游戏瞄准角度(View);
				if (Menu::Window.AimBotTab.自动压枪.取状态())
				{
					Vector AimAngle;
					AimAngle = pLocal->localPlayerExclusive()->GetAimPunchAngle()* 2.f;
					View.x = View.x + AimAngle.x;
					View.y = View.y + AimAngle.y;
				}
				float FoV = 取角度差(ViewOffset, View, pTarget, HitBox);
				if (FoV < (float)Menu::Window.AimBotTab.瞄准范围.取值())
					是否寻找瞄准对象 = false;
			}
		}
	}

	if (是否寻找瞄准对象)
	{
		对象ID = 0;
		pTarget = nullptr;
		HitBox = -1;
		switch (0)//瞄准选择
		{
		case 0:
			对象ID = 取最近玩家_准心距离();
			break;
		case 1:
			对象ID = 取最近玩家_距离();
			break;
		case 2:
			对象ID = 取最近玩家_血量();
			break;
		}
		if (对象ID >= 0)
		{
			pTarget = Interfaces::EntList->GetClientEntity(对象ID);
		}
		else
		{
			pTarget = nullptr;
			HitBox = -1;
		}
	}

	if (对象ID >= 0 && pTarget)
	{
		HitBox = 取瞄准部位(pTarget);


		if (GetAsyncKeyState(Menu::Window.AimBotTab.自瞄按键.取值()) == 0)
		{
			对象ID = -1;
			pTarget = nullptr;
			HitBox = -1;
			return;
		}

		if (GetAsyncKeyState(Menu::Window.AimBotTab.自瞄按键.取值()) == 0)
		{
		}
		else
		{
			float pointscale = -3.f; // Aim height

			Vector AimPoint = GetHitboxPosition(pTarget, HitBox) + Vector(0, 0, pointscale);
			瞄准目标(pLocal, AimPoint);
		}

		瞄准目标(pLocal, AimPoint);
	}



}

bool 类型_自动瞄准::判断目标是否符合要求(IClientEntity* pEntity)
{
	// Is a valid player
	if (pEntity && pEntity->IsDormant() == false && pEntity->是否可用() && pEntity->GetIndex() != hackManager.pLocal()->GetIndex())
	{
		// Entity Type checks
		ClientClass *pClientClass = pEntity->GetClientClass();
		player_info_t pinfo;
		if (pClientClass->m_ClassID == (int)对象ID::CCSPlayer && Interfaces::Engine->取玩家信息(pEntity->GetIndex(), &pinfo))
		{
			// Team Check
			if (pEntity->GetTeamNum() != hackManager.pLocal()->GetTeamNum() || Menu::Window.AimBotTab.瞄准队友.取状态())
			{
				// Spawn Check
				if (!pEntity->HasGunGameImmunity())
				{
					return true;
				}
			}
		}
	}

	// They must have failed a requirement
	return false;
}

float 类型_自动瞄准::取角度差(Vector ViewOffSet, Vector View, IClientEntity* pEntity, int aHitBox)
{
	// Anything past 180 degrees is just going to wrap around
	CONST FLOAT MaxDegrees = 180.0f;

	// Get local angles
	Vector Angles = View;

	// Get local view / eye position
	Vector Origin = ViewOffSet;

	// Create and intiialize vectors for calculations below
	Vector Delta(0, 0, 0);
	//Vector Origin(0, 0, 0);
	Vector Forward(0, 0, 0);

	// Convert angles to normalized directional forward vector
	AngleVectors(Angles, &Forward);
	Vector AimPos = GetHitboxPosition(pEntity, aHitBox);
	// Get delta vector between our local eye position and passed vector
	VectorSubtract(AimPos, Origin, Delta);
	//Delta = AimPos - Origin;

	// Normalize our delta vector
	Normalize(Delta, Delta);

	// Get dot product between delta position and directional forward vectors
	FLOAT DotProduct = Forward.Dot(Delta);

	// Time to calculate the field of view
	return (acos(DotProduct) * (MaxDegrees / PI));
}

int 类型_自动瞄准::取最近玩家_准心距离()
{
	int target = -1;
	float minFoV = (float)Menu::Window.AimBotTab.瞄准范围.取值();

	IClientEntity* pLocal = hackManager.pLocal();
	Vector ViewOffset = pLocal->GetOrigin() + pLocal->GetViewOffset();
	Vector View; Interfaces::Engine->取游戏瞄准角度(View);
	if (Menu::Window.AimBotTab.自动压枪.取状态())
	{
		Vector AimAngle;
		AimAngle = pLocal->localPlayerExclusive()->GetAimPunchAngle()* 2.f;
		View.x = View.x + AimAngle.x;
		View.y = View.y + AimAngle.y;
	}


	for (int i = 0; i < Interfaces::EntList->GetMaxEntities(); i++) //GetHighestEntityIndex()
	{
		IClientEntity *pEntity = Interfaces::EntList->GetClientEntity(i);
		if (判断目标是否符合要求(pEntity))
		{
			int NewHitBox = 取瞄准部位(pEntity);
			if (NewHitBox >= 0)
			{
				float fov = 取角度差(ViewOffset, View, pEntity, 0);
				if (fov < minFoV)
				{
					minFoV = fov;
					target = i;
				}
			}
		}
	}

	return target;
}

int 类型_自动瞄准::取最近玩家_距离()
{
	// Target selection
	int target = -1;
	int minDist = 8129;

	IClientEntity* pLocal = hackManager.pLocal();
	Vector ViewOffset = pLocal->GetOrigin() + pLocal->GetViewOffset();
	Vector View; Interfaces::Engine->取游戏瞄准角度(View);

	for (int i = 0; i < Interfaces::EntList->GetMaxEntities(); i++)
	{
		IClientEntity *pEntity = Interfaces::EntList->GetClientEntity(i);
		if (判断目标是否符合要求(pEntity))
		{
			int NewHitBox = 取瞄准部位(pEntity);
			if (NewHitBox >= 0)
			{
				Vector Difference = pLocal->GetOrigin() - pEntity->GetOrigin();
				int Distance = Difference.Length();
				float fov = 取角度差(ViewOffset, View, pEntity, 0);
				if (Distance < minDist && fov < (float)Menu::Window.AimBotTab.瞄准范围.取值())
				{
					minDist = Distance;
					target = i;
				}
			}
		}
	}

	return target;
}

int 类型_自动瞄准::取最近玩家_血量()
{
	// Target selection
	int target = -1;
	int minHealth = 101;

	IClientEntity* pLocal = hackManager.pLocal();
	Vector ViewOffset = pLocal->GetOrigin() + pLocal->GetViewOffset();
	Vector View; Interfaces::Engine->取游戏瞄准角度(View);

	for (int i = 0; i < Interfaces::EntList->GetMaxEntities(); i++)
	{
		IClientEntity *pEntity = Interfaces::EntList->GetClientEntity(i);
		if (判断目标是否符合要求(pEntity))
		{
			int NewHitBox = 取瞄准部位(pEntity);
			if (NewHitBox >= 0)
			{
				int Health = pEntity->GetHealth();
				float fov = 取角度差(ViewOffset, View, pEntity, 0);
				if (Health < minHealth && fov < (float)Menu::Window.AimBotTab.瞄准范围.取值())
				{
					minHealth = Health;
					target = i;
				}
			}
		}
	}

	return target;
}


int 类型_自动瞄准::取瞄准部位(IClientEntity* pEntity)
{
	IClientEntity* pLocal = hackManager.pLocal();
	std::vector<int> HitBoxesToScan;

			switch (Menu::Window.AimBotTab.瞄准部位.取值())
			{
			case 0: //头
				HitBoxesToScan.push_back((int)人物部位::Head);
				break;
			case 1: //脖子
				HitBoxesToScan.push_back((int)人物部位::Neck);
				//HitBoxesToScan.push_back((int)人物部位::NeckLower);
				break;
			case 2: //胸 
				HitBoxesToScan.push_back((int)人物部位::UpperChest);
				HitBoxesToScan.push_back((int)人物部位::Chest);
				HitBoxesToScan.push_back((int)人物部位::Stomach);
				HitBoxesToScan.push_back((int)人物部位::Pelvis);
				HitBoxesToScan.push_back((int)人物部位::LowerChest);
				break;
			case 3: //全身模式
				HitBoxesToScan.push_back((int)人物部位::Head);//1
				HitBoxesToScan.push_back((int)人物部位::Neck);//2
				//HitBoxesToScan.push_back((int)人物部位::NeckLower);//3
				HitBoxesToScan.push_back((int)人物部位::Pelvis);//4
				HitBoxesToScan.push_back((int)人物部位::Stomach);//5
				HitBoxesToScan.push_back((int)人物部位::LowerChest);//6
				HitBoxesToScan.push_back((int)人物部位::Chest);//7
				HitBoxesToScan.push_back((int)人物部位::UpperChest);//8
				HitBoxesToScan.push_back((int)人物部位::RightThigh);//9
				HitBoxesToScan.push_back((int)人物部位::LeftThigh);//10
				HitBoxesToScan.push_back((int)人物部位::LeftThigh);//11
				HitBoxesToScan.push_back((int)人物部位::RightShin);//12
				HitBoxesToScan.push_back((int)人物部位::LeftShin);//13
				HitBoxesToScan.push_back((int)人物部位::RightFoot);//14
				HitBoxesToScan.push_back((int)人物部位::LeftFoot);//15
				HitBoxesToScan.push_back((int)人物部位::RightHand);
				HitBoxesToScan.push_back((int)人物部位::LeftHand);
				HitBoxesToScan.push_back((int)人物部位::RightUpperArm);
				HitBoxesToScan.push_back((int)人物部位::RightLowerArm);
				HitBoxesToScan.push_back((int)人物部位::LeftUpperArm);
				HitBoxesToScan.push_back((int)人物部位::LeftLowerArm);
				break;




			}
	for (auto HitBoxID : HitBoxesToScan)
	{
			if (GameUtils::可视检查(hackManager.pLocal(), pEntity, HitBoxID) || !Menu::Window.AimBotTab.可视检查.取状态())
				return HitBoxID;
	}

	return -1;
}


bool 类型_自动瞄准::瞄准目标(IClientEntity* pLocal, Vector point)
{
	bool ReturnValue = false;
	// Get the full angles
	if (point.Length() == 0) return ReturnValue;

	Vector angles;
	Vector src = pLocal->GetOrigin() + pLocal->GetViewOffset();
	CalcAngle(src, point, angles);
	if (angles[0] != angles[0] || angles[1] != angles[1])
	{
		return ReturnValue;
	}


	自瞄锁定 = true;
	Vector ViewOffset = pLocal->GetOrigin() + pLocal->GetViewOffset();
	if (!是否能开枪)
		LastAimstepAngle = LastAngle;
	float fovLeft = 取角度差(ViewOffset, LastAimstepAngle, Interfaces::EntList->GetClientEntity(对象ID), 0);

		ReturnValue = true;
		if (Menu::Window.AimBotTab.自动压枪.取状态())
		{
			Vector AimAngle;
			AimAngle = pLocal->localPlayerExclusive()->GetAimPunchAngle()* 2.f;
			angles.x = angles.x - AimAngle.x;
			angles.y = angles.y - AimAngle.y;
		}

		Interfaces::Engine->写游戏瞄准角度(angles);
		if (Menu::Window.AimBotTab.自动开枪.取状态())
		{
			自动开枪();
		}


	return ReturnValue;
}

bool 类型_自动瞄准::自动开枪()
{
	DWORD address = Offsets::Modules::Client + 0x313520C;
	//*(int*)address = 5;
	mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
	mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);

	return true;
}


