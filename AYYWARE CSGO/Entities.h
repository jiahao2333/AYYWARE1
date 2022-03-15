/*
Syn's AyyWare Framework 2015
*/

#pragma once

#include "模版代码.h"
#include "ClientRecvProps.h"
#include "offsets.h"
#include "Vector.h"

#define TEAM_CS_T 2
#define TEAM_CS_CT 3

#define BONE_USED_BY_HITBOX			0x00000100

#define ptr( x, x1, x2 ) *(x*)( (DWORD)x1 + (DWORD)x2 )

class IClientRenderable;
class IClientNetworkable;
class IClientUnknown;
class IClientThinkable;
class IClientEntity;
class CSWeaponInfo;

class CSWeaponInfo //vorher
{
public:
	char _0x0000[2048];
	__int32 m_IsFullAuto; //0x0800 
	char _0x0804[52];
	__int32 weapon_type; //0x0838 
	__int32 weapon_team; //0x083C 
	__int32 weapon_id; //0x0840 
	char _0x0844[4];
	float heat_ps; //0x0848 
	__int32 price; //0x084C 
	float m_flArmorRatio; //0x0850
	float player_speed; //0x0854 
	float player_speed_alt; //0x0858 
	__int32 crosshair_min_distance; //0x085C 
	__int32 crosshair_delta; //0x0860 
	float m_flPenetration; //0x0864 
	__int32 m_iDamage; //0x0868 
	float m_flRange; //0x086C 
	float m_flRangeModifier; //0x0870 
	__int32 bullets; //0x0874 
	float cycle_time; //0x0878 
	float cycle_time_alt; //0x087C 
	char _0x0880[416];
	float spread; //0x0A20 
	float spread_alt; //0x0A24 
};


enum class 对象ID
{
	CAI_BaseNPC,
	CAK47,
	CBaseAnimating,
	CBaseAnimatingOverlay,
	CBaseAttributableItem,
	CBaseButton,
	CBaseCombatCharacter,
	CBaseCombatWeapon,
	CBaseCSGrenade,
	CBaseCSGrenadeProjectile,
	CBaseDoor,
	CBaseEntity,
	CBaseFlex,
	CBaseGrenade,
	CBaseParticleEntity,
	CBasePlayer,
	CBasePropDoor,
	CBaseTeamObjectiveResource,
	CBaseTempEntity,
	CBaseToggle,
	CBaseTrigger,
	CBaseViewModel,
	CBaseVPhysicsTrigger,
	CBaseWeaponWorldModel,
	CBeam,
	CBeamSpotlight,
	CBoneFollower,
	CBRC4Target,
	CBreachCharge,
	CBreachChargeProjectile,
	CBreakableProp,
	CBreakableSurface,
	CBumpMine,
	CBumpMineProjectile,
	CC4,
	CCascadeLight,
	CChicken,
	CColorCorrection,
	CColorCorrectionVolume,
	CCSGameRulesProxy,
	CCSPlayer,
	CCSPlayerResource,
	CCSRagdoll,
	CCSTeam,
	CDangerZone,
	CDangerZoneController,
	CDEagle,
	CDecoyGrenade,
	CDecoyProjectile,
	CDrone,
	CDronegun,
	CDynamicLight,
	CDynamicProp,
	CEconEntity,
	CEconWearable,
	CEmbers,
	CEntityDissolve,
	CEntityFlame,
	CEntityFreezing,
	CEntityParticleTrail,
	CEnvAmbientLight,
	CEnvDetailController,
	CEnvDOFController,
	CEnvGasCanister,
	CEnvParticleScript,
	CEnvProjectedTexture,
	CEnvQuadraticBeam,
	CEnvScreenEffect,
	CEnvScreenOverlay,
	CEnvTonemapController,
	CEnvWind,
	CFEPlayerDecal,
	CFireCrackerBlast,
	CFireSmoke,
	CFireTrail,
	CFish,
	CFists,
	CFlashbang,
	CFogController,
	CFootstepControl,
	CFunc_Dust,
	CFunc_LOD,
	CFuncAreaPortalWindow,
	CFuncBrush,
	CFuncConveyor,
	CFuncLadder,
	CFuncMonitor,
	CFuncMoveLinear,
	CFuncOccluder,
	CFuncReflectiveGlass,
	CFuncRotating,
	CFuncSmokeVolume,
	CFuncTrackTrain,
	CGameRulesProxy,
	CGrassBurn,
	CHandleTest,
	CHEGrenade,
	CHostage,
	CHostageCarriableProp,
	CIncendiaryGrenade,
	CInferno,
	CInfoLadderDismount,
	CInfoMapRegion,
	CInfoOverlayAccessor,
	CItem_Healthshot,
	CItemCash,
	CItemDogtags,
	CKnife,
	CKnifeGG,
	CLightGlow,
	CMaterialModifyControl,
	CMelee,
	CMolotovGrenade,
	CMolotovProjectile,
	CMovieDisplay,
	CParadropChopper,
	CParticleFire,
	CParticlePerformanceMonitor,
	CParticleSystem,
	CPhysBox,
	CPhysBoxMultiplayer,
	CPhysicsProp,
	CPhysicsPropMultiplayer,
	CPhysMagnet,
	CPhysPropAmmoBox,
	CPhysPropLootCrate,
	CPhysPropRadarJammer,
	CPhysPropWeaponUpgrade,
	CPlantedC4,
	CPlasma,
	CPlayerPing,
	CPlayerResource,
	CPointCamera,
	CPointCommentaryNode,
	CPointWorldText,
	CPoseController,
	CPostProcessController,
	CPrecipitation,
	CPrecipitationBlocker,
	CPredictedViewModel,
	CProp_Hallucination,
	CPropCounter,
	CPropDoorRotating,
	CPropJeep,
	CPropVehicleDriveable,
	CRagdollManager,
	CRagdollProp,
	CRagdollPropAttached,
	CRopeKeyframe,
	CSCAR17,
	CSceneEntity,
	CSensorGrenade,
	CSensorGrenadeProjectile,
	CShadowControl,
	CSlideshowDisplay,
	CSmokeGrenade,
	CSmokeGrenadeProjectile,
	CSmokeStack,
	CSnowball,
	CSnowballPile,
	CSnowballProjectile,
	CSpatialEntity,
	CSpotlightEnd,
	CSprite,
	CSpriteOriented,
	CSpriteTrail,
	CStatueProp,
	CSteamJet,
	CSun,
	CSunlightShadowControl,
	CSurvivalSpawnChopper,
	CTablet,
	CTeam,
	CTeamplayRoundBasedRulesProxy,
	CTEArmorRicochet,
	CTEBaseBeam,
	CTEBeamEntPoint,
	CTEBeamEnts,
	CTEBeamFollow,
	CTEBeamLaser,
	CTEBeamPoints,
	CTEBeamRing,
	CTEBeamRingPoint,
	CTEBeamSpline,
	CTEBloodSprite,
	CTEBloodStream,
	CTEBreakModel,
	CTEBSPDecal,
	CTEBubbles,
	CTEBubbleTrail,
	CTEClientProjectile,
	CTEDecal,
	CTEDust,
	CTEDynamicLight,
	CTEEffectDispatch,
	CTEEnergySplash,
	CTEExplosion,
	CTEFireBullets,
	CTEFizz,
	CTEFootprintDecal,
	CTEFoundryHelpers,
	CTEGaussExplosion,
	CTEGlowSprite,
	CTEImpact,
	CTEKillPlayerAttachments,
	CTELargeFunnel,
	CTEMetalSparks,
	CTEMuzzleFlash,
	CTEParticleSystem,
	CTEPhysicsProp,
	CTEPlantBomb,
	CTEPlayerAnimEvent,
	CTEPlayerDecal,
	CTEProjectedDecal,
	CTERadioIcon,
	CTEShatterSurface,
	CTEShowLine,
	CTesla,
	CTESmoke,
	CTESparks,
	CTESprite,
	CTESpriteSpray,
	CTest_ProxyToggle_Networkable,
	CTestTraceline,
	CTEWorldDecal,
	CTriggerPlayerMovement,
	CTriggerSoundOperator,
	CVGuiScreen,
	CVoteController,
	CWaterBullet,
	CWaterLODControl,
	CWeaponAug,
	CWeaponAWP,
	CWeaponBaseItem,
	CWeaponBizon,
	CWeaponCSBase,
	CWeaponCSBaseGun,
	CWeaponCycler,
	CWeaponElite,
	CWeaponFamas,
	CWeaponFiveSeven,
	CWeaponG3SG1,
	CWeaponGalil,
	CWeaponGalilAR,
	CWeaponGlock,
	CWeaponHKP2000,
	CWeaponM249,
	CWeaponM3,
	CWeaponM4A1,
	CWeaponMAC10,
	CWeaponMag7,
	CWeaponMP5Navy,
	CWeaponMP7,
	CWeaponMP9,
	CWeaponNegev,
	CWeaponNOVA,
	CWeaponP228,
	CWeaponP250,
	CWeaponP90,
	CWeaponSawedoff,
	CWeaponSCAR20,
	CWeaponScout,
	CWeaponSG550,
	CWeaponSG552,
	CWeaponSG556,
	CWeaponShield,
	CWeaponSSG08,
	CWeaponTaser,
	CWeaponTec9,
	CWeaponTMP,
	CWeaponUMP45,
	CWeaponUSP,
	CWeaponXM1014,
	CWorld,
	CWorldVguiText,
	DustTrail,
	MovieExplosion,
	ParticleSmokeGrenade,
	RocketTrail,
	SmokeTrail,
	SporeExplosion,
	SporeTrail,
};




enum class 人物部位
{
	Head = 0,//1
	Neck,//2
//	NeckLower,//3
Pelvis,//4
Stomach,//5

LowerChest,//6
Chest,//7
UpperChest,//8

RightThigh,//9
LeftThigh,//10

RightShin,//11
LeftShin,//12


RightFoot,//13
LeftFoot,//14

RightHand,//15
LeftHand,//16


RightUpperArm,//17
RightLowerArm,//18
LeftUpperArm,//19
LeftLowerArm,//20
Max,
};

// Weapon IDs
enum ItemDefinitionIndex : int
{
	/**
	WEAPON_DEAGLE = 1,
	WEAPON_ELITE = 2,
	WEAPON_FIVESEVEN = 3,
	WEAPON_GLOCK = 4,
	WEAPON_AK47 = 7,
	WEAPON_AUG = 8,
	WEAPON_AWP = 9,
	WEAPON_FAMAS = 10,
	WEAPON_G3SG1 = 11,
	WEAPON_GALILAR = 13,
	WEAPON_M249 = 14,
	WEAPON_M4A1 = 16,
	WEAPON_MAC10 = 17,
	WEAPON_P90 = 19,
	WEAPON_UMP45 = 24,
	WEAPON_XM1014 = 25,
	WEAPON_BIZON = 26,
	WEAPON_MAG7 = 27,
	WEAPON_NEGEV = 28,
	WEAPON_SAWEDOFF = 29,
	WEAPON_TEC9 = 30,
	WEAPON_TASER = 31,
	WEAPON_HKP2000 = 32,
	WEAPON_MP7 = 33,
	WEAPON_MP9 = 34,
	WEAPON_NOVA = 35,
	WEAPON_P250 = 36,
	WEAPON_SCAR20 = 38,
	WEAPON_SG556 = 39,
	WEAPON_SSG08 = 40,
	WEAPON_KNIFE_CT = 42,
	WEAPON_FLASHBANG = 43,
	WEAPON_HEGRENADE = 44,
	WEAPON_SMOKEGRENADE = 45,
	WEAPON_MOLOTOV = 46,
	WEAPON_DECOY = 47,
	WEAPON_INCGRENADE = 48,
	WEAPON_C4 = 49,
	WEAPON_KNIFE_T = 59,
	WEAPON_M4A1_SILENCER = 60,
	WEAPON_USP_SILENCER = 61,
	WEAPON_CZ75A = 63,
	WEAPON_REVOLVER = 64,
	WEAPON_KNIFE_BAYONET = 500,
	WEAPON_KNIFE_FLIP = 505,
	WEAPON_KNIFE_GUT = 506,
	WEAPON_KNIFE_KARAMBIT = 507,
	WEAPON_KNIFE_M9_BAYONET = 508,
	WEAPON_KNIFE_TACTICAL = 509,
	WEAPON_KNIFE_FALCHION = 512,
	WEAPON_KNIFE_BOWIE = 514,
	WEAPON_KNIFE_BUTTERFLY = 515,
	WEAPON_KNIFE_PUSH = 516

	*/

	WEAPON_NONE = 0,
	WEAPON_DEAGLE,
	WEAPON_ELITE,
	WEAPON_FIVESEVEN,
	WEAPON_GLOCK,
	WEAPON_AK47 = 7,
	WEAPON_AUG,
	WEAPON_AWP,
	WEAPON_FAMAS,
	WEAPON_G3SG1,
	WEAPON_GALILAR = 13,
	WEAPON_M249,
	WEAPON_M4A1 = 16,
	WEAPON_MAC10,
	WEAPON_P90 = 19,
	WEAPON_MP5SD = 23,
	WEAPON_UMP45,
	WEAPON_XM1014,
	WEAPON_BIZON,
	WEAPON_MAG7,
	WEAPON_NEGEV,
	WEAPON_SAWEDOFF,
	WEAPON_TEC9,
	WEAPON_TASER,
	WEAPON_HKP2000,
	WEAPON_MP7,
	WEAPON_MP9,
	WEAPON_NOVA,
	WEAPON_P250,
	WEAPON_SCAR20 = 38,
	WEAPON_SG556,
	WEAPON_SSG08,
	WEAPON_KNIFEGG,
	WEAPON_KNIFE,
	WEAPON_FLASHBANG,
	WEAPON_HEGRENADE,
	WEAPON_SMOKEGRENADE,
	WEAPON_MOLOTOV,
	WEAPON_DECOY,
	WEAPON_INCGRENADE,
	WEAPON_C4,
	WEAPON_HEALTHSHOT = 57,
	WEAPON_KNIFE_T = 59,
	WEAPON_M4A1_SILENCER,
	WEAPON_USP_SILENCER,
	WEAPON_CZ75A = 63,
	WEAPON_REVOLVER,
	WEAPON_TAGRENADE = 68,
	WEAPON_FISTS,
	WEAPON_BREACHCHARGE,
	WEAPON_TABLET = 72,
	WEAPON_MELEE = 74,
	WEAPON_AXE,
	WEAPON_HAMMER,
	WEAPON_SPANNER = 78,
	WEAPON_KNIFE_GHOST = 80,
	WEAPON_FIREBOMB,
	WEAPON_DIVERSION,
	WEAPON_FRAG_GRENADE,
	WEAPON_BAYONET = 500,
	WEAPON_KNIFE_FLIP = 505,
	WEAPON_KNIFE_GUT,
	WEAPON_KNIFE_KARAMBIT,
	WEAPON_KNIFE_M9_BAYONET,
	WEAPON_KNIFE_TACTICAL,
	WEAPON_KNIFE_FALCHION = 512,
	WEAPON_KNIFE_SURVIVAL_BOWIE = 514,
	WEAPON_KNIFE_BUTTERFLY,
	WEAPON_KNIFE_PUSH,
	WEAPON_KNIFE_URSUS = 519,
	WEAPON_KNIFE_GYPSY_JACKKNIFE,
	WEAPON_KNIFE_STILETTO = 522,
	WEAPON_KNIFE_WIDOWMAKER
};

class ScriptCreatedItem
{
public:
	声明读内存子程序2(int*, ItemDefinitionIndex, 0xE67AB3B8); //m_iItemDefinitionIndex
	声明读内存子程序2(int*, AccountID, 0x24abbea8); //m_iAccountID
	声明读内存子程序2(int*, ItemIDHigh, 0x714778A); //m_iItemIDHigh
	声明读内存子程序2(int*, ItemIDLow, 0x3A3DFC74); //m_iItemIDLow
	声明读内存子程序2(int*, EntityQuality, 0x110be6fe); //m_iEntityQuality
};

class AttributeContainer
{
public:
	声明读内存子程序2(ScriptCreatedItem*, m_Item, 0x7E029CE5);
};


class CBaseCombatWeapon
{
public:
	声明读内存子程序(float, GetNextPrimaryAttack, 0xDB7B106E); //m_flNextPrimaryAttack
	声明读内存子程序(int, GetAmmoInClip, 0x97B6F70C); //m_iClip1
	声明读内存子程序(HANDLE, GetOwnerHandle, 0xC32DF98D); //m_hOwner
	声明读内存子程序(Vector, GetOrigin, 0x1231CE10); //m_vecOrigin
	声明读内存子程序2(int*, FallbackPaintKit, 0xADE4C870); // m_nFallbackPaintKit
	声明读内存子程序2(int*, FallbackSeed, 0xC2D0683D); // m_nFallbackSeed
	声明读内存子程序2(float*, FallbackWear, 0xA263576C); //m_flFallbackWear
	声明读内存子程序2(int*, FallbackStatTrak, 0x1ED78768); //m_nFallbackStatTrak
	声明读内存子程序2(int*, OwnerXuidLow, 0xAD8D897F);
	声明读内存子程序2(int*, OwnerXuidHigh, 0x90511E77);
	声明读内存子程序2(int*, ViewModelIndex, 0x7F7C89C1);
	声明读内存子程序2(int*, ModelIndex, 0x27016F83);
	声明读内存子程序2(int*, WorldModelIndex, 0x4D8AD9F3);
	声明读内存子程序2(char*, szCustomName, 0x0);

	声明读内存子程序2(AttributeContainer*, m_AttributeManager, 0xCFFCE089);

	声明读内存子程序(int, GetZoomLevel, 0x26553F1A);

	float GetInaccuracy()
	{
		typedef float(__thiscall * oInaccuracy)(PVOID);
		return Call_从数组中取地址调用CALL< oInaccuracy >(this, 476)(this);
	}

	float GetInnacc()
	{
		typedef float(__thiscall * OrigFn)(void*);
		return Call_从数组中取地址调用CALL<OrigFn>(this, 484)(this);
	}

	void UpdateAccPenalty()
	{
		typedef void(__thiscall * OrigFn)(void*);
		return Call_从数组中取地址调用CALL<OrigFn>(this, 477)(this);
	}

	bool IsScoped(int x = 0)
	{
		return GetZoomLevel() > 0;
	}
	/*
	CSWeaponInfo* GetCSWpnData()
	{
		static DWORD GetCSWpnDataAddr = Utilities::内存操作::查找内存_字节集("client_panorama.dll", (PBYTE)"\x55\x8B\xEC\x81\xEC\x00\x00\x00\x00\xB8\x00\x00\x00\x00\x57", "xxxxx????x????x");
		if (GetCSWpnDataAddr)
		{
			CSWeaponInfo* retData;
			__asm
			{
				mov ecx, this
				call GetCSWpnDataAddr
				mov retData, eax
			}
			return retData;
		}
		else
		{
			return nullptr;
		}
	}
	*/

	CSWeaponInfo* GetCSWpnData()
	{
		if (!this) return nullptr;

		typedef CSWeaponInfo* (__thiscall * OriginalFn)(void*);
		return  Call_从数组中取地址调用CALL<OriginalFn>(this, 454)(this);
	}
};

class CCSBomb
{
public:
	声明读内存子程序(HANDLE, GetOwnerHandle, 0xC32DF98D); //m_hOwner 0x29BC
	声明读内存子程序(float, GetC4BlowTime, 0xB5E0CA1C); //m_flC4Blow 0x297C
	声明读内存子程序(float, GetC4DefuseCountDown, 0xB959B4A6); //m_flDefuseCountDown 0x2994
};

class CLocalPlayerExclusive
{
public:
	声明读内存子程序(Vector, GetViewPunchAngle, 0x68F014C0);//m_viewPunchAngle
	//声明读内存子程序(Vector, GetAimPunchAngle, 0xBF25C290);//m_aimPunchAngle
	声明读内存子程序(Vector, GetAimPunchAngleVel, 0x8425E045);//m_aimPunchAngleVel
	模版_读内存(Vector, GetAimPunchAngle, 0x70)
		模版_读内存(Vector, 取动作扩散数据, -0x2E9C)
};

class CollisionProperty
{
public:
	声明读内存子程序(Vector, GetMins, 0xF6F78BAB);//m_vecMins
	声明读内存子程序(Vector, GetMaxs, 0xE47C6FC4);//m_vecMaxs
	声明读内存子程序(unsigned char, GetSolidType, 0xB86722A1);//m_nSolidType
	声明读内存子程序(unsigned short, GetSolidFlags, 0x63BB24C1);//m_usSolidFlags
	声明读内存子程序(int, GetSurroundsType, 0xB677A0BB); //m_nSurroundType

	bool IsSolid()
	{
		return (GetSolidType() != SOLID_NONE) && ((GetSolidFlags() & FSOLID_NOT_SOLID) == 0);
	}
};

class IClientRenderable
{
public:
	//virtual void*					GetIClientUnknown() = 0;
	virtual Vector const& GetRenderOrigin(void) = 0;
	virtual Vector const& GetRenderAngles(void) = 0;
	virtual bool					ShouldDraw(void) = 0;
	virtual bool					IsTransparent(void) = 0;
	virtual bool					UsesPowerOfTwoFrameBufferTexture() = 0;
	virtual bool					UsesFullFrameBufferTexture() = 0;
	virtual void					GetShadowHandle() const = 0;
	virtual void* RenderHandle() = 0;
	virtual const model_t* GetModel() const = 0;
	virtual int						DrawModel(int flags) = 0;
	virtual int						GetBody() = 0;
	virtual void					ComputeFxBlend() = 0;

	bool SetupBones(matrix3x4* pBoneToWorldOut, int nMaxBones, int boneMask, float currentTime)
	{
		typedef bool(__thiscall * oSetupBones)(PVOID, matrix3x4*, int, int, float);
		return Call_从数组中取地址调用CALL< oSetupBones>(this, 13)(this, pBoneToWorldOut, nMaxBones, boneMask, currentTime);
	}
};

class IClientNetworkable
{
public:
	virtual IClientUnknown* GetIClientUnknown() = 0;
	virtual void			Release() = 0;
	virtual ClientClass* GetClientClass() = 0;// FOR NETVARS FIND YOURSELF ClientClass* stuffs
	virtual void			NotifyShouldTransmit( /* ShouldTransmitState_t state*/) = 0;
	virtual void			OnPreDataChanged( /*DataUpdateType_t updateType*/) = 0;
	virtual void			OnDataChanged( /*DataUpdateType_t updateType*/) = 0;
	virtual void			PreDataUpdate( /*DataUpdateType_t updateType*/) = 0;
	virtual void			PostDataUpdate( /*DataUpdateType_t updateType*/) = 0;
	virtual void			unknown();
	virtual bool			IsDormant(void) = 0;
	virtual int				GetIndex(void) const = 0;
	virtual void			ReceiveMessage(int classID /*, bf_read &msg*/) = 0;
	virtual void* GetDataTableBasePtr() = 0;
	virtual void			SetDestroyedOnRecreateEntities(void) = 0;
};

class IClientUnknown
{
public:
	virtual void* GetCollideable() = 0;
	virtual IClientNetworkable* GetClientNetworkable() = 0;
	virtual IClientRenderable* GetClientRenderable() = 0;
	virtual IClientEntity* GetIClientEntity() = 0;
	virtual IClientEntity* GetBaseEntity() = 0;
	virtual IClientThinkable* GetClientThinkable() = 0;
};

class IClientThinkable
{
public:
	virtual IClientUnknown* GetIClientUnknown() = 0;
	virtual void				ClientThink() = 0;
	virtual void* GetThinkHandle() = 0;
	virtual void				SetThinkHandle(void* hThink) = 0;
	virtual void				Release() = 0;
};

class __declspec (novtable)IClientEntity : public IClientUnknown, public IClientRenderable, public IClientNetworkable, public IClientThinkable
{
public:
public:
	virtual void			Release(void) = 0;
	virtual void			blahblahpad(void) = 0;
	virtual Vector& GetAbsOrigin(void) const = 0;//in broken place use GetOrigin Below
	virtual const Vector& GetAbsAngles(void) const = 0;

	声明读内存子程序2(CLocalPlayerExclusive*, localPlayerExclusive, 0x7177BC3E);// m_Local
	声明读内存子程序2(CollisionProperty*, collisionProperty, 0xE477CBD0);//m_Collision
	声明读内存子程序(float, GetLowerBodyYaw, 0xE6996CCF); //m_flLowerBodyYawTarget
	声明读内存子程序(int, GetFlags, 0xE456D580); //m_fFlags
	声明读内存子程序(float, GetTargetYaw, 0xE6996CCF)
		声明读内存子程序(Vector, GetOrigin, 0x1231CE10); //m_vecOrigin 0x0134
	声明读内存子程序(Vector, GetRotation, 0x6BEA197A); //m_angRotation
	声明读内存子程序(int, GetTeamNum, 0xC08B6C6E); //m_iTeamNum
	声明读内存子程序(int, GetMaxHealth, 0xC52E1C28); //m_iMaxHealth
	声明读内存子程序(int, GetHealth, 0xA93054E3); //m_iHealth
	声明读内存子程序(float, GetFlashDuration, 0x4B5938D5); //m_flFlashDuration
	声明读内存子程序(float, GetFlashAlpha, 0xFE79FB98); //m_flFlashMaxAlpha
	声明读内存子程序(unsigned char, GetLifeState, 0xD795CCFC); //m_lifeState
	声明读内存子程序(HANDLE, GetActiveWeaponHandle, 0xB4FECDA3); //m_hActiveWeapon
	声明读内存子程序(int, GetTickBase, 0xD472B079); //m_nTickBase
	声明读内存子程序(Vector, GetViewOffset, 0xA9F74931); //m_vecViewOffset[0]
	声明读内存子程序(Vector, GetViewPunch, 0x68F014C0);
	声明读内存子程序(Vector, GetPunch, 0xBF25C290);
	声明读内存子程序(Vector, GetVelocity, 0x40C1CA24); //m_vecVelocity[0]
	声明读内存子程序(bool, HasGunGameImmunity, 0x6AD6FA0D); //m_bGunGameImmunity
	声明读内存子程序(bool, IsDefusing, 0xA2C14106); //m_bIsDefusing
	声明读内存子程序(int, ArmorValue, 0x3898634); //m_ArmorValue
	声明读内存子程序(bool, HasHelmet, 0x7B97F18A); //m_bHasHelmet
	声明读内存子程序(int, GetObserverMode, 0x2441D093); // m_iObserverMode
	声明读内存子程序(HANDLE, GetObserverTargetHandle, 0x8660FD83); //m_hObserverTarget
	声明读内存子程序(int, GetShotsFired, 0x3F2F6C66); //m_nTickBase
	声明读内存子程序(float, GetSimulationTime, 0xC4560E44); //m_flSimulationTime
	声明读内存子程序(float, GetAnimTime, 0xD27E8416);
	声明读内存子程序(bool, IsScoped, 0x61B9C22C); //m_bIsScoped
	声明读内存子程序2(char*, GetLastPlaceName, 0x9911c2d7);

	bool 是否可用()
	{
		return (GetLifeState() == LIFE_ALIVE && GetHealth() > 0);
	}
	Vector 取骨骼顶点(int i)
	{
		matrix3x4 boneMatrix[128];
		if (this->SetupBones(boneMatrix, 128, BONE_USED_BY_HITBOX, GetTickCount64()))
		{
			return Vector(boneMatrix[i][0][3], boneMatrix[i][1][3], boneMatrix[i][2][3]);
		}
		return Vector(0, 0, 0);
	}

	Vector 取头部顶点()
	{
		return this->取骨骼顶点(8); //Neu war 6
	}


	bool 是否为玩家()
	{
		return GetClientClass()->m_ClassID == (int)对象ID::CCSPlayer;
	}

};