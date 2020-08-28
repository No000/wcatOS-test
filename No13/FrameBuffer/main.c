#define BG_RED      100
#define BG_GREEN    10
#define BG_BLUE     100
#define TRUE        1

struct pixelformat {
    unsigned char b;
    unsigned char g;
    unsigned char r;
    unsigned char _reserved;
};

struct framebuffer {
    struct pixelformat *base;
    unsigned long long size;
    unsigned int hr;
    unsigned int vr;
};
// 第二引数でフレームバッファのアドレス、第三引数でファイルシステムの先頭アドレスを渡してるらしい
void start_kernel(void *_t __attribute__ ((unused)), struct framebuffer *fb,
            void *_fs_start __attribute__ ((unused)))
{
    unsigned int x, y;
    struct pixelformat *p;

    for (y = 0; y < fb->vr; y++) {
        for (x = 0; x < fb->hr; x++) {
            p = fb->base + (fb->hr * y) + x;
            p->r = BG_RED;
            p->g = BG_GREEN;
            p->b = BG_BLUE;
        }
    }

    while (TRUE);
}
