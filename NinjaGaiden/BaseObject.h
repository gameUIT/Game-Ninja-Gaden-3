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
public:
	void setSprite(Sprite*sprite);
	Sprite* getSprite();

	bool getPauseAnimation();
	virtual void setPauseAnimation(bool pauseAnimation);

	bool getIsLastFrameAnimationDone();
	virtual void setIsLastFrameAnimationDone(bool isLastFrameAnimationDone);

	/* hàm ảo được gọi khi khởi tạo đối tượng đọc từ file, mỗi đối tượng sẽ thực hiện phương thức này khác nhau */
	virtual void onInitFromFile(ifstream& fs,int mapHeight);

	/* hàm ảo, hành động update của đối tượng, do mỗi đối tượng có phương thức cập nhật khác nhau
		như con zombie thì chạy còn con dơi thì bay hình sin
		dt : thời gian giữa 2 khung hình game tính bằng giây dùng để tính toán vật lý sau này
	*/
	virtual void onUpdate(float dt);
	/* hành động cập nhật của đối tượng sau mỗi lần vẽ lại */

	void update(float dt);
	/* hành động vẽ của đối tượng 
		camera dùng để biến đổi tọa độ của object từ world sang view
	*/
	virtual void render(Camera* camera);

	BaseObject();
	~BaseObject();
};

