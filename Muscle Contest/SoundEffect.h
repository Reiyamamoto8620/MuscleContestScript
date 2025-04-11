#pragma once
class SoundEffect
{
public:
	////////////////////////
	//--------�֐�--------//
	////////////////////////
	//�R���X�g���N�^
	SoundEffect();
	//�f�X�g���N�^
	~SoundEffect();
	//������
	void Init();
	//�X�V
	void Update(bool _isSuccess, bool _isMiss, bool _isSelect, bool _isEnter, bool _isNPCPose, bool _isStart);
private:
	////////////////////////
	//--------�֐�--------//
	////////////////////////
	//���莞SE���Đ�
	void PlayEnterSE();
	//�|�[�W���O���sSE���Đ�
	void PlayMissSE();
	//�|�[�W���O����SE���Đ�
	void PlaySuccessSE();
	//�I����SE���Đ�
	void PlaySelectSE();
	//�Q�[���X�^�[�g��SE���Đ�
	void PlayStartSE();
	//NPC���|�[�Y��������SE���Đ�
	void PlayNPCPoseSE();
	//�v���C���[���|�[�Y�����Ƃ��̐���SE���Đ�
	void PlayPlayerSuccessPoseSE();
	//�v���C���[���|�[�Y�����Ƃ��̎��sSE���Đ�
	void PlayPlayerMissPoseSE();
	//�O�t���[���̔���Ƃ��āA���t���[���̔����ۑ�
	void SetLastIsSE(bool _isSuccess,bool _isMiss,bool _isSelect, 
		bool _isEnter,bool _isNPCPose,bool _isStart);

	////////////////////////
	//--------�ϐ�--------//
	////////////////////////
	int enterSE;				//���莞SE
	int missSE;					//�|�[�W���O���sSE
	int successSE;				//�|�[�W���O����SE
	int selectSE;				//�I����SE
	int startSE;				//�Q�[���J�n��SE
	int npcPoseSE;				//NPC���|�[�Y�����Ƃ���SE
	int playerSuccessPoseSE;	//�v���C���[���|�[�Y�����Ƃ��̐���SE
	int playerMissPoseSE;		//�v���C���[���|�[�Y�����Ƃ��̎��sSE

	bool lastFrameIsEnterSE;			//�O�t���[����IsEnter�̔���
	bool lastFrameIsMissSE;				//�O�t���[����IsMiss�̔���
	bool lastFrameIsSuccessSE;			//�O�t���[����IsSuccess�̔���
	bool lastFrameIsSelectSE;			//�O�t���[����IsSelect�̔���
	bool lastFrameIsStartSE;			//�O�t���[����IsStart�̔���
	bool lastFrameIsNPCPoseSE;			//�O�t���[����IsNPCPose�̔���
};