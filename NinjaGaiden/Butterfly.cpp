#include "Butterfly.h"
#include "ExplosionEffect.h"

Butterfly::Butterfly()
{
	setCollisionType(COLLISION_TYPE::CT_MISC);
	setDirection(RIGHT);
}

void Butterfly::onCollision(MovableRect* other, float collisionTime, int nx, int ny)
{
	BaseObject::onCollision(other, collisionTime, nx, ny);
}

void Butterfly::onIntersect(MovableRect* other)
{
	if (getRenderActive() && other->getCollisionType() == CT_WEAPON)
	{
		auto effect = new ExplosionEffect();
		effect->setX(getMidX());
		effect->setY(getMidY());
		setRenderActive(false);
	}
}
