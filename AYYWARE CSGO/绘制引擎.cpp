/*
Syn's AyyWare Framework 2015
*/

#pragma once

#include "����_��������.h"

namespace Render
{
	namespace ����
	{
		DWORD Menu;
		DWORD ESP;
		DWORD Small;
		DWORD Middle;
		DWORD Large;
		DWORD Default;

	};
};

enum ������
{
	������_FONTFLAG_NONE,
	������_FONTFLAG_ITALIC = 0x001,
	������_FONTFLAG_UNDERLINE = 0x002,
	������_FONTFLAG_STRIKEOUT = 0x004,
	������_FONTFLAG_SYMBOL = 0x008,
	������_����� = 0x010,
	������_FONTFLAG_GAUSSIANBLUR = 0x020,
	������_FONTFLAG_ROTARY = 0x040,
	������_��Ӱ = 0x080,
	������_FONTFLAG_ADDITIVE = 0x100,
	������__���� = 0x200,
	������_FONTFLAG_CUSTOM = 0x400,
	������_FONTFLAG_BITMAP = 0x800,
};

void Render::��ʼ��()
{
	����::Default = Interfaces::Surface->FontCreate();
	����::Large = Interfaces::Surface->FontCreate();
	����::Middle = Interfaces::Surface->FontCreate();
	����::Small = Interfaces::Surface->FontCreate();
	����::Menu = Interfaces::Surface->FontCreate();
	����::ESP = Interfaces::Surface->FontCreate();


	const char* main_font = "΢���ź�";
	Interfaces::Surface->SetFontGlyphSet(����::Large, main_font, 14, 900, 0, 0, ������__����);//��
	Interfaces::Surface->SetFontGlyphSet(����::Middle, main_font, 14, 600, 0, 0, ������__����);//��
	Interfaces::Surface->SetFontGlyphSet(����::Small, main_font, 9, 900, 0, 0, ������__����);//С
	Interfaces::Surface->SetFontGlyphSet(����::Default, main_font, 16, 900, 0, 0, ������__����);
	Interfaces::Surface->SetFontGlyphSet(����::Menu, main_font, 12, 900, 0, 0, ������__����);
	Interfaces::Surface->SetFontGlyphSet(����::ESP, main_font, 13, 600, 0, 0, ������__����);
}

RECT Render::ȡ��Ļ��С()
{
	RECT Viewport = { 0, 0, 0, 0 };
	int w, h;
	Interfaces::Engine->GetScreenSize(w, h);
	Viewport.right = w; Viewport.bottom = h;
	return Viewport;
}

void Render::����ֱ��(int x, int y, int w, int h, Color color)
{
	Interfaces::Surface->DrawSetColor(color);
	Interfaces::Surface->DrawFilledRect(x, y, x + w, y + h);
}
void Render::����ֱ��1(int x, int y, int w, int h, Color color)
{
	Interfaces::Surface->DrawSetColor(color);
	Interfaces::Surface->DrawFilledRect(x, y, w, h);
}

void Render::���Ʒ���(int x, int y, int w, int h, Color color)
{
	Interfaces::Surface->DrawSetColor(color);
	Interfaces::Surface->DrawOutlinedRect(x, y, x + w, y + h);
}

void Render::��������(int x, int y, int x2, int y2, Color color)
{
	Interfaces::Surface->DrawSetColor(color);
	Interfaces::Surface->DrawLine(x, y, x2, y2);
}



wchar_t* ����ת��_AnsiToUnicode(const char* szStr)
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

void Render::�����ı�(int x, int y, Color color, DWORD font, const char* text)
{
	size_t origsize = strlen(text) + 1;
	const size_t newsize = 100;
	size_t convertedChars = 0;
	wchar_t wcstring[newsize];
	mbstowcs_s(&convertedChars, wcstring, origsize, text, _TRUNCATE);
	Interfaces::Surface->DrawSetTextFont(font);
	Interfaces::Surface->DrawSetTextColor(color);
	Interfaces::Surface->DrawSetTextPos(x, y);
	Interfaces::Surface->DrawPrintText(����ת��_AnsiToUnicode(text), wcslen(����ת��_AnsiToUnicode(text)));
	return;
}

bool Render::����ת��(Vector &in, Vector &out)
{
	const matrix3x4& �������� = Interfaces::Engine->ȡ���絽��Ļ����(); 
	float w = ��������[3][0] * in[0] + ��������[3][1] * in[1] + ��������[3][2] * in[2]  + ��������[3][3];
	//����[3x0] = ������(x) * ������(y)
	//����[3x1] = ������(x) * ������(y)
	//����[3x2] = ������(y)
	out.z = 0;
	if (w > 0.001) 
	{
		RECT ��Ļ��� = ȡ��Ļ��С();
		float fl1DBw = 1 / w; 
		out.x = (��Ļ���.right / 2) + (0.5f * ((��������[0][0] * in[0] + ��������[0][1] * in[1] + ��������[0][2] * in[2] + ��������[0][3]) * fl1DBw) * ��Ļ���.right + 0.5f); //Get the X dimension and push it in to the Vector.
		out.y = (��Ļ���.bottom / 2) - (0.5f * ((��������[1][0] * in[0] + ��������[1][1] * in[1] + ��������[1][2] * in[2] + ��������[1][3]) * fl1DBw) * ��Ļ���.bottom + 0.5f); //Get the Y dimension and push it in to the Vector.
		return true;
	}
	return false;
}


RECT Render::ȡ�ı�����(DWORD font, const char* text)
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

void Render::����Բ��(float x, float y, float r, float s, Color color)
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



