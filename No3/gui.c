#include "efi.h"
#include "common.h"
#include "graphics.h"
#include "gui.h"

void gui(void)
{
    /* 矩形の表示 */
    struct RECT r = {10, 10, 20, 20};

    ST->ConOut->ClearScreen(ST->ConOut);

    /* ファイルアイコンのような矩形を描画 */
    draw_rect(r, white);

    while (TRUE);
}
