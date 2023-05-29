#pragma once
#include "AbstractScene.h"
class Title :
    public AbstractScene
{
private:

    enum class MENU
    {
        PLAY,
        EXIT,
        MENU_SIZE
    };

    const char* menu_items[static_cast<int>(MENU::MENU_SIZE)] = 
    {
        "PLAY",
        "EXIT"
    };

    // �I�����Ă��郁�j���[
    int select_menu;

    //����Ԋu����
    int input_margin;

    //�t�F�[�h�p�J�E���^
    int fade_counter;

public:

    //�R���X�g���N�^
    Title();

    //�f�X�g���N�^
    ~Title();

    //�`��ȊO�̍X�V�����s
    AbstractScene* Update() override;

    //�`��Ɋւ��邱�Ƃ�����
    void Draw() const override;
};

