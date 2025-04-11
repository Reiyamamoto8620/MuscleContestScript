#pragma once

class TitleScene
{
public:
	////////////////////////
	//--------�֐�--------//
	////////////////////////
	//�R���X�g���N�^
	TitleScene();
	//�f�X�g���N�^
	~TitleScene();
	//������
	void Init();
	//�X�V
	void Update(bool _isRight, bool _isLeft, bool _isSpace);

	/// <summary>
	/// ���̃V�[���ɐi�ޔ�����擾
	/// </summary>
	bool GetIsNext()
	{
		return isNext;
	}
	/// <summary>
	/// �Q�[���̏I��������擾
	/// </summary>
	bool GetIsEnd()
	{
		return isEnd;
	}
	/// <summary>
	/// �X�R�A�̕`�攻�������
	/// </summary>
	bool GetIsDrawScore()
	{
		return isDrawScore;
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

	//�{�^���̃C���f�b�N�X
	enum class SelectButtonIndex
	{
		Start,
		Score,
		End
	};

private:
	////////////////////////
	//--------�֐�--------//
	////////////////////////
	//�`��
	void Draw();
	//�{�^���̕`��
	void DrawButton();
	//���͂���I�𒆂̃{�^���𔻒�
	void SelectButton(bool _isRight, bool _isLeft,bool _isSpace);

	////////////////////////
	//--------�ϐ�--------//
	////////////////////////
	bool isNext;				//���̃V�[���ɐi�ޔ���
	bool isEnd;					//�Q�[���I���{�^���I�𔻒�
	bool isStart;				//�Q�[���J�n�{�^���I�𔻒�
	bool isScore;				//�X�R�A�\���{�^���I�𔻒�
	bool isDrawScore;			//�X�R�A�\������
	bool isEnter;				//����{�^��������������
	int selectButtonIndex;		//�I�𒆂̃{�^���ԍ�
	int titleImg;				//�^�C�g���̉摜
	int startImg;				//START�{�^���̉摜
	int endImg;					//END�{�^���̉摜
	int scoreImg;				//SCORE�{�^���̉摜

	int creditFontHandle;		//�N���W�b�g�̃t�H���g�n���h��

	bool isSelect;				//�{�^���I�����̔���

	////////////////////////
	//--------�萔--------//
	////////////////////////
	static constexpr float TitleImgCenter = 0.5f;					//�^�C�g���摜�̒��S�_
	static constexpr float TitleImgSize = 7.5f;						//�^�C�g����Y���W
	const VECTOR TitlePos = VGet(0, 6, 25);							//�^�C�g���̍��W
	static constexpr float StartImgPosX = 1920 / 4 - 669 / 2;       //�X�^�[�g�{�^����X���W
	static constexpr float StartImgPosY = 700;						//�X�^�[�g�{�^����Y���W
	static constexpr float EndImgPosX = 1920 / 4 * 3 - 412 / 2;     //�G���h�{�^����X���W
	static constexpr float EndImgPosY = 700;						//�G���h�{�^����Y���W
	static constexpr float ScoreImgPosX = 1920 / 2 - 683 / 2;		//�X�R�A�{�^����X���W
	static constexpr float ScoreImgPosY = 860;						//�X�R�A�{�^����Y���W
	static constexpr int NotSelectBlendPal = 100;					//�I������Ă��Ȃ��{�^���̃u�����h�l
	static constexpr int BlendPalMax = 255;							//�u�����h�l�̍ő�
	static constexpr int SelectButtonIndexMin = 0;					//�{�^���̃C���f�b�N�X�̍ŏ�
	static constexpr int SelectButtonIndexMax = 2;					//�{�^���̃C���f�b�N�X�̍ő�

	static constexpr int CreditFontSize = 30;						//�N���W�b�g�̃t�H���g�T�C�Y
	static constexpr int CreditFontThick = 3;						//�N���W�b�g�̑���
	static constexpr int CreditFontEdgeSize = 3;					//�N���W�b�g�̉��̃T�C�Y
	static constexpr int CreditPosX = 10;							//�N���W�b�g��X���W
	static constexpr int CreditPosY = 10;							//�N���W�b�g��Y���W
	const int CreditColor = GetColor(255, 255, 255);				//�N���W�b�g�̃J���[
};

