
#include "Hacks.h"

// All misc visuals (Crosshairs etc) go in this class

class 类型_杂项 : public CHack
{
public:
	void Init();
	void Draw();
	void Move(CUserCmd *pCmd, bool &bSendPacket);
private:
	void 绘制准心();
	void 绘制弹道准心();
	void NameSteal();
};

class 类型_自动瞄准 : public CHack
{
public:
	void Init();
	void Draw();
	void Move(CUserCmd *pCmd, bool &bSendPacket);
private:
	// Targetting
	int 取最近玩家_准心距离();
	int 取最近玩家_距离();
	int 取最近玩家_血量();
	bool 判断目标是否符合要求(IClientEntity* pEntity);
	float 取角度差(Vector ViewOffSet, Vector View, IClientEntity* pEntity, int HitBox);
	int 取瞄准部位(IClientEntity* pEntity);
	bool 瞄准目标(IClientEntity* pLocal, Vector point);
	bool 自动开枪();
	// Functionality
	void 子程序_自动瞄准();
	//void 自动开枪(CUserCmd *pCmd, bool &bSendpacket);


	// AimStep
	bool 是否能开枪;
	Vector LastAimstepAngle;
	Vector LastAngle;

	// Aimbot
	bool 自瞄锁定;
	int 对象ID;
	int HitBox;
	Vector AimPoint;
};

class 类型_透视 : public CHack
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
	void 绘制玩家(IClientEntity* pEntity, player_info_t pinfo);

	// Get player info
	Color 取阵营颜色(IClientEntity* pEntity);
	bool 取方框(IClientEntity* pEntity, ESPBox &result);
	bool 取3D方框(IClientEntity* pEntity, ESPBox3D &result);
	// Draw shit about player
	void 显示观察者();
	//void GrenadePrediction();

	void 绘制方框(ESPBox size, Color color); //NEU
	void 绘制名字(const char* pinfo, ESPBox size, int em);
	void 绘制血条(IClientEntity* pEntity, ESPBox size);
	void 绘制信息(IClientEntity* pEntity, ESPBox size);
	void 绘制头部(IClientEntity* pEntity);
	void 绘制骨骼(IClientEntity* pEntity);
	void 绘制野鸡(IClientEntity* pEntity, ClientClass* cClass);
	void 绘制人质(IClientEntity* pEntity, ClientClass* cClass);
	void 绘制未知(IClientEntity* pEntity, ClientClass* cClass);
	//void DrawSkeletonRainbow(IClientEntity* pEntity); //NEU

	//void DrawChicken(IClientEntity* pEntity, ClientClass* cClass);
	void 绘制掉落(IClientEntity* pEntity, ClientClass* cClass);
	void 绘制放置的炸弹(IClientEntity* pEntity, ClientClass* cClass);
	void 绘制炸弹(IClientEntity* pEntity, ClientClass* cClass);
};
