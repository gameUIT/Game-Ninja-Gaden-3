#pragma once
#include "Cell.h"

class Grid
{
	int widthLevel1, heightLevel1;
	int rowCells, columnCells;
	int cellWidth, cellHeight;
	Cell** gridData;
	vector<BaseObject*> allObjectsHaveToWork;
	static Grid* instance;

public:
	static Grid* getInstance();
	void addObjectToGrid(BaseObject* object);
	vector<BaseObject*> getAllObjectsInActiveCells();
	//Hàm này đóng vai trò là bao chứa các object đã đang hoạt động trong camera và các object mới được camera quét qua
	vector<BaseObject*> getAllObjectsHaveToWork();
	Grid();
	~Grid();
};

