#pragma once
#include"MovableRect.h"
#include"Space.h"

class Camera : public MovableRect
{
	static Camera* instance;

	Space* space;
public:
	static Camera* getInstance();
	/* phương thức chuyển đổi world qua view
		Tham số đầu vào là xWorld yWorld
		Tham số cần lấy là xView yView (nên có dấu &, cần xem lại khái niệm về tham chiếu C++ để hiểu)
		Phương thức này trong sách game có giở sách ra xem sẽ thấy
	*/
	void convertWorldToView(float xWorld, float yWorld, float& xView, float& yView);

	void setSpace(Space* space);

	/* cập nhật camera */
	void update();

	Camera();
	~Camera();
};

