#include "MoneyBagRed.h"
#include"ScoreBar.h"



MoneyBagRed::MoneyBagRed()
{
}

void MoneyBagRed::onContactPlayer()
{
	ScoreBar::getInstance()->increaseScore(100);
}

MoneyBagRed::~MoneyBagRed()
{
}
