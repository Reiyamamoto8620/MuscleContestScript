#include "DxLib.h"
#include "ResultSceneManager.h"
/// <summary>
/// コンストラクタ
/// </summary>
ResultSceneManager::ResultSceneManager():
	resultScene(*new ResultScene),
	input(*new Input),
	hitKeyCheck(*new HitKeyCheck)
{

}
/// <summary>
/// デストラクタ
/// </summary>
ResultSceneManager::~ResultSceneManager()
{

}
/// <summary>
/// 初期化
/// </summary>
void ResultSceneManager::Init()
{
	resultScene.Init();
	input.Init();
	hitKeyCheck.Init();
}
/// <summary>
/// 更新
/// </summary>
void ResultSceneManager::Update(int _score)
{
	input.Update(!hitKeyCheck.GetIsHitKey());
	hitKeyCheck.HitKeyOnce();
	resultScene.Update(input.GetIsRight(),input.GetIsLeft(),input.GetIsEnter(), _score);
}