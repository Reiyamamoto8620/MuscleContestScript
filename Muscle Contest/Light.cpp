#include "DxLib.h"
#include "Light.h"
/// <summary>
/// �R���X�g���N�^
/// </summary>
Light::Light()
{
	
}
/// <summary>
/// �f�X�g���N�^
/// </summary>
Light::~Light()
{

}
/// <summary>
/// ������
/// </summary>
void Light::Init()
{
	//���C�g�̊p�x���Z�b�g
	SetLightDirection(LightDirection);
}