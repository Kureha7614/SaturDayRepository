#pragma once
#include<vector>
#include<iostream>
#include"Config.h"
#include"Collision.h"
using namespace std;
class Map
{
private:
	//ファイルを読み込み

	/// <summary>
	/// ロードマップ
	/// </summary>
	/// <param name="filePath"マップCSVファイルパス></param>
	/// <param name="mapDate">マップチップイメージ</param>
	/// <returns>描画判定</returns>
	bool LoadMap(const char* filePath,std::vector<std::vector<int>>&mapDate);

	/// <summary>
	/// 描画レイヤー
	/// </summary>
	/// <param name="mapDate">マップのデータ</param>
	void DrawLayer(const std::vector<std::vector<int>>& mapDate) const;

	/// <summary>
	/// 描画フラグ
	/// </summary>
	/// <param name="mapX">X座標</param>
	/// <param name="mapY">Y座標</param>
	bool IsValidMapPosition(int mapX, int mapY)const;

	/// <summary>
	/// Collisionの矩形マップに合わせて押し戻す
	/// </summary>
	/// <param name="changeRect">Collisionチェック矩形</param>
	void HitCalc(Collision& changeRect)const;

	/// <summary>
	/// 指定したマップの当たり判定チップ番号の習得
	/// </summary>
	/// <param name="mapX">指定したマップ座標のX座標</param>
	/// <param name="mapY">指定したマップ座標のY座標</param>
	void GetBlockType(int mapX, int mapY)const;

	/// <summary>
	/// 指定したチップの上下左右に空きがある方向を習得
	/// </summary>
	/// <param name="mapX"></param>
	/// <param name="mapY"></param>
	/// <returns></returns>
	unsigned char GetBlockInfo(int mapX, int mapY)const;

	int chipImages[Config::MAP_CHIP_IMAGE_COUNT];

	//マップの内容
	std::vector<std::vector<int>> backMap;
	std::vector<std::vector<int>> baseMap;
	std::vector<std::vector<int>> nearMap;
	
	int mapXNum;
	int mapYNum;
	bool isInitialized;
public:
	//コンストラクタ＆デストラクタ
	Map();
	~Map();
	//画像とCSVを読み込み

	/// <summary>
	/// 画像読み込みの初期化
	/// </summary>
	/// <returns></returns>
	bool Init();

	//マップを奥から手前に描画

	/// <summary>
	/// びょうが
	/// </summary>
	void Draw()const;

	//Dxlib終了前に呼び出して画像などを解放

	void Finalize();
		

};

