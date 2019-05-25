#include"Banshee.h"
#include"Ryu.h"
#include"BansheeBullet.h"

Banshee::Banshee()
{
	setDirection(LEFT);
	setSprite(SPR(SPRITE_INFO_BANSHEE));
	setCollisionType(CT_ENEMY);
	setState(BANSHEE_STATE_RUN);
	vDirection = -1;

	runDelay.init(GLOBALS_D("banshee_time_run"));
	fireDelay.init(GLOBALS_D("banshee_time_fire"));

	runDelay.start();

}

void Banshee::setState(BANSHEE_STATE state)
{
	this->state = state;
}

void Banshee::onCollision(MovableRect * other, float collisionTime, int nx, int ny)
{
	if (nx != 0)
	{
		return;
	}
	Enemy::onCollision(other, collisionTime, nx, ny);
}

void Banshee::onIntersect(MovableRect * other)
{
	Enemy::onIntersect(other);
}

void Banshee::onUpdate(float dt)
{
	runDelay.update();
	fireDelay.update();
	auto bansheeDelta = GLOBALS_D("banshee_delta");
	setDirectionFollowPlayer();

	switch (state)
	{
	case BANSHEE_STATE_RUN:

		if (getRenderActive() == true)
		{
			if (getDx() < 0 && ((getMidX() - initBox->getMidX()) < -bansheeDelta))
			{
				vDirection = 1;
			}

			if (getDx() > 0 && ((getMidX() - initBox->getMidX()) > bansheeDelta))
			{
				vDirection = -1;
			}

			if (runDelay.isTerminated())
			{
				BansheeBullet* bullet = new BansheeBullet();
				bullet->setVx(getDirection()* GLOBALS_D("banshee_weapon_vx"));
				bullet->setVy(GLOBALS_D("banshee_weapon_vy"));
				bullet->setX(getX());
				bullet->setY(getY());
				bullet->setRenderActive(true);
				setState(BANSHEE_STATE_FIRE);
				fireDelay.start();
			}
		}


		//if((getDx() < 0 && ((getMidX() - initBox->getMidX() )< bansheeDelta))||
		//	(getDx() > 0 && ((getMidX() - initBox->getMidX() ) > bansheeDelta)))
		////if(abs(getMidX() - getX()) > bansheeDelta)
		//{
		//	setX(initBox->getX());
		//	vDirection = -vDirection;
		//}
		setVx(GLOBALS_D("banshee_vx") * vDirection);
		break;
	case BANSHEE_STATE_FIRE:
		setVx(0);

		if (fireDelay.isTerminated())
		{
			setState(BANSHEE_STATE_RUN);
			runDelay.start();
		}
		break;
	default:
		break;
	}

	Enemy::onUpdate(dt);
}

void Banshee::restoreLocation()
{
	BaseObject::restoreLocation();
	setState(BANSHEE_STATE_RUN);

}

Banshee::~Banshee()
{
}
