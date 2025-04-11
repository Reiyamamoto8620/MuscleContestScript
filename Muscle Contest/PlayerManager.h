#pragma once
#include "Input.h"
#include "CharacterState.h"
#include "Animation.h"
#include "PlayerModel.h"

class PlayerManager
{
public:
	////////////////////////
	//--------関数--------//
	////////////////////////
	//コンストラクタ
	PlayerManager();
	//デストラクタ
	~PlayerManager();
	//更新
	void Update(int _successCount, int _sceneState,bool _isNPCPose, bool _isFinishJudge);
	//初期化
	void Init();

	/// <summary>
	/// ステートを取得
	/// </summary>
	int GetState()
	{
		return (int)state->GetState();
	}
	/// <summary>
	/// ポージング判定を取得
	/// </summary>
	bool GetIsPose()
	{
		return state->GetIsPose();
	}
	/// <summary>
	/// アニメーションの終了判定を取得
	/// </summary>
	bool GetIsEndAnimation()
	{
		return animation->GetIsEndAnimation();
	}
private:
	////////////////////////
	//--------変数--------//
	////////////////////////
	Input* input;			//入力判定クラス
	Animation* animation;	//アニメーションクラス
	CharacterState* state;	//ステートクラス
	PlayerModel* model;		//モデルクラス
};

