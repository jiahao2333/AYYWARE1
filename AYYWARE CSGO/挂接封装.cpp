/*
Syn's AyyWare Framework 2015
*/

#include "��������_�ҽӷ�װ.h"
#include "ȫ�ֱ���.h" //Falsch?
#include <algorithm>
#include "tinyxml2.h"
#include "�Զ�����������.h"
#include "Hacks.h" //falsch?
#include "���Ʒ�װ.h"
bool ��ʾ�˵� = false;
int ��ǰ�˵� = -1;
int �����˵� = -1;
CGUI GUI;

bool ����Ƿ��ڷ�Χ��(int x, int y, int w, int h)
{
	POINT mp; GetCursorPos(&mp);
	ScreenToClient(GetForegroundWindow(), &mp); 

	if (mp.x >= x && mp.x <= x + w && mp.y >= y  && mp.y <= y + h)
	{
		return true;
	}
	else;
	return false;
}

CGUI::CGUI()
{

}


void CGUI::Draw()//D3D��ʼִ���ӳ���
{
	for (auto window : Windows)
	{
		if (��ʾ�˵� == true)
		{
			���ƹҽ�(window);
		}
	}
	
	if 	(��ʾ�˵� == true)//���ָ�����
	{
		// ȡ�������
		POINT mp; GetCursorPos(&mp);
		ScreenToClient(GetForegroundWindow(), &mp);
		Mouse.x = mp.x; Mouse.y = mp.y;
		RECT Screen = Render::ȡ��Ļ��С();//ȡ��Ļ��߶�
		Render::����ֱ��(Mouse.x + 1, Mouse.y, 1, 17, Color(178, 34, 34, 255));

		for (int i = 0; i < 11; i++)
			Render::����ֱ��(Mouse.x + 2 + i, Mouse.y + 1 + i, 1, 1, Color(178, 34, 34, 255));
		Render::����ֱ��(Mouse.x + 8, Mouse.y + 12, 5, 1, Color(178, 34, 34, 255));
		Render::����ֱ��(Mouse.x + 8, Mouse.y + 13, 1, 1, Color(178, 34, 34, 255));
		Render::����ֱ��(Mouse.x + 9, Mouse.y + 14, 1, 2, Color(178, 34, 34, 255));
		Render::����ֱ��(Mouse.x + 10, Mouse.y + 16, 1, 2, Color(178, 34, 34, 255));
		Render::����ֱ��(Mouse.x + 8, Mouse.y + 18, 2, 1, Color(178, 34, 34, 255));
		Render::����ֱ��(Mouse.x + 7, Mouse.y + 16, 1, 2, Color(178, 34, 34, 255));
		Render::����ֱ��(Mouse.x + 6, Mouse.y + 14, 1, 2, Color(178, 34, 34, 255));
		Render::����ֱ��(Mouse.x + 5, Mouse.y + 13, 1, 1, Color(178, 34, 34, 255));
		Render::����ֱ��(Mouse.x + 4, Mouse.y + 14, 1, 1, Color(178, 34, 34, 255));
		Render::����ֱ��(Mouse.x + 3, Mouse.y + 15, 1, 1, Color(178, 34, 34, 255));
		Render::����ֱ��(Mouse.x + 2, Mouse.y + 16, 1, 1, Color(178, 34, 34, 255));
		for (int i = 0; i < 4; i++)
			Render::����ֱ��(Mouse.x + 2 + i, Mouse.y + 2 + i, 1, 14 - (i * 2), Color(37 - (i * 4), 137 - (i * 4), 255 - (i * 4), 255));
		Render::����ֱ��(Mouse.x + 6, Mouse.y + 6, 1, 8, UI_COL_MAIN);
		Render::����ֱ��(Mouse.x + 7, Mouse.y + 7, 1, 9, UI_COL_MAIN);
		for (int i = 0; i < 4; i++)
			Render::����ֱ��(Mouse.x + 8 + i, Mouse.y + 8 + i, 1, 4 - i, Color(37 - (i * 4), 137 - (i * 4), 255 - (i * 4), 255));
		Render::����ֱ��(Mouse.x + 8, Mouse.y + 14, 1, 4, UI_COL_MAIN);
		Render::����ֱ��(Mouse.x + 9, Mouse.y + 16, 1, 2, UI_COL_MAIN);
	}



}

void CGUI::�����ҽ�()
{
	if (GetAsyncKeyState(VK_F9) == -32767)
	{
		��ʾ�˵� = !��ʾ�˵�;
	}

	if (GetAsyncKeyState(1) == -32767)//�������Ƿ���
	{
		//**************************һ���˵�*************************************
		if (����Ƿ��ڷ�Χ��(5, 5 + 0 * 31, 240, 31))
		{
			�����˵� = -1;
			if (��ǰ�˵� == 0)
			{
				��ǰ�˵� = -1;
			}
			else; ��ǰ�˵� = 0;
		}

		if (����Ƿ��ڷ�Χ��(5, 5 + 1 * 31, 240, 31))
		{
			�����˵� = -1;
			if (��ǰ�˵� == 1) { ��ǰ�˵� = -1; }
			else { ��ǰ�˵� = 1; }
		}

		if (����Ƿ��ڷ�Χ��(5, 5 + 2 * 31, 240, 31))
		{
			�����˵� = -1;
			if (��ǰ�˵� == 2) { ��ǰ�˵� = -1; }
			else { ��ǰ�˵� = 2; }
		}

		if (����Ƿ��ڷ�Χ��(5, 5 + 3 * 31, 240, 31))
		{
			�����˵� = -1;
			if (��ǰ�˵� == 3) { ��ǰ�˵� = -1; }
			else { ��ǰ�˵� = 3; }
		}
		//if (����Ƿ��ڷ�Χ��(5, 5 + 4 * 31, 240, 31))
		//{
		//	�����˵� = -1;
		//	if (��ǰ�˵� == 4) { ��ǰ�˵� = -1; }
		//	else { ��ǰ�˵� = 4; }
		//}

		//**************************�����˵�*************************************
		if (��ǰ�˵� == 1)//��������
		{
			if (����Ƿ��ڷ�Χ��(248, 5 + 1 * 31, 240, 31))
			{
				if (�����˵� == 1) { �����˵� = -1; }
				else { �����˵� = 1; }
			}
		}
		if (��ǰ�˵� == 2)//͸������
		{
			if (����Ƿ��ڷ�Χ��(248, 5 + 1 * 31, 240, 31))
			{
				if (�����˵� == 2) { �����˵� = -1; }
				else { �����˵� = 2; }
			}
		}


		//******************************ʵ�ʹ��ܿ���***************************
		if (��ǰ�˵� == 1)//���鿪��
		{
			if (����Ƿ��ڷ�Χ��(456, 5 + 0 * 31, 31, 31))
			{
				Menu::Window.AimBotTab.�Զ���׼.�л�״̬();
			}

		}
		if (��ǰ�˵� == 2)//����͸��
		{
			if (����Ƿ��ڷ�Χ��(456, 5 + 0 * 31, 31, 31))
			{
				Menu::Window.RadarTab.����͸��.�л�״̬();
			}
			if (����Ƿ��ڷ�Χ��(456, 5 + 1 * 31, 31, 31))
			{
				Menu::Window.RadarTab.����͸��.�л�״̬();
			}
		}
		if (��ǰ�˵� == 3)//����
		{
			if (����Ƿ��ڷ�Χ��(456, 5 + 0 * 31, 31, 31))
			{
				Menu::Window.RadarTab.ʮ��׼��.�л�״̬();
			}
			if (����Ƿ��ڷ�Χ��(456, 5 + 1 * 31, 31, 31))
			{
				Menu::Window.RadarTab.����׼��.�л�״̬();
			}
			if (����Ƿ��ڷ�Χ��(456, 5 + 2 * 31, 31, 31))
			{
				Menu::Window.RadarTab.NameSteal.�л�״̬();
			}
			if (����Ƿ��ڷ�Χ��(456, 5 + 3 * 31, 31, 31))
			{
				Menu::Window.RadarTab.��������.�л�״̬();

			}
			if (����Ƿ��ڷ�Χ��(456, 5 + 4 * 31, 31, 31))
			{
				Menu::Window.RadarTab.��ʾ��λ.�л�״̬();
			}
			//if (����Ƿ��ڷ�Χ��(456, 5 + 5 * 31, 31, 31))
			//{
			//	Menu::Window.RadarTab.���.�л�״̬();
			//}
			if (����Ƿ��ڷ�Χ��(456, 5 + 5 * 31, 31, 31))
			{
				Menu::Window.RadarTab.��ʾ�۲���.�л�״̬();

			}
			if (����Ƿ��ڷ�Χ��(456, 5 + 6 * 31, 31, 31))
			{
				Menu::Window.RadarTab.���޾ٱ�.�л�״̬();

			}

		}




		if (�����˵� == 1)
		{
			if (����Ƿ��ڷ�Χ��(699, 5 + 0 * 31, 31, 31))
			{
				int lpidex = Menu::Window.AimBotTab.��׼��λ.ȡֵ();
				lpidex = lpidex + 1;
				if (lpidex == 4) { lpidex = 0; }
				Menu::Window.AimBotTab.��׼��λ.����ֵ(lpidex);
			}
			if (����Ƿ��ڷ�Χ��(699, 5 + 1 * 31, 31, 31))
			{
				Menu::Window.AimBotTab.��׼����.�л�״̬();
			}
			if (����Ƿ��ڷ�Χ��(631, 5 + 2 * 31, 20, 30))//��������FOV
			{
				int fov = Menu::Window.AimBotTab.��׼��Χ.ȡֵ();
				if (fov >= 0)
				{
					fov = fov - 1;
					Menu::Window.AimBotTab.��׼��Χ.����ֵ(fov);
				}
			}
			if (����Ƿ��ڷ�Χ��(711, 5 + 2 * 31, 20, 30))//��������FOV
			{
				int fov = Menu::Window.AimBotTab.��׼��Χ.ȡֵ();
				if (fov <= 360)
				{
					fov = fov + 1;
					Menu::Window.AimBotTab.��׼��Χ.����ֵ(fov);
				}
			}
			if (����Ƿ��ڷ�Χ��(699, 5 + 3 * 31, 31, 31))
			{
				int aimkey = Menu::Window.AimBotTab.���鰴��.ȡֵ();

				if (aimkey == VK_LBUTTON)
				{
					Menu::Window.AimBotTab.���鰴��.����ֵ(VK_RBUTTON);//C��
				}
				if (aimkey == VK_RBUTTON)
				{
					Menu::Window.AimBotTab.���鰴��.����ֵ(VK_MENU);//Alt
				}
				if (aimkey == VK_MENU)
				{
					Menu::Window.AimBotTab.���鰴��.����ֵ(VK_CONTROL);//Ctrl
				}
				if (aimkey == VK_CONTROL)
				{
					Menu::Window.AimBotTab.���鰴��.����ֵ(VK_LBUTTON);//������
				}

			}
			
			//if (����Ƿ��ڷ�Χ��(699, 5 + 4 * 31, 31, 31))
			//{
			//	Menu::Window.AimBotTab.�Զ���ǹ.�л�״̬();
			//}

			if (����Ƿ��ڷ�Χ��(699, 5 + 4 * 31, 31, 31))
			{
				Menu::Window.AimBotTab.���Ӽ��.�л�״̬();
			}
			//if (����Ƿ��ڷ�Χ��(699, 5 + 5 * 31, 31, 31))
			//{
			//	Menu::Window.AimBotTab.�޺�����.�л�״̬();
			//}
			if (����Ƿ��ڷ�Χ��(699, 5 + 5 * 31, 31, 31))
			{
				Menu::Window.AimBotTab.�Զ�ѹǹ.�л�״̬();
			}
			if (����Ƿ��ڷ�Χ��(699, 5 + 6 * 31, 31, 31))
			{
				Menu::Window.AimBotTab.�Զ����.�л�״̬();
			}
		}
		if (�����˵� == 2)
		{
			if (����Ƿ��ڷ�Χ��(699, 5 + 0 * 31, 31, 31))
			{
				Menu::Window.RadarTab.����.�л�״̬();
			}
			if (����Ƿ��ڷ�Χ��(699, 5 + 1 * 31, 31, 31))
			{
				Menu::Window.RadarTab.����͸��.�л�״̬();
			}
			if (����Ƿ��ڷ�Χ��(699, 5 + 2 * 31, 31, 31))
			{
				Menu::Window.RadarTab.��ʾ��Ʒ.�л�״̬();
			}
			if (����Ƿ��ڷ�Χ��(699, 5 + 3 * 31, 31, 31))
			{
				Menu::Window.RadarTab.��ʾ����.�л�״̬();
			}

			if (����Ƿ��ڷ�Χ��(699, 5 + 4 * 31, 31, 31))
			{	
				Menu::Window.RadarTab.��ʾѪ��.�л�״̬();
			}

			if (����Ƿ��ڷ�Χ��(699, 5 + 5 * 31, 31, 31))
			{
				Menu::Window.RadarTab.��ʾ����.�л�״̬();
			}
			if (����Ƿ��ڷ�Χ��(699, 5 + 6 * 31, 31, 31))
			{
				Menu::Window.RadarTab.��ʾͷ��.�л�״̬();
			}
			if (����Ƿ��ڷ�Χ��(699, 5 + 7 * 31, 31, 31))
			{
				Menu::Window.RadarTab.��ʾ����.�л�״̬();
			}
			if (����Ƿ��ڷ�Χ��(699, 5 + 8 * 31, 31, 31))
			{
				Menu::Window.RadarTab.��ʾ��Ϣ.�л�״̬();
			}
			if (����Ƿ��ڷ�Χ��(699, 5 + 9 * 31, 31, 31))
			{
				Menu::Window.RadarTab.��ʾ������Ʒ.�л�״̬();
			}
			if (����Ƿ��ڷ�Χ��(699, 5 + 10 * 31, 31, 31))
			{
				Menu::Window.RadarTab.�״�͸��.�л�״̬();
			}
			if (����Ƿ��ڷ�Χ��(699, 5 + 11 * 31, 31, 31))
			{
				Menu::Window.RadarTab.����.�л�״̬();
			}


		}




	}
}






// Returns 





bool CGUI::GetKeyPress(unsigned int key)
{
	if (keys[key] == true && oldKeys[key] == false)
		return true;
	else
		return false;
}

bool CGUI::��ȡ����״̬(unsigned int key)
{
	if (key >= 0 && key <= 255)
		return keys[key];
	else
		return false;
}

bool CGUI::IsMouseInRegion(int x, int y, int x2, int y2)
{
	if (Mouse.x > x && Mouse.y > y && Mouse.x < x2 && Mouse.y < y2)
		return true;
	else
		return false;
}

bool CGUI::IsMouseInRegion(RECT region)
{
	return IsMouseInRegion(region.left, region.top, region.left + region.right, region.top + region.bottom);
}

POINT CGUI::GetMouse()
{
	return Mouse;
}

bool CGUI::���ƹҽ�(CWindow* window)//���Ʋ˵�
{
	D3D_���Ʋ˵���(5, 5 + 0 * 31, "���������ݼ���",0);
	D3D_���Ʋ˵���(5 ,5 + 1 * 31, "�Զ���׼",1);
	D3D_���Ʋ˵���(5, 5 + 2 * 31, "͸�ӹ���",1);
	D3D_���Ʋ˵���(5, 5 + 3 * 31, "�����",1);
	//D3D_���Ʋ˵���(5, 5 + 4 * 31, "��ɫ����",1);
	D3D_���Ʋ˵���(5, 5 + 4 * 31, "�ȶ���ȫ", 0);
	D3D_���Ʋ˵���(5, 5 + 5 * 31, "ÿ���Ƹ�", 0);
    //D3D_���Ʋ˵���(5, 5 + 7 * 31, "NameSteal", Menu::Window.RadarTab.NameSteal.ȡ����ֵ());
	

	
	if (��ǰ�˵� == 1)
	{
		D3D_���Ʋ˵���(248, 5 + 0 * 31, "�Զ���׼", Menu::Window.AimBotTab.�Զ���׼.ȡ����ֵ());
		D3D_���Ʋ˵���(248, 5 + 1 * 31, "��׼����", 1);
	}
	if (��ǰ�˵� == 2)
	{
		D3D_���Ʋ˵���(248, 5 + 0 * 31, "����͸��", Menu::Window.RadarTab.����͸��.ȡ����ֵ());
		D3D_���Ʋ˵���(248, 5 + 1 * 31, "͸������", 1);
	}
	if (��ǰ�˵� == 3)
	{
		D3D_���Ʋ˵���(248, 5 + 0 * 31, "ʮ��׼��", Menu::Window.RadarTab.ʮ��׼��.ȡ����ֵ());
		D3D_���Ʋ˵���(248, 5 + 1 * 31, "����׼��", Menu::Window.RadarTab.����׼��.ȡ����ֵ());
		D3D_���Ʋ˵���(248, 5 + 2 * 31, "��������", Menu::Window.RadarTab.NameSteal.ȡ����ֵ());
		D3D_���Ʋ˵���(248, 5 + 3 * 31, "��������", Menu::Window.RadarTab.��������.ȡ����ֵ());
		D3D_���Ʋ˵���(248, 5 + 4 * 31, "��ʾ��λ", Menu::Window.RadarTab.��ʾ��λ.ȡ����ֵ());
		//D3D_���Ʋ˵���(248, 5 + 5 * 31, "���", Menu::Window.RadarTab.���.ȡ����ֵ());
		D3D_���Ʋ˵���(248, 5 + 5 * 31, "��ʾ�۲��ߣ�Ĭ�Ͽ�����", Menu::Window.RadarTab.��ʾ�۲���.ȡ����ֵ());
		D3D_���Ʋ˵���(248, 5 + 6 * 31, "�ٱ��������", Menu::Window.RadarTab.���޾ٱ�.ȡ����ֵ());
	}
	//if (��ǰ�˵� == 4)
	//{
	//	D3D_���Ʋ˵���(248, 5 + 0 * 31, "������ɫ", 0);
	//	D3D_���Ʋ˵���(248, 5 + 1 * 31, "������ɫ", 0);
	//	D3D_���Ʋ˵���(248, 5 + 2 * 31, "׼����ɫ", 0);
	//}

	//******************************�����˵�����**************************************
	if (�����˵� == 1)
	{
		D3D_���Ʋ˵���(491, 5 + 0 * 31, "��׼��λ", Menu::Window.AimBotTab.��׼��λ.ȡ����ֵ() + 8);
		D3D_���Ʋ˵���(491, 5 + 1 * 31, "��׼���� (ͷ����ѵģʽ)", Menu::Window.AimBotTab.��׼����.ȡ����ֵ());
		D3D_���Ʋ˵���(491, 5 + 2 * 31, "��׼�Ƕ�", 0);
		D3D_����������(491, 5 + 2 * 31, Menu::Window.AimBotTab.��׼��Χ.ȡ����ֵ(), 360);
		D3D_���Ʋ˵���(491, 5 + 3 * 31, "��׼����", Menu::Window.AimBotTab.���鰴��.ȡ����ֵ());
//		D3D_���Ʋ˵���(491, 5 + 4 * 31, "�Զ���ǹ", Menu::Window.AimBotTab.�Զ���ǹ.ȡ����ֵ());
		D3D_���Ʋ˵���(491, 5 + 4 * 31, "���Ӽ��", Menu::Window.AimBotTab.���Ӽ��.ȡ����ֵ());
//		D3D_���Ʋ˵���(491, 5 + 5 * 31, "�޺�����", Menu::Window.AimBotTab.�޺�����.ȡ����ֵ());
		D3D_���Ʋ˵���(491, 5 + 5 * 31, "�Զ�ѹǹ", Menu::Window.AimBotTab.�Զ�ѹǹ.ȡ����ֵ());
		D3D_���Ʋ˵���(491, 5 + 6 * 31, "�Զ����", Menu::Window.AimBotTab.�Զ����.ȡ����ֵ());
	}
	if (�����˵� == 2)
	{
		D3D_���Ʋ˵���(491, 5 + 0 * 31, "����", Menu::Window.RadarTab.����.ȡ����ֵ());
		D3D_���Ʋ˵���(491, 5 + 1 * 31, "����͸�� (ͷ����ѵģʽ)", Menu::Window.RadarTab.����͸��.ȡ����ֵ());
		D3D_���Ʋ˵���(491, 5 + 2 * 31, "��Ʒ͸��", Menu::Window.RadarTab.��ʾ��Ʒ.ȡ����ֵ());
		D3D_���Ʋ˵���(491, 5 + 3 * 31, "����͸��", Menu::Window.RadarTab.��ʾ����.ȡ����ֵ());
		D3D_���Ʋ˵���(491, 5 + 4 * 31, "Ѫ��͸��", Menu::Window.RadarTab.��ʾѪ��.ȡ����ֵ());
		D3D_���Ʋ˵���(491, 5 + 5 * 31, "��ʾ����", Menu::Window.RadarTab.��ʾ����.ȡ����ֵ());
		D3D_���Ʋ˵���(491, 5 + 6 * 31, "��ʾͷ��", Menu::Window.RadarTab.��ʾͷ��.ȡ����ֵ());
		D3D_���Ʋ˵���(491, 5 + 7 * 31, "��ʾ����", Menu::Window.RadarTab.��ʾ����.ȡ����ֵ());
		D3D_���Ʋ˵���(491, 5 + 8 * 31, "��ʾ��Ϣ", Menu::Window.RadarTab.��ʾ��Ϣ.ȡ����ֵ());
		D3D_���Ʋ˵���(491, 5 + 9 * 31, "��ʾ������Ʒ", Menu::Window.RadarTab.��ʾ������Ʒ.ȡ����ֵ());
		D3D_���Ʋ˵���(491, 5 + 10 * 31, "�״�͸��", Menu::Window.RadarTab.�״�͸��.ȡ����ֵ());
		D3D_���Ʋ˵���(491, 5 + 11 * 31, "����", Menu::Window.RadarTab.����.ȡ����ֵ());
	}




	return true;
}

void CGUI::ע�ᴰ��(CWindow* window)
{
	Windows.push_back(window);

	// Resorting to put groupboxes at the start
	for (auto tab : window->Tabs)
	{
		for (auto control : tab->Controls)
		{
			if (control->Flag(UIFlags::UI_RenderFirst))
			{
				CControl * c = control;
				tab->Controls.erase(std::remove(tab->Controls.begin(), tab->Controls.end(), control), tab->Controls.end());
				tab->Controls.insert(tab->Controls.begin(), control);
			}
		}
	}
}


