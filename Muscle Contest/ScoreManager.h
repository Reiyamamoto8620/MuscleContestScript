#pragma once
#include "Score.h"

//プロトタイプ宣言
class Score;

class ScoreManager
{
public:
	////////////////////////
	//--------関数--------//
	////////////////////////
	//コンストラクタ
	ScoreManager();
	//デストラクタ
	~ScoreManager();
	//初期化
	void Init();
	//更新
	void Update(int _successCount,bool _isSuccess);

	/// <summary>
	/// スコアを取得
	/// </summary>
	int GetScore()
	{
		return score.GetScore();
	}
private:
	////////////////////////
	//--------変数--------//
	////////////////////////
	Score score;		//スコアクラス
};

