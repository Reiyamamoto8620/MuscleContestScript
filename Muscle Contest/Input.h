#pragma once
class Input
{

public:
	////////////////////////
	//--------�֐�--------//
	////////////////////////
	//�R���X�g���N�^
	Input();
	//�f�X�g���N�^
	~Input();
	//������
	void Init();
	//�X�V
	void Update(bool _isInput);

	/// <summary>
	/// ����͂̔�����擾
	/// </summary>
	bool GetIsUp()
	{
		return isUp;
	}
	/// <summary>
	/// �����͂̔�����擾
	/// </summary>
	bool GetIsDown()
	{
		return isDown;
	}
	/// <summary>
	/// �E���͂̔�����擾
	/// </summary>
	bool GetIsRight()
	{
		return isRight;
	}
	/// <summary>
	/// �����͂̔�����擾
	/// </summary>
	bool GetIsLeft()
	{
		return isLeft;
	}
	/// <summary>
	/// �G���^�[���͂̔�����擾
	/// </summary>
	bool GetIsEnter()
	{
		return isEnter;
	}

private:
	////////////////////////
	//--------�֐�--------//
	////////////////////////
	//���͂��擾
	void GetInputKey(bool _isInput);

	////////////////////////
	//--------�ϐ�--------//
	////////////////////////
	bool isUp;			//����͂̔���
	bool isDown;		//�����͂̔���
	bool isRight;		//�E���͂̔���
	bool isLeft;		//�����͂̔���
	bool isEnter;		//�G���^�[���͂̔���

};

