#include "ȫ�ֱ���.h"


HackWindow Menu::Window;




void HackWindow::Setup()
{

	ע�Ṧ�ܷ�ҳ(&AimBotTab);
	ע�Ṧ�ܷ�ҳ(&RadarTab);

}




void Menu::SetupMenu()
{
	Window.Setup();
	GUI.ע�ᴰ��(&Window);
}

void Menu::���ܳ�ʼ��()
{
	if (!Window.AimBotTab.��ʼ��.ȡ״̬())
	{
		Window.AimBotTab.��ʼ��.����״̬(true);
		Window.AimBotTab.��׼��Χ.����ֵ(5);
		Window.AimBotTab.���Ӽ��.����״̬(true);
		Window.RadarTab.��ʾ��Ʒ.����״̬(true);
	//	Window.RadarTab.ʮ��׼��.����״̬(true);
	//	Window.RadarTab.����׼��.����״̬(true);
		Window.RadarTab.��ʾ�۲���.����״̬(true);




	}

	GUI.�����ҽ�();
	GUI.Draw();

	
}


