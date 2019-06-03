#pragma once
#include "BaseObject.h"
class BirdStatic :
	public BaseObject
{
public:
	BirdStatic();
	void onCollision(MovableRect* other, float collisionTime, int nx, int ny) override;
	void onIntersect(MovableRect* other) override;

};

