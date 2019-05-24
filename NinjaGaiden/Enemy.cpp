#include"Enemy.h"
#include"Ryu.h"
#include"Collision.h"
#include"RunTimeObject.h"
#include"ExplosionEffect.h"

Enemy::Enemy()
{
	setHealth(1);
}

void Enemy::setDirectionFollowPlayer()
{
	if (Ryu::getInstance()->getMidX() - getMidX() < 0)
	{
		setDirection(LEFT);
	}
	else
	{
		setDirection(RIGHT);
	}
}

void Enemy::onUpdate(float dt)
{
	Ryu* ryu = Ryu::getInstance();
	if (Collision::AABBCheck(this, ryu))
	{
		onIntersect(ryu);
	}

	PhysicsObject::onUpdate(dt);
}

void Enemy::onCollision(MovableRect* other, float collisionTime, int nx, int ny)
{
	Ryu* ryu = Ryu::getInstance();
	if (other == ryu)
	{
		return;
	}
	preventMovementOnCollision(collisionTime, nx, ny);
	PhysicsObject::onCollision(other, collisionTime, nx, ny);

	//if (other->getCollisionType() == CT_GROUND)
	//{
	//	preventMovementOnCollision(collisionTime, nx, ny);
	//	PhysicsObject::onCollision(other, collisionTime, nx, ny);
	//}

	//if (other->getCollisionType() == CT_PLAYER)
	//{
	//	onIntersect(other);
	//}
}

void Enemy::onIntersect(MovableRect * other)
{
	/* Xử lí khi enemy va chạm với simon */
	Ryu* ryu = Ryu::getInstance();
	if (other == ryu && !ryu->blinkDelay.isOnTime() && canAttackPlayer() && !ryu->isDead)
	{
		onCollisionWithPlayer();
		//ScoreBar::getInstance()->increaseHealth(-1);
		//if (ScoreBar::getInstance()->getHealth() <= 0)
		//{
		//	simon->isDead = true;
		//	simon->deadDelay.start();
		//}
	}

	if (other->getCollisionType() == CT_WEAPON && getRenderActive())
	{
		//restoreLocation();
		setRenderActive(false);
		auto effect = new ExplosionEffect();
		effect->setX(getMidX());
		effect->setY(getMidY());
	}

	//if (other->getCollisionType() == CT_WEAPON)
	//{
	//	((MorningStarAttack*)other)->setNeedDelete(true);
	//	onContactWeapon();
	//}
}

void Enemy::restoreLocation()
{
	setHealth(1);
	BaseObject::restoreLocation();
}

void Enemy::onDeath()
{
}

void Enemy::onDecreaseHealth()
{
}

void Enemy::onCollisionWithPlayer()
{
	Ryu* ryu = Ryu::getInstance();
	Camera* camera = Camera::getInstance();
	ryu->blinkDelay.start();
	ryu->setVy(GLOBALS_D("player_hit_vy"));
	//ryu->setVx(-(getDirection() * GLOBALS_D("player_hit_vx")));

	//ryu->blinkDelay.setIsTerminated(true);

	//if (!ryu->getIsOnStair())
	//{
	//	player->setAnimation(SIMON_ACTION_HURT);
	//	player->setIsOnGround(false);
	//	player->setDy(0);
	//	if (player->getX() > this->getX())
	//	{
	//		player->setVx(GLOBALS_D("player_hit_vx"));
	//	}
	//	else
	//	{
	//		player->setVx(-GLOBALS_D("player_hit_vx"));
	//	}
	//}
}

void Enemy::setHealth(int health)
{
	this->health = health;
}

int Enemy::getHealth()
{
	return health;
}

void Enemy::onCollisionWithWeapon()
{
	setHealth(getHealth() - 1);
	onDecreaseHealth();
	if (getHealth() <= 0)
	{
		this->setIsAlive(false);
		onDeath();
	}
}

bool Enemy::canAttackPlayer()
{
	return this->getRenderActive();
}

Enemy::~Enemy()
{
}
