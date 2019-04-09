#pragma once
#include"PhysicsObject.h"
#include"SpriteManager.h"
#include"KEY.h"

enum RYU_ANIMATION
{
	RYU_ANIMATION_STAND,
	RYU_ANIMATION_RUN,
	RYU_ANIMATION_JUMP,
	RYU_ANIMATION_ATTACK,
};

enum RYU_STATE
{
	RYU_STATE_NORMAL,
	RYU_STATE_RUN,
	RYU_STATE_ATTACK,
};

class Ryu :
	public PhysicsObject
{
	static Ryu* instance;
public:
	static Ryu* getInstance();
	void onUpdate(float dt) override;
	void onCollision(MovableRect* other, float collisionTime, int nx, int ny);
	Ryu();
	~Ryu();
};

