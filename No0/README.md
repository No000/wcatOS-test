# BareMetalUefi  

### クロスコンパイラ  
```bash
sudo apt install gcc-mingw-w64-x86-64
```
mingwバージョン  
```bash
gcc version 9.2-win32 20191008 (GCC) 
```

### コンパイル方法  
```bash
x86_64-w64-mingw32-gcc -Wall -Wextra -e efi_main -nostdinc -nostdlib -fno-builtin -Wl,--subsystem,10 -o main.efi ../BareMetalUefi/sample_1_1_hello_uefi/main.c 
```
オプション  
-Wall・・・特殊な警告オプションの全部のせ（man gccを参照のこと）  

-nostdinc・・・ヘッダファイルのための標準のシステムディレクトリを検索しません。`-I' オプションによって指定したディレクトリ (またはカレントディレクト リ) のみを検索します。
`-nostdinc' と `-I-'を使用することにより、インクルードファイルの検索パスを明示的に指 定したディレクトリのみに限定することが可能となります。  

-nostdlib・・・リンク時に、標準のシステムライブラリとスタートアップファイルを使用しません。 指定したファイルのみがリンカに渡されます。  

-fno-builtin・・・ビルトイン関数のうち、2 つのアンダースコアで始まるもの以外を認識しなくなり ます。現在、この指定は_exit, abort, abs, alloca, cos, exit, fabs, labs, memcmp, memcpy, sin, sqrt, strcmp, strcpy, strlen の関数に影響を及ぼします。
`-ansi' オプションを指定すると、alloca と _exit はビルトイン関数として扱われなくなります。  

-Wl,・・・オプション option をリンカに渡します。option がコンマを含む場合は、それらのコンマで複数のオプションとして分割されます。  

--subsystem,10・・・実行ファイルの指定っぽい  

>https://linuxjm.osdn.jp/html/GNU_gcc/man1/gcc.1.html

### Qemuでの実行方法  
```bash
qemu-system-x86_64 -m 512 -bios firmware/OVMF.fd -hda fat:rw:hdd1
```

### ディレクトリ構造  
```bash
BM
├── BareMetalUefi
│  ├── README.md
│  └── sample_1_1_hello_uefi
│     └── main.c
├── Exfile
│  ├── BOOTX64.efi
│  └── main.efi
├── firmware
│  └── OVMF.fd
├── hdd1
│  └── EFI
│     └── BOOT
│        └── BOOTX64.efi
```

### 全体的な参考文献  
>http://yuma.ohgami.jp/UEFI-Bare-Metal-Programming/
