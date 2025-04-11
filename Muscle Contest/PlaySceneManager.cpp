#include "DxLib.h"
#include "PlaySceneManager.h"
/// <summary>
/// コンストラクタ
/// </summary>
PlaySceneManager::PlaySceneManager() :
	playScene(*new PlayScene)
{

}
/// <summary>
/// デストラクタ
/// </summary>
PlaySceneManager::~PlaySceneManager()
{

}
/// <summary>
/// 初期化
/// </summary>
void PlaySceneManager::Init()
{
	playScene.Init();
}
/// <summary>
/// 更新
/// </summary>
void PlaySceneManager::Update(int _score, bool _isNPCPose, int _npcState,
	int _nowNPCPose, bool _isPlayerPose, int _playerState)
{
	playScene.Update(_score, _isNPCPose, _npcState, _nowNPCPose, _isPlayerPose, _playerState);
}