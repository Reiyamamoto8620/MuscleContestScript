#pragma once
#include "TitleScene.h"
#include "Input.h"
#include "HitKeyCheck.h"

class TitleSceneManager
{
public:
	////////////////////////
	//--------�֐�--------//
	////////////////////////
	//�R���X�g���N�^
	TitleSceneManager();
	//�f�X�g���N�^
	~TitleSceneManager();
	//������
	void Init();
	//�X�V
	void Update();

	/// <summary>
	/// �{�^���I�𔻒���擾
	/// </summary>
	bool GetIsSelect()
	{
		return titleScene.GetIsSelect();
	}
	/// <summary>
	/// ���̃V�[���ɐi�ޔ�����擾
	/// </summary>
	bool GetIsNext()
	{
		return titleScene.GetIsNext();
	}
	/// <summary>
	/// �X�R�A�̕`�攻����擾
	/// </summary>
	bool GetIsDrawScore()
	{
		return titleScene.GetIsDrawScore();
	}
	/// <summary>
	/// �Q�[���̏I��������擾
	/// </summary>
	bool GetIsEnd()
	{
		return titleScene.GetIsEnd();
	}
	/// <summary>
	/// ���蔻����擾
	/// </summary>
	bool GetIsEnter()
	{
		return titleScene.GetIsEnter();
	}
private:
	////////////////////////
	//--------�ϐ�--------//
	////////////////////////
	TitleScene titleScene;		//�^�C�g���V�[���̃N���X
	Input input;				//���͎�t�̃N���X
	HitKeyCheck hitKeyCheck;	//���͐����̃N���X
};