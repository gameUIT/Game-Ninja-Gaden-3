#include "Game.h"
#include"ScoreBar.h"
#include"KEY.h"

Game * Game::instance = 0;
Game * Game::getInstance()
{
	if (instance == 0)
		instance = new Game();
	return instance;
}

/* Các câu lệnh khởi tạo game */
void Game::GameInit()
{


	Camera::getInstance()->setSize(
		GLOBALS_D("backbuffer_width"),
		GLOBALS_D("backbuffer_height"));

	world2 = new World();
	world2->Init("assets/levels/level3_2");

	world3 = new World();
	world3->Init("assets/levels/level_boss");

	world1 = new World();
	world1->Init("assets/levels/level3_1");

	world = world1;

}
/* Các câu lệnh cập nhật game */
void Game::GameUpdate(float dt)
{
	//if (KEY::getInstance()->isKeyMap1Down)
	//{
	//	world = world1;
	//	World::instance = world1;
	//	World::instance->setCurrentSpace(0);
	//	World::instance->resetLocationInSpace();
	//}
	if (KEY::getInstance()->isKeyMap2Down)
	{
		world = world2;
		World::instance = world2;
		World::instance->setCurrentSpace(0);
		World::instance->resetLocationInSpace();
	}
	if (KEY::getInstance()->isKeyMap3Down)
	{
		world = world3;
		World::instance = world3;
		World::instance->setCurrentSpace(0);
		World::instance->resetLocationInSpace();
	}
	/* cập nhật đối tượng trong world */
	world->update(dt);
	ScoreBar::getInstance()->update();

}
/* Các câu lệnh vẽ của game */
void Game::GameRender()
{
	/* vẽ đối tượng trong world */
	world->render();
	ScoreBar::getInstance()->render();
}

Game::Game()
{
}


Game::~Game()
{
}
