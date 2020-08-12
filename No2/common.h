#ifndef _COMMON_H_
#define _COMMON_H_

#define NULL        (void *)0
#define TRUE        1
#define FALSE       0

void putc(unsigned short c);
void puts(unsigned short *s);
unsigned int gets(unsigned short *buf, unsigned int buf_size);
int strcmp(const unsigned short *sl, const unsigned short *s2);
void cls(void);
#endif
