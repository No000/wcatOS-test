#include "common.h"
#include "graphics.h"
#include "shell.h"
#include "gui.h"

#define MAX_COMMAND_LEN     100

void shell(void)
{
    unsigned short com[MAX_COMMAND_LEN];
    struct RECT r1 = {10, 10, 100, 200};    /* x,y,w,h */
    struct RECT r2 = {150, 150, 200, 100};
    struct RECT r3 = {200, 0, 1, 500};

    while (TRUE) {
        puts(L"wcatOS> ");
        if (gets(com, MAX_COMMAND_LEN) <= 0)
            continue;

        if (!strcmp(L"hello", com)) /* helloコマンド */
            puts(L"Hello World!\r\n");
        else if (!strcmp(L"uname", com))    /* unameコマンド */
            puts(L"wcatOS\r\n");
        else if (!strcmp(L"cls", com))  /* クリアコマンド */
            cls();
        else if (!strcmp(L"rect", com)) /* 矩形コマンド */
        {
            draw_rect(r1, white);
            draw_rect(r2, white);
            draw_rect(r3, white);
        }
        else if (!strcmp(L"gui", com))  /* guiモード */
            gui();
        else
            puts(L"Command not found.\r\n");     
    }
}
