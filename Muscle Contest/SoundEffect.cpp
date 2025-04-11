#include "DxLib.h"
#include "SoundEffect.h"

/// <summary>
/// コンストラクタ
/// </summary>
SoundEffect::SoundEffect() :
	enterSE(LoadSoundMem("Data/Sound/SE/Enter.mp3")),
	missSE(LoadSoundMem("Data/Sound/SE/Miss.mp3")),
	successSE(LoadSoundMem("Data/Sound/SE/Success.mp3")),
	selectSE(LoadSoundMem("Data/Sound/SE/Select.mp3")),
	startSE(LoadSoundMem("Data/Sound/SE/Start.mp3")),
	npcPoseSE(LoadSoundMem("Data/Sound/SE/NPCPosed.mp3")),
	playerSuccessPoseSE(LoadSoundMem("Data/Sound/SE/PlayerSuccessPosed.mp3")),
	playerMissPoseSE(LoadSoundMem("Data/Sound/SE/PlayerMissPosed.mp3")),
	lastFrameIsEnterSE(false),
	lastFrameIsMissSE(false),
	lastFrameIsSelectSE(false),
	lastFrameIsStartSE(false),
	lastFrameIsSuccessSE(false),
	lastFrameIsNPCPoseSE(false)
{

}
/// <summary>
/// デストラクタ
/// </summary>
SoundEffect::~SoundEffect()
{
	InitSoundMem();
}
/// <summary>
/// 初期化
/// </summary>
void SoundEffect::Init()
{

}
/// <summary>
/// 更新
/// </summary>
void SoundEffect::Update(bool _isSuccess, bool _isMiss, 
	bool _isSelect, bool _isEnter, bool _isNPCPose, bool _isStart)
{
	//決定判定の前フレームの判定がFalseで今フレームの判定がTrueの時実行
	if (!lastFrameIsEnterSE && _isEnter)
	{
		PlayEnterSE();
	}
	//ゲームスタート判定の前フレームの判定がFalseで今フレームの判定がTrueの時実行
	if (!lastFrameIsStartSE && _isStart)
	{
		PlayStartSE();
	}
	//ボタン選択判定の前フレームの判定がFalseで今フレームの判定がTrueの時実行
	if (!lastFrameIsSelectSE && _isSelect)
	{
		PlaySelectSE();
	}
	//NPCのポーズ判定の前フレームの判定がFalseで今フレームの判定がTrueの時実行
	if (!lastFrameIsNPCPoseSE && _isNPCPose)
	{
		PlayNPCPoseSE();
	}
	//成功判定の前フレームの判定がFalseで今フレームの判定がTrueの時実行
	if (!lastFrameIsSuccessSE && _isSuccess)
	{
		PlayPlayerSuccessPoseSE();
		PlaySuccessSE();
	}
	//ミス判定の前フレームの判定がFalseで今フレームの判定がTrueの時実行
	if (!lastFrameIsMissSE && _isMiss)
	{
		PlayPlayerMissPoseSE();
		PlayMissSE();
	}
	//今フレームの判定を前フレームの判定として保存
	SetLastIsSE(_isSuccess,_isMiss,_isSelect,_isEnter,_isNPCPose,_isStart);
}
/// <summary>
/// 決定時SEを再生
/// </summary>
void SoundEffect::PlayEnterSE()
{
	PlaySoundMem(enterSE, DX_PLAYTYPE_BACK, TRUE);
}
/// <summary>
/// ポージング失敗SEを再生
/// </summary>
void SoundEffect::PlayMissSE()
{
	PlaySoundMem(missSE, DX_PLAYTYPE_BACK, TRUE);
}
/// <summary>
/// ポージング成功SEを再生
/// </summary>
void SoundEffect::PlaySuccessSE()
{
	PlaySoundMem(successSE, DX_PLAYTYPE_BACK, TRUE);
}
/// <summary>
/// 選択時SEを再生
/// </summary>
void SoundEffect::PlaySelectSE()
{
	PlaySoundMem(selectSE, DX_PLAYTYPE_BACK, TRUE);
}
/// <summary>
/// ゲームスタート時SEを再生
/// </summary>
void SoundEffect::PlayStartSE()
{
	PlaySoundMem(startSE, DX_PLAYTYPE_BACK, TRUE);
}
/// <summary>
/// NPCがポーズした時のSEを再生
/// </summary>
void SoundEffect::PlayNPCPoseSE()
{
	PlaySoundMem(npcPoseSE, DX_PLAYTYPE_BACK, TRUE);
}
/// <summary>
/// プレイヤーがポーズしたときの成功SEを再生
/// </summary>
void SoundEffect::PlayPlayerSuccessPoseSE()
{
	PlaySoundMem(playerSuccessPoseSE, DX_PLAYTYPE_BACK, TRUE);
}
/// <summary>
/// プレイヤーがポーズしたときの失敗SEを再生
/// </summary>
void SoundEffect::PlayPlayerMissPoseSE()
{
	PlaySoundMem(playerMissPoseSE, DX_PLAYTYPE_BACK, TRUE);
}
/// <summary>
/// 前フレームの判定として、今フレームの判定を保存
/// </summary>
void SoundEffect::SetLastIsSE(bool _isSuccess, bool _isMiss,
	bool _isSelect, bool _isEnter, bool _isNPCPose, bool _isStart)
{
	lastFrameIsSuccessSE = _isSuccess;
	lastFrameIsMissSE = _isMiss;
	lastFrameIsSelectSE = _isSelect;
	lastFrameIsEnterSE = _isEnter;
	lastFrameIsNPCPoseSE = _isNPCPose;
	lastFrameIsStartSE = _isStart;
}