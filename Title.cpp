#include "Title.h"
#include"PadInput.h"
#include"GameMain.h"
#include"DxLib.h"

#define FADE_TIME 300

#define STATE_Y 300

#define EXIT_Y 400


//-----------------------------------
// �R���X�g���N�^
//-----------------------------------
Title::Title()
{
	input_margin = 0;

	select_menu = static_cast<int>(MENU::PLAY);

	fade_counter = 0;

	cursor_y = 0;

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
	const int max_input_margin = 10;

	// �X�e�B�b�N�̊��x
	const int stick_sensitivity = 20000;

	//���쎞�ԁA�Ԋu
	if (input_margin < max_input_margin)
	{
		input_margin++;
	}
	else //����
	{

		// �X�e�B�b�N��Y���W���擾
		//int stick_y = PadInput::GetLStick().y;
		 stick_y = PadInput::GetLStick().y;

		 //�X�e�B�b�N�̎�t
		 if (stick_y > stick_sensitivity || stick_y < stick_sensitivity * -1)
		{

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

	//�J�[�\���̈ʒu
	switch (select_menu)
	{
	case 0:
		cursor_y = STATE_Y; //�X�^�[�g�̃J�[�\���ʒu
		break;
	case 1:
		cursor_y = EXIT_Y; //EXIT�̃J�[�\���ʒu
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

	SetDrawBright(bright, bright, bright); //��ʂ̖��邳

	SetFontSize(40);

	DrawFormatString(400, 100, 0xFFFFFF, "�^�C�g���l����");

	DrawFormatString(550, 300, 0xFFFFFF, "START");

	DrawFormatString(550, 400, 0xFFFFFF, "EXIT");

	DrawFormatString(100, 100, 0xFFFFFF, "%d", stick_y);

	
	//�J�[�\��
	DrawString(500, cursor_y, "��", GetColor(255, 255, 255));

}