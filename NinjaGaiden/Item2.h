#pragma once
#include "Item.h"
class Item2 :
	public Item
{
public:
	Item2();
	void onContactPlayer() override;
	~Item2();
};

