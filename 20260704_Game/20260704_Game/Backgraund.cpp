#include "BackGraund.h"
#include"DxLib.h"
//================================================================
//初期化
//================================================================
void BackGraund::Init()
{
	imageHandle = LoadGraph("image/BackGround.png");
}
//================================================================
//描画
//================================================================
void BackGraund::Draw(float cameraX)
{
	DrawGraph(-(int)(cameraX * 0.5f), 0, imageHandle, TRUE);
}