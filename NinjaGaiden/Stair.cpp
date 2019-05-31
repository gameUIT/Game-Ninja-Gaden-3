#include "Stair.h"
#include"Ryu.h"
Stair::Stair()
{

}

void Stair::onCollision(MovableRect* other, float collisionTime, int nx, int ny)
{
	if (nx == -1 && Ryu::getInstance()->getDirection() == RIGHT)
	{
		Ryu::getInstance()->stair = this;
		Ryu::getInstance()->setState(RYU_STATE::RYU_STATE_STAIR);
	}
}
