/* 画面出力のUEFIapp */
/* 使わない機能の部分の定義には、アドレスが合うようにバッファを入れている */
/* unsigned long longとしているのは、参考文献の著者の趣味であり、移植性が下がる。 */
/* 今後は、typedefで定義することにする */
struct EFI_SYSTEM_TABLE {
    char _buf[60];
    struct EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL {
        unsigned long long _buf;
        unsigned long long (*OutputString)(
            struct EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This,
            unsigned short *String);
            unsigned long long _buf2[4];
            unsigned long long (*ClearScreen) (
                struct EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This);  /* 所属している構造体のポインタ */
    } *ConOut;  /* 再定義 */
};

void efi_main(void *ImageHandle __attribute__ ((unused)),
        struct EFI_SYSTEM_TABLE *SystemTable)
{
    SystemTable->ConOut->ClearScreen(SystemTable->ConOut);
    SystemTable->ConOut->OutputString(SystemTable->ConOut,
                                    L"Hello UEFI\n");
    while(1);
}
