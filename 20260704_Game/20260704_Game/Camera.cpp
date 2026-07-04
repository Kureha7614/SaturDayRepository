#include "Camera.h"
#include"DxLib.h"
#include"Confing.h"

//================================================================
//コンストラクタ
//================================================================
Camera::Camera()
{
	x = 0.0f;
}

//================================================================
//更新
//================================================================
void Camera::Update()
{
	//Aキーで左に移動
	if (CheckHitKey(KEY_INPUT_A)) { x -= GameConst::CAMERA_SPEED; }

	//Dキーで右に移動
	if (CheckHitKey(KEY_INPUT_D)) { x += GameConst::CAMERA_SPEED; }
	//画面外に出ないように制限
	if (x < 0) { x = 0;}
	if (x > GameConst::SCREEN_WIDTH) { x = GameConst::SCREEN_WIDTH; }
}
//================================================================
//X座標の取得
//================================================================
float Camera::GetX() const
{
	return x;
}