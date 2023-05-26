#pragma once
#include "AbstractScene.h"
class Title :
    public AbstractScene
{
private:

    enum class MENU
    {
        PLAY,
        //OPTION,
        HELP,
        EXIT,
        MENU_SIZE
    };

    const char* menu_items[static_cast<int>(MENU::MENU_SIZE)] = {
        "PLAY",
        //"OPTION",
        "HELP",
        "EXIT"
    };

    // 選択しているメニュー
    int select_menu;

public:

    //コンストラクタ
    Title();

    //デストラクタ
    ~Title();

    //描画以外の更新を実行
    AbstractScene* Update() override;

    //描画に関することを実装
    void Draw() const override;
};

