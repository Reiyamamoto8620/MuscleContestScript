#include "DxLib.h"
#include "CameraManager.h"

/// <summary>
/// コンストラクタ
/// </summary>
CameraManager::CameraManager() :
	camera(*new Camera)
{

}
/// <summary>
/// デストラクタ
/// </summary>
CameraManager::~CameraManager()
{

}
/// <summary>
/// 初期化
/// </summary>
void CameraManager::Init(int _sceneState)
{
	camera.Init(_sceneState);
}
/// <summary>
/// 更新
/// </summary>
void CameraManager::Update()
{
	camera.Update();
}