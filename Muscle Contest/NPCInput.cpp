#include "DxLib.h"
#include "CharacterState.h"
#include "NPCInput.h"

/// <summary>
/// コンストラクタ
/// </summary>
NPCInput::NPCInput() :
	isUp(false),
	isDown(false),
	isRight(false),
	isLeft(false),
	nowInput(0)
{

}

/// <summary>
/// デストラクタ
/// </summary>
NPCInput::~NPCInput()
{

}

/// <summary>
/// 初期化
/// </summary>
void NPCInput::Init()
{
	isUp = false;
	isDown = false;
	isRight = false;
	isLeft = false;
	nowInput = 0;
}

/// <summary>
/// 更新
/// </summary>
void NPCInput::Update(bool _isPose, bool _isPlayerPose)
{
	Init();
	if (!_isPose && !_isPlayerPose)
	{
		//1～4をランダムで選択(ランダムの最小値をステートのUpPose(Value:1)に合わせる)
		nowInput = GetRand(SelectInputMax) + (int)CharacterState::State::UpPose;
	}

	//nowInputがUpPose状態と同じ値の場合
	if (nowInput == (int)CharacterState::State::UpPose)
	{
		isUp = true;
	}
	//nowInputがDownPose状態と同じ値の場合
	if (nowInput == (int)CharacterState::State::DownPose)
	{
		isDown = true;
	}
	//nowInputがRightPose状態と同じ値の場合
	if (nowInput == (int)CharacterState::State::RightPose)
	{
		isRight = true;
	}
	//nowInputがLeftPose状態と同じ値の場合
	if (nowInput == (int)CharacterState::State::LeftPose)
	{
		isLeft = true;
	}
}