# BareMetalUefi6  
今回は、ファイル(FATでフォーマットされたもの)の読み書きに関してを知ることができるようです。  

注)マウスが動作しないので、GUIモード関連の章は飛ばします。(写経だけはする。)  

# ソースコード関連  


Unicodeのテキストファイルの生成
```bash
nkf -w16L0 -Lw sample.txt >> abc
```

コンパイル  
```bash
x86_64-w64-mingw32-gcc -Wall -Wextra -e efi_main -nostdinc -nostdlib -fno-builtin -Wl,--subsystem,10 -o ../Exfile/BOOTX64.EFI efi.c common.c shell.c main.c graphics.c gui.c file.c
```

Qemu  
```bash
qemu-system-x86_64 -enable-kvm -m 512 -bios firmware/OVMF.fd -hda fat:rw:hdd1
```

# 使用するプロトコル  
・EFI_SIMPLE_FILE_SYSTEM_PROTOCOL  

・EFI_FILE_PROTOCOL  

# メモ  

・ここで作成するcatコマンドはもどきなので、指定されたファイルしか出力できない。  

・ファイルの読み出しはOpen関数を使用する。  

・Open関数の第三引数である、モードは8進数（マクロで置換しろということ）->仕様書P508  

・Unicodeのテキストファイルを用意したが、改行コードかなにかに問題があるのか変な改行とスペースが追加されてしまっていた。（abc）  

・ファイルに書き込んだ場合は、Flush関数を実行してあげなければならない。  

・Flushとは、メモリ上のバッファのデータを記憶装置に書き込むこと  

# 参考・引用文献  
>http://yuma.ohgami.jp/UEFI-Bare-Metal-Programming/main_5.html  
