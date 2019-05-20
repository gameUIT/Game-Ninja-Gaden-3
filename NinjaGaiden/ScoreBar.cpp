#include "ScoreBar.h"
#include "Player.h"
#include "SpriteManager.h"

#define NUMBER_WIDTH 8
#define HEALTH_WIDTH 4

void ignoreLineIfstream(ifstream& fs, int lineCount);

ScoreBar * ScoreBar::instance = 0;
ScoreBar * ScoreBar::getInstance()
{
	if (instance == 0)
		instance = new ScoreBar();
	return instance;
}

ScoreBar::ScoreBar()
{
	//scoreBar = TEXTURE_MANAGER->Get(TEXTURE_SCOREBAR);
	//scorebarItemSprite = GRAPHICS_ASSETS_MANAGER->getGraphicsAssets(SPRITE_INFO_SCOREBAR);
	timeGame.init(1000);

	ifstream ifs("Assets/GraphicsAssets/Scorebar/score_bar_item_location.txt");
	ignoreLineIfstream(ifs, 1);
	ifs >> lifeLocation.X >> lifeLocation.Y >> lifeLocation.MaxLength;
	setPlayerLife(3);
	setScore(0);

	ignoreLineIfstream(ifs, 2);
	ifs >> heartLocation.X >> heartLocation.Y >> heartLocation.MaxLength;
	setHeartCount(5);

	ignoreLineIfstream(ifs, 2);
	ifs >> stageLocation.X >> stageLocation.Y >> stageLocation.MaxLength;

	ignoreLineIfstream(ifs, 2);
	ifs >> scoreLocation.X >> scoreLocation.Y >> scoreLocation.MaxLength;

	ignoreLineIfstream(ifs, 2);
	ifs >> timeLocation.X >> timeLocation.Y >> timeLocation.MaxLength;

	ignoreLineIfstream(ifs, 2);
	ifs >> healthLocation.X >> healthLocation.Y >> maxHealth;

	ignoreLineIfstream(ifs, 2);
	ifs >> subWeaponLocation.X >> subWeaponLocation.Y;

	ignoreLineIfstream(ifs, 2);
	ifs >> bossHealthLocation.X >> bossHealthLocation.Y >> bossHealthLocation.MaxLength;

	setHealth(maxHealth);
	setBossHealth(maxHealth);
	setTime(900);
}

void ScoreBar::renderNumber(int num, int x, int y, int maxLength)
{
	int currentX = x + NUMBER_WIDTH * maxLength;
	int length = 0;
	while (num)
	{
		currentX -= NUMBER_WIDTH;
		int val = num % 10;
		scorebarItemSprite->render(currentX, y, SCOREBAR_ACTION_NUMBER, val);
		num /= 10;
		length++;
	}
	for (; length < maxLength; length++)
	{
		currentX -= NUMBER_WIDTH;
		scorebarItemSprite->render(currentX, y, SCOREBAR_ACTION_NUMBER, 0);
	}
}

void ScoreBar::renderHealth()
{
	int healthLost = maxHealth - health;
	int lastLocationXHealth = healthLocation.X + HEALTH_WIDTH * maxHealth - HEALTH_WIDTH;
	for (size_t i = 0; i < healthLost; i++)
	{
		scorebarItemSprite->render(lastLocationXHealth, healthLocation.Y, SCOREBAR_ACTION_LOST_HEART, 0);
		lastLocationXHealth -= HEALTH_WIDTH;
	}
}

void ScoreBar::renderBossHealth()
{
	int healthLost = maxHealth - bossHealth;
	if (healthLost > maxHealth)
	{
		healthLost = maxHealth;
	}
	int lastLocationXHealth = bossHealthLocation.X + HEALTH_WIDTH * maxHealth - HEALTH_WIDTH;
	for (size_t i = 0; i < healthLost; i++)
	{
		scorebarItemSprite->render(lastLocationXHealth, bossHealthLocation.Y, SCOREBAR_ACTION_LOST_HEART, 0);
		lastLocationXHealth -= HEALTH_WIDTH;
	}
}

void ScoreBar::renderSubWeapon()
{
	if (this->subWeapon != 0)
	{
		//this->subWeapon->getGraphicsAssets()->Render(subWeaponLocation.X,
		//	subWeaponLocation.Y,
		//	subWeapon->getAction(), 0);
	}
}


void ScoreBar::render()
{
	GameDirectX::getInstance()->GetSprite()->Draw(scoreBar,
		0,
		&D3DXVECTOR3(0, 0, 0),
		&D3DXVECTOR3(0, 0, 0),
		D3DCOLOR_XRGB(255, 255, 255));

	renderNumber(getPlayerLife(), lifeLocation.X, lifeLocation.Y, lifeLocation.MaxLength);
	renderNumber(getHeartCount(), heartLocation.X, heartLocation.Y, heartLocation.MaxLength);
	renderNumber(currentStageNumber, stageLocation.X, stageLocation.Y, stageLocation.MaxLength);
	renderNumber(score, scoreLocation.X, scoreLocation.Y, scoreLocation.MaxLength);
	renderNumber(time, timeLocation.X, timeLocation.Y, timeLocation.MaxLength);
	renderHealth();
	renderBossHealth();
	renderSubWeapon();
}

void ScoreBar::update()
{
	if (timeGame.atTime())
	{
		increaseTime(-1);
	}
}

void ScoreBar::setSubWeapon(BaseObject* subWeapon)
{
	this->subWeapon = subWeapon;
}

void ScoreBar::restoreHealth()
{
	setHealth(maxHealth);
}

void ScoreBar::restoreBossHealth()
{
	setBossHealth(maxHealth);
}

int ScoreBar::getPlayerLife()
{
	return playerLife;
}

void ScoreBar::setPlayerLife(int playerLife)
{
	if (playerLife >= 0)
		this->playerLife = playerLife;
}

void ScoreBar::increasePlayerLife(int playerLife)
{
	setPlayerLife(this->playerLife + playerLife);
}

int ScoreBar::getHeartCount()
{
	return heartCount;
}

void ScoreBar::setHeartCount(int heartCount)
{
	this->heartCount = heartCount;
}

void ScoreBar::increaseHeartCount(int heartCount)
{
	setHeartCount(this->heartCount + heartCount);
}

void ScoreBar::setCurrentStageNumber(int currentStageNumber)
{
	this->currentStageNumber = currentStageNumber;
}

int ScoreBar::getCurrentStageNumber()
{
	return this->currentStageNumber;
}

int ScoreBar::getScore()
{
	return score;
}
void ScoreBar::setScore(int score)
{
	this->score = score;
}
void ScoreBar::increaseScore(int score)
{
	this->score += score;
}

int ScoreBar::getTime()
{
	return time;
}
void ScoreBar::setTime(int time)
{
	if (time >= 0)
		this->time = time;
}
void ScoreBar::increaseTime(int time)
{
	setTime(this->time + time);
}

int ScoreBar::getHealth()
{
	return health;
}
void ScoreBar::setHealth(int health)
{
	if (health >= 0)
		this->health = health;
}
void ScoreBar::increaseHealth(int health)
{
	setHealth(this->health + health);
}

int ScoreBar::getBossHealth()
{
	return bossHealth;
}
void ScoreBar::setBossHealth(int health)
{
	this->bossHealth = health;
}
void ScoreBar::increaseBossHealth(int health)
{
	setBossHealth(bossHealth + health);
}

int ScoreBar::getMaxHealth()
{
	return maxHealth;
}

ScoreBar::~ScoreBar()
{
}