#include "MoneyBagBlue.h"
#include"ScoreBar.h"


MoneyBagBlue::MoneyBagBlue()
{
}

void MoneyBagBlue::onContactPlayer()
{
	ScoreBar::getInstance()->increaseScore(100);
}

MoneyBagBlue::~MoneyBagBlue()
{
}
