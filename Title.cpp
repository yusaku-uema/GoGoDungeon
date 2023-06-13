#include "Title.h"
#include"PadInput.h"
#include"GameMain.h"
#include"DxLib.h"

#define FADE_TIME 300

#define STATE_Y 300

#define EXIT_Y 400


//-----------------------------------
// コンストラクタ
//-----------------------------------
Title::Title()
{
	input_margin = 0;

	select_menu = static_cast<int>(MENU::PLAY);

	fade_counter = 0;

	cursor_y = 0;

}

//-----------------------------------
// デストラクタ
//-----------------------------------
Title::~Title()
{

}

//-----------------------------------
// 更新
//-----------------------------------
AbstractScene* Title::Update()
{
	//フェードイン
	if (fade_counter < FADE_TIME)
	{
		//画面をだんだん明るくする。
		fade_counter++;
	}

	// 操作間隔時間
	const int max_input_margin = 10;

	// スティックの感度
	const int stick_sensitivity = 20000;

	//操作時間、間隔
	if (input_margin < max_input_margin)
	{
		input_margin++;
	}
	else //操作
	{

		// スティックのY座標を取得
		//int stick_y = PadInput::GetLStick().y;
		 stick_y = PadInput::GetLStick().y;

		 //スティックの受付
		 if (stick_y > stick_sensitivity || stick_y < stick_sensitivity * -1)
		{

			// スティックが上に移動した場合
			if (stick_y > 0) {
				// メニュー選択肢を一つ前に移動
				select_menu = (select_menu - 1 + static_cast<int>(MENU::MENU_SIZE)) % static_cast<int>(MENU::MENU_SIZE);
			}
			// スティックが下に移動した場合
			else if (stick_y < 0) {
				// メニュー選択肢を一つ次に移動
				select_menu = (select_menu + 1) % static_cast<int>(MENU::MENU_SIZE);
			}

			input_margin = 0;

		}

	}

	//カーソルの位置
	switch (select_menu)
	{
	case 0:
		cursor_y = STATE_Y; //スタートのカーソル位置
		break;
	case 1:
		cursor_y = EXIT_Y; //EXITのカーソル位置
		break;
	default:
		break;
	}


	if (PadInput::GetNowKey(XINPUT_BUTTON_A) && (PadInput::OnButton(XINPUT_BUTTON_A) == true))
	{
		input_margin = 0;
		MENU current_selection = static_cast<MENU>(select_menu);

		switch (current_selection)
		{
		case Title::MENU::PLAY:
			return new GameMain();
			break;

		case Title::MENU::EXIT:
			return this;
			break;

		default:
			printfDx("未実装な機能です。\n");
			break;
		}

	}

	return this;
}

//-----------------------------------
// 描画
//-----------------------------------
void Title::Draw()const
{
	int bright = static_cast<int>((static_cast<float>(fade_counter) / FADE_TIME * 255));

	SetDrawBright(bright, bright, bright); //画面の明るさ

	SetFontSize(40);

	DrawFormatString(400, 100, 0xFFFFFF, "タイトル考え中");

	DrawFormatString(550, 300, 0xFFFFFF, "START");

	DrawFormatString(550, 400, 0xFFFFFF, "EXIT");

	DrawFormatString(100, 100, 0xFFFFFF, "%d", stick_y);

	
	//カーソル
	DrawString(500, cursor_y, "■", GetColor(255, 255, 255));

}