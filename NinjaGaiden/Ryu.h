#pragma once
#include"PhysicsObject.h"
#include"SpriteManager.h"
#include"KEY.h"
#include"DelayTime.h"
#include"Stair.h"

enum RYU_ANIMATION
{
	RYU_ANIMATION_STAND,
	RYU_ANIMATION_RUN,
	RYU_ANIMATION_SIT,
	RYU_ANIMATION_ATTACK_SIT_RIGHT,
	RYU_ANIMATION_ATTACK_SIT_LEFT,
	RYU_ANIMATION_ATTACK_STAND_RIGHT,
	RYU_ANIMATION_ATTACK_STAND_LEFT,
	RYU_ANIMATION_JUMP,
	RYU_ANIMATION_ATTACK_JUMP,
	RYU_ANIMATION_CLIMBING,
	RYU_ANIMATION_ATTACK_RANGED_RIGHT,
	RYU_ANIMATION_ATTACK_RANGED_LEFT,
	RYU_ANIMATION_HURT,
};

enum RYU_STATE
{
	RYU_STATE_NORMAL,
	RYU_STATE_RUN,
	RYU_STATE_SIT,
	RYU_STATE_JUMP,
	RYU_STATE_CLIMBING,
	RYU_STATE_ATTACK,
	RYU_STATE_HURT,
	RYU_STATE_STAIR,
};

class Ryu :
	public PhysicsObject
{
	static Ryu* instance;

	RYU_STATE state;

	bool canSitDown;
	bool isSitting;
	DelayTime invisibleDelay;
	GameTime invisibleTime;
	bool isHit;


public:
	Stair* stair;
	bool isDead;

	GameTime blinkTime;
	DelayTime blinkDelay;

	static Ryu* getInstance();
	void onUpdate(float dt) override;
	void onCollision(MovableRect* other, float collisionTime, int nx, int ny) override;
	void onIntersect(MovableRect* other) override;

	void setCanSitDown(bool canSitDown);
	bool getCanSitDown();

	void setIsSitting(bool isSitting);

	void createNewSword();

	RYU_STATE getState();
	void setState(RYU_STATE state);

	Ryu();
	~Ryu();
};

