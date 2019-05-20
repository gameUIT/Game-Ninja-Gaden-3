#include "Cell.h"



vector<BaseObject*> Cell::getObjects()
{
	return this->objects;
}

void Cell::add(BaseObject * object)
{
	objects.push_back(object);
}

Cell::Cell()
{
}


Cell::~Cell()
{
}
