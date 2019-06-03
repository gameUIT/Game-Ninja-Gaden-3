#include "Item.h"
#include"Ryu.h"
Item::Item()
{
	setCollisionType(CT_ITEM);
	setRenderActive(false);
	setPhysicsEnable(false);
}

void Item::onIntersect(MovableRect* other)
{
	if (!getRenderActive())
	{
		if (other->getCollisionType() == CT_WEAPON)
		{
			setRenderActive(true);
			setPhysicsEnable(true);
		}
	}
	else
	{
		if (other == Ryu::getInstance())
		{
			setRenderActive(false);
			onContactPlayer();
		}
	}
	
}

void Item::onCollision(MovableRect* other, float collisionTime, int nx, int ny)
{
	if (other->getCollisionType() == CT_GROUND)
	{
		preventMovementOnCollision(collisionTime, nx, ny);
	}
}

void Item::onContactPlayer()
{
}
