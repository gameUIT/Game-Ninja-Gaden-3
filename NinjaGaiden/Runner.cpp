#include"Runner.h"
#include"Ryu.h"

Runner::Runner()
{
	setDirection(LEFT);
	setSprite(SPR(SPRITE_INFO_RUNNER));
	setCollisionType(CT_ENEMY);
	setState(RUNNER_STATE_INVISIBLE);
}

void Runner::setState(RUNNER_STATE state)
{
	this->state = state;
}

void Runner::onCollision(MovableRect * other, float collisionTime, int nx, int ny)
{
	Enemy::onCollision(other, collisionTime, nx, ny);
}

void Runner::onIntersect(MovableRect * other)
{
	Enemy::onIntersect(other);
}

void Runner::onUpdate(float dt)
{
	switch (state)
	{
	case RUNNER_STATE_INVISIBLE:
		setRenderActive(false);
		setVx(0);
		setDx(0);
		if (abs(getMidX() - Ryu::getInstance()->getMidX()) < GLOBALS_D("swordman_distance_to_activate"))
		{
			setState(RUNNER_STATE_VISIBLE);
			setRenderActive(true);
		}
		break;
	case RUNNER_STATE_VISIBLE:
		setVx(GLOBALS_D("runner_vx") * getDirection());
		break;
	default:
		break;
	}

	Enemy::onUpdate(dt);
}

void Runner::restoreLocation()
{
	BaseObject::restoreLocation();
	int direction = getDirection();
	if (direction == 1)
	{
		setState(RUNNER_STATE_VISIBLE);
	}
	else
	{
		setState(RUNNER_STATE_INVISIBLE);
	}
}

Runner::~Runner()
{
}
