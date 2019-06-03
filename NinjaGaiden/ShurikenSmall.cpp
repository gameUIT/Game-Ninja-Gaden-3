#include "ShurikenSmall.h"
#include"SpriteManager.h"
ShurikenSmall::ShurikenSmall()
{
	setCollisionType(CT_WEAPON);
	setSprite(SpriteManager::getSprite(SPRITE_INFO::SPRITE_ITEM_SHURIKEN_SMALL));
	setPhysicsEnable(false);
}

void ShurikenSmall::onIntersect(MovableRect * other)
{
	if (other->getCollisionType() == CT_ENEMY || other->getCollisionType() == CT_MISC)
	{
		remove();
	}
}
