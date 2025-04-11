#include "DxLib.h"
#include "SceneManager.h"
#include "NPCManager.h"
/// <summary>
/// コンストラクタ
/// </summary>
NPCManager::NPCManager() :
	animation(new Animation),
	state(new CharacterState),
	model(new NPCModel),
	input(new NPCInput)
{

}
/// <summary>
/// デストラクタ
/// </summary>
NPCManager::~NPCManager()
{

}
/// <summary>
/// 初期化
/// </summary>
void NPCManager::Init()
{
	model->SetModel(animation->Init(model->GetModel()));
	state->Init();
	input->Init();
	model->Init();
}
/// <summary>
/// 更新
/// </summary>
void NPCManager::Update(int _successCount,int _sceneState,
	bool _isPlayerPose, bool _isFinishJudge)
{
	if (_sceneState == SceneManager::SceneState::PlayScene)
	{
		//入力の更新
		input->Update(state->GetIsPose(),_isPlayerPose);
	}
	//ステートの更新
	state->Update(input->GetIsUp(), input->GetIsDown(),
		input->GetIsRight(), input->GetIsLeft(), 
		_sceneState == SceneManager::SceneState::ResultScene,
		animation->GetIsEndAnimation(),_isFinishJudge);
	//アニメーションの更新と、更新したアニメーションを適用したモデルを格納
	model->SetModel(animation->Update(model->GetModel(), 
		state->GetState(),state->GetLastTimeState(), _successCount));
	//モデルの更新
	model->Update();
}