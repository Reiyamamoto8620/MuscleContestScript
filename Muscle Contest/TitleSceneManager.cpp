#include "DxLib.h"
#include "TitleSceneManager.h"

/// <summary>
/// コンストラクタ
/// </summary>
TitleSceneManager::TitleSceneManager():
	titleScene(*new TitleScene),
	input(*new Input),
	hitKeyCheck(*new HitKeyCheck)
{

}
/// <summary>
/// デストラクタ
/// </summary>
TitleSceneManager::~TitleSceneManager()
{

}
/// <summary>
/// 初期化
/// </summary>
void TitleSceneManager::Init()
{
	titleScene.Init();
	input.Init();
	hitKeyCheck.Init();
}
/// <summary>
/// 更新
/// </summary>
void TitleSceneManager::Update()
{
	input.Update(!hitKeyCheck.GetIsHitKey());
	hitKeyCheck.HitKeyOnce();
	titleScene.Update(input.GetIsRight(),input.GetIsLeft(),input.GetIsEnter());
}