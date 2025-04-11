#include "DxLib.h"
#include "ScoreManager.h"

/// <summary>
/// コンストラクタ
/// </summary>
ScoreManager::ScoreManager() :
	score(*new Score)
{

}

/// <summary>
/// デストラクタ
/// </summary>
ScoreManager::~ScoreManager()
{

}

/// <summary>
/// 初期化
/// </summary>
void ScoreManager::Init()
{
	score.Init();
}

/// <summary>
/// 更新
/// </summary>
void ScoreManager::Update(int _successCount, bool _isSuccess)
{
	score.Update(_successCount,_isSuccess);
}