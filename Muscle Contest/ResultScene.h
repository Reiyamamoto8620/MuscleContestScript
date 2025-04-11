#pragma once

class Sound;

class ResultScene
{
public:
	////////////////////////
	//--------関数--------//
	////////////////////////
	//コンストラクタ
	ResultScene();
	//デストラクタ
	~ResultScene();
	//初期化
	void Init();
	//更新
	void Update(bool _isRight,bool _isLeft,bool _isSpace, int _score);

	/// <summary>
	/// 次のシーンに進む判定を取得
	/// </summary>
	bool GetIsNext()
	{
		return isNext;
	}
	/// <summary>
	/// リプレイ判定を取得
	/// </summary>
	bool GetIsReplay()
	{
		return isReplay;
	}
	/// <summary>
	/// タイトルシーンに戻る判定を取得
	/// </summary>
	bool GetIsBackTitle()
	{
		return isBackTitle;
	}
	/// <summary>
	/// ボタン選択判定を取得
	/// </summary>
	bool GetIsSelect()
	{
		return isSelect;
	}
	/// <summary>
	/// 決定判定を取得
	/// </summary>
	bool GetIsEnter()
	{
		return isEnter;
	}
private:
	////////////////////////
	//--------関数--------//
	////////////////////////
	//描画
	void Draw(int _score);
	//スコアにカウントアップ演出
	void CountUpScore(int _score);
	//スコアの評価を描画
	void DrawScoreImg(int _nowScore);
	//ボタンの選択
	void SelectButton(bool _isRight, bool _isLeft, bool _isSpace);

	////////////////////////
	//--------変数--------//
	////////////////////////
	bool isNext;			//次のシーンに進む判定
	bool isReplay;			//リプレイボタン選択判定
	bool isBackTitle;		//バックタイトルボタン選択判定
	bool isSelect;			//選択中のボタンが変更されたかの判定
	bool isEnter;			//決定ボタンの判定
	int nowScore;			//現在表示中のスコア
	int resultImg;			//RESULTの画像
	int replayImg;			//REPLAYの画像
	int backTitleImg;		//BACKTITLEの画像
	int highScoreImg;		//高得点時の画像
	int middleScoreImg;		//中得点時の画像
	int lowScoreImg;		//低得点時の画像
	int nowScoreImgAddPosX;	//現在のスコアの加算値
	int scoreFontHandle;	//スコアのフォントハンドル

	////////////////////////
	//--------定数--------//
	////////////////////////
	static constexpr int ResultImgPosX = 240;									//リザルトのX座標
	static constexpr int ResultImgPosY = 100;									//リザルトのY座標

	static constexpr int RePlayImgPosX = 1920 / 4 - 611 / 2;					//リプレイボタンのX座標
	static constexpr int RePlayImgPosY = 750;									//リプレイボタンのY座標

	static constexpr int BackTitleImgPosX = 1920 / 4 * 3 - 449 / 2;				//タイトルボタンのX座標
	static constexpr int BackTitleImgPosY = 750;								//タイトルボタンのY座標

	static constexpr int NotSelectBlendPal = 100;								//選択されていないボタンのブレンド値
	static constexpr int BlendPalMax = 255;										//デフォルトのブレンド値

	static constexpr int ScoreFontHandleSize = 150;								//スコアのフォントサイズ
	static constexpr int ScoreFontHandleThick = 6;								//スコアの太さ
	static constexpr int ScorePosX = 240;										//スコアのX座標
	static constexpr int ScorePosY = 300;										//スコアのY座標
	static constexpr int ScoreFontEdgeSize = 7;									//スコアの縁のサイズ
	const int ScoreColor = GetColor(255, 255, 255);								//スコアのカラー

	static constexpr int AddNowScore = 432;										//スコアカウントアップ時の加算値

	static constexpr int HighScoreMin = 45000;									//高得点スコア評価の最小値
	static constexpr int MiddleScoreMin = 20000;								//中得点スコア評価の最小値

	static constexpr int NowScoreImgSpeed = 40;									//スコア評価の画像の移動速度
	static constexpr int NowScoreImgPosMinX = 240;								//スコア評価の画像の最小X座標
	static constexpr int NowScoreImgPosMinY = 500;								//スコア評価の画像の最小Y座標
	static constexpr int NowScoreImgPosMaxX = 1017;								//スコア評価の画像の最大X座標
	static constexpr int NowScoreImgPosMaxY = 665;								//スコア評価の画像の最大Y座標

	static constexpr int NowScoreImgAddPosMaxX = 1680;							//スコア評価の画像の加算値の最大
};

