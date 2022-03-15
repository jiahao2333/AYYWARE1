#pragma once
#include "Interfaces.h"


namespace Render
{
	void 初始化();
	void 绘制直线(int x, int y, int w, int h, Color color);
	void 绘制直线1(int x, int y, int w, int h, Color color);
	void 绘制方框(int x, int y, int w, int h, Color color);
	void 绘制线条(int x, int y, int x2, int y2, Color color);
	void 绘制圆形(float x, float y, float r, float s, Color color); 

	namespace 字体
	{
		extern DWORD Default;
		extern DWORD Menu;
		extern DWORD ESP;
		extern DWORD Small;
		extern DWORD Middle;
		extern DWORD Large;

	};

	void 绘制文本(int x, int y, Color color, DWORD font, const char* text);
	RECT 取文本长度(DWORD font, const char* text);
	bool 矩阵转换(Vector &in, Vector &out);
	RECT 取屏幕大小();

};