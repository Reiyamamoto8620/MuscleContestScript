#pragma once
#include "ResultScene.h"
#include "Input.h"
#include "HitKeyCheck.h"
class ResultSceneManager
{
public:
	////////////////////////
	//--------�֐�--------//
	////////////////////////
	//�R���X�g���N�^
	ResultSceneManager();
	//�f�X�g���N�^
	~ResultSceneManager();
	//������
	void Init();
	//�X�V
	void Update(int _score);
	
	/// <summary>
	/// ���̃V�[���ɐi�ޔ�����擾
	/// </summary>
	bool GetIsNext()
	{
		return resultScene.GetIsNext();
	}
	/// <summary>
	/// ���v���C������擾
	/// </summary>
	bool GetIsReplay()
	{
		return resultScene.GetIsReplay();
	}
	/// <summary>
	/// �^�C�g���V�[���ɖ߂锻����擾
	/// </summary>
	bool GetIsBackTitle()
	{
		return resultScene.GetIsBackTitle();
	}
	/// <summary>
	/// �{�^���I�𔻒���擾
	/// </summary>
	bool GetIsSelect()
	{
		return resultScene.GetIsSelect();
	}
	/// <summary>
	/// ���蔻����擾
	/// </summary>
	bool GetIsEnter()
	{
		return resultScene.GetIsEnter();
	}
private:
	////////////////////////
	//--------�ϐ�--------//
	////////////////////////
	ResultScene resultScene;		//���U���g�V�[���̃N���X
	Input input;					//���͔���̃N���X
	HitKeyCheck hitKeyCheck;		//���͐����̃N���X
};