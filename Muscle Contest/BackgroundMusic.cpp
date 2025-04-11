#include "DxLib.h"
#include "SceneManager.h"
#include "BackgroundMusic.h"

/// <summary>
/// コンストラクタ
/// </summary>
BackgroundMusic::BackgroundMusic() :
	titleBGM(LoadSoundMem("Data/Sound/BGM/Title.mp3")),
	playBGM(LoadSoundMem("Data/Sound/BGM/Play.mp3")),
	resultBGM(LoadSoundMem("Data/Sound/BGM/Result.mp3")),
	isPlayTitleBGM(false),
	isPlayPlayBGM(false),
	isPlayResultBGM(false)
{
	ChangeVolumeSoundMem(PlayBGMVolume, playBGM);
}
/// <summary>
/// デストラクタ
/// </summary>
BackgroundMusic::~BackgroundMusic()
{
	InitSoundMem();
}
/// <summary>
/// 初期化
/// </summary>
void BackgroundMusic::Init()
{
	isPlayTitleBGM = true;
	isPlayPlayBGM = true;
	isPlayResultBGM = false;
}
/// <summary>
/// 更新
/// </summary>
void BackgroundMusic::Update(int _sceneState, int _successCount)
{
	//シーンの状態がTitleで、タイトルBGMが再生されていない時実行
	if (_sceneState == SceneManager::SceneState::TitleScene && isPlayTitleBGM) 
	{
		//タイトルのBGMを再生
		PlayTitleBGM();
	}
	//シーンの状態がTitleではなく、タイトルBGMが再生されている時実行
	else if(_sceneState != SceneManager::SceneState::TitleScene && !isPlayTitleBGM)
	{
		//タイトルのBGMを停止
		StopTitleBGM();
	}
	//シーンの状態がPlayで、プレイBGMが再生されていない時実行
	if (_sceneState == SceneManager::SceneState::PlayScene)
	{
		//BGMの周波数を変化
		SetFrequencyPlayBGM(_successCount);
		if(isPlayPlayBGM)
		//プレイシーンのBGMを再生
		PlayPlayBGM();
	}
	//シーンの状態がPlayではなく、プレイBGMが再生されている時実行
	else if(_sceneState != SceneManager::SceneState::PlayScene && !isPlayPlayBGM)
	{
		//プレイシーンのBGMを停止
		StopPlayBGM();
	}
	//シーンの状態がResultで、リザルトBGMが再生されていない実行
	if (_sceneState == SceneManager::SceneState::ResultScene && isPlayResultBGM)
	{
		//リザルトのBGMを再生
		PlayResultBGM();
	}
	//シーンの状態がResultではなく、リザルトBGMが再生されている時実行
	else if(_sceneState != SceneManager::SceneState::ResultScene && !isPlayResultBGM)
	{
		//リザルトのBGMを停止
		StopResultBGM();
	}
}

/// <summary>
/// プレイBGMの周波数をコンボ数に合わせて変化させる
/// </summary>
void BackgroundMusic::SetFrequencyPlayBGM(int _successCount)
{
	//コンボ数を獲得
	float addPlayBGMFrequency = _successCount;		//追加する周波数値
	//コンボ数が30以上ならば
	if (addPlayBGMFrequency >= AddPlayBGMFrequencyMax)
	{
		//addPlayBGMFrequencyに30を代入
		addPlayBGMFrequency = AddPlayBGMFrequencyMax;
	}
	//追加する周波数を計算
	addPlayBGMFrequency *= AddPlayBGMFrequencyNum;
	//セットする周波数を計算して周波数をセット
	SetFrequencySoundMem(PlayBGMFrequencyMin + addPlayBGMFrequency, playBGM);
}
/// <summary>
/// タイトルBGMを再生
/// </summary>
void BackgroundMusic::PlayTitleBGM()
{
	PlaySoundMem(titleBGM, DX_PLAYTYPE_LOOP, TRUE);
	isPlayTitleBGM = false;
}
/// <summary>
/// タイトルBGMを停止
/// </summary>
void BackgroundMusic::StopTitleBGM()
{
	StopSoundMem(titleBGM);
	isPlayTitleBGM = true;
}
/// <summary>
/// プレイBGMを再生
/// </summary>
void BackgroundMusic::PlayPlayBGM()
{
	PlaySoundMem(playBGM, DX_PLAYTYPE_LOOP, TRUE);
	isPlayPlayBGM = false;
}
/// <summary>
/// プレイBGMを停止
/// </summary>
void BackgroundMusic::StopPlayBGM()
{
	StopSoundMem(playBGM);
	isPlayPlayBGM = true;
}
/// <summary>
/// リザルトBGMを再生
/// </summary>
void BackgroundMusic::PlayResultBGM()
{
	PlaySoundMem(resultBGM, DX_PLAYTYPE_LOOP, TRUE);
	isPlayResultBGM = false;
}
/// <summary>
/// リザルトBGMを停止
/// </summary>
void BackgroundMusic::StopResultBGM()
{
	StopSoundMem(resultBGM);
	isPlayResultBGM = true;
}