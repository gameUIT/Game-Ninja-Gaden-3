#pragma once


#include"GameDirectX.h"

enum TEXTURE_DIRECTION
{
	TEXTURE_DIRECTION_LEFT = -1,
	TEXTURE_DIRECTION_RIGHT = 1
};



class GameTexture
{

private:
	LPDIRECT3DTEXTURE9 m_image;
public:

	int Width, Height;
	/* Hướng mặc định của texture */
	TEXTURE_DIRECTION direction;

	GameTexture(const char* filepath, D3DCOLOR transColor = 0);

	/** Tạo texture
	filepath: duong dan file hinh anh
	transColor: mau can trong suot
	*/
	void Init(const char* filepath, D3DCOLOR transColor = 0);
	GameTexture() {}

	/** Vẽ texture
	x,y: vị trí bức hình trong backbuffer
	r: vùng chữ nhật cần vẽ
	anchorX : điểm neo x
	anchorY : điểm neo y
	*/

	void Render(int x, int y, int anchorX=0, int anchorY=0, RECT *r = 0);
	~GameTexture();
};
