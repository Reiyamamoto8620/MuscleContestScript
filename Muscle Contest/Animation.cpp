#include "DxLib.h"
#include "CharacterState.h"
#include "Animation.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
Animation::Animation() :
	animationTime(0),
	blendValue(0),
	isEndAnimation(false)
{

	for (int i = 0; i < AnimationMax; i++)
	{
		int animModel;
		switch ((CharacterState::State)i)
		{
			//Idle�A�j���[�V���������[�h
		case CharacterState::State::Idle:
			animModel = MV1LoadModel("Data/Animation/Idle.mv1");
			break;
			//����͂̃|�[�Y�����[�h
		case CharacterState::State::UpPose:
			animModel = MV1LoadModel("Data/Animation/UpPose.mv1");
			break;
			//�����͂̃|�[�Y�����[�h
		case CharacterState::State::DownPose:
			animModel = MV1LoadModel("Data/Animation/DownPose.mv1");
			break;
			//�E���͂̃|�[�Y�����[�h
		case CharacterState::State::RightPose:
			animModel = MV1LoadModel("Data/Animation/RightPose.mv1");
			break;
			//�����͂̃|�[�Y�����[�h
		case CharacterState::State::LeftPose:
			animModel = MV1LoadModel("Data/Animation/LeftPose.mv1");
			break;
			//���U���g�̃_���X�����[�h
		case CharacterState::State::FinishDance:
			animModel = MV1LoadModel("Data/Animation/FinishDance.mv1");
			break;
		default:
			break;
		}
		//vector�ɃA�j���[�V�������f�����i�[
		animation.push_back(animModel);
	}
}
/// <summary>
/// �f�X�g���N�^
/// </summary>
Animation::~Animation()
{
	for (int i = 0; i < animation.size(); i++)
	{
		MV1DeleteModel(animation[i]);
	}
	animation.clear();
	index.clear();
}
/// <summary>
/// ������
/// </summary>
int Animation::Init(int _model)
{
	//�A�^�b�`���Ă���A�j���[�V���������ׂč폜
	for (int i = 0; i < index.size(); i++)
	{
		MV1DetachAnim(_model, index[i]);
	}
	//�A�j���[�V�����̃A�^�b�`�ԍ���S�č폜
	index.clear();
	//Idle�A�j���[�V�������Z�b�g
	SetIdle(_model);
	return _model;
}
/// <summary>
/// �X�V
/// </summary>
int Animation::Update(int _model, int _state, int _lastTimeState ,int _successCount)
{
	//�A�j���[�V�����̍Đ����I�����Ă���A�܂��́A
	//�O�t���[���̃X�e�[�g��Idle�ō��̃X�e�[�g��Idle�ȊO�̎����������s
	if (isEndAnimation 
		|| _lastTimeState == (int)CharacterState::State::Idle 
		&&_state != (int)CharacterState::State::Idle)
	{
		//�A�j���[�V�������Z�b�g
		_model = SetAnimation(_state, _model);
	}
	//�A�j���[�V�������Đ�
	_model = PlayAnimation(_model, _successCount);

	return _model;
}
/// <summary>
/// �A�j���[�V�������A�^�b�`
/// </summary>
int Animation::SetAnimation(int _state, int _model)
{
	//�A�j���[�V�������w�肳�ꂽ�A�j���[�V�����ɐݒ�
	index.push_back(MV1AttachAnim(_model, 0, animation[_state], FALSE));
	//�A�j���[�V�����̍Đ����Ԃ����Z�b�g
	animationTime = 0;

	isEndAnimation = false;

	return _model;
}
/// <summary>
/// �A�j���[�V�������Đ�
/// </summary>
int Animation::PlayAnimation(int _model, int _successCount)
{
	float addAnimSpeed = (float)_successCount / (float)ChangeSuccessCountToAnimationSpeed;
	if (addAnimSpeed > AddAnimationSpeedMax)
	{
		addAnimSpeed = AddAnimationSpeedMax;
	}
	//�A�j���[�V�����̎��Ԃ�1F�i�߂�
	//Success�������Ȃ�΂Ȃ�قǑ��x���グ��
	animationTime += AnimationSpeed + addAnimSpeed;

	//�A�j���[�V�������Đ�����I��������ɍĐ����Ԃ�0�ɂ���
	if (animationTime >= MV1GetAttachAnimTotalTime(_model, index[0]))
	{
		animationTime = 0;
		isEndAnimation = true;
	}
	//�A�^�b�`����Ă���A�j���[�V������2�ȏ�ɂȂ�����
	if (index.size() >= AttachAnimationBlendValue)
	{
		_model = BlendAnimation(_model);
	}
	//���f���ɃA�j���[�V�����̍Đ����Ԃ�K�p
	MV1SetAttachAnimTime(_model, index[0], animationTime);
	return _model;
}

/// <summary>
/// �A�j���[�V�����̃u�����h
/// </summary>
int Animation::BlendAnimation(int _model)
{
	//���݂̃A�j���[�V�����̃u�����h�l��ݒ�(����������)
	MV1SetAttachAnimBlendRate(_model, index[BlendBeforAnimationIndex], BlendValueMax - blendValue);
	//���̃A�j���[�V�����̃u�����h�l��ݒ�(������������)
	MV1SetAttachAnimBlendRate(_model, index[BlendAfterAnimationIndex], blendValue);
	//�u�����h�l�̑���
	blendValue += BlendSpeed;
	//�u�����h�l��1.0f�ȏ�ɂȂ����ꍇ�A�܂��́Aindex�̃T�C�Y���ő�l�ȏ�ɂȂ����ꍇ
	if (blendValue >= BlendValueMax || 
		index.size() >= AnimationIndexSizeMax)
	{
		//���݂̃A�j���[�V�������f�^�b�`
		MV1DetachAnim(_model, index[BlendBeforAnimationIndex]);
		//���݂̃A�j���[�V�����̃A�^�b�`�ԍ���j��
		index.erase(index.begin());
		//�u�����h�l�����Z�b�g
		blendValue = 0;
	}
	return _model;
}

/// <summary>
/// Idle�A�j���[�V�����ɃZ�b�g����
/// </summary>
int Animation::SetIdle(int _model)
{
	//�A�j���[�V������Idle�ɐݒ�
	index.push_back(MV1AttachAnim(_model, 0,
		animation[(int)CharacterState::State::Idle], FALSE));
	//�A�j���[�V�����̍Đ����Ԃ����Z�b�g
	animationTime = 0;

	return _model;
}