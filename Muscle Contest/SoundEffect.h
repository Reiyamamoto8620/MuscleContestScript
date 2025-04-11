#pragma once
class SoundEffect
{
public:
	////////////////////////
	//--------関数--------//
	////////////////////////
	//コンストラクタ
	SoundEffect();
	//デストラクタ
	~SoundEffect();
	//初期化
	void Init();
	//更新
	void Update(bool _isSuccess, bool _isMiss, bool _isSelect, bool _isEnter, bool _isNPCPose, bool _isStart);
private:
	////////////////////////
	//--------関数--------//
	////////////////////////
	//決定時SEを再生
	void PlayEnterSE();
	//ポージング失敗SEを再生
	void PlayMissSE();
	//ポージング成功SEを再生
	void PlaySuccessSE();
	//選択時SEを再生
	void PlaySelectSE();
	//ゲームスタート時SEを再生
	void PlayStartSE();
	//NPCがポーズした時のSEを再生
	void PlayNPCPoseSE();
	//プレイヤーがポーズしたときの成功SEを再生
	void PlayPlayerSuccessPoseSE();
	//プレイヤーがポーズしたときの失敗SEを再生
	void PlayPlayerMissPoseSE();
	//前フレームの判定として、今フレームの判定を保存
	void SetLastIsSE(bool _isSuccess,bool _isMiss,bool _isSelect, 
		bool _isEnter,bool _isNPCPose,bool _isStart);

	////////////////////////
	//--------変数--------//
	////////////////////////
	int enterSE;				//決定時SE
	int missSE;					//ポージング失敗SE
	int successSE;				//ポージング成功SE
	int selectSE;				//選択時SE
	int startSE;				//ゲーム開始時SE
	int npcPoseSE;				//NPCがポーズしたときのSE
	int playerSuccessPoseSE;	//プレイヤーがポーズしたときの成功SE
	int playerMissPoseSE;		//プレイヤーがポーズしたときの失敗SE

	bool lastFrameIsEnterSE;			//前フレームのIsEnterの判定
	bool lastFrameIsMissSE;				//前フレームのIsMissの判定
	bool lastFrameIsSuccessSE;			//前フレームのIsSuccessの判定
	bool lastFrameIsSelectSE;			//前フレームのIsSelectの判定
	bool lastFrameIsStartSE;			//前フレームのIsStartの判定
	bool lastFrameIsNPCPoseSE;			//前フレームのIsNPCPoseの判定
};