#pragma once
#include "Light.h"

class LightManager
{
public:
	////////////////////////
	//--------�֐�--------//
	////////////////////////
	//�R���X�g���N�^
	LightManager();
	//�f�X�g���N�^
	~LightManager();
	//������
	void Init();
private:
	////////////////////////
	//--------�֐�--------//
	////////////////////////
	Light light;	//���C�g�N���X
};