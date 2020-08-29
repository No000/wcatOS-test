#include <x86.h>

inline unsigned char io_read(unsigned short addr)   // インラインアセンブラでin命令
{
    unsigned char value;
    asm volatile ("inb %[addr], %[value]"
                : [value] "=a"(value) : [addr]"d"(addr));   // アセンブラ拡張(アセンブラテンプレート: 出力オペランド : 入力オペランド)
    return value;
}
