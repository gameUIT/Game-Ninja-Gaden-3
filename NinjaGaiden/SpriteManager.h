#pragma once

#include"List.h"
#include"Sprite.h"

/* khai báo 1 define viết tắt cho chữ SpriteManager::getSprite */
#define SPR SpriteManager::getSprite

/* ta tạo 1 sprite info để lưu thông tin của các sprite */
enum SPRITE_INFO
{
	/* đối tượng không có hình ảnh ta sẽ đặt số âm */
	SPRITE_INFO_GROUND = -1,

	/* đối tượng có hình ảnh ta sẽ đặt số dương */
	SPRITE_INFO_RYU = 0,
	SPRITE_INFO_SWORDMAN = 1,
	SPRITE_INFO_PANTHER = 2,
	SPRITE_INFO_BAT = 3,
	SPRITE_INFO_BROWN_BIRD = 4,
	SPRITE_INFO_BANSHEE = 5,
	SPRITE_INFO_SHOOTER = 7,
	SPRITE_INFO_BANSHEE_WEAPON = 8,
	SPRITE_INFO_SHOOTER_WEAPON = 9,

	SPRITE_COUNT
};

class SpriteManager
{
	/* ta lưu tất cả sprite ở đây */
	List<Sprite*> sprites;

	/* singleton pattern */
	static SpriteManager* instance;
public:
	static SpriteManager* getInstance();

	/* dùng để lấy sprite từ spriteManager */
	static Sprite* getSprite(int spriteInfo);

	SpriteManager();
	~SpriteManager();
};

