#pragma once

class NPCModel
{

public:
	////////////////////////
	//--------関数--------//
	////////////////////////
	//コンストラクタ
	NPCModel();
	//デストラクタ
	~NPCModel();
	//初期化
	void Init();
	//更新
	void Update();

	/// <summary>
	/// モデルを取得
	/// </summary>
	int GetModel()
	{
		return model;
	}
	/// <summary>
	/// モデルを格納
	/// </summary>
	void SetModel(int _model)
	{
		model = _model;
	}

private:
	////////////////////////
	//--------関数--------//
	////////////////////////
	//描画
	void Draw();

	////////////////////////
	//--------変数--------//
	////////////////////////
	int model;			//プレイヤーのモデル

	////////////////////////
	//--------定数--------//
	////////////////////////
	const VECTOR ModelScale = VGet(0.015f, 0.015f, 0.015f);		//モデルの拡大率
	const VECTOR Position = VGet(-2.0f, 1.5f, 25.0f);			//初期座標
};

