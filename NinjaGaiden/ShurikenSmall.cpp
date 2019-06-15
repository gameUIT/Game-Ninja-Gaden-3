#include "ShurikenSmall.h"
#include"SpriteManager.h"
ShurikenSmall::ShurikenSmall()
{
	setCollisionType(CT_WEAPON);
	setSprite(SpriteManager::getSprite(SPRITE_INFO::SPRITE_ITEM_SHURIKEN_SMALL));
	setPhysicsEnable(false);
	setInitBox(new Rect());
	canReturn = true;
}

void ShurikenSmall::onUpdate(float dt)
{
	//if (abs(this->getX() - this->getInitBox()->getX()) > 100 && canReturn)
	//{
	//	setDx(-getDx());
	//	canReturn = false;
	//}
	SubWeapon::onUpdate(dt);
}

void ShurikenSmall::onIntersect(MovableRect * other)
{
	if (other->getCollisionType() == CT_ENEMY || other->getCollisionType() == CT_MISC)
	{
		remove();
	}
}
