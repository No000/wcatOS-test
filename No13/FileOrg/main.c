#include <fb.h>
#define TRUE    1
// 第二引数でフレームバッファのアドレス、第三引数でファイルシステムの先頭アドレスを渡してるらしい
void start_kernel(void *_t __attribute__ ((unused)), struct framebuffer *_fb,
            void *_fs_start __attribute__ ((unused)))
{
    fb_init(_fb);
    set_bg(0, 255, 0);
    clear_screen();
    
    while (TRUE);
}

// r:100g:10b:100
