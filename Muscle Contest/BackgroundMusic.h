#pragma once
class BackgroundMusic
{
public:
	////////////////////////
	//--------関数--------//
	////////////////////////
	//コンストラクタ
	BackgroundMusic();
	//デストラクタ
	~BackgroundMusic();
	//初期化
	void Init();
	//更新
	void Update(int _sceneState,int _successCount);
private:
	////////////////////////
	//--------関数--------//
	////////////////////////
	//プレイBGMの周波数をコンボ数に合わせて変化させる
	void SetFrequencyPlayBGM(int _successCount);
	//タイトルBGMを再生
	void PlayTitleBGM();
	//タイトルBGMを停止
	void StopTitleBGM();
	//プレイBGMを再生
	void PlayPlayBGM();
	//プレイBGMを停止
	void StopPlayBGM();
	//リザルトBGMを再生
	void PlayResultBGM();
	//リザルトBGMを停止
	void StopResultBGM();

	////////////////////////
	//--------変数--------//
	////////////////////////
	int titleBGM;				//タイトルBGM
	int playBGM;				//プレイBGM
	int resultBGM;				//リザルトBGM
	bool isPlayTitleBGM;		//タイトルBGMの再生判定
	bool isPlayPlayBGM;			//プレイBGMの再生判定
	bool isPlayResultBGM;		//リザルトBGMの再生判定

	////////////////////////
	//--------定数--------//
	////////////////////////
	static constexpr int PlayBGMVolume = 200;				//プレイBGMの音量
	static constexpr int AddPlayBGMFrequencyMax = 30;		//PlayBGMに追加する周波数値の最大
	static constexpr int AddPlayBGMFrequencyNum = 500;		//1コンボあたりに追加される周波数値
	static constexpr int PlayBGMFrequencyMin = 35000;		//PlayBGMの周波数の最小
};