#include "DxLib.h"
#include "CharacterState.h"
#include "Animation.h"

/// <summary>
/// コンストラクタ
/// </summary>
Animation::Animation() :
	animationTime(0),
	blendValue(0),
	isEndAnimation(false)
{

	for (int i = 0; i < AnimationMax; i++)
	{
		int animModel;
		switch ((CharacterState::State)i)
		{
			//Idleアニメーションをロード
		case CharacterState::State::Idle:
			animModel = MV1LoadModel("Data/Animation/Idle.mv1");
			break;
			//上入力のポーズをロード
		case CharacterState::State::UpPose:
			animModel = MV1LoadModel("Data/Animation/UpPose.mv1");
			break;
			//下入力のポーズをロード
		case CharacterState::State::DownPose:
			animModel = MV1LoadModel("Data/Animation/DownPose.mv1");
			break;
			//右入力のポーズをロード
		case CharacterState::State::RightPose:
			animModel = MV1LoadModel("Data/Animation/RightPose.mv1");
			break;
			//左入力のポーズをロード
		case CharacterState::State::LeftPose:
			animModel = MV1LoadModel("Data/Animation/LeftPose.mv1");
			break;
			//リザルトのダンスをロード
		case CharacterState::State::FinishDance:
			animModel = MV1LoadModel("Data/Animation/FinishDance.mv1");
			break;
		default:
			break;
		}
		//vectorにアニメーションモデルを格納
		animation.push_back(animModel);
	}
}
/// <summary>
/// デストラクタ
/// </summary>
Animation::~Animation()
{
	for (int i = 0; i < animation.size(); i++)
	{
		MV1DeleteModel(animation[i]);
	}
	animation.clear();
	index.clear();
}
/// <summary>
/// 初期化
/// </summary>
int Animation::Init(int _model)
{
	//アタッチしているアニメーションをすべて削除
	for (int i = 0; i < index.size(); i++)
	{
		MV1DetachAnim(_model, index[i]);
	}
	//アニメーションのアタッチ番号を全て削除
	index.clear();
	//Idleアニメーションをセット
	SetIdle(_model);
	return _model;
}
/// <summary>
/// 更新
/// </summary>
int Animation::Update(int _model, int _state, int _lastTimeState ,int _successCount)
{
	//アニメーションの再生が終了している、または、
	//前フレームのステートがIdleで今のステートがIdle以外の時処理を実行
	if (isEndAnimation 
		|| _lastTimeState == (int)CharacterState::State::Idle 
		&&_state != (int)CharacterState::State::Idle)
	{
		//アニメーションをセット
		_model = SetAnimation(_state, _model);
	}
	//アニメーションを再生
	_model = PlayAnimation(_model, _successCount);

	return _model;
}
/// <summary>
/// アニメーションをアタッチ
/// </summary>
int Animation::SetAnimation(int _state, int _model)
{
	//アニメーションを指定されたアニメーションに設定
	index.push_back(MV1AttachAnim(_model, 0, animation[_state], FALSE));
	//アニメーションの再生時間をリセット
	animationTime = 0;

	isEndAnimation = false;

	return _model;
}
/// <summary>
/// アニメーションを再生
/// </summary>
int Animation::PlayAnimation(int _model, int _successCount)
{
	float addAnimSpeed = (float)_successCount / (float)ChangeSuccessCountToAnimationSpeed;
	if (addAnimSpeed > AddAnimationSpeedMax)
	{
		addAnimSpeed = AddAnimationSpeedMax;
	}
	//アニメーションの時間を1F進める
	//Successが多くなればなるほど速度を上げる
	animationTime += AnimationSpeed + addAnimSpeed;

	//アニメーションが再生され終わった時に再生時間を0にする
	if (animationTime >= MV1GetAttachAnimTotalTime(_model, index[0]))
	{
		animationTime = 0;
		isEndAnimation = true;
	}
	//アタッチされているアニメーションが2つ以上になったら
	if (index.size() >= AttachAnimationBlendValue)
	{
		_model = BlendAnimation(_model);
	}
	//モデルにアニメーションの再生時間を適用
	MV1SetAttachAnimTime(_model, index[0], animationTime);
	return _model;
}

/// <summary>
/// アニメーションのブレンド
/// </summary>
int Animation::BlendAnimation(int _model)
{
	//現在のアニメーションのブレンド値を設定(少しずつ減る)
	MV1SetAttachAnimBlendRate(_model, index[BlendBeforAnimationIndex], BlendValueMax - blendValue);
	//次のアニメーションのブレンド値を設定(少しずつ増える)
	MV1SetAttachAnimBlendRate(_model, index[BlendAfterAnimationIndex], blendValue);
	//ブレンド値の増加
	blendValue += BlendSpeed;
	//ブレンド値が1.0f以上になった場合、または、indexのサイズが最大値以上になった場合
	if (blendValue >= BlendValueMax || 
		index.size() >= AnimationIndexSizeMax)
	{
		//現在のアニメーションをデタッチ
		MV1DetachAnim(_model, index[BlendBeforAnimationIndex]);
		//現在のアニメーションのアタッチ番号を破棄
		index.erase(index.begin());
		//ブレンド値をリセット
		blendValue = 0;
	}
	return _model;
}

/// <summary>
/// Idleアニメーションにセットする
/// </summary>
int Animation::SetIdle(int _model)
{
	//アニメーションをIdleに設定
	index.push_back(MV1AttachAnim(_model, 0,
		animation[(int)CharacterState::State::Idle], FALSE));
	//アニメーションの再生時間をリセット
	animationTime = 0;

	return _model;
}