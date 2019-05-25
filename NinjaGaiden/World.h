#pragma once
#include"Tilemap.h"
#include"SpriteManager.h"
#include"BaseObject.h"
#include"CollisionTypeCollide.h"
#include"Space.h"

enum WORLD_STATE
{
	WORLD_STATE_PAUSE,
	WORLD_STATE_RUN
};

class World
{
	Tilemap tilemap;
	List<BaseObject*> allObjects;
	List<CollisionTypeCollide*> collisionTypeCollides;
	List<List<BaseObject*>*> objectCategories;

	List<Space*> spaces;
	Space* currentSpace;

	static World* instance;

public:
	WORLD_STATE worldState;
	static World* getInstance();
	void Init(
		const char* tilesheetPath,
		const char* matrixPath,
		const char* objectsPath,
		const char* collisionTypeCollidePath,
		const char* spacePath);
	void Init(const char* folderPath);

	void update(float dt);

	void render();

	void setCurrentSpace(int spaceIndex);

	Space* getCurrentSpace();

	/* reset vị trí camera & ryu trong space */
	void resetLocationInSpace();

	World();
	~World();
};

