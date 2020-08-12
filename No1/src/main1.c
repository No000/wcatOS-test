/* キー入力の定義 */
struct EFI_INPUT_KEY {
    unsigned short ScanCode;
    unsigned short UnicodeChar;
};



/* システムテーブルの定義 */
struct EFI_SYSTEM_TABLE {
    char _buf1[44];
    /* キー入力のプロトコル */
    struct EFI_SIMPLE_TEXT_INPUT_PROTOCOL {
        unsigned long long _buf;
        unsigned long long (*ReadKeyStroke)(
            struct EFI_SIMPLE_TEXT_INPUT_PROTOCOL *This,
            struct EFI_INPUT_KEY                  *key);
        void *WaitForKey;
    } *ConIn;

    unsigned long long _buf2;
    
    /* 画面出力のプロトコル */
    struct EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL {
        unsigned long long _buf;
        unsigned long long (*OutputString) (
            struct EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This,
            unsigned short *String);
        unsigned long long _buf2[4];
        unsigned long long (*ClearScreen) (
            struct EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This);
    } *ConOut;
    unsigned long long _buf3[3];
    /* ブートサービスプロトコル（ブートローダ関連） */
    struct EFI_BOOT_SERVICES {
        char _buf1[24];
        /*                          */
        /* Task Priority Services   */
        /*                          */
        unsigned long long _buf2[2];
        /*                          */
        /* Memory Services          */
        /*                          */
        unsigned long long _buf3[5];
        /*                          */
        /* Event & Timer Services   */
        /*                          */
        unsigned long long _buf4[2];
        
        unsigned long long (*WaitForEvent) (
            unsigned long long NumberOfEvents,
            void **event,
            unsigned long long *Index
        );
        unsigned long long _buf4_2[3];
		/*                              */
		/* Protocol Handler Services    */
		/*                              */
		unsigned long long _buf5[9];
		/*                              */
		/* Image Services               */
		/*                              */
		unsigned long long _buf6[5];
		/*                              */
		/* Miscellaneous Services       */
		/*                              */
        unsigned long long _buf7[3];
        //
        // DriverSupport Services
        //
        unsigned long long _buf8[2];
        //
        // Open and Close Protocol Services
        //
        unsigned long long _buf9[3];
        //
        // Library Services
        //
        unsigned long long _buf10[5];
        //
        // 32-bit CRC Services
        //
        unsigned long long _buf11;
        //
        // Miscellaneous Services
        //
        unsigned long long _buf12[14]; 
    } *BootServices;
};

void efi_main(void *ImageHandle __attribute__ ((unused)),
        struct EFI_SYSTEM_TABLE *SystemTable)
{
    struct EFI_INPUT_KEY key;
    unsigned long long waitidx; /* 何らかの変数を用意してあげればいい感じ */

    unsigned short str[3];
    SystemTable->ConOut->ClearScreen(SystemTable->ConOut);
    while (1) {
        SystemTable->BootServices->WaitForEvent(1,
                                    &(SystemTable->ConIn->WaitForKey), &waitidx);
        if (!SystemTable->ConIn->ReadKeyStroke(SystemTable->ConIn,
                                &key)) {
            if (key.UnicodeChar != L'\r') {
                str[0] = key.UnicodeChar;
                str[1] = L'\0'; /* NULL文字 */
            } else {
                str[0] = L'\r';
                str[1] = L'\n';
                str[2] = L'\0';
            }
            SystemTable->ConOut->OutputString(SystemTable->ConOut,
                                str);
        }
    }
}
