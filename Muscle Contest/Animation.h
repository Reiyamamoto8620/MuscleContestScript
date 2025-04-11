#pragma once
#include "iostream"
#include "vector"

class Animation
{
public:
	////////////////////////
	//--------�֐�--------//
	////////////////////////
	//�R���X�g���N�^
	Animation();
	//�f�X�g���N�^
	~Animation();
	//������
	int Init(int _model);
	//�X�V
	int Update(int _model, int _state,  int _lastTimeState,int _successCount);

	/// <summary>
	/// �A�j���[�V�����̏I��������擾
	/// </summary>
	bool GetIsEndAnimation()
	{
		return isEndAnimation;
	}
private:
	////////////////////////
	//--------�֐�--------//
	////////////////////////
	//�A�j���[�V�����̃Z�b�g
	int SetAnimation(int _state, int _model);
	//�A�j���[�V�����̍Đ�
	int PlayAnimation(int _model,int _successCount);
	//�A�j���[�V�����̃u�����h
	int BlendAnimation(int _model);
	//Idle�A�j���[�V�����̃Z�b�g
	int SetIdle(int _model);

	////////////////////////
	//--------�ϐ�--------//
	////////////////////////
	std::vector<int> animation;		//�A�j���[�V�����̊i�[
	std::vector<int> index;			//�A�j���[�V�����̃C���f�b�N�X
	float animationTime;			//�A�j���[�V�����̌��݂̍Đ�����
	float blendValue;				//�A�j���[�V�����̃u�����h�l
	bool isEndAnimation;			//�A�j���[�V�������I������

	////////////////////////
	//--------�萔--------//
	////////////////////////
	static constexpr float 
		BlendValueMax = 1.0f;						//�u�����h�l�̍ő�
	static constexpr int 
		AttachAnimationBlendValue = 2;				//�A�^�b�`���ꂽ�A�j���[�V�������u�����h����Œ�l
	static constexpr float 
		BlendSpeed = 0.2f;							//�A�j���[�V�����u�����h�̑��x
	static constexpr int 
		AnimationSpeed = 1;							//�A�j���[�V�����̍Đ����x
	static constexpr int 
		ChangeSuccessCountToAnimationSpeed = 30;	//�R���{�����A�j���[�V�����̑��x�ɓK�����邽�߂̌v�Z�p
	static constexpr int 
		AddAnimationSpeedMax = 1;					//�A�j���[�V�����̍Đ����x�̉��Z�l
	static constexpr int 
		AnimationMax = 6;							//�A�j���[�V�����̍ő吔
	static constexpr int 
		AnimationIndexSizeMax = 3;					//�A�^�b�`�ł���A�j���[�V�����̍ő吔
	static constexpr int 
		BlendBeforAnimationIndex = 0;				//�u�����h����O�̃A�j���[�V�����̃C���f�b�N�X
	static constexpr int 
		BlendAfterAnimationIndex = 1;				//�u�����h�����̃A�j���[�V�����̃C���f�b�N�X
};

