/*
Syn's AyyWare Framework 2015
*/
//#define AYY_DEBUG

// General shit
#include "DLLMain.h"
#include "Utilities.h"
#include "INJ/ReflectiveLoader.h"
#include "Hooks.h"
#include "声明_绘制引擎.h"
#include "Hacks.h"
#include <string>
#include <cstddef>
#include <time.h>
#include <vector>
#include <stdlib.h>
using namespace std;
// Used as part of the reflective DLL injection
extern HINSTANCE hAppInstance;

// Our DLL Instance
HINSTANCE HThisModule;
bool DoUnload;


struct GlowObjectDefinition {
	IClientEntity* entity;
	Vector glowColor;
	float   alpha;
	char pad[4];
	float   m_flSomeFloat;
	float   bloomAmount;
	float   m_flAnotherFloat;
	bool    renderWhenOccluded;
	bool    renderWhenUnoccluded;
	bool    fullBloomRender;
	char pad1;
	int fullBloomStencilTestValue;
	int glowStyle;
	int splitScreenSlot;
	int nextFreeSlot;

	constexpr bool isUnused() const noexcept { return nextFreeSlot != ENTRY_IN_USE; }

	static constexpr int END_OF_FREE_LIST = -1;
	static constexpr int ENTRY_IN_USE = -2;
};
template <typename T>
class UtlVector {
public:
	constexpr T& operator[](int i) noexcept { return memory[i]; };

	T* memory;
	int allocationCount;
	int growSize;
	int size;
	T* elements;
};


struct GlowObjectManager {
	UtlVector<GlowObjectDefinition> glowObjectDefinitions;
	int firstFreeSlot;
};


int 启动辅助()
{
	Offsets::Initialise(); // Set our VMT offsets and do any pattern scans
	Interfaces::Initialise(); // Get pointers to the valve classes
	NetVar.RetrieveClasses(); // Setup our NetVar manager (thanks shad0w bby)
	NetvarManager::Instance()->CreateDatabase();
	Render::初始化();
	Hacks::安装外挂();
	Menu::SetupMenu();
	Hooks::Initialise();

	DWORD address = *(DWORD*)(Utilities::内存操作::查找内存_文本型W("client.dll", "8B 0D ? ? ? ? 8B D6 8B C1 83 CA 02") + 2);
	auto glowObjectManager = (GlowObjectManager*) * (DWORD*)(Utilities::内存操作::查找内存_文本型W("client.dll", "0F 11 05 ? ? ? ? 83 C8 01") + 3);

	srand(time(0));
	// While our cheat is running
	while (DoUnload == false)
	{
		if (!hackManager.pLocal())
		{
			Sleep(500);
			continue;
		}

		if (Menu::Window.RadarTab.连跳.取状态())
		{
			IClientEntity* pLocalEntity = (IClientEntity*)Interfaces::EntList->GetClientEntity(Interfaces::Engine->取本人基址());

			if (GetAsyncKeyState(VK_SPACE) & 0x8000 && pLocalEntity->GetFlags() & FL_ONGROUND)
			{
				*(int*)address = 6;
				Sleep(1);
			}
		}

		if (Menu::Window.RadarTab.发光.取状态())
		{
			for (int i = 0; i < glowObjectManager->glowObjectDefinitions.size; i++) {
				GlowObjectDefinition& glowobject = glowObjectManager->glowObjectDefinitions[i];

				auto entity = glowobject.entity;

				if (glowobject.isUnused() || !entity || !entity->是否可用())
					continue;

				if (entity->GetTeamNum() != hackManager.pLocal()->GetTeamNum())
				{
					glowobject.renderWhenOccluded = true;
					glowobject.alpha = 255;
					//glowobject.glowStyle = 0;
					//glowobject.bloomAmount = 2;
					glowobject.glowColor = { 255,  0, 0 };
				}
			}
		}

		if (Menu::Window.RadarTab.嘴臭.取状态())
		{
			static time_t last_time = 0;
			if ((time(0) - last_time) > 1)
			{
				static std::vector<std::string> chat = { u8"N M $ L",u8"艹 你 马 的 香 蕉 船",u8"快休息吧外星人妖 大脸长的好像方锹 披个斗篷 拎个包.",u8"300多斤你还说你最擅长的是跳高 还说自己学过散打练过摔跤 ",u8"那你晚上和nm单挑 尿尿往nm脸上交 还和nm说呢你这叫无招盛有招",u8"后边背个书包.手上拿个暖瓶，瞎了20多年，",u8"你老希望自己能从见光明.还装鸡把可爱说自己是宠物小精灵",u8"我是非常地了解你自卑的心情",u8"nm的目标是把卖B进行到底 那你草完nm还说你是在亲情和欲望之间迷失了自己？"
				u8"我就把那跑跑卡叮车塞进nm的小p眼子",u8"朋友你的艾滋病毒以每秒180.555公里的速度正在吞噬你的精子细胞",u8"无情的病魔一下一下杀死你和nm干炮的波涛 一个崭新的x无能患者即将诞生 那就是你 大傻狍",u8"听说你拉屎不开定 见到小姑娘你就好起性",u8"牛子还总绑绑硬 根据我多年观察的兽医临床经验你好象得了性绝症 叫艾滋病 你看你拉屎你都拉不净",u8"没事半夜拿个矿泉水去尿尿 还跟我说这是强力魔法药",u8"你和nm干炮的姿势一点都不着调 看见nm的大扎你就哈哈大笑" };
				Interfaces::Engine->ClientCmd_Unrestricted(("say \"" + chat[rand() % chat.size()] + "\"").c_str());
				last_time = time(0);
			}
		}
	}

	Hooks::UndoHooks();
	FreeLibraryAndExitThread(HThisModule, 0);

	return 0;
}






BOOL WINAPI DllMain(_In_ HINSTANCE hinstDLL,_In_ DWORD     fdwReason,_In_ LPVOID    lpvReserved)
{
	HANDLE vm;
	

	switch (fdwReason)
	{
	case DLL_QUERY_HMODULE:
		if (lpvReserved != NULL)
			*(HMODULE *)lpvReserved = hAppInstance;
		break;
	case DLL_PROCESS_ATTACH:
		HThisModule = hinstDLL;
		CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)启动辅助, NULL, NULL, NULL);
		
		break;
	case DLL_PROCESS_DETACH:
		break;
	}

	return TRUE;
}