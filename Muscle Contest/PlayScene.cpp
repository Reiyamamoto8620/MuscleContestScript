#include "DxLib.h"
#include "CharacterState.h"
#include "PlayScene.h"
/// <summary>
/// �R���X�g���N�^
/// </summary>
PlayScene::PlayScene() :
	isNext(false),
	isStart(false),
	isStartSE(false),
	isJudgeDraw(false),
	isCheckPose(false),
	isSuccess(false),
	isMiss(false),
	isFinishJudge(false),
	isGameEnd(false),
	startTime(0),
	audiencePosY(0),
	playerImgAddPos(0),
	nowJudgeImg(0),
	successCount(0),
	gameTimeCount(0),
	inputTimer(0),
	successImg(LoadGraph("Data/Img/Play/Success.png")),
	missImg(LoadGraph("Data/Img/Play/Miss.png")),
	readyImg(LoadGraph("Data/Img/Play/Ready.png")),
	goImg(LoadGraph("Data/Img/Play/Go.png")),
	audienceImg(LoadGraph("Data/Img/Play/Audience.png")),
	playerImg(LoadGraph("Data/Img/Play/Player.png")),
	successCountFontHandle(CreateFontToHandle("Dela Gothic one", SuccessCountFontSize,
		SuccessCountFontThick, DX_FONTTYPE_ANTIALIASING_EDGE, -1, SuccessCountFontEdgeSize)),
	gameTimeFontHandle(CreateFontToHandle("Dela Gothic one", GameTimeFontSize,
		GameTimeFontThick, DX_FONTTYPE_ANTIALIASING_EDGE, -1, GameTimeFontEdgeSize)),
	comboFontHandle(CreateFontToHandle("Dela gothic one", ComboFontSize,
		ComboFontThick, DX_FONTTYPE_ANTIALIASING_EDGE, -1, ComboFontEdgeSize)),
	playerImgPos(VGet(0,0,0))
{

}
/// <summary>
/// �f�X�g���N�^
/// </summary>
PlayScene::~PlayScene()
{

}
/// <summary>
/// ������
/// </summary>
void PlayScene::Init()
{
	isNext = false;
	isStart = false;
	isStartSE = false;
	isJudgeDraw = false;
	isCheckPose = false;
	isSuccess = false;
	isMiss = false;
	isFinishJudge = false;
	isGameEnd = false;
	startTime = 0;
	successCount = 0;
	inputTimer = 0;
	gameTimeCount = GameTimeMax;
	audiencePosY = AudiencePosY;
	playerImgPos = PlayerImgPos;
}
/// <summary>
/// �X�V
/// </summary>
void PlayScene::Update(int _score,bool _isNPCPose,int _npcState,
	int _nowNPCPose,bool _isPlayerPose,int _playerState)
{
	//�Q�[���̊J�n���Ԃ̌v��
	StartTimer();
	//[PLAYER]�̍��W���Z�b�g
	if (!isStart)
	{
		//[Player]�̍��W���㉺�ɓ�����
		if (playerImgPos.y >= PlayerImgPosMaxY)
		{
			playerImgAddPos = -PlayerImgAddPos;
		}
		if (playerImgPos.y <= PlayerImgPosMinY)
		{
			playerImgAddPos = PlayerImgAddPos;
		}
		playerImgPos.y += playerImgAddPos;
	}
	//�|�[�W���O�̔���
	CheckPose(_isNPCPose,_npcState,_nowNPCPose,_isPlayerPose,_playerState);
	//�ϋq�����肠���点��
	RiseUpAudience(_score);
	//�Q�[�������Ԃ̃J�E���g
	CountGameTime();
	//�`��
	Draw();
}
/// <summary>
/// �`��
/// </summary>
void PlayScene::Draw()
{
	if (!isStart)
	{
		//�Q�[���J�n���Ԃ��ҋ@���Ԃ�菬�����ꍇ
		if (startTime <= ReadyWaitTime)
		{
			//READY��`��
			DrawGraph(ReadyImgPosX, ReadyImgPosY, readyImg, TRUE);
		}
		else
		{
			if (!isStartSE)
			{
				//�J�n��SE���Đ�
				isStartSE = true;
			}
			//GO��`��
			DrawGraph(GoImgPosX, GoImgPosY, goImg, TRUE);
		}
		//Player�̏��[Player]��\��
		DrawBillboard3D(playerImgPos, PlayerImgCenter, PlayerImgCenter,
			PlayerImgSize, 0.0f, playerImg, TRUE);
	}
	//�ϋq��\��
	else
	{
		DrawGraph(AudiencePosX, audiencePosY, audienceImg, TRUE);
		//�|�[�W���O�̔����`�悷�邩�̔���
		if (isJudgeDraw)
		{
			//�|�[�W���O�̔����`��
			DrawBillboard3D(JudgeImgPos, JudgeImgCenter, JudgeImgCenter,
				JudgeImgSize, 0.0f, nowJudgeImg, TRUE);
		}

		//�|�[�W���O�̓��͑ҋ@���Ԃ�`��
	
		//���͑ҋ@���Ԃ̃Q�[�W�̘g��`��
		DrawBox(InputTimerGaugeFrameMinX, InputTimerGaugeFrameMinY,
			InputTimerGaugeFrameMaxX, InputTimerGaugeFrameMaxY, InputTimerGaugeFrameColor, TRUE);

		//���͑ҋ@���Ԃ̃Q�[�W��`��
		DrawBox(InputTimerGaugeMinX, InputTimerGaugeMinY,
			InputTimerGaugeMaxX - inputTimer * InputTimerGaugeDecreaseNum, InputTimerGaugeMaxY,
			InputTimerGaugeColor, TRUE);

		int successCountWidth;		//�R���{��������̉���
		//�R���{��������̉������擾
		successCountWidth = GetDrawFormatStringWidthToHandle(successCountFontHandle, "%d", successCount);

		//�A�������񐔂�`��
		DrawFormatStringToHandle(SuccessCountPosX - successCountWidth, SuccessCountPosY, SuccessCountColor,
			successCountFontHandle, "%d", successCount);

		//COMBO��A�������񐔂̉��ɕ`��
		DrawStringToHandle(ComboPosX, ComboPosY, "COMBO", ComboColor, comboFontHandle);

		//�Q�[���̎c�莞�Ԃ�`��
		float width = 0;	//�c�莞�Ԃ̕�����

		//�c�莞�Ԃ̕��������擾
		width = GetDrawFormatStringWidthToHandle(gameTimeFontHandle, "%d", gameTimeCount / FPS);

		//�c�莞�Ԃ�`��
		DrawFormatStringToHandle(GameTimePosX - width / 2, GameTimePosY, GameTimeColor,
			gameTimeFontHandle, "%d", gameTimeCount / FPS);
	}
}
/// <summary>
/// �Q�[���J�n���Ԃ̌v��
/// </summary>
void PlayScene::StartTimer()
{
	//�Q�[���J�n���Ԃ����Z
	startTime++;

	//�Q�[���J�n���Ԃ��ҋ@���Ԉȏ�̏ꍇ
	if (startTime >= StartTimeMax)
	{
		//�Q�[�����J�n����
		isStart = true;
	}
}
/// <summary>
/// �������ϋq���o�Ă���
/// </summary>
void PlayScene::RiseUpAudience(int _score)
{
	int audiencePosMaxY = 0;

	//�X�R�A���n�C�X�R�A�̎����s
	if (_score >= HighScoreMin)
	{
		audiencePosMaxY = 0;
	}
	//�X�R�A���~�h���X�R�A�̎����s
	else if (_score >= MiddleScoreMin)
	{
		audiencePosMaxY = AudienceMiddleScorePos;
	}
	//�X�R�A����Q�ȊO�̎����s
	else
	{
		audiencePosMaxY = AudienceLowScorePos;
	}

	//�|�[�Y���������Ă��āA�����`�悵�Ă��āA�ϋq�̍��W��0���傫���ꍇ
	if (audiencePosY > audiencePosMaxY && isSuccess)
	{
		//�ϋq�̍��W�����������ď��X�ɉ�ʂ̏�����֓�����
		audiencePosY -= AudienceSpeed;
	}
	//�����`�悵�Ă��炸�A�ϋq�̍��W�����W�̍ő�l��菬�����ꍇ
	else if (audiencePosY < AudiencePosY && !isSuccess)
	{
		//�ϋq�̍��W��傫�������X�ɉ�ʂ̉������֓�����
		audiencePosY += AudienceSpeed;
	}
}
/// <summary>
/// �|�[�W���O�̊m�F
/// </summary>
void PlayScene::CheckPose(bool _isNPCPose,int _npcState,int _nowNPCPose ,bool _isPlayerPose,int _playerState)
{
	bool isTimeOver = false;	//���͑ҋ@���Ԃ��߂������̔���

	//�|�[�W���O�̓��͑ҋ@���Ԃ��߂��Ă��邩����
	isTimeOver = InputTimeCheck(_isNPCPose,_isPlayerPose);
	isFinishJudge = false;
	//�|�[�Y�̔���
	if (_isPlayerPose && _isNPCPose || isTimeOver)
	{
		//�|�[�Y���ɂP������肵�Ă��Ȃ��Ƃ��ɔ���ɓ���
		if (!isCheckPose)
		{
			//�|�[�Y���������̔����true�ɂ���
			isCheckPose = true;

			//�|�[�Y�����������ꍇ
			if (_playerState == _nowNPCPose)
			{
				//�|�[�W���O����SE���Đ�
				isSuccess = true;
				//�����̉��o
				isJudgeDraw = true;
				//�\������|�[�W���O�̔���ɐ�������̉摜���i�[
				nowJudgeImg = successImg;
				//�A�������񐔂𑝂₷
				successCount++;
			}
			//�|�[�Y���������Ă��Ȃ��ꍇ
			else
			{
				//�|�[�W���O���sSE���Đ�
				isMiss = true;
				//���s�̉��o
				isJudgeDraw = true;
				//�\������|�[�W���O�̔���Ɏ��s����̉摜���i�[
				nowJudgeImg = missImg;
				//�A�������񐔂�0�ɂ���
				successCount = 0;
			}
		}
		//Player���|�[�Y���I��������ɔ�������Z�b�g����
		if (_playerState == (int)CharacterState::State::Idle
			&& _isPlayerPose || isTimeOver)
		{
			//�|�[�W���O�����false��
			isJudgeDraw = false;
			//�|�[�W���O�̐��������false��
			isSuccess = false;
			//�|�[�W���O�̎��s�����false��
			isMiss = false;
			//�|�[�W���O�̊m�F�����false��
			isCheckPose = false;
			//�|�[�W���O�̏I�������false��
			isFinishJudge = true;
		}
	}
}

/// <summary>
/// ���͑ҋ@���Ԃ̌v���{����
/// </summary>
bool PlayScene::InputTimeCheck(bool _isNPCPose, bool _isPlayerPose)
{
	bool isTimeOver = false;		//���͑ҋ@���ԓ��Ƀ|�[�W���O�����Ă��Ȃ����̔���

	//NPC���|�[�Y�����I����Ă��v���C���[���|�[�Y���Ƃ��Ă��Ȃ��ꍇ
	if (_isNPCPose && !_isPlayerPose)
	{
		//���͑ҋ@���Ԃ�i�߂�
		inputTimer++;
		//���͑ҋ@���Ԃ�����ȏ�ɂȂ����ꍇ
		if (inputTimer >= InputTimerMax)
		{
			//True��Ԃ��ē��͑ҋ@���Ԃ����Z�b�g
			isTimeOver = true;
			inputTimer = 0;
		}
	}
	//Player���|�[�Y���Ƃ��Ă���ꍇ
	if (_isPlayerPose)
	{
		//���͑ҋ@���Ԃ����Z�b�g
		inputTimer = 0;
	}
	//���͑ҋ@���ԓ��Ƀ|�[�W���O�����Ă��Ȃ����̔���𑗂�
	return isTimeOver;
}

/// <summary>
/// �Q�[���̎c�莞�Ԃ��v��
/// </summary>
void PlayScene::CountGameTime()
{
	if (isStart)
	{
		//�Q�[���̎c�莞�Ԃ����炷
		gameTimeCount--;
		//�Q�[���̎c�莞�Ԃ��O�ȉ��ɂȂ����ꍇ
		if (gameTimeCount <= 0)
		{
			//�Q�[���I���̔����true�ɂ���
			isGameEnd = true;
		}
	}
}