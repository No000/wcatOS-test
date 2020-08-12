# BareMetalUefi9  
キーボード入力に関しての章らしいです。  

# 参照しているドキュメント  
UEFI_Spec_2_8_A_Feb14

## Makefileに関して  
作成したMakefileなのですが、make cleanを作ってないです。今後、入れれたら入れよかなって…  

# 使用しているプロトコル  
keyb  
## EFI_SIMPLE_TEXT_INPUT_EX_PROTOCOL  
RegisterKeyNotify()・・・特定のキーで呼び出す関数を登録できる(ReadKeyStrokeExも覗いた方がいいっぽい？)  

# メモ  
配列にいれてた折返しの```\```が悪さをしていました。なんでやろ…？  

# 引用・参考文献  
>http://yuma.ohgami.jp/UEFI-Bare-Metal-Programming-2/02_simple_text_input_ex.html