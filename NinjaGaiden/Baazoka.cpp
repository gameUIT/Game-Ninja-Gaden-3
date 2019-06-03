#include"Baazoka.h"
#include"Ryu.h"
#include"ShooterBullet.h"
#include"Camera.h"
#include"Collision.h"

Baazoka::Baazoka()
{
	setDirection(LEFT);
	setSprite(SPR(SPRITE_INFO_BAAZOKA));
	setCollisionType(CT_ENEMY);
	setState(BAAZOKA_STATE_INVISIBLE);

	fireDelay.init(GLOBALS_D("baazoka_fire_delay"));
	fireTime.init(GLOBALS_D("baazoka_fire_time"));

}

void Baazoka::setState(BAAZOKA_STATE state)
{
	this->state = state;
}

void Baazoka::onCollision(MovableRect * other, float collisionTime, int nx, int ny)
{
	Enemy::onCollision(other, collisionTime, nx, ny);
}

void Baazoka::onIntersect(MovableRect * other)
{
	Enemy::onIntersect(other);
}

//("shooter_run_delay", 2000));
//globalsConfigurationDouble->insert(pair<const char*, double>("shooter_fire_delay", 1000));
//globalsConfigurationDouble->insert(pair<const char*, double>("shooter_fire_time", 100));
//globalsConfigurationDouble->insert(pair<const char*, double>("shooter_vx", 80));

void Baazoka::onUpdate(float dt)
{
	fireDelay.update();

	switch (state)
	{
	case BAAZOKA_STATE_INVISIBLE:
		setRenderActive(false);
		setVx(0);
		setDx(0);
		if (abs(getMidX() - Ryu::getInstance()->getMidX()) < GLOBALS_D("swordman_distance_to_activate"))
		{
			setState(BAAZOKA_STATE_STATE_FIRE);
			setRenderActive(true);
		}
		break;
	case BAAZOKA_STATE_STATE_FIRE:
		setVx(0);

		if (fireTime.atTime())
		{
			ShooterBullet* bullet = new ShooterBullet();
			bullet->setVx(getDirection()* GLOBALS_D("shooter_bullet_vx"));
			bullet->setX(getX());
			bullet->setY(getY() - 2);
			bullet->setRenderActive(true);
		}

		if (fireDelay.isTerminated())
		{
			setState(BAAZOKA_STATE_INVISIBLE);
		}
		break;
	default:
		break;
	}

	Enemy::onUpdate(dt);
}

void Baazoka::restoreLocation()
{
	BaseObject::restoreLocation();
	int direction = getDirection();
	setState(BAAZOKA_STATE_INVISIBLE);

}

Baazoka::~Baazoka()
{
}
