#include "DxLib.h"
#include "CameraManager.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
CameraManager::CameraManager() :
	camera(*new Camera)
{

}
/// <summary>
/// �f�X�g���N�^
/// </summary>
CameraManager::~CameraManager()
{

}
/// <summary>
/// ������
/// </summary>
void CameraManager::Init(int _sceneState)
{
	camera.Init(_sceneState);
}
/// <summary>
/// �X�V
/// </summary>
void CameraManager::Update()
{
	camera.Update();
}