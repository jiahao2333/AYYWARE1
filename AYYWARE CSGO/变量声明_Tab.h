
#include "Hacks.h"

// All misc visuals (Crosshairs etc) go in this class

class ����_���� : public CHack
{
public:
	void Init();
	void Draw();
	void Move(CUserCmd *pCmd, bool &bSendPacket);
private:
	void ����׼��();
	void ���Ƶ���׼��();
	void NameSteal();
};

class ����_�Զ���׼ : public CHack
{
public:
	void Init();
	void Draw();
	void Move(CUserCmd *pCmd, bool &bSendPacket);
private:
	// Targetting
	int ȡ������_׼�ľ���();
	int ȡ������_����();
	int ȡ������_Ѫ��();
	bool �ж�Ŀ���Ƿ����Ҫ��(IClientEntity* pEntity);
	float ȡ�ǶȲ�(Vector ViewOffSet, Vector View, IClientEntity* pEntity, int HitBox);
	int ȡ��׼��λ(IClientEntity* pEntity);
	bool ��׼Ŀ��(IClientEntity* pLocal, Vector point);
	bool �Զ���ǹ();
	// Functionality
	void �ӳ���_�Զ���׼();
	//void �Զ���ǹ(CUserCmd *pCmd, bool &bSendpacket);


	// AimStep
	bool �Ƿ��ܿ�ǹ;
	Vector LastAimstepAngle;
	Vector LastAngle;

	// Aimbot
	bool ��������;
	int ����ID;
	int HitBox;
	Vector AimPoint;
};

class ����_͸�� : public CHack
{
public:
	void Init();
	void Draw();
	void Move(CUserCmd *pCmd, bool &bSendPacket);
private:

	// Other shit
	IClientEntity *BombCarrier;

	struct ESPBox
	{
		int x, y, w, h;
	};
	struct ESPBox3D
	{
		int x1,y1,x2,y2,x3,y3,x4,y4,x5,y5,x6,y6,x7,y7,x8,y8;
	};
	// Draw a player
	void �������(IClientEntity* pEntity, player_info_t pinfo);

	// Get player info
	Color ȡ��Ӫ��ɫ(IClientEntity* pEntity);
	bool ȡ����(IClientEntity* pEntity, ESPBox &result);
	bool ȡ3D����(IClientEntity* pEntity, ESPBox3D &result);
	// Draw shit about player
	void ��ʾ�۲���();
	//void GrenadePrediction();

	void ���Ʒ���(ESPBox size, Color color); //NEU
	void ��������(const char* pinfo, ESPBox size, int em);
	void ����Ѫ��(IClientEntity* pEntity, ESPBox size);
	void ������Ϣ(IClientEntity* pEntity, ESPBox size);
	void ����ͷ��(IClientEntity* pEntity);
	void ���ƹ���(IClientEntity* pEntity);
	void ����Ұ��(IClientEntity* pEntity, ClientClass* cClass);
	void ��������(IClientEntity* pEntity, ClientClass* cClass);
	void ����δ֪(IClientEntity* pEntity, ClientClass* cClass);
	//void DrawSkeletonRainbow(IClientEntity* pEntity); //NEU

	//void DrawChicken(IClientEntity* pEntity, ClientClass* cClass);
	void ���Ƶ���(IClientEntity* pEntity, ClientClass* cClass);
	void ���Ʒ��õ�ը��(IClientEntity* pEntity, ClientClass* cClass);
	void ����ը��(IClientEntity* pEntity, ClientClass* cClass);
};
