#pragma once
#include "Camera.h"
class CameraManager
{
public:
	////////////////////////
	//--------�֐�--------//
	////////////////////////
	//�R���X�g���N�^
	CameraManager();
	//�f�X�g���N�^
	~CameraManager();
	//������
	void Init(int _sceneState);
	//�X�V
	void Update();
private:
	Camera camera;		//�J�����N���X
};

