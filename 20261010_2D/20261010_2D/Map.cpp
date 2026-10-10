#include "Map.h"
#include"Dxlib.h"

#include<fstream>
#include<sstream>
#include<cmath>



//コンストラクタ
Map::Map()
{
	//マップの大きさを初期化
	mapWidth = 0;
	mapHeight = 0;
	//マップチップ画像の読み込み
	for (int i = 0; i < 64; i++)
	{
		chipImage[i] = -1;
	}

}


bool Map::LoadCSV(const char* fileName, vector<vector<int>>& data)
{
	std::ifstream file(fileName);
	if (!file.is_open())
	{
		return false;
	}
	data.clear();

	std::string line;

	while (std::getline(file, line))
	{
		std::vector<int> row;
		std::stringstream ss(line);
		std::string value;


	}
	return false;
}


