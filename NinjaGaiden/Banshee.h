#pragma once
#include "Enemy.h"
#include"DelayTime.h"


enum BANSHEE_STATE
{
	BANSHEE_STATE_RUN,
	BANSHEE_STATE_FIRE
};

class Banshee :
	public Enemy
{
	BANSHEE_STATE state;
	int vDirection;
	DelayTime runDelay;
	DelayTime fireDelay;
public:
	void setState(BANSHEE_STATE state);
	void onCollision(MovableRect* other, float collisionTime, int nx, int ny) override;
	void onIntersect(MovableRect* other) override;
	void onUpdate(float dt) override;
	void restoreLocation() override;
	Banshee();
	~Banshee();
};

