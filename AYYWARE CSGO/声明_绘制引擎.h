#pragma once
#include "Interfaces.h"


namespace Render
{
	void ��ʼ��();
	void ����ֱ��(int x, int y, int w, int h, Color color);
	void ����ֱ��1(int x, int y, int w, int h, Color color);
	void ���Ʒ���(int x, int y, int w, int h, Color color);
	void ��������(int x, int y, int x2, int y2, Color color);
	void ����Բ��(float x, float y, float r, float s, Color color); 

	namespace ����
	{
		extern DWORD Default;
		extern DWORD Menu;
		extern DWORD ESP;
		extern DWORD Small;
		extern DWORD Middle;
		extern DWORD Large;

	};

	void �����ı�(int x, int y, Color color, DWORD font, const char* text);
	RECT ȡ�ı�����(DWORD font, const char* text);
	bool ����ת��(Vector &in, Vector &out);
	RECT ȡ��Ļ��С();

};