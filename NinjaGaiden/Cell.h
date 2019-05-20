#pragma once
#include <vector>
#include <iostream>
#include "BaseObject.h"

using namespace std;

class Cell
{
	vector<BaseObject*> objects;
public:
	vector<BaseObject*> getObjects();
	void add(BaseObject* object);
	Cell();
	~Cell();
};

