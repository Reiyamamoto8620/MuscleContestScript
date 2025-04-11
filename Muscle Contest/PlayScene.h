#pragma once

class Sound;

class PlayScene
{
public:
	////////////////////////
	//--------�֐�--------//
	////////////////////////
	//�R���X�g���N�^
	PlayScene();
	//�f�X�g���N�^
	~PlayScene();
	//������
	void Init();
	//�X�V
	void Update(int _score,bool _isNPCPose, int _npcState, int _nowNPCPose, 
		bool _isPlayerPose, int _playerState);

	/// <summary>
	/// �Q�[���X�^�[�g������擾
	/// </summary>
	bool GetIsStart()
	{
		return isStart;
	}
	/// <summary>
	/// �|�[�W���O�̔���̏I��������擾
	/// </summary>
	bool GetIsFinishJudge()
	{
		return isFinishJudge;
	}
	/// <summary>
	/// �A�������񐔂��擾
	/// </summary>
	int GetSuccessCount()
	{
		return successCount;
	}
	/// <summary>
	/// �Q�[���̏I��������擾
	/// </summary>
	bool GetIsGameEnd()
	{
		return isGameEnd;
	}
	/// <summary>
	/// ����������擾
	/// </summary>
	bool GetIsSuccess()
	{
		return isSuccess;
	}
	/// <summary>
	/// ���s������擾
	/// </summary>
	bool GetIsMiss()
	{
		return isMiss;
	}
	/// <summary>
	/// �Q�[���X�^�[�gSE������擾
	/// </summary>
	bool GetIsStartSE()
	{
		return isStartSE;
	}
private:
	////////////////////////
	//--------�֐�--------//
	////////////////////////
	//�`��
	void Draw();
	//�Q�[���J�n���Ԃ̌v��
	void StartTimer();
	//�������Ɋϋq��\��
	void RiseUpAudience(int _score);
	//�|�[�W���O�̔���
	void CheckPose(bool _isNPCPose, int _npcState, 
		int _nowNPCPose,bool _isPlayerPose, int _playerState);
	//���͑ҋ@���Ԃ̊m�F
	bool InputTimeCheck(bool _isNPCPose, bool _isPlayerPose);
	//�Q�[�����Ԃ̃J�E���g
	void CountGameTime();


	////////////////////////
	//--------�ϐ�--------//
	////////////////////////
	bool isNext;					//���̃V�[���ɐi�ޔ���
	bool isStart;					//�Q�[���J�n����
	bool isStartSE;					//�X�^�[�g��SE�̍Đ�����
	bool isJudgeDraw;				//�|�[�W���O����̕`�攻��
	bool isCheckPose;				//�|�[�W���O�̊m�F����
	bool isSuccess;					//�|�[�W���O�̐�������
	bool isMiss;					//�|�[�W���O�̎��s����
	bool isFinishJudge;				//�|�[�W���O����̏I������
	bool isGameEnd;					//�Q�[���̏I������
	int successImg;					//��������̉摜
	int missImg;					//���s����̉摜
	int nowJudgeImg;				//���݂̃|�[�W���O����̉摜
	int startTime;					//�Q�[���J�n�܂ł̎���
	int readyImg;					//READY�̉摜
	int goImg;						//GO!!�̉摜
	int audienceImg;				//�ϋq�̉摜
	int audiencePosY;				//�ϋq�̉摜��Y���W
	int playerImg;					//[Player]�̉摜
	int successCount;				//�|�[�W���O�̘A��������
	int successCountFontHandle;		//�A�������񐔂̃t�H���g�n���h��
	int gameTimeCount;				//�Q�[��������
	int gameTimeFontHandle;			//�Q�[�������Ԃ̃t�H���g�n���h��

	int comboFontHandle;			//�R���{�̃t�H���g�n���h��
	float playerImgAddPos;			//[Player]�̍��W�̉��Z�l
	VECTOR playerImgPos;			//[Player]�̍��W

	int inputTimer;					//���͑ҋ@����


	////////////////////////
	//--------�萔--------//
	////////////////////////
	static constexpr int FPS = 60;								//FPS

	static constexpr int StartTimeMax = 60;						//�Q�[���X�^�[�g�܂ł̑ҋ@����
	static constexpr int ReadyWaitTime = 40;					//READY�̕\������
	static constexpr int ReadyImgPosX = 1920 / 2 - 683 / 2;		//READY��X���W
	static constexpr int ReadyImgPosY = 1080 / 2 - 169 / 2;		//READY��Y���W
	static constexpr int GoImgPosX = 1920 / 2 - 365 / 2;		//GO!!��X���W
	static constexpr int GoImgPosY = 1080 / 2 - 170 / 2;		//GO!!��Y���W
	static constexpr int AudiencePosX = 0;						//�ϋq�̉摜��X���W�̏����l
	static constexpr int AudiencePosY = 480;					//�ϋq�̉摜��Y���W�̏����l
	static constexpr int AudienceSpeed = 24;					//�ϋq�̈ړ����x�㏸�l
	static constexpr int AudienceLowScorePos = 240;				//��X�R�A���̊ϋq�̍ő���W
	static constexpr int AudienceMiddleScorePos = 160;			//���X�R�A���̊ϋq�̍ő���W

	static constexpr int HighScoreMin = 45000;					//�����_�X�R�A�]���̍ŏ��l
	static constexpr int MiddleScoreMin = 20000;				//�����_�X�R�A�]���̍ŏ��l

	static constexpr float PlayerImgSize = 2.0f;				//[Player]�̕`��T�C�Y
	static constexpr float PlayerImgCenter = 0.5f;				//[Player]�̉摜�̒��S
	static constexpr float PlayerImgPosMinY = 5.5f;				//[Player]�̍ŏ�Y���W
	static constexpr float PlayerImgPosMaxY = 5.625f;			//[Player]�̍ő�Y���W
	static constexpr float PlayerImgAddPos = 0.008f;			//[Player]�̍��W���Z�l
	const VECTOR PlayerImgPos = VGet(2, 5.5f, 25);				//[Player]�̕`����W

	static constexpr float JudgeImgSize = 2.5f;					//�|�[�W���O����̕`��T�C�Y
	static constexpr float JudgeImgCenter = 0.5f;				//�|�[�W���O����̉摜�̒��S
	const VECTOR JudgeImgPos = VGet(2, 5.625, 25);				//�|�[�W���O����̕`����W

	static constexpr int InputTimerMax = 60;					//���͑ҋ@���Ԃ̍ő�

	static constexpr int InputTimerGaugeMinX = 0;				//���͑ҋ@���ԃQ�[�W��X�̍ŏ����W
	static constexpr int InputTimerGaugeMinY = 1060;			//���͑ҋ@���ԃQ�[�W��Y�̍ŏ����W
	static constexpr int InputTimerGaugeMaxX = 1920;			//���͑ҋ@���ԃQ�[�W��X�̍ő���W
	static constexpr int InputTimerGaugeMaxY = 1080;			//���͑ҋ@���ԃQ�[�W��Y�̍ő���W
	const int InputTimerGaugeColor = GetColor(0, 255, 0);		//���͑ҋ@���ԃQ�[�W�̐F

	static constexpr int InputTimerGaugeFrameMinX = 0;			//���͑ҋ@���ԃQ�[�W�g��X�̍ŏ����W
	static constexpr int InputTimerGaugeFrameMinY = 1060;		//���͑ҋ@���ԃQ�[�W�g��Y�̍ŏ����W
	static constexpr int InputTimerGaugeFrameMaxX = 1920;		//���͑ҋ@���ԃQ�[�W�g��X�̍ő���W
	static constexpr int InputTimerGaugeFrameMaxY = 1080;		//���͑ҋ@���ԃQ�[�W�g��Y�̍ő���W
	const int InputTimerGaugeFrameColor = GetColor(255, 0, 0);	//���͑ҋ@���ԃQ�[�W�g�̐F

	static constexpr int InputTimerGaugeDecreaseNum = 32;		//���͑ҋ@���Ԃ̃Q�[�W�̌���l
	static constexpr int SuccessCountFontSize = 100;			//�A�������񐔂̃t�H���g�T�C�Y
	static constexpr int SuccessCountFontThick = 6;				//�A�������񐔂̕�����
	static constexpr int SuccessCountFontEdgeSize = 7;			//�A�������񐔂̉��̕�
	static constexpr int SuccessCountPosX = 1870;				//�A�������񐔂�X���W
	static constexpr int SuccessCountPosY = 700;				//�A�������񐔂�Y���W
	const int SuccessCountColor = GetColor(255, 255, 255);		//�A�������񐔂̐F
	static constexpr int ComboFontSize = 50;					//������[COMBO]�̃t�H���g�T�C�Y
	static constexpr int ComboFontThick = 6;					//������[COMBO]�̕�����
	static constexpr int ComboFontEdgeSize = 7;					//������[COMBO]�̉��̕�
	static constexpr int ComboPosX = 1555;						//������[COMBO]��X���W
	static constexpr int ComboPosY = 810;						//������[COMBO]��Y���W
	const int ComboColor = GetColor(255, 255, 255);				//������[COMBO]�̐F
	static constexpr int GameTimeMax = 60 * 60;					//�Q�[���̎c�莞�Ԃ̍ő�
	static constexpr int GameTimeFontSize = 50;					//�Q�[���̎c�莞�Ԃ̃t�H���g�T�C�Y
	static constexpr int GameTimeFontThick = 6;					//�Q�[���̎c�莞�Ԃ̕�����
	static constexpr int GameTimeFontEdgeSize = 7;				//�Q�[���̎c�莞�Ԃ̉��̕�
	static constexpr int GameTimePosX = 960;					//�Q�[���̎c�莞�Ԃ�X���W
	static constexpr int GameTimePosY = 50;						//�Q�[���̎c�莞�Ԃ�Y���W
	const int GameTimeColor = GetColor(255, 255, 255);			//�Q�[���̎c�莞�Ԃ̐F

};