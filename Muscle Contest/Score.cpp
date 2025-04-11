#include "DxLib.h"
#include "Score.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
Score::Score() :
	score(0),
	isAddScore(false),
	scoreFontHandle(CreateFontToHandle("Dela gothic one",
		ScoreFontSize, ScoreFontThick, DX_FONTTYPE_ANTIALIASING_EDGE, -1, ScoreFontEdgeSize))
{

}
/// <summary>
/// �f�X�g���N�^
/// </summary>
Score::~Score()
{

}
/// <summary>
/// ������
/// </summary>
void Score::Init()
{
	score = 0;
	isAddScore = false;
}
/// <summary>
/// �X�V
/// </summary>
void Score::Update(int _successCount, bool _isSuccess)
{
	AddScore(_successCount, _isSuccess);
	Draw();
}
/// <summary>
/// �X�R�A�����Z
/// </summary>
void Score::AddScore(int _successCount, bool _isSuccess)
{
	//�|�[�W���O���������Ă��āA�܂��X�R�A�����Z���Ă��Ȃ��ꍇ���s
	if (_isSuccess && isAddScore)
	{
		//�X�R�A�����Z
		score += AddScoreValue + ScoreBonus * _successCount;
		isAddScore = false;
	}
	//�|�[�W���O���������Ă��Ȃ��Ƃ����s
	else if (!_isSuccess)
	{
		isAddScore = true;
	}
}
/// <summary>
/// �`��
/// </summary>
void Score::Draw()
{
	//�X�R�A��`��
	DrawFormatStringToHandle(ScorePosX, ScorePosY, ScoreColor, 
		scoreFontHandle, "SCORE : %d", score);
}