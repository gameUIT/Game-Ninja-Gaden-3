#pragma once
#include "Rect.h"
#include"CollisionType.h"

class MovableRect :
	public Rect
{
	/* độ dời di chuyển của đối tượng */
	float dx, dy;
	COLLISION_TYPE collisionType;
	bool stopCollision;
public:
	bool isAlive;
	COLLISION_TYPE getCollisionType();
	virtual void setCollisionType(COLLISION_TYPE collisionType);
	virtual void setDx(float dx);
	virtual void setDy(float dy);
	float getDx();
	float getDy();
	/* phương thức di chuyển */
	void goX();
	void goY();

	bool getIsAlive();
	void setIsAlive(bool isAlive);

	/* phương thức xử lý va chạm là phương thức ảo sẽ được mỗi đối tượng override để hiện thực */
	virtual void onCollision(MovableRect* other, float collisionTime, int nx, int ny);
	/* xử lý va chạm với player */
	virtual void onIntersect(MovableRect* other) {}

	/* phương thức xử lý va chạm chặn di chuyển khi phát hiện va chạm */
	void preventMovementOnCollision(float collisionTime, int nx, int ny);

	bool getStopCollision();
	void setStopCollision(bool stopCollision);

	MovableRect();
	~MovableRect();
};



 