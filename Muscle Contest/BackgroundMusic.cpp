#include "DxLib.h"
#include "SceneManager.h"
#include "BackgroundMusic.h"

/// <summary>
/// �R���X�g���N�^
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
/// �f�X�g���N�^
/// </summary>
BackgroundMusic::~BackgroundMusic()
{
	InitSoundMem();
}
/// <summary>
/// ������
/// </summary>
void BackgroundMusic::Init()
{
	isPlayTitleBGM = true;
	isPlayPlayBGM = true;
	isPlayResultBGM = false;
}
/// <summary>
/// �X�V
/// </summary>
void BackgroundMusic::Update(int _sceneState, int _successCount)
{
	//�V�[���̏�Ԃ�Title�ŁA�^�C�g��BGM���Đ�����Ă��Ȃ������s
	if (_sceneState == SceneManager::SceneState::TitleScene && isPlayTitleBGM) 
	{
		//�^�C�g����BGM���Đ�
		PlayTitleBGM();
	}
	//�V�[���̏�Ԃ�Title�ł͂Ȃ��A�^�C�g��BGM���Đ�����Ă��鎞���s
	else if(_sceneState != SceneManager::SceneState::TitleScene && !isPlayTitleBGM)
	{
		//�^�C�g����BGM���~
		StopTitleBGM();
	}
	//�V�[���̏�Ԃ�Play�ŁA�v���CBGM���Đ�����Ă��Ȃ������s
	if (_sceneState == SceneManager::SceneState::PlayScene)
	{
		//BGM�̎��g����ω�
		SetFrequencyPlayBGM(_successCount);
		if(isPlayPlayBGM)
		//�v���C�V�[����BGM���Đ�
		PlayPlayBGM();
	}
	//�V�[���̏�Ԃ�Play�ł͂Ȃ��A�v���CBGM���Đ�����Ă��鎞���s
	else if(_sceneState != SceneManager::SceneState::PlayScene && !isPlayPlayBGM)
	{
		//�v���C�V�[����BGM���~
		StopPlayBGM();
	}
	//�V�[���̏�Ԃ�Result�ŁA���U���gBGM���Đ�����Ă��Ȃ����s
	if (_sceneState == SceneManager::SceneState::ResultScene && isPlayResultBGM)
	{
		//���U���g��BGM���Đ�
		PlayResultBGM();
	}
	//�V�[���̏�Ԃ�Result�ł͂Ȃ��A���U���gBGM���Đ�����Ă��鎞���s
	else if(_sceneState != SceneManager::SceneState::ResultScene && !isPlayResultBGM)
	{
		//���U���g��BGM���~
		StopResultBGM();
	}
}

/// <summary>
/// �v���CBGM�̎��g�����R���{���ɍ��킹�ĕω�������
/// </summary>
void BackgroundMusic::SetFrequencyPlayBGM(int _successCount)
{
	//�R���{�����l��
	float addPlayBGMFrequency = _successCount;		//�ǉ�������g���l
	//�R���{����30�ȏ�Ȃ��
	if (addPlayBGMFrequency >= AddPlayBGMFrequencyMax)
	{
		//addPlayBGMFrequency��30����
		addPlayBGMFrequency = AddPlayBGMFrequencyMax;
	}
	//�ǉ�������g�����v�Z
	addPlayBGMFrequency *= AddPlayBGMFrequencyNum;
	//�Z�b�g������g�����v�Z���Ď��g�����Z�b�g
	SetFrequencySoundMem(PlayBGMFrequencyMin + addPlayBGMFrequency, playBGM);
}
/// <summary>
/// �^�C�g��BGM���Đ�
/// </summary>
void BackgroundMusic::PlayTitleBGM()
{
	PlaySoundMem(titleBGM, DX_PLAYTYPE_LOOP, TRUE);
	isPlayTitleBGM = false;
}
/// <summary>
/// �^�C�g��BGM���~
/// </summary>
void BackgroundMusic::StopTitleBGM()
{
	StopSoundMem(titleBGM);
	isPlayTitleBGM = true;
}
/// <summary>
/// �v���CBGM���Đ�
/// </summary>
void BackgroundMusic::PlayPlayBGM()
{
	PlaySoundMem(playBGM, DX_PLAYTYPE_LOOP, TRUE);
	isPlayPlayBGM = false;
}
/// <summary>
/// �v���CBGM���~
/// </summary>
void BackgroundMusic::StopPlayBGM()
{
	StopSoundMem(playBGM);
	isPlayPlayBGM = true;
}
/// <summary>
/// ���U���gBGM���Đ�
/// </summary>
void BackgroundMusic::PlayResultBGM()
{
	PlaySoundMem(resultBGM, DX_PLAYTYPE_LOOP, TRUE);
	isPlayResultBGM = false;
}
/// <summary>
/// ���U���gBGM���~
/// </summary>
void BackgroundMusic::StopResultBGM()
{
	StopSoundMem(resultBGM);
	isPlayResultBGM = true;
}