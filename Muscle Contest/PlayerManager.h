#pragma once
#include "Input.h"
#include "CharacterState.h"
#include "Animation.h"
#include "PlayerModel.h"

class PlayerManager
{
public:
	////////////////////////
	//--------�֐�--------//
	////////////////////////
	//�R���X�g���N�^
	PlayerManager();
	//�f�X�g���N�^
	~PlayerManager();
	//�X�V
	void Update(int _successCount, int _sceneState,bool _isNPCPose, bool _isFinishJudge);
	//������
	void Init();

	/// <summary>
	/// �X�e�[�g���擾
	/// </summary>
	int GetState()
	{
		return (int)state->GetState();
	}
	/// <summary>
	/// �|�[�W���O������擾
	/// </summary>
	bool GetIsPose()
	{
		return state->GetIsPose();
	}
	/// <summary>
	/// �A�j���[�V�����̏I��������擾
	/// </summary>
	bool GetIsEndAnimation()
	{
		return animation->GetIsEndAnimation();
	}
private:
	////////////////////////
	//--------�ϐ�--------//
	////////////////////////
	Input* input;			//���͔���N���X
	Animation* animation;	//�A�j���[�V�����N���X
	CharacterState* state;	//�X�e�[�g�N���X
	PlayerModel* model;		//���f���N���X
};

