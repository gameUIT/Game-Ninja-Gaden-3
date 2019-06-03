#pragma once
#include "Enemy.h"
#include "DelayTime.h"


enum BAAZOKA_STATE
{
	BAAZOKA_STATE_INVISIBLE,
	BAAZOKA_STATE_STATE_FIRE,
};

class Baazoka :
	public Enemy
{
	BAAZOKA_STATE state;
	DelayTime fireDelay;
	GameTime fireTime;
public:
	void setState(BAAZOKA_STATE state);
	void onCollision(MovableRect* other, float collisionTime, int nx, int ny) override;
	void onIntersect(MovableRect* other) override;
	void onUpdate(float dt) override;
	void restoreLocation() override;
	Baazoka();
	~Baazoka();
};

