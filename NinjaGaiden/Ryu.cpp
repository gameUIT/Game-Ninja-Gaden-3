#include "Ryu.h"
#include"SwordRObject.h"
#include"World.h"
#include"Camera.h"
#include"Collision.h"
#include"Enemy.h"
#include"ScoreBar.h"

Ryu * Ryu::instance = 0;
Ryu * Ryu::getInstance()
{
	if (instance == 0)
	{
		instance = new Ryu();
	}
	return instance;
}

Ryu::Ryu()
{
	setDirection(RIGHT);
	setSprite(SPR(SPRITE_INFO_RYU));
	setCollisionType(CT_PLAYER);
	setState(RYU_STATE_NORMAL);
	canSitDown = true;
	blinkTime.setDeltaTime(GLOBALS_D("player_blink_time"));
	blinkDelay.init(GLOBALS_D("player_blink_delay"));
	invisibleDelay.init(GLOBALS_D("player_invisible_delay"));
	invisibleTime.init(GLOBALS_D("player_invisible_time"));
	isHit = false;
}

void Ryu::onUpdate(float dt)
{
	if (this->getTop() < Camera::getInstance()->getBottom())
	{
		restoreLocation();
		Camera::getInstance()->setX(World::getInstance()->getCurrentSpace()->CameraX);
		Camera::getInstance()->setY(World::getInstance()->getCurrentSpace()->CameraY);
		return;
	}

	blinkDelay.update();
	if (blinkDelay.isOnTime())
	{
		if (invisibleTime.atTime())
		{
			setRenderActive(true);
		}
		else
		{
			setRenderActive(false);
		}
	}
	if (blinkDelay.isTerminated())
	{
		setRenderActive(true);
	}
	if (isHit)
	{
		PhysicsObject::onUpdate(dt);
		if (getIsGrounded())
		{
			isHit = false;
		}
		else
		{
			return;
		}
	}




	KEY* key = KEY::getInstance();
	bool keyLeftDown, keyRightDown, keyUpDown, keyDownDown, keyJumpPress, keyAttackPress;
	float vx = GLOBALS_D("player_vx");
	float vy = GLOBALS_D("player_vy_jump");

	keyLeftDown = key->isLeftDown;
	keyRightDown = key->isRightDown;
	keyUpDown = key->isUpDown;
	keyDownDown = key->isDownDown;
	keyJumpPress = key->isJumpPress;
	keyAttackPress = key->isAttackPress;

	switch (state)
	{
	case RYU_STATE_NORMAL:
		if (getIsGrounded())
		{
			setCanSitDown(true);

			if (keyLeftDown)
			{
				setAnimation(RYU_ANIMATION_RUN);
				setVx(getDirection() * vx);
				setDirection(LEFT);

				if (keyDownDown)
				{
					setState(RYU_STATE_SIT);
				}
				else if (keyAttackPress)
				{
					createNewSword();

					setState(RYU_STATE_ATTACK);
				}
			}
			else if (keyRightDown)
			{
				setAnimation(RYU_ANIMATION_RUN);
				setVx(getDirection() * vx);
				setDirection(RIGHT);

				if (keyDownDown)
				{
					setState(RYU_STATE_SIT);
				}
				else if (keyAttackPress)
				{
					createNewSword();

					setState(RYU_STATE_ATTACK);

				}  
			}
			else if (keyDownDown)
			{
				setState(RYU_STATE_SIT);
			}
			else if (keyAttackPress)
			{
				createNewSword();

				setState(RYU_STATE_ATTACK);
			}
			else
			{
				setAnimation(RYU_ANIMATION_STAND);
				setVx(0);
			}
			if (keyJumpPress)
			{
				setVy(vy);
			}
		}
		else /* Nhân vật đang lơ lửng trên không */
		{

			if (keyLeftDown)
			{
				setDirection(LEFT);
				setVx(getDirection() * vx);
			}
			else if (keyRightDown)
			{
				setDirection(RIGHT);
				setVx(getDirection() * vx);
			}

			if (getAnimation() == RYU_ANIMATION_ATTACK_JUMP)
			{
				if (getIsLastFrameAnimationDone())
				{
					setAnimation(RYU_ANIMATION_JUMP);
				}
			}
			else
			{
				setAnimation(RYU_ANIMATION_JUMP);
			}

			if (keyAttackPress)
			{
				setAnimation(RYU_ANIMATION_ATTACK_JUMP);
				createNewSword();
				//setState(RYU_STATE_ATTACK);
				//setAnimation(RYU_ANIMATION_ATTACK_JUMP);
			}
		}

		PhysicsObject::onUpdate(dt);
		break;
	case RYU_STATE_RUN:
		break;
	case RYU_STATE_SIT:
		setVx(0);
		setDx(0);
		setIsSitting(true);
		setAnimation(RYU_ANIMATION_SIT);

		if (!keyDownDown)
		{
			setIsSitting(false);
			setState(RYU_STATE_NORMAL);
		}
		else if (keyAttackPress)
		{
			createNewSword();
			setState(RYU_STATE_ATTACK);
		}

		PhysicsObject::onUpdate(dt);
		break;
	case RYU_STATE_JUMP:

		PhysicsObject::onUpdate(dt);
		break;
	case RYU_STATE_CLIMBING:
		break;
	case RYU_STATE_ATTACK:
		if (getIsGrounded())
		{
			setDx(0);
			setVx(0);
			if (isSitting)
			{
				switch (getDirection())
				{
				case RIGHT:
					setAnimation(RYU_ANIMATION_ATTACK_SIT_RIGHT);

					if (getIsLastFrameAnimationDone())
					{
						setState(RYU_STATE_SIT);
						setAnimation(RYU_ANIMATION_SIT);
					}
					break;
				case LEFT:
					setAnimation(RYU_ANIMATION_ATTACK_SIT_LEFT);

					if (getIsLastFrameAnimationDone())
					{
						setState(RYU_STATE_SIT);
						setAnimation(RYU_ANIMATION_SIT);
					}
					break;
				default:
					break;
				}

				//setAnimation(RYU_ANIMATION_ATTACK_SIT_RIGHT);

				//if (getIsLastFrameAnimationDone())
				//{
				//	setState(RYU_STATE_SIT);
				//	setAnimation(RYU_ANIMATION_SIT);
				//}
			}
			else
			{
				setDx(0);
				setVx(0);

				switch (getDirection())
				{
				case RIGHT:
					setAnimation(RYU_ANIMATION_ATTACK_STAND_RIGHT);

					if (getIsLastFrameAnimationDone())
					{
						setState(RYU_STATE_NORMAL);
						setAnimation(RYU_ANIMATION_STAND);
					}
					break;
				case LEFT:
					setAnimation(RYU_ANIMATION_ATTACK_STAND_LEFT);

					if (getIsLastFrameAnimationDone())
					{
						setState(RYU_STATE_NORMAL);
						setAnimation(RYU_ANIMATION_STAND);
					}
					break;
				default:
					setAnimation(RYU_ANIMATION_ATTACK_STAND_RIGHT);

					if (getIsLastFrameAnimationDone())
					{
						setState(RYU_STATE_NORMAL);
						setAnimation(RYU_ANIMATION_STAND);
					}
					break;
				}

				//setAnimation(RYU_ANIMATION_ATTACK_STAND);

				//if (getIsLastFrameAnimationDone())
				//{
				//	setState(RYU_STATE_NORMAL);
				//	setAnimation(RYU_ANIMATION_STAND);
				//}
			}
		}
		else /* ryu đang nhảy */
		{
			//setVx(getDirection() * vx);
			setAnimation(RYU_ANIMATION_ATTACK_JUMP);

			//if (getIsLastFrameAnimationDone())
			//{
			//	setState(RYU_STATE_NORMAL);
			//	setAnimation(RYU_ANIMATION_JUMP);
			//}
		}

		PhysicsObject::onUpdate(dt);
		break;
	default:
		break;
	}

	PhysicsObject::onUpdate(dt);
}

void Ryu::onCollision(MovableRect * other, float collisionTime, int nx, int ny)
{
	if (other->getCollisionType() == CT_GROUND)
	{
		PhysicsObject::onCollision(other, collisionTime, nx, ny);
		preventMovementOnCollision(collisionTime, nx, ny);
		if (ny == 1)
		{
			isHit = false;
		}
	}

}

void Ryu::onIntersect(MovableRect* other)
{
	if (other->getCollisionType() == CT_ENEMY && !blinkDelay.isOnTime() && ((Enemy*)other)->getRenderActive())
	{
		blinkDelay.start();
		isHit = true;
		setVy(GLOBALS_D("player_hit_vy"));
		setVx(-getDirection() * GLOBALS_D("player_hit_vx"));
		ScoreBar::getInstance()->setHealth(ScoreBar::getInstance()->getHealth() - 1);
	}
}

void Ryu::setIsSitting(bool isSitting)
{
	this->isSitting = isSitting;
}

void Ryu::createNewSword()
{
	auto sword = new SwordRObject();
	if (getDirection() == RIGHT)
	{
		sword->setX(getRight());
	}
	else
	{
		sword->setX(getleft() - 10);
	}

	sword->setY(getTop() + 10);
	//sword->setY(getMidY());
	sword->setWidth(24);
	sword->setHeight(30);
}

void Ryu::setCanSitDown(bool canSitDown)
{
	this->canSitDown = canSitDown;
}

bool Ryu::getCanSitDown()
{
	return this->canSitDown;
}

RYU_STATE Ryu::getState()
{
	return this->state;
}

void Ryu::setState(RYU_STATE state)
{
	this->state = state;
}

Ryu::~Ryu()
{
}
