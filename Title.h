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
 

    // 選択しているメニュー
    int select_menu;

    //カーソルのY座標
    int cursor_y;

    //操作間隔時間
    int input_margin;

    //フェード用カウンタ
    int fade_counter;

    int stick_y;

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

