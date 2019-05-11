#include "SwordRObject.h"



void SwordRObject::onIntersect(MovableRect * other)
{
	if (other->getCollisionType() == CT_ENEMY)
	{
		remove();
	}
}

SwordRObject::SwordRObject()
{
	setCollisionType(COLLISION_TYPE::CT_WEAPON);
}


SwordRObject::~SwordRObject()
{
}
