#pragma once
#include "Cell.h"

class Grid
{
	List<Cell*> cells;
	List<List<BaseObject*>*> objectCategories;
public:
	void addObjectToGrid(BaseObject* object, int worldHeight);
	List<BaseObject*> getCollisionObjects();
	List<List<BaseObject*>*> getObjectCategories();
	void Init(const char* gridPath);
	void clearCells();
	Grid();
	~Grid();
};


