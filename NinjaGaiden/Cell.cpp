#include "Cell.h"
#include "Camera.h"
#include "Collision.h"

List<BaseObject*> Cell::getObjects()
{
	return objects;
}

void Cell::add(BaseObject* object)
{
	objects._Add(object);
}

void Cell::clear()
{
	objects.Clear();
}

Cell::Cell()
{
}

Cell::~Cell()
{
}