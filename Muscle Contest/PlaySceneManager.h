#pragma once
#include "PlayScene.h"
class PlaySceneManager
{
public:
	////////////////////////
	//--------関数--------//
	////////////////////////
	//コンストラクタ
	PlaySceneManager();
	//デストラクタ
	~PlaySceneManager();
	//初期化
	void Init();
	//更新
	void Update(int _score, bool _isNPCPose, int _npcState,
		int _nowNPCPose, bool _isPlayerPose, int _playerState);

	/// <summary>
	/// ゲームのスタート判定を取得
	/// </summary>
	bool GetIsStart()
	{
		return playScene.GetIsStart();
	}
	/// <summary>
	/// ポージングの判定の終了判定を取得
	/// </summary>
	bool GetIsFinishJudge()
	{
		return playScene.GetIsFinishJudge();
	}
	/// <summary>
	/// 連続成功回数の取得
	/// </summary>
	int GetSuccessCount()
	{
		return playScene.GetSuccessCount();
	}
	/// <summary>
	/// ゲーム終了判定を取得
	/// </summary>
	bool GetIsGameEnd()
	{
		return playScene.GetIsGameEnd();
	}
	/// <summary>
	/// 成功判定を取得
	/// </summary>
	bool GetIsSuccess()
	{
		return playScene.GetIsSuccess();
	}
	/// <summary>
	/// 失敗判定を取得
	/// </summary>
	bool GetIsMiss()
	{
		return playScene.GetIsMiss();
	}
	/// <summary>
	/// ゲームスタートSE判定を取得
	/// </summary>
	bool GetIsStartSE()
	{
		return playScene.GetIsStartSE();
	}

private:
	////////////////////////
	//--------変数--------//
	////////////////////////
	PlayScene playScene;		//プレイシーンのクラス
};