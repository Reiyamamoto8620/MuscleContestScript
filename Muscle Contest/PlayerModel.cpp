#include "DxLib.h"
#include "PlayerModel.h"

/// <summary>
/// コンストラクタ
/// </summary>
PlayerModel::PlayerModel() :
	model(MV1LoadModel("Data/Model/PlayerModel.mv1"))
{
	//モデルのスケールを設定
	MV1SetScale(model, ModelScale);
}

/// <summary>
/// デストラクタ
/// </summary>
PlayerModel::~PlayerModel()
{
	//モデルを削除
	MV1DeleteModel(model);
}

/// <summary>
/// 初期化
/// </summary>
void PlayerModel::Init()
{
	//モデルの座標を設定
	MV1SetPosition(model, Position);
}

/// <summary>
/// 更新
/// </summary>
void PlayerModel::Update()
{
	Draw();
}

/// <summary>
/// 描画
/// </summary>
void PlayerModel::Draw()
{
	MV1DrawModel(model);
}