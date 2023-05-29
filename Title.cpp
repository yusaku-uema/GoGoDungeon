#include "Title.h"
#include"PadInput.h"
#include"DxLib.h"

#define FADE_TIME 300


//-----------------------------------
// �R���X�g���N�^
//-----------------------------------
Title::Title()
{
	input_margin = 0;

	select_menu = static_cast<int>(MENU::PLAY);

	fade_counter = 0;

}

//-----------------------------------
// �f�X�g���N�^
//-----------------------------------
Title::~Title()
{
	
}

//-----------------------------------
// �X�V
//-----------------------------------
AbstractScene* Title::Update()
{
	//�t�F�[�h�C��
	if (fade_counter < FADE_TIME)
	{
		//��ʂ����񂾂񖾂邭����B
		fade_counter++;
	}

	// ����Ԋu����
	const int max_input_margin = 15;

	// �X�e�B�b�N�̊��x
	const int stick_sensitivity = 20000;

	if (input_margin < max_input_margin)
	{
		input_margin++;
	}
	else {

		// �X�e�B�b�N��Y���W���擾
		int stick_y = PadInput::GetLStick().y;

		if (stick_y > stick_sensitivity) {

			// �X�e�B�b�N����Ɉړ������ꍇ
			if (stick_y > 0) {
				// ���j���[�I��������O�Ɉړ�
				select_menu = (select_menu - 1 + static_cast<int>(MENU::MENU_SIZE)) % static_cast<int>(MENU::MENU_SIZE);
			}
			// �X�e�B�b�N�����Ɉړ������ꍇ
			else if (stick_y < 0) {
				// ���j���[�I����������Ɉړ�
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
			printfDx("�������ȋ@�\�ł��B\n");
			break;
		}

	}

	return this;
}

//-----------------------------------
// �`��
//-----------------------------------
void Title::Draw()const
{
	int bright = static_cast<int>((static_cast<float>(fade_counter) / FADE_TIME * 255));
	SetDrawBright(bright, bright, bright);

	DrawFormatString(300, 100, 0xFFFFFF, "�C�P�C�P�_���W�����N");

	for (int i = 0; i < static_cast<int>(MENU::MENU_SIZE); i++)
	{
		// ������̍ŏ�Y���W
		const int base_y = 400;

		// �������Y���W�Ԋu
		const int margin_y = 100;

		// �����F
		int color = 0xFFFFFF;
		// �����O�g�F
		int border_color = 0x000000;

		// �����x
		int transparency = 180;

		// �J�[�\���������Ă���ꍇ�A�����F�ƕ����O�g�F�𔽓]������
		if (select_menu == i) {
			color = ~color;
			border_color = ~border_color;
			transparency = 255;
		}

	}


}