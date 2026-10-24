#pragma once
#include<vector>
#include<vector>
#include<iostream>
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
	bool IsValidMapPosition(int mapX, int mapY);
	//マップの内容
	std::vector<std::vector<int>> backMap;
	std::vector<std::vector<int>> baseMap;
	std::vector<std::vector<int>> nearMap;
	
	int mapXNum;
	int mapYNum;
	bool isInitialized;
public:
};

