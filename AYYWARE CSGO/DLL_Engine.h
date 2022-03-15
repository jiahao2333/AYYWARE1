class IVEngineClient
{
public:

	void GetScreenSize(int& width, int& height)
	{
		typedef void(__thiscall* oGetScreenSize)(PVOID, int&, int&);
		return Call_��������ȡ��ַ����CALL< oGetScreenSize >(this, Offsets::VMT::Engine_GetScreenSize)(this, width, height);
	}
	bool ȡ�����Ϣ(int ent_num, player_info_t *pinfo)
	{
		typedef bool(__thiscall* oȡ�����Ϣ)(PVOID, int, player_info_t*);
		return Call_��������ȡ��ַ����CALL< oȡ�����Ϣ >(this, Offsets::VMT::Engine_ȡ�����Ϣ)(this, ent_num, pinfo);
	}
	int ȡ���˻�ַ()
	{
		typedef int(__thiscall* oLocal)(PVOID);
		return Call_��������ȡ��ַ����CALL< oLocal >(this, Offsets::VMT::Engine_GetLocalPlayer)(this);
	}

	float ȡ��Ϸʱ��()
	{
		typedef float(__thiscall* oTime)(PVOID);
		return Call_��������ȡ��ַ����CALL< oTime >(this, Offsets::VMT::Engine_Time)(this);
	}
	void ȡ��Ϸ��׼�Ƕ�(Vector& vAngles)
	{
		typedef void(__thiscall* oSetViewAngles)(PVOID, Vector&);
		return Call_��������ȡ��ַ����CALL< oSetViewAngles >(this, Offsets::VMT::Engine_ȡ��Ϸ��׼�Ƕ�)(this, vAngles);
	}
	void д��Ϸ��׼�Ƕ�(Vector& vAngles)
	{
		typedef void(__thiscall* ͨ����)(PVOID, Vector&);
		return Call_��������ȡ��ַ����CALL< ͨ���� >(this, Offsets::VMT::Engine_SetViewAngles)(this, vAngles);
	}
	int GetMaxClients()
	{
		typedef bool(__thiscall* oGetMaxClients)(PVOID);
		return Call_��������ȡ��ַ����CALL< oGetMaxClients >(this, Offsets::VMT::Engine_GetMaxClients)(this);
	}
	bool IsConnected()
	{
		typedef bool(__thiscall* oGetScreenSize)(PVOID);
		return Call_��������ȡ��ַ����CALL< oGetScreenSize >(this, Offsets::VMT::Engine_IsConnected)(this);
	}
	bool �Ƿ�����Ϸ()
	{
		typedef bool(__thiscall* ͨ����)(PVOID);
		return Call_��������ȡ��ַ����CALL< ͨ���� >(this, Offsets::VMT::Engine_IsInGame)(this);
	}
	const matrix3x4& ȡ���絽��Ļ����()
	{
		typedef const matrix3x4& (__thiscall* o����ת��Matrix)(PVOID);
		return Call_��������ȡ��ַ����CALL< o����ת��Matrix >(this, Offsets::VMT::Engine_����ת������)(this);
	}

	void ClientCmd_Unrestricted(char  const* cmd)
	{
		typedef void(__thiscall* oClientCmdUnres)(PVOID, const char*);
		return Call_��������ȡ��ַ����CALL<oClientCmdUnres>(this, Offsets::VMT::Engine_ClientCmd_Unrestricted)(this, cmd);
	}
};
