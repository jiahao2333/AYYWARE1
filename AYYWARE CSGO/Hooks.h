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
	extern Utilities::�ڴ����::VMTManager VMTPanel; // Hooking drawing functions
	extern Utilities::�ڴ����::VMTManager VMTClient; // Maybe CreateMove
	extern Utilities::�ڴ����::VMTManager VMTClientMode; // CreateMove for functionality
	extern Utilities::�ڴ����::VMTManager VMTModelRender; // DrawModelEx for chams
	extern Utilities::�ڴ����::VMTManager VMTPrediction; // InPrediction for no vis recoil
	extern Utilities::�ڴ����::VMTManager VMTPlaySound; // Autoaccept shit
	extern Utilities::�ڴ����::VMTManager VMTRenderView;
};