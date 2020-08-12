# BareMetalUefi8  
コンソール出力をより高度なプロトコルを使用してやるようです。また今回からはMakefileを作成していこうかと…（ファイル移動が、そろそろめんどくさくなってきた）  
# 使用したプロトコルや関数  

・EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL.SetAttribute()・・・背景や文字色の変更  
・EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL.TestString()・・・使用できる文字のテスト  
・EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL.QueryMode()・・・コンソールのテキストモード情報の取得

# ディレクトリ関連  

```bash
├── BareMetalUefi8
│  ├── QueryMode・・・使用できるテキストモードの表示
│  │  ├── common.c
│  │  ├── common.h
│  │  ├── efi.c
│  │  ├── efi.h
│  │  ├── file.c
│  │  ├── file.h
│  │  ├── graphics.c
│  │  ├── graphics.h
│  │  ├── gui.c
│  │  ├── gui.h
│  │  ├── main.c
│  │  ├── shell.c
│  │  └── shell.h
│  ├── README.md
│  ├── SetAttribute・・・文字や背景の色を設定する
│  │  ├── common.c
│  │  ├── common.h
│  │  ├── efi.c
│  │  ├── efi.h
│  │  ├── file.c
│  │  ├── file.h
│  │  ├── graphics.c
│  │  ├── graphics.h
│  │  ├── gui.c
│  │  ├── gui.h
│  │  ├── main.c
│  │  ├── shell.c
│  │  └── shell.h
│  └── TestString・・・使用可能文字の判定
│     ├── common.c
│     ├── common.h
│     ├── efi.c
│     ├── efi.h
│     ├── file.c
│     ├── file.h
│     ├── graphics.c
│     ├── graphics.h
│     ├── gui.c
│     ├── gui.h
│     ├── main.c
│     ├── shell.c
│     └── shell.h

```

# メモ  

# 参考・引用文献  
>http://yuma.ohgami.jp/UEFI-Bare-Metal-Programming-2/01_simple_text_output.html