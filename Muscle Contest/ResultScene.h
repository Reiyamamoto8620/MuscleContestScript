#pragma once

class Sound;

class ResultScene
{
public:
	////////////////////////
	//--------�֐�--------//
	////////////////////////
	//�R���X�g���N�^
	ResultScene();
	//�f�X�g���N�^
	~ResultScene();
	//������
	void Init();
	//�X�V
	void Update(bool _isRight,bool _isLeft,bool _isSpace, int _score);

	/// <summary>
	/// ���̃V�[���ɐi�ޔ�����擾
	/// </summary>
	bool GetIsNext()
	{
		return isNext;
	}
	/// <summary>
	/// ���v���C������擾
	/// </summary>
	bool GetIsReplay()
	{
		return isReplay;
	}
	/// <summary>
	/// �^�C�g���V�[���ɖ߂锻����擾
	/// </summary>
	bool GetIsBackTitle()
	{
		return isBackTitle;
	}
	/// <summary>
	/// �{�^���I�𔻒���擾
	/// </summary>
	bool GetIsSelect()
	{
		return isSelect;
	}
	/// <summary>
	/// ���蔻����擾
	/// </summary>
	bool GetIsEnter()
	{
		return isEnter;
	}
private:
	////////////////////////
	//--------�֐�--------//
	////////////////////////
	//�`��
	void Draw(int _score);
	//�X�R�A�ɃJ�E���g�A�b�v���o
	void CountUpScore(int _score);
	//�X�R�A�̕]����`��
	void DrawScoreImg(int _nowScore);
	//�{�^���̑I��
	void SelectButton(bool _isRight, bool _isLeft, bool _isSpace);

	////////////////////////
	//--------�ϐ�--------//
	////////////////////////
	bool isNext;			//���̃V�[���ɐi�ޔ���
	bool isReplay;			//���v���C�{�^���I�𔻒�
	bool isBackTitle;		//�o�b�N�^�C�g���{�^���I�𔻒�
	bool isSelect;			//�I�𒆂̃{�^�����ύX���ꂽ���̔���
	bool isEnter;			//����{�^���̔���
	int nowScore;			//���ݕ\�����̃X�R�A
	int resultImg;			//RESULT�̉摜
	int replayImg;			//REPLAY�̉摜
	int backTitleImg;		//BACKTITLE�̉摜
	int highScoreImg;		//�����_���̉摜
	int middleScoreImg;		//�����_���̉摜
	int lowScoreImg;		//�ᓾ�_���̉摜
	int nowScoreImgAddPosX;	//���݂̃X�R�A�̉��Z�l
	int scoreFontHandle;	//�X�R�A�̃t�H���g�n���h��

	////////////////////////
	//--------�萔--------//
	////////////////////////
	static constexpr int ResultImgPosX = 240;									//���U���g��X���W
	static constexpr int ResultImgPosY = 100;									//���U���g��Y���W

	static constexpr int RePlayImgPosX = 1920 / 4 - 611 / 2;					//���v���C�{�^����X���W
	static constexpr int RePlayImgPosY = 750;									//���v���C�{�^����Y���W

	static constexpr int BackTitleImgPosX = 1920 / 4 * 3 - 449 / 2;				//�^�C�g���{�^����X���W
	static constexpr int BackTitleImgPosY = 750;								//�^�C�g���{�^����Y���W

	static constexpr int NotSelectBlendPal = 100;								//�I������Ă��Ȃ��{�^���̃u�����h�l
	static constexpr int BlendPalMax = 255;										//�f�t�H���g�̃u�����h�l

	static constexpr int ScoreFontHandleSize = 150;								//�X�R�A�̃t�H���g�T�C�Y
	static constexpr int ScoreFontHandleThick = 6;								//�X�R�A�̑���
	static constexpr int ScorePosX = 240;										//�X�R�A��X���W
	static constexpr int ScorePosY = 300;										//�X�R�A��Y���W
	static constexpr int ScoreFontEdgeSize = 7;									//�X�R�A�̉��̃T�C�Y
	const int ScoreColor = GetColor(255, 255, 255);								//�X�R�A�̃J���[

	static constexpr int AddNowScore = 432;										//�X�R�A�J�E���g�A�b�v���̉��Z�l

	static constexpr int HighScoreMin = 45000;									//�����_�X�R�A�]���̍ŏ��l
	static constexpr int MiddleScoreMin = 20000;								//�����_�X�R�A�]���̍ŏ��l

	static constexpr int NowScoreImgSpeed = 40;									//�X�R�A�]���̉摜�̈ړ����x
	static constexpr int NowScoreImgPosMinX = 240;								//�X�R�A�]���̉摜�̍ŏ�X���W
	static constexpr int NowScoreImgPosMinY = 500;								//�X�R�A�]���̉摜�̍ŏ�Y���W
	static constexpr int NowScoreImgPosMaxX = 1017;								//�X�R�A�]���̉摜�̍ő�X���W
	static constexpr int NowScoreImgPosMaxY = 665;								//�X�R�A�]���̉摜�̍ő�Y���W

	static constexpr int NowScoreImgAddPosMaxX = 1680;							//�X�R�A�]���̉摜�̉��Z�l�̍ő�
};

