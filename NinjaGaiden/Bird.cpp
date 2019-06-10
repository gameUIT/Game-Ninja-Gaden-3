#include"Bird.h"
#include"Ryu.h"
#include"Camera.h"
#include"Collision.h"
#include "Boss.h"

Bird::Bird()
{
	setDirection(LEFT);
	setSprite(SPR(SPRITE_INFO_BROWN_BIRD));
	setCollisionType(CT_ENEMY);
	setState(BIRD_STATE_FOLLOW_PLAYER);
	setDirectionFollowPlayer();
}

void Bird::setState(BIRD_STATE state)
{
	this->state = state;
}


void Bird::onCollision(MovableRect * other, float collisionTime, int nx, int ny)
{

}

void Bird::onIntersect(MovableRect * other)
{
	Enemy::onIntersect(other);
}

void Bird::onUpdate(float dt)
{
	auto ryu = Ryu::getInstance();
	if (!Collision::AABBCheck(Camera::getInstance(), this))
	{
		setState(BIRD_STATE_INVISIBLE);
	}
	switch (state)
	{
	case BIRD_STATE_INVISIBLE:
		setRenderActive(false);
		if (Collision::AABBCheck(Camera::getInstance(),this))
		{
			setState(BIRD_STATE_FOLLOW_PLAYER);
			setRenderActive(true);
		}
		break;
	case BIRD_STATE_FOLLOW_PLAYER:
	{
		auto r = GLOBALS_D("bird_r");

		float dy = 0;
		auto x = getX(), y = getY(), xr = ryu->getX() + 5, yr = ryu->getY() + 5;

		auto deltax = x - xr, deltay = y - yr;

		if (abs(deltax) < GLOBALS_D("bird_min_x") || abs(deltay) < GLOBALS_D("bird_min_x"))
		{
			setState(BIRD_STATE_RUN_UNTIL_RETURN);
		}

		dy = r * sqrt((deltay*deltay) / (deltax*deltax + deltay * deltay));

		if (y - yr > 0)
		{
			dy = -dy;
		}

		auto dx = dy * deltax / deltay;
		if (dx < 0)
		{
			setDirection(LEFT);
		}
		else
		{
			setDirection(RIGHT);
		}

		setDx(dx);
		setDy(dy);

		break;
	}
	case BIRD_STATE_RUN_UNTIL_RETURN:
	{
		auto x = getX(), y = getY(), xr = ryu->getX(), yr = ryu->getY();
		auto deltax = x - xr, deltay = y - yr;
		if (deltax*deltax + deltay * deltay  > GLOBALS_D("bird_max_x")*GLOBALS_D("bird_max_x"))
		{
			setState(BIRD_STATE_FOLLOW_PLAYER);
		}
		break;
	}
	default:
		break;
	}

	//BaseObject::onUpdate(dt);
}

void Bird::restoreLocation()
{
	BaseObject::restoreLocation();
	setDirectionFollowPlayer();
	setState(BIRD_STATE_FOLLOW_PLAYER);
}

Bird::~Bird()
{
}
