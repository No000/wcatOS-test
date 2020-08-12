# BareMetalUefi4  
今回はグラフィックの画面出力を行う方法を演習する感じみたい。  
# メモ  
・グラフィック描画のための```EFI_GRAPHIC_OUTPUT_PROTOCOL```はSystemTableのメンバではないので、プロトコルの先頭アドレスを取得することでアクセスする。  

・画面モードの変更は、```EFI_GRAPHICS_OUTPUT_PROTOCOL```のSetMode関数を使うことで変更することができる。  

# コンパイル方法  
```bash
x86_64-w64-mingw32-gcc -Wall -Wextra -e efi_main -nostdinc -nostdlib -fno-builtin -Wl,--subsystem,10 -o ../Exfile/BOOTX64.EFI efi.c common.c shell.c main.c graphics.c
```

# 実行方法  
```bash
qemu-system-x86_64 -m 512 -bios firmware/OVMF.fd -hda fat:rw:hdd1
```

# ディレクトリ構造  
```bash
├── BareMetalUefi4
│  ├── common.c
│  ├── common.h
│  ├── efi.c
│  ├── efi.h
│  ├── graphics.c
│  ├── graphics.h
│  ├── gui.c
│  ├── gui.h
│  ├── main.c
│  ├── README.md
│  ├── shell.c
│  └── shell.h
├── Exfile
│  └── BOOTX64.EFI
├── firmware
│  └── OVMF.fd
└── hdd1
   ├── EFI
   │  └── BOOT
   │     └── BOOTX64.EFI
   └── NvVars
```

# 参考＋引用文献  
>http://yuma.ohgami.jp/UEFI-Bare-Metal-Programming/main_3.html