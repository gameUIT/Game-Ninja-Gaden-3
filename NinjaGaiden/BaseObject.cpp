#include "BaseObject.h"

void BaseObject::setSprite(Sprite * sprite)
{
	this->sprite = sprite;
}

Sprite * BaseObject::getSprite()
{
	return this->sprite;
}

bool BaseObject::getPauseAnimation()
{
	return pauseAnimation;
}

void BaseObject::setPauseAnimation(bool pauseAnimation)
{
	this->pauseAnimation = pauseAnimation;
}

bool BaseObject::getIsLastFrameAnimationDone()
{
	return isLastFrameAnimationDone;
}

void BaseObject::setIsLastFrameAnimationDone(bool isLastFrameAnimationDone)
{
	this->isLastFrameAnimationDone = isLastFrameAnimationDone;
}

void BaseObject::onInitFromFile(ifstream& fs, int mapHeight)
{
	int collisionType, x, y, width, height;
	/* đọc collision type x y width height từ file. collision_type thì sẽ học ở bài sau */
	fs >> collisionType >> x >> y >> width >> height;
	/* do y của đối tượng trong file là tọa độ hướng từ trên xuống
	Nhưng y của game chúng ta làm thì gốc tọa độ bên dưới nên ta chuyển nó về cho đúng tọa độ logic */
	y = mapHeight - y;
	/* khởi tạo x y width height cho đối tượng */
	set(x, y, width, height);
}

void BaseObject::update(float dt)
{
	/* chúng ta di chuyển đối tượng trước khi cập nhật */
	goX();
	goY();

	/* mặc định đây không phải là frame cuối đã hoàn thành */
	setIsLastFrameAnimationDone(false);

	/* nếu đối tượng này có hình và không bị pauseAnimation thì ta cập nhật animation cho nó */
	if (!pauseAnimation && getSprite() != NULL)
	{
		if (animationGameTime.atTime())
		{
			/* cập nhật animation cho đối tượng */
			sprite->update(animationIndex, frameIndex);
			if (frameIndex == 0)
			{
				/* nếu frame cuối đã chạy thì sau khi cập nhật frameIndex sẽ là 0 */
				setIsLastFrameAnimationDone(true);
			}
		}
	}

	onUpdate(dt);
}

void BaseObject::onUpdate(float dt)
{
	/* mặc định sẽ cho chạy animation */
	setPauseAnimation(false);
}

void BaseObject::render(Camera* camera)
{
	if (getSprite() == 0)
		return;

	float xView, yView;
	/* tính tọa độ view để vẽ đối tượng lên màn hình */
	camera->convertWorldToView(getX(), getY(), xView, yView);
	/* vẽ đối tượng lên màn hình */
	sprite->render(xView, yView, animationIndex, frameIndex);
}

BaseObject::BaseObject()
{
	animationIndex = 0;
	frameIndex = 0;
	setSprite(NULL);
	animationGameTime.init(GLOBALS_D("object_animation_time_default"));
	setStopCollision(false);
	//setIsAlive(true);
	//setRenderActive(true);
}


BaseObject::~BaseObject()
{
}
