#pragma once
#include "SubWeapon.h"
class ShurikenSmall :
	public SubWeapon
{
	bool canReturn;
public:
	ShurikenSmall();
	void onUpdate(float dt) override;
	void onIntersect(MovableRect* other) override;
};

