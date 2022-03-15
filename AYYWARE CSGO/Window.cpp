/*
Syn's AyyWare Framework 2015
*/

#pragma once

#include "变量声明_挂接封装.h"

#include "Interfaces.h"

//void CWindow::SetPosition(int x, int y)
//{
//	m_x = x; m_y = y;
//}

void CWindow::SetSize(int w, int h)
{
	m_iWidth = w;
	m_iHeight = h;
}

void CWindow::SetTitle(std::string title)
{
	Title = title;
}

void CWindow::注册功能分页(CTab* Tab)
{
	if (Tabs.size() == 0)
	{
		SelectedTab = Tab;
	}
	Tab->parent = this;
	Tabs.push_back(Tab);
}






void CWindow::Open()
{
	m_bIsOpen = true;
}

void CWindow::Close()
{
	m_bIsOpen = false;
}

void CWindow::Toggle()
{
	m_bIsOpen = !m_bIsOpen;
	if (m_bIsOpen)
		Interfaces::Engine->ClientCmd_Unrestricted("cl_mouseenable 0");
	else
		Interfaces::Engine->ClientCmd_Unrestricted("cl_mouseenable 1");
}

CControl* CWindow::GetFocus()
{
	return FocusedControl;
}

// TABS ---------------------------------------------------------------------------------------------------

void CTab::SetTitle(std::string name)
{
	Title = name;
}

void CTab::RegisterControl(CControl* control)
{
	control->parent = parent;
	Controls.push_back(control);
}