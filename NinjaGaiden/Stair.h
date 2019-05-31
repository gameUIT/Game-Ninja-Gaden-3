#pragma once
#include "BaseObject.h"
class Stair :
	public BaseObject
{
public:
	Stair();
	void onCollision(MovableRect* other, float collisionTime, int nx, int ny) override;
};

