/*
Syn's AyyWare Framework 2015
*/

#pragma once

#include "变量声明_挂接封装.h"
#include "自定义数据类型.h"



struct PlayerListItem_t
{
	bool Friendly;
	bool AimPrio;
	bool Callout;
};



class AimBotClass : public CTab
{
public:
	void Setup();
	数据类型_功能开关类 初始化;
	数据类型_功能开关类 自动瞄准;
	数据类型_功能开关类 自动开枪;
	数据类型_功能数据类 瞄准范围;
	数据类型_功能开关类 静默自瞄;
	数据类型_功能开关类 无后坐力;
	数据类型_功能开关类 瞄准队友;
	数据类型_功能数据类 瞄准部位;
	数据类型_功能开关类 可视检查;
	数据类型_功能开关类 自动压枪;
	数据类型_功能按键绑定类  自瞄按键;
	数据类型_功能开关类 自动扳机;
};

class RadarClass : public CTab
{
public:
	void Setup();

	// 声明透视变量

	数据类型_功能开关类 人物透视;
	数据类型_功能开关类 方框透视;
	数据类型_功能开关类 队友透视;
	数据类型_功能开关类 显示骨骼;
	数据类型_功能开关类 无视闪光;
	数据类型_功能开关类 显示物品;
	数据类型_功能开关类 十字准心;
	数据类型_功能开关类 弹道准心;
	数据类型_功能开关类 显示头部;
	数据类型_功能开关类 显示名字;
	数据类型_功能开关类 显示血条;
	数据类型_功能开关类 显示武器;
	数据类型_功能开关类 显示信息;
	数据类型_功能开关类 显示各种物品;
	数据类型_功能开关类 显示观察者;
	数据类型_功能开关类 无限举报;
	数据类型_功能开关类 雷达透视;
	数据类型_功能开关类 连跳;
	数据类型_功能开关类 发光;
	数据类型_功能开关类 显示段位;
	数据类型_功能开关类 嘴臭;
	数据类型_功能开关类 NameSteal;
};



class HackWindow : public CWindow
{
public:
	void Setup();
	AimBotClass AimBotTab;
	RadarClass RadarTab;
};

namespace Menu
{
	void SetupMenu();
	void 功能初始化();
	extern HackWindow Window;
};