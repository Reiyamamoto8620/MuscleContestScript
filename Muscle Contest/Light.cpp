#include "DxLib.h"
#include "Light.h"
/// <summary>
/// コンストラクタ
/// </summary>
Light::Light()
{
	
}
/// <summary>
/// デストラクタ
/// </summary>
Light::~Light()
{

}
/// <summary>
/// 初期化
/// </summary>
void Light::Init()
{
	//ライトの角度をセット
	SetLightDirection(LightDirection);
}