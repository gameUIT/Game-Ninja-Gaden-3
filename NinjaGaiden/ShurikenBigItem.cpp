#include "ShurikenBigItem.h"
#include"SpriteManager.h"
#include"ScoreBar.h"
#include"Ryu.h"
ShurikenBigItem::ShurikenBigItem()
{
}

void ShurikenBigItem::onInitFromFile(ifstream & fs, int mapHeight)
{
	Item::onInitFromFile(fs, mapHeight);
	setSprite(SpriteManager::getSprite(SPRITE_MISC));
	setAnimation(MISC_SPRITE_ID_SHURIKEN_BIG);
}

void ShurikenBigItem::onContactPlayer()
{
	ScoreBar::getInstance()->enableSubweapon();
	Ryu::getInstance()->isBigShuriken = true;
}
