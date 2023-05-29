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

    // 選択しているメニュー
    int select_menu;

    //操作間隔時間
    int input_margin;

    //フェード用カウンタ
    int fade_counter;

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

