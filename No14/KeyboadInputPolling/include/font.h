#ifndef _FONT_H_
#define _FONT_H_
// 文字の大きさを定義(描画範囲が変わるだけで範囲は変わらない)
#define FONT_WIDTH	8
#define FONT_HEIGHT	10

extern const unsigned char font_bitmap[][FONT_HEIGHT][FONT_WIDTH];

#endif
