#pragma once
#include "Score.h"

//�v���g�^�C�v�錾
class Score;

class ScoreManager
{
public:
	////////////////////////
	//--------�֐�--------//
	////////////////////////
	//�R���X�g���N�^
	ScoreManager();
	//�f�X�g���N�^
	~ScoreManager();
	//������
	void Init();
	//�X�V
	void Update(int _successCount,bool _isSuccess);

	/// <summary>
	/// �X�R�A���擾
	/// </summary>
	int GetScore()
	{
		return score.GetScore();
	}
private:
	////////////////////////
	//--------�ϐ�--------//
	////////////////////////
	Score score;		//�X�R�A�N���X
};

