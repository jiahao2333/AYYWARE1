/*
Syn's AyyWare Framework 2015
*/

#pragma once

#include "模版代码.h"
#include "offsets.h"

class IBaseClientDLL
{
public:

	ClientClass* GetAllClasses(void)
	{
		typedef ClientClass* (__thiscall* OriginalFn)(PVOID); //Anything inside a VTable is a __thiscall unless it completly disregards the thisptr. You can also call them as __stdcalls, but you won't have access to the __thisptr.
		return Call_从数组中取地址调用CALL<OriginalFn>(this, Offsets::VMT::CHL_GetAllClasses)(this); //Return the pointer to the head CClientClass.
	}
};