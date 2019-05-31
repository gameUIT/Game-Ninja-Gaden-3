#include "BaseObject.h"

BaseObject::BaseObject()
{
	animationIndex = 0;
	frameIndex = 0;
	setSprite(NULL);
	animationGameTime.init(GLOBALS_D("object_animation_time_default"));
	setStopCollision(false);
	setIsAlive(true);
	setRenderActive(true);
}

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

TEXTURE_DIRECTION BaseObject::getDirection()
{
	return this->direction;
}

void BaseObject::setDirection(TEXTURE_DIRECTION direction)
{
	this->direction = direction;
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
	auto initBox = new Rect();
	initBox->set(x, y, width, height);
	setInitBox(initBox);
}

void BaseObject::update(float dt)
{
	if (!isAlive)
	{
		return;
	}
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
	if (!isAlive)
	{
		return;
	}
	if (getSprite() == 0)
		return;

	if (!getRenderActive())
		return;

	float xView, yView;
	/* tính tọa độ view để vẽ đối tượng lên màn hình */
	camera->convertWorldToView(getX(), getY(), xView, yView);

	/* hướng mặt mặc định của bức hình */
	TEXTURE_DIRECTION imageDirection = sprite->image->direction;

	/* hướng mặt của nhân vật */
	TEXTURE_DIRECTION currentDirection = getDirection();

	/* nếu hướng mặt của nhân vật khác với hướng mặt trong bức hình thì tiến hành lật hình */
	if (imageDirection != currentDirection)
	{
		int currentFrameWidth = getSprite()->animations[getAnimation()]->frames[getFrameAnimation()]->right -
			getSprite()->animations[getAnimation()]->frames[getFrameAnimation()]->left;
		D3DXMATRIX flipMatrix;
		D3DXMatrixIdentity(&flipMatrix);
		flipMatrix._11 = -1;
		flipMatrix._41 = 2 * (xView + currentFrameWidth / 2);
		GameDirectX::getInstance()->GetSprite()->SetTransform(&flipMatrix);
	}

	/* vẽ đối tượng lên màn hình */
	sprite->render(xView, yView, animationIndex, frameIndex);

	if (direction != imageDirection)
	{
		/* khôi phục lại ma trận mặc định */
		D3DXMATRIX identityMatrix;
		D3DXMatrixIdentity(&identityMatrix);
		GameDirectX::getInstance()->GetSprite()->SetTransform(&identityMatrix);
	}

}

int BaseObject::getAnimation()
{
	return animationIndex;
}

void BaseObject::setAnimation(int animation)
{
	/* nếu set khác animation thì cho chạy lại từ frame 0 */
	if (this->animationIndex != animation)
	{
		setFrameAnimation(0);
	}
	this->animationIndex = animation;
}

int BaseObject::getFrameAnimation()
{
	return frameIndex;
}

void BaseObject::setFrameAnimation(int frameAnimation)
{
	this->frameIndex = frameAnimation;
}

Rect * BaseObject::getInitBox()
{
	return initBox;
}

void BaseObject::setInitBox(Rect * initBox)
{
	this->initBox = initBox;
}



void BaseObject::setRenderActive(bool renderActive)
{
	this->renderActive = renderActive;
}
bool BaseObject::getRenderActive()
{
	return this->renderActive;
}

int BaseObject::distanceHorToFirstLocation()
{
	return abs(this->getMidX() - initBox->getMidX());
}

void BaseObject::restoreLocation()
{
	set(initBox->getX(), initBox->getY(), initBox->getWidth(), initBox->getHeight());
	setIsAlive(true);
}



bool BaseObject::canRemoveFromCamera()
{
	return true;
}

BaseObject::~BaseObject()
{
}
