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
		if (GetJoypadInputState(DX_INPUT_KEY_PAD1)&PAD_INPUT_UP || CheckHitKey(KEY_INPUT_W))
		{
			isUp = true;
		}
		//下入力
		if (GetJoypadInputState(DX_INPUT_KEY_PAD1) & PAD_INPUT_DOWN || CheckHitKey(KEY_INPUT_S))
		{
			isDown = true;
		}
		//右入力
		if (GetJoypadInputState(DX_INPUT_KEY_PAD1) & PAD_INPUT_RIGHT || CheckHitKey(KEY_INPUT_D))
		{
			isRight = true;
		}
		//左入力
		if (GetJoypadInputState(DX_INPUT_KEY_PAD1) & PAD_INPUT_LEFT || CheckHitKey(KEY_INPUT_A))
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