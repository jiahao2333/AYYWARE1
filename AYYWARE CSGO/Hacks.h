/*
Syn's AyyWare Framework 2015
*/

#pragma once

#pragma once

#include "CommonIncludes.h"
#include "SDK.h"
#include "ȫ�ֱ���.h"
#include <vector>

namespace Hacks
{
	void ��װ���();
	void DrawHacks();
}

class CHack
{
public:
	virtual void Draw() = 0;
	virtual void Move(CUserCmd *pCmd, bool &bSendPacket) = 0;
	virtual void Init() = 0;
};


class HackManager
{
public:
	void ��װ(CHack* hake);
	void ����();

	void Draw();
	void Move(CUserCmd *pCmd,bool &bSendPacket);
	IClientEntity *pLocal();
private:
	std::vector<CHack*> Hacks;
	IClientEntity *pLocalInstance;
	bool �Ƿ񼤻�;
};

extern HackManager hackManager;