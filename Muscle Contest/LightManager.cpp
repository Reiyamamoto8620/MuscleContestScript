#include "DxLib.h"
#include "LightManager.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
LightManager::LightManager() :
	light(*new Light)
{

}
/// <summary>
/// �f�X�g���N�^
/// </summary>
LightManager::~LightManager()
{

}
/// <summary>
/// ������
/// </summary>
void LightManager::Init()
{
	light.Init();
}