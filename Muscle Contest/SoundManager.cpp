#include "DxLib.h"
#include "SoundManager.h"
/// <summary>
/// コンストラクタ
/// </summary>
SoundManager::SoundManager() :
	backgroundMusic(*new BackgroundMusic),
	soundEffect(*new SoundEffect)
{

}
/// <summary>
/// デストラクタ
/// </summary>
SoundManager::~SoundManager()
{

}
/// <summary>
/// 初期化
/// </summary>
void SoundManager::Init()
{
	backgroundMusic.Init();
}
/// <summary>
/// 更新
/// </summary>
void SoundManager::Update(int _sceneState,int _successCount, bool _isSuccess, bool _isMiss, 
	bool _isSelect, bool _isEnter, bool _isNPCPose, bool _isStart)
{
	backgroundMusic.Update(_sceneState, _successCount);
	soundEffect.Update(_isSuccess, _isMiss, _isSelect, _isEnter, _isNPCPose, _isStart);
}