#pragma once
#include "NPCInput.h"
#include "CharacterState.h"
#include "Animation.h"
#include "NPCModel.h"

class NPCManager
{
public:
	////////////////////////
	//--------関数--------//
	////////////////////////
	//コンストラクタ
	NPCManager();
	//デストラクタ
	~NPCManager();
	//初期化
	void Init();
	//更新
	void Update(int _successCount, int _sceneState,bool _isPlayerPose,bool _isFinishJudge);

	/// <summary>
	/// ステートを取得
	/// </summary>
	int GetState()
	{
		return (int)state->GetState();
	}
	/// <summary>
	/// 現在のポーズを取得
	/// </summary>
	int GetNowPose()
	{
		return state->GetNowPose();
	}
	/// <summary>
	/// ポージング判定を取得
	/// </summary>
	bool GetIsPose()
	{
		return state->GetIsPose();
	}
private:
	////////////////////////
	//--------変数--------//
	////////////////////////
	Animation* animation;		//アニメーションクラス
	CharacterState* state;		//ステートクラス
	NPCModel* model;			//モデルクラス
	NPCInput* input;			//入力判定クラス
};