#include"SwordMan.h"
#include"Ryu.h"

SwordMan::SwordMan()
{
	setDirection(LEFT);
	setSprite(SPR(SPRITE_INFO_SWORDMAN));
	setCollisionType(CT_ENEMY);
	setState(SWORDMAN_STATE_INVISIBLE);
}

void SwordMan::setState(SWORDMAN_STATE state)
{
	this->state = state;
}

void SwordMan::onCollision(MovableRect * other, float collisionTime, int nx, int ny)
{
	Enemy::onCollision(other, collisionTime, nx, ny);
}

void SwordMan::onIntersect(MovableRect * other)
{
	Enemy::onIntersect(other);
}

void SwordMan::onUpdate(float dt)
{
	switch (state)
	{
	case SWORDMAN_STATE_INVISIBLE:
		setRenderActive(false);
		setVx(0);
		setDx(0);
		if (abs(getMidX() - Ryu::getInstance()->getMidX()) < GLOBALS_D("swordman_distance_to_activate"))
		{
			setState(SWORDMAN_STATE_VISIBLE);
			setRenderActive(true);
		}
		break;
	case SWORDMAN_STATE_VISIBLE:
		setVx(GLOBALS_D("swordman_vx") * getDirection());
		break;
	default:
		break;
	}

	Enemy::onUpdate(dt);
}

void SwordMan::restoreLocation()
{
	BaseObject::restoreLocation();
	int direction = getDirection();
	if (direction == 1)
	{
		setState(SWORDMAN_STATE_VISIBLE);
	}
	else
	{
		setState(SWORDMAN_STATE_INVISIBLE);
	}
}

SwordMan::~SwordMan()
{
}
