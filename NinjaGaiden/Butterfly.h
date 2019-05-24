#pragma once
#include "BaseObject.h"
class Butterfly :
	public BaseObject
{
public:
	Butterfly();
	void onCollision(MovableRect* other, float collisionTime, int nx, int ny) override;
	void onIntersect(MovableRect* other) override;

};

