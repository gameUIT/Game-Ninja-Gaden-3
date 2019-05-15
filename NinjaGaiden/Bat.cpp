#include"Bat.h"
#include"Ryu.h"

Bat::Bat()
{
	setDirection(LEFT);
	setSprite(SPR(SPRITE_INFO_BAT));
	setCollisionType(CT_ENEMY);
	setState(BAT_STATE_INVISIBLE);
}

void Bat::setState(BAT_STATE state)
{
	this->state = state;
}

void Bat::onCollision(MovableRect * other, float collisionTime, int nx, int ny)
{
	Enemy::onCollision(other, collisionTime, nx, ny);
}

void Bat::onIntersect(MovableRect * other)
{
	//if (other->getCollisionType() == CT_WEAPON)
	//{
	//	this->setAlive(false);
	//}
	Enemy::onIntersect(other);
}

void Bat::onUpdate(float dt)
{
	switch (state)
	{
	case BAT_STATE_INVISIBLE:
		setRenderActive(false);
		setVx(0);
		setDx(0);
		if (abs(getMidX() - Ryu::getInstance()->getMidX()) < GLOBALS_D("panther_distance_to_activate"))
		{
			setState(BAT_STATE_VISIBLE);
			setRenderActive(true);
		}
		break;
	case BAT_STATE_VISIBLE:
		setVx(GLOBALS_D("panther_vx") * getDirection());
		break;
	default:
		break;
	}

	Enemy::onUpdate(dt);
}

void Bat::restoreLocation()
{
	BaseObject::restoreLocation();
	int direction = getDirection();
	if (direction == 1)
	{
		setState(BAT_STATE_VISIBLE);
	}
	else
	{
		setState(BAT_STATE_INVISIBLE);
	}
}

Bat::~Bat()
{
}
