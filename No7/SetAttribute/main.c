#include "efi.h"
#include "common.h"

void efi_main(void *ImageHandle __attribute__ ((unused)),
            struct EFI_SYSTEM_TABLE *SystemTable)
{
    efi_init(SystemTable);

    puts(L" ");

    ST->ConOut->SetAttribute(ST->ConOut,
                    EFI_LIGHTGREEN | EFI_BACKGROUND_LIGHTGRAY);
    ST->ConOut->ClearScreen(ST->ConOut);

    puts(L"\r\n\r\n\r\n\r\n\r\n\r\n\r\n");
    puts(L"                              ");
    puts(L"フルスクラッチで作る！\r\n");

    ST->ConOut->SetAttribute(ST->ConOut,
                EFI_LIGHTRED | EFI_BACKGROUND_LIGHTGRAY);
    puts(L"                              ");
    puts(L"UEFIベアメタルプログラミング\r\n");

    ST->ConOut->SetAttribute(ST->ConOut,
                EFI_LIGHTGREEN | EFI_BACKGROUND_LIGHTGRAY);
    puts(L"                                  ");
    puts(L"Welcome to wcatOS!!!\r\n");

    ST->ConOut->SetAttribute(ST->ConOut,
                EFI_LIGHTRED | EFI_BACKGROUND_LIGHTGRAY);
    puts(L"                                  ");
    puts(L"meow!!!");

    while (TRUE);
}
