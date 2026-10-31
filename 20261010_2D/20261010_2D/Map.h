#pragma once
#include<vector>
#include<iostream>
#include"Config.h"
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

