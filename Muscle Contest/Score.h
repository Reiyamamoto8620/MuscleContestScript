#pragma once

class Score
{
public:
	////////////////////////
	//--------�֐�--------//
	////////////////////////
	//�R���X�g���N�^
	Score();
	//�f�X�g���N�^
	~Score();
	//������
	void Init();
	//�X�V
	void Update(int _successCount, bool _isSuccess);
	//�X�R�A���Z
	void AddScore(int _successCount, bool _isSuccess);
	//�`��
	void Draw();

	/// <summary>
	/// �X�R�A���擾
	/// </summary>
	int GetScore()
	{
		return score;
	}
private:
	////////////////////////
	//--------�ϐ�--------//
	////////////////////////
	int score;					//���݂̃X�R�A
	int scoreFontHandle;		//�X�R�A�̃t�H���g�n���h��
	bool isAddScore;			//�X�R�A�̉��Z����

	////////////////////////
	//--------�萔--------//
	////////////////////////
	static constexpr int AddScoreValue = 200;		//���Z�����X�R�A
	static constexpr int ScoreBonus = 40;			//�X�R�A�{�[�i�X

	const int ScoreColor = GetColor(255, 255, 255);				//�X�R�A�̕����J���[
	static constexpr int ScorePosX = 50;                        //�X�R�A�̕`����WX
	static constexpr int ScorePosY = 50;                        //�X�R�A�̕`����WY
	static constexpr int ScoreFontSize = 50;                    //�X�R�A�̕����T�C�Y
	static constexpr int ScoreFontThick = 6;                    //�X�R�A�̕����̑���
	static constexpr int ScoreFontEdgeSize = 7;                 //�X�R�A�̕������̃T�C�Y
};

