#pragma once
#include "SubWeapon.h"
class ShurikenBig :
	public SubWeapon
{
	bool canReturn;
public:
	ShurikenBig();
	void onUpdate(float dt) override;
	void onIntersect(MovableRect* other) override;
};

