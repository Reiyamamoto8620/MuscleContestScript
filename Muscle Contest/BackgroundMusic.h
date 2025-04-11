#pragma once
class BackgroundMusic
{
public:
	////////////////////////
	//--------�֐�--------//
	////////////////////////
	//�R���X�g���N�^
	BackgroundMusic();
	//�f�X�g���N�^
	~BackgroundMusic();
	//������
	void Init();
	//�X�V
	void Update(int _sceneState,int _successCount);
private:
	////////////////////////
	//--------�֐�--------//
	////////////////////////
	//�v���CBGM�̎��g�����R���{���ɍ��킹�ĕω�������
	void SetFrequencyPlayBGM(int _successCount);
	//�^�C�g��BGM���Đ�
	void PlayTitleBGM();
	//�^�C�g��BGM���~
	void StopTitleBGM();
	//�v���CBGM���Đ�
	void PlayPlayBGM();
	//�v���CBGM���~
	void StopPlayBGM();
	//���U���gBGM���Đ�
	void PlayResultBGM();
	//���U���gBGM���~
	void StopResultBGM();

	////////////////////////
	//--------�ϐ�--------//
	////////////////////////
	int titleBGM;				//�^�C�g��BGM
	int playBGM;				//�v���CBGM
	int resultBGM;				//���U���gBGM
	bool isPlayTitleBGM;		//�^�C�g��BGM�̍Đ�����
	bool isPlayPlayBGM;			//�v���CBGM�̍Đ�����
	bool isPlayResultBGM;		//���U���gBGM�̍Đ�����

	////////////////////////
	//--------�萔--------//
	////////////////////////
	static constexpr int PlayBGMVolume = 200;				//�v���CBGM�̉���
	static constexpr int AddPlayBGMFrequencyMax = 30;		//PlayBGM�ɒǉ�������g���l�̍ő�
	static constexpr int AddPlayBGMFrequencyNum = 500;		//1�R���{������ɒǉ��������g���l
	static constexpr int PlayBGMFrequencyMin = 35000;		//PlayBGM�̎��g���̍ŏ�
};