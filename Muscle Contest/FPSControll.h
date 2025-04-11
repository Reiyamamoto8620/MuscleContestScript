#pragma once
#include "DxLib.h"
#include "Common.h"
class FPSControll
{
public:
	////////////////////////
	//--------�֐�--------//
	////////////////////////
	// �R���X�g���N�^
	FPSControll();
	// �f�X�g���N�^
	~FPSControll();
	// �X�V
	void Update();
	// 60�t���[���ɍ����悤�ɑҋ@
	void WaitFPS();
	// FPS��`��
	void DrawFPS();
	// FPS���v��
	void MeasureFPS();

private:
	////////////////////////
	//--------�ϐ�--------//
	////////////////////////
	double firstTime;								//�v���J�n����
	double maxTime;									//�t���[���̍ő�ҋ@����
	double fpcCheckTime;							//FPS�̌v�����J�n��������
	int fpsCount;									//FPS���J�E���g
	int fps;										//���݂�FPS

	////////////////////////
	//--------�萔--------//
	////////////////////////
	static constexpr float FrameMin = 0.0f;			//�Œ�l
	static constexpr float FrameMax = 16666.6f;		//1�t���[���̃}�C�N���b�@�@1,000,000�� / 60��
	static constexpr int FPSMax = 1000000;			//60�t���[���̃}�C�N���b
	const int FPSColor = GetColor(255, 255, 255);	//FPS�̕`��F
};

