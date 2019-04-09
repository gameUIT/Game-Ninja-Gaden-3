#include "Ryu.h"


Ryu * Ryu::instance = 0;
Ryu * Ryu::getInstance()
{
	if (instance == 0)
	{
		instance = new Ryu();
	}
	return instance;
}

void Ryu::onUpdate(float dt)
{
	bool keyLeftDown, keyRightDown, keyUpDown, keyDownDown, keyJumpDown;
	float vx = GLOBALS_D("player_vx");
	KEY *key = KEY::getInstance();
	keyLeftDown = key->isLeftDown;
	keyRightDown = key->isRightDown;
	keyUpDown = key->isUpDown;
	keyDownDown = key->isDownDown;
	keyJumpDown = key->isJumpDown;

	if (getIsGrounded())
	{
		if (keyLeftDown)
		{
			setVx(-vx);
		}
		else if (keyRightDown)
		{
			setVx(vx);
		}
		else
		{
			setVx(0);
		}
	}

	PhysicsObject::onUpdate(dt);
}

void Ryu::onCollision(MovableRect * other, float collisionTime, int nx, int ny)
{
	preventMovementOnCollision(collisionTime, nx, ny);
	PhysicsObject::onCollision(other, collisionTime, nx, ny);
}

Ryu::Ryu()
{
	setSprite(SPR(SPRITE_INFO_RYU));
	setCollisionType(CT_PLAYER);
	//setSimonState(SIMON_STATE_NORMAL);
}


Ryu::~Ryu()
{
}
