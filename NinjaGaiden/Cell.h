#pragma once
#include "Rect.h"
#include"BaseObject.h"

class Cell :
	public Rect
{
	List<BaseObject*> objects;
public:
	List<BaseObject*> getObjects();
	void add(BaseObject* object);
	void clear();
	Cell();
	~Cell();
};
