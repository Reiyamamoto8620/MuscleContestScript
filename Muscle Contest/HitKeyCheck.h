#pragma once
class HitKeyCheck
{
public:
	////////////////////////
	//--------関数--------//
	////////////////////////
	//コンストラクタ
	HitKeyCheck();
	//デストラクタ
	~HitKeyCheck();
	//初期化
	void Init();
	//一度に１つしかキーを押せないようにする
	void HitKeyOnce();

	/// <summary>
	/// キーがすでに押されているかの判定を取得
	/// </summary>
	bool GetIsHitKey()
	{
		return isHitKey;
	}

private:
	////////////////////////
	//--------変数--------//
	////////////////////////
	bool isHitKey;		//キーがすでに押されているかの判定
};

