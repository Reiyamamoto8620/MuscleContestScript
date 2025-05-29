#include "DxLib.h"
#include "Input.h"
/// <summary>
/// �R���X�g���N�^
/// </summary>
Input::Input() :
	isUp(false),
	isDown(false),
	isLeft(false),
	isRight(false),
	isEnter(false)
{

}
/// <summary>
/// �f�X�g���N�^
/// </summary>
Input::~Input()
{

}
/// <summary>
/// ������
/// </summary>
void Input::Init()
{
	isUp = false;
	isDown = false;
	isLeft = false;
	isRight = false;
	isEnter = false;
}
/// <summary>
/// �X�V
/// </summary>
void Input::Update(bool _isInput)
{
	Init();
	GetInputKey(_isInput);
}
/// <summary>
/// ���͂��擾
/// </summary>
void Input::GetInputKey(bool _isInput)
{
	if (_isInput)
	{
		//�����
		if (GetJoypadInputState(DX_INPUT_KEY_PAD1)&PAD_INPUT_UP || CheckHitKey(KEY_INPUT_W))
		{
			isUp = true;
		}
		//������
		if (GetJoypadInputState(DX_INPUT_KEY_PAD1) & PAD_INPUT_DOWN || CheckHitKey(KEY_INPUT_S))
		{
			isDown = true;
		}
		//�E����
		if (GetJoypadInputState(DX_INPUT_KEY_PAD1) & PAD_INPUT_RIGHT || CheckHitKey(KEY_INPUT_D))
		{
			isRight = true;
		}
		//������
		if (GetJoypadInputState(DX_INPUT_KEY_PAD1) & PAD_INPUT_LEFT || CheckHitKey(KEY_INPUT_A))
		{
			isLeft = true;
		}
		//�G���^�[�L�[���͂܂��̓p�b�g�{�^��1�̓���
		if (CheckHitKey(KEY_INPUT_RETURN)|| GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_1)
		{
			isEnter = true;
		}
	}
}