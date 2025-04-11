#pragma once

class TitleScene
{
public:
	////////////////////////
	//--------関数--------//
	////////////////////////
	//コンストラクタ
	TitleScene();
	//デストラクタ
	~TitleScene();
	//初期化
	void Init();
	//更新
	void Update(bool _isRight, bool _isLeft, bool _isSpace);

	/// <summary>
	/// 次のシーンに進む判定を取得
	/// </summary>
	bool GetIsNext()
	{
		return isNext;
	}
	/// <summary>
	/// ゲームの終了判定を取得
	/// </summary>
	bool GetIsEnd()
	{
		return isEnd;
	}
	/// <summary>
	/// スコアの描画判定を所得
	/// </summary>
	bool GetIsDrawScore()
	{
		return isDrawScore;
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

	//ボタンのインデックス
	enum class SelectButtonIndex
	{
		Start,
		Score,
		End
	};

private:
	////////////////////////
	//--------関数--------//
	////////////////////////
	//描画
	void Draw();
	//ボタンの描画
	void DrawButton();
	//入力から選択中のボタンを判定
	void SelectButton(bool _isRight, bool _isLeft,bool _isSpace);

	////////////////////////
	//--------変数--------//
	////////////////////////
	bool isNext;				//次のシーンに進む判定
	bool isEnd;					//ゲーム終了ボタン選択判定
	bool isStart;				//ゲーム開始ボタン選択判定
	bool isScore;				//スコア表示ボタン選択判定
	bool isDrawScore;			//スコア表示判定
	bool isEnter;				//決定ボタンを押した判定
	int selectButtonIndex;		//選択中のボタン番号
	int titleImg;				//タイトルの画像
	int startImg;				//STARTボタンの画像
	int endImg;					//ENDボタンの画像
	int scoreImg;				//SCOREボタンの画像

	int creditFontHandle;		//クレジットのフォントハンドル

	bool isSelect;				//ボタン選択時の判定

	////////////////////////
	//--------定数--------//
	////////////////////////
	static constexpr float TitleImgCenter = 0.5f;					//タイトル画像の中心点
	static constexpr float TitleImgSize = 7.5f;						//タイトルのY座標
	const VECTOR TitlePos = VGet(0, 6, 25);							//タイトルの座標
	static constexpr float StartImgPosX = 1920 / 4 - 669 / 2;       //スタートボタンのX座標
	static constexpr float StartImgPosY = 700;						//スタートボタンのY座標
	static constexpr float EndImgPosX = 1920 / 4 * 3 - 412 / 2;     //エンドボタンのX座標
	static constexpr float EndImgPosY = 700;						//エンドボタンのY座標
	static constexpr float ScoreImgPosX = 1920 / 2 - 683 / 2;		//スコアボタンのX座標
	static constexpr float ScoreImgPosY = 860;						//スコアボタンのY座標
	static constexpr int NotSelectBlendPal = 100;					//選択されていないボタンのブレンド値
	static constexpr int BlendPalMax = 255;							//ブレンド値の最大
	static constexpr int SelectButtonIndexMin = 0;					//ボタンのインデックスの最小
	static constexpr int SelectButtonIndexMax = 2;					//ボタンのインデックスの最大

	static constexpr int CreditFontSize = 30;						//クレジットのフォントサイズ
	static constexpr int CreditFontThick = 3;						//クレジットの太さ
	static constexpr int CreditFontEdgeSize = 3;					//クレジットの縁のサイズ
	static constexpr int CreditPosX = 10;							//クレジットのX座標
	static constexpr int CreditPosY = 10;							//クレジットのY座標
	const int CreditColor = GetColor(255, 255, 255);				//クレジットのカラー
};

