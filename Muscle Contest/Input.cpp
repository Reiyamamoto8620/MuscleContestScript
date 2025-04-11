#include "DxLib.h"
#include "Input.h"
/// <summary>
/// コンストラクタ
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
/// デストラクタ
/// </summary>
Input::~Input()
{

}
/// <summary>
/// 初期化
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
/// 更新
/// </summary>
void Input::Update(bool _isInput)
{
	Init();
	GetInputKey(_isInput);
}
/// <summary>
/// 入力を取得
/// </summary>
void Input::GetInputKey(bool _isInput)
{
	if (_isInput)
	{
		//上入力
		if (GetJoypadInputState(DX_INPUT_KEY_PAD1)&PAD_INPUT_UP)
		{
			isUp = true;
		}
		//下入力
		if (GetJoypadInputState(DX_INPUT_KEY_PAD1) & PAD_INPUT_DOWN)
		{
			isDown = true;
		}
		//右入力
		if (GetJoypadInputState(DX_INPUT_KEY_PAD1) & PAD_INPUT_RIGHT)
		{
			isRight = true;
		}
		//左入力
		if (GetJoypadInputState(DX_INPUT_KEY_PAD1) & PAD_INPUT_LEFT)
		{
			isLeft = true;
		}
		//エンターキー入力またはパットボタン1の入力
		if (CheckHitKey(KEY_INPUT_RETURN)|| GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_1)
		{
			isEnter = true;
		}
	}
}