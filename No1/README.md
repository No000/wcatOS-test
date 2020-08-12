# BareMetalUefi2  
キー入力に関しての演習  
main.c・・・キー入力のエコーバック  
main1.c・・・上記アプリケーションのイベント時にCPUを休止させる版  

### 使用するUEFIのプロトコル  

EFI_STATUS・・・符号なしのネイティブ幅（機種のbit数）  
*EFI_HANDLE・・・関連するインターフェースの集合体、Void型  

### コンパイル方法  

```bash
x86_64-w64-mingw32-gcc -Wall -Wextra -e efi_main -nostdinc -nostdlib -fno-builtin -Wl,--subsystem,10 -o Exfile/main.efi BareMetalUefi2/src/main.c 
```
main1.cは適宜変える  
### 実行方法  
```bash
qemu-system-x86_64 -m 512 -bios firmware/OVMF.fd -hda fat:rw:hdd1
```

### ディレクトリ構造  
```bash
.
├── BareMetalUefi
│  ├── README.md
│  └── sample_1_1_hello_uefi
│     └── main.c
├── BareMetalUefi2
│  ├── README.md
│  └── src
│     ├── main.c
│     └── main1.c
├── Exfile
│  ├── BOOTX64.efi
│  └── main.efi
├── firmware
│  └── OVMF.fd
└── hdd1
   └── EFI
      └── BOOT
         └── BOOTX64.efi
```

### 適当な感想  
UEFI仕様書の構造体のプロトコル名から型まで大文字なので、仕様書独特の型をunsighed long longに書き直すのは読みやすくて割とありだなと思った。(けど仕様書読んでると、typdefで再定義したほうがわかりやすい…うーんこの)  

### C言語的な  

```__attribute__ ((unused))```
    ・・・使用しない仮引数の指定をするためのもの、voidのほうがいいらしい？

・システムテーブルの隙間埋めのバッファの大きさはCommon UEFI Data Typesを参照  

### ゴミ置き場  
```c
/* 空文字列系の定義 */
#define IN
#define EFIAPI
#define EFI_SUCCESS 0

/* UEFI固有の型の変換 */
typedef unsigned short CHAR16;
typedef unsigned long long EFI_STATUS;
typedef void *EFI_HANDLE;

/* プロトコルの宣言 */
struct _EFI_SIMPLE_TEXT_INPUT_PROTOCOL;
struct _EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL;

/* エントリーポイント */
typedef
EFI_STATUS
(EFIAPI *EFI_TEXT_STRING) (
IN EFI_HANDLE           ImageHandle,
IN EFI_SYSTEM_TABLE     *SystemTable
);

/* EFI_SYSTEM_TABLE */
typedef struct {
    unsigned long long _buf1[44];
    EFI_SIMPLE_TEXT_INPUT_PROTOCOL      *ConIn;
    unsigned long long _buf2;
    EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL     *ConOut;
} EFI_SYSTEM_TABLE;

/* プロトコルの各種関数の変換 */
typedef struct _EFI_SIMPLE_TEXT_INPUT_PROTOCOL {
    unsigned long long      _buf3;
    EFI_INPUT_READ_KEY      ReadKeyStroke;
} EFI_SIMPLE_TEXT_INPUT_PROTOCOL;

typedef struct _EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL {
unsigned long long          _buf4;
EFI_TEXT_STRING             OutputString;
unsigned long long          _buf5[4];
EFI_TEXT_CLEAR_SCREEN       ClearScreen;
} EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL;

void efi_main(
    IN      EFI_HANDLE      ImageHandle;
    IN      EFI_SYSTEM_TABLE        *SystemTable;
    )
{
    unsigned short str[3];
    SystemTable
}
```