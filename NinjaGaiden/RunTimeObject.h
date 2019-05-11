#pragma once
#include"PhysicsObject.h"
#include"List.h"
class RunTimeObject :
	public PhysicsObject
{
	static List<RunTimeObject*>* runTimeObjects;
	bool removed;
public:
	static List<RunTimeObject*>* getRunTimeObjects();
	static void updateRuntimeObjects();
	void remove();
	RunTimeObject();
	~RunTimeObject();
};

