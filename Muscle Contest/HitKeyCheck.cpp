#include "DxLib.h"
#include "HitKeyCheck.h"
/// <summary>
/// �R���X�g���N�^
/// </summary>
HitKeyCheck::HitKeyCheck() :
	isHitKey(false)
{

}
/// <summary>
/// �f�X�g���N�^
/// </summary>
HitKeyCheck::~HitKeyCheck()
{

}
/// <summary>
/// ������
/// </summary>
void HitKeyCheck::Init()
{
	isHitKey = false;
}
/// <summary>
/// ��x�ɂP�����L�[�������Ȃ��悤�ɂ���
/// </summary>
void HitKeyCheck::HitKeyOnce()
{
	//�L�[��������Ă��邩������Ă��Ȃ����̔���
	if (CheckHitKeyAll())
	{
		//������Ă���ꍇ��isHitKey��true��
		isHitKey = true;
	}
	else
	{
		//������Ă���Ȃ��ꍇ��isHitKey��false��
		isHitKey = false;
	}
}