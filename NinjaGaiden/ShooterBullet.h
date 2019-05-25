#pragma once
#include"RunTimeObject.h"
class ShooterBullet
	: public RunTimeObject
{
public:
	void onUpdate(float dt) override;
	void onIntersect(MovableRect* other) override;
	ShooterBullet();
	~ShooterBullet();
};

