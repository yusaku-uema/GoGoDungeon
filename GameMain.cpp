#include "GameMain.h"
#include"DxLib.h"


//-----------------------------------
// �X�V
//-----------------------------------
AbstractScene* GameMain::Update()
{



	return this; //������Ԃ��@���[�v
}

//-----------------------------------
// �`�悾��
//-----------------------------------
void GameMain::Draw() const
{
	DrawFormatString(300,300,0xFFFFFF,"�Q�[�����C���e�X�g");
}
