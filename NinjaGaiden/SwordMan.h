#pragma once
#include "Enemy.h"

enum SWORDMAN_STATE
{
	SWORDMAN_STATE_INVISIBLE,
	SWORDMAN_STATE_VISIBLE,
};

class SwordMan :
	public Enemy
{
	SWORDMAN_STATE state;
public:
	void setState(SWORDMAN_STATE state);
	void onCollision(MovableRect* other, float collisionTime, int nx, int ny) override;
	void onIntersect(MovableRect* other) override;
	void onUpdate(float dt) override;
	void restoreLocation() override;
	SwordMan();
	~SwordMan();
};

