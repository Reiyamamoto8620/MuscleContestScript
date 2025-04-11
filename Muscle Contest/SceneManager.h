#pragma once

//プロトタイプ宣言
class FPSControll;
class ScoreRanking;
class PlayerManager;
class NPCManager;
class ScoreManager;
class MapManager;
class CameraManager;
class SoundManager;
class PlaySceneManager;
class TitleSceneManager;
class ResultSceneManager;

class SceneManager
{
public:
	//シーンステート
	enum SceneState
	{
		TitleScene,
		PlayScene,
		ResultScene,
		LoadScene,
		WaitPlayScene
	};
	
	////////////////////////
	//--------関数--------//
	////////////////////////
	//コンストラクタ
	SceneManager();
	//デストラクタ
	~SceneManager();
	//初期化
	void Init();
	//タイトルシーン
	void Title(TitleSceneManager& _titleSceneManager, FPSControll& _fpsControll,CameraManager& _cameraManager,
		ScoreRanking& _scoreRanking,PlayerManager& _playerManager,
		NPCManager& _npcManager,MapManager& _mapManager,SoundManager& _soundManager);
	//プレイシーン
	void Play(PlaySceneManager& _playSceneManager, FPSControll& _fpsControll, CameraManager& _cameraManager,
		PlayerManager& _playerManager,NPCManager& _npcManager, ScoreManager& _scoreManager, 
		MapManager& _mapManager, SoundManager& _soundManager);
	//リザルトシーン
	void Result(ResultSceneManager& _resultSceneManager, FPSControll& _fpsControll, CameraManager& _cameraManager,
		 PlayerManager& _playerManager,ScoreManager& _scoreManager, 
		MapManager& _mapManager, SoundManager& _soundManager);
	//GET,POST中にゲームが進まないようにするロードシーン
	void Load(ScoreRanking& _scoreRanking,
		FPSControll&_fpsControll, SoundManager& _soundManager);
private:
	////////////////////////
	//--------変数--------//
	////////////////////////
	int nowLoadingImgBlendNum;		//現在のNOWLOADINFのブレンド値
	int nowBlendAddNum;				//現在のブレンド加算値
	int nowLoadingImg;				//NOWLOADINGの画像
	int sceneState;					//シーンの状態

	////////////////////////
	//--------定数--------//
	////////////////////////
	static constexpr int AddScore = 100;				//スコアの加算値
	static constexpr int ScoreBonus = 10;				//スコアのコンボボーナス
	static constexpr int NowLoadingImgX = 423;			//NOWLOADINGのX座標
	static constexpr int NowLoadingImgY = 440;			//NOWLOADINGのY座標
	static constexpr int NowLoadingImgBlendMax = 255;	//NOWLOADINGのブレンド値の最大
	static constexpr int NowLoadingBlendSpeed = 5;		//NOWLOADINGのブレンド加算値のスピード
	static constexpr float JudgeImgSize = 2.5f;			//ポージング判定の描画サイズ
	static constexpr float JudgeImgCenter = 0.5f;		//ポージング判定の画像の中心
	const VECTOR JudgeImgPos = VGet(2, 5.625, 25);		//ポージング判定の描画座標

};

