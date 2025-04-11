#include "DxLib.h"
#include "ResultSceneManager.h"
/// <summary>
/// �R���X�g���N�^
/// </summary>
ResultSceneManager::ResultSceneManager():
	resultScene(*new ResultScene),
	input(*new Input),
	hitKeyCheck(*new HitKeyCheck)
{

}
/// <summary>
/// �f�X�g���N�^
/// </summary>
ResultSceneManager::~ResultSceneManager()
{

}
/// <summary>
/// ������
/// </summary>
void ResultSceneManager::Init()
{
	resultScene.Init();
	input.Init();
	hitKeyCheck.Init();
}
/// <summary>
/// �X�V
/// </summary>
void ResultSceneManager::Update(int _score)
{
	input.Update(!hitKeyCheck.GetIsHitKey());
	hitKeyCheck.HitKeyOnce();
	resultScene.Update(input.GetIsRight(),input.GetIsLeft(),input.GetIsEnter(), _score);
}