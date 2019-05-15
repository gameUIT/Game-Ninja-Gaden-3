#pragma once
#include "Enemy.h"


enum BANSHEE_STATE
{
	BANSHEE_STATE_INVISIBLE,
	BANSHEE_STATE_VISIBLE,
	BANSHEE_STATE_ATTACK,
};

class Banshee :
	public Enemy
{
	BANSHEE_STATE state;
public:
	void setState(BANSHEE_STATE state);
	void onCollision(MovableRect* other, float collisionTime, int nx, int ny) override;
	void onIntersect(MovableRect* other) override;
	void onUpdate(float dt) override;
	void restoreLocation() override;
	Banshee();
	~Banshee();
};

