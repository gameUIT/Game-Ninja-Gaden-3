#include "BirdStatic.h"
#include "ExplosionEffect.h"

BirdStatic::BirdStatic()
{
	setCollisionType(COLLISION_TYPE::CT_MISC);
	setDirection(RIGHT);
}

void BirdStatic::onCollision(MovableRect* other, float collisionTime, int nx, int ny)
{
	BaseObject::onCollision(other, collisionTime, nx, ny);
}

void BirdStatic::onIntersect(MovableRect* other)
{
	if (getRenderActive() && other->getCollisionType() == CT_WEAPON)
	{
		auto effect = new ExplosionEffect();
		effect->setX(getMidX());
		effect->setY(getMidY());
		setRenderActive(false);
	}
}
