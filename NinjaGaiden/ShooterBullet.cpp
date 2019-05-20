#include "ShooterBullet.h"
#include"SpriteManager.h"


void ShooterBullet::onUpdate(float dt)
{
	RunTimeObject::onUpdate(dt);
}

ShooterBullet::ShooterBullet()
{
	setSprite(SpriteManager::getSprite(SPRITE_INFO_SHOOTER_WEAPON));
	setAy(0);
}


ShooterBullet::~ShooterBullet()
{
}
