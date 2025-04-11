#pragma once
#include "Camera.h"
class CameraManager
{
public:
	////////////////////////
	//--------関数--------//
	////////////////////////
	//コンストラクタ
	CameraManager();
	//デストラクタ
	~CameraManager();
	//初期化
	void Init(int _sceneState);
	//更新
	void Update();
private:
	Camera camera;		//カメラクラス
};

