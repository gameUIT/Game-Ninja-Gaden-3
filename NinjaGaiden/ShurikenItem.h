#pragma once
#include "Item.h"
class ShurikenItem :
	public Item
{
public:
	ShurikenItem();
	void onContactPlayer() override;
};

