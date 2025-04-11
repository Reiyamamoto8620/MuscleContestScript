#pragma once


class Camera
{
public:
	////////////////////////
	//--------�֐�--------//
	////////////////////////
	//�R���X�g���N�^
	Camera();
	//�f�X�g���N�^
	~Camera();
	//�X�V
	void Update();
	//������
	void Init(int _sceneState);
	//�J�����̍��W���^�C�g���p�̍��W�ɃZ�b�g
	void SetTitleCameraPosition();
	//�J�����̍��W���v���C�V�[���p�̍��W�ɃZ�b�g
	void SetPlayCameraPosition();
	//�J�����̍��W�����U���g�p�̍��W�ɃZ�b�g
	void SetResultCameraPosition();
	//�J�����̍��W���G���[�p�̍��W�ɃZ�b�g
	void SetErrorCameraPosition();
private:
	////////////////////////
	//--------�ϐ�--------//
	////////////////////////
	VECTOR position;			//�J�����̍��W

	////////////////////////
	//--------�萔--------//
	////////////////////////
	const VECTOR PlayCameraPosition = VGet(0,3, 19.75);				//�J�����̃v���C�V�[���̍��W
	const VECTOR ResultCameraPosition = VGet(0, 3, 19.75);			//�J�����̃��U���g�̍��W
	const VECTOR TitleCameraPosition = VGet(0, 4.25f, 19.25f);		//�J�����̃^�C�g���̍��W
	const VECTOR ErrorCameraPosition = VGet(0, 0, 0);				//�J�����̃G���[���̍��W
	static constexpr float NearPosition = 1;						//�J������Near
	static constexpr float FarPosition = 100.0f;					//�J������Far
};

