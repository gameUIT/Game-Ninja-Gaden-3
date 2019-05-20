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
	/* dùng tilemap để vẽ map */
	Tilemap tilemap;

	/* tất cả object có trong world */
	List<BaseObject*> allObjects;

	/* danh sách collisionTypeCollide */
	List<CollisionTypeCollide*> collisionTypeCollides;

	/* danh sách object được phân loại theo collision_type */
	List<List<BaseObject*>*> objectCategories;

	/* danh sách spaces trong world */
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

	/* cập nhật các đối tượng trong game */
	void update(float dt);

	/* vẽ các đối tượng trong game */
	void render();

	void setCurrentSpace(int spaceIndex);

	Space* getCurrentSpace();

	/* reset vị trí camera & ryu trong space */
	void resetLocationInSpace();

	World();
	~World();
};

