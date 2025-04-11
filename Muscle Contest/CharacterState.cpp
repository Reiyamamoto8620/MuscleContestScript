#include "CharacterState.h"

/// <summary>
/// コンストラクタ
/// </summary>
CharacterState::CharacterState() :
	state(*new State),
	lastTimeState(*new State),
	isPose(false),
	nowPose(0)
{

}

/// <summary>
/// デストラクタ
/// </summary>
CharacterState::~CharacterState()
{

}

/// <summary>
/// 初期化
/// </summary>
void CharacterState::Init()
{
	state = State::Idle;
	lastTimeState = State::Idle;
	isPose = false;
	nowPose = 0;
}

/// <summary>
/// 更新
/// </summary>
void CharacterState::Update(bool _isUp, bool _isDown,
	bool _isRight, bool _isLeft, bool _isDance, bool _isEndAnimation,bool _isFinishJudge)
{
	SetState(_isUp, _isDown, _isRight, _isLeft, _isDance, _isEndAnimation);
	CheckIsPose(_isFinishJudge);
}

/// <summary>
/// ステートをセット
/// </summary>
void CharacterState::SetState(bool _isUp, bool _isDown,
	bool _isRight, bool _isLeft, bool _isDance, bool _isEndAnimation)
{

	if (state != State::Idle && _isEndAnimation)
	{
		//Idle状態に設定
		state = State::Idle;
	}
	//前フレームのステートを保存
	lastTimeState = state;

	if (state == State::Idle)
	{
		//左入力がある場合処理を実行
		if (_isLeft)
		{
			//ステートを左入力のポージング状態にする
			state = State::LeftPose;
		}
		//右入力がある場合処理を実行
		if (_isRight)
		{
			//ステートを右入力のポージング状態にする
			state = State::RightPose;
		}
		//下入力がある場合処理を実行
		if (_isDown)
		{
			//ステートを下入力のポージング状態にする
			state = State::DownPose;
		}
		//上入力がある場合処理を実行
		if (_isUp)
		{
			//ステートを上入力のポージング状態にする
			state = State::UpPose;
		}
	}
	//ゲームの状態がリザルトの場合処理を実行
	if (_isDance)
	{
		//ステートをリザルトでのダンス状態にする
		state = State::FinishDance;
	}
}
/// <summary>
/// ポージング判定の確認
/// </summary>
void CharacterState::CheckIsPose(bool _isFinishJudge)
{
	//ステートがIdle以外で前フレームのステートがIdleの時実行
	if (state != State::Idle && lastTimeState == State::Idle)
	{
		//ポージング判定をTrue
		isPose = true;
		//現在のポーズを更新
		nowPose = (int)state;
	}
	//ポージングの確認が終了したときに実行
	if (_isFinishJudge)
	{
		//ポージング判定をFalse
		isPose = false;
	}
}