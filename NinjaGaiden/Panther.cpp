#include"Panther.h"
#include"Ryu.h"

Panther::Panther()
{
	setDirection(LEFT);
	setSprite(SPR(SPRITE_INFO_PANTHER));
	setCollisionType(CT_ENEMY);
	setState(PANTHER_STATE_INVISIBLE);
}

void Panther::setState(PANTHER_STATE state)
{
	this->state = state;
}

void Panther::onCollision(MovableRect * other, float collisionTime, int nx, int ny)
{
	Enemy::onCollision(other, collisionTime, nx, ny);
}

void Panther::onIntersect(MovableRect * other)
{
	//if (other->getCollisionType() == CT_WEAPON)
	//{
	//	this->setAlive(false);
	//}
	Enemy::onIntersect(other);
}

void Panther::onUpdate(float dt)
{
	switch (state)
	{
	case PANTHER_STATE_INVISIBLE:
		setRenderActive(false);
		setVx(0);
		setDx(0);
		if (abs(getMidX() - Ryu::getInstance()->getMidX()) < GLOBALS_D("panther_distance_to_activate"))
		{
			setState(PANTHER_STATE_VISIBLE);
			setRenderActive(true);
		}
		break;
	case PANTHER_STATE_VISIBLE:
		setVx(GLOBALS_D("panther_vx") * getDirection());
		break;
	default:
		break;
	}

	Enemy::onUpdate(dt);
}

void Panther::restoreLocation()
{
	BaseObject::restoreLocation();
	int direction = getDirection();
	if (direction == 1)
	{
		setState(PANTHER_STATE_VISIBLE);
	}
	else
	{
		setState(PANTHER_STATE_INVISIBLE);
	}
}

Panther::~Panther()
{
}
