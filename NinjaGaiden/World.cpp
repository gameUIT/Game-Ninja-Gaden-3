#include"World.h"
#include"Camera.h"
#include"Ryu.h"
#include"KEY.h"
#include"Collision.h"

void World::Init(const char * tilesheetPath, const char * matrixPath, const char * objectsPath)
{
	/* khởi tạo vị trí player */
	Ryu::getInstance()->set(52, 100, 16, 30);

	/* khởi tạo tilemap */
	tilemap.Init(tilesheetPath, matrixPath);

	int worldHeight = tilemap.getWorldHeight();

	/* khởi tạo đối tượng */
	int objectCount;
	ifstream fs(objectsPath);
	fs >> objectCount;
	for (size_t i = 0; i < objectCount; i++)
	{
		BaseObject* obj;
		int id;
		/* đọc id đối tượng */
		fs >> id;
		switch (id)
		{
			
		default:
			obj = new BaseObject();
			break;
		}
		/* đọc thông số của đối tượng */
		obj->onInitFromFile(fs, worldHeight);
		if (id >= 0)
		{
			/* nếu id đối tượng không âm tức đối tượng có sprite ta gán sprite cho nó */
			obj->setSprite(SPR(id));
		}
		/* thêm đối tượng vào danh sách */
		allObjects._Add(obj);
	}
}

void World::Init(const char * folderPath)
{
	/* tìm đường dẫn tilesheet và matrix object */
	string folderPathString = (string)folderPath;
	string tilesheetString = folderPathString;
	tilesheetString.append("/tilesheet.png");
	string matrixPathString = folderPathString;
	matrixPathString.append("/matrix.dat");
	string objectPathString = folderPathString;
	objectPathString.append("/objects.dat");

	Init(tilesheetString.c_str(), matrixPathString.c_str(), objectPathString.c_str());
}

void World::update(float dt)
{
	/* cập nhật key */
	KEY::getInstance()->update();
	for (size_t i = 0; i < allObjects.Count; i++)
	{
		/* cập nhật đối tượng */
		allObjects[i]->update(dt);
		Collision::CheckCollision(Ryu::getInstance(), allObjects[i]);
	}
	Ryu::getInstance()->update(dt);
	Camera::getInstance()->update();
}	

void World::render()
{
	tilemap.render(Camera::getInstance());
	for (size_t i = 0; i < allObjects.Count; i++)
	{
		/* vẽ đối tượng */
		allObjects[i]->render(Camera::getInstance());
	}
	Ryu::getInstance()->render(Camera::getInstance());
}

World::World()
{
}
World::~World()
{
}
