#include "DxLib.h"
#include "SceneManager.h"
#include "Camera.h"
/// <summary>
/// コンストラクタ
/// </summary>
Camera::Camera() : 
	position (VGet(0,0,0))
{
	//カメラのNear,Farをセット
	SetCameraNearFar(NearPosition, FarPosition);
}
/// <summary>
/// デストラクタ
/// </summary>
Camera::~Camera()
{

}
/// <summary>
/// 更新
/// </summary>
void Camera::Update()
{
	SetCameraPositionAndAngle(position, 0, 0, 0);
}
/// <summary>
/// 初期化
/// </summary>
void Camera::Init(int _sceneState)
{
	//シーンの状態がTitleの時実行
	if (_sceneState == SceneManager::SceneState::TitleScene)
	{
		SetTitleCameraPosition();
	}
	//シーンの状態がPlayの時実行
	else if (_sceneState == SceneManager::SceneState::PlayScene ||
		_sceneState == SceneManager::SceneState::WaitPlayScene)
	{
		SetPlayCameraPosition();
	}
	//シーンの状態がResultの時実行
	else if (_sceneState == SceneManager::SceneState::ResultScene)
	{
		SetResultCameraPosition();
	}
	//シーンの状態がその他の時実行
	else
	{
		SetErrorCameraPosition();
	}
}
/// <summary>
/// カメラの座標をタイトル用の座標にセット
/// </summary>
void Camera::SetTitleCameraPosition()
{
	position = TitleCameraPosition;
}
/// <summary>
/// カメラの座標をプレイシーン用の座標にセット
/// </summary>
void Camera::SetPlayCameraPosition()
{
	position = PlayCameraPosition;
}
/// <summary>
/// カメラの座標をリザルト用の座標にセット
/// </summary>
void Camera::SetResultCameraPosition()
{
	position = ResultCameraPosition;
}
/// <summary>
/// カメラの座標をエラー用の座標にセット
/// </summary>
void Camera::SetErrorCameraPosition()
{
	position = ErrorCameraPosition;
}