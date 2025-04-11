#include "DxLib.h"
#include "SceneManager.h"
#include "NPCManager.h"
/// <summary>
/// �R���X�g���N�^
/// </summary>
NPCManager::NPCManager() :
	animation(new Animation),
	state(new CharacterState),
	model(new NPCModel),
	input(new NPCInput)
{

}
/// <summary>
/// �f�X�g���N�^
/// </summary>
NPCManager::~NPCManager()
{

}
/// <summary>
/// ������
/// </summary>
void NPCManager::Init()
{
	model->SetModel(animation->Init(model->GetModel()));
	state->Init();
	input->Init();
	model->Init();
}
/// <summary>
/// �X�V
/// </summary>
void NPCManager::Update(int _successCount,int _sceneState,
	bool _isPlayerPose, bool _isFinishJudge)
{
	if (_sceneState == SceneManager::SceneState::PlayScene)
	{
		//���͂̍X�V
		input->Update(state->GetIsPose(),_isPlayerPose);
	}
	//�X�e�[�g�̍X�V
	state->Update(input->GetIsUp(), input->GetIsDown(),
		input->GetIsRight(), input->GetIsLeft(), 
		_sceneState == SceneManager::SceneState::ResultScene,
		animation->GetIsEndAnimation(),_isFinishJudge);
	//�A�j���[�V�����̍X�V�ƁA�X�V�����A�j���[�V������K�p�������f�����i�[
	model->SetModel(animation->Update(model->GetModel(), 
		state->GetState(),state->GetLastTimeState(), _successCount));
	//���f���̍X�V
	model->Update();
}