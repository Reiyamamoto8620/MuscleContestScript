#include "DxLib.h"
#include "SceneManager.h"
#include "Camera.h"
/// <summary>
/// �R���X�g���N�^
/// </summary>
Camera::Camera() : 
	position (VGet(0,0,0))
{
	//�J������Near,Far���Z�b�g
	SetCameraNearFar(NearPosition, FarPosition);
}
/// <summary>
/// �f�X�g���N�^
/// </summary>
Camera::~Camera()
{

}
/// <summary>
/// �X�V
/// </summary>
void Camera::Update()
{
	SetCameraPositionAndAngle(position, 0, 0, 0);
}
/// <summary>
/// ������
/// </summary>
void Camera::Init(int _sceneState)
{
	//�V�[���̏�Ԃ�Title�̎����s
	if (_sceneState == SceneManager::SceneState::TitleScene)
	{
		SetTitleCameraPosition();
	}
	//�V�[���̏�Ԃ�Play�̎����s
	else if (_sceneState == SceneManager::SceneState::PlayScene ||
		_sceneState == SceneManager::SceneState::WaitPlayScene)
	{
		SetPlayCameraPosition();
	}
	//�V�[���̏�Ԃ�Result�̎����s
	else if (_sceneState == SceneManager::SceneState::ResultScene)
	{
		SetResultCameraPosition();
	}
	//�V�[���̏�Ԃ����̑��̎����s
	else
	{
		SetErrorCameraPosition();
	}
}
/// <summary>
/// �J�����̍��W���^�C�g���p�̍��W�ɃZ�b�g
/// </summary>
void Camera::SetTitleCameraPosition()
{
	position = TitleCameraPosition;
}
/// <summary>
/// �J�����̍��W���v���C�V�[���p�̍��W�ɃZ�b�g
/// </summary>
void Camera::SetPlayCameraPosition()
{
	position = PlayCameraPosition;
}
/// <summary>
/// �J�����̍��W�����U���g�p�̍��W�ɃZ�b�g
/// </summary>
void Camera::SetResultCameraPosition()
{
	position = ResultCameraPosition;
}
/// <summary>
/// �J�����̍��W���G���[�p�̍��W�ɃZ�b�g
/// </summary>
void Camera::SetErrorCameraPosition()
{
	position = ErrorCameraPosition;
}