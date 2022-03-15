#include "声明_绘制引擎.h"



void D3D_绘制菜单框(int X, int Y, const char* Text,int Type)
{
	Render::绘制方框(X - 1, Y - 1, 241, 30, Color(178, 34, 34, 255));
	Render::绘制直线(X, Y, 239, 28, Color(0, 0, 0, 220));
	Render::绘制文本(X + 7, Y + 5, Color(255, 255, 255, 255), Render::字体::Middle, Text);
	if (Type == 1)
	{
		Render::绘制文本(X + 223, Y + 5, Color(255, 255, 255, 255), Render::字体::Middle, "♂");	//绘制箭头
	}
	if (Type == 2)
	{
		Render::绘制方框(X + 211, Y - 1, 29, 29, Color(0, 0, 0, 255));
		Render::绘制直线(X + 212, Y, 28, 28, Color(0,170, 240, 255));
		Render::绘制文本(X + 213, Y + 5, Color(255, 255, 255, 255), Render::字体::Middle, "开启");

	}
	if (Type == 3)
	{
		Render::绘制方框(X + 211, Y - 1, 29, 29, Color(0, 0, 0, 255));
		Render::绘制直线(X + 212, Y, 28, 28, Color(255, 0, 0, 255));
		Render::绘制文本(X + 213, Y + 5, Color(255, 255, 255, 255), Render::字体::Middle, "关闭");

	}
	if (Type == 4)
	{
		Render::绘制方框(X + 211, Y - 1, 29, 29, Color(0, 0, 0, 255));
		Render::绘制直线(X + 212, Y, 28, 28, Color(0, 255, 0, 255));
		Render::绘制文本(X + 213, Y + 5, Color(255, 255, 255, 255), Render::字体::Middle, "左键");
	}
	if (Type == 5)
	{
		Render::绘制方框(X + 211, Y - 1, 29, 29, Color(0, 0, 0, 255));
		Render::绘制直线(X + 212, Y, 28, 28, Color(0, 255, 0, 255));
		Render::绘制文本(X + 213, Y + 5, Color(255, 255, 255, 255), Render::字体::Middle, "右键");
	}
	if (Type == 6)
	{
		Render::绘制方框(X + 211, Y - 1, 29, 29, Color(0, 0, 0, 255));
		Render::绘制直线(X + 212, Y, 28, 28, Color(0, 255, 0, 255));
		Render::绘制文本(X + 213, Y + 5, Color(255, 255, 255, 255), Render::字体::Middle, "Alt");
	}
	if (Type == 7)
	{
		Render::绘制方框(X + 211, Y - 1, 29, 29, Color(0, 0, 0, 255));
		Render::绘制直线(X + 212, Y, 28, 28, Color(0, 255, 0, 255));
		Render::绘制文本(X + 213, Y + 5, Color(255, 255, 255, 255), Render::字体::Middle, "Ctrl");
	}
	if (Type == 8)
	{
		Render::绘制方框(X + 211, Y - 1, 29, 29, Color(0, 0, 0, 255));
		Render::绘制直线(X + 212, Y, 28, 28, Color(0, 255, 0, 255));
		Render::绘制文本(X + 213, Y + 5, Color(255, 255, 255, 255), Render::字体::Middle, "头部");
	}
	if (Type == 9)
	{
		Render::绘制方框(X + 211, Y - 1, 29, 29, Color(0, 0, 0, 255));
		Render::绘制直线(X + 212, Y, 28, 28, Color(0, 255, 0, 255));
		Render::绘制文本(X + 213, Y + 5, Color(255, 255, 255, 255), Render::字体::Middle, "脖子");
	}
	if (Type == 10)
	{
		Render::绘制方框(X + 211, Y - 1, 29, 29, Color(0, 0, 0, 255));
		Render::绘制直线(X + 212, Y, 28, 28, Color(0, 255, 0, 255));
		Render::绘制文本(X + 213, Y + 5, Color(255, 255, 255, 255), Render::字体::Middle, "胸部");
	}
	if (Type == 11)
	{
		Render::绘制方框(X + 211, Y - 1, 29, 29, Color(0, 0, 0, 255));
		Render::绘制直线(X + 212, Y, 28, 28, Color(0, 255, 0, 255));
		Render::绘制文本(X + 213, Y + 5, Color(255, 255, 255, 255), Render::字体::Middle, "全身");
	}
}

void D3D_绘制数据条(int x, int y ,int in , int maxin)
{
	//左边
	Render::绘制方框(x + 140, y-1, 20, 30, Color(0, 0, 0, 255));
	Render::绘制直线(x + 141, y , 18, 28, Color(0, 170, 240, 255));
	Render::绘制文本(x + 145, y + 5, Color(255, 255, 255, 255), Render::字体::Middle, "<");

	//中间
	char a[11];
	const char *p = itoa(in, a, 10);
	printf("%s\n", p);
	char b[11];
	const char *o = itoa(maxin, b, 10);
	printf("%s\n",o );

	std::string Text1 = p;
	std::string Text2 = o;
	std::string BFBText = Text1 + "/" + Text2;
	Render::绘制文本(x + 167, y + 6, Color(255, 255, 255, 255), Render::字体::Middle, BFBText.c_str());

	//右边
	Render::绘制方框(x + 220, y-1, 20, 30, Color(0, 0, 0, 255));
	Render::绘制直线(x + 221, y , 18, 28, Color(0, 170, 240, 255));
	Render::绘制文本(x + 225, y + 5, Color(255, 255, 255, 255), Render::字体::Middle, ">");

}




void D3D_绘制方框(int x, int y, int w,int h,Color color,int px)
{
	Render::绘制直线(x, y + h - px, w, px, color);
	Render::绘制直线(x, y, px, h, color);
	Render::绘制直线(x, y, w, px, color);
	Render::绘制直线(x + w - px, y, px, h, color);
}

void D3D_绘制文本_中(int x, int y, int w, int h, Color color, const char* Text)
{
	Render::绘制文本(x,y, color, Render::字体::Middle, Text);
}

void D3D_绘制文本_小(int x, int y, int w, int h, Color color, const char* Text)
{
	Render::绘制文本(x, y, color, Render::字体::Small, Text);
}

void D3D_绘制文本_大(int x, int y, int w, int h, Color color, const char* Text)
{
	Render::绘制文本(x, y, color, Render::字体::Large, Text);
}

void L_D3D_绘制文本_大(int x, int y, int w, int h, Color color, const char* Text)
{
	Render::绘制文本(x+1, y, Color(0, 0, 0, 255), Render::字体::Large, Text);
	Render::绘制文本(x-1, y, Color(0, 0, 0, 255), Render::字体::Large, Text);
	Render::绘制文本(x, y+1, Color(0, 0, 0, 255), Render::字体::Large, Text);
	Render::绘制文本(x, y-1, Color(0, 0, 0, 255), Render::字体::Large, Text);
	Render::绘制文本(x, y, color, Render::字体::Large, Text);
}

void L_D3D_绘制文本_中(int x, int y, int w, int h, Color color, const char* Text)
{
	Render::绘制文本(x + 1, y, Color(0, 0, 0, 255), Render::字体::Middle, Text);
	Render::绘制文本(x - 1, y, Color(0, 0, 0, 255), Render::字体::Middle, Text);
	Render::绘制文本(x, y + 1, Color(0, 0, 0, 255), Render::字体::Middle, Text);
	Render::绘制文本(x, y - 1, Color(0, 0, 0, 255), Render::字体::Middle, Text);
	Render::绘制文本(x, y, color, Render::字体::Middle, Text);
}

void L_D3D_绘制文本_小(int x, int y, int w, int h, Color color, const char* Text)
{
	Render::绘制文本(x + 1, y, Color(0, 0, 0, 255), Render::字体::Small, Text);
	Render::绘制文本(x - 1, y, Color(0, 0, 0, 255), Render::字体::Small, Text);
	Render::绘制文本(x, y + 1, Color(0, 0, 0, 255), Render::字体::Small, Text);
	Render::绘制文本(x, y - 1, Color(0, 0, 0, 255), Render::字体::Small, Text);
	Render::绘制文本(x, y, color, Render::字体::Middle, Text);
}

void D3D_绘制直线(int x, int y, int w, int h, Color color)
{
	Render::绘制直线(x, y , w,h, color);
}

void D3D_绘制线条(int startx, int starty, int endx, int endy, Color color)
{
	Render::绘制线条(startx, starty, endx, endy, color);
}