#include "StopWatch.h"
#include"ScoreBar.h"


StopWatch::StopWatch()
{
}

void StopWatch::onContactPlayer()
{
	ScoreBar::getInstance()->increaseScore(100);
}

StopWatch::~StopWatch()
{
}
