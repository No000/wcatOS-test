# BareMetalUefi3  
シェルっぽいもののを作る演習  

# ファイル構成  
main.c・・・エントリポイントの設置  

efi.h、efi.c・・・UEFIの定義や初期化処理を担当

common.h、common.c・・・凡庸的に定義される定義や関数を担当(毎回メンバにアクセスするのは大変だからだと思う+標準関数は使えないのでっぽい)  

shell.h、shell.h・・・シェルの処理を担当  

# 実行方法  
コンパイル  
```bash
x86_64-w64-mingw32-gcc -Wall -Wextra -e efi_main -nostdinc -nostdlib -fno-builtin -Wl,--subsystem,10 -o ../Exfile/BOOTX64.EFI efi.c common.c shell.c main.c 
```

実行  
```bash
qemu-system-x86_64 -m 512 -bios firmware/OVMF.fd -hda fat:rw:hdd1
```

# ディレクトリ構造  
```bash
├── BareMetalUefi3
│  ├── common.c
│  ├── common.h
│  ├── efi.c
│  ├── efi.h
│  ├── main.c
│  ├── README.md
│  ├── shell.c
│  └── shell.h
├── Exfile
│  └── BOOTX64.EFI
├── firmware
│  └── OVMF.fd
└── hdd1
   └── EFI
      └── BOOT
         └── BOOTX64.EFI
```

# 感想  
ヘッダーファイルに記載されている#ifndefはデバッグ用？

# 参考文献  
>http://yuma.ohgami.jp/UEFI-Bare-Metal-Programming/
