#pragma once
enum COLLISION_TYPE
{
	CT_GROUND,
	CT_ENEMY,
	CT_WALL,
	CT_WEAPON,
	CT_ITEM,
	CT_PLAYER,
	CT_MISC,
	/* số lượng collisionType luôn nằm cuối */
	CT_ALL,
	COLLISION_TYPE_COUNT
};