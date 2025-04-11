#include "DxLib.h"
#include "CharacterState.h"
#include "PlayScene.h"
/// <summary>
/// コンストラクタ
/// </summary>
PlayScene::PlayScene() :
	isNext(false),
	isStart(false),
	isStartSE(false),
	isJudgeDraw(false),
	isCheckPose(false),
	isSuccess(false),
	isMiss(false),
	isFinishJudge(false),
	isGameEnd(false),
	startTime(0),
	audiencePosY(0),
	playerImgAddPos(0),
	nowJudgeImg(0),
	successCount(0),
	gameTimeCount(0),
	inputTimer(0),
	successImg(LoadGraph("Data/Img/Play/Success.png")),
	missImg(LoadGraph("Data/Img/Play/Miss.png")),
	readyImg(LoadGraph("Data/Img/Play/Ready.png")),
	goImg(LoadGraph("Data/Img/Play/Go.png")),
	audienceImg(LoadGraph("Data/Img/Play/Audience.png")),
	playerImg(LoadGraph("Data/Img/Play/Player.png")),
	successCountFontHandle(CreateFontToHandle("Dela Gothic one", SuccessCountFontSize,
		SuccessCountFontThick, DX_FONTTYPE_ANTIALIASING_EDGE, -1, SuccessCountFontEdgeSize)),
	gameTimeFontHandle(CreateFontToHandle("Dela Gothic one", GameTimeFontSize,
		GameTimeFontThick, DX_FONTTYPE_ANTIALIASING_EDGE, -1, GameTimeFontEdgeSize)),
	comboFontHandle(CreateFontToHandle("Dela gothic one", ComboFontSize,
		ComboFontThick, DX_FONTTYPE_ANTIALIASING_EDGE, -1, ComboFontEdgeSize)),
	playerImgPos(VGet(0,0,0))
{

}
/// <summary>
/// デストラクタ
/// </summary>
PlayScene::~PlayScene()
{

}
/// <summary>
/// 初期化
/// </summary>
void PlayScene::Init()
{
	isNext = false;
	isStart = false;
	isStartSE = false;
	isJudgeDraw = false;
	isCheckPose = false;
	isSuccess = false;
	isMiss = false;
	isFinishJudge = false;
	isGameEnd = false;
	startTime = 0;
	successCount = 0;
	inputTimer = 0;
	gameTimeCount = GameTimeMax;
	audiencePosY = AudiencePosY;
	playerImgPos = PlayerImgPos;
}
/// <summary>
/// 更新
/// </summary>
void PlayScene::Update(int _score,bool _isNPCPose,int _npcState,
	int _nowNPCPose,bool _isPlayerPose,int _playerState)
{
	//ゲームの開始時間の計測
	StartTimer();
	//[PLAYER]の座標をセット
	if (!isStart)
	{
		//[Player]の座標を上下に動かす
		if (playerImgPos.y >= PlayerImgPosMaxY)
		{
			playerImgAddPos = -PlayerImgAddPos;
		}
		if (playerImgPos.y <= PlayerImgPosMinY)
		{
			playerImgAddPos = PlayerImgAddPos;
		}
		playerImgPos.y += playerImgAddPos;
	}
	//ポージングの判定
	CheckPose(_isNPCPose,_npcState,_nowNPCPose,_isPlayerPose,_playerState);
	//観客をせりあがらせる
	RiseUpAudience(_score);
	//ゲーム内時間のカウント
	CountGameTime();
	//描画
	Draw();
}
/// <summary>
/// 描画
/// </summary>
void PlayScene::Draw()
{
	if (!isStart)
	{
		//ゲーム開始時間が待機時間より小さい場合
		if (startTime <= ReadyWaitTime)
		{
			//READYを描画
			DrawGraph(ReadyImgPosX, ReadyImgPosY, readyImg, TRUE);
		}
		else
		{
			if (!isStartSE)
			{
				//開始時SEを再生
				isStartSE = true;
			}
			//GOを描画
			DrawGraph(GoImgPosX, GoImgPosY, goImg, TRUE);
		}
		//Playerの上に[Player]を表示
		DrawBillboard3D(playerImgPos, PlayerImgCenter, PlayerImgCenter,
			PlayerImgSize, 0.0f, playerImg, TRUE);
	}
	//観客を表示
	else
	{
		DrawGraph(AudiencePosX, audiencePosY, audienceImg, TRUE);
		//ポージングの判定を描画するかの判定
		if (isJudgeDraw)
		{
			//ポージングの判定を描画
			DrawBillboard3D(JudgeImgPos, JudgeImgCenter, JudgeImgCenter,
				JudgeImgSize, 0.0f, nowJudgeImg, TRUE);
		}

		//ポージングの入力待機時間を描画
	
		//入力待機時間のゲージの枠を描画
		DrawBox(InputTimerGaugeFrameMinX, InputTimerGaugeFrameMinY,
			InputTimerGaugeFrameMaxX, InputTimerGaugeFrameMaxY, InputTimerGaugeFrameColor, TRUE);

		//入力待機時間のゲージを描画
		DrawBox(InputTimerGaugeMinX, InputTimerGaugeMinY,
			InputTimerGaugeMaxX - inputTimer * InputTimerGaugeDecreaseNum, InputTimerGaugeMaxY,
			InputTimerGaugeColor, TRUE);

		int successCountWidth;		//コンボ数文字列の横幅
		//コンボ数文字列の横幅を取得
		successCountWidth = GetDrawFormatStringWidthToHandle(successCountFontHandle, "%d", successCount);

		//連続成功回数を描画
		DrawFormatStringToHandle(SuccessCountPosX - successCountWidth, SuccessCountPosY, SuccessCountColor,
			successCountFontHandle, "%d", successCount);

		//COMBOを連続成功回数の下に描画
		DrawStringToHandle(ComboPosX, ComboPosY, "COMBO", ComboColor, comboFontHandle);

		//ゲームの残り時間を描画
		float width = 0;	//残り時間の文字幅

		//残り時間の文字幅を取得
		width = GetDrawFormatStringWidthToHandle(gameTimeFontHandle, "%d", gameTimeCount / FPS);

		//残り時間を描画
		DrawFormatStringToHandle(GameTimePosX - width / 2, GameTimePosY, GameTimeColor,
			gameTimeFontHandle, "%d", gameTimeCount / FPS);
	}
}
/// <summary>
/// ゲーム開始時間の計測
/// </summary>
void PlayScene::StartTimer()
{
	//ゲーム開始時間を加算
	startTime++;

	//ゲーム開始時間が待機時間以上の場合
	if (startTime >= StartTimeMax)
	{
		//ゲームを開始する
		isStart = true;
	}
}
/// <summary>
/// 成功時観客が出てくる
/// </summary>
void PlayScene::RiseUpAudience(int _score)
{
	int audiencePosMaxY = 0;

	//スコアがハイスコアの時実行
	if (_score >= HighScoreMin)
	{
		audiencePosMaxY = 0;
	}
	//スコアがミドルスコアの時実行
	else if (_score >= MiddleScoreMin)
	{
		audiencePosMaxY = AudienceMiddleScorePos;
	}
	//スコアが上２つ以外の時実行
	else
	{
		audiencePosMaxY = AudienceLowScorePos;
	}

	//ポーズが成功していて、判定を描画していて、観客の座標が0より大きい場合
	if (audiencePosY > audiencePosMaxY && isSuccess)
	{
		//観客の座標を小さくして徐々に画面の上方向へ動かす
		audiencePosY -= AudienceSpeed;
	}
	//判定を描画しておらず、観客の座標が座標の最大値より小さい場合
	else if (audiencePosY < AudiencePosY && !isSuccess)
	{
		//観客の座標を大きくし徐々に画面の下方向へ動かす
		audiencePosY += AudienceSpeed;
	}
}
/// <summary>
/// ポージングの確認
/// </summary>
void PlayScene::CheckPose(bool _isNPCPose,int _npcState,int _nowNPCPose ,bool _isPlayerPose,int _playerState)
{
	bool isTimeOver = false;	//入力待機時間が過ぎたかの判定

	//ポージングの入力待機時間が過ぎているか判定
	isTimeOver = InputTimeCheck(_isNPCPose,_isPlayerPose);
	isFinishJudge = false;
	//ポーズの判定
	if (_isPlayerPose && _isNPCPose || isTimeOver)
	{
		//ポーズ中に１回も判定していないときに判定に入る
		if (!isCheckPose)
		{
			//ポーズをしたかの判定をtrueにする
			isCheckPose = true;

			//ポーズが成功した場合
			if (_playerState == _nowNPCPose)
			{
				//ポージング成功SEを再生
				isSuccess = true;
				//成功の演出
				isJudgeDraw = true;
				//表示するポージングの判定に成功判定の画像を格納
				nowJudgeImg = successImg;
				//連続成功回数を増やす
				successCount++;
			}
			//ポーズが成功していない場合
			else
			{
				//ポージング失敗SEを再生
				isMiss = true;
				//失敗の演出
				isJudgeDraw = true;
				//表示するポージングの判定に失敗判定の画像を格納
				nowJudgeImg = missImg;
				//連続成功回数を0にする
				successCount = 0;
			}
		}
		//Playerがポーズし終わった時に判定をリセットする
		if (_playerState == (int)CharacterState::State::Idle
			&& _isPlayerPose || isTimeOver)
		{
			//ポージング判定をfalseに
			isJudgeDraw = false;
			//ポージングの成功判定をfalseに
			isSuccess = false;
			//ポージングの失敗判定をfalseに
			isMiss = false;
			//ポージングの確認判定をfalseに
			isCheckPose = false;
			//ポージングの終了判定をfalseに
			isFinishJudge = true;
		}
	}
}

/// <summary>
/// 入力待機時間の計測＋判定
/// </summary>
bool PlayScene::InputTimeCheck(bool _isNPCPose, bool _isPlayerPose)
{
	bool isTimeOver = false;		//入力待機時間内にポージングをしていないかの判定

	//NPCがポーズを取り終わってかつプレイヤーがポーズをとっていない場合
	if (_isNPCPose && !_isPlayerPose)
	{
		//入力待機時間を進める
		inputTimer++;
		//入力待機時間が上限以上になった場合
		if (inputTimer >= InputTimerMax)
		{
			//Trueを返して入力待機時間をリセット
			isTimeOver = true;
			inputTimer = 0;
		}
	}
	//Playerがポーズをとっている場合
	if (_isPlayerPose)
	{
		//入力待機時間をリセット
		inputTimer = 0;
	}
	//入力待機時間内にポージングをしていないかの判定を送る
	return isTimeOver;
}

/// <summary>
/// ゲームの残り時間を計測
/// </summary>
void PlayScene::CountGameTime()
{
	if (isStart)
	{
		//ゲームの残り時間を減らす
		gameTimeCount--;
		//ゲームの残り時間が０以下になった場合
		if (gameTimeCount <= 0)
		{
			//ゲーム終了の判定をtrueにする
			isGameEnd = true;
		}
	}
}