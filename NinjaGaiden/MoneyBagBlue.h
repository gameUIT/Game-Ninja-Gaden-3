#pragma once
#include "Item.h"
class MoneyBagBlue :
	public Item
{
public:
	MoneyBagBlue();
	void onContactPlayer() override;
	~MoneyBagBlue();
};

