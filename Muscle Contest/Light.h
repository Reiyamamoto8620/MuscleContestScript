#pragma once

class Light
{
public:
	////////////////////////
	//--------�֐�--------//
	////////////////////////
	//�R���X�g���N�^
	Light();
	//�f�X�g���N�^
	~Light();
	//������
	void Init();
private:
	////////////////////////
	//--------�萔--------//
	////////////////////////
	const VECTOR LightDirection = VGet(1,-1,1);				//���C�g�̊p�x
};