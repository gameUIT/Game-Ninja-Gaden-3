#pragma once
#include "Enemy.h"


enum SHOOTER_STATE
{
	SHOOTER_STATE_INVISIBLE,
	SHOOTER_STATE_VISIBLE,
};

class Shooter :
	public Enemy
{
	SHOOTER_STATE state;
public:
	void setState(SHOOTER_STATE state);
	void onCollision(MovableRect* other, float collisionTime, int nx, int ny) override;
	void onIntersect(MovableRect* other) override;
	void onUpdate(float dt) override;
	void restoreLocation() override;
	Shooter();
	~Shooter();
};

