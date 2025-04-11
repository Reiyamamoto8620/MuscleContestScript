#include "DxLib.h"
#include "Score.h"

/// <summary>
/// コンストラクタ
/// </summary>
Score::Score() :
	score(0),
	isAddScore(false),
	scoreFontHandle(CreateFontToHandle("Dela gothic one",
		ScoreFontSize, ScoreFontThick, DX_FONTTYPE_ANTIALIASING_EDGE, -1, ScoreFontEdgeSize))
{

}
/// <summary>
/// デストラクタ
/// </summary>
Score::~Score()
{

}
/// <summary>
/// 初期化
/// </summary>
void Score::Init()
{
	score = 0;
	isAddScore = false;
}
/// <summary>
/// 更新
/// </summary>
void Score::Update(int _successCount, bool _isSuccess)
{
	AddScore(_successCount, _isSuccess);
	Draw();
}
/// <summary>
/// スコアを加算
/// </summary>
void Score::AddScore(int _successCount, bool _isSuccess)
{
	//ポージングが成功していて、まだスコアを加算していない場合実行
	if (_isSuccess && isAddScore)
	{
		//スコアを加算
		score += AddScoreValue + ScoreBonus * _successCount;
		isAddScore = false;
	}
	//ポージングが成功していないとき実行
	else if (!_isSuccess)
	{
		isAddScore = true;
	}
}
/// <summary>
/// 描画
/// </summary>
void Score::Draw()
{
	//スコアを描画
	DrawFormatStringToHandle(ScorePosX, ScorePosY, ScoreColor, 
		scoreFontHandle, "SCORE : %d", score);
}