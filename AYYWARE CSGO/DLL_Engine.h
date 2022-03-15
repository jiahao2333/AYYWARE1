class IVEngineClient
{
public:

	void GetScreenSize(int& width, int& height)
	{
		typedef void(__thiscall* oGetScreenSize)(PVOID, int&, int&);
		return Call_从数组中取地址调用CALL< oGetScreenSize >(this, Offsets::VMT::Engine_GetScreenSize)(this, width, height);
	}
	bool 取玩家信息(int ent_num, player_info_t *pinfo)
	{
		typedef bool(__thiscall* o取玩家信息)(PVOID, int, player_info_t*);
		return Call_从数组中取地址调用CALL< o取玩家信息 >(this, Offsets::VMT::Engine_取玩家信息)(this, ent_num, pinfo);
	}
	int 取本人基址()
	{
		typedef int(__thiscall* oLocal)(PVOID);
		return Call_从数组中取地址调用CALL< oLocal >(this, Offsets::VMT::Engine_GetLocalPlayer)(this);
	}

	float 取游戏时间()
	{
		typedef float(__thiscall* oTime)(PVOID);
		return Call_从数组中取地址调用CALL< oTime >(this, Offsets::VMT::Engine_Time)(this);
	}
	void 取游戏瞄准角度(Vector& vAngles)
	{
		typedef void(__thiscall* oSetViewAngles)(PVOID, Vector&);
		return Call_从数组中取地址调用CALL< oSetViewAngles >(this, Offsets::VMT::Engine_取游戏瞄准角度)(this, vAngles);
	}
	void 写游戏瞄准角度(Vector& vAngles)
	{
		typedef void(__thiscall* 通用型)(PVOID, Vector&);
		return Call_从数组中取地址调用CALL< 通用型 >(this, Offsets::VMT::Engine_SetViewAngles)(this, vAngles);
	}
	int GetMaxClients()
	{
		typedef bool(__thiscall* oGetMaxClients)(PVOID);
		return Call_从数组中取地址调用CALL< oGetMaxClients >(this, Offsets::VMT::Engine_GetMaxClients)(this);
	}
	bool IsConnected()
	{
		typedef bool(__thiscall* oGetScreenSize)(PVOID);
		return Call_从数组中取地址调用CALL< oGetScreenSize >(this, Offsets::VMT::Engine_IsConnected)(this);
	}
	bool 是否在游戏()
	{
		typedef bool(__thiscall* 通用型)(PVOID);
		return Call_从数组中取地址调用CALL< 通用型 >(this, Offsets::VMT::Engine_IsInGame)(this);
	}
	const matrix3x4& 取世界到屏幕矩阵()
	{
		typedef const matrix3x4& (__thiscall* o矩阵转换Matrix)(PVOID);
		return Call_从数组中取地址调用CALL< o矩阵转换Matrix >(this, Offsets::VMT::Engine_矩阵转换数据)(this);
	}

	void ClientCmd_Unrestricted(char  const* cmd)
	{
		typedef void(__thiscall* oClientCmdUnres)(PVOID, const char*);
		return Call_从数组中取地址调用CALL<oClientCmdUnres>(this, Offsets::VMT::Engine_ClientCmd_Unrestricted)(this, cmd);
	}
};
