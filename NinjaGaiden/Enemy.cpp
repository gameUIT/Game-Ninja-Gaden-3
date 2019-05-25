#include"Enemy.h"
#include"Ryu.h"
#include"Collision.h"
#include"RunTimeObject.h"
#include"ExplosionEffect.h"
#include"ScoreBar.h"

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

	//if (this->getTop() < Camera::getInstance()->getBottom() && (abs(this->getInitBox()->getX() - this->getX() >= 350)))
	//{
	//	setRenderActive(false);
	//	setIsAlive(false);
	//	restoreLocation();
	//}

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
	}

	if (other->getCollisionType() == CT_WEAPON && getRenderActive())
	{
		//setRenderActive(false);
		setIsAlive(false);
		auto effect = new ExplosionEffect();
		effect->setX(getMidX());
		effect->setY(getMidY());

		ScoreBar::getInstance()->setScore(ScoreBar::getInstance()->getScore() + 100);
	}
}

void Enemy::restoreLocation()
{
	setIsAlive(true);
	setRenderActive(true);
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

	ScoreBar::getInstance()->setHealth(ScoreBar::getInstance()->getHealth() - 1);
	if (ScoreBar::getInstance()->getHealth() <= 0)
	{
		ryu->isDead = true;
		//ryu->deadDelay.start();
	}

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
