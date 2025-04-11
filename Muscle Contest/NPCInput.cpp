#include "DxLib.h"
#include "CharacterState.h"
#include "NPCInput.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
NPCInput::NPCInput() :
	isUp(false),
	isDown(false),
	isRight(false),
	isLeft(false),
	nowInput(0)
{

}

/// <summary>
/// �f�X�g���N�^
/// </summary>
NPCInput::~NPCInput()
{

}

/// <summary>
/// ������
/// </summary>
void NPCInput::Init()
{
	isUp = false;
	isDown = false;
	isRight = false;
	isLeft = false;
	nowInput = 0;
}

/// <summary>
/// �X�V
/// </summary>
void NPCInput::Update(bool _isPose, bool _isPlayerPose)
{
	Init();
	if (!_isPose && !_isPlayerPose)
	{
		//1�`4�������_���őI��(�����_���̍ŏ��l���X�e�[�g��UpPose(Value:1)�ɍ��킹��)
		nowInput = GetRand(SelectInputMax) + (int)CharacterState::State::UpPose;
	}

	//nowInput��UpPose��ԂƓ����l�̏ꍇ
	if (nowInput == (int)CharacterState::State::UpPose)
	{
		isUp = true;
	}
	//nowInput��DownPose��ԂƓ����l�̏ꍇ
	if (nowInput == (int)CharacterState::State::DownPose)
	{
		isDown = true;
	}
	//nowInput��RightPose��ԂƓ����l�̏ꍇ
	if (nowInput == (int)CharacterState::State::RightPose)
	{
		isRight = true;
	}
	//nowInput��LeftPose��ԂƓ����l�̏ꍇ
	if (nowInput == (int)CharacterState::State::LeftPose)
	{
		isLeft = true;
	}
}