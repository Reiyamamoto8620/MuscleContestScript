#include "DxLib.h"
#include "SoundEffect.h"

/// <summary>
/// �R���X�g���N�^
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
/// �f�X�g���N�^
/// </summary>
SoundEffect::~SoundEffect()
{
	InitSoundMem();
}
/// <summary>
/// ������
/// </summary>
void SoundEffect::Init()
{

}
/// <summary>
/// �X�V
/// </summary>
void SoundEffect::Update(bool _isSuccess, bool _isMiss, 
	bool _isSelect, bool _isEnter, bool _isNPCPose, bool _isStart)
{
	//���蔻��̑O�t���[���̔��肪False�ō��t���[���̔��肪True�̎����s
	if (!lastFrameIsEnterSE && _isEnter)
	{
		PlayEnterSE();
	}
	//�Q�[���X�^�[�g����̑O�t���[���̔��肪False�ō��t���[���̔��肪True�̎����s
	if (!lastFrameIsStartSE && _isStart)
	{
		PlayStartSE();
	}
	//�{�^���I�𔻒�̑O�t���[���̔��肪False�ō��t���[���̔��肪True�̎����s
	if (!lastFrameIsSelectSE && _isSelect)
	{
		PlaySelectSE();
	}
	//NPC�̃|�[�Y����̑O�t���[���̔��肪False�ō��t���[���̔��肪True�̎����s
	if (!lastFrameIsNPCPoseSE && _isNPCPose)
	{
		PlayNPCPoseSE();
	}
	//��������̑O�t���[���̔��肪False�ō��t���[���̔��肪True�̎����s
	if (!lastFrameIsSuccessSE && _isSuccess)
	{
		PlayPlayerSuccessPoseSE();
		PlaySuccessSE();
	}
	//�~�X����̑O�t���[���̔��肪False�ō��t���[���̔��肪True�̎����s
	if (!lastFrameIsMissSE && _isMiss)
	{
		PlayPlayerMissPoseSE();
		PlayMissSE();
	}
	//���t���[���̔����O�t���[���̔���Ƃ��ĕۑ�
	SetLastIsSE(_isSuccess,_isMiss,_isSelect,_isEnter,_isNPCPose,_isStart);
}
/// <summary>
/// ���莞SE���Đ�
/// </summary>
void SoundEffect::PlayEnterSE()
{
	PlaySoundMem(enterSE, DX_PLAYTYPE_BACK, TRUE);
}
/// <summary>
/// �|�[�W���O���sSE���Đ�
/// </summary>
void SoundEffect::PlayMissSE()
{
	PlaySoundMem(missSE, DX_PLAYTYPE_BACK, TRUE);
}
/// <summary>
/// �|�[�W���O����SE���Đ�
/// </summary>
void SoundEffect::PlaySuccessSE()
{
	PlaySoundMem(successSE, DX_PLAYTYPE_BACK, TRUE);
}
/// <summary>
/// �I����SE���Đ�
/// </summary>
void SoundEffect::PlaySelectSE()
{
	PlaySoundMem(selectSE, DX_PLAYTYPE_BACK, TRUE);
}
/// <summary>
/// �Q�[���X�^�[�g��SE���Đ�
/// </summary>
void SoundEffect::PlayStartSE()
{
	PlaySoundMem(startSE, DX_PLAYTYPE_BACK, TRUE);
}
/// <summary>
/// NPC���|�[�Y��������SE���Đ�
/// </summary>
void SoundEffect::PlayNPCPoseSE()
{
	PlaySoundMem(npcPoseSE, DX_PLAYTYPE_BACK, TRUE);
}
/// <summary>
/// �v���C���[���|�[�Y�����Ƃ��̐���SE���Đ�
/// </summary>
void SoundEffect::PlayPlayerSuccessPoseSE()
{
	PlaySoundMem(playerSuccessPoseSE, DX_PLAYTYPE_BACK, TRUE);
}
/// <summary>
/// �v���C���[���|�[�Y�����Ƃ��̎��sSE���Đ�
/// </summary>
void SoundEffect::PlayPlayerMissPoseSE()
{
	PlaySoundMem(playerMissPoseSE, DX_PLAYTYPE_BACK, TRUE);
}
/// <summary>
/// �O�t���[���̔���Ƃ��āA���t���[���̔����ۑ�
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