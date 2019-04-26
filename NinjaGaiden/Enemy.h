#pragma once
#include"PhysicsObject.h"

class Enemy :
	public PhysicsObject
{
	int health;
public:
	void setHealth(int health);
	int getHealth();
	void setDirectionFollowPlayer();

	void onUpdate(float dt) override;
	void onCollision(MovableRect* other, float collisionTime, int nx, int ny);
	void onIntersect(MovableRect* other) override;
	void restoreLocation() override;

	virtual void onDeath();
	virtual void onDecreaseHealth();
	virtual void onCollisionWithPlayer();
	virtual void onCollisionWithWeapon();
	virtual bool canAttackPlayer();
	Enemy();
	~Enemy();
};

