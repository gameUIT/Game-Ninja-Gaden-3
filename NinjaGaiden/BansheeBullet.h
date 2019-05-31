#pragma once
#include "RunTimeObject.h"

class BansheeBullet :
	public RunTimeObject
{
public:
	void onCollision(MovableRect *other, float collisionTime, int nx, int ny);
	BansheeBullet();
	~BansheeBullet();
	void onUpdate(float dt) override;
	void onIntersect(MovableRect* other) override;
	void render(Camera* camera);
};

