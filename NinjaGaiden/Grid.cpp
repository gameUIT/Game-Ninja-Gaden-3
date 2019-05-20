#include "Grid.h"
#include "Camera.h"
#include <algorithm>
#include <iterator>



Grid * Grid::instance = NULL;
Grid * Grid::getInstance()
{
	if (instance == NULL) instance = new Grid();
	return instance;
}



Grid::Grid()
{
	widthLevel1 = 3584;
	heightLevel1 = 432;
	cellWidth = 112;
	cellHeight = 54;
	rowCells = 8;
	columnCells = 32;

	gridData = new Cell*[rowCells];
	for (int rowIndex = 0; rowIndex < rowCells; rowIndex++)
	{
		gridData[rowIndex] = new Cell[columnCells];
	}
}


void Grid::addObjectToGrid(BaseObject * object)
{
	int beginCol = object->getX() / cellWidth;
	int endCol = (object->getX() + object->getWidth()) / cellWidth;
	int beginRow = (object->getY() - object->getHeight()) / cellHeight;
	int endRow = object->getY() / cellHeight;

	if (beginCol == endCol || (endCol - beginCol == 1))
		gridData[beginRow][beginCol].add(object);
	else {
		//Xử lý cho cầu thang dài
		for (int i = beginRow; i <= endRow; i++) {
			for (int j = beginCol; j <= endCol; j++)
			{
				gridData[i][j].add(object);
			}
		}
	}
}

vector<BaseObject*> Grid::getAllObjectsInActiveCells()
{
	Camera* CAMERA = Camera::getInstance();
	vector<BaseObject*> result;
	int beginCol = CAMERA->getX() / cellWidth;
	int endCol = (CAMERA->getX() + CAMERA->getWidth()) / cellWidth;
	int beginRow = (CAMERA->getY() - CAMERA->getHeight()) / cellHeight;
	int endRow = CAMERA->getY() / cellHeight;
	for (int i = beginRow; i <= endRow; i++) {
		for (int j = beginCol; j <= endCol; j++)
		{
			vector<BaseObject*> b = gridData[i][j].getObjects();
			//DebugOut((wchar_t*)L"%d \n", b.size());
			result.insert(std::end(result), std::begin(b), std::end(b));
		}
	}
	return result;
}

vector<BaseObject*> Grid::getAllObjectsHaveToWork()
{
	Camera* CAMERA = Camera::getInstance();
	vector<BaseObject*> allObjectsInActiveCells = this->getAllObjectsInActiveCells();

	//Đầu tiên loại bỏ những object đã đi ra ngoài camera ra ra khỏi allObjectsHaveToWork
	//và đặt lại vị trí ban đầu cho nó
	for (int i = 0; i < allObjectsHaveToWork.size(); i++) {
		int x = allObjectsHaveToWork[i]->getX();
		int y = allObjectsHaveToWork[i]->getY();
		int initX = allObjectsHaveToWork[i]->getInitBox()->getX();
		int initY = allObjectsHaveToWork[i]->getInitBox()->getY();
		//int initX = allObjectsHaveToWork[i]->getInitX();
		//int initY = allObjectsHaveToWork[i]->getInitY();

		if (
			(x < (CAMERA->getX() - 20) || x >(CAMERA->getRight() + 20) || y > (CAMERA->getY() + 20) || y < (CAMERA->getBottom() - 20))
			&&
			(initX <= CAMERA->getX() - 20 || initX >= (CAMERA->getRight() + 20) || initY > (CAMERA->getY() + 20) || initY < (CAMERA->getBottom() - 20))
			) {
			//allObjectsHaveToWork[i]->onReborn();
			allObjectsHaveToWork.erase(allObjectsHaveToWork.begin() + i);
		}
	}

	vector<BaseObject*> newObjects;
	//So sánh và lấy ra nhưng object nằm trong allObjectsInActiveCells
	//nhưng không nằm trong allObjectsHaveToWork và bỏ vào newObjects
	//Sắp xếp
	std::sort(allObjectsInActiveCells.begin(), allObjectsInActiveCells.end());
	std::sort(allObjectsHaveToWork.begin(), allObjectsHaveToWork.end());
	//Xóa những element trùng nhau
	allObjectsInActiveCells.erase(std::unique(allObjectsInActiveCells.begin(), allObjectsInActiveCells.end()), allObjectsInActiveCells.end());
	allObjectsHaveToWork.erase(std::unique(allObjectsHaveToWork.begin(), allObjectsHaveToWork.end()), allObjectsHaveToWork.end());
	//Kiểm tra sự khác nhau
	std::set_difference(allObjectsInActiveCells.begin(), allObjectsInActiveCells.end(),
		allObjectsHaveToWork.begin(), allObjectsHaveToWork.end(),
		std::back_inserter(newObjects));

	//Add newObjects vào allObjectsHaveToWork
	allObjectsHaveToWork.insert(std::end(allObjectsHaveToWork), std::begin(newObjects), std::end(newObjects));

	return allObjectsHaveToWork;
}

Grid::~Grid()
{

}
