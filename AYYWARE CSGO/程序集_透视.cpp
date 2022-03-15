/*
Syn's AyyWare Framework 2015
*/

#include "变量声明_Tab.h"
#include "Interfaces.h"
#include "声明_绘制引擎.h"
#include <string>
using std::string;
using std::wstring;
string UnicodeToAscii(const wstring& wstr) {
	// 预算-缓冲区中多字节的长度    
	int ansiiLen = WideCharToMultiByte(CP_ACP, 0, wstr.c_str(), -1, nullptr, 0, nullptr, nullptr);
	// 给指向缓冲区的指针变量分配内存    
	char *pAssii = (char*)malloc(sizeof(char)*ansiiLen);
	// 开始向缓冲区转换字节    
	WideCharToMultiByte(CP_ACP, 0, wstr.c_str(), -1, pAssii, ansiiLen, nullptr, nullptr);
	string ret_str = pAssii;
	free(pAssii);
	return ret_str;
}
wstring Utf8ToUnicode(const string& str) {
	// 预算-缓冲区中宽字节的长度    
	int unicodeLen = MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, nullptr, 0);
	// 给指向缓冲区的指针变量分配内存    
	wchar_t *pUnicode = (wchar_t*)malloc(sizeof(wchar_t)*unicodeLen);
	// 开始向缓冲区转换字节    
	MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, pUnicode, unicodeLen);
	wstring ret_str = pUnicode;
	free(pUnicode);
	return ret_str;
}
string Utf8ToAscii(const string& str) {
	return UnicodeToAscii(Utf8ToUnicode(str));
}


void 类型_透视::Init()
{
	BombCarrier = nullptr;
}
// Yeah dude we're defo gunna do some sick moves for the esp yeah
void 类型_透视::Move(CUserCmd *pCmd,bool &bSendPacket) 
{

}

// Main ESP Drawing loop
void 类型_透视::Draw()
{
	IClientEntity *pLocal = hackManager.pLocal();
	if (Menu::Window.RadarTab.显示观察者.取状态())
	{
		显示观察者();
	}
	// Loop through all active entitys
	for (int i = 0; i < Interfaces::EntList->GetHighestEntityIndex(); i++)
	{
		// Get the entity
		IClientEntity *pEntity = Interfaces::EntList->GetClientEntity(i);
		player_info_t pinfo;

		// The entity isn't some laggy peice of shit or something
		if (pEntity &&  pEntity != pLocal && !pEntity->IsDormant())
		{
			// Is it a player?!
			if (Interfaces::Engine->取玩家信息(i, &pinfo) && pEntity->是否可用())
			{
				绘制玩家(pEntity, pinfo);
			}

			// ~ Other ESP's here (items and shit) ~ //
			ClientClass* cClass = (ClientClass*)pEntity->GetClientClass();

			// Dropped weapons
			if (Menu::Window.RadarTab.显示武器.取状态() && cClass->m_ClassID != (int)对象ID::CBaseWeaponWorldModel && ((strstr(cClass->m_pNetworkName, "Weapon") || cClass->m_ClassID == (int)对象ID::CDEagle || cClass->m_ClassID == (int)对象ID::CAK47)))
			{
				绘制掉落(pEntity, cClass);
			}

			// If entity is the bomb
			if (Menu::Window.RadarTab.显示物品.取状态())
			{
				//bool showclass = false;
				if (cClass->m_ClassID == (int)对象ID::CPlantedC4)
				{
				//	showclass = true;
					绘制放置的炸弹(pEntity, cClass);
				}
				if (cClass->m_ClassID == (int)对象ID::CC4)
				{
					绘制炸弹(pEntity, cClass);
				//	showclass = true;
				}
				if (cClass->m_ClassID == (int)对象ID::CChicken)
				{
					绘制野鸡(pEntity, cClass);
				//	showclass = true;
				}
				if (cClass->m_ClassID == (int)对象ID::CHostage || cClass->m_ClassID == (int)对象ID::CHostageCarriableProp)
				{
					绘制人质(pEntity, cClass);
					//	showclass = true;
				}



			}

		}
	}
	if (Menu::Window.RadarTab.无视闪光.取状态())
	{
		DWORD m_flFlashMaxAlpha = NetVar.GetNetVar(0xFE79FB98);
		*(float*)((DWORD)pLocal + m_flFlashMaxAlpha) = 0;
	}
}


void 类型_透视::显示观察者()
{
	IClientEntity *pLocal = hackManager.pLocal();

	RECT scrn = Render::取屏幕大小();
	int ayy = 0;

	// Loop through all active entitys
	for (int i = 0; i < Interfaces::EntList->GetHighestEntityIndex(); i++)
	{
		// Get the entity
		IClientEntity *pEntity = Interfaces::EntList->GetClientEntity(i);
		player_info_t pinfo;

		// The entity isn't some laggy peice of shit or something
		if (pEntity &&  pEntity != pLocal)
		{
			if (Interfaces::Engine->取玩家信息(i, &pinfo) && !pEntity->是否可用() && !pEntity->IsDormant())
			{
				HANDLE obs = pEntity->GetObserverTargetHandle();

				if (obs)
				{
					IClientEntity *pTarget = Interfaces::EntList->GetClientEntityFromHandle(obs);
					player_info_t pinfo2;
					if (pTarget)
					{
						if (Interfaces::Engine->取玩家信息(pTarget->GetIndex(), &pinfo2))
						{
							string watcher = Utf8ToAscii(pinfo.name);
							string player = Utf8ToAscii(pinfo2.name);


							if (pTarget->GetIndex() == pLocal->GetIndex())
							{
									RECT TextSizeD = Render::取文本长度(Render::字体::Default, "警告:有人正在观看你 请注意演技！");
									Render::绘制文本(scrn.right/2 - TextSizeD.right/2 - 4, scrn.bottom / 2 + 30, Color(240, 70, 80, 255), Render::字体::Default, "警告:有人正在观看你 请注意演技！");
							}


							char buf[255]; sprintf_s(buf, "%s 在观看 %s",watcher.c_str(), player.c_str());
							RECT TextSize = Render::取文本长度(Render::字体::ESP, buf);
							Render::绘制直线(scrn.right - 260, (scrn.bottom / 2) + (16 * ayy), 260, 16, Color(0, 0, 0, 140));
							Render::绘制文本(scrn.right - TextSize.right - 4, (scrn.bottom / 2) + (16 * ayy), pTarget->GetIndex() == pLocal->GetIndex() ? Color(240, 70, 80, 255) : Color(255, 255, 255, 255), Render::字体::ESP, buf);
							ayy++;
						}
					}
				}
			}
		}
	}

	Render::绘制方框(scrn.right - 261, (scrn.bottom / 2) - 1, 262, (16 * ayy) + 2, Color(23, 23, 23, 255));
	Render::绘制方框(scrn.right - 260, (scrn.bottom / 2), 260, (16 * ayy), Color(90, 90, 90, 255));
}

//  Yeah m8
void 类型_透视::绘制玩家(IClientEntity* pEntity, player_info_t pinfo)
{
	ESPBox3D Box3D;
	ESPBox Box;
	Color Color;
	string 玩家名字 = Utf8ToAscii(pinfo.name);




	// Show own team false? well gtfo teammate lol
	if (!Menu::Window.RadarTab.队友透视.取状态() && pEntity->GetTeamNum() == hackManager.pLocal()->GetTeamNum())
		return;

	if (取3D方框(pEntity, Box3D) && 取方框(pEntity, Box))
	{
		Color = 取阵营颜色(pEntity);
		if (Menu::Window.RadarTab.方框透视.取状态())
		{
			绘制方框(Box, Color);//绘制方框



// 			Render::绘制线条(Box3D.x3, Box3D.y3, Box3D.x6, Box3D.y6, Color);
// 			Render::绘制线条(Box3D.x6, Box3D.y6, Box3D.x5, Box3D.y5, Color);
// 			Render::绘制线条(Box3D.x5, Box3D.y5, Box3D.x1, Box3D.y1, Color);
// 			Render::绘制线条(Box3D.x1, Box3D.y1, Box3D.x3, Box3D.y3, Color);
// 			Render::绘制线条(Box3D.x1, Box3D.y1, Box3D.x8, Box3D.y8, Color);
// 			Render::绘制线条(Box3D.x3, Box3D.y3, Box3D.x7, Box3D.y7, Color);
// 			Render::绘制线条(Box3D.x6, Box3D.y6, Box3D.x2, Box3D.y2, Color);
// 			Render::绘制线条(Box3D.x5, Box3D.y5, Box3D.x4, Box3D.y4, Color);
// 			Render::绘制线条(Box3D.x2, Box3D.y2, Box3D.x4, Box3D.y4, Color);
// 			Render::绘制线条(Box3D.x4, Box3D.y4, Box3D.x8, Box3D.y8, Color);
// 			Render::绘制线条(Box3D.x8, Box3D.y8, Box3D.x7, Box3D.y7, Color);
// 			Render::绘制线条(Box3D.x7, Box3D.y7, Box3D.x2, Box3D.y2, Color);



			//Render::绘制直线1(Box3D.x4, Box3D.y4, Box3D.x1, Box3D.y4+2, Color);
			//Render::绘制直线(Box3D.x5, Box3D.y5, 2, 2, Color);
			//Render::绘制直线(Box3D.x6, Box3D.y6, 2, 2, Color);
			//Render::绘制直线(Box3D.x7, Box3D.y7, 2, 2, Color);
			//Render::绘制直线(Box3D.x8, Box3D.y8, 2, 2, Color);



			int ColorRD;
			if (pEntity->GetTeamNum() == hackManager.pLocal()->GetTeamNum())
			{
				ColorRD = 1;
			}
			else
			{
				ColorRD = 2;
			}


			if (Menu::Window.RadarTab.显示名字.取状态())
			{
				绘制名字(玩家名字.c_str(), Box, ColorRD);//绘制名字

			}


			if (Menu::Window.RadarTab.显示血条.取状态())
			{
				绘制血条(pEntity, Box);//绘制血量

			}
			if (Menu::Window.RadarTab.显示信息.取状态())
			{
				绘制信息(pEntity, Box);//绘制信息

			}



		}





		if (Menu::Window.RadarTab.显示骨骼.取状态())
		{
			绘制骨骼(pEntity);//绘制骨骼
		}
		if (Menu::Window.RadarTab.显示头部.取状态())
		{

			绘制头部(pEntity);//绘制头部
		}
		if (Menu::Window.RadarTab.雷达透视.取状态())
		{
			DWORD m_bSpotted = NetVar.GetNetVar(0x839EB159);
			*(char*)((DWORD)(pEntity)+m_bSpotted) = 1;
		}



	}
}


// Gets the 2D bounding box for the entity
// Returns false on failure nigga don't fail me
bool 类型_透视::取3D方框(IClientEntity* pEntity, 类型_透视::ESPBox3D &result)
{
	// Variables
	Vector  vOrigin, min, max,	flb, brt, blb, frt, frb, brb, blt, flt;
	float left, right , top, bottom;
	
	// Get the locations
	vOrigin = pEntity->GetOrigin();
	min = pEntity->collisionProperty()->GetMins() + vOrigin;
	max = pEntity->collisionProperty()->GetMaxs() + vOrigin;

	// Points of a 3d bounding box
	Vector points[] = { Vector(min.x, min.y, min.z),
		Vector(min.x, max.y, min.z),
		Vector(max.x, max.y, min.z),
		Vector(max.x, min.y, min.z),
		Vector(max.x, max.y, max.z),
		Vector(min.x, max.y, max.z),
		Vector(min.x, min.y, max.z),
		Vector(max.x, min.y, max.z) };

	// Get screen positions
	if (!Render::矩阵转换(points[3], flb) || !Render::矩阵转换(points[5], brt)
		|| !Render::矩阵转换(points[0], blb) || !Render::矩阵转换(points[4], frt)
		|| !Render::矩阵转换(points[2], frb) || !Render::矩阵转换(points[1], brb)
		|| !Render::矩阵转换(points[6], blt) || !Render::矩阵转换(points[7], flt))
		return false;
	
	// Put them in an array (maybe start them off in one later for speed?)
	Vector arr[] = { flb, brt, blb, frt, frb, brb, blt, flt };

	result.x1 = flb.x; //下
	result.y1 = flb.y; //下
	result.x2 = brt.x;
	result.y2 = brt.y; 
	result.x3 = blb.x;  //下
	result.y3 = blb.y; //下
	result.x4 = frt.x;
	result.y4 = frt.y;
	result.x5 = frb.x; //下 
	result.y5 = frb.y; //下
	result.x6 = brb.x; //下
	result.y6 = brb.y; //下
	result.x7 = blt.x;
	result.y7 = blt.y;
	result.x8 = flt.x;
	result.y8 = flt.y;
	return true;
}


bool 类型_透视::取方框(IClientEntity* pEntity, 类型_透视::ESPBox &result)
{
	// Variables
	Vector  vOrigin, min, max, sMin, sMax, sOrigin,
		flb, brt, blb, frt, frb, brb, blt, flt;
	float left, top, right, bottom;

	// Get the locations
	vOrigin = pEntity->GetOrigin();
	min = pEntity->collisionProperty()->GetMins() + vOrigin;
	max = pEntity->collisionProperty()->GetMaxs() + vOrigin;

	// Points of a 3d bounding box
	Vector points[] = { Vector(min.x, min.y, min.z),
		Vector(min.x, max.y, min.z),
		Vector(max.x, max.y, min.z),
		Vector(max.x, min.y, min.z),
		Vector(max.x, max.y, max.z),
		Vector(min.x, max.y, max.z),
		Vector(min.x, min.y, max.z),
		Vector(max.x, min.y, max.z) };

	// Get screen positions
	if (!Render::矩阵转换(points[3], flb) || !Render::矩阵转换(points[5], brt)
		|| !Render::矩阵转换(points[0], blb) || !Render::矩阵转换(points[4], frt)
		|| !Render::矩阵转换(points[2], frb) || !Render::矩阵转换(points[1], brb)
		|| !Render::矩阵转换(points[6], blt) || !Render::矩阵转换(points[7], flt))
		return false;

	// Put them in an array (maybe start them off in one later for speed?)
	Vector arr[] = { flb, brt, blb, frt, frb, brb, blt, flt };

	// Init this shit
	left = flb.x;
	top = flb.y;
	right = flb.x;
	bottom = flb.y;

	// Find the bounding corners for our box
	for (int i = 1; i < 8; i++)
	{
		if (left > arr[i].x)
			left = arr[i].x;
		if (bottom < arr[i].y)
			bottom = arr[i].y;
		if (right < arr[i].x)
			right = arr[i].x;
		if (top > arr[i].y)
			top = arr[i].y;
	}

	// Width / height
	result.x = left;
	result.y = top;
	result.w = right - left;
	result.h = bottom - top;

	return true;
}




// Get an entities color depending on team and vis ect
Color 类型_透视::取阵营颜色(IClientEntity* pEntity)
{
	int TeamNum = pEntity->GetTeamNum();
	bool IsVis = GameUtils::可视检查(hackManager.pLocal(), pEntity, (int)人物部位::Head);
	
	Color color;

	if (pEntity->GetTeamNum() == hackManager.pLocal()->GetTeamNum())
	{
		if (IsVis)
			color = Color(74, 134, 232, 255);
		else
			color = Color(74, 134, 232, 170);
	}
	else
	{
		if (IsVis)
			color = Color(255, 0, 0, 255);
		else
			color = Color(255, 0, 0, 170);
	}


	return color;
}



void 类型_透视::绘制方框(类型_透视::ESPBox size, Color color)
{
	Render::绘制直线(size.x, size.y + size.h - 2, size.w, 2, color);
	Render::绘制直线(size.x, size.y, 2, size.h, color);
	Render::绘制直线(size.x, size.y, size.w, 2, color);
	Render::绘制直线(size.x + size.w - 2, size.y, 2, size.h, color);

}




void 类型_透视::绘制名字(const char* name, 类型_透视::ESPBox size ,int 阵营颜色)
{
	Color NameColor;
	if (阵营颜色 == 0)
	{
		NameColor = Color(255, 255, 255, 255);
	}
	if (阵营颜色==1)
	{
		NameColor = Color(74, 134, 232, 255);
	}
	if (阵营颜色 == 2)
	{
		NameColor = Color(255, 0, 0, 255);
	}

	RECT nameSize = Render::取文本长度(Render::字体::ESP, name);
	Render::绘制文本(size.x + (size.w / 2) - (nameSize.right / 2), size.y - 16, NameColor, Render::字体::ESP, name);
}


// Draw a health bar. For Tf2 when a bar is bigger than max health a second bar is displayed
void 类型_透视::绘制血条(IClientEntity* pEntity, 类型_透视::ESPBox size)
{
	ESPBox HealthBar = size;
	HealthBar.y += (HealthBar.h + 6);
	HealthBar.h = 4;

	float 当前血量 = pEntity->GetHealth();
	float 最大血量 = 100.f;
	float 血量百分比 = 当前血量 / 最大血量 * 100;
	Color 血条颜色;
	if (血量百分比 >= 70.f)
	{
		血条颜色 = Color(0, 255, 0, 230);//绿色
	}
	if (血量百分比 <= 70.f && 血量百分比 >= 40.f)
	{
		血条颜色 = Color(85, 168, 11, 230);//黄色
	}
	if (血量百分比 <= 40.f)
	{
		血条颜色 = Color(255, 0, 0, 230);//红色
	}

	size.x = size.x + size.w / 2 - 35;
	size.y = size.y + size.h + 3;
	Render::绘制方框(size.x, size.y, 70, 6, Color(0, 0, 0, 240));
	Render::绘制直线(size.x + 1, size.y + 1, 68 * 当前血量 / 最大血量, 4, 血条颜色);
}


std::string 取物品显示名(std::string name)
{
	std::string Name = name;
	// Tidy up the weapon Name
	if (Name[0] == 'C')
		Name.erase(Name.begin());

	// Remove the word Weapon
	auto startOfWeap = Name.find("Weapon");
	if (startOfWeap != std::string::npos)
		Name.erase(Name.begin() + startOfWeap, Name.begin() + startOfWeap + 6);

	return Name;
}

void 类型_透视::绘制信息(IClientEntity* pEntity, 类型_透视::ESPBox size)
{
	std::vector<std::string> Info;

	IClientEntity* pWeapon = Interfaces::EntList->GetClientEntityFromHandle((HANDLE)pEntity->GetActiveWeaponHandle());
	if (pWeapon)
	{
		ClientClass* cClass = (ClientClass*)pWeapon->GetClientClass();
		if (cClass)
		{

			Info.push_back(取物品显示名(cClass->m_pNetworkName));
		}
	}


	if (pEntity == BombCarrier)
	{
		Info.push_back("炸弹(C4)");
	}

	static RECT Size = Render::取文本长度(Render::字体::Default, "炸弹(C4)");
	int i = 0;
	for (auto Text : Info)
	{
		Render::绘制文本(size.x + size.w + 3, size.y + (i*(Size.bottom + 2)), Color(255, 255, 255, 255), Render::字体::ESP, Text.c_str());
		i++;
	}
}


void 类型_透视::绘制头部(IClientEntity* pEntity)
{
	Vector cross = pEntity->取头部顶点(), screen;
	static int Scale = 2;
	if (Render::矩阵转换(cross, screen))
	{
		Render::绘制直线(screen.x - Scale, screen.y - (Scale * 2), (Scale * 2), (Scale * 4), Color(20, 20, 20, 160));
		Render::绘制直线(screen.x - (Scale * 2), screen.y - Scale, (Scale * 4), (Scale * 2), Color(20, 20, 20, 160));
		Render::绘制直线(screen.x - Scale - 1, screen.y - (Scale * 2) - 1, (Scale * 2) - 2, (Scale * 4) - 2, Color(250, 250, 250, 160));
		Render::绘制直线(screen.x - (Scale * 2) - 1, screen.y - Scale - 1, (Scale * 4) - 2, (Scale * 2) - 2, Color(250, 250, 250, 160));
	}
}


void 类型_透视::绘制掉落(IClientEntity* pEntity, ClientClass* cClass)
{
	Vector Box;
	CBaseCombatWeapon* Weapon = (CBaseCombatWeapon*)pEntity;
	IClientEntity* plr = Interfaces::EntList->GetClientEntityFromHandle((HANDLE)Weapon->GetOwnerHandle());
	if (!plr && Render::矩阵转换(Weapon->GetOrigin(), Box))
	{
		//方框
			Render::绘制方框(Box.x - 2, Box.y - 2, 4, 4, Color(255, 255, 255, 255));
			Render::绘制方框(Box.x - 3, Box.y - 3, 6, 6, Color(10, 10, 10, 150));
		//名字
			std::string ItemName = 取物品显示名(cClass->m_pNetworkName);
			RECT TextSize = Render::取文本长度(Render::字体::ESP, ItemName.c_str());
			Render::绘制文本(Box.x - (TextSize.right / 2), Box.y - 16, Color(255, 255, 255, 255), Render::字体::ESP, ItemName.c_str());
	}
}

void 类型_透视::绘制野鸡(IClientEntity* pEntity, ClientClass* cClass)
{
	ESPBox Box;
	if (取方框(pEntity, Box))
	{
		string 实体名字 = "鸡(Chicken)";
		绘制名字(实体名字.c_str(), Box,0);
	}
}
void 类型_透视::绘制人质(IClientEntity* pEntity, ClientClass* cClass)
{
	ESPBox Box;
	if (取方框(pEntity, Box))
	{
		Box.y = Box.y + Box.h * 0.2;
		string 实体名字 = "人质(Hostage)";
		绘制名字(实体名字.c_str(), Box, 0);
	}
}


void 类型_透视::绘制未知(IClientEntity* pEntity, ClientClass* cClass)
{
	ESPBox Box;
	if (取方框(pEntity, Box))
	{
		int classid = cClass->m_ClassID;
		char buf[10];
		sprintf(buf, "%d", classid);
		string b = buf;
		绘制名字(b.c_str(), Box, 0);
	}
}


void 类型_透视::绘制放置的炸弹(IClientEntity* pEntity, ClientClass* cClass) 
{
	Vector vOrig; Vector vScreen;
	vOrig = pEntity->GetOrigin();
	CCSBomb* Bomb = (CCSBomb*)pEntity;

	if (Render::矩阵转换(vOrig, vScreen))
	{
		float flBlow = Bomb->GetC4BlowTime();
		float TimeRemaining = flBlow - (Interfaces::Globals->interval_per_tick * hackManager.pLocal()->GetTickBase());
		char buffer[64];
		sprintf_s(buffer, "* 炸弹(C4): %.1f", TimeRemaining);
		Render::绘制文本(vScreen.x, vScreen.y, Color(250, 42, 42, 255), Render::字体::ESP, buffer);
	}
}

void 类型_透视::绘制炸弹(IClientEntity* pEntity, ClientClass* cClass)
{
	CBaseCombatWeapon *BombWeapon = (CBaseCombatWeapon *)pEntity;
	Vector vOrig; Vector vScreen;
	vOrig = pEntity->GetOrigin();
	bool adopted = true;
	HANDLE parent = BombWeapon->GetOwnerHandle();
	if (parent || (vOrig.x == 0 && vOrig.y == 0 && vOrig.z == 0))
	{
		IClientEntity* pParentEnt = (Interfaces::EntList->GetClientEntityFromHandle(parent));
		if (pParentEnt && pParentEnt->是否可用())
		{
			BombCarrier = pParentEnt;
			adopted = false;
		}
	}

	if (adopted)
	{
		if (Render::矩阵转换(vOrig, vScreen))
		{
			Render::绘制文本(vScreen.x, vScreen.y, Color(112, 230, 20, 255), Render::字体::ESP, "炸弹(C4)");
		}
	}
}



void 类型_透视::绘制骨骼(IClientEntity* pEntity)
{
	studiohdr_t* pStudioHdr = Interfaces::ModelInfo->GetStudiomodel(pEntity->GetModel());

	if (!pStudioHdr)
		return;

	Vector vParent, vChild, sParent, sChild;

	for (int j = 0; j < pStudioHdr->numbones; j++)
	{
		mstudiobone_t* pBone = pStudioHdr->GetBone(j);

		if (pBone && (pBone->flags & BONE_USED_BY_HITBOX) && (pBone->parent != -1))
		{
			vChild = pEntity->取骨骼顶点(j);
			vParent = pEntity->取骨骼顶点(pBone->parent);

			if (Render::矩阵转换(vParent, sParent) && Render::矩阵转换(vChild, sChild))
			{
				Render::绘制线条(sParent[0], sParent[1], sChild[0], sChild[1], Color(255,255,255,255));
			}
		}
	}
}


