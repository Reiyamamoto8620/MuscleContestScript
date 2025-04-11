#include "DxLib.h"
#include "SoundManager.h"
/// <summary>
/// �R���X�g���N�^
/// </summary>
SoundManager::SoundManager() :
	backgroundMusic(*new BackgroundMusic),
	soundEffect(*new SoundEffect)
{

}
/// <summary>
/// �f�X�g���N�^
/// </summary>
SoundManager::~SoundManager()
{

}
/// <summary>
/// ������
/// </summary>
void SoundManager::Init()
{
	backgroundMusic.Init();
}
/// <summary>
/// �X�V
/// </summary>
void SoundManager::Update(int _sceneState,int _successCount, bool _isSuccess, bool _isMiss, 
	bool _isSelect, bool _isEnter, bool _isNPCPose, bool _isStart)
{
	backgroundMusic.Update(_sceneState, _successCount);
	soundEffect.Update(_isSuccess, _isMiss, _isSelect, _isEnter, _isNPCPose, _isStart);
}