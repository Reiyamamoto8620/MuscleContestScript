#pragma once
#include "Map.h"

class MapManager
{
public:
	////////////////////////
	//--------�֐�--------//
	////////////////////////
	//�R���X�g���N�^
	MapManager();
	//�f�X�g���N�^
	~MapManager();
	//������
	void Init();
	//�X�V
	void Update();
private:
	////////////////////////
	//--------�ϐ�--------//
	////////////////////////
	Map map;		//�}�b�v�N���X
};