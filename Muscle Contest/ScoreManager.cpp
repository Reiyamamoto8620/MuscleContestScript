#include "DxLib.h"
#include "ScoreManager.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
ScoreManager::ScoreManager() :
	score(*new Score)
{

}

/// <summary>
/// �f�X�g���N�^
/// </summary>
ScoreManager::~ScoreManager()
{

}

/// <summary>
/// ������
/// </summary>
void ScoreManager::Init()
{
	score.Init();
}

/// <summary>
/// �X�V
/// </summary>
void ScoreManager::Update(int _successCount, bool _isSuccess)
{
	score.Update(_successCount,_isSuccess);
}