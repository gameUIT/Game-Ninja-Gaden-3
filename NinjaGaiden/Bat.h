#pragma once
#include "Enemy.h"


enum BAT_STATE
{
	BAT_STATE_INVISIBLE,
	BAT_STATE_VISIBLE,
};

class Bat :
	public Enemy
{
	BAT_STATE state;
public:
	void setState(BAT_STATE state);
	void onCollision(MovableRect* other, float collisionTime, int nx, int ny) override;
	void onIntersect(MovableRect* other) override;
	void onUpdate(float dt) override;
	void restoreLocation() override;
	Bat();
	~Bat();
};

