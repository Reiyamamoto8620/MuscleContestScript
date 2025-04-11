#pragma once
#include "ResultScene.h"
#include "Input.h"
#include "HitKeyCheck.h"
class ResultSceneManager
{
public:
	////////////////////////
	//--------関数--------//
	////////////////////////
	//コンストラクタ
	ResultSceneManager();
	//デストラクタ
	~ResultSceneManager();
	//初期化
	void Init();
	//更新
	void Update(int _score);
	
	/// <summary>
	/// 次のシーンに進む判定を取得
	/// </summary>
	bool GetIsNext()
	{
		return resultScene.GetIsNext();
	}
	/// <summary>
	/// リプレイ判定を取得
	/// </summary>
	bool GetIsReplay()
	{
		return resultScene.GetIsReplay();
	}
	/// <summary>
	/// タイトルシーンに戻る判定を取得
	/// </summary>
	bool GetIsBackTitle()
	{
		return resultScene.GetIsBackTitle();
	}
	/// <summary>
	/// ボタン選択判定を取得
	/// </summary>
	bool GetIsSelect()
	{
		return resultScene.GetIsSelect();
	}
	/// <summary>
	/// 決定判定を取得
	/// </summary>
	bool GetIsEnter()
	{
		return resultScene.GetIsEnter();
	}
private:
	////////////////////////
	//--------変数--------//
	////////////////////////
	ResultScene resultScene;		//リザルトシーンのクラス
	Input input;					//入力判定のクラス
	HitKeyCheck hitKeyCheck;		//入力制限のクラス
};