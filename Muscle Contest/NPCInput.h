#pragma once
class NPCInput
{
public:
	////////////////////////
	//--------関数--------//
	////////////////////////
	//コンストラクタ
	NPCInput();
	//デストラクタ
	~NPCInput();
	//初期化
	void Init();
	//更新
	void Update(bool _isPose,bool _isPlayerPose);

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
private:
	////////////////////////
	//--------変数--------//
	////////////////////////
	bool isUp;			//上入力の判定
	bool isDown;		//下入力の判定
	bool isRight;		//右入力の判定
	bool isLeft;		//左入力の判定
	int nowInput;		//現在の入力

	////////////////////////
	//--------定数--------//
	////////////////////////
	static constexpr int SelectInputMax = 3;	//選択される入力値の最大
};

