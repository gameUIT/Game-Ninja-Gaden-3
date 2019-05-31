#include "ShurikenItem.h"
#include"SpriteManager.h"
#include"ScoreBar.h"
ShurikenItem::ShurikenItem()
{
	setSprite(SpriteManager::getSprite(SPRITE_MISC));
	setAnimation(MISC_SPRITE_ID_SHURIKEN_BIG);
}

void ShurikenItem::onContactPlayer()
{
	ScoreBar::getInstance()->enableSubweapon();
}
