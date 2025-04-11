#pragma once

class Score
{
public:
	////////////////////////
	//--------関数--------//
	////////////////////////
	//コンストラクタ
	Score();
	//デストラクタ
	~Score();
	//初期化
	void Init();
	//更新
	void Update(int _successCount, bool _isSuccess);
	//スコア加算
	void AddScore(int _successCount, bool _isSuccess);
	//描画
	void Draw();

	/// <summary>
	/// スコアを取得
	/// </summary>
	int GetScore()
	{
		return score;
	}
private:
	////////////////////////
	//--------変数--------//
	////////////////////////
	int score;					//現在のスコア
	int scoreFontHandle;		//スコアのフォントハンドル
	bool isAddScore;			//スコアの加算判定

	////////////////////////
	//--------定数--------//
	////////////////////////
	static constexpr int AddScoreValue = 200;		//加算されるスコア
	static constexpr int ScoreBonus = 40;			//スコアボーナス

	const int ScoreColor = GetColor(255, 255, 255);				//スコアの文字カラー
	static constexpr int ScorePosX = 50;                        //スコアの描画座標X
	static constexpr int ScorePosY = 50;                        //スコアの描画座標Y
	static constexpr int ScoreFontSize = 50;                    //スコアの文字サイズ
	static constexpr int ScoreFontThick = 6;                    //スコアの文字の太さ
	static constexpr int ScoreFontEdgeSize = 7;                 //スコアの文字縁のサイズ
};

