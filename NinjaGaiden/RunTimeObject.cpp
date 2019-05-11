#include "RunTimeObject.h"
#include"Collision.h"
#include"Camera.h"

List<RunTimeObject*>* RunTimeObject::runTimeObjects = 0;
List<RunTimeObject*>* RunTimeObject::getRunTimeObjects()
{
	if (runTimeObjects == 0)
	{
		runTimeObjects = new List<RunTimeObject*>();
	}
	return runTimeObjects;
}

void RunTimeObject::updateRuntimeObjects()
{
	auto objs = getRunTimeObjects();
	for (int i = 0; i < objs->Count; i++)
	{
		auto obj = objs->at(i);
		if (!Collision::AABBCheck(Camera::getInstance(), obj))
		{
			obj->remove();
		}

		if (obj->removed)
		{
			getRunTimeObjects()->_Remove(obj);
			delete obj;
			i--;
		}
	}
}

void RunTimeObject::remove()
{
	removed = true;

}

RunTimeObject::RunTimeObject()
{
	getRunTimeObjects()->_Add(this);
	removed = false;
}


RunTimeObject::~RunTimeObject()
{
}
