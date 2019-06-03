#include "ShooterBullet.h"
#include"SpriteManager.h"
#include"Ryu.h"
#include"ScoreBar.h"
#include"ExplosionEffect.h"


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

		//ScoreBar::getInstance()->increaseHealth(-1);
	}

	if (other->getCollisionType() == CT_WEAPON)
	{
		auto effect = new ExplosionEffect();
		effect->setX(getMidX());
		effect->setY(getMidY());
		remove();

		//ScoreBar::getInstance()->setScore(ScoreBar::getInstance()->getScore() + 100);
	}
}

ShooterBullet::ShooterBullet()
{
	setSprite(SpriteManager::getSprite(SPRITE_INFO_SHOOTER_WEAPON));
	setCollisionType(CT_ENEMY);
	setAy(0);
}


ShooterBullet::~ShooterBullet()
{
}
