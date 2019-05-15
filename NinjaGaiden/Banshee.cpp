#include"Banshee.h"
#include"Ryu.h"

Banshee::Banshee()
{
	setDirection(LEFT);
	setSprite(SPR(SPRITE_INFO_BANSHEE));
	setCollisionType(CT_ENEMY);
	setState(BANSHEE_STATE_INVISIBLE);
}

void Banshee::setState(BANSHEE_STATE state)
{
	this->state = state;
}

void Banshee::onCollision(MovableRect * other, float collisionTime, int nx, int ny)
{
	Enemy::onCollision(other, collisionTime, nx, ny);
}

void Banshee::onIntersect(MovableRect * other)
{
	//if (other->getCollisionType() == CT_WEAPON)
	//{
	//	this->setAlive(false);
	//}
	Enemy::onIntersect(other);
}

void Banshee::onUpdate(float dt)
{
	switch (state)
	{
	case BANSHEE_STATE_INVISIBLE:
		setRenderActive(false);
		setVx(0);
		setDx(0);
		if (abs(getMidX() - Ryu::getInstance()->getMidX()) < GLOBALS_D("swordman_distance_to_activate"))
		{
			setState(BANSHEE_STATE_VISIBLE);
			setRenderActive(true);
		}
		break;
	case BANSHEE_STATE_VISIBLE:
		setVx(GLOBALS_D("swordman_vx") * getDirection());
		break;
	default:
		break;
	}

	Enemy::onUpdate(dt);
}

void Banshee::restoreLocation()
{
	BaseObject::restoreLocation();
	int direction = getDirection();
	if (direction == 1)
	{
		setState(BANSHEE_STATE_VISIBLE);
	}
	else
	{
		setState(BANSHEE_STATE_INVISIBLE);
	}
}

Banshee::~Banshee()
{
}
