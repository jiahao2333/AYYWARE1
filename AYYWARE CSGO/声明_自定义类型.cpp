/*
Syn's AyyWare Framework 2015
*/

#include "自定义数据类型.h"
#include "声明_绘制引擎.h"



#pragma region Base Control
void CControl::SetPosition(int x, int y)
{
	m_x = x;
	m_y = y;
}

void CControl::SetSize(int w, int h)
{
	m_iWidth = w;
	m_iHeight = h;
}

void CControl::GetSize(int &w, int &h)
{
	w = m_iWidth;
	h = m_iHeight;
}

bool CControl::Flag(int f)
{
	if (m_Flags & f)
		return true;
	else
		return false;
}


void CControl::SetFileId(std::string fid)
{
	FileIdentifier = fid;
}
#pragma endregion Implementations of the Base control functions


void 数据类型_功能按键绑定类::设置值(int s)
{
	 key = s;
}

int 数据类型_功能按键绑定类::取值()
{
	return key;
}

int 数据类型_功能按键绑定类::取绘制值()
{
	if (key <= 0)
	{
		key = VK_LBUTTON;
		return 4;
	}
	if (key == VK_LBUTTON)//鼠标左键
	{
		return 4;
	}
	if (key == VK_RBUTTON)//鼠标右键
	{
		return 5;
	}
	if (key == VK_MENU)//Alt
	{
		return 6;
	}
	if (key == VK_SHIFT)//Shift
	{
		return 7;
	}
}


void 数据类型_功能数据类::设置值(int s)
{
	ints = s;
}

int 数据类型_功能数据类::取值()
{
	return ints;
}

int 数据类型_功能数据类::取绘制值()
{
	return ints;
}








void 数据类型_功能开关类::设置状态(bool s)
{
	Active = s;
}

bool 数据类型_功能开关类::取状态()
{
	return Active;
}

void 数据类型_功能开关类::切换状态()
{
	Active = !Active;
}

int 数据类型_功能开关类::取绘制值()
{
	if (Active == true)
	{
		return 2;
	}
	else{ return 3; }

}

