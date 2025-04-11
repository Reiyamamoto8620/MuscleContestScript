#pragma once

//�v���g�^�C�v�錾
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
	//�V�[���X�e�[�g
	enum SceneState
	{
		TitleScene,
		PlayScene,
		ResultScene,
		LoadScene,
		WaitPlayScene
	};
	
	////////////////////////
	//--------�֐�--------//
	////////////////////////
	//�R���X�g���N�^
	SceneManager();
	//�f�X�g���N�^
	~SceneManager();
	//������
	void Init();
	//�^�C�g���V�[��
	void Title(TitleSceneManager& _titleSceneManager, FPSControll& _fpsControll,CameraManager& _cameraManager,
		ScoreRanking& _scoreRanking,PlayerManager& _playerManager,
		NPCManager& _npcManager,MapManager& _mapManager,SoundManager& _soundManager);
	//�v���C�V�[��
	void Play(PlaySceneManager& _playSceneManager, FPSControll& _fpsControll, CameraManager& _cameraManager,
		PlayerManager& _playerManager,NPCManager& _npcManager, ScoreManager& _scoreManager, 
		MapManager& _mapManager, SoundManager& _soundManager);
	//���U���g�V�[��
	void Result(ResultSceneManager& _resultSceneManager, FPSControll& _fpsControll, CameraManager& _cameraManager,
		 PlayerManager& _playerManager,ScoreManager& _scoreManager, 
		MapManager& _mapManager, SoundManager& _soundManager);
	//GET,POST���ɃQ�[�����i�܂Ȃ��悤�ɂ��郍�[�h�V�[��
	void Load(ScoreRanking& _scoreRanking,
		FPSControll&_fpsControll, SoundManager& _soundManager);
private:
	////////////////////////
	//--------�ϐ�--------//
	////////////////////////
	int nowLoadingImgBlendNum;		//���݂�NOWLOADINF�̃u�����h�l
	int nowBlendAddNum;				//���݂̃u�����h���Z�l
	int nowLoadingImg;				//NOWLOADING�̉摜
	int sceneState;					//�V�[���̏��

	////////////////////////
	//--------�萔--------//
	////////////////////////
	static constexpr int AddScore = 100;				//�X�R�A�̉��Z�l
	static constexpr int ScoreBonus = 10;				//�X�R�A�̃R���{�{�[�i�X
	static constexpr int NowLoadingImgX = 423;			//NOWLOADING��X���W
	static constexpr int NowLoadingImgY = 440;			//NOWLOADING��Y���W
	static constexpr int NowLoadingImgBlendMax = 255;	//NOWLOADING�̃u�����h�l�̍ő�
	static constexpr int NowLoadingBlendSpeed = 5;		//NOWLOADING�̃u�����h���Z�l�̃X�s�[�h
	static constexpr float JudgeImgSize = 2.5f;			//�|�[�W���O����̕`��T�C�Y
	static constexpr float JudgeImgCenter = 0.5f;		//�|�[�W���O����̉摜�̒��S
	const VECTOR JudgeImgPos = VGet(2, 5.625, 25);		//�|�[�W���O����̕`����W

};

