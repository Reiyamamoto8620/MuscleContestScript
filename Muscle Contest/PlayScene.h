#pragma once

class Sound;

class PlayScene
{
public:
	////////////////////////
	//--------関数--------//
	////////////////////////
	//コンストラクタ
	PlayScene();
	//デストラクタ
	~PlayScene();
	//初期化
	void Init();
	//更新
	void Update(int _score,bool _isNPCPose, int _npcState, int _nowNPCPose, 
		bool _isPlayerPose, int _playerState);

	/// <summary>
	/// ゲームスタート判定を取得
	/// </summary>
	bool GetIsStart()
	{
		return isStart;
	}
	/// <summary>
	/// ポージングの判定の終了判定を取得
	/// </summary>
	bool GetIsFinishJudge()
	{
		return isFinishJudge;
	}
	/// <summary>
	/// 連続成功回数を取得
	/// </summary>
	int GetSuccessCount()
	{
		return successCount;
	}
	/// <summary>
	/// ゲームの終了判定を取得
	/// </summary>
	bool GetIsGameEnd()
	{
		return isGameEnd;
	}
	/// <summary>
	/// 成功判定を取得
	/// </summary>
	bool GetIsSuccess()
	{
		return isSuccess;
	}
	/// <summary>
	/// 失敗判定を取得
	/// </summary>
	bool GetIsMiss()
	{
		return isMiss;
	}
	/// <summary>
	/// ゲームスタートSE判定を取得
	/// </summary>
	bool GetIsStartSE()
	{
		return isStartSE;
	}
private:
	////////////////////////
	//--------関数--------//
	////////////////////////
	//描画
	void Draw();
	//ゲーム開始時間の計測
	void StartTimer();
	//成功時に観客を表示
	void RiseUpAudience(int _score);
	//ポージングの判定
	void CheckPose(bool _isNPCPose, int _npcState, 
		int _nowNPCPose,bool _isPlayerPose, int _playerState);
	//入力待機時間の確認
	bool InputTimeCheck(bool _isNPCPose, bool _isPlayerPose);
	//ゲーム時間のカウント
	void CountGameTime();


	////////////////////////
	//--------変数--------//
	////////////////////////
	bool isNext;					//次のシーンに進む判定
	bool isStart;					//ゲーム開始判定
	bool isStartSE;					//スタート時SEの再生判定
	bool isJudgeDraw;				//ポージング判定の描画判定
	bool isCheckPose;				//ポージングの確認判定
	bool isSuccess;					//ポージングの成功判定
	bool isMiss;					//ポージングの失敗判定
	bool isFinishJudge;				//ポージング判定の終了判定
	bool isGameEnd;					//ゲームの終了判定
	int successImg;					//成功判定の画像
	int missImg;					//失敗判定の画像
	int nowJudgeImg;				//現在のポージング判定の画像
	int startTime;					//ゲーム開始までの時間
	int readyImg;					//READYの画像
	int goImg;						//GO!!の画像
	int audienceImg;				//観客の画像
	int audiencePosY;				//観客の画像のY座標
	int playerImg;					//[Player]の画像
	int successCount;				//ポージングの連続成功回数
	int successCountFontHandle;		//連続成功回数のフォントハンドル
	int gameTimeCount;				//ゲーム内時間
	int gameTimeFontHandle;			//ゲーム内時間のフォントハンドル

	int comboFontHandle;			//コンボのフォントハンドル
	float playerImgAddPos;			//[Player]の座標の加算値
	VECTOR playerImgPos;			//[Player]の座標

	int inputTimer;					//入力待機時間


	////////////////////////
	//--------定数--------//
	////////////////////////
	static constexpr int FPS = 60;								//FPS

	static constexpr int StartTimeMax = 60;						//ゲームスタートまでの待機時間
	static constexpr int ReadyWaitTime = 40;					//READYの表示時間
	static constexpr int ReadyImgPosX = 1920 / 2 - 683 / 2;		//READYのX座標
	static constexpr int ReadyImgPosY = 1080 / 2 - 169 / 2;		//READYのY座標
	static constexpr int GoImgPosX = 1920 / 2 - 365 / 2;		//GO!!のX座標
	static constexpr int GoImgPosY = 1080 / 2 - 170 / 2;		//GO!!のY座標
	static constexpr int AudiencePosX = 0;						//観客の画像のX座標の初期値
	static constexpr int AudiencePosY = 480;					//観客の画像のY座標の初期値
	static constexpr int AudienceSpeed = 24;					//観客の移動速度上昇値
	static constexpr int AudienceLowScorePos = 240;				//低スコア時の観客の最大座標
	static constexpr int AudienceMiddleScorePos = 160;			//中スコア時の観客の最大座標

	static constexpr int HighScoreMin = 45000;					//高得点スコア評価の最小値
	static constexpr int MiddleScoreMin = 20000;				//中得点スコア評価の最小値

	static constexpr float PlayerImgSize = 2.0f;				//[Player]の描画サイズ
	static constexpr float PlayerImgCenter = 0.5f;				//[Player]の画像の中心
	static constexpr float PlayerImgPosMinY = 5.5f;				//[Player]の最小Y座標
	static constexpr float PlayerImgPosMaxY = 5.625f;			//[Player]の最大Y座標
	static constexpr float PlayerImgAddPos = 0.008f;			//[Player]の座標加算値
	const VECTOR PlayerImgPos = VGet(2, 5.5f, 25);				//[Player]の描画座標

	static constexpr float JudgeImgSize = 2.5f;					//ポージング判定の描画サイズ
	static constexpr float JudgeImgCenter = 0.5f;				//ポージング判定の画像の中心
	const VECTOR JudgeImgPos = VGet(2, 5.625, 25);				//ポージング判定の描画座標

	static constexpr int InputTimerMax = 60;					//入力待機時間の最大

	static constexpr int InputTimerGaugeMinX = 0;				//入力待機時間ゲージのXの最小座標
	static constexpr int InputTimerGaugeMinY = 1060;			//入力待機時間ゲージのYの最小座標
	static constexpr int InputTimerGaugeMaxX = 1920;			//入力待機時間ゲージのXの最大座標
	static constexpr int InputTimerGaugeMaxY = 1080;			//入力待機時間ゲージのYの最大座標
	const int InputTimerGaugeColor = GetColor(0, 255, 0);		//入力待機時間ゲージの色

	static constexpr int InputTimerGaugeFrameMinX = 0;			//入力待機時間ゲージ枠のXの最小座標
	static constexpr int InputTimerGaugeFrameMinY = 1060;		//入力待機時間ゲージ枠のYの最小座標
	static constexpr int InputTimerGaugeFrameMaxX = 1920;		//入力待機時間ゲージ枠のXの最大座標
	static constexpr int InputTimerGaugeFrameMaxY = 1080;		//入力待機時間ゲージ枠のYの最大座標
	const int InputTimerGaugeFrameColor = GetColor(255, 0, 0);	//入力待機時間ゲージ枠の色

	static constexpr int InputTimerGaugeDecreaseNum = 32;		//入力待機時間のゲージの減る値
	static constexpr int SuccessCountFontSize = 100;			//連続成功回数のフォントサイズ
	static constexpr int SuccessCountFontThick = 6;				//連続成功回数の文字幅
	static constexpr int SuccessCountFontEdgeSize = 7;			//連続成功回数の縁の幅
	static constexpr int SuccessCountPosX = 1870;				//連続成功回数のX座標
	static constexpr int SuccessCountPosY = 700;				//連続成功回数のY座標
	const int SuccessCountColor = GetColor(255, 255, 255);		//連続成功回数の色
	static constexpr int ComboFontSize = 50;					//文字列[COMBO]のフォントサイズ
	static constexpr int ComboFontThick = 6;					//文字列[COMBO]の文字幅
	static constexpr int ComboFontEdgeSize = 7;					//文字列[COMBO]の縁の幅
	static constexpr int ComboPosX = 1555;						//文字列[COMBO]のX座標
	static constexpr int ComboPosY = 810;						//文字列[COMBO]のY座標
	const int ComboColor = GetColor(255, 255, 255);				//文字列[COMBO]の色
	static constexpr int GameTimeMax = 60 * 60;					//ゲームの残り時間の最大
	static constexpr int GameTimeFontSize = 50;					//ゲームの残り時間のフォントサイズ
	static constexpr int GameTimeFontThick = 6;					//ゲームの残り時間の文字幅
	static constexpr int GameTimeFontEdgeSize = 7;				//ゲームの残り時間の縁の幅
	static constexpr int GameTimePosX = 960;					//ゲームの残り時間のX座標
	static constexpr int GameTimePosY = 50;						//ゲームの残り時間のY座標
	const int GameTimeColor = GetColor(255, 255, 255);			//ゲームの残り時間の色

};