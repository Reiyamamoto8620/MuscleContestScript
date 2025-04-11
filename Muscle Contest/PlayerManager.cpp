#include "DxLib.h"
#include "PlayerManager.h"
#include "SceneManager.h"

/// <summary>
/// コンストラクタ
/// </summary>
PlayerManager::PlayerManager()
{
	input = new Input();
	animation = new Animation();
	state = new CharacterState();
	model = new PlayerModel();
}

/// <summary>
/// デストラクタ
/// </summary>
PlayerManager::~PlayerManager()
{

}

/// <summary>
/// 初期化
/// </summary>
void PlayerManager::Init()
{
	model->SetModel(animation->Init(model->GetModel()));
	input->Init();
	state->Init();
	model->Init();
}

/// <summary>
/// 更新
/// </summary>
void PlayerManager::Update(int _successCount, int _sceneState, 
	bool _isNPCPose, bool _isFinishJudge)
{
	if (_sceneState == SceneManager::SceneState::PlayScene)
	{
		//入力の更新
		input->Update(_isNPCPose && !state->GetIsPose());
	}
	//ステートの更新
	state->Update(input->GetIsUp(), input->GetIsDown(),
		input->GetIsRight(), input->GetIsLeft(), 
		_sceneState == SceneManager::SceneState::ResultScene,
		animation->GetIsEndAnimation(), _isFinishJudge);
	//アニメーションの更新と、更新したアニメーションを適用したモデルを格納
	model->SetModel(animation->Update(
		model->GetModel(), state->GetState(), state->GetLastTimeState(), _successCount));
	//モデルの更新
	model->Update();
}