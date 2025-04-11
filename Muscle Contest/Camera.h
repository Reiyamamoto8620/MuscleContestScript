#pragma once


class Camera
{
public:
	////////////////////////
	//--------関数--------//
	////////////////////////
	//コンストラクタ
	Camera();
	//デストラクタ
	~Camera();
	//更新
	void Update();
	//初期化
	void Init(int _sceneState);
	//カメラの座標をタイトル用の座標にセット
	void SetTitleCameraPosition();
	//カメラの座標をプレイシーン用の座標にセット
	void SetPlayCameraPosition();
	//カメラの座標をリザルト用の座標にセット
	void SetResultCameraPosition();
	//カメラの座標をエラー用の座標にセット
	void SetErrorCameraPosition();
private:
	////////////////////////
	//--------変数--------//
	////////////////////////
	VECTOR position;			//カメラの座標

	////////////////////////
	//--------定数--------//
	////////////////////////
	const VECTOR PlayCameraPosition = VGet(0,3, 19.75);				//カメラのプレイシーンの座標
	const VECTOR ResultCameraPosition = VGet(0, 3, 19.75);			//カメラのリザルトの座標
	const VECTOR TitleCameraPosition = VGet(0, 4.25f, 19.25f);		//カメラのタイトルの座標
	const VECTOR ErrorCameraPosition = VGet(0, 0, 0);				//カメラのエラー時の座標
	static constexpr float NearPosition = 1;						//カメラのNear
	static constexpr float FarPosition = 100.0f;					//カメラのFar
};

