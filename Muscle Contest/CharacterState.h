#pragma once
class CharacterState
{
public:
	//ステートのデータベース
	enum State
	{
		Idle,			//Idle状態
		UpPose,			//上入力のポージング状態
		DownPose,		//下入力のポージング状態
		RightPose,		//右入力のポージング状態
		LeftPose,		//左入力のポージング状態
		FinishDance,	//リザルトでのダンス状態
		None			//該当なしの状態
	};

	////////////////////////
	//--------関数--------//
	////////////////////////
	//コンストラクタ
	CharacterState();
	//デストラクタ
	~CharacterState();
	//初期化
	void Init();
	//更新
	void Update(bool _isUp, bool _isDown,
		bool _isRight, bool _isLeft, bool _isDance, bool _isEndAnimation, bool _isFinishJudge);

	/// <summary>
	/// ステートを取得
	/// </summary>
	int GetState()
	{
		return (int)state;
	}
	/// <summary>
	/// 前フレームのステートを取得
	/// </summary>
	int GetLastTimeState()
	{
		return (int)lastTimeState;
	}
	/// <summary>
	/// ポージング判定を取得
	/// </summary>
	bool GetIsPose()
	{
		return isPose;
	}
	/// <summary>
	/// 現在のポーズを取得
	/// </summary>
	int GetNowPose()
	{
		return nowPose;
	}

private:
	////////////////////////
	//--------関数--------//
	////////////////////////
	//ステートをセット
	void SetState(bool _isUp, bool _isDown,
		bool _isRight, bool _isLeft, bool _isdance,bool _isEndAnimation);
	//ポージング判定の確認
	void CheckIsPose(bool _isFinishJudge);

	////////////////////////
	//--------変数--------//
	////////////////////////
	State state;			//現在のステート
	State lastTimeState;	//前フレームのステート

	int nowPose;			//現在のポーズ
	bool isPose;			//ポージング判定
};