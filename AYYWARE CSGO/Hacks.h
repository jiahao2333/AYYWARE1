/*
Syn's AyyWare Framework 2015
*/

#pragma once

#pragma once

#include "CommonIncludes.h"
#include "SDK.h"
#include "全局变量.h"
#include <vector>

namespace Hacks
{
	void 安装外挂();
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
	void 安装(CHack* hake);
	void 激活();

	void Draw();
	void Move(CUserCmd *pCmd,bool &bSendPacket);
	IClientEntity *pLocal();
private:
	std::vector<CHack*> Hacks;
	IClientEntity *pLocalInstance;
	bool 是否激活;
};

extern HackManager hackManager;