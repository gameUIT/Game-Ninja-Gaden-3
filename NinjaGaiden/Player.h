#pragma once
#include "PhysicsObject.h"
#include"SpriteManager.h"
#include"KEY.h"

enum RYU_ACTION
{
	RYU_ACTION_STAND,
	RYU_ACTION_RUN,
	RYU_ACTION_JUMP,
	RYU_ACTION_ATTACK
};

enum RYU_STATE
{
	RYU_STATE_NORMAL,
	RYU_STATE_ATTACK,
};

class Player :
	public PhysicsObject
{
	static Player* instance; 
public:
	static Player* getInstance();
	void onUpdate(float dt) override;
	void onCollision(MovableRect* other, float collisionTime, int nx, int ny);
	Player();
	~Player();
};

