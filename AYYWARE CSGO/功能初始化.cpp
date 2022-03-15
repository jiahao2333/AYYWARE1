#include "全局变量.h"


HackWindow Menu::Window;




void HackWindow::Setup()
{

	注册功能分页(&AimBotTab);
	注册功能分页(&RadarTab);

}




void Menu::SetupMenu()
{
	Window.Setup();
	GUI.注册窗口(&Window);
}

void Menu::功能初始化()
{
	if (!Window.AimBotTab.初始化.取状态())
	{
		Window.AimBotTab.初始化.设置状态(true);
		Window.AimBotTab.瞄准范围.设置值(5);
		Window.AimBotTab.可视检查.设置状态(true);
		Window.RadarTab.显示物品.设置状态(true);
	//	Window.RadarTab.十字准心.设置状态(true);
	//	Window.RadarTab.弹道准心.设置状态(true);
		Window.RadarTab.显示观察者.设置状态(true);




	}

	GUI.按键挂接();
	GUI.Draw();

	
}


