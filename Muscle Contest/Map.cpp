#include "DxLib.h"
#include "Map.h"
/// <summary>
/// コンストラクタ
/// </summary>
Map::Map() : 
	gymModel(MV1LoadModel("Data/Map/Gym.mv1"))
{
	//モデルの大きさを設定
	MV1SetScale(gymModel, GymScale);
}
/// <summary>
/// デストラクタ
/// </summary>
Map::~Map()
{
	MV1DeleteModel(gymModel);
}
/// <summary>
/// 初期化
/// </summary>
void Map::Init()
{
	//モデルに座標をセット
	MV1SetPosition(gymModel, GymPosition);
}
/// <summary>
/// 描画
/// </summary>
void Map::Draw()
{
	//モデルを描画
	MV1DrawModel(gymModel);
}