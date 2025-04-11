#include "FPSControll.h"
/// <summary>
/// �R���X�g���N�^
/// </summary>
FPSControll::FPSControll()
{
	firstTime = FrameMin;
	maxTime = FrameMax;
	fpsCount = 0;
	fps = 0;
	fpcCheckTime = GetNowHiPerformanceCount();
}
/// <summary>
/// �f�X�g���N�^
/// </summary>
FPSControll::~FPSControll()
{

}
/// <summary>
/// �X�V
/// </summary>
void FPSControll::Update()
{
	firstTime = GetNowHiPerformanceCount();//���݂̌o�ߎ��Ԃ��擾
	fpsCount++;
	MeasureFPS();
}
/// <summary>
/// 60�t���[���ɍ����悤�ɑҋ@
/// </summary>
void FPSControll::WaitFPS()
{
	//Update�Ŏ擾�������Ԃƍ��̎��Ԃ̍����A���߂����Ԃ��r���ăt���[���𒲐߂���
	while (GetNowHiPerformanceCount() - firstTime < maxTime)
	{
		//�����Ȃ�
	}
	
}
/// <summary>
/// FPS��`��
/// </summary>
void FPSControll::DrawFPS()
{
	DrawFormatString(0, 0, FPSColor, "%d", fps);
}
/// <summary>
/// FPS���v��
/// </summary>
void FPSControll::MeasureFPS()
{
	//���̎��Ԃ��擾
	double nowTime = GetNowHiPerformanceCount();
	//���݂̂e�o�r���v�Z
	if (nowTime - fpcCheckTime > FPSMax)
	{
		fps = fpsCount;
		fpsCount = 0;
		fpcCheckTime = nowTime;
	}
}