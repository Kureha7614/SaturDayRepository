#pragma once

#include<vector>
#include<iostream>
using namespace std;
class Map
{
private:
	//マップチップの番号
	vector<vector<int>> mapDate;
	//当たり判定の情報
	vector<vector<int>> hitDate2;

	//マップチップ画像
	int chipImage[64];

	//マップの縦横のマスの数
	int mapWidth;
	int mapHeight;

	//マップの大きさ
	static constexpr int CHIP_SIZE = 64;

	//csvファイルの読み込み
	bool LoadCSV(const char* fileName, vector<vector<int>>& data);

public:
	/// <summary>
	/// Mapコンストラクタ
	/// </summary>
	Map();

	bool Init();

	/// <summary>
	/// Mapの描画
	/// </summary>
	void Draw(float cameraX, float cameraY);

	/// <summary>
	/// マップの当たり判定の描画
	/// </summary>
	/// <param name="cameraX">カメラのX座標</param>
	/// <param name="cameraY">カメラのY座標</param>
	void DrawHitBox(float cameraX, float cameraY);

	/// <summary>
	/// 指定したマスが通行できるか調べる
	/// </summary>
	/// <param name="tileX">マスのX座標</param>
	/// <param name="tileY">マスのY座標</param>
	/// <returns>通行できる場合はtrue、そうでない場合はfalse</returns>
	bool IsSolid(int tileX, int tileY);

	/// <summary>
	/// ワールド座標から当たり判定を調べる
	/// </summary>
	/// <param name="tileX">ワールド座標のX</param>
	/// <param name="tileY">ワールド座標のY</param>
	/// <returns>当たり判定がある場合はtrue、そうでない場合はfalse</returns>
	bool IsSolidat(int tileX, int tileY);
};

