#include "����_��������.h"



void D3D_���Ʋ˵���(int X, int Y, const char* Text,int Type)
{
	Render::���Ʒ���(X - 1, Y - 1, 241, 30, Color(178, 34, 34, 255));
	Render::����ֱ��(X, Y, 239, 28, Color(0, 0, 0, 220));
	Render::�����ı�(X + 7, Y + 5, Color(255, 255, 255, 255), Render::����::Middle, Text);
	if (Type == 1)
	{
		Render::�����ı�(X + 223, Y + 5, Color(255, 255, 255, 255), Render::����::Middle, "��");	//���Ƽ�ͷ
	}
	if (Type == 2)
	{
		Render::���Ʒ���(X + 211, Y - 1, 29, 29, Color(0, 0, 0, 255));
		Render::����ֱ��(X + 212, Y, 28, 28, Color(0,170, 240, 255));
		Render::�����ı�(X + 213, Y + 5, Color(255, 255, 255, 255), Render::����::Middle, "����");

	}
	if (Type == 3)
	{
		Render::���Ʒ���(X + 211, Y - 1, 29, 29, Color(0, 0, 0, 255));
		Render::����ֱ��(X + 212, Y, 28, 28, Color(255, 0, 0, 255));
		Render::�����ı�(X + 213, Y + 5, Color(255, 255, 255, 255), Render::����::Middle, "�ر�");

	}
	if (Type == 4)
	{
		Render::���Ʒ���(X + 211, Y - 1, 29, 29, Color(0, 0, 0, 255));
		Render::����ֱ��(X + 212, Y, 28, 28, Color(0, 255, 0, 255));
		Render::�����ı�(X + 213, Y + 5, Color(255, 255, 255, 255), Render::����::Middle, "���");
	}
	if (Type == 5)
	{
		Render::���Ʒ���(X + 211, Y - 1, 29, 29, Color(0, 0, 0, 255));
		Render::����ֱ��(X + 212, Y, 28, 28, Color(0, 255, 0, 255));
		Render::�����ı�(X + 213, Y + 5, Color(255, 255, 255, 255), Render::����::Middle, "�Ҽ�");
	}
	if (Type == 6)
	{
		Render::���Ʒ���(X + 211, Y - 1, 29, 29, Color(0, 0, 0, 255));
		Render::����ֱ��(X + 212, Y, 28, 28, Color(0, 255, 0, 255));
		Render::�����ı�(X + 213, Y + 5, Color(255, 255, 255, 255), Render::����::Middle, "Alt");
	}
	if (Type == 7)
	{
		Render::���Ʒ���(X + 211, Y - 1, 29, 29, Color(0, 0, 0, 255));
		Render::����ֱ��(X + 212, Y, 28, 28, Color(0, 255, 0, 255));
		Render::�����ı�(X + 213, Y + 5, Color(255, 255, 255, 255), Render::����::Middle, "Ctrl");
	}
	if (Type == 8)
	{
		Render::���Ʒ���(X + 211, Y - 1, 29, 29, Color(0, 0, 0, 255));
		Render::����ֱ��(X + 212, Y, 28, 28, Color(0, 255, 0, 255));
		Render::�����ı�(X + 213, Y + 5, Color(255, 255, 255, 255), Render::����::Middle, "ͷ��");
	}
	if (Type == 9)
	{
		Render::���Ʒ���(X + 211, Y - 1, 29, 29, Color(0, 0, 0, 255));
		Render::����ֱ��(X + 212, Y, 28, 28, Color(0, 255, 0, 255));
		Render::�����ı�(X + 213, Y + 5, Color(255, 255, 255, 255), Render::����::Middle, "����");
	}
	if (Type == 10)
	{
		Render::���Ʒ���(X + 211, Y - 1, 29, 29, Color(0, 0, 0, 255));
		Render::����ֱ��(X + 212, Y, 28, 28, Color(0, 255, 0, 255));
		Render::�����ı�(X + 213, Y + 5, Color(255, 255, 255, 255), Render::����::Middle, "�ز�");
	}
	if (Type == 11)
	{
		Render::���Ʒ���(X + 211, Y - 1, 29, 29, Color(0, 0, 0, 255));
		Render::����ֱ��(X + 212, Y, 28, 28, Color(0, 255, 0, 255));
		Render::�����ı�(X + 213, Y + 5, Color(255, 255, 255, 255), Render::����::Middle, "ȫ��");
	}
}

void D3D_����������(int x, int y ,int in , int maxin)
{
	//���
	Render::���Ʒ���(x + 140, y-1, 20, 30, Color(0, 0, 0, 255));
	Render::����ֱ��(x + 141, y , 18, 28, Color(0, 170, 240, 255));
	Render::�����ı�(x + 145, y + 5, Color(255, 255, 255, 255), Render::����::Middle, "<");

	//�м�
	char a[11];
	const char *p = itoa(in, a, 10);
	printf("%s\n", p);
	char b[11];
	const char *o = itoa(maxin, b, 10);
	printf("%s\n",o );

	std::string Text1 = p;
	std::string Text2 = o;
	std::string BFBText = Text1 + "/" + Text2;
	Render::�����ı�(x + 167, y + 6, Color(255, 255, 255, 255), Render::����::Middle, BFBText.c_str());

	//�ұ�
	Render::���Ʒ���(x + 220, y-1, 20, 30, Color(0, 0, 0, 255));
	Render::����ֱ��(x + 221, y , 18, 28, Color(0, 170, 240, 255));
	Render::�����ı�(x + 225, y + 5, Color(255, 255, 255, 255), Render::����::Middle, ">");

}




void D3D_���Ʒ���(int x, int y, int w,int h,Color color,int px)
{
	Render::����ֱ��(x, y + h - px, w, px, color);
	Render::����ֱ��(x, y, px, h, color);
	Render::����ֱ��(x, y, w, px, color);
	Render::����ֱ��(x + w - px, y, px, h, color);
}

void D3D_�����ı�_��(int x, int y, int w, int h, Color color, const char* Text)
{
	Render::�����ı�(x,y, color, Render::����::Middle, Text);
}

void D3D_�����ı�_С(int x, int y, int w, int h, Color color, const char* Text)
{
	Render::�����ı�(x, y, color, Render::����::Small, Text);
}

void D3D_�����ı�_��(int x, int y, int w, int h, Color color, const char* Text)
{
	Render::�����ı�(x, y, color, Render::����::Large, Text);
}

void L_D3D_�����ı�_��(int x, int y, int w, int h, Color color, const char* Text)
{
	Render::�����ı�(x+1, y, Color(0, 0, 0, 255), Render::����::Large, Text);
	Render::�����ı�(x-1, y, Color(0, 0, 0, 255), Render::����::Large, Text);
	Render::�����ı�(x, y+1, Color(0, 0, 0, 255), Render::����::Large, Text);
	Render::�����ı�(x, y-1, Color(0, 0, 0, 255), Render::����::Large, Text);
	Render::�����ı�(x, y, color, Render::����::Large, Text);
}

void L_D3D_�����ı�_��(int x, int y, int w, int h, Color color, const char* Text)
{
	Render::�����ı�(x + 1, y, Color(0, 0, 0, 255), Render::����::Middle, Text);
	Render::�����ı�(x - 1, y, Color(0, 0, 0, 255), Render::����::Middle, Text);
	Render::�����ı�(x, y + 1, Color(0, 0, 0, 255), Render::����::Middle, Text);
	Render::�����ı�(x, y - 1, Color(0, 0, 0, 255), Render::����::Middle, Text);
	Render::�����ı�(x, y, color, Render::����::Middle, Text);
}

void L_D3D_�����ı�_С(int x, int y, int w, int h, Color color, const char* Text)
{
	Render::�����ı�(x + 1, y, Color(0, 0, 0, 255), Render::����::Small, Text);
	Render::�����ı�(x - 1, y, Color(0, 0, 0, 255), Render::����::Small, Text);
	Render::�����ı�(x, y + 1, Color(0, 0, 0, 255), Render::����::Small, Text);
	Render::�����ı�(x, y - 1, Color(0, 0, 0, 255), Render::����::Small, Text);
	Render::�����ı�(x, y, color, Render::����::Middle, Text);
}

void D3D_����ֱ��(int x, int y, int w, int h, Color color)
{
	Render::����ֱ��(x, y , w,h, color);
}

void D3D_��������(int startx, int starty, int endx, int endy, Color color)
{
	Render::��������(startx, starty, endx, endy, color);
}