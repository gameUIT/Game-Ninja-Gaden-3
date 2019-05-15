#include"Bird.h"
#include"Ryu.h"

Bird::Bird()
{
	setDirection(LEFT);
	setSprite(SPR(SPRITE_INFO_BROWN_BIRD));
	setCollisionType(CT_ENEMY);
	setState(BIRD_STATE_INVISIBLE);
}

void Bird::setState(BIRD_STATE state)
{
	this->state = state;
}

void Bird::onCollision(MovableRect * other, float collisionTime, int nx, int ny)
{
	Enemy::onCollision(other, collisionTime, nx, ny);
}

void Bird::onIntersect(MovableRect * other)
{
	//if (other->getCollisionType() == CT_WEAPON)
	//{
	//	this->setAlive(false);
	//}
	Enemy::onIntersect(other);
}

void Bird::onUpdate(float dt)
{
	switch (state)
	{
	case BIRD_STATE_INVISIBLE:
		setRenderActive(false);
		setVx(0);
		setDx(0);
		if (abs(getMidX() - Ryu::getInstance()->getMidX()) < GLOBALS_D("swordman_distance_to_activate"))
		{
			setState(BIRD_STATE_VISIBLE);
			setRenderActive(true);
		}
		break;
	case BIRD_STATE_VISIBLE:
		setVx(GLOBALS_D("swordman_vx") * getDirection());
		break;
	default:
		break;
	}

	Enemy::onUpdate(dt);
}

void Bird::restoreLocation()
{
	BaseObject::restoreLocation();
	int direction = getDirection();
	if (direction == 1)
	{
		setState(BIRD_STATE_VISIBLE);
	}
	else
	{
		setState(BIRD_STATE_INVISIBLE);
	}
}

Bird::~Bird()
{
}
