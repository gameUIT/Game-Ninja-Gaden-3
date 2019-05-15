#include"Shooter.h"
#include"Ryu.h"

Shooter::Shooter()
{
	setDirection(LEFT);
	setSprite(SPR(SPRITE_INFO_SHOOTER));
	setCollisionType(CT_ENEMY);
	setState(SHOOTER_STATE_INVISIBLE);
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

void Shooter::onUpdate(float dt)
{
	switch (state)
	{
	case SHOOTER_STATE_INVISIBLE:
		setRenderActive(false);
		setVx(0);
		setDx(0);
		if (abs(getMidX() - Ryu::getInstance()->getMidX()) < GLOBALS_D("swordman_distance_to_activate"))
		{
			setState(SHOOTER_STATE_VISIBLE);
			setRenderActive(true);
		}
		break;
	case SHOOTER_STATE_VISIBLE:
		setVx(GLOBALS_D("swordman_vx") * getDirection());
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
	if (direction == 1)
	{
		setState(SHOOTER_STATE_VISIBLE);
	}
	else
	{
		setState(SHOOTER_STATE_INVISIBLE);
	}
}

Shooter::~Shooter()
{
}
