#include<d3dx9.h>
#include"Camera.h"
#include"Ryu.h"

Camera * Camera::instance = 0;
Camera * Camera::getInstance()
{
	if (instance == 0)
	{
		instance = new Camera();
	}
	return instance;
}

void Camera::convertWorldToView(float xWorld, float yWorld, float & xView, float & yView)
{
	/* ma trận biến đổi world to view */
	D3DXMATRIX matrixWorldToView;
	D3DXMatrixIdentity(&matrixWorldToView);
	matrixWorldToView._22 = -1;
	matrixWorldToView._41 = -this->getX();
	matrixWorldToView._42 = this->getY();

	/* nhân ma trận đó với xWorld yWorld ta được xView yView */
	D3DXVECTOR3 pos3(xWorld, yWorld, 1);
	D3DXVECTOR4 MatrixResult;
	D3DXVec3Transform(&MatrixResult, &pos3, &matrixWorldToView);

	xView = MatrixResult.x;
	yView = MatrixResult.y;
}

void Camera::update()
{
	/* mặc định cho camera đứng yên, chỉ khi player chạy nó mới chạy theo */
	setDx(0);

	Ryu* ryu = Ryu::getInstance();
	/* nếu player đang chạy sang trái (player->getDx()<0) và phần giữa camera nằm bên phải phần giữa player */
	if (ryu->getDx() < 0 && getMidX() > ryu->getMidX())
	{
		/* thì cho camera chạy theo player (về bên trái) */
		setDx(ryu->getDx());
	}
	/* nếu player đang chạy sang phải (player->getDx()>0) và phần giữa camera nằm bên trái phần giữa player */
	if (ryu->getDx() > 0 && getMidX() < ryu->getMidX())
	{
		/* thì cho camera chạy theo player (về bên phải) */
		setDx(ryu->getDx());
	}

	/* cập nhật vị trí camera */
	goX();
	goY();
}

Camera::Camera()
{
}


Camera::~Camera()
{
}
