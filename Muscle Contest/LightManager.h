#pragma once
#include "Light.h"

class LightManager
{
public:
	////////////////////////
	//--------関数--------//
	////////////////////////
	//コンストラクタ
	LightManager();
	//デストラクタ
	~LightManager();
	//初期化
	void Init();
private:
	////////////////////////
	//--------関数--------//
	////////////////////////
	Light light;	//ライトクラス
};