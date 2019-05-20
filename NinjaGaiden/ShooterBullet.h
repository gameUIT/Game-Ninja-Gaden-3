#pragma once
#include"RunTimeObject.h"
class ShooterBullet
	: public RunTimeObject
{
public:
	void onUpdate(float dt) override;
	ShooterBullet();
	~ShooterBullet();
};

