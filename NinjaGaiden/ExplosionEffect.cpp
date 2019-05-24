#include "ExplosionEffect.h"
#include"SpriteManager.h"
ExplosionEffect::ExplosionEffect()
{
	setSprite(SpriteManager::getInstance()->getSprite(SPRITE_EXPLOSION));
	setDirection(RIGHT);
	animationGameTime.init(50);
	
}

void ExplosionEffect::onUpdate(float dt)
{
	if (getIsLastFrameAnimationDone())
	{
		removed = true;
		setRenderActive(false);
	}
}

void ExplosionEffect::render(Camera* camera)
{
	RunTimeObject::render(camera);
}
