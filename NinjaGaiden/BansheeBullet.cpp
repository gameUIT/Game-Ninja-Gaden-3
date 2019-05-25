#include "BansheeBullet.h"
#include"SpriteManager.h"
#include"Ryu.h"


void BansheeBullet::onCollision(MovableRect * other, float collisionTime, int nx, int ny)
{
}

BansheeBullet::BansheeBullet()
{
	setSprite(SpriteManager::getSprite(SPRITE_INFO_BANSHEE_WEAPON));
	setWidth(8);
	setHeight(15);
}


BansheeBullet::~BansheeBullet()
{

}

void BansheeBullet::onUpdate(float dt)
{
	RunTimeObject::onUpdate(dt);
}

void BansheeBullet::onIntersect(MovableRect * other)
{
	if (other->getCollisionType() == CT_PLAYER)
	{
		Ryu* ryu = Ryu::getInstance();
		ryu->blinkDelay.start();
		ryu->setVy(GLOBALS_D("player_hit_vy"));
	}
}

void BansheeBullet::render(Camera * camera)
{
	RunTimeObject::render(camera);
}
