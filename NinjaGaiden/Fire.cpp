#include "Fire.h"
#include"ScoreBar.h"



Fire::Fire()
{
}

void Fire::onContactPlayer()
{
	ScoreBar::getInstance()->increaseScore(100);
}

Fire::~Fire()
{
}
