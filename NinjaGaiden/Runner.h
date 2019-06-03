#pragma once
#include "Enemy.h"

enum RUNNER_STATE
{
	RUNNER_STATE_INVISIBLE,
	RUNNER_STATE_VISIBLE,
};

class Runner :
	public Enemy
{
	RUNNER_STATE state;
public:
	void setState(RUNNER_STATE state);
	void onCollision(MovableRect* other, float collisionTime, int nx, int ny) override;
	void onIntersect(MovableRect* other) override;
	void onUpdate(float dt) override;
	void restoreLocation() override;
	Runner();
	~Runner();
};

