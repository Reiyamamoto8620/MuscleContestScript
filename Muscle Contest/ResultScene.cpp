#include "DxLib.h"
#include "ResultScene.h"
/// <summary>
/// �R���X�g���N�^
/// </summary>
ResultScene::ResultScene() :
	isNext(false),
	isReplay(false),
	isBackTitle(false),
	isSelect(false),
	isEnter(false),
	nowScore(0),
	nowScoreImgAddPosX(0),
	resultImg(LoadGraph("Data/Img/Result/Result.png")),
	replayImg(LoadGraph("Data/Img/Result/RePlay.png")),
	backTitleImg(LoadGraph("Data/Img/Result/Title.png")),
	highScoreImg(LoadGraph("Data/Img/Result/HighScore.png")),
	middleScoreImg(LoadGraph("Data/Img/Result/MiddleScore.png")),
	lowScoreImg(LoadGraph("Data/Img/Result/LowScore.png")),
	scoreFontHandle(CreateFontToHandle("Dela Gothic one", ScoreFontHandleSize, ScoreFontHandleThick,
		DX_FONTTYPE_ANTIALIASING_EDGE, -1, ScoreFontEdgeSize))
{

}
/// <summary>
/// �f�X�g���N�^
/// </summary>
ResultScene::~ResultScene()
{

}
/// <summary>
/// ������
/// </summary>
void ResultScene::Init()
{
	isNext = false;
	isReplay = true;
	isBackTitle = false;
	isSelect = false;
	isEnter = false;
	nowScore = 0;
	nowScoreImgAddPosX = NowScoreImgAddPosMaxX;
}
/// <summary>
/// �X�V
/// </summary>
void ResultScene::Update(bool _isRight, bool _isLeft, bool _isSpace,int _score)
{
	isSelect = false;
	isEnter = false;
	SelectButton(_isRight, _isLeft, _isSpace);
	Draw(_score);
}
/// <summary>
/// �`��
/// </summary>
void ResultScene::Draw(int _score)
{
	int scoreWidth = 0;			//�X�R�A�̉���
	//RESULT��`��
	DrawGraph(ResultImgPosX, ResultImgPosY, resultImg, true);
	//�X�R�A�̉������擾
	scoreWidth = GetDrawFormatStringWidthToHandle(scoreFontHandle, "%d", nowScore);
	//�X�R�A��`��
	DrawFormatStringToHandle(ScorePosX, ScorePosY, ScoreColor, scoreFontHandle, "%d", nowScore);
	//�X�R�A���J�E���g�A�b�v
	CountUpScore(_score);

	if (_score == nowScore)
	{
		DrawScoreImg(nowScore);
	}

	//REPLAY���I������Ă���ꍇ
	if (isReplay)
	{
		//REPLAY�{�^����`��
		DrawGraph(RePlayImgPosX, RePlayImgPosY, replayImg, true);
		//�I������Ă��Ȃ��{�^���𔖂��\������
		//�u�����h�l���Z�b�g
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, NotSelectBlendPal);
		//BACKTITLE��`��
		DrawGraph(BackTitleImgPosX, BackTitleImgPosY, backTitleImg, true);
		//�u�����h�l���f�t�H���g�ɃZ�b�g
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, BlendPalMax);
	}
	//BACKTITLE���I������Ă���ꍇ
	if (isBackTitle)
	{
		//BACKTITLE��`��
		DrawGraph(BackTitleImgPosX, BackTitleImgPosY, backTitleImg, true);
		//�I������Ă��Ȃ��{�^���𔖂��\������
		//�u�����h�l���Z�b�g
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, NotSelectBlendPal);
		//REPLAY�{�^����`��
		DrawGraph(RePlayImgPosX, RePlayImgPosY, replayImg, true);
		//�u�����h�l���f�t�H���g�ɃZ�b�g
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, BlendPalMax);
	}
}
/// <summary>
/// �X�R�A�̃J�E���g�A�b�v���o
/// </summary>
void ResultScene::CountUpScore(int _score)
{
	//�\�����̃X�R�A������̃X�R�A��菬�����ꍇ
	if (_score > nowScore)
	{
		//�\�����̃X�R�A�����Z
		nowScore += AddNowScore;
	}
	//�\�����̃X�R�A������̃X�R�A���ȏ�ꍇ
	if (_score <= nowScore)
	{
		//�\�����̃X�R�A�ɍ���̃X�R�A����
		nowScore = _score;
	}
}
/// <summary>
/// �X�R�A�̕]����`��
/// </summary>
void ResultScene::DrawScoreImg(int _nowScore)
{
	int nowScoreImg = 0;				//���݂̃X�R�A�]���̉摜

	//�����_�]��
	if (_nowScore >= HighScoreMin)
	{
		//�����_�]���摜����
		nowScoreImg = highScoreImg;
	}
	//�����_�]��
	else if (_nowScore >= MiddleScoreMin)
	{
		//�����_�]���摜����
		nowScoreImg = middleScoreImg;
	}
	//�ᓾ�_�]��
	else
	{
		//�ᓾ�_�]���摜����
		nowScoreImg = lowScoreImg;
	}
	//�X�R�A����ʊO�����ʓ��Ɉړ�������
	if (nowScoreImgAddPosX > 0)
	{
		//X���W�̉��Z�l�����炵�Ă���
		nowScoreImgAddPosX -= NowScoreImgSpeed;
	}
	//���_�]���摜��傫�������킹�ĕ`��
	DrawExtendGraph(NowScoreImgPosMinX + nowScoreImgAddPosX, NowScoreImgPosMinY,
		NowScoreImgPosMaxX + nowScoreImgAddPosX,NowScoreImgPosMaxY, nowScoreImg, TRUE);
}
/// <summary>
/// �{�^���̑I��
/// </summary>
void ResultScene::SelectButton(bool _isRight, bool _isLeft, bool _isSpace)
{
	//�E�������ꂽ�Ƃ�
	if (_isRight)
	{
		//�I����SE���Đ�
		isSelect = true;
		//END���I�������
		isBackTitle = true;
		isReplay = false;
	}
	//���������ꂽ�Ƃ�
	else if (_isLeft)
	{
		//�I����SE���Đ�
		isSelect = true;
		//START���I�������
		isReplay = true;
		isBackTitle = false;
	}
	//SPACE�������ꂽ�Ƃ�
	if (_isSpace)
	{
		//�I����SE���Đ�
		isEnter = true;
		//���ɐi��
		isNext = true;
	}
}