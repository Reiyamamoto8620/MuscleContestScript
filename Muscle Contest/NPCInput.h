#pragma once
class NPCInput
{
public:
	////////////////////////
	//--------�֐�--------//
	////////////////////////
	//�R���X�g���N�^
	NPCInput();
	//�f�X�g���N�^
	~NPCInput();
	//������
	void Init();
	//�X�V
	void Update(bool _isPose,bool _isPlayerPose);

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
private:
	////////////////////////
	//--------�ϐ�--------//
	////////////////////////
	bool isUp;			//����͂̔���
	bool isDown;		//�����͂̔���
	bool isRight;		//�E���͂̔���
	bool isLeft;		//�����͂̔���
	int nowInput;		//���݂̓���

	////////////////////////
	//--------�萔--------//
	////////////////////////
	static constexpr int SelectInputMax = 3;	//�I���������͒l�̍ő�
};

