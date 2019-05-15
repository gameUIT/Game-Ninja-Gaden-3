#include"World.h"
#include"Camera.h"
#include"Ryu.h"
#include"SwordMan.h"
#include"KEY.h"
#include"Collision.h"
#include"RunTimeObject.h"
#include"CollisionType.h"
#include"Banshee.h"
#include"Bat.h"
#include"Bird.h"
#include"Panther.h"
#include"Shooter.h"

void World::Init(
	const char* tilesheetPath,
	const char* matrixPath,
	const char* objectsPath,
	const char* collisionTypeCollidePath,
	const char* spacePath)
{
	/* khởi tạo vị trí player */
	Ryu::getInstance()->set(52, 100, 16, 30);

	/* khởi tạo tilemap */
	tilemap.Init(tilesheetPath, matrixPath);

	int worldHeight = tilemap.getWorldHeight();

	/* khởi tạo phân loại đối tượng */
	for (size_t i = 0; i < COLLISION_TYPE_COUNT; i++)
	{
		objectCategories._Add(new List<BaseObject*>());
	}

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

		case SPRITE_INFO_SWORDMAN:
			obj = new SwordMan();
			break;

		case SPRITE_INFO_BANSHEE:
			obj = new Banshee();
			break;

		case SPRITE_INFO_BAT:
			obj = new Bat();
			break;

		case SPRITE_INFO_BROWN_BIRD:
			obj = new Bird();
			break;

		case SPRITE_INFO_PANTHER:
			obj = new Panther();
			break;

		case SPRITE_INFO_SHOOTER:
			obj = new Shooter();
			break;

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

		/* thêm object vào từng loại đối tượng */
		objectCategories.at(obj->getCollisionType())->_Add(obj);
	}

	/* đọc collision type collide */
	int collisionTypeCollideCount = 0;
	ifstream fsColli(collisionTypeCollidePath);
	fsColli >> collisionTypeCollideCount;
	for (size_t i = 0; i < collisionTypeCollideCount; i++)
	{
		int collisionType1, collisionType2;
		fsColli >> collisionType1 >> collisionType2;
		CollisionTypeCollide* collisionTypeCollide = new CollisionTypeCollide();
		collisionTypeCollide->COLLISION_TYPE_1 = (COLLISION_TYPE)collisionType1;
		collisionTypeCollide->COLLISION_TYPE_2 = (COLLISION_TYPE)collisionType2;
		collisionTypeCollides._Add(collisionTypeCollide);
	}

	/* đọc space */
	int numberOfSpaces = 0;
	ifstream fsSpace(spacePath);
	/* enter 1 dòng */
	ignoreLineIfstream(fsSpace, 1);
	fsSpace >> numberOfSpaces;
	for (size_t i = 0; i < numberOfSpaces; i++)
	{
		/* enter 4 dòng */
		ignoreLineIfstream(fsSpace, 4);
		Space* space = new Space();
		fsSpace >> space->X >> space->Y >> space->Width >> space->Height;

		/* enter 2 dòng */
		ignoreLineIfstream(fsSpace, 2);
		fsSpace >> space->CameraX >> space->CameraY;

		/* enter 2 dòng */
		ignoreLineIfstream(fsSpace, 2);
		fsSpace >> space->PlayerX >> space->PlayerY;

		/* do chiều y của trong file định nghĩa ngược với chiều logic nên cần đổi lại */
		space->CameraY = worldHeight - space->CameraY;
		space->PlayerY = worldHeight - space->PlayerY;
		space->Y = worldHeight - space->Y;

		/* thêm vào space */
		spaces._Add(space);
	}

	/* bắt đầu từ space 0 */
	setCurrentSpace(0);
	resetLocationInSpace();
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

	string collisionTypeCollidePath = folderPathString;
	collisionTypeCollidePath.append("/collision_type_collides.dat");

	string spacePath = folderPathString;
	spacePath.append("/spaces.dat");

	Init(
		tilesheetString.c_str(),
		matrixPathString.c_str(),
		objectPathString.c_str(),
		collisionTypeCollidePath.c_str(),
		spacePath.c_str());
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
		Collision::CheckCollision(allObjects[i], Ryu::getInstance());
	}

	RunTimeObject::updateRuntimeObjects();

	auto runTimeObjects = RunTimeObject::getRunTimeObjects();

	auto enemies = objectCategories.at(COLLISION_TYPE::CT_ENEMY);

	for (int ir = 0; ir < runTimeObjects->Count; ir++)
	{
		auto runTimeObject = runTimeObjects->at(ir);
		for (int ie = 0; ie < enemies->Count; ie++)
		{
			auto enemy = enemies->at(ie);
			Collision::CheckCollision(runTimeObject, enemy);
		}
	}

	/* xét va chạm cho các loại đối tượng với nhau */
	for (size_t i = 0; i < collisionTypeCollides.size(); i++)
	{
		COLLISION_TYPE col1 = collisionTypeCollides.at(i)->COLLISION_TYPE_1;
		COLLISION_TYPE col2 = collisionTypeCollides.at(i)->COLLISION_TYPE_2;

		/* danh sách đối tượng thuộc collision type 1 */
		List<BaseObject*>* collection1 = objectCategories.at(col1);
		/* danh sách đối tượng thuộc collision type 2 */
		List<BaseObject*>* collection2 = objectCategories.at(col2);

		for (size_t i1 = 0; i1 < collection1->size(); i1++)
		{
			for (size_t i2 = 0; i2 < collection2->size(); i2++)
			{
				/* cho xét va chạm của đối tượng dựa vào 1 cặp collisionType trong CollisionTypeCollide */
				Collision::CheckCollision(collection1->at(i1), collection2->at(i2));
			}
		}
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

void World::setCurrentSpace(int spaceIndex)
{
	this->currentSpace = spaces.at(spaceIndex);
	Camera::getInstance()->setSpace(this->currentSpace);
}

Space * World::getCurrentSpace()
{
	return this->currentSpace;
}

void World::resetLocationInSpace()
{
	Camera* camera = Camera::getInstance();
	Ryu* ryu = Ryu::getInstance();

	camera->setLocation(getCurrentSpace()->CameraX, getCurrentSpace()->CameraY);
	ryu->setLocation(getCurrentSpace()->PlayerX, getCurrentSpace()->PlayerY);
}

World::World()
{
}
World::~World()
{
}
