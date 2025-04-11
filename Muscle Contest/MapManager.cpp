#include "DxLib.h"
#include "MapManager.h"

/// <summary>
/// コンストラクタ
/// </summary>
MapManager::MapManager() :
	map(*new Map)
{

}
/// <summary>
/// デストラクタ
/// </summary>
MapManager::~MapManager()
{

}
/// <summary>
/// 初期化
/// </summary>
void MapManager::Init()
{
	map.Init();
}
/// <summary>
/// 更新
/// </summary>
void MapManager::Update()
{
	map.Draw();
}