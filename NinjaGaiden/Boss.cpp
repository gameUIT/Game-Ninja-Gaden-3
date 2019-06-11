#include "Boss.h"
#include "Ryu.h"
#include "ExplosionEffect.h"
#include "ScoreBar.h"
#include "ShooterBullet.h"

void Boss::setCollisionType(COLLISION_TYPE collisionType)
{
	Enemy::setCollisionType(collisionType);
}

void Boss::setState(BOSS_STATE state)
{
	this->state = state;
}

void Boss::onCollision(MovableRect * other, float collisionTime, int nx, int ny)
{
	Enemy::onCollision(other, collisionTime, nx, ny);
}

void Boss::onIntersect(MovableRect * other)
{
	Ryu* ryu = Ryu::getInstance();
	if (other == ryu && !ryu->blinkDelay.isOnTime() && canAttackPlayer() && !ryu->isDead)
	{
		onCollisionWithPlayer();
	}

	if (other->getCollisionType() == CT_WEAPON)
	{
		ScoreBar::getInstance()->setBossHealth(ScoreBar::getInstance()->getBossHealth() - 1);
	}

	if (other->getCollisionType() == CT_WEAPON && getRenderActive() && ScoreBar::getInstance()->getBossHealth() <= 0)
	{
		//setRenderActive(false);
		setIsAlive(false);
		auto effect = new ExplosionEffect();
		effect->setX(getMidX());
		effect->setY(getMidY());

		ScoreBar::getInstance()->setScore(ScoreBar::getInstance()->getScore() + 1000);
	}
}

void Boss::onUpdate(float dt)
{
	standDelay.update();
	switch (state)
	{
	case BOSS_STATE_STAND:
		if (standDelay.isTerminated())
		{
			setVy(GLOBALS_D("boss_vy"));
			setVx(getDirection() * GLOBALS_D("boss_vx"));
			setState(BOSS_STATE_JUMP);
		}
		else
		{
			setVx(0);
		}
		break;
	case BOSS_STATE_JUMP:
		if (getIsGrounded())
		{
			setDirection((TEXTURE_DIRECTION) -getDirection());
			standDelay.start();
			setState(BOSS_STATE_STAND);

			ShooterBullet* bullet = new ShooterBullet();
			bullet->setX(getX());
			bullet->setY(getY());
			bullet->setDirection(getDirection());
			bullet->setVx(getDirection() * 100);

			bullet = new ShooterBullet();
			bullet->setX(getX());
			bullet->setY(getY() - 10);
			bullet->setDirection(getDirection());
			bullet->setVx(getDirection() * 100);

			bullet = new ShooterBullet();
			bullet->setX(getX());
			bullet->setY(getY() - 20);
			bullet->setDirection(getDirection());
			bullet->setVx(getDirection() * 100);
		}
		break;
	default:
		break;
	}
	Enemy::onUpdate(dt);
}


Boss::Boss()
{
	setCollisionType(CT_ENEMY);
	setAnimation(BOSS_ACTION_ONGROUND);
	setDirection(RIGHT);
	standDelay.init(1000);
	standDelay.start();
}

Boss::~Boss()
{
}
