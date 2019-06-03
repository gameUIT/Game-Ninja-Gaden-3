#pragma once
#include "Item.h"
class Fire :
	public Item
{
public:
	Fire();

	void onContactPlayer() override;

	~Fire();
};

