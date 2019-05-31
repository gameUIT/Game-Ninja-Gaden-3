#include "ShurikenBig.h"
#include"SpriteManager.h"
ShurikenBig::ShurikenBig()
{
	setCollisionType(CT_WEAPON);
	setSprite(SpriteManager::getSprite(SPRITE_INFO::SPRITE_ITEM_SHURIKEN_BIG));
	setPhysicsEnable(false);
}
