/*
Syn's AyyWare Framework
*/

#pragma once
#include "CommonIncludes.h"

namespace Utilities
{
	

	namespace �ڴ����
	{
		DWORD ��ȡģ���ַ(std::string moduleName);

		DWORD FindPattern(std::string moduleName, BYTE* Mask, char* szMask);

		DWORD �����ڴ�_�ֽڼ�(std::string moduleName, BYTE* Mask, char* szMask);
		DWORD �����ڴ�_�ı���(std::string moduleName, char* string);
		DWORD �����ڴ�_�ı���W(std::string moduleName, std::string pattern);
		////Neu/////
		template <typename T>
		T* CaptureInterface(std::string strModule, std::string strInterface)
		{
			typedef T* (*CreateInterfaceFn)(const char* szName, int iReturn);
			CreateInterfaceFn CreateInterface = (CreateInterfaceFn)GetProcAddress(GetModuleHandleA(strModule.c_str()), "CreateInterface");

			return CreateInterface(strInterface.c_str(), 0);
		}
		////Neu ENDE/////
		class VMTManager
		{
		private:
			DWORD	*CustomTable;
			bool	initComplete;
			DWORD	*OriginalTable;
			DWORD	*Instance;

			int		MethodCount(DWORD* InstancePointer);
			
		public:
			bool	Initialise(DWORD* InstancePointer); // Pass a &class

			DWORD	HookMethod(DWORD NewFunction, int Index);
			void	UnhookMethod(int Index);

			void	RestoreOriginal();
			void	RestoreCustom();

			template<typename T>
			T GetMethod(size_t nIndex)
			{
				return (T)OriginalTable[nIndex];
			}

			DWORD	GetOriginalFunction(int Index);
		};
	};
};

