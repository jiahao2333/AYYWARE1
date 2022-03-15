/*
Syn's AyyWare Framework 2015
*/

#pragma once

#include "变量声明_挂接封装.h"

class 数据类型_功能开关类
{
public:
	void 设置状态(bool s);
	void 切换状态();
	int 取绘制值();
	bool 取状态();
protected:
	bool Active;
};

class 数据类型_功能按键绑定类
{
public:
	void 设置值(int s);
	int 取绘制值();
	int 取值();
protected:
	int key;
};

class 数据类型_功能数据类
{
public:
	void 设置值(int s);
	int 取绘制值();
	int 取值();
protected:
	int ints;
};

