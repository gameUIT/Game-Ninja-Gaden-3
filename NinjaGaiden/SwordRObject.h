#pragma once
#include"RunTimeObject.h"
class SwordRObject :
	public RunTimeObject
{
public:

	void onIntersect(MovableRect* other) override;

	SwordRObject();
	~SwordRObject();
};

