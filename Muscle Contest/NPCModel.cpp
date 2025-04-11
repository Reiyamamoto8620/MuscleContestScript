#include "DxLib.h"
#include "NPCModel.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
NPCModel::NPCModel() :
	model(MV1LoadModel("Data/Model/NPCModel.mv1"))
{
	//���f���̃X�P�[����ݒ�
	MV1SetScale(model, ModelScale);
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
NPCModel::~NPCModel()
{
	//���f�����폜
	MV1DeleteModel(model);
}

/// <summary>
/// ������
/// </summary>
void NPCModel::Init()
{
	//���f���̍��W��ݒ�
	MV1SetPosition(model, Position);
}

/// <summary>
/// �X�V
/// </summary>
void NPCModel::Update()
{
	Draw();
}

/// <summary>
/// �`��
/// </summary>
void NPCModel::Draw()
{
	MV1DrawModel(model);
}