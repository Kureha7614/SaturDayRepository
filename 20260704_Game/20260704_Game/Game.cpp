#include"Game.h"
#include"Config.h"
#include"DxLib.h"

void Game::Init()
{
	//======================================
	//分割画像の読み込み
	//======================================
	LoadDivGraph("Image/AnimationPlayer1.png",
		Config::PLAYER_TOTAL_FRAMES,
		Config::PLAYER_COL,
		Config::PLAYER_ROW,
		Config::PLAYER_WIDTH,
		Config::PLAYER_HEIGHT,
		images);
	//======================================
	//アニメーションに分割画像を設定
	//======================================
	animations.SetImages(images);

	currentAnim = AnimationType::idel;
	PlayerAnimation(currentAnim);
	oldSpace = false;
}

void Game::Update()
{
	//======================================
	//フレームマネージャー更新
	//======================================
	frameManager.Update();

	//======================================
	//スペースキーの押した判定
	//======================================
	bool nowSpase = (CheckHitKey(KEY_INPUT_SPACE));

	//======================================
	//スペースキーが押された瞬間にアニメーションを切り替える
	//======================================
	if (nowSpase && !oldSpace)
	{
		switch (currentAnim)
		{
		case AnimationType::idel:
			currentAnim = AnimationType::walk;
			break;
		case AnimationType::walk:
			currentAnim = AnimationType::run;
			break;
		case AnimationType::run:
			currentAnim = AnimationType::jump;
			break;
		case AnimationType::jump:
			currentAnim = AnimationType::idel;
			break;
		default:
			break;
		}
		//======================================
		//アニメーション切り替え
		//======================================
		PlayerAnimation(currentAnim);
	}
	//======================================
	//前回のスペースキーの状態更新
	//======================================	
	oldSpace = nowSpase;
}

void Game::Draw()
{


	DrawGraph(Config::PLAYER_DRAW_X,
		Config::PLAYER_DRAW_Y,
		animations.GetImage(frameManager.GetFrameCounter()),
		TRUE);

	DrawFormatString(
		20,
		20,
		GetColor(255, 255, 255),
		"Frame : %d",
		frameManager.GetFrameCounter());
}

void Game::PlayerAnimation(AnimationType type)
{
	int row = static_cast<int>(type);

	int startFrame = row * Config::PLAYER_COL;

	int speed = Config::IDLE_SPPED;

	switch (type)
	{
	case AnimationType::idel:
		speed = Config::IDLE_SPPED;
		break;
		case AnimationType::walk:
		speed = Config::WALK_SPPED;
		break;
	case AnimationType::run:
		speed = Config::RUN_SPPED;
		break;
	case AnimationType::jump:
		speed = Config::JUMP_SPPED;
		break;
	}

	animations.Play(startFrame, Config::PLAYER_COL,
		speed);
}