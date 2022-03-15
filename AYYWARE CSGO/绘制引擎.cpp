/*
Syn's AyyWare Framework 2015
*/

#pragma once

#include "声明_绘制引擎.h"

namespace Render
{
	namespace 字体
	{
		DWORD Menu;
		DWORD ESP;
		DWORD Small;
		DWORD Middle;
		DWORD Large;
		DWORD Default;

	};
};

enum 字体风格
{
	字体风格_FONTFLAG_NONE,
	字体风格_FONTFLAG_ITALIC = 0x001,
	字体风格_FONTFLAG_UNDERLINE = 0x002,
	字体风格_FONTFLAG_STRIKEOUT = 0x004,
	字体风格_FONTFLAG_SYMBOL = 0x008,
	字体风格_抗锯齿 = 0x010,
	字体风格_FONTFLAG_GAUSSIANBLUR = 0x020,
	字体风格_FONTFLAG_ROTARY = 0x040,
	字体风格_阴影 = 0x080,
	字体风格_FONTFLAG_ADDITIVE = 0x100,
	字体风格__轮廓 = 0x200,
	字体风格_FONTFLAG_CUSTOM = 0x400,
	字体风格_FONTFLAG_BITMAP = 0x800,
};

void Render::初始化()
{
	字体::Default = Interfaces::Surface->FontCreate();
	字体::Large = Interfaces::Surface->FontCreate();
	字体::Middle = Interfaces::Surface->FontCreate();
	字体::Small = Interfaces::Surface->FontCreate();
	字体::Menu = Interfaces::Surface->FontCreate();
	字体::ESP = Interfaces::Surface->FontCreate();


	const char* main_font = "微软雅黑";
	Interfaces::Surface->SetFontGlyphSet(字体::Large, main_font, 14, 900, 0, 0, 字体风格__轮廓);//大
	Interfaces::Surface->SetFontGlyphSet(字体::Middle, main_font, 14, 600, 0, 0, 字体风格__轮廓);//中
	Interfaces::Surface->SetFontGlyphSet(字体::Small, main_font, 9, 900, 0, 0, 字体风格__轮廓);//小
	Interfaces::Surface->SetFontGlyphSet(字体::Default, main_font, 16, 900, 0, 0, 字体风格__轮廓);
	Interfaces::Surface->SetFontGlyphSet(字体::Menu, main_font, 12, 900, 0, 0, 字体风格__轮廓);
	Interfaces::Surface->SetFontGlyphSet(字体::ESP, main_font, 13, 600, 0, 0, 字体风格__轮廓);
}

RECT Render::取屏幕大小()
{
	RECT Viewport = { 0, 0, 0, 0 };
	int w, h;
	Interfaces::Engine->GetScreenSize(w, h);
	Viewport.right = w; Viewport.bottom = h;
	return Viewport;
}

void Render::绘制直线(int x, int y, int w, int h, Color color)
{
	Interfaces::Surface->DrawSetColor(color);
	Interfaces::Surface->DrawFilledRect(x, y, x + w, y + h);
}
void Render::绘制直线1(int x, int y, int w, int h, Color color)
{
	Interfaces::Surface->DrawSetColor(color);
	Interfaces::Surface->DrawFilledRect(x, y, w, h);
}

void Render::绘制方框(int x, int y, int w, int h, Color color)
{
	Interfaces::Surface->DrawSetColor(color);
	Interfaces::Surface->DrawOutlinedRect(x, y, x + w, y + h);
}

void Render::绘制线条(int x, int y, int x2, int y2, Color color)
{
	Interfaces::Surface->DrawSetColor(color);
	Interfaces::Surface->DrawLine(x, y, x2, y2);
}



wchar_t* 编码转换_AnsiToUnicode(const char* szStr)
{
	int nLen = MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, szStr, -1, NULL, 0);
	if (nLen == 0)
	{
		return NULL;
	}
	wchar_t* pResult = new wchar_t[nLen];
	MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, szStr, -1, pResult, nLen);
	return pResult;
}

void Render::绘制文本(int x, int y, Color color, DWORD font, const char* text)
{
	size_t origsize = strlen(text) + 1;
	const size_t newsize = 100;
	size_t convertedChars = 0;
	wchar_t wcstring[newsize];
	mbstowcs_s(&convertedChars, wcstring, origsize, text, _TRUNCATE);
	Interfaces::Surface->DrawSetTextFont(font);
	Interfaces::Surface->DrawSetTextColor(color);
	Interfaces::Surface->DrawSetTextPos(x, y);
	Interfaces::Surface->DrawPrintText(编码转换_AnsiToUnicode(text), wcslen(编码转换_AnsiToUnicode(text)));
	return;
}

bool Render::矩阵转换(Vector &in, Vector &out)
{
	const matrix3x4& 矩阵数据 = Interfaces::Engine->取世界到屏幕矩阵(); 
	float w = 矩阵数据[3][0] * in[0] + 矩阵数据[3][1] * in[1] + 矩阵数据[3][2] * in[2]  + 矩阵数据[3][3];
	//矩阵[3x0] = 求余弦(x) * 求余弦(y)
	//矩阵[3x1] = 求正弦(x) * 求正弦(y)
	//矩阵[3x2] = 求正弦(y)
	out.z = 0;
	if (w > 0.001) 
	{
		RECT 屏幕宽高 = 取屏幕大小();
		float fl1DBw = 1 / w; 
		out.x = (屏幕宽高.right / 2) + (0.5f * ((矩阵数据[0][0] * in[0] + 矩阵数据[0][1] * in[1] + 矩阵数据[0][2] * in[2] + 矩阵数据[0][3]) * fl1DBw) * 屏幕宽高.right + 0.5f); //Get the X dimension and push it in to the Vector.
		out.y = (屏幕宽高.bottom / 2) - (0.5f * ((矩阵数据[1][0] * in[0] + 矩阵数据[1][1] * in[1] + 矩阵数据[1][2] * in[2] + 矩阵数据[1][3]) * fl1DBw) * 屏幕宽高.bottom + 0.5f); //Get the Y dimension and push it in to the Vector.
		return true;
	}
	return false;
}


RECT Render::取文本长度(DWORD font, const char* text)
{
	size_t origsize = strlen(text) + 1;
	const size_t newsize = 100;
	size_t convertedChars = 0;
	wchar_t wcstring[newsize];
	mbstowcs_s(&convertedChars, wcstring, origsize, text, _TRUNCATE);

	RECT rect; int x, y;
	Interfaces::Surface->GetTextSize(font, wcstring, x, y);
	rect.left = x; rect.bottom = y;
	rect.right = x;
	return rect;
}

void Render::绘制圆形(float x, float y, float r, float s, Color color)
{
	float Step = PI * 2.0 / s;
	for (float a = 0; a < (PI*2.0); a += Step)
	{
		float x1 = r * cos(a) + x;
		float y1 = r * sin(a) + y;
		float x2 = r * cos(a + Step) + x;
		float y2 = r * sin(a + Step) + y;
		Interfaces::Surface->DrawSetColor(color);
		Interfaces::Surface->DrawLine(x1, y1, x2, y2);
	}
}



