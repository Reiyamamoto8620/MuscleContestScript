#pragma once
#include "NPCInput.h"
#include "CharacterState.h"
#include "Animation.h"
#include "NPCModel.h"

class NPCManager
{
public:
	////////////////////////
	//--------�֐�--------//
	////////////////////////
	//�R���X�g���N�^
	NPCManager();
	//�f�X�g���N�^
	~NPCManager();
	//������
	void Init();
	//�X�V
	void Update(int _successCount, int _sceneState,bool _isPlayerPose,bool _isFinishJudge);

	/// <summary>
	/// �X�e�[�g���擾
	/// </summary>
	int GetState()
	{
		return (int)state->GetState();
	}
	/// <summary>
	/// ���݂̃|�[�Y���擾
	/// </summary>
	int GetNowPose()
	{
		return state->GetNowPose();
	}
	/// <summary>
	/// �|�[�W���O������擾
	/// </summary>
	bool GetIsPose()
	{
		return state->GetIsPose();
	}
private:
	////////////////////////
	//--------�ϐ�--------//
	////////////////////////
	Animation* animation;		//�A�j���[�V�����N���X
	CharacterState* state;		//�X�e�[�g�N���X
	NPCModel* model;			//���f���N���X
	NPCInput* input;			//���͔���N���X
};