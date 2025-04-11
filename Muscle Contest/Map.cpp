#include "DxLib.h"
#include "Map.h"
/// <summary>
/// �R���X�g���N�^
/// </summary>
Map::Map() : 
	gymModel(MV1LoadModel("Data/Map/Gym.mv1"))
{
	//���f���̑傫����ݒ�
	MV1SetScale(gymModel, GymScale);
}
/// <summary>
/// �f�X�g���N�^
/// </summary>
Map::~Map()
{
	MV1DeleteModel(gymModel);
}
/// <summary>
/// ������
/// </summary>
void Map::Init()
{
	//���f���ɍ��W���Z�b�g
	MV1SetPosition(gymModel, GymPosition);
}
/// <summary>
/// �`��
/// </summary>
void Map::Draw()
{
	//���f����`��
	MV1DrawModel(gymModel);
}