#include "DxLib.h"
#include"SceneManager.h"
#include"PadInput.h"
#include"Title.h"

#define FRAMERATE 60.0 //�t���[�����[�g

#define SCREEN_WIDTH 1280 //��ʃT�C�Y�i���j

#define SCREEN_HEIGHT 720 //��ʃT�C�Y�i�c�j

/***********************************************
 * �v���O�����̊J�n
 ***********************************************/
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{

	double dNextTime = GetNowCount();

	SetMainWindowText("�C�P�C�P!! �_���W�����N");

	ChangeWindowMode(TRUE);		// �E�B���h�E���[�h�ŋN��

	SetAlwaysRunFlag(true);		//�E�B���h�E����A�N�e�B�u�łȂ��Ă��������p�����邩�ݒ�

	SetGraphMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32);	//��ʃT�C�Y�̐ݒ�

	if (DxLib_Init() == -1) return -1;	// DX���C�u�����̏���������

	SetDrawScreen(DX_SCREEN_BACK);	// �`����ʂ𗠂ɂ���

	SceneManager* sceneMng; //�V�[���}�l�[�W���[


	sceneMng = new SceneManager((AbstractScene*)new Title()); //�V�[���}�l�[�W���[�Ƀ^�C�g�����Z�b�g

	
	// �Q�[�����[�v
	while ((ProcessMessage() == 0) && (sceneMng->Update() != nullptr))
	{

		ClearDrawScreen();		// ��ʂ̏�����
		PadInput::UpdateKey();
		sceneMng->Draw();

		

		ScreenFlip();			// ����ʂ̓��e��\��ʂɔ��f

		//�t���[�����[�g�̐ݒ�
		dNextTime += 1.0 / 60.0 * 1000.0;

		if (dNextTime > GetNowCount())
		{
			WaitTimer(static_cast<int>(dNextTime) - GetNowCount());
		}
		else { dNextTime = GetNowCount(); }		//�␳
	}


	return 0;
}