#include "DxLib.h"
#include "TitleScene.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
TitleScene::TitleScene() :
	isNext(false),
	isStart(false),
	isEnd(false),
	isScore(false),
	isDrawScore(false),
	isEnter(false),
	selectButtonIndex(0),
	titleImg(LoadGraph("Data/Img/Title/GameTitle.png")),
	startImg(LoadGraph("Data/Img/Title/Start.png")),
	endImg(LoadGraph("Data/Img/Title/End.png")),
	scoreImg(LoadGraph("Data/Img/Title/Score.png")),
	creditFontHandle(CreateFontToHandle("Dela Gothic one", CreditFontSize, CreditFontThick,
		DX_FONTTYPE_ANTIALIASING_EDGE, -1, CreditFontEdgeSize))
{

}
/// <summary>
/// �f�X�g���N�^
/// </summary>
TitleScene::~TitleScene()
{

}
/// <summary>
/// ������
/// </summary>
void TitleScene::Init()
{
	selectButtonIndex = 0;
	isNext = false;
	isStart = true;
	isEnd = false;
	isScore = false;
	isDrawScore = false;
	isEnter = false;
}
/// <summary>
/// �X�V
/// </summary>
void TitleScene::Update(bool _isRight, bool _isLeft, bool _isSpace)
{
	isSelect = false;
	isEnter = false;
	//�{�^����I��
	SelectButton(_isRight,_isLeft,_isSpace);

	//SPACE�������ꂽ�Ƃ�
	if (_isSpace)
	{
		//����SE���Đ�
		isEnter = true;
		//isScore��false�Ȃ�
		if (!isScore)
		{
			//���ɐi��
			isNext = true;
		}
		//isScore��true��isDrawScore��False�̏ꍇScore��`�悷��
		if (isScore && !isDrawScore)
		{
			isDrawScore = true;
		}
		//isScore��true��isDrawScore��true�̏ꍇScore��`������Ȃ�
		else if (isScore && isDrawScore)
		{
			isDrawScore = false;
		}
	}
	//�`��
	Draw();
}
/// <summary>
/// �`��
/// </summary>
void TitleScene::Draw()
{
	//�^�C�g���̉摜��`��
	DrawBillboard3D(TitlePos, TitleImgCenter, TitleImgCenter, TitleImgSize, 0, titleImg, TRUE);
	//�N���W�b�g��\��
	DrawStringToHandle(CreditPosX, CreditPosY, "BGM : ������", CreditColor, creditFontHandle);
	//�{�^����`��
	DrawButton();
}
/// <summary>
/// �{�^����`��
/// </summary>
void TitleScene::DrawButton()
{
	//�X�R�A�����L���O��\�����Ă���ꍇ
	if (isDrawScore)
	{
		//�X�R�A�����L���O��\�����͑S�Ẵ{�^�����u�����h���ĕ`��
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, NotSelectBlendPal);
		DrawGraph(StartImgPosX, StartImgPosY, startImg, true);
		DrawGraph(ScoreImgPosX, ScoreImgPosY, scoreImg, true);
		DrawGraph(EndImgPosX, EndImgPosY, endImg, true);
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, BlendPalMax);
	}
	//Start�{�^����I�𒆂̏ꍇ
	else if (selectButtonIndex == (int)SelectButtonIndex::Start)
	{
		//�I�𒆂�Start���u�����h�Ȃ��ŕ`��
		DrawGraph(StartImgPosX, StartImgPosY, startImg, true);
		//�I���O�̃{�^�����u�����h���ĕ`��
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, NotSelectBlendPal);
		DrawGraph(ScoreImgPosX, ScoreImgPosY, scoreImg, true);
		DrawGraph(EndImgPosX, EndImgPosY, endImg, true);
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, BlendPalMax);
	}
	//Score�{�^����I�𒆂̏ꍇ
	else if (selectButtonIndex == (int)SelectButtonIndex::Score)
	{
		//�I�𒆂�Score���u�����h�Ȃ��ŕ`��
		DrawGraph(ScoreImgPosX, ScoreImgPosY, scoreImg, true);
		//�I���O�̃{�^�����u�����h���ĕ`��
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, NotSelectBlendPal);
		DrawGraph(StartImgPosX, StartImgPosY, startImg, true);
		DrawGraph(EndImgPosX, EndImgPosY, endImg, true);
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, BlendPalMax);
	}
	//End�{�^����I�𒆂̏ꍇ
	else if (selectButtonIndex == (int)SelectButtonIndex::End)
	{
		//�I�𒆂�End���u�����h�Ȃ��ŕ`��
		DrawGraph(EndImgPosX, EndImgPosY, endImg, true);
		//�I���O�̃{�^�����u�����h���ĕ`��
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, NotSelectBlendPal);
		DrawGraph(StartImgPosX, StartImgPosY, startImg, true);
		DrawGraph(ScoreImgPosX, ScoreImgPosY, scoreImg, true);
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, BlendPalMax);
	}
}
/// <summary>
/// ���͂���I�𒆂̃{�^���𔻒�
/// </summary>
void TitleScene::SelectButton(bool _isRight, bool _isLeft,bool _isSpace)
{
	if (!isDrawScore)
	{
		//�E�������ꂽ�Ƃ�
		if (_isRight)
		{
			//�I�𒆂̃{�^������E�ɂ��炷
			selectButtonIndex++;
			//�I��SE���Đ�
			isSelect = true;
			//�I�𒆂̃{�^���̃C���f�b�N�X���ő���z������
			if (selectButtonIndex > SelectButtonIndexMax)
			{
				//�X�^�[�g�{�^���̃C���f�b�N�X��������
				selectButtonIndex = (int)SelectButtonIndex::Start;
			}
		}
		//���������ꂽ�Ƃ�
		else if (_isLeft)
		{
			//�I�𒆂̃{�^��������ɂ��炷
			selectButtonIndex--;
			//�I��SE���Đ�
			isSelect = true;
			//�I�𒆂̃{�^���̃C���f�b�N�X���ŏ����z������
			if (selectButtonIndex < SelectButtonIndexMin)
			{
				//�G���h�{�^���̃C���f�b�N�X��������
				selectButtonIndex = (int)SelectButtonIndex::End;
			}
		}
		isStart = false;
		isScore = false;
		isEnd = false;
		//�I�𒆂̃{�^����START�̏ꍇ
		if (selectButtonIndex == (int)SelectButtonIndex::Start)
		{
			//Start�����TRUE
			isStart = true;
		}
		if (selectButtonIndex == (int)SelectButtonIndex::Score)
		{
			//Score�����TRUE
			isScore = true;
		}
		if (selectButtonIndex == (int)SelectButtonIndex::End)
		{
			//End�����TRUE
			isEnd = true;
		}
	}
}