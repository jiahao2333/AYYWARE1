/*
Syn's AyyWare Framework 2015
*/

#include "变量声明_挂接封装.h"
#include "全局变量.h" //Falsch?
#include <algorithm>
#include "tinyxml2.h"
#include "自定义数据类型.h"
#include "Hacks.h" //falsch?
#include "绘制封装.h"
bool 显示菜单 = false;
int 当前菜单 = -1;
int 二级菜单 = -1;
CGUI GUI;

bool 鼠标是否在范围内(int x, int y, int w, int h)
{
	POINT mp; GetCursorPos(&mp);
	ScreenToClient(GetForegroundWindow(), &mp); 

	if (mp.x >= x && mp.x <= x + w && mp.y >= y  && mp.y <= y + h)
	{
		return true;
	}
	else;
	return false;
}

CGUI::CGUI()
{

}


void CGUI::Draw()//D3D初始执行子程序
{
	for (auto window : Windows)
	{
		if (显示菜单 == true)
		{
			绘制挂接(window);
		}
	}
	
	if 	(显示菜单 == true)//鼠标指针绘制
	{
		// 取鼠标坐标
		POINT mp; GetCursorPos(&mp);
		ScreenToClient(GetForegroundWindow(), &mp);
		Mouse.x = mp.x; Mouse.y = mp.y;
		RECT Screen = Render::取屏幕大小();//取屏幕宽高度
		Render::绘制直线(Mouse.x + 1, Mouse.y, 1, 17, Color(178, 34, 34, 255));

		for (int i = 0; i < 11; i++)
			Render::绘制直线(Mouse.x + 2 + i, Mouse.y + 1 + i, 1, 1, Color(178, 34, 34, 255));
		Render::绘制直线(Mouse.x + 8, Mouse.y + 12, 5, 1, Color(178, 34, 34, 255));
		Render::绘制直线(Mouse.x + 8, Mouse.y + 13, 1, 1, Color(178, 34, 34, 255));
		Render::绘制直线(Mouse.x + 9, Mouse.y + 14, 1, 2, Color(178, 34, 34, 255));
		Render::绘制直线(Mouse.x + 10, Mouse.y + 16, 1, 2, Color(178, 34, 34, 255));
		Render::绘制直线(Mouse.x + 8, Mouse.y + 18, 2, 1, Color(178, 34, 34, 255));
		Render::绘制直线(Mouse.x + 7, Mouse.y + 16, 1, 2, Color(178, 34, 34, 255));
		Render::绘制直线(Mouse.x + 6, Mouse.y + 14, 1, 2, Color(178, 34, 34, 255));
		Render::绘制直线(Mouse.x + 5, Mouse.y + 13, 1, 1, Color(178, 34, 34, 255));
		Render::绘制直线(Mouse.x + 4, Mouse.y + 14, 1, 1, Color(178, 34, 34, 255));
		Render::绘制直线(Mouse.x + 3, Mouse.y + 15, 1, 1, Color(178, 34, 34, 255));
		Render::绘制直线(Mouse.x + 2, Mouse.y + 16, 1, 1, Color(178, 34, 34, 255));
		for (int i = 0; i < 4; i++)
			Render::绘制直线(Mouse.x + 2 + i, Mouse.y + 2 + i, 1, 14 - (i * 2), Color(37 - (i * 4), 137 - (i * 4), 255 - (i * 4), 255));
		Render::绘制直线(Mouse.x + 6, Mouse.y + 6, 1, 8, UI_COL_MAIN);
		Render::绘制直线(Mouse.x + 7, Mouse.y + 7, 1, 9, UI_COL_MAIN);
		for (int i = 0; i < 4; i++)
			Render::绘制直线(Mouse.x + 8 + i, Mouse.y + 8 + i, 1, 4 - i, Color(37 - (i * 4), 137 - (i * 4), 255 - (i * 4), 255));
		Render::绘制直线(Mouse.x + 8, Mouse.y + 14, 1, 4, UI_COL_MAIN);
		Render::绘制直线(Mouse.x + 9, Mouse.y + 16, 1, 2, UI_COL_MAIN);
	}



}

void CGUI::按键挂接()
{
	if (GetAsyncKeyState(VK_F9) == -32767)
	{
		显示菜单 = !显示菜单;
	}

	if (GetAsyncKeyState(1) == -32767)//鼠标左键是否按下
	{
		//**************************一级菜单*************************************
		if (鼠标是否在范围内(5, 5 + 0 * 31, 240, 31))
		{
			二级菜单 = -1;
			if (当前菜单 == 0)
			{
				当前菜单 = -1;
			}
			else; 当前菜单 = 0;
		}

		if (鼠标是否在范围内(5, 5 + 1 * 31, 240, 31))
		{
			二级菜单 = -1;
			if (当前菜单 == 1) { 当前菜单 = -1; }
			else { 当前菜单 = 1; }
		}

		if (鼠标是否在范围内(5, 5 + 2 * 31, 240, 31))
		{
			二级菜单 = -1;
			if (当前菜单 == 2) { 当前菜单 = -1; }
			else { 当前菜单 = 2; }
		}

		if (鼠标是否在范围内(5, 5 + 3 * 31, 240, 31))
		{
			二级菜单 = -1;
			if (当前菜单 == 3) { 当前菜单 = -1; }
			else { 当前菜单 = 3; }
		}
		//if (鼠标是否在范围内(5, 5 + 4 * 31, 240, 31))
		//{
		//	二级菜单 = -1;
		//	if (当前菜单 == 4) { 当前菜单 = -1; }
		//	else { 当前菜单 = 4; }
		//}

		//**************************二级菜单*************************************
		if (当前菜单 == 1)//自瞄设置
		{
			if (鼠标是否在范围内(248, 5 + 1 * 31, 240, 31))
			{
				if (二级菜单 == 1) { 二级菜单 = -1; }
				else { 二级菜单 = 1; }
			}
		}
		if (当前菜单 == 2)//透视设置
		{
			if (鼠标是否在范围内(248, 5 + 1 * 31, 240, 31))
			{
				if (二级菜单 == 2) { 二级菜单 = -1; }
				else { 二级菜单 = 2; }
			}
		}


		//******************************实际功能开关***************************
		if (当前菜单 == 1)//自瞄开关
		{
			if (鼠标是否在范围内(456, 5 + 0 * 31, 31, 31))
			{
				Menu::Window.AimBotTab.自动瞄准.切换状态();
			}

		}
		if (当前菜单 == 2)//方框透视
		{
			if (鼠标是否在范围内(456, 5 + 0 * 31, 31, 31))
			{
				Menu::Window.RadarTab.方框透视.切换状态();
			}
			if (鼠标是否在范围内(456, 5 + 1 * 31, 31, 31))
			{
				Menu::Window.RadarTab.人物透视.切换状态();
			}
		}
		if (当前菜单 == 3)//杂项
		{
			if (鼠标是否在范围内(456, 5 + 0 * 31, 31, 31))
			{
				Menu::Window.RadarTab.十字准心.切换状态();
			}
			if (鼠标是否在范围内(456, 5 + 1 * 31, 31, 31))
			{
				Menu::Window.RadarTab.弹道准心.切换状态();
			}
			if (鼠标是否在范围内(456, 5 + 2 * 31, 31, 31))
			{
				Menu::Window.RadarTab.NameSteal.切换状态();
			}
			if (鼠标是否在范围内(456, 5 + 3 * 31, 31, 31))
			{
				Menu::Window.RadarTab.无视闪光.切换状态();

			}
			if (鼠标是否在范围内(456, 5 + 4 * 31, 31, 31))
			{
				Menu::Window.RadarTab.显示段位.切换状态();
			}
			//if (鼠标是否在范围内(456, 5 + 5 * 31, 31, 31))
			//{
			//	Menu::Window.RadarTab.嘴臭.切换状态();
			//}
			if (鼠标是否在范围内(456, 5 + 5 * 31, 31, 31))
			{
				Menu::Window.RadarTab.显示观察者.切换状态();

			}
			if (鼠标是否在范围内(456, 5 + 6 * 31, 31, 31))
			{
				Menu::Window.RadarTab.无限举报.切换状态();

			}

		}




		if (二级菜单 == 1)
		{
			if (鼠标是否在范围内(699, 5 + 0 * 31, 31, 31))
			{
				int lpidex = Menu::Window.AimBotTab.瞄准部位.取值();
				lpidex = lpidex + 1;
				if (lpidex == 4) { lpidex = 0; }
				Menu::Window.AimBotTab.瞄准部位.设置值(lpidex);
			}
			if (鼠标是否在范围内(699, 5 + 1 * 31, 31, 31))
			{
				Menu::Window.AimBotTab.瞄准队友.切换状态();
			}
			if (鼠标是否在范围内(631, 5 + 2 * 31, 20, 30))//减少自瞄FOV
			{
				int fov = Menu::Window.AimBotTab.瞄准范围.取值();
				if (fov >= 0)
				{
					fov = fov - 1;
					Menu::Window.AimBotTab.瞄准范围.设置值(fov);
				}
			}
			if (鼠标是否在范围内(711, 5 + 2 * 31, 20, 30))//增加自瞄FOV
			{
				int fov = Menu::Window.AimBotTab.瞄准范围.取值();
				if (fov <= 360)
				{
					fov = fov + 1;
					Menu::Window.AimBotTab.瞄准范围.设置值(fov);
				}
			}
			if (鼠标是否在范围内(699, 5 + 3 * 31, 31, 31))
			{
				int aimkey = Menu::Window.AimBotTab.自瞄按键.取值();

				if (aimkey == VK_LBUTTON)
				{
					Menu::Window.AimBotTab.自瞄按键.设置值(VK_RBUTTON);//C键
				}
				if (aimkey == VK_RBUTTON)
				{
					Menu::Window.AimBotTab.自瞄按键.设置值(VK_MENU);//Alt
				}
				if (aimkey == VK_MENU)
				{
					Menu::Window.AimBotTab.自瞄按键.设置值(VK_CONTROL);//Ctrl
				}
				if (aimkey == VK_CONTROL)
				{
					Menu::Window.AimBotTab.自瞄按键.设置值(VK_LBUTTON);//鼠标左键
				}

			}
			
			//if (鼠标是否在范围内(699, 5 + 4 * 31, 31, 31))
			//{
			//	Menu::Window.AimBotTab.自动开枪.切换状态();
			//}

			if (鼠标是否在范围内(699, 5 + 4 * 31, 31, 31))
			{
				Menu::Window.AimBotTab.可视检查.切换状态();
			}
			//if (鼠标是否在范围内(699, 5 + 5 * 31, 31, 31))
			//{
			//	Menu::Window.AimBotTab.无后坐力.切换状态();
			//}
			if (鼠标是否在范围内(699, 5 + 5 * 31, 31, 31))
			{
				Menu::Window.AimBotTab.自动压枪.切换状态();
			}
			if (鼠标是否在范围内(699, 5 + 6 * 31, 31, 31))
			{
				Menu::Window.AimBotTab.自动扳机.切换状态();
			}
		}
		if (二级菜单 == 2)
		{
			if (鼠标是否在范围内(699, 5 + 0 * 31, 31, 31))
			{
				Menu::Window.RadarTab.发光.切换状态();
			}
			if (鼠标是否在范围内(699, 5 + 1 * 31, 31, 31))
			{
				Menu::Window.RadarTab.队友透视.切换状态();
			}
			if (鼠标是否在范围内(699, 5 + 2 * 31, 31, 31))
			{
				Menu::Window.RadarTab.显示物品.切换状态();
			}
			if (鼠标是否在范围内(699, 5 + 3 * 31, 31, 31))
			{
				Menu::Window.RadarTab.显示骨骼.切换状态();
			}

			if (鼠标是否在范围内(699, 5 + 4 * 31, 31, 31))
			{	
				Menu::Window.RadarTab.显示血条.切换状态();
			}

			if (鼠标是否在范围内(699, 5 + 5 * 31, 31, 31))
			{
				Menu::Window.RadarTab.显示名字.切换状态();
			}
			if (鼠标是否在范围内(699, 5 + 6 * 31, 31, 31))
			{
				Menu::Window.RadarTab.显示头部.切换状态();
			}
			if (鼠标是否在范围内(699, 5 + 7 * 31, 31, 31))
			{
				Menu::Window.RadarTab.显示武器.切换状态();
			}
			if (鼠标是否在范围内(699, 5 + 8 * 31, 31, 31))
			{
				Menu::Window.RadarTab.显示信息.切换状态();
			}
			if (鼠标是否在范围内(699, 5 + 9 * 31, 31, 31))
			{
				Menu::Window.RadarTab.显示各种物品.切换状态();
			}
			if (鼠标是否在范围内(699, 5 + 10 * 31, 31, 31))
			{
				Menu::Window.RadarTab.雷达透视.切换状态();
			}
			if (鼠标是否在范围内(699, 5 + 11 * 31, 31, 31))
			{
				Menu::Window.RadarTab.连跳.切换状态();
			}


		}




	}
}






// Returns 





bool CGUI::GetKeyPress(unsigned int key)
{
	if (keys[key] == true && oldKeys[key] == false)
		return true;
	else
		return false;
}

bool CGUI::获取按键状态(unsigned int key)
{
	if (key >= 0 && key <= 255)
		return keys[key];
	else
		return false;
}

bool CGUI::IsMouseInRegion(int x, int y, int x2, int y2)
{
	if (Mouse.x > x && Mouse.y > y && Mouse.x < x2 && Mouse.y < y2)
		return true;
	else
		return false;
}

bool CGUI::IsMouseInRegion(RECT region)
{
	return IsMouseInRegion(region.left, region.top, region.left + region.right, region.top + region.bottom);
}

POINT CGUI::GetMouse()
{
	return Mouse;
}

bool CGUI::绘制挂接(CWindow* window)//绘制菜单
{
	D3D_绘制菜单框(5, 5 + 0 * 31, "正版大地球演技版",0);
	D3D_绘制菜单框(5 ,5 + 1 * 31, "自动瞄准",1);
	D3D_绘制菜单框(5, 5 + 2 * 31, "透视功能",1);
	D3D_绘制菜单框(5, 5 + 3 * 31, "杂项功能",1);
	//D3D_绘制菜单框(5, 5 + 4 * 31, "颜色设置",1);
	D3D_绘制菜单框(5, 5 + 4 * 31, "稳定安全", 0);
	D3D_绘制菜单框(5, 5 + 5 * 31, "每天云更", 0);
    //D3D_绘制菜单框(5, 5 + 7 * 31, "NameSteal", Menu::Window.RadarTab.NameSteal.取绘制值());
	

	
	if (当前菜单 == 1)
	{
		D3D_绘制菜单框(248, 5 + 0 * 31, "自动瞄准", Menu::Window.AimBotTab.自动瞄准.取绘制值());
		D3D_绘制菜单框(248, 5 + 1 * 31, "瞄准设置", 1);
	}
	if (当前菜单 == 2)
	{
		D3D_绘制菜单框(248, 5 + 0 * 31, "方框透视", Menu::Window.RadarTab.方框透视.取绘制值());
		D3D_绘制菜单框(248, 5 + 1 * 31, "透视设置", 1);
	}
	if (当前菜单 == 3)
	{
		D3D_绘制菜单框(248, 5 + 0 * 31, "十字准星", Menu::Window.RadarTab.十字准心.取绘制值());
		D3D_绘制菜单框(248, 5 + 1 * 31, "弹道准星", Menu::Window.RadarTab.弹道准心.取绘制值());
		D3D_绘制菜单框(248, 5 + 2 * 31, "名字窃贼", Menu::Window.RadarTab.NameSteal.取绘制值());
		D3D_绘制菜单框(248, 5 + 3 * 31, "无视闪光", Menu::Window.RadarTab.无视闪光.取绘制值());
		D3D_绘制菜单框(248, 5 + 4 * 31, "显示段位", Menu::Window.RadarTab.显示段位.取绘制值());
		//D3D_绘制菜单框(248, 5 + 5 * 31, "嘴臭", Menu::Window.RadarTab.嘴臭.取绘制值());
		D3D_绘制菜单框(248, 5 + 5 * 31, "显示观察者（默认开启）", Menu::Window.RadarTab.显示观察者.取绘制值());
		D3D_绘制菜单框(248, 5 + 6 * 31, "举报对面五个", Menu::Window.RadarTab.无限举报.取绘制值());
	}
	//if (当前菜单 == 4)
	//{
	//	D3D_绘制菜单框(248, 5 + 0 * 31, "敌人颜色", 0);
	//	D3D_绘制菜单框(248, 5 + 1 * 31, "队友颜色", 0);
	//	D3D_绘制菜单框(248, 5 + 2 * 31, "准心颜色", 0);
	//}

	//******************************二级菜单绘制**************************************
	if (二级菜单 == 1)
	{
		D3D_绘制菜单框(491, 5 + 0 * 31, "瞄准部位", Menu::Window.AimBotTab.瞄准部位.取绘制值() + 8);
		D3D_绘制菜单框(491, 5 + 1 * 31, "瞄准队友 (头号特训模式)", Menu::Window.AimBotTab.瞄准队友.取绘制值());
		D3D_绘制菜单框(491, 5 + 2 * 31, "瞄准角度", 0);
		D3D_绘制数据条(491, 5 + 2 * 31, Menu::Window.AimBotTab.瞄准范围.取绘制值(), 360);
		D3D_绘制菜单框(491, 5 + 3 * 31, "瞄准按键", Menu::Window.AimBotTab.自瞄按键.取绘制值());
//		D3D_绘制菜单框(491, 5 + 4 * 31, "自动开枪", Menu::Window.AimBotTab.自动开枪.取绘制值());
		D3D_绘制菜单框(491, 5 + 4 * 31, "可视检查", Menu::Window.AimBotTab.可视检查.取绘制值());
//		D3D_绘制菜单框(491, 5 + 5 * 31, "无后坐力", Menu::Window.AimBotTab.无后坐力.取绘制值());
		D3D_绘制菜单框(491, 5 + 5 * 31, "自动压枪", Menu::Window.AimBotTab.自动压枪.取绘制值());
		D3D_绘制菜单框(491, 5 + 6 * 31, "自动扳机", Menu::Window.AimBotTab.自动扳机.取绘制值());
	}
	if (二级菜单 == 2)
	{
		D3D_绘制菜单框(491, 5 + 0 * 31, "发光", Menu::Window.RadarTab.发光.取绘制值());
		D3D_绘制菜单框(491, 5 + 1 * 31, "队友透视 (头号特训模式)", Menu::Window.RadarTab.队友透视.取绘制值());
		D3D_绘制菜单框(491, 5 + 2 * 31, "物品透视", Menu::Window.RadarTab.显示物品.取绘制值());
		D3D_绘制菜单框(491, 5 + 3 * 31, "骨骼透视", Menu::Window.RadarTab.显示骨骼.取绘制值());
		D3D_绘制菜单框(491, 5 + 4 * 31, "血条透视", Menu::Window.RadarTab.显示血条.取绘制值());
		D3D_绘制菜单框(491, 5 + 5 * 31, "显示名字", Menu::Window.RadarTab.显示名字.取绘制值());
		D3D_绘制菜单框(491, 5 + 6 * 31, "显示头部", Menu::Window.RadarTab.显示头部.取绘制值());
		D3D_绘制菜单框(491, 5 + 7 * 31, "显示武器", Menu::Window.RadarTab.显示武器.取绘制值());
		D3D_绘制菜单框(491, 5 + 8 * 31, "显示信息", Menu::Window.RadarTab.显示信息.取绘制值());
		D3D_绘制菜单框(491, 5 + 9 * 31, "显示各种物品", Menu::Window.RadarTab.显示各种物品.取绘制值());
		D3D_绘制菜单框(491, 5 + 10 * 31, "雷达透视", Menu::Window.RadarTab.雷达透视.取绘制值());
		D3D_绘制菜单框(491, 5 + 11 * 31, "连跳", Menu::Window.RadarTab.连跳.取绘制值());
	}




	return true;
}

void CGUI::注册窗口(CWindow* window)
{
	Windows.push_back(window);

	// Resorting to put groupboxes at the start
	for (auto tab : window->Tabs)
	{
		for (auto control : tab->Controls)
		{
			if (control->Flag(UIFlags::UI_RenderFirst))
			{
				CControl * c = control;
				tab->Controls.erase(std::remove(tab->Controls.begin(), tab->Controls.end(), control), tab->Controls.end());
				tab->Controls.insert(tab->Controls.begin(), control);
			}
		}
	}
}


