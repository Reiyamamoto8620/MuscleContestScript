#include "DxLib.h"
#include "PlayerModel.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
PlayerModel::PlayerModel() :
	model(MV1LoadModel("Data/Model/PlayerModel.mv1"))
{
	//���f���̃X�P�[����ݒ�
	MV1SetScale(model, ModelScale);
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
PlayerModel::~PlayerModel()
{
	//���f�����폜
	MV1DeleteModel(model);
}

/// <summary>
/// ������
/// </summary>
void PlayerModel::Init()
{
	//���f���̍��W��ݒ�
	MV1SetPosition(model, Position);
}

/// <summary>
/// �X�V
/// </summary>
void PlayerModel::Update()
{
	Draw();
}

/// <summary>
/// �`��
/// </summary>
void PlayerModel::Draw()
{
	MV1DrawModel(model);
}