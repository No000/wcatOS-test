#include <fb.h>
#include <fbcon.h>

#define TRUE    1
// 第二引数でフレームバッファのアドレス、第三引数でファイルシステムの先頭アドレスを渡してるらしい
void start_kernel(void *_t __attribute__ ((unused)), struct framebuffer *_fb,
            void *_fs_start __attribute__ ((unused)))
{
    fb_init(_fb);
    set_fg(0, 204, 153);
    set_bg(51, 51,  51);
    clear_screen();
    
    puts("HELLO WORLD!");

    while (TRUE);
}

// r:100g:10b:100
