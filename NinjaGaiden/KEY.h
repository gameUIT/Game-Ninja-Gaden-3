#pragma once
#include<Windows.h>
class KEY
{
public:
	bool
		isLeftDown,
		isRightDown,
		isUpDown,
		isDownDown,
		isJumpDown,
		isPreviousJumpDown,
		isJumpPress,
		isSpace1Down,
		isSpace2Down,
		isSpace3Down,
		isSpace4Down,
		isSpace5Down,
		isAttackDown,
		isPreviousAttackDown,
		isKeyMap2Down,
		isKeyMap3Down,
		isAttackPress;

	static KEY* instance;
	static KEY* getInstance();

	void update();

	KEY();
	~KEY();
};

