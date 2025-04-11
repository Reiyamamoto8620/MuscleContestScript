#include "DxLib.h"
#include "PlaySceneManager.h"
/// <summary>
/// �R���X�g���N�^
/// </summary>
PlaySceneManager::PlaySceneManager() :
	playScene(*new PlayScene)
{

}
/// <summary>
/// �f�X�g���N�^
/// </summary>
PlaySceneManager::~PlaySceneManager()
{

}
/// <summary>
/// ������
/// </summary>
void PlaySceneManager::Init()
{
	playScene.Init();
}
/// <summary>
/// �X�V
/// </summary>
void PlaySceneManager::Update(int _score, bool _isNPCPose, int _npcState,
	int _nowNPCPose, bool _isPlayerPose, int _playerState)
{
	playScene.Update(_score, _isNPCPose, _npcState, _nowNPCPose, _isPlayerPose, _playerState);
}