#include "DxLib.h"
#include "TitleSceneManager.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
TitleSceneManager::TitleSceneManager():
	titleScene(*new TitleScene),
	input(*new Input),
	hitKeyCheck(*new HitKeyCheck)
{

}
/// <summary>
/// �f�X�g���N�^
/// </summary>
TitleSceneManager::~TitleSceneManager()
{

}
/// <summary>
/// ������
/// </summary>
void TitleSceneManager::Init()
{
	titleScene.Init();
	input.Init();
	hitKeyCheck.Init();
}
/// <summary>
/// �X�V
/// </summary>
void TitleSceneManager::Update()
{
	input.Update(!hitKeyCheck.GetIsHitKey());
	hitKeyCheck.HitKeyOnce();
	titleScene.Update(input.GetIsRight(),input.GetIsLeft(),input.GetIsEnter());
}