#pragma once
#include "SubWeapon.h"
class ShurikenSmall :
	public SubWeapon
{
public:
	ShurikenSmall();
	void onIntersect(MovableRect* other) override;
};

