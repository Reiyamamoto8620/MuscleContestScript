#pragma once
class HitKeyCheck
{
public:
	////////////////////////
	//--------�֐�--------//
	////////////////////////
	//�R���X�g���N�^
	HitKeyCheck();
	//�f�X�g���N�^
	~HitKeyCheck();
	//������
	void Init();
	//��x�ɂP�����L�[�������Ȃ��悤�ɂ���
	void HitKeyOnce();

	/// <summary>
	/// �L�[�����łɉ�����Ă��邩�̔�����擾
	/// </summary>
	bool GetIsHitKey()
	{
		return isHitKey;
	}

private:
	////////////////////////
	//--------�ϐ�--------//
	////////////////////////
	bool isHitKey;		//�L�[�����łɉ�����Ă��邩�̔���
};

