#include <fb.h>

struct framebuffer fb;
struct pixelformat color_fg;
struct pixelformat color_bg;

void fb_init(struct framebuffer *_fb)   // ブートローダーからバッファへのポインタを受け取る
{
    fb.base = _fb->base;    // *_fbなのでポインタ参照
    fb.size = _fb->size;
    fb.hr   = _fb->hr;
    fb.vr   = _fb->vr;
}

void set_fg(unsigned char r, unsigned char g, unsigned char b)  // フォントの色の事前設定
{
    color_fg.b = b;
    color_fg.g = g;
    color_fg.r = r;
}

void set_bg(unsigned char r, unsigned char g, unsigned char b)
{
    color_bg.b = b;
    color_bg.g = g;
    color_bg.r = r;
}

inline void draw_px(unsigned int x, unsigned int y,
            unsigned char r, unsigned char g, unsigned char b)
{
    struct pixelformat *p = fb.base;
    p += y * fb.hr + x;

    p->b = b;
    p->g = g;
    p->r = r;
}

inline void draw_px_fg(unsigned int x, unsigned int y)  // フォントの座標の指定（事前に色を設定する必要あり）
{
    draw_px(x, y, color_fg.r, color_fg.g, color_fg.b);
}

inline void fill_rect(unsigned int x, unsigned int y,   // 左上の基準座標
                unsigned int w, unsigned int h,         // ワイド、ハイの大きさ
                unsigned char r, unsigned char g, unsigned char b)  //  色
{
    unsigned int i, j;
    for (i = y; i < (y + h); i++)
        for (j = x; j < (x + w); j++)
            draw_px(j, i, r, g, b);
}

void clear_screen(void)
{
    fill_rect(0, 0, fb.hr, fb.vr, color_bg.r, color_bg.g, color_bg.b);
}
