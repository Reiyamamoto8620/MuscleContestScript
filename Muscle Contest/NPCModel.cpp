#include "DxLib.h"
#include "NPCModel.h"

/// <summary>
/// コンストラクタ
/// </summary>
NPCModel::NPCModel() :
	model(MV1LoadModel("Data/Model/NPCModel.mv1"))
{
	//モデルのスケールを設定
	MV1SetScale(model, ModelScale);
}

/// <summary>
/// デストラクタ
/// </summary>
NPCModel::~NPCModel()
{
	//モデルを削除
	MV1DeleteModel(model);
}

/// <summary>
/// 初期化
/// </summary>
void NPCModel::Init()
{
	//モデルの座標を設定
	MV1SetPosition(model, Position);
}

/// <summary>
/// 更新
/// </summary>
void NPCModel::Update()
{
	Draw();
}

/// <summary>
/// 描画
/// </summary>
void NPCModel::Draw()
{
	MV1DrawModel(model);
}