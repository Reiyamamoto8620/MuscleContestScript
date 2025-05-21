#pragma once
#include "iostream"
#include "vector"
#include <Windows.h>
#include "cpprest/http_client.h"
#include "cpprest/filestream.h"

using namespace utility;                    // ������ϊ��Ȃǂ̈�ʓI�ȃ��[�e�B���e�B
using namespace web;                        // URI�̂悤�ȋ��ʂ̋@�\
using namespace web::http;                  // ���ʂ�HTTP�@�\
using namespace web::http::client;          // HTTP �N���C�A���g�̋@�\
using namespace concurrency::streams;       // �񓯊��X�g���[��

class ScoreRanking
{
public:
	////////////////////////
	//--------�֐�--------//
	////////////////////////
	//�R���X�g���N�^
	ScoreRanking();
	//�f�X�g���N�^
	~ScoreRanking();
	//������
	void Init();
	//�`��
	void Draw();
	//�X�V
	void Update(HttpRequestType _requestType, int _nowScore);

	/// <summary>
	/// isTaskEnd�̃Q�b�^�[
	/// </summary>
	bool GetIsTaskEnd()
	{
		return isTaskEnd;
	}
	/// <summary>
	/// isTaskEnd�̃Z�b�^�[
	/// </summary>
	void SetIsTaskEnd(bool _isTaskEnd)
	{
		isTaskEnd = _isTaskEnd;
	}

private:
	////////////////////////
	//--------�֐�--------//
	////////////////////////
	//GAS���烉���L���O��Get����
	pplx::task<void> GetRanking();
	//GAS�Ƀ����L���O��Post����
	pplx::task<void> PostRanking(int _nowScore);

	////////////////////////
	//--------�ϐ�--------//
	////////////////////////
	std::vector<int> ranking;		//GAS����擾���������L���O���i�[����vector
	int scoreRankingImg;			//SCORERANKING�̉摜
	int rankingFontHandle;			//�����L���O�̃t�H���g�n���h��
	int titleButtonImg;				//TITLE�{�^���̉摜
	bool isTaskEnd;					//�^�X�N�����̔���
	bool isServerAlive;				//�T�[�o�[�ɐڑ��\���̔���
	bool isTestEnd;					//�T�[�o�[�ڑ��e�X�g�̏I������

	////////////////////////
	//--------�萔--------//
	////////////////////////
	static constexpr int RankingMax = 5;					//�擾�A�\�����郉���L���O�̍ő吔

	static constexpr int RankingFontSize = 120;				//�����L���O�̃t�H���g�T�C�Y
	static constexpr int RankingFontThick = 6;				//�����L���O�̕����̑���
	static constexpr int RankingFontEdgeSize = 7;			//�����L���O�̉��̕�

	static constexpr int ScoreBackBlendPal = 100;			//�X�R�A�̔w�i�̃u�����h�l
	static constexpr int BlendPalMax = 255;					//�f�t�H���g�̃u�����h�l
	static constexpr int ScoreBackPosMinX = 100;			//�X�R�A�̔w�i��X�̍ŏ�
	static constexpr int ScoreBackPosMinY = 40;				//�X�R�A�̔w�i��Y�̍ŏ�
	static constexpr int ScoreBackPosMaxX = 1820;			//�X�R�A�̔w�i��X�̍ő�
	static constexpr int ScoreBackPosMaxY = 1040;			//�X�R�A�̔w�i��Y�̍ő�

	static constexpr int RankingPosX = 480;					//�����L���O��X���W
	static constexpr int RankingPosY = 200;					//�����L���O�̊��Y���W

	static constexpr int RankingPosShiftY = 120;			//�����L���O��Y���W�����ʂ��Ƃɂ��炷�p�̒l
	static constexpr int RankingWidthQuarterNum = 4;		//
	static constexpr int RankingPlacePosX = 600;			//[��]��X���W

	static constexpr int RankingScorePosX = 860;			//�����L���O�̃X�R�A��X���W

	static constexpr float ScoreRankingImgPosX = 181.0f;	//SCORERANKING��X���W
	static constexpr float ScoreRankingImgPosY = 50.0f;		//SCORERANKING��Y���W

	static constexpr float TitlButtonImgPosX = 643.5f;		//Title�{�^����X���W
	static constexpr float TitlButtonImgPosY = 860.0f;		//Title�{�^����Y���W

	const int FirstScoreColor = GetColor(255, 215, 0);		//1�ʂ̃X�R�A�J���[
	const int SecondScoreColor = GetColor(192, 192, 192);	//2�ʂ̃X�R�A�J���[
	const int ThirdScoreColor = GetColor(169, 82, 45);		//3�ʂ̃X�R�A�J���[
	const int OtherScoreColor = GetColor(255, 255, 255);	//4�ʈȉ��̃X�R�A�J���[
	const int ScoreBackColor = GetColor(255, 255, 255);		//�X�R�A�̔w�i�̃J���[

	const int OfflineTextColor = GetColor(255, 255, 255);	//�I�t���C�����[�h�̃J���[
	const TCHAR* OfflineText = (TCHAR*)"�I�t���C�����[�h";	//�I�t���C�����[�h�̕���
	const int OfflineTextPosX = 1920 / 2 -					//�I�t���C�����[�h��X���W
		GetDrawStringWidthToHandle(OfflineText,
			strlen(OfflineText), rankingFontHandle)/2;
	const int OfflineTextPosY = 1080 / 2 -					//�I�t���C�����[�h��Y���W
		RankingFontSize / 2;

	//�����L���O�̃C���f�b�N�X
	enum class RankingIndex
	{
		First,		//1��
		Second,		//2��
		Third		//3��
	};
};

