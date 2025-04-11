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
/// �R���X�g���N�^
/// </summary>
SceneManager::SceneManager() :
	nowLoadingImgBlendNum(0),
	nowBlendAddNum(0),
	sceneState(0),
	nowLoadingImg(LoadGraph("Data/Img/Load/NowLoading.png"))
{

}
/// <summary>
/// �f�X�g���N�^
/// </summary>
SceneManager::~SceneManager()
{

}
/// <summary>
/// ������
/// </summary>
void SceneManager::Init()
{
	nowBlendAddNum = 0;
	nowLoadingImgBlendNum = 0;
}
/// <summary>
/// �^�C�g���V�[��
/// </summary>
void SceneManager::Title(TitleSceneManager& _titleSceneManager, FPSControll& _fpsControll, 
	CameraManager& _cameraManager,ScoreRanking& _scoreRanking, PlayerManager& _playerManager,
	NPCManager& _npcManager, MapManager& _mapManager, SoundManager& _soundManager)
{
	//�V�[���X�e�[�g���^�C�g����ԂɕύX
	sceneState = (int)SceneState::TitleScene;
	//�J�����̃|�W�V�������^�C�g���p�ɃZ�b�g
	_cameraManager.Init(sceneState);
	while (!CheckHitKey(KEY_INPUT_ESCAPE))
	{
		//FPS�̌v�����J�n
		_fpsControll.Update();
		//��ʂ��N���A
		ClearDrawScreen();
		//�J�����̍X�V
		_cameraManager.Update();
		//�}�b�v�̍X�V
		_mapManager.Update();
		//NPC�̍X�V
		_npcManager.Update(0, sceneState, _playerManager.GetIsPose(), false);
		//�v���C���[�̍X�V
		_playerManager.Update(0, sceneState, _npcManager.GetIsPose(), false);
		//�^�C�g���̍X�V
		_titleSceneManager.Update();
		//�T�E���h�̍X�V
		_soundManager.Update(sceneState, 0, false, false, _titleSceneManager.GetIsSelect(),
			_titleSceneManager.GetIsEnter(), false, false);
		//isDrawScore��true�̎��X�R�A�����L���O��`�悷��B
		if (_titleSceneManager.GetIsDrawScore())
		{
			//�X�R�A�����L���O��`��
			_scoreRanking.Draw();
		}
		//����ʂ�`��
		ScreenFlip();
		//FPS�Œ�p�Ƀt���[���������܂őҋ@
		_fpsControll.WaitFPS();
		//����{�^���������ꂽ�Ƃ�
		if (_titleSceneManager.GetIsNext())
		{
			//while���甲����
			break;
		}
	}
}
/// <summary>
/// �v���C�V�[��
/// </summary>
void SceneManager::Play(PlaySceneManager& _playSceneManager, FPSControll& _fpsControll,
	CameraManager& _cameraManager,PlayerManager& _playerManager,NPCManager& _npcManager, 
	ScoreManager& _scoreManager, MapManager& _mapManager, SoundManager& _soundManager)
{
	//�V�[���X�e�[�g���v���C�ҋ@��ԂɕύX
	sceneState = (int)SceneState::WaitPlayScene;
	//�J�����̃|�W�V���������U���g�p�ɃZ�b�g
	_cameraManager.Init(sceneState);
	float playerImgAddPos = 0;		//[Player]��Y���W���Z�l
	//�Q�[�����[�v
	while (!CheckHitKey(KEY_INPUT_ESCAPE))
	{
		//FPS�̌v�����J�n
		_fpsControll.Update();
		//��ʂ��N���A
		ClearDrawScreen();
		//�J�������X�V
		_cameraManager.Update();
		//�}�b�v�̍X�V
		_mapManager.Update();
		//NPC�̍X�V
		_npcManager.Update(_playSceneManager.GetSuccessCount(), sceneState,
			_playerManager.GetIsPose(), _playSceneManager.GetIsFinishJudge());
		//�v���C���[�̍X�V
		_playerManager.Update(_playSceneManager.GetSuccessCount(),sceneState,
			_npcManager.GetIsPose(), _playSceneManager.GetIsFinishJudge());
		//Play�V�[���̍X�V
		_playSceneManager.Update(_scoreManager.GetScore(), 
			_npcManager.GetIsPose(),_npcManager.GetState(), 
			_npcManager.GetNowPose(),_playerManager.GetIsPose(),_playerManager.GetState());
		//�Q�[���J�n����
		if (_playSceneManager.GetIsStart())
		{
			//�X�R�A�̍X�V
			_scoreManager.Update(_playSceneManager.GetSuccessCount(),
				_playSceneManager.GetIsSuccess());
			//�V�[���X�e�[�g���v���C��ԂɕύX
			sceneState = (int)SceneManager::SceneState::PlayScene;
		}
		//�T�E���h�̍X�V
		_soundManager.Update(sceneState, _playSceneManager.GetSuccessCount(), 
			_playSceneManager.GetIsSuccess(),_playSceneManager.GetIsMiss(), 
			false, false, _npcManager.GetIsPose(), _playSceneManager.GetIsStartSE());
		//����ʂ�`��
		ScreenFlip();
		//FPS�Œ�p�Ƀt���[���������܂őҋ@
		_fpsControll.WaitFPS();
		//�Q�[���I������
		if (_playSceneManager.GetIsGameEnd())
		{
			//while�𔲂���
			break;
		}
	}
}
/// <summary>
/// ���U���g�V�[��
/// </summary>
void SceneManager::Result(ResultSceneManager& _resultSceneManager, 
	FPSControll& _fpsControll, CameraManager& _cameraManager,PlayerManager& _playerManager,
	ScoreManager& _scoreManager, MapManager& _mapManager, SoundManager& _soundManager)
{
	//�V�[���X�e�[�g�����U���g��ԂɕύX
	sceneState = (int)SceneState::ResultScene;
	//�J�����̃|�W�V���������U���g�p�ɃZ�b�g
	_cameraManager.Init(sceneState);

	while (!CheckHitKey(KEY_INPUT_ESCAPE))
	{
		//FPS�̌v�����J�n
		_fpsControll.Update();
		//��ʂ�������
		ClearDrawScreen();
		//�J�����̍X�V
		_cameraManager.Update();
		//�}�b�v�̕`��
		_mapManager.Update();
		//�v���C���[�̍X�V
		_playerManager.Update(0, sceneState, false, false);
		//���U���g�V�[���̍X�V
		_resultSceneManager.Update(_scoreManager.GetScore());
		//�T�E���h�̍X�V
		_soundManager.Update(sceneState, 0, false, false, _resultSceneManager.GetIsSelect(), 
			_resultSceneManager.GetIsEnter(), false, false);
		//����ʂ�`��
		ScreenFlip();
		//FPS�Œ�p�Ƀt���[���������܂őҋ@
		_fpsControll.WaitFPS();
		//����{�^���������ꂽ�Ƃ�
		if (_resultSceneManager.GetIsNext())
		{
			//while���甲����
			break;
		}
	}
}
/// <summary>
/// GET,POST���ɃQ�[�����i�܂Ȃ��悤�ɂ��郍�[�h�V�[��
/// </summary>
void SceneManager::Load(ScoreRanking& _scoreRanking, 
	FPSControll& _fpsControll,SoundManager& _soundManager)
{
	//�V�[���X�e�[�g�����[�h��ԂɕύX
	sceneState = (int)SceneState::LoadScene;
	//�T�E���h�̍X�V(�S�Ď~�߂�)
	_soundManager.Update(sceneState, 0, false, false, false, false, false, false);

	while (true)
	{
		//FPS�̌v�����J�n
		_fpsControll.Update();
		//�^�X�N���I�������ꍇ
		if (_scoreRanking.GetIsTaskEnd())
		{
			//while���甲����
			break;
		}
		//��ʂ�������
		ClearDrawScreen();
		//NOWLOADING�̃u�����h�l���Z�b�g
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, nowLoadingImgBlendNum);
		//NOWLOADING�̕`��
		DrawGraph(NowLoadingImgX, NowLoadingImgY, nowLoadingImg, TRUE);
		//�u�����h�l���f�t�H���g�ɖ߂�
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, NowLoadingImgBlendMax);
		//����ʂ�`��
		ScreenFlip();
		//���݂̃u�����h�l��0�ȉ��̏ꍇ
		if (nowLoadingImgBlendNum <= 0)
		{
			//�u�����h�l�̉��Z�l��+�ɂ���
			nowBlendAddNum = NowLoadingBlendSpeed;
		}
		//�u�����h�l��255�ȏ�̏ꍇ
		else if (nowLoadingImgBlendNum >= NowLoadingImgBlendMax)
		{
			//�u�����h�l�̉��Z�l��-�ɂ���
			nowBlendAddNum = -NowLoadingBlendSpeed;
		}
		//���݂̃u�����h�l�Ƀu�����h�̉��Z�l������
		nowLoadingImgBlendNum += nowBlendAddNum;
		//FPS�Œ�p�Ƀt���[���������܂őҋ@
		_fpsControll.WaitFPS();
	}
}