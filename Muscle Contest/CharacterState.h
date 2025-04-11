#pragma once
class CharacterState
{
public:
	//�X�e�[�g�̃f�[�^�x�[�X
	enum State
	{
		Idle,			//Idle���
		UpPose,			//����͂̃|�[�W���O���
		DownPose,		//�����͂̃|�[�W���O���
		RightPose,		//�E���͂̃|�[�W���O���
		LeftPose,		//�����͂̃|�[�W���O���
		FinishDance,	//���U���g�ł̃_���X���
		None			//�Y���Ȃ��̏��
	};

	////////////////////////
	//--------�֐�--------//
	////////////////////////
	//�R���X�g���N�^
	CharacterState();
	//�f�X�g���N�^
	~CharacterState();
	//������
	void Init();
	//�X�V
	void Update(bool _isUp, bool _isDown,
		bool _isRight, bool _isLeft, bool _isDance, bool _isEndAnimation, bool _isFinishJudge);

	/// <summary>
	/// �X�e�[�g���擾
	/// </summary>
	int GetState()
	{
		return (int)state;
	}
	/// <summary>
	/// �O�t���[���̃X�e�[�g���擾
	/// </summary>
	int GetLastTimeState()
	{
		return (int)lastTimeState;
	}
	/// <summary>
	/// �|�[�W���O������擾
	/// </summary>
	bool GetIsPose()
	{
		return isPose;
	}
	/// <summary>
	/// ���݂̃|�[�Y���擾
	/// </summary>
	int GetNowPose()
	{
		return nowPose;
	}

private:
	////////////////////////
	//--------�֐�--------//
	////////////////////////
	//�X�e�[�g���Z�b�g
	void SetState(bool _isUp, bool _isDown,
		bool _isRight, bool _isLeft, bool _isdance,bool _isEndAnimation);
	//�|�[�W���O����̊m�F
	void CheckIsPose(bool _isFinishJudge);

	////////////////////////
	//--------�ϐ�--------//
	////////////////////////
	State state;			//���݂̃X�e�[�g
	State lastTimeState;	//�O�t���[���̃X�e�[�g

	int nowPose;			//���݂̃|�[�Y
	bool isPose;			//�|�[�W���O����
};