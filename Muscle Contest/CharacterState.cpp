#include "CharacterState.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
CharacterState::CharacterState() :
	state(*new State),
	lastTimeState(*new State),
	isPose(false),
	nowPose(0)
{

}

/// <summary>
/// �f�X�g���N�^
/// </summary>
CharacterState::~CharacterState()
{

}

/// <summary>
/// ������
/// </summary>
void CharacterState::Init()
{
	state = State::Idle;
	lastTimeState = State::Idle;
	isPose = false;
	nowPose = 0;
}

/// <summary>
/// �X�V
/// </summary>
void CharacterState::Update(bool _isUp, bool _isDown,
	bool _isRight, bool _isLeft, bool _isDance, bool _isEndAnimation,bool _isFinishJudge)
{
	SetState(_isUp, _isDown, _isRight, _isLeft, _isDance, _isEndAnimation);
	CheckIsPose(_isFinishJudge);
}

/// <summary>
/// �X�e�[�g���Z�b�g
/// </summary>
void CharacterState::SetState(bool _isUp, bool _isDown,
	bool _isRight, bool _isLeft, bool _isDance, bool _isEndAnimation)
{

	if (state != State::Idle && _isEndAnimation)
	{
		//Idle��Ԃɐݒ�
		state = State::Idle;
	}
	//�O�t���[���̃X�e�[�g��ۑ�
	lastTimeState = state;

	if (state == State::Idle)
	{
		//�����͂�����ꍇ���������s
		if (_isLeft)
		{
			//�X�e�[�g�������͂̃|�[�W���O��Ԃɂ���
			state = State::LeftPose;
		}
		//�E���͂�����ꍇ���������s
		if (_isRight)
		{
			//�X�e�[�g���E���͂̃|�[�W���O��Ԃɂ���
			state = State::RightPose;
		}
		//�����͂�����ꍇ���������s
		if (_isDown)
		{
			//�X�e�[�g�������͂̃|�[�W���O��Ԃɂ���
			state = State::DownPose;
		}
		//����͂�����ꍇ���������s
		if (_isUp)
		{
			//�X�e�[�g������͂̃|�[�W���O��Ԃɂ���
			state = State::UpPose;
		}
	}
	//�Q�[���̏�Ԃ����U���g�̏ꍇ���������s
	if (_isDance)
	{
		//�X�e�[�g�����U���g�ł̃_���X��Ԃɂ���
		state = State::FinishDance;
	}
}
/// <summary>
/// �|�[�W���O����̊m�F
/// </summary>
void CharacterState::CheckIsPose(bool _isFinishJudge)
{
	//�X�e�[�g��Idle�ȊO�őO�t���[���̃X�e�[�g��Idle�̎����s
	if (state != State::Idle && lastTimeState == State::Idle)
	{
		//�|�[�W���O�����True
		isPose = true;
		//���݂̃|�[�Y���X�V
		nowPose = (int)state;
	}
	//�|�[�W���O�̊m�F���I�������Ƃ��Ɏ��s
	if (_isFinishJudge)
	{
		//�|�[�W���O�����False
		isPose = false;
	}
}