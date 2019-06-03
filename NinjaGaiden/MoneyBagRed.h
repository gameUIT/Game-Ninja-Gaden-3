#pragma once
#include "Item.h"
class MoneyBagRed :
	public Item
{
public:
	MoneyBagRed();
	void onContactPlayer() override;
	~MoneyBagRed();
};

