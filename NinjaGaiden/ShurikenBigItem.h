#pragma once
#include "Item.h"
class ShurikenBigItem :
	public Item
{
public:
	ShurikenBigItem();
	virtual void onInitFromFile(ifstream& fs, int mapHeight) override;
	void onContactPlayer() override;
};

