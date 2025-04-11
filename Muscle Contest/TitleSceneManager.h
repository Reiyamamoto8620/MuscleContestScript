#pragma once
#include "TitleScene.h"
#include "Input.h"
#include "HitKeyCheck.h"

class TitleSceneManager
{
public:
	////////////////////////
	//--------関数--------//
	////////////////////////
	//コンストラクタ
	TitleSceneManager();
	//デストラクタ
	~TitleSceneManager();
	//初期化
	void Init();
	//更新
	void Update();

	/// <summary>
	/// ボタン選択判定を取得
	/// </summary>
	bool GetIsSelect()
	{
		return titleScene.GetIsSelect();
	}
	/// <summary>
	/// 次のシーンに進む判定を取得
	/// </summary>
	bool GetIsNext()
	{
		return titleScene.GetIsNext();
	}
	/// <summary>
	/// スコアの描画判定を取得
	/// </summary>
	bool GetIsDrawScore()
	{
		return titleScene.GetIsDrawScore();
	}
	/// <summary>
	/// ゲームの終了判定を取得
	/// </summary>
	bool GetIsEnd()
	{
		return titleScene.GetIsEnd();
	}
	/// <summary>
	/// 決定判定を取得
	/// </summary>
	bool GetIsEnter()
	{
		return titleScene.GetIsEnter();
	}
private:
	////////////////////////
	//--------変数--------//
	////////////////////////
	TitleScene titleScene;		//タイトルシーンのクラス
	Input input;				//入力受付のクラス
	HitKeyCheck hitKeyCheck;	//入力制限のクラス
};