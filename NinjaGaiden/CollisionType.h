#pragma once
enum COLLISION_TYPE
{
	CT_GROUND,
	CT_ENEMY,
	CT_STAIR,
	/* thêm các collisionType khác trong tool vào đây */
	CT_WEAPON,
	CT_ITEM,
	CT_PLAYER,
	/* số lượng collisionType luôn nằm cuối */
	COLLISION_TYPE_COUNT
};