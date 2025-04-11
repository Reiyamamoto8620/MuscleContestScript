#pragma once

class NPCModel
{

public:
	////////////////////////
	//--------�֐�--------//
	////////////////////////
	//�R���X�g���N�^
	NPCModel();
	//�f�X�g���N�^
	~NPCModel();
	//������
	void Init();
	//�X�V
	void Update();

	/// <summary>
	/// ���f�����擾
	/// </summary>
	int GetModel()
	{
		return model;
	}
	/// <summary>
	/// ���f�����i�[
	/// </summary>
	void SetModel(int _model)
	{
		model = _model;
	}

private:
	////////////////////////
	//--------�֐�--------//
	////////////////////////
	//�`��
	void Draw();

	////////////////////////
	//--------�ϐ�--------//
	////////////////////////
	int model;			//�v���C���[�̃��f��

	////////////////////////
	//--------�萔--------//
	////////////////////////
	const VECTOR ModelScale = VGet(0.015f, 0.015f, 0.015f);		//���f���̊g�嗦
	const VECTOR Position = VGet(-2.0f, 1.5f, 25.0f);			//�������W
};

