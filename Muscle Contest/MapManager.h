#pragma once
#include "Map.h"

class MapManager
{
public:
	////////////////////////
	//--------関数--------//
	////////////////////////
	//コンストラクタ
	MapManager();
	//デストラクタ
	~MapManager();
	//初期化
	void Init();
	//更新
	void Update();
private:
	////////////////////////
	//--------変数--------//
	////////////////////////
	Map map;		//マップクラス
};