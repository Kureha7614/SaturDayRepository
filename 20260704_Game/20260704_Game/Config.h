#pragma once

namespace Config
{
	//===================================
	// Window settings
	//===================================
	//ウィンドウサイズ
	constexpr int WINDOW_WIDTH = 1920;
	constexpr int WINDOW_HEIGHT = 1080;
	//表示するx,y座標
	constexpr int PLAYER_DRAW_X = 96;
	constexpr int PLAYER_DRAW_Y = 96;

	//===================================
	// PLAYER Settings
	//===================================
	//一コマのサイズ
	constexpr int PLAYER_WIDTH = 210;
	constexpr int PLAYER_HEIGHT = 220;
	//分割数
	constexpr int PLAYER_COL = 7;
	constexpr int PLAYER_ROW = 7;
	
	//総フレーム
	constexpr int PLAYER_TOTAL_FRAMES = PLAYER_COL * PLAYER_ROW;

	//===================================
	// アニメーションの速度
	//===================================
	constexpr int IDLE_SPPED = 10;
	constexpr int WALK_SPPED = 7;
	constexpr int RUN_SPPED = 8;
	constexpr int JUMP_SPPED = 6;

}