#include "DxLib.h"
#include "FPSControll.h"
#include "ScoreRanking.h"
#include "PlayerManager.h"
#include "NPCManager.h"
#include "CharacterState.h"
#include "ScoreManager.h"
#include "MapManager.h"
#include "CameraManager.h"
#include "SoundManager.h"
#include "PlaySceneManager.h"
#include "TitleSceneManager.h"
#include "ResultSceneManager.h"
#include "SceneManager.h"

/// <summary>
/// コンストラクタ
/// </summary>
SceneManager::SceneManager() :
	nowLoadingImgBlendNum(0),
	nowBlendAddNum(0),
	sceneState(0),
	nowLoadingImg(LoadGraph("Data/Img/Load/NowLoading.png"))
{

}
/// <summary>
/// デストラクタ
/// </summary>
SceneManager::~SceneManager()
{

}
/// <summary>
/// 初期化
/// </summary>
void SceneManager::Init()
{
	nowBlendAddNum = 0;
	nowLoadingImgBlendNum = 0;
}
/// <summary>
/// タイトルシーン
/// </summary>
void SceneManager::Title(TitleSceneManager& _titleSceneManager, FPSControll& _fpsControll, 
	CameraManager& _cameraManager,ScoreRanking& _scoreRanking, PlayerManager& _playerManager,
	NPCManager& _npcManager, MapManager& _mapManager, SoundManager& _soundManager)
{
	//シーンステートをタイトル状態に変更
	sceneState = (int)SceneState::TitleScene;
	//カメラのポジションをタイトル用にセット
	_cameraManager.Init(sceneState);
	while (!CheckHitKey(KEY_INPUT_ESCAPE))
	{
		//FPSの計測を開始
		_fpsControll.Update();
		//画面をクリア
		ClearDrawScreen();
		//カメラの更新
		_cameraManager.Update();
		//マップの更新
		_mapManager.Update();
		//NPCの更新
		_npcManager.Update(0, sceneState, _playerManager.GetIsPose(), false);
		//プレイヤーの更新
		_playerManager.Update(0, sceneState, _npcManager.GetIsPose(), false);
		//タイトルの更新
		_titleSceneManager.Update();
		//サウンドの更新
		_soundManager.Update(sceneState, 0, false, false, _titleSceneManager.GetIsSelect(),
			_titleSceneManager.GetIsEnter(), false, false);
		//isDrawScoreがtrueの時スコアランキングを描画する。
		if (_titleSceneManager.GetIsDrawScore())
		{
			//スコアランキングを描画
			_scoreRanking.Draw();
		}
		//裏画面を描画
		ScreenFlip();
		//FPS固定用にフレームが合うまで待機
		_fpsControll.WaitFPS();
		//決定ボタンが押されたとき
		if (_titleSceneManager.GetIsNext())
		{
			//whileから抜ける
			break;
		}
	}
}
/// <summary>
/// プレイシーン
/// </summary>
void SceneManager::Play(PlaySceneManager& _playSceneManager, FPSControll& _fpsControll,
	CameraManager& _cameraManager,PlayerManager& _playerManager,NPCManager& _npcManager, 
	ScoreManager& _scoreManager, MapManager& _mapManager, SoundManager& _soundManager)
{
	//シーンステートをプレイ待機状態に変更
	sceneState = (int)SceneState::WaitPlayScene;
	//カメラのポジションをリザルト用にセット
	_cameraManager.Init(sceneState);
	float playerImgAddPos = 0;		//[Player]のY座標加算値
	//ゲームループ
	while (!CheckHitKey(KEY_INPUT_ESCAPE))
	{
		//FPSの計測を開始
		_fpsControll.Update();
		//画面をクリア
		ClearDrawScreen();
		//カメラを更新
		_cameraManager.Update();
		//マップの更新
		_mapManager.Update();
		//NPCの更新
		_npcManager.Update(_playSceneManager.GetSuccessCount(), sceneState,
			_playerManager.GetIsPose(), _playSceneManager.GetIsFinishJudge());
		//プレイヤーの更新
		_playerManager.Update(_playSceneManager.GetSuccessCount(),sceneState,
			_npcManager.GetIsPose(), _playSceneManager.GetIsFinishJudge());
		//Playシーンの更新
		_playSceneManager.Update(_scoreManager.GetScore(), 
			_npcManager.GetIsPose(),_npcManager.GetState(), 
			_npcManager.GetNowPose(),_playerManager.GetIsPose(),_playerManager.GetState());
		//ゲーム開始判定
		if (_playSceneManager.GetIsStart())
		{
			//スコアの更新
			_scoreManager.Update(_playSceneManager.GetSuccessCount(),
				_playSceneManager.GetIsSuccess());
			//シーンステートをプレイ状態に変更
			sceneState = (int)SceneManager::SceneState::PlayScene;
		}
		//サウンドの更新
		_soundManager.Update(sceneState, _playSceneManager.GetSuccessCount(), 
			_playSceneManager.GetIsSuccess(),_playSceneManager.GetIsMiss(), 
			false, false, _npcManager.GetIsPose(), _playSceneManager.GetIsStartSE());
		//裏画面を描画
		ScreenFlip();
		//FPS固定用にフレームが合うまで待機
		_fpsControll.WaitFPS();
		//ゲーム終了判定
		if (_playSceneManager.GetIsGameEnd())
		{
			//whileを抜ける
			break;
		}
	}
}
/// <summary>
/// リザルトシーン
/// </summary>
void SceneManager::Result(ResultSceneManager& _resultSceneManager, 
	FPSControll& _fpsControll, CameraManager& _cameraManager,PlayerManager& _playerManager,
	ScoreManager& _scoreManager, MapManager& _mapManager, SoundManager& _soundManager)
{
	//シーンステートをリザルト状態に変更
	sceneState = (int)SceneState::ResultScene;
	//カメラのポジションをリザルト用にセット
	_cameraManager.Init(sceneState);

	while (!CheckHitKey(KEY_INPUT_ESCAPE))
	{
		//FPSの計測を開始
		_fpsControll.Update();
		//画面を初期化
		ClearDrawScreen();
		//カメラの更新
		_cameraManager.Update();
		//マップの描画
		_mapManager.Update();
		//プレイヤーの更新
		_playerManager.Update(0, sceneState, false, false);
		//リザルトシーンの更新
		_resultSceneManager.Update(_scoreManager.GetScore());
		//サウンドの更新
		_soundManager.Update(sceneState, 0, false, false, _resultSceneManager.GetIsSelect(), 
			_resultSceneManager.GetIsEnter(), false, false);
		//裏画面を描画
		ScreenFlip();
		//FPS固定用にフレームが合うまで待機
		_fpsControll.WaitFPS();
		//決定ボタンが押されたとき
		if (_resultSceneManager.GetIsNext())
		{
			//whileから抜ける
			break;
		}
	}
}
/// <summary>
/// GET,POST中にゲームが進まないようにするロードシーン
/// </summary>
void SceneManager::Load(ScoreRanking& _scoreRanking, 
	FPSControll& _fpsControll,SoundManager& _soundManager)
{
	//シーンステートをロード状態に変更
	sceneState = (int)SceneState::LoadScene;
	//サウンドの更新(全て止める)
	_soundManager.Update(sceneState, 0, false, false, false, false, false, false);

	while (true)
	{
		//FPSの計測を開始
		_fpsControll.Update();
		//タスクが終了した場合
		if (_scoreRanking.GetIsTaskEnd())
		{
			//whileから抜ける
			break;
		}
		//画面を初期化
		ClearDrawScreen();
		//NOWLOADINGのブレンド値をセット
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, nowLoadingImgBlendNum);
		//NOWLOADINGの描画
		DrawGraph(NowLoadingImgX, NowLoadingImgY, nowLoadingImg, TRUE);
		//ブレンド値をデフォルトに戻す
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, NowLoadingImgBlendMax);
		//裏画面を描画
		ScreenFlip();
		//現在のブレンド値が0以下の場合
		if (nowLoadingImgBlendNum <= 0)
		{
			//ブレンド値の加算値を+にする
			nowBlendAddNum = NowLoadingBlendSpeed;
		}
		//ブレンド値が255以上の場合
		else if (nowLoadingImgBlendNum >= NowLoadingImgBlendMax)
		{
			//ブレンド値の加算値を-にする
			nowBlendAddNum = -NowLoadingBlendSpeed;
		}
		//現在のブレンド値にブレンドの加算値をたす
		nowLoadingImgBlendNum += nowBlendAddNum;
		//FPS固定用にフレームが合うまで待機
		_fpsControll.WaitFPS();
	}
}