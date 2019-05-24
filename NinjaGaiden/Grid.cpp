﻿#include "Grid.h"
#include "Collision.h"


void Grid::Init(const char* gridPath)
{
	ifstream fsGrid(gridPath);
	int numberGridRect;
	float widthGirdRect, heightGridRect;
	fsGrid >> numberGridRect >> widthGirdRect >> heightGridRect;
	for (size_t i = 0; i < numberGridRect; i++)
	{
		float x, y;
		fsGrid >> x >> y;
		Cell* cell = new Cell();
		cell->set(x, y, widthGirdRect, heightGridRect);
		cells._Add(cell);
	}
}

void Grid::addObjectToGrid(BaseObject* object, int worldHeight)
{
	float objectXBottom = object->getX() + object->getWidth();
	float realYTop = worldHeight - object->getY();
	float objectYBottom = realYTop + object->getHeight();
	for (size_t j = 0; j < cells.Count; j++) {
		float rectXBottom = cells.at(j)->getX() + cells.at(j)->getWidth();
		float rectYBottom = cells.at(j)->getY() + cells.at(j)->getHeight();
		if ((object->getX() >= cells.at(j)->getX() && realYTop >= cells.at(j)->getY())
			&& ((objectXBottom <= rectXBottom && objectYBottom <= rectYBottom)
				|| (object->getX() < rectXBottom && object->getY() < rectYBottom))
			)
		{
			cells.at(j)->add(object);
			break;
		}
	}
}

List<BaseObject*> Grid::getCollisionObjects()
{
	objectCategories.Clear();
	for (size_t i = 0; i < COLLISION_TYPE_COUNT; i++)
	{
		objectCategories._Add(new List<BaseObject*>());
	}
	List<BaseObject*> collisionObjects;
	for (size_t i = 0; i < cells.Count; i++)
	{
		if (Collision::AABBCheck(cells.at(i), Camera::getInstance()))
		{
			for (size_t j = 0; j < cells.at(i)->getObjects().Count; j++)
			{
				collisionObjects._Add(cells.at(i)->getObjects().at(j));
				objectCategories.at(cells.at(i)->getObjects().at(j)->getCollisionType())->_Add(cells.at(i)->getObjects().at(j));
				objectCategories.at(CT_ALL)->_Add(cells.at(i)->getObjects().at(j));
				
			}
		}
	}
	return collisionObjects;
}

List<List<BaseObject*>*> Grid::getObjectCategories()
{
	return objectCategories;
}

void Grid::clearCells()
{
	for (size_t i = 0; i < cells.Count; i++)
	{
		cells.at(i)->clear();
	}
}

Grid::Grid()
{
}

Grid::~Grid()
{
}