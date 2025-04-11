#include "DxLib.h"
#include <Sensapi.h>
#include "ScoreRanking.h"
#pragma comment(lib,"Sensapi.lib")

/// <summary>
/// コンストラクタ
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
/// デストラクタ
/// </summary>
ScoreRanking::~ScoreRanking()
{
	ranking.clear();
}
/// <summary>
/// 初期化
/// </summary>
void ScoreRanking::Init()
{
	for (int i = 0; i < RankingMax; i++)
	{
		ranking.push_back(0);
	}
}
/// <summary>
/// 描画
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
		//1位のスコア表示時
		if (i == (int)RankingIndex::First)
		{
			//1だけ文字幅が異常に小さいため、表示位置から文字幅の半分をずらす
			//文字列の長さを取得
			int strLen = strlen("1");
			//文字列の幅を取得
			rankingWidth = GetDrawStringWidthToHandle("1", strLen, rankingFontHandle);
			//1位用のフォントカラーを設定
			color = FirstScoreColor;
		}
		else
		{
			//1位以外の場合は文字幅文ずらす必要はないため、
			//ずらす文字幅の値を0にする
			rankingWidth = 0;
		}
		//2位のスコア表示時
		if (i == (int)RankingIndex::Second)
		{
			//2位用のフォントカラーを取得
			color = SecondScoreColor;
		}
		//3位のスコア表示時
		if (i == (int)RankingIndex::Third)
		{
			//3位用のフォントカラーを取得
			color = ThirdScoreColor;
		}
		//4位以下のスコア表示時
		if (i > (int)RankingIndex::Third)
		{
			//4位用のフォントカラーを取得
			color = OtherScoreColor;
		}
		//順位の表示
		DrawFormatStringToHandle(RankingPosX + rankingWidth / RankingWidthQuarterNum,
			i * RankingPosShiftY + RankingPosY, color, rankingFontHandle, "%d", i + 1);
		DrawStringToHandle(RankingPlacePosX, i * RankingPosShiftY + RankingPosY,
			"位", color, rankingFontHandle);
		//スコアの表示
		DrawFormatStringToHandle(RankingScorePosX, i * RankingPosShiftY + RankingPosY,
			color, rankingFontHandle, "%d", ranking[i]);
	}
}
/// <summary>
/// GASからランキングをGetする
/// </summary>
pplx::task<void> ScoreRanking::GetRanking()
{
	//タスクを生成
	return pplx::create_task([]
		{
			//URLを取得
			http_client client(L"https://script.google.com/macros/s/AKfycbwyeGTtb4ya8-CFZIBHJ6VcCepAVJbLSAeCbuBr9xxdbjGlj9NnTrMi_-T1UCwPcfpLUQ/exec");
			//リクエストを送信
			return client.request(methods::GET);
		})
		//上のリターンを取得
			.then([](http_response response)
				{
					// ステータスコード判定
					if (response.status_code() == status_codes::OK)
					{
						// レスポンスをJSONとして解析する
						return response.extract_json();
					}
				})
			//上のリターンを取得
					.then([this](json::value json)
						{
							//ランキングの中に0が入っているため中身を削除
							ranking.clear();
							// ほしいもののkeyから値だけ取得する
							ranking.push_back(json[L"First"].as_integer());
							ranking.push_back(json[L"Second"].as_integer());
							ranking.push_back(json[L"Third"].as_integer());
							ranking.push_back(json[L"Fourth"].as_integer());
							ranking.push_back(json[L"Fifth"].as_integer());
							isTaskEnd = true;
						});
}
/// <summary>
/// GASにランキングをPostする
/// </summary>
pplx::task<void> ScoreRanking::PostRanking(int _nowScore)
{
	//タスクを生成
	return pplx::create_task([_nowScore]
		{
			// クライアントの設定
			http_client client(L"https://script.google.com/macros/s/AKfycbwyeGTtb4ya8-CFZIBHJ6VcCepAVJbLSAeCbuBr9xxdbjGlj9NnTrMi_-T1UCwPcfpLUQ/exec");

			// 送信データの作成
			json::value postData;
			//Json形式にデータを格納
			postData[L"NowScore"] = json::value::number(_nowScore);

			// リクエスト送信
			return client.request(methods::POST, L"", postData.serialize(), L"application/json");
		})
		//上のリターンを取得
			.then([](http_response  response)
				{
					// ステータスコード判定
					if (response.status_code() == status_codes::OK)
					{
						//レスポンスをJSONに解析
						return response.extract_json();
					}
				})
			//上のリターンを取得
					.then([this](json::value json)
						{
							//Keyを指定して値を表示
							std::wcout << json[L"Message"].as_string() << std::endl;
							isTaskEnd = true;
						});
}
/// <summary>
/// 更新
/// </summary>
void ScoreRanking::Update(int _requestType,int _nowScore)
{
	DWORD networkType;
	//ネットワークに接続されているか判定
	if (IsNetworkAlive(&networkType) == TRUE && GetLastError() == 0)
	{
		//ランキングをGet
		try
		{
			//タスク終了判定をfalse
			isTaskEnd = false;
			
			//Getを開始
			if (_requestType == 0)
			{
				GetRanking();
			}
			//Postを開始
			else if (_requestType == 1)
			{
				PostRanking(_nowScore);
			}

		}
		catch (const std::exception& e)
		{
			//Getが失敗した場合
			std::cout << "Error " << e.what() << std::endl;
			//タスク終了判定をtrue
			isTaskEnd= true;
		}
	}
}