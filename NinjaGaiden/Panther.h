#pragma once
#include "Enemy.h"


enum PANTHER_STATE
{
	PANTHER_STATE_INVISIBLE,
	PANTHER_STATE_VISIBLE,
};

class Panther :
	public Enemy
{
	PANTHER_STATE state;
public:
	void setState(PANTHER_STATE state);
	void onCollision(MovableRect* other, float collisionTime, int nx, int ny) override;
	void onIntersect(MovableRect* other) override;
	void onUpdate(float dt) override;
	void restoreLocation() override;
	Panther();
	~Panther();
};

