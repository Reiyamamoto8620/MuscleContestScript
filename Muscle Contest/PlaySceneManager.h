#pragma once
#include "PlayScene.h"
class PlaySceneManager
{
public:
	////////////////////////
	//--------�֐�--------//
	////////////////////////
	//�R���X�g���N�^
	PlaySceneManager();
	//�f�X�g���N�^
	~PlaySceneManager();
	//������
	void Init();
	//�X�V
	void Update(int _score, bool _isNPCPose, int _npcState,
		int _nowNPCPose, bool _isPlayerPose, int _playerState);

	/// <summary>
	/// �Q�[���̃X�^�[�g������擾
	/// </summary>
	bool GetIsStart()
	{
		return playScene.GetIsStart();
	}
	/// <summary>
	/// �|�[�W���O�̔���̏I��������擾
	/// </summary>
	bool GetIsFinishJudge()
	{
		return playScene.GetIsFinishJudge();
	}
	/// <summary>
	/// �A�������񐔂̎擾
	/// </summary>
	int GetSuccessCount()
	{
		return playScene.GetSuccessCount();
	}
	/// <summary>
	/// �Q�[���I��������擾
	/// </summary>
	bool GetIsGameEnd()
	{
		return playScene.GetIsGameEnd();
	}
	/// <summary>
	/// ����������擾
	/// </summary>
	bool GetIsSuccess()
	{
		return playScene.GetIsSuccess();
	}
	/// <summary>
	/// ���s������擾
	/// </summary>
	bool GetIsMiss()
	{
		return playScene.GetIsMiss();
	}
	/// <summary>
	/// �Q�[���X�^�[�gSE������擾
	/// </summary>
	bool GetIsStartSE()
	{
		return playScene.GetIsStartSE();
	}

private:
	////////////////////////
	//--------�ϐ�--------//
	////////////////////////
	PlayScene playScene;		//�v���C�V�[���̃N���X
};