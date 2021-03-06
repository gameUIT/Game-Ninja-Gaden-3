#include "SpriteManager.h"
SpriteManager * SpriteManager::instance = 0;
SpriteManager * SpriteManager::getInstance()
{
	if (instance == 0)
	{
		instance = new SpriteManager();
	}
	return instance;
}
Sprite * SpriteManager::getSprite(int spriteInfo)
{
	return getInstance()->sprites[spriteInfo];
}
SpriteManager::SpriteManager()
{
	/* thêm SPRITE_COUNT phần tử cho list sprite */
	for (size_t i = 0; i < SPRITE_COUNT; i++)
	{
		sprites._Add(new Sprite());
	}

	/* sprite của sword man */
	sprites[SPRITE_INFO_SWORDMAN]->InitFromFile("assets/sprites/enemies/swordman/image.png", "assets/sprites/enemies/swordman/swordman.info.dat");
	sprites[SPRITE_INFO_SWORDMAN]->image->direction = RIGHT;

	/* sprite của panther */
	sprites[SPRITE_INFO_PANTHER]->InitFromFile("assets/sprites/enemies/panther/image.png", "assets/sprites/enemies/panther/panther.info.dat");
	sprites[SPRITE_INFO_PANTHER]->image->direction = RIGHT;

	/* sprite của bat */
	sprites[SPRITE_INFO_BAT]->InitFromFile("assets/sprites/enemies/bat/image.png", "assets/sprites/enemies/bat/bat.info.dat");
	sprites[SPRITE_INFO_BAT]->image->direction = RIGHT;

	/* sprite của brown_bird */
	sprites[SPRITE_INFO_BROWN_BIRD]->InitFromFile("assets/sprites/enemies/brown_bird/image.png", "assets/sprites/enemies/brown_bird/brown_bird.info.dat");
	sprites[SPRITE_INFO_BROWN_BIRD]->image->direction = RIGHT;

	/* sprite của banshee */
	sprites[SPRITE_INFO_BANSHEE]->InitFromFile("assets/sprites/enemies/banshee/image.png", "assets/sprites/enemies/banshee/banshee.info.dat");
	sprites[SPRITE_INFO_BANSHEE]->image->direction = RIGHT;

	/* sprite của shooter */
	sprites[SPRITE_INFO_SHOOTER]->InitFromFile("assets/sprites/enemies/shooter/image.png", "assets/sprites/enemies/shooter/shooter.info.dat");
	sprites[SPRITE_INFO_SHOOTER]->image->direction = RIGHT;

	/* sprite của runner */
	sprites[SPRITE_INFO_RUNNER]->InitFromFile("assets/sprites/enemies/runner/image.png", "assets/sprites/enemies/runner/runner.info.dat");
	sprites[SPRITE_INFO_RUNNER]->image->direction = RIGHT;

	/* sprite của baazoka */
	sprites[SPRITE_INFO_BAAZOKA]->InitFromFile("assets/sprites/enemies/baazoka/image.png", "assets/sprites/enemies/baazoka/baazoka.info.dat");
	sprites[SPRITE_INFO_BAAZOKA]->image->direction = RIGHT;
	
	/* sprite của ryu */
	sprites[SPRITE_INFO_RYU]->InitFromFile("assets/sprites/ryu/image.png", "assets/sprites/ryu/ryu.info.dat");
	sprites[SPRITE_INFO_RYU]->image->direction = RIGHT;

	sprites[SPRITE_INFO_BANSHEE_WEAPON]->InitFromFile("assets/sprites/weapon/banshee_weapon/image.png"
		, "assets/sprites/weapon/banshee_weapon/banshee_weapon.info.dat");
	sprites[SPRITE_INFO_BANSHEE_WEAPON]->image->direction = RIGHT;

	sprites[SPRITE_INFO_SHOOTER_WEAPON]->InitFromFile("assets/sprites/weapon/shooter_weapon/image.png"
		, "assets/sprites/weapon/shooter_weapon/shooter_weapon.info.dat");
	sprites[SPRITE_INFO_SHOOTER_WEAPON]->image->direction = RIGHT;


	sprites[SPRITE_MISC]->InitFromFile("assets/sprites/Misc/misc.png", "assets/sprites/Misc/misc.info.txt");
	sprites[SPRITE_MISC]->image->direction = RIGHT;

	sprites[SPRITE_EXPLOSION]->InitFromFile("assets/sprites/explosion/image.png", "assets/sprites/explosion/explosion.info.dat");
	sprites[SPRITE_EXPLOSION]->image->direction = RIGHT;

	sprites[SPRITE_BUTTER_FLY]->InitFromFile("assets/sprites/butterfly/image.png", "assets/sprites/butterfly/butterfly.info.dat");
	sprites[SPRITE_BUTTER_FLY]->image->direction = RIGHT;

	sprites[SPRITE_BIRD_STATIC]->InitFromFile("assets/sprites/bird_static/image.png", "assets/sprites/bird_static/bird_static.info.dat");
	sprites[SPRITE_BIRD_STATIC]->image->direction = RIGHT;

	sprites[SPRITE_ITEM_1]->InitFromFile("assets/sprites/items/item1/image.png", "assets/sprites/items/item1/item1.info.dat");
	sprites[SPRITE_ITEM_1]->image->direction = RIGHT;

	sprites[SPRITE_ITEM_2]->InitFromFile("assets/sprites/items/item2/image.png", "assets/sprites/items/item2/item2.info.dat");
	sprites[SPRITE_ITEM_2]->image->direction = RIGHT;

	sprites[SPRITE_ITEM_MONEY_BAG_BLUE]->InitFromFile("assets/sprites/items/money_bag_1/image.png", "assets/sprites/items/money_bag_1/money_bag_1.info.dat");
	sprites[SPRITE_ITEM_MONEY_BAG_BLUE]->image->direction = RIGHT;

	sprites[SPRITE_ITEM_FIRE]->InitFromFile("assets/sprites/items/fire/image.png", "assets/sprites/items/fire/fire.info.dat");
	sprites[SPRITE_ITEM_FIRE]->image->direction = RIGHT;

	sprites[SPRITE_ITEM_STOP_WATCH]->InitFromFile("assets/sprites/items/stop_watch/image.png", "assets/sprites/items/stop_watch/stop_watch.info.dat");
	sprites[SPRITE_ITEM_STOP_WATCH]->image->direction = RIGHT;

	sprites[SPRITE_ITEM_MONEY_BAG_RED]->InitFromFile("assets/sprites/items/money_bag_2/image.png", "assets/sprites/items/money_bag_2/money_bag_2.info.dat");
	sprites[SPRITE_ITEM_MONEY_BAG_RED]->image->direction = RIGHT;

	sprites[SPRITE_ITEM_SHURIKEN_SMALL]->InitFromFile("assets/sprites/weapon/shuriken_small/image.png", "assets/sprites/weapon/shuriken_small/shuriken_small.info.dat");
	sprites[SPRITE_ITEM_SHURIKEN_SMALL]->image->direction = RIGHT;

	sprites[SPRITE_ITEM_SHURIKEN_BIG]->InitFromFile("assets/sprites/weapon/shuriken_big/image.png", "assets/sprites/weapon/shuriken_big/shuriken_big.info.dat");
	sprites[SPRITE_ITEM_SHURIKEN_BIG]->image->direction = RIGHT;

	sprites[SPRITE_BOSS]->InitFromFile("assets/sprites/enemies/boss/image.png", "assets/sprites/enemies/boss/boss.info.dat");
	sprites[SPRITE_BOSS]->image->direction = RIGHT;

}
SpriteManager::~SpriteManager()
{
}
