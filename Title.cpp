#include "Title.h"
#include"PadInput.h"
#include"DxLib.h"

#define FADE_TIME 300


//-----------------------------------
// コンストラクタ
//-----------------------------------
Title::Title()
{
	input_margin = 0;

	select_menu = static_cast<int>(MENU::PLAY);

	fade_counter = 0;

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
	const int max_input_margin = 15;

	// スティックの感度
	const int stick_sensitivity = 20000;

	if (input_margin < max_input_margin)
	{
		input_margin++;
	}
	else {

		// スティックのY座標を取得
		int stick_y = PadInput::GetLStick().y;

		if (stick_y > stick_sensitivity) {

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


	if (PadInput::GetNowKey(XINPUT_BUTTON_A) && (PadInput::OnButton(XINPUT_BUTTON_A) == true))
	{
		input_margin = 0;
		MENU current_selection = static_cast<MENU>(select_menu);

		switch (current_selection)
		{
		case Title::MENU::PLAY:
			return this;
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
	SetDrawBright(bright, bright, bright);

	DrawFormatString(300, 100, 0xFFFFFF, "イケイケダンジョン君");

	for (int i = 0; i < static_cast<int>(MENU::MENU_SIZE); i++)
	{
		// 文字列の最小Y座標
		const int base_y = 400;

		// 文字列のY座標間隔
		const int margin_y = 100;

		// 文字色
		int color = 0xFFFFFF;
		// 文字外枠色
		int border_color = 0x000000;

		// 透明度
		int transparency = 180;

		// カーソルが合っている場合、文字色と文字外枠色を反転させる
		if (select_menu == i) {
			color = ~color;
			border_color = ~border_color;
			transparency = 255;
		}

	}


}