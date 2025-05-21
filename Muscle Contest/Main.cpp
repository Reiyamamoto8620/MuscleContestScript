#include "DxLib.h"
#include "Common.h"
#include "SceneManager.h"
#include "FPSControll.h"
#include "ScoreRanking.h"
#include "PlayerManager.h"
#include "NPCManager.h"
#include "ScoreManager.h"
#include "MapManager.h"
#include "LightManager.h"
#include "CameraManager.h"
#include "SoundManager.h"
#include "PlaySceneManager.h"
#include "TitleSceneManager.h"
#include "ResultSceneManager.h"
#include <Sensapi.h>
#pragma comment(lib,"Sensapi.lib")


int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	//垂直同期を切る
	SetWaitVSyncFlag(0);
	//Dxlibの初期化
	if (DxLib_Init() == -1)
	{
		return -1;//エラーが起きたら直ちに終了
	}

	//画面初期設定
	SetDrawScreen(DX_SCREEN_BACK);
	SetGraphMode(DisplaySizeX, DisplaySizeY, ColorBit);
	ChangeWindowMode(TRUE);
	SetMouseDispFlag(FALSE);
	// Ｚバッファを有効にする
	SetUseZBuffer3D(TRUE);

	// Ｚバッファへの書き込みを有効にする
	SetWriteZBuffer3D(TRUE);
	LPCSTR fontPath = "Data/Font/DelaGothicOne-Regular.ttf";
	if (AddFontResourceEx(fontPath, FR_PRIVATE, NULL) > 0)
	{
		//処理なし
	}
	else {
		// フォント読込エラー処理
		MessageBox(NULL, "フォント読込失敗", "", MB_OK);
	}

	//変数宣言
	FPSControll* fpsControll = new FPSControll;
	SceneManager* sceneManager = new SceneManager;
	ScoreRanking* scoreRanking = new ScoreRanking;
	PlayerManager* playerManager = new PlayerManager;
	NPCManager* npcManager = new NPCManager;
	ScoreManager* scoreManager = new ScoreManager;
	MapManager* mapManager = new MapManager;
	LightManager* lightManager = new LightManager;
	CameraManager* cameraManager = new CameraManager;
	SoundManager* soundManager = new SoundManager;
	PlaySceneManager* playSceneManager = new PlaySceneManager;
	TitleSceneManager* titleSceneManager = new TitleSceneManager;
	ResultSceneManager* resultSceneManager = new ResultSceneManager;

	while (!CheckHitKey(KEY_INPUT_ESCAPE))
	{
		//初期化
		lightManager->Init();
		sceneManager->Init();
		scoreRanking->Init();
		playerManager->Init();
		npcManager->Init();
		scoreManager->Init();
		mapManager->Init();
		soundManager->Init();
		playSceneManager->Init();
		titleSceneManager->Init();

		//リプレイの場合はタイトルに入らない
		if (!resultSceneManager->GetIsReplay())
		{
			//前回のタスクが終わるまで待機
			sceneManager->Load(*scoreRanking, *fpsControll,*soundManager);
			//ネットワークに接続を確認し、スコアをGET
			scoreRanking->Update(Get, scoreManager->GetScore());
			//タスクが終わるまで待機
			sceneManager->Load(*scoreRanking, *fpsControll,*soundManager);
			//タイトルシーン
			sceneManager->Title(*titleSceneManager, *fpsControll, *cameraManager,
				*scoreRanking, *playerManager, *npcManager, *mapManager, *soundManager);

			//ゲーム終了が選択された場合
			if (titleSceneManager->GetIsEnd())
			{
				break;
			}
		}
		//リザルトの初期化
		resultSceneManager->Init();
		//プレイシーン
		sceneManager->Play(*playSceneManager, *fpsControll, *cameraManager, *playerManager,
			*npcManager, *scoreManager, *mapManager, *soundManager);
		//プレイヤーの初期化
		playerManager->Init();
		//前回のタスクが終わるまで待機
		sceneManager->Load(*scoreRanking, *fpsControll,*soundManager);
		//ネットワークの接続を確認し、スコアをPOST
		scoreRanking->Update(Post, scoreManager->GetScore());
		//リザルトシーン
		sceneManager->Result(*resultSceneManager, *fpsControll, *cameraManager,
			*playerManager, *scoreManager, *mapManager, *soundManager);
	}

	//DxLib の後始末
	DxLib_End();
	return 0;
}