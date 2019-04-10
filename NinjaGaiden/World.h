#pragma once
#include"Tilemap.h"
#include"SpriteManager.h"
#include"BaseObject.h"
#include"CollisionTypeCollide.h"
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

public:
	void Init(
		const char* tilesheetPath, 
		const char* matrixPath, 
		const char* objectsPath,
		const char* collisionTypeCollidePath);
	void Init(const char* folderPath);
	/* cập nhật các đối tượng trong game */
	void update(float dt);
	/* vẽ các đối tượng trong game */
	void render();
	World();
	~World();
};

