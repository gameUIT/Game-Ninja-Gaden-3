#pragma once
#include "Enemy.h"
#include "DelayTime.h"


enum BOSS_STATE
{
	BOSS_STATE_STAND,
	BOSS_STATE_JUMP
};

enum BOSS_ACTION
{
	BOSS_ACTION_JUMPING,
	BOSS_ACTION_ONGROUND,
	BOSS_ACTION_JUMP
};

class Boss :
	public Enemy
{
	BOSS_STATE state;
	DelayTime standDelay;
public:
	void setCollisionType(COLLISION_TYPE collisionType) override;
	void setState(BOSS_STATE state);
	void onCollision(MovableRect* other, float collisionTime, int nx, int ny) override;
	void onIntersect(MovableRect* other) override;
	void onUpdate(float dt) override;
	Boss();
	~Boss();
};

