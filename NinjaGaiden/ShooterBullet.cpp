#include "ShooterBullet.h"
#include"SpriteManager.h"
#include"Ryu.h"


void ShooterBullet::onUpdate(float dt)
{
	RunTimeObject::onUpdate(dt);
}

void ShooterBullet::onIntersect(MovableRect * other)
{
	if (other->getCollisionType() == CT_PLAYER)
	{
		Ryu* ryu = Ryu::getInstance();
		ryu->blinkDelay.start();
		ryu->setVy(GLOBALS_D("player_hit_vy"));
	}
}

ShooterBullet::ShooterBullet()
{
	setSprite(SpriteManager::getSprite(SPRITE_INFO_SHOOTER_WEAPON));
	setAy(0);
}


ShooterBullet::~ShooterBullet()
{
}
