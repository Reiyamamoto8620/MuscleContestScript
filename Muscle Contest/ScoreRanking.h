#pragma once
#include "iostream"
#include "vector"
#include <Windows.h>
#include "cpprest/http_client.h"
#include "cpprest/filestream.h"

using namespace utility;                    // 文字列変換などの一般的なユーティリティ
using namespace web;                        // URIのような共通の機能
using namespace web::http;                  // 共通のHTTP機能
using namespace web::http::client;          // HTTP クライアントの機能
using namespace concurrency::streams;       // 非同期ストリーム

class ScoreRanking
{
public:
	////////////////////////
	//--------関数--------//
	////////////////////////
	//コンストラクタ
	ScoreRanking();
	//デストラクタ
	~ScoreRanking();
	//初期化
	void Init();
	//描画
	void Draw();
	//更新
	void Update(HttpRequestType _requestType, int _nowScore);

	/// <summary>
	/// isTaskEndのゲッター
	/// </summary>
	bool GetIsTaskEnd()
	{
		return isTaskEnd;
	}
	/// <summary>
	/// isTaskEndのセッター
	/// </summary>
	void SetIsTaskEnd(bool _isTaskEnd)
	{
		isTaskEnd = _isTaskEnd;
	}

private:
	////////////////////////
	//--------関数--------//
	////////////////////////
	//GASからランキングをGetする
	pplx::task<void> GetRanking();
	//GASにランキングをPostする
	pplx::task<void> PostRanking(int _nowScore);

	////////////////////////
	//--------変数--------//
	////////////////////////
	std::vector<int> ranking;		//GASから取得したランキングを格納するvector
	int scoreRankingImg;			//SCORERANKINGの画像
	int rankingFontHandle;			//ランキングのフォントハンドル
	int titleButtonImg;				//TITLEボタンの画像
	bool isTaskEnd;					//タスク中かの判定
	bool isServerAlive;				//サーバーに接続可能かの判定
	bool isTestEnd;					//サーバー接続テストの終了判定

	////////////////////////
	//--------定数--------//
	////////////////////////
	static constexpr int RankingMax = 5;					//取得、表示するランキングの最大数

	static constexpr int RankingFontSize = 120;				//ランキングのフォントサイズ
	static constexpr int RankingFontThick = 6;				//ランキングの文字の太さ
	static constexpr int RankingFontEdgeSize = 7;			//ランキングの縁の幅

	static constexpr int ScoreBackBlendPal = 100;			//スコアの背景のブレンド値
	static constexpr int BlendPalMax = 255;					//デフォルトのブレンド値
	static constexpr int ScoreBackPosMinX = 100;			//スコアの背景のXの最小
	static constexpr int ScoreBackPosMinY = 40;				//スコアの背景のYの最小
	static constexpr int ScoreBackPosMaxX = 1820;			//スコアの背景のXの最大
	static constexpr int ScoreBackPosMaxY = 1040;			//スコアの背景のYの最大

	static constexpr int RankingPosX = 480;					//ランキングのX座標
	static constexpr int RankingPosY = 200;					//ランキングの基準のY座標

	static constexpr int RankingPosShiftY = 120;			//ランキングのY座標を順位ごとにずらす用の値
	static constexpr int RankingWidthQuarterNum = 4;		//
	static constexpr int RankingPlacePosX = 600;			//[位]のX座標

	static constexpr int RankingScorePosX = 860;			//ランキングのスコアのX座標

	static constexpr float ScoreRankingImgPosX = 181.0f;	//SCORERANKINGのX座標
	static constexpr float ScoreRankingImgPosY = 50.0f;		//SCORERANKINGのY座標

	static constexpr float TitlButtonImgPosX = 643.5f;		//TitleボタンのX座標
	static constexpr float TitlButtonImgPosY = 860.0f;		//TitleボタンのY座標

	const int FirstScoreColor = GetColor(255, 215, 0);		//1位のスコアカラー
	const int SecondScoreColor = GetColor(192, 192, 192);	//2位のスコアカラー
	const int ThirdScoreColor = GetColor(169, 82, 45);		//3位のスコアカラー
	const int OtherScoreColor = GetColor(255, 255, 255);	//4位以下のスコアカラー
	const int ScoreBackColor = GetColor(255, 255, 255);		//スコアの背景のカラー

	const int OfflineTextColor = GetColor(255, 255, 255);	//オフラインモードのカラー
	const TCHAR* OfflineText = (TCHAR*)"オフラインモード";	//オフラインモードの文字
	const int OfflineTextPosX = 1920 / 2 -					//オフラインモードのX座標
		GetDrawStringWidthToHandle(OfflineText,
			strlen(OfflineText), rankingFontHandle)/2;
	const int OfflineTextPosY = 1080 / 2 -					//オフラインモードのY座標
		RankingFontSize / 2;

	//ランキングのインデックス
	enum class RankingIndex
	{
		First,		//1位
		Second,		//2位
		Third		//3位
	};
};

