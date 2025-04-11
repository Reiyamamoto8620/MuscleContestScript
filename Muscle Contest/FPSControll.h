#pragma once
#include "DxLib.h"
#include "Common.h"
class FPSControll
{
public:
	////////////////////////
	//--------関数--------//
	////////////////////////
	// コンストラクタ
	FPSControll();
	// デストラクタ
	~FPSControll();
	// 更新
	void Update();
	// 60フレームに合うように待機
	void WaitFPS();
	// FPSを描画
	void DrawFPS();
	// FPSを計測
	void MeasureFPS();

private:
	////////////////////////
	//--------変数--------//
	////////////////////////
	double firstTime;								//計測開始時間
	double maxTime;									//フレームの最大待機時間
	double fpcCheckTime;							//FPSの計測を開始した時間
	int fpsCount;									//FPSをカウント
	int fps;										//現在のFPS

	////////////////////////
	//--------定数--------//
	////////////////////////
	static constexpr float FrameMin = 0.0f;			//最低値
	static constexpr float FrameMax = 16666.6f;		//1フレームのマイクロ秒　　1,000,000μ / 60μ
	static constexpr int FPSMax = 1000000;			//60フレームのマイクロ秒
	const int FPSColor = GetColor(255, 255, 255);	//FPSの描画色
};

