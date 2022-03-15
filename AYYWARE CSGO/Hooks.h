/*
Syn's AyyWare Framework 2015
*/

#pragma once

// It's actually in DLLMain but w/e
extern bool DoUnload;

#include "Utilities.h"

namespace Hooks
{
	void Initialise();
	void UndoHooks();

	// VMT Managers
	extern Utilities::内存操作::VMTManager VMTPanel; // Hooking drawing functions
	extern Utilities::内存操作::VMTManager VMTClient; // Maybe CreateMove
	extern Utilities::内存操作::VMTManager VMTClientMode; // CreateMove for functionality
	extern Utilities::内存操作::VMTManager VMTModelRender; // DrawModelEx for chams
	extern Utilities::内存操作::VMTManager VMTPrediction; // InPrediction for no vis recoil
	extern Utilities::内存操作::VMTManager VMTPlaySound; // Autoaccept shit
	extern Utilities::内存操作::VMTManager VMTRenderView;
};