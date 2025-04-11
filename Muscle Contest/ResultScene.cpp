#include "DxLib.h"
#include "ResultScene.h"
/// <summary>
/// コンストラクタ
/// </summary>
ResultScene::ResultScene() :
	isNext(false),
	isReplay(false),
	isBackTitle(false),
	isSelect(false),
	isEnter(false),
	nowScore(0),
	nowScoreImgAddPosX(0),
	resultImg(LoadGraph("Data/Img/Result/Result.png")),
	replayImg(LoadGraph("Data/Img/Result/RePlay.png")),
	backTitleImg(LoadGraph("Data/Img/Result/Title.png")),
	highScoreImg(LoadGraph("Data/Img/Result/HighScore.png")),
	middleScoreImg(LoadGraph("Data/Img/Result/MiddleScore.png")),
	lowScoreImg(LoadGraph("Data/Img/Result/LowScore.png")),
	scoreFontHandle(CreateFontToHandle("Dela Gothic one", ScoreFontHandleSize, ScoreFontHandleThick,
		DX_FONTTYPE_ANTIALIASING_EDGE, -1, ScoreFontEdgeSize))
{

}
/// <summary>
/// デストラクタ
/// </summary>
ResultScene::~ResultScene()
{

}
/// <summary>
/// 初期化
/// </summary>
void ResultScene::Init()
{
	isNext = false;
	isReplay = true;
	isBackTitle = false;
	isSelect = false;
	isEnter = false;
	nowScore = 0;
	nowScoreImgAddPosX = NowScoreImgAddPosMaxX;
}
/// <summary>
/// 更新
/// </summary>
void ResultScene::Update(bool _isRight, bool _isLeft, bool _isSpace,int _score)
{
	isSelect = false;
	isEnter = false;
	SelectButton(_isRight, _isLeft, _isSpace);
	Draw(_score);
}
/// <summary>
/// 描画
/// </summary>
void ResultScene::Draw(int _score)
{
	int scoreWidth = 0;			//スコアの横幅
	//RESULTを描画
	DrawGraph(ResultImgPosX, ResultImgPosY, resultImg, true);
	//スコアの横幅を取得
	scoreWidth = GetDrawFormatStringWidthToHandle(scoreFontHandle, "%d", nowScore);
	//スコアを描画
	DrawFormatStringToHandle(ScorePosX, ScorePosY, ScoreColor, scoreFontHandle, "%d", nowScore);
	//スコアをカウントアップ
	CountUpScore(_score);

	if (_score == nowScore)
	{
		DrawScoreImg(nowScore);
	}

	//REPLAYが選択されている場合
	if (isReplay)
	{
		//REPLAYボタンを描画
		DrawGraph(RePlayImgPosX, RePlayImgPosY, replayImg, true);
		//選択されていないボタンを薄く表示する
		//ブレンド値をセット
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, NotSelectBlendPal);
		//BACKTITLEを描画
		DrawGraph(BackTitleImgPosX, BackTitleImgPosY, backTitleImg, true);
		//ブレンド値をデフォルトにセット
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, BlendPalMax);
	}
	//BACKTITLEが選択されている場合
	if (isBackTitle)
	{
		//BACKTITLEを描画
		DrawGraph(BackTitleImgPosX, BackTitleImgPosY, backTitleImg, true);
		//選択されていないボタンを薄く表示する
		//ブレンド値をセット
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, NotSelectBlendPal);
		//REPLAYボタンを描画
		DrawGraph(RePlayImgPosX, RePlayImgPosY, replayImg, true);
		//ブレンド値をデフォルトにセット
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, BlendPalMax);
	}
}
/// <summary>
/// スコアのカウントアップ演出
/// </summary>
void ResultScene::CountUpScore(int _score)
{
	//表示中のスコアが今回のスコアより小さい場合
	if (_score > nowScore)
	{
		//表示中のスコアを加算
		nowScore += AddNowScore;
	}
	//表示中のスコアが今回のスコアより以上場合
	if (_score <= nowScore)
	{
		//表示中のスコアに今回のスコアを代入
		nowScore = _score;
	}
}
/// <summary>
/// スコアの評価を描画
/// </summary>
void ResultScene::DrawScoreImg(int _nowScore)
{
	int nowScoreImg = 0;				//現在のスコア評価の画像

	//高得点評価
	if (_nowScore >= HighScoreMin)
	{
		//高得点評価画像を代入
		nowScoreImg = highScoreImg;
	}
	//中得点評価
	else if (_nowScore >= MiddleScoreMin)
	{
		//中得点評価画像を代入
		nowScoreImg = middleScoreImg;
	}
	//低得点評価
	else
	{
		//低得点評価画像を代入
		nowScoreImg = lowScoreImg;
	}
	//スコアを画面外から画面内に移動させる
	if (nowScoreImgAddPosX > 0)
	{
		//X座標の加算値を減らしていく
		nowScoreImgAddPosX -= NowScoreImgSpeed;
	}
	//得点評価画像を大きさを合わせて描画
	DrawExtendGraph(NowScoreImgPosMinX + nowScoreImgAddPosX, NowScoreImgPosMinY,
		NowScoreImgPosMaxX + nowScoreImgAddPosX,NowScoreImgPosMaxY, nowScoreImg, TRUE);
}
/// <summary>
/// ボタンの選択
/// </summary>
void ResultScene::SelectButton(bool _isRight, bool _isLeft, bool _isSpace)
{
	//右が押されたとき
	if (_isRight)
	{
		//選択時SEを再生
		isSelect = true;
		//ENDが選択される
		isBackTitle = true;
		isReplay = false;
	}
	//左が押されたとき
	else if (_isLeft)
	{
		//選択時SEを再生
		isSelect = true;
		//STARTが選択される
		isReplay = true;
		isBackTitle = false;
	}
	//SPACEが押されたとき
	if (_isSpace)
	{
		//選択時SEを再生
		isEnter = true;
		//次に進む
		isNext = true;
	}
}