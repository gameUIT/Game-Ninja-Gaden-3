#include "Item2.h"
#include"ScoreBar.h"
#include"SpriteManager.h"


Item2::Item2()
{
	setSprite(SpriteManager::getSprite(SPRITE_ITEM_2));
}

void Item2::onContactPlayer()
{
	ScoreBar::getInstance()->increaseScore(100);
}

Item2::~Item2()
{
}
