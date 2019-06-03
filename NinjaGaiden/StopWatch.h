#pragma once
#include "Item.h"
class StopWatch :
	public Item
{
public:
	StopWatch();
	void onContactPlayer() override;
	~StopWatch();
};

