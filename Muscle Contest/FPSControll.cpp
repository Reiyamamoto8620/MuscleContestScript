#include "FPSControll.h"
/// <summary>
/// コンストラクタ
/// </summary>
FPSControll::FPSControll()
{
	firstTime = FrameMin;
	maxTime = FrameMax;
	fpsCount = 0;
	fps = 0;
	fpcCheckTime = GetNowHiPerformanceCount();
}
/// <summary>
/// デストラクタ
/// </summary>
FPSControll::~FPSControll()
{

}
/// <summary>
/// 更新
/// </summary>
void FPSControll::Update()
{
	firstTime = GetNowHiPerformanceCount();//現在の経過時間を取得
	fpsCount++;
	MeasureFPS();
}
/// <summary>
/// 60フレームに合うように待機
/// </summary>
void FPSControll::WaitFPS()
{
	//Updateで取得した時間と今の時間の差を、決めた時間を比較してフレームを調節する
	while (GetNowHiPerformanceCount() - firstTime < maxTime)
	{
		//処理なし
	}
	
}
/// <summary>
/// FPSを描画
/// </summary>
void FPSControll::DrawFPS()
{
	DrawFormatString(0, 0, FPSColor, "%d", fps);
}
/// <summary>
/// FPSを計測
/// </summary>
void FPSControll::MeasureFPS()
{
	//今の時間を取得
	double nowTime = GetNowHiPerformanceCount();
	//現在のＦＰＳを計算
	if (nowTime - fpcCheckTime > FPSMax)
	{
		fps = fpsCount;
		fpsCount = 0;
		fpcCheckTime = nowTime;
	}
}