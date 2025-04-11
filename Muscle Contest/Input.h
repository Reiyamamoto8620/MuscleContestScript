#pragma once
class Input
{

public:
	////////////////////////
	//--------関数--------//
	////////////////////////
	//コンストラクタ
	Input();
	//デストラクタ
	~Input();
	//初期化
	void Init();
	//更新
	void Update(bool _isInput);

	/// <summary>
	/// 上入力の判定を取得
	/// </summary>
	bool GetIsUp()
	{
		return isUp;
	}
	/// <summary>
	/// 下入力の判定を取得
	/// </summary>
	bool GetIsDown()
	{
		return isDown;
	}
	/// <summary>
	/// 右入力の判定を取得
	/// </summary>
	bool GetIsRight()
	{
		return isRight;
	}
	/// <summary>
	/// 左入力の判定を取得
	/// </summary>
	bool GetIsLeft()
	{
		return isLeft;
	}
	/// <summary>
	/// エンター入力の判定を取得
	/// </summary>
	bool GetIsEnter()
	{
		return isEnter;
	}

private:
	////////////////////////
	//--------関数--------//
	////////////////////////
	//入力を取得
	void GetInputKey(bool _isInput);

	////////////////////////
	//--------変数--------//
	////////////////////////
	bool isUp;			//上入力の判定
	bool isDown;		//下入力の判定
	bool isRight;		//右入力の判定
	bool isLeft;		//左入力の判定
	bool isEnter;		//エンター入力の判定

};

