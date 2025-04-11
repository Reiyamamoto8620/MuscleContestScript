#include "DxLib.h"
#include "HitKeyCheck.h"
/// <summary>
/// コンストラクタ
/// </summary>
HitKeyCheck::HitKeyCheck() :
	isHitKey(false)
{

}
/// <summary>
/// デストラクタ
/// </summary>
HitKeyCheck::~HitKeyCheck()
{

}
/// <summary>
/// 初期化
/// </summary>
void HitKeyCheck::Init()
{
	isHitKey = false;
}
/// <summary>
/// 一度に１つしかキーを押せないようにする
/// </summary>
void HitKeyCheck::HitKeyOnce()
{
	//キーが押されているか押されていないかの判定
	if (CheckHitKeyAll())
	{
		//押されている場合はisHitKeyをtrueに
		isHitKey = true;
	}
	else
	{
		//押されているない場合はisHitKeyをfalseに
		isHitKey = false;
	}
}