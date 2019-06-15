#include "ShurikenBig.h"
#include"SpriteManager.h"
#include"Ryu.h"
ShurikenBig::ShurikenBig()
{
	setCollisionType(CT_WEAPON);
	setSprite(SpriteManager::getSprite(SPRITE_INFO::SPRITE_ITEM_SHURIKEN_BIG));
	setPhysicsEnable(false);
	setInitBox(new Rect());
	canReturn = true;
}

void ShurikenBig::onUpdate(float dt)
{
	if (abs(this->getX() - this->getInitBox()->getX()) > 100)
	{
		setDx(-getDx());
	}
	SubWeapon::onUpdate(dt);
}

void ShurikenBig::onIntersect(MovableRect * other)
{
	if (other->getCollisionType() == CT_ENEMY || other->getCollisionType() == CT_MISC || other == Ryu::getInstance())
	{
		remove();
	}
}
