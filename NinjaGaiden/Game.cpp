#include "Game.h"


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
	/* khởi tạo tilemap */
	world = new World();
	world->Init("assets/levels/level3_1");

	Camera::getInstance()->setSize(
		GLOBALS_D("backbuffer_width"),
		GLOBALS_D("backbuffer_height"));

	//Camera::getInstance()->set(
	//	0,
	//	192, /* y camera */
	//	/* kích thước của camera bằng với kích thước của backbuffer */
		//GLOBALS_D("backbuffer_width"), 
		//GLOBALS_D("backbuffer_height"));
}
/* Các câu lệnh cập nhật game */
void Game::GameUpdate(float dt)
{
	/* cập nhật đối tượng trong world */
	world->update(dt);
}
/* Các câu lệnh vẽ của game */
void Game::GameRender()
{
	/* vẽ đối tượng trong world */
	world->render();
}

Game::Game()
{
}


Game::~Game()
{
}
