/*
Syn's AyyWare Framework 2015
*/

#include "�Զ�����������.h"
#include "����_��������.h"



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


void ��������_���ܰ�������::����ֵ(int s)
{
	 key = s;
}

int ��������_���ܰ�������::ȡֵ()
{
	return key;
}

int ��������_���ܰ�������::ȡ����ֵ()
{
	if (key <= 0)
	{
		key = VK_LBUTTON;
		return 4;
	}
	if (key == VK_LBUTTON)//������
	{
		return 4;
	}
	if (key == VK_RBUTTON)//����Ҽ�
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


void ��������_����������::����ֵ(int s)
{
	ints = s;
}

int ��������_����������::ȡֵ()
{
	return ints;
}

int ��������_����������::ȡ����ֵ()
{
	return ints;
}








void ��������_���ܿ�����::����״̬(bool s)
{
	Active = s;
}

bool ��������_���ܿ�����::ȡ״̬()
{
	return Active;
}

void ��������_���ܿ�����::�л�״̬()
{
	Active = !Active;
}

int ��������_���ܿ�����::ȡ����ֵ()
{
	if (Active == true)
	{
		return 2;
	}
	else{ return 3; }

}

