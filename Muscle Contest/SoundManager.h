#pragma once
#include "BackgroundMusic.h"
#include "SoundEffect.h"

class SoundManager
{
public:
	////////////////////////
	//--------関数--------//
	////////////////////////
	//コンストラクタ
	SoundManager();
	//デストラクタ
	~SoundManager();
	//初期化
	void Init();
	//更新
	void Update(int _sceneState, int _successCount, bool _isSuccess, bool _isMiss, 
		bool _isSelect, bool _isEnter, bool _isNPCPose, bool _isStart);
private:
	////////////////////////
	//--------変数--------//
	////////////////////////
	BackgroundMusic backgroundMusic;		//BGMクラス
	SoundEffect soundEffect;				//SEクラス
};

