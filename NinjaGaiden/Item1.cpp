#include "Item1.h"
#include"ScoreBar.h"

void Item1::onContactPlayer()
{
	ScoreBar::getInstance()->increaseScore(100);
}
