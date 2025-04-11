#include "DxLib.h"
#include "PlayerManager.h"
#include "SceneManager.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
PlayerManager::PlayerManager()
{
	input = new Input();
	animation = new Animation();
	state = new CharacterState();
	model = new PlayerModel();
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
PlayerManager::~PlayerManager()
{

}

/// <summary>
/// ������
/// </summary>
void PlayerManager::Init()
{
	model->SetModel(animation->Init(model->GetModel()));
	input->Init();
	state->Init();
	model->Init();
}

/// <summary>
/// �X�V
/// </summary>
void PlayerManager::Update(int _successCount, int _sceneState, 
	bool _isNPCPose, bool _isFinishJudge)
{
	if (_sceneState == SceneManager::SceneState::PlayScene)
	{
		//���͂̍X�V
		input->Update(_isNPCPose && !state->GetIsPose());
	}
	//�X�e�[�g�̍X�V
	state->Update(input->GetIsUp(), input->GetIsDown(),
		input->GetIsRight(), input->GetIsLeft(), 
		_sceneState == SceneManager::SceneState::ResultScene,
		animation->GetIsEndAnimation(), _isFinishJudge);
	//�A�j���[�V�����̍X�V�ƁA�X�V�����A�j���[�V������K�p�������f�����i�[
	model->SetModel(animation->Update(
		model->GetModel(), state->GetState(), state->GetLastTimeState(), _successCount));
	//���f���̍X�V
	model->Update();
}