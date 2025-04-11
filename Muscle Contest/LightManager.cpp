#include "DxLib.h"
#include "LightManager.h"

/// <summary>
/// コンストラクタ
/// </summary>
LightManager::LightManager() :
	light(*new Light)
{

}
/// <summary>
/// デストラクタ
/// </summary>
LightManager::~LightManager()
{

}
/// <summary>
/// 初期化
/// </summary>
void LightManager::Init()
{
	light.Init();
}