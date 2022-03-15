/*
Syn's AyyWare Framework 2015
*/

#pragma once

#include "ģ�����.h"
#include "offsets.h"
#include "Vector.h"
#include "MiscClasses.h"
#include "Vector2D.h"


class IMaterial
{
public:
	const char* GetName()
	{
		typedef const char*(__thiscall* oGetName)(PVOID);
		return Call_��������ȡ��ַ����CALL< oGetName >(this, Offsets::VMT::Material_GetName)(this);
	}

	void SetMaterialVarFlag(MaterialVarFlags_t flag, bool value)
	{
		typedef void(__thiscall* oSetMatFlag)(PVOID, MaterialVarFlags_t, bool);
		return Call_��������ȡ��ַ����CALL< oSetMatFlag >(this, Offsets::VMT::Material_SetMaterialVarFlag)(this, flag, value);
	}

	bool GetMaterialVarFlag(MaterialVarFlags_t flag)
	{
		typedef bool(__thiscall* oGetMatFlag)(PVOID, MaterialVarFlags_t);
		return Call_��������ȡ��ַ����CALL< oGetMatFlag >(this, Offsets::VMT::Material_GetMaterialVarFlag)(this, flag);
	}

	void AlphaModulate(float a)
	{
		typedef void(__thiscall* oAlphaModulate)(PVOID, float);
		return Call_��������ȡ��ַ����CALL< oAlphaModulate >(this, Offsets::VMT::Material_AlphaModulate)(this, a);
	}

	void ColorModulate(float r, float g, float b)
	{
		typedef void(__thiscall* oColorModulate)(PVOID, float, float, float);
		return Call_��������ȡ��ַ����CALL< oColorModulate >(this, Offsets::VMT::Material_ColorModulate)(this, r, g, b);
	}

	void IncrementReferenceCount(void)
	{
		typedef void(__thiscall* oIncrementReferenceCount)(PVOID);
		return Call_��������ȡ��ַ����CALL< oIncrementReferenceCount >(this, Offsets::VMT::Material_IncrementReferenceCount)(this);
	}
};

class CMaterialSystem
{
public:
	IMaterial* FindMaterial(char const* pMaterialName, const char *pTextureGroupName, bool complain = true, const char *pComplainPrefix = NULL)
	{
		typedef IMaterial*(__thiscall* oFindMaterial)(PVOID, char const*, char const*, bool, char const*);
		return Call_��������ȡ��ַ����CALL< oFindMaterial >(this, Offsets::VMT::MaterialSystem_FindMaterial)(this, pMaterialName, pTextureGroupName, complain, pComplainPrefix);
	}

	IMaterial*	CreateMaterial(const char *pMaterialName, KeyValues *pVMTKeyValues)
	{
		typedef IMaterial* (__thiscall* oCreateMaterial)(PVOID, const char *, KeyValues*);
		return Call_��������ȡ��ַ����CALL<oCreateMaterial>(this, Offsets::VMT::MaterialSystem_CreateMaterial)(this, pMaterialName, pVMTKeyValues);
	}
};

class IVModelRender
{
public:
	void ForcedMaterialOverride(IMaterial *material, OverrideType_t type = OVERRIDE_NORMAL, int idk = NULL)
	{
		typedef void(__thiscall* Fn)(void*, IMaterial*, OverrideType_t, int);
		return Call_��������ȡ��ַ����CALL<Fn>(this, Offsets::VMT::ModelRender_ForcedMaterialOverride)(this, material, type, idk);
	}

};

class CModelInfo
{
public:
	int	GetModelIndex(const char *name)
	{
		typedef int (__thiscall* oGetModelName)(PVOID, const char *);
		return Call_��������ȡ��ַ����CALL< oGetModelName >(this, 2)(this, name);
	}
	const char *GetModelName(const model_t *mod)
	{
		typedef const char *(__thiscall* oGetModelName)(PVOID, const model_t*);
		return Call_��������ȡ��ַ����CALL< oGetModelName >(this, Offsets::VMT::ModelInfo_GetModelName)(this, mod);
	}

	studiohdr_t	*GetStudiomodel(const model_t *mod)
	{
		typedef studiohdr_t *(__stdcall* oGetStudiomodel)(const model_t*);
		return Call_��������ȡ��ַ����CALL< oGetStudiomodel >(this, Offsets::VMT::ModelInfo_GetStudiomodel)(mod);
	}
};

class CVRenderView
{
public:
	void SetBlend(float alpha)
	{
		typedef void(__thiscall* oDrawModelExecute)(PVOID, float);
		return Call_��������ȡ��ַ����CALL< oDrawModelExecute >(this, Offsets::VMT::RenderView_SetBlend)(this, alpha);
	}

	void SetColorModulation(float const* colors)
	{
		typedef void(__thiscall* oDrawModelExecute)(PVOID, float const*);
		return Call_��������ȡ��ַ����CALL< oDrawModelExecute >(this, Offsets::VMT::RenderView_SetColorModulation)(this, colors);
	}
};