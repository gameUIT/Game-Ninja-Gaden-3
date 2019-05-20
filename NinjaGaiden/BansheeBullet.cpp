#include "BansheeBullet.h"
#include"SpriteManager.h"


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

void BansheeBullet::render(Camera * camera)
{
	RunTimeObject::render(camera);
}
