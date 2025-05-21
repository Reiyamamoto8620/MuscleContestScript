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
	//����������؂�
	SetWaitVSyncFlag(0);
	//Dxlib�̏�����
	if (DxLib_Init() == -1)
	{
		return -1;//�G���[���N�����璼���ɏI��
	}

	//��ʏ����ݒ�
	SetDrawScreen(DX_SCREEN_BACK);
	SetGraphMode(DisplaySizeX, DisplaySizeY, ColorBit);
	ChangeWindowMode(TRUE);
	SetMouseDispFlag(FALSE);
	// �y�o�b�t�@��L���ɂ���
	SetUseZBuffer3D(TRUE);

	// �y�o�b�t�@�ւ̏������݂�L���ɂ���
	SetWriteZBuffer3D(TRUE);
	LPCSTR fontPath = "Data/Font/DelaGothicOne-Regular.ttf";
	if (AddFontResourceEx(fontPath, FR_PRIVATE, NULL) > 0)
	{
		//�����Ȃ�
	}
	else {
		// �t�H���g�Ǎ��G���[����
		MessageBox(NULL, "�t�H���g�Ǎ����s", "", MB_OK);
	}

	//�ϐ��錾
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
		//������
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

		//���v���C�̏ꍇ�̓^�C�g���ɓ���Ȃ�
		if (!resultSceneManager->GetIsReplay())
		{
			//�O��̃^�X�N���I���܂őҋ@
			sceneManager->Load(*scoreRanking, *fpsControll,*soundManager);
			//�l�b�g���[�N�ɐڑ����m�F���A�X�R�A��GET
			scoreRanking->Update(Get, scoreManager->GetScore());
			//�^�X�N���I���܂őҋ@
			sceneManager->Load(*scoreRanking, *fpsControll,*soundManager);
			//�^�C�g���V�[��
			sceneManager->Title(*titleSceneManager, *fpsControll, *cameraManager,
				*scoreRanking, *playerManager, *npcManager, *mapManager, *soundManager);

			//�Q�[���I�����I�����ꂽ�ꍇ
			if (titleSceneManager->GetIsEnd())
			{
				break;
			}
		}
		//���U���g�̏�����
		resultSceneManager->Init();
		//�v���C�V�[��
		sceneManager->Play(*playSceneManager, *fpsControll, *cameraManager, *playerManager,
			*npcManager, *scoreManager, *mapManager, *soundManager);
		//�v���C���[�̏�����
		playerManager->Init();
		//�O��̃^�X�N���I���܂őҋ@
		sceneManager->Load(*scoreRanking, *fpsControll,*soundManager);
		//�l�b�g���[�N�̐ڑ����m�F���A�X�R�A��POST
		scoreRanking->Update(Post, scoreManager->GetScore());
		//���U���g�V�[��
		sceneManager->Result(*resultSceneManager, *fpsControll, *cameraManager,
			*playerManager, *scoreManager, *mapManager, *soundManager);
	}

	//DxLib �̌�n��
	DxLib_End();
	return 0;
}