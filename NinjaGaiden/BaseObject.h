#pragma once
#include "MovableRect.h"
#include"Sprite.h"
#include"GameTime.h"
#include"Camera.h"

/* Đây là đối tượng của game. Kế thừa lại lớp đối tượng có thể chuyển động */
class BaseObject :
	public MovableRect
{
	Sprite* sprite;
	/* animation hiện tại và frame index hiện tại */
	int animationIndex, frameIndex;

	/* dùng để làm chậm animation */
	GameTime animationGameTime;

	/* dừng animation */
	bool pauseAnimation;
	/* kiểm tra xem frame cuối cùng đã hoàn thành hay chưa
		Ví dụ action có 3 frame thì animation sẽ chạy frame 0 1 2 0 1 2 0 1 2. tức là khi frame=2 hoàn thành và chuyển
		sang frame 0 thì biến này sẽ là true. cái này thường làm lúc simon đánh cây roi, khi hoàn thành việc đánh nó quay về
		trạng thái đứng yên
	*/
	bool isLastFrameAnimationDone;
	TEXTURE_DIRECTION direction;

public:
	/* dùng để restore location */
	Rect* initBox;
	bool renderActive;
	bool isAlive;

	void setSprite(Sprite*sprite);
	Sprite* getSprite();

	bool getPauseAnimation();
	virtual void setPauseAnimation(bool pauseAnimation);

	int getAnimation();
	void setAnimation(int animation);

	int getFrameAnimation();
	void setFrameAnimation(int frameAnimation);

	TEXTURE_DIRECTION getDirection();
	void setDirection(TEXTURE_DIRECTION direction);

	bool getIsLastFrameAnimationDone();
	void update(float dt);
	virtual void setIsLastFrameAnimationDone(bool isLastFrameAnimationDone);
	virtual void onInitFromFile(ifstream& fs, int mapHeight);
	virtual void onUpdate(float dt);
	virtual void render(Camera* camera);

	Rect* getInitBox();
	void setInitBox(Rect* initBox);

	bool getIsAlive();
	void setIsAlive(bool isAlive);

	void setRenderActive(bool renderActive);
	bool getRenderActive();

	int distanceHorToFirstLocation();
	virtual void restoreLocation();

	void onIntersect(MovableRect* other) override {}
	virtual bool canRemoveFromCamera();

	BaseObject();
	~BaseObject();
};

