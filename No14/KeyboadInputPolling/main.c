#include <fb.h>
#include <fbcon.h>
#include <kbc.h>

#define TRUE    1
// 第二引数でフレームバッファのアドレス、第三引数でファイルシステムの先頭アドレスを渡してるらしい
void start_kernel(void *_t __attribute__ ((unused)), struct framebuffer *_fb,
            void *_fs_start __attribute__ ((unused)))
{
    fb_init(_fb);
    set_fg(0, 204, 153);
    set_bg(51, 51,  51);
    clear_screen();
    
    while (TRUE){
        char c = getc();
        if (('a' <= c) && (c <= 'z'))
            c = c - 'a' + 'A';  // 大文字に変換
        else if (c == '\n')
            putc('\r');
        putc(c);    // 画面表示（基本の）
    }
}

// r:100 g:10 b:100 文字
// r:51 g:51 b:51    背景
