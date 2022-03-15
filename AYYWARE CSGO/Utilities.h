/*
Syn's AyyWare Framework
*/

#pragma once
#include "CommonIncludes.h"

namespace Utilities
{
	

	namespace 内存操作
	{
		DWORD 获取模块地址(std::string moduleName);

		DWORD FindPattern(std::string moduleName, BYTE* Mask, char* szMask);

		DWORD 查找内存_字节集(std::string moduleName, BYTE* Mask, char* szMask);
		DWORD 查找内存_文本型(std::string moduleName, char* string);
		DWORD 查找内存_文本型W(std::string moduleName, std::string pattern);
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

