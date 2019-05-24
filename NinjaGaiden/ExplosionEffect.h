#pragma once
#include "RunTimeObject.h"
class ExplosionEffect :
	public RunTimeObject
{
public:
	ExplosionEffect();
	void onUpdate(float dt) override;
	void render(Camera* camera) override;
};

