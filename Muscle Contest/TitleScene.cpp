#include "DxLib.h"
#include "TitleScene.h"

/// <summary>
/// コンストラクタ
/// </summary>
TitleScene::TitleScene() :
	isNext(false),
	isStart(false),
	isEnd(false),
	isScore(false),
	isDrawScore(false),
	isEnter(false),
	selectButtonIndex(0),
	titleImg(LoadGraph("Data/Img/Title/GameTitle.png")),
	startImg(LoadGraph("Data/Img/Title/Start.png")),
	endImg(LoadGraph("Data/Img/Title/End.png")),
	scoreImg(LoadGraph("Data/Img/Title/Score.png")),
	creditFontHandle(CreateFontToHandle("Dela Gothic one", CreditFontSize, CreditFontThick,
		DX_FONTTYPE_ANTIALIASING_EDGE, -1, CreditFontEdgeSize))
{

}
/// <summary>
/// デストラクタ
/// </summary>
TitleScene::~TitleScene()
{

}
/// <summary>
/// 初期化
/// </summary>
void TitleScene::Init()
{
	selectButtonIndex = 0;
	isNext = false;
	isStart = true;
	isEnd = false;
	isScore = false;
	isDrawScore = false;
	isEnter = false;
}
/// <summary>
/// 更新
/// </summary>
void TitleScene::Update(bool _isRight, bool _isLeft, bool _isSpace)
{
	isSelect = false;
	isEnter = false;
	//ボタンを選択
	SelectButton(_isRight,_isLeft,_isSpace);

	//SPACEが押されたとき
	if (_isSpace)
	{
		//決定SEを再生
		isEnter = true;
		//isScoreがfalseなら
		if (!isScore)
		{
			//次に進む
			isNext = true;
		}
		//isScoreがtrueでisDrawScoreがFalseの場合Scoreを描画する
		if (isScore && !isDrawScore)
		{
			isDrawScore = true;
		}
		//isScoreがtrueでisDrawScoreがtrueの場合Scoreを描画をしない
		else if (isScore && isDrawScore)
		{
			isDrawScore = false;
		}
	}
	//描画
	Draw();
}
/// <summary>
/// 描画
/// </summary>
void TitleScene::Draw()
{
	//タイトルの画像を描画
	DrawBillboard3D(TitlePos, TitleImgCenter, TitleImgCenter, TitleImgSize, 0, titleImg, TRUE);
	//クレジットを表示
	DrawStringToHandle(CreditPosX, CreditPosY, "BGM : 魔王魂", CreditColor, creditFontHandle);
	//ボタンを描画
	DrawButton();
}
/// <summary>
/// ボタンを描画
/// </summary>
void TitleScene::DrawButton()
{
	//スコアランキングを表示している場合
	if (isDrawScore)
	{
		//スコアランキングを表示中は全てのボタンをブレンドして描画
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, NotSelectBlendPal);
		DrawGraph(StartImgPosX, StartImgPosY, startImg, true);
		DrawGraph(ScoreImgPosX, ScoreImgPosY, scoreImg, true);
		DrawGraph(EndImgPosX, EndImgPosY, endImg, true);
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, BlendPalMax);
	}
	//Startボタンを選択中の場合
	else if (selectButtonIndex == (int)SelectButtonIndex::Start)
	{
		//選択中のStartをブレンドなしで描画
		DrawGraph(StartImgPosX, StartImgPosY, startImg, true);
		//選択外のボタンをブレンドして描画
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, NotSelectBlendPal);
		DrawGraph(ScoreImgPosX, ScoreImgPosY, scoreImg, true);
		DrawGraph(EndImgPosX, EndImgPosY, endImg, true);
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, BlendPalMax);
	}
	//Scoreボタンを選択中の場合
	else if (selectButtonIndex == (int)SelectButtonIndex::Score)
	{
		//選択中のScoreをブレンドなしで描画
		DrawGraph(ScoreImgPosX, ScoreImgPosY, scoreImg, true);
		//選択外のボタンをブレンドして描画
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, NotSelectBlendPal);
		DrawGraph(StartImgPosX, StartImgPosY, startImg, true);
		DrawGraph(EndImgPosX, EndImgPosY, endImg, true);
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, BlendPalMax);
	}
	//Endボタンを選択中の場合
	else if (selectButtonIndex == (int)SelectButtonIndex::End)
	{
		//選択中のEndをブレンドなしで描画
		DrawGraph(EndImgPosX, EndImgPosY, endImg, true);
		//選択外のボタンをブレンドして描画
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, NotSelectBlendPal);
		DrawGraph(StartImgPosX, StartImgPosY, startImg, true);
		DrawGraph(ScoreImgPosX, ScoreImgPosY, scoreImg, true);
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, BlendPalMax);
	}
}
/// <summary>
/// 入力から選択中のボタンを判定
/// </summary>
void TitleScene::SelectButton(bool _isRight, bool _isLeft,bool _isSpace)
{
	if (!isDrawScore)
	{
		//右が押されたとき
		if (_isRight)
		{
			//選択中のボタンを一つ右にずらす
			selectButtonIndex++;
			//選択SEを再生
			isSelect = true;
			//選択中のボタンのインデックスが最大を越えたら
			if (selectButtonIndex > SelectButtonIndexMax)
			{
				//スタートボタンのインデックスを代入する
				selectButtonIndex = (int)SelectButtonIndex::Start;
			}
		}
		//左が押されたとき
		else if (_isLeft)
		{
			//選択中のボタンを一つ左にずらす
			selectButtonIndex--;
			//選択SEを再生
			isSelect = true;
			//選択中のボタンのインデックスが最小を越えたら
			if (selectButtonIndex < SelectButtonIndexMin)
			{
				//エンドボタンのインデックスを代入する
				selectButtonIndex = (int)SelectButtonIndex::End;
			}
		}
		isStart = false;
		isScore = false;
		isEnd = false;
		//選択中のボタンがSTARTの場合
		if (selectButtonIndex == (int)SelectButtonIndex::Start)
		{
			//Start判定をTRUE
			isStart = true;
		}
		if (selectButtonIndex == (int)SelectButtonIndex::Score)
		{
			//Score判定をTRUE
			isScore = true;
		}
		if (selectButtonIndex == (int)SelectButtonIndex::End)
		{
			//End判定をTRUE
			isEnd = true;
		}
	}
}