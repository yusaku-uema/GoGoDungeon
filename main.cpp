#include "DxLib.h"
#include"SceneManager.h"
#include"PadInput.h"
#include"Title.h"

#define FRAMERATE 60.0 //フレームレート

#define SCREEN_WIDTH 1280 //画面サイズ（横）

#define SCREEN_HEIGHT 720 //画面サイズ（縦）

/***********************************************
 * プログラムの開始
 ***********************************************/
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{

	double dNextTime = GetNowCount();

	SetMainWindowText("考え中");

	ChangeWindowMode(TRUE);		// ウィンドウモードで起動

	SetAlwaysRunFlag(true);		//ウィンドウが非アクティブでなくても処理を継続するか設定

	SetGraphMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32);	//画面サイズの設定

	if (DxLib_Init() == -1) return -1;	// DXライブラリの初期化処理

	SetDrawScreen(DX_SCREEN_BACK);	// 描画先画面を裏にする

	SceneManager* sceneMng; //シーンマネージャー


	sceneMng = new SceneManager((AbstractScene*)new Title()); //シーンマネージャーにタイトルをセット

	
	// ゲームループ
	while ((ProcessMessage() == 0) && (sceneMng->Update() != nullptr))
	{

		ClearDrawScreen();		// 画面の初期化
		PadInput::UpdateKey();
		sceneMng->Draw();

		ScreenFlip();			// 裏画面の内容を表画面に反映

		//フレームレートの設定
		dNextTime += 1.0 / 60.0 * 1000.0;

		if (dNextTime > GetNowCount())
		{
			WaitTimer(static_cast<int>(dNextTime) - GetNowCount());
			//static_cast<int>　int型に変換（キャスト）
		}
		else { dNextTime = GetNowCount(); }		//補正
	}


	return 0;
}