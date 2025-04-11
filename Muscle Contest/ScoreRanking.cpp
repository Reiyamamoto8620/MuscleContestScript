#include "DxLib.h"
#include <Sensapi.h>
#include "ScoreRanking.h"
#pragma comment(lib,"Sensapi.lib")

/// <summary>
/// �R���X�g���N�^
/// </summary>
ScoreRanking::ScoreRanking() :
	rankingFontHandle(CreateFontToHandle("Dela Gothic one", RankingFontSize,
		RankingFontThick, DX_FONTTYPE_ANTIALIASING_EDGE, -1, RankingFontEdgeSize)),
	scoreRankingImg(LoadGraph("Data/Img/Score/ScoreRanking.png")),
	titleButtonImg(LoadGraph("Data/Img/Score/Title.png")),
	isTaskEnd(true),
	isServerAlive(false)
{

}
/// <summary>
/// �f�X�g���N�^
/// </summary>
ScoreRanking::~ScoreRanking()
{
	ranking.clear();
}
/// <summary>
/// ������
/// </summary>
void ScoreRanking::Init()
{
	for (int i = 0; i < RankingMax; i++)
	{
		ranking.push_back(0);
	}
}
/// <summary>
/// �`��
/// </summary>
void ScoreRanking::Draw()
{
	int color = 0;
	int rankingWidth = 0;
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, ScoreBackBlendPal);
	DrawBox(ScoreBackPosMinX, ScoreBackPosMinY, ScoreBackPosMaxX, ScoreBackPosMaxY, ScoreBackColor, TRUE);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, BlendPalMax);
	DrawGraph(ScoreRankingImgPosX, ScoreRankingImgPosY, scoreRankingImg, TRUE);
	DrawGraph(TitlButtonImgPosX, TitlButtonImgPosY, titleButtonImg, TRUE);
	for (int i = 0; i < RankingMax; i++)
	{
		//1�ʂ̃X�R�A�\����
		if (i == (int)RankingIndex::First)
		{
			//1�������������ُ�ɏ��������߁A�\���ʒu���當�����̔��������炷
			//������̒������擾
			int strLen = strlen("1");
			//������̕����擾
			rankingWidth = GetDrawStringWidthToHandle("1", strLen, rankingFontHandle);
			//1�ʗp�̃t�H���g�J���[��ݒ�
			color = FirstScoreColor;
		}
		else
		{
			//1�ʈȊO�̏ꍇ�͕����������炷�K�v�͂Ȃ����߁A
			//���炷�������̒l��0�ɂ���
			rankingWidth = 0;
		}
		//2�ʂ̃X�R�A�\����
		if (i == (int)RankingIndex::Second)
		{
			//2�ʗp�̃t�H���g�J���[���擾
			color = SecondScoreColor;
		}
		//3�ʂ̃X�R�A�\����
		if (i == (int)RankingIndex::Third)
		{
			//3�ʗp�̃t�H���g�J���[���擾
			color = ThirdScoreColor;
		}
		//4�ʈȉ��̃X�R�A�\����
		if (i > (int)RankingIndex::Third)
		{
			//4�ʗp�̃t�H���g�J���[���擾
			color = OtherScoreColor;
		}
		//���ʂ̕\��
		DrawFormatStringToHandle(RankingPosX + rankingWidth / RankingWidthQuarterNum,
			i * RankingPosShiftY + RankingPosY, color, rankingFontHandle, "%d", i + 1);
		DrawStringToHandle(RankingPlacePosX, i * RankingPosShiftY + RankingPosY,
			"��", color, rankingFontHandle);
		//�X�R�A�̕\��
		DrawFormatStringToHandle(RankingScorePosX, i * RankingPosShiftY + RankingPosY,
			color, rankingFontHandle, "%d", ranking[i]);
	}
}
/// <summary>
/// GAS���烉���L���O��Get����
/// </summary>
pplx::task<void> ScoreRanking::GetRanking()
{
	//�^�X�N�𐶐�
	return pplx::create_task([]
		{
			//URL���擾
			http_client client(L"https://script.google.com/macros/s/AKfycbwyeGTtb4ya8-CFZIBHJ6VcCepAVJbLSAeCbuBr9xxdbjGlj9NnTrMi_-T1UCwPcfpLUQ/exec");
			//���N�G�X�g�𑗐M
			return client.request(methods::GET);
		})
		//��̃��^�[�����擾
			.then([](http_response response)
				{
					// �X�e�[�^�X�R�[�h����
					if (response.status_code() == status_codes::OK)
					{
						// ���X�|���X��JSON�Ƃ��ĉ�͂���
						return response.extract_json();
					}
				})
			//��̃��^�[�����擾
					.then([this](json::value json)
						{
							//�����L���O�̒���0�������Ă��邽�ߒ��g���폜
							ranking.clear();
							// �ق������̂�key����l�����擾����
							ranking.push_back(json[L"First"].as_integer());
							ranking.push_back(json[L"Second"].as_integer());
							ranking.push_back(json[L"Third"].as_integer());
							ranking.push_back(json[L"Fourth"].as_integer());
							ranking.push_back(json[L"Fifth"].as_integer());
							isTaskEnd = true;
						});
}
/// <summary>
/// GAS�Ƀ����L���O��Post����
/// </summary>
pplx::task<void> ScoreRanking::PostRanking(int _nowScore)
{
	//�^�X�N�𐶐�
	return pplx::create_task([_nowScore]
		{
			// �N���C�A���g�̐ݒ�
			http_client client(L"https://script.google.com/macros/s/AKfycbwyeGTtb4ya8-CFZIBHJ6VcCepAVJbLSAeCbuBr9xxdbjGlj9NnTrMi_-T1UCwPcfpLUQ/exec");

			// ���M�f�[�^�̍쐬
			json::value postData;
			//Json�`���Ƀf�[�^���i�[
			postData[L"NowScore"] = json::value::number(_nowScore);

			// ���N�G�X�g���M
			return client.request(methods::POST, L"", postData.serialize(), L"application/json");
		})
		//��̃��^�[�����擾
			.then([](http_response  response)
				{
					// �X�e�[�^�X�R�[�h����
					if (response.status_code() == status_codes::OK)
					{
						//���X�|���X��JSON�ɉ��
						return response.extract_json();
					}
				})
			//��̃��^�[�����擾
					.then([this](json::value json)
						{
							//Key���w�肵�Ēl��\��
							std::wcout << json[L"Message"].as_string() << std::endl;
							isTaskEnd = true;
						});
}
/// <summary>
/// �X�V
/// </summary>
void ScoreRanking::Update(int _requestType,int _nowScore)
{
	DWORD networkType;
	//�l�b�g���[�N�ɐڑ�����Ă��邩����
	if (IsNetworkAlive(&networkType) == TRUE && GetLastError() == 0)
	{
		//�����L���O��Get
		try
		{
			//�^�X�N�I�������false
			isTaskEnd = false;
			
			//Get���J�n
			if (_requestType == 0)
			{
				GetRanking();
			}
			//Post���J�n
			else if (_requestType == 1)
			{
				PostRanking(_nowScore);
			}

		}
		catch (const std::exception& e)
		{
			//Get�����s�����ꍇ
			std::cout << "Error " << e.what() << std::endl;
			//�^�X�N�I�������true
			isTaskEnd= true;
		}
	}
}