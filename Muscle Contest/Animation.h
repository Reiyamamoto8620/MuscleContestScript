#pragma once
#include "iostream"
#include "vector"

class Animation
{
public:
	////////////////////////
	//--------関数--------//
	////////////////////////
	//コンストラクタ
	Animation();
	//デストラクタ
	~Animation();
	//初期化
	int Init(int _model);
	//更新
	int Update(int _model, int _state,  int _lastTimeState,int _successCount);

	/// <summary>
	/// アニメーションの終了判定を取得
	/// </summary>
	bool GetIsEndAnimation()
	{
		return isEndAnimation;
	}
private:
	////////////////////////
	//--------関数--------//
	////////////////////////
	//アニメーションのセット
	int SetAnimation(int _state, int _model);
	//アニメーションの再生
	int PlayAnimation(int _model,int _successCount);
	//アニメーションのブレンド
	int BlendAnimation(int _model);
	//Idleアニメーションのセット
	int SetIdle(int _model);

	////////////////////////
	//--------変数--------//
	////////////////////////
	std::vector<int> animation;		//アニメーションの格納
	std::vector<int> index;			//アニメーションのインデックス
	float animationTime;			//アニメーションの現在の再生時間
	float blendValue;				//アニメーションのブレンド値
	bool isEndAnimation;			//アニメーションが終了した

	////////////////////////
	//--------定数--------//
	////////////////////////
	static constexpr float 
		BlendValueMax = 1.0f;						//ブレンド値の最大
	static constexpr int 
		AttachAnimationBlendValue = 2;				//アタッチされたアニメーションをブレンドする最低値
	static constexpr float 
		BlendSpeed = 0.2f;							//アニメーションブレンドの速度
	static constexpr int 
		AnimationSpeed = 1;							//アニメーションの再生速度
	static constexpr int 
		ChangeSuccessCountToAnimationSpeed = 30;	//コンボ数をアニメーションの速度に適応するための計算用
	static constexpr int 
		AddAnimationSpeedMax = 1;					//アニメーションの再生速度の加算値
	static constexpr int 
		AnimationMax = 6;							//アニメーションの最大数
	static constexpr int 
		AnimationIndexSizeMax = 3;					//アタッチできるアニメーションの最大数
	static constexpr int 
		BlendBeforAnimationIndex = 0;				//ブレンドする前のアニメーションのインデックス
	static constexpr int 
		BlendAfterAnimationIndex = 1;				//ブレンドする後のアニメーションのインデックス
};

