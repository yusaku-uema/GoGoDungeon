#include "GameMain.h"
#include"DxLib.h"


//-----------------------------------
// 更新
//-----------------------------------
AbstractScene* GameMain::Update()
{



	return this; //自分を返す　ループ
}

//-----------------------------------
// 描画だけ
//-----------------------------------
void GameMain::Draw() const
{
	DrawFormatString(300,300,0xFFFFFF,"ゲームメインテスト");
}
