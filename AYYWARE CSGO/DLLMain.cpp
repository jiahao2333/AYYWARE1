/*
Syn's AyyWare Framework 2015
*/
//#define AYY_DEBUG

// General shit
#include "DLLMain.h"
#include "Utilities.h"
#include "INJ/ReflectiveLoader.h"
#include "Hooks.h"
#include "����_��������.h"
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


int ��������()
{
	Offsets::Initialise(); // Set our VMT offsets and do any pattern scans
	Interfaces::Initialise(); // Get pointers to the valve classes
	NetVar.RetrieveClasses(); // Setup our NetVar manager (thanks shad0w bby)
	NetvarManager::Instance()->CreateDatabase();
	Render::��ʼ��();
	Hacks::��װ���();
	Menu::SetupMenu();
	Hooks::Initialise();

	DWORD address = *(DWORD*)(Utilities::�ڴ����::�����ڴ�_�ı���W("client.dll", "8B 0D ? ? ? ? 8B D6 8B C1 83 CA 02") + 2);
	auto glowObjectManager = (GlowObjectManager*) * (DWORD*)(Utilities::�ڴ����::�����ڴ�_�ı���W("client.dll", "0F 11 05 ? ? ? ? 83 C8 01") + 3);

	srand(time(0));
	// While our cheat is running
	while (DoUnload == false)
	{
		if (!hackManager.pLocal())
		{
			Sleep(500);
			continue;
		}

		if (Menu::Window.RadarTab.����.ȡ״̬())
		{
			IClientEntity* pLocalEntity = (IClientEntity*)Interfaces::EntList->GetClientEntity(Interfaces::Engine->ȡ���˻�ַ());

			if (GetAsyncKeyState(VK_SPACE) & 0x8000 && pLocalEntity->GetFlags() & FL_ONGROUND)
			{
				*(int*)address = 6;
				Sleep(1);
			}
		}

		if (Menu::Window.RadarTab.����.ȡ״̬())
		{
			for (int i = 0; i < glowObjectManager->glowObjectDefinitions.size; i++) {
				GlowObjectDefinition& glowobject = glowObjectManager->glowObjectDefinitions[i];

				auto entity = glowobject.entity;

				if (glowobject.isUnused() || !entity || !entity->�Ƿ����())
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

		if (Menu::Window.RadarTab.���.ȡ״̬())
		{
			static time_t last_time = 0;
			if ((time(0) - last_time) > 1)
			{
				static std::vector<std::string> chat = { u8"N M $ L",u8"ܳ �� �� �� �� �� ��",u8"����Ϣ���������� �������ĺ����� �������� �����.",u8"300����㻹˵�����ó��������� ��˵�Լ�ѧ��ɢ������ˤ�� ",u8"�������Ϻ�nm���� ������nm���Ͻ� ����nm˵�����������ʢ����",u8"��߱������.�����ø�ůƿ��Ϲ��20���꣬",u8"����ϣ���Լ��ܴӼ�����.��װ���ѿɰ�˵�Լ��ǳ���С����",u8"���Ƿǳ����˽����Ա�������",u8"nm��Ŀ���ǰ���B���е��� �������nm��˵���������������֮����ʧ���Լ���"
				u8"�ҾͰ������ܿ���������nm��Сp����",u8"������İ��̲�����ÿ��180.555������ٶ�����������ľ���ϸ��",u8"����Ĳ�ħһ��һ��ɱ�����nm���ڵĲ��� һ��ո�µ�x���ܻ��߼������� �Ǿ����� ��ɵ��",u8"��˵����ʺ������ ����С������ͺ�����",u8"ţ�ӻ��ܰ��Ӳ �����Ҷ���۲����ҽ�ٴ��������������Ծ�֢ �а��̲� �㿴����ʺ�㶼������",u8"û�°�ҹ�ø���Ȫˮȥ���� ������˵����ǿ��ħ��ҩ",u8"���nm���ڵ�����һ�㶼���ŵ� ����nm�Ĵ�����͹�����Ц" };
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
		CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)��������, NULL, NULL, NULL);
		
		break;
	case DLL_PROCESS_DETACH:
		break;
	}

	return TRUE;
}