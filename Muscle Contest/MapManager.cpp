#include "DxLib.h"
#include "MapManager.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
MapManager::MapManager() :
	map(*new Map)
{

}
/// <summary>
/// �f�X�g���N�^
/// </summary>
MapManager::~MapManager()
{

}
/// <summary>
/// ������
/// </summary>
void MapManager::Init()
{
	map.Init();
}
/// <summary>
/// �X�V
/// </summary>
void MapManager::Update()
{
	map.Draw();
}