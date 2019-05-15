#pragma once
#include "Enemy.h"


enum BIRD_STATE
{
	BIRD_STATE_INVISIBLE,
	BIRD_STATE_VISIBLE,
};

class Bird :
	public Enemy
{
	BIRD_STATE state;
public:
	void setState(BIRD_STATE state);
	void onCollision(MovableRect* other, float collisionTime, int nx, int ny) override;
	void onIntersect(MovableRect* other) override;
	void onUpdate(float dt) override;
	void restoreLocation() override;
	Bird();
	~Bird();
};

