#pragma once
#include "BackgroundMusic.h"
#include "SoundEffect.h"

class SoundManager
{
public:
	////////////////////////
	//--------�֐�--------//
	////////////////////////
	//�R���X�g���N�^
	SoundManager();
	//�f�X�g���N�^
	~SoundManager();
	//������
	void Init();
	//�X�V
	void Update(int _sceneState, int _successCount, bool _isSuccess, bool _isMiss, 
		bool _isSelect, bool _isEnter, bool _isNPCPose, bool _isStart);
private:
	////////////////////////
	//--------�ϐ�--------//
	////////////////////////
	BackgroundMusic backgroundMusic;		//BGM�N���X
	SoundEffect soundEffect;				//SE�N���X
};

