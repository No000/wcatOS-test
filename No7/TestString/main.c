#include "efi.h"
#include "common.h"

void efi_main(void *ImageHandle __attribute__ ((unused)),
            struct EFI_SYSTEM_TABLE *SystemTable)
{
    efi_init(SystemTable);
    ST->ConOut->ClearScreen(ST->ConOut);

    /* test1 */
    if (!ST->ConOut->TestString(ST->ConOut, L"Hello"))
        puts(L"English: success!(0_0)\r\n");
    else
        puts(L"English: fail...(*_*)\r\n");
    
    /* test2 */
    if (!ST->ConOut->TestString(ST->ConOut,L"こんにちは"))
        puts(L"Japanese: success!(0_0)\r\n");
    else
        puts(L"Japanese: fail...(*_*)\r\n");
    
    /* test3 */
    if (!ST->ConOut->TestString(ST->ConOut,L"こんにちは！meow!!!"))
        puts(L"English + Japanese: success!(0_0)\r\n");
    else
        puts(L"English + Japanese: fail...(*_*)\r\n");


    while (TRUE);
}
