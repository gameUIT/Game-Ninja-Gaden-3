#include"Shooter.h"
#include"Ryu.h"
#include"ShooterBullet.h"
#include"Camera.h"
#include"Collision.h"

Shooter::Shooter()
{
	setDirection(LEFT);
	setSprite(SPR(SPRITE_INFO_SHOOTER));
	setCollisionType(CT_ENEMY);
	setState(SHOOTER_STATE_RUN);

	runDelay.init(GLOBALS_D("shooter_run_delay"));
	fireDelay.init(GLOBALS_D("shooter_fire_delay"));
	fireTime.init(GLOBALS_D("shooter_fire_time"));

	runDelay.start();
}

void Shooter::setState(SHOOTER_STATE state)
{
	this->state = state;
}

void Shooter::onCollision(MovableRect * other, float collisionTime, int nx, int ny)
{
	Enemy::onCollision(other, collisionTime, nx, ny);
}

void Shooter::onIntersect(MovableRect * other)
{
	//if (other->getCollisionType() == CT_WEAPON)
	//{
	//	this->setAlive(false);
	//}
	Enemy::onIntersect(other);
}

//("shooter_run_delay", 2000));
//globalsConfigurationDouble->insert(pair<const char*, double>("shooter_fire_delay", 1000));
//globalsConfigurationDouble->insert(pair<const char*, double>("shooter_fire_time", 100));
//globalsConfigurationDouble->insert(pair<const char*, double>("shooter_vx", 80));

void Shooter::onUpdate(float dt)
{
	runDelay.update();
	fireDelay.update();

	if (!Collision::AABBCheck(Camera::getInstance(), this))
	{
		setState(SHOOTER_STATE_INVISIBLE);
	}

	switch (state)
	{
	case SHOOTER_STATE_INVISIBLE:
		setRenderActive(false);
		if (Collision::AABBCheck(Camera::getInstance(), this))
		{
			setState(SHOOTER_STATE_RUN);
			setRenderActive(true);
			runDelay.start();
		}
		break;
	case SHOOTER_STATE_RUN:

		setVx(GLOBALS_D("shooter_vx")* getDirection());

		if (runDelay.isTerminated())
		{
			
			setState(SHOOTER_STATE_FIRE);
			fireDelay.start();
		}


		//if((getDx() < 0 && ((getMidX() - initBox->getMidX() )< bansheeDelta))||
		//	(getDx() > 0 && ((getMidX() - initBox->getMidX() ) > bansheeDelta)))
		////if(abs(getMidX() - getX()) > bansheeDelta)
		//{
		//	setX(initBox->getX());
		//	vDirection = -vDirection;
		//}
		break;
	case SHOOTER_STATE_FIRE:
		setVx(0);

		if (fireTime.atTime())
		{
			ShooterBullet* bullet = new ShooterBullet();
			bullet->setVx(getDirection()* GLOBALS_D("shooter_bullet_vx"));
			bullet->setX(getX());
			bullet->setY(getY()-5);
			bullet->setRenderActive(true);
		}

		if (fireDelay.isTerminated())
		{
			setState(SHOOTER_STATE_RUN);
			runDelay.start();
		}
		break;
	default:
		break;
	}


	Enemy::onUpdate(dt);
}

void Shooter::restoreLocation()
{
	BaseObject::restoreLocation();
	int direction = getDirection();
	setState(SHOOTER_STATE_RUN);

}

Shooter::~Shooter()
{
}
