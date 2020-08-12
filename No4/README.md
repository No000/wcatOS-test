# BareMetalUefi5  
マウス情報の取得を行うことをやるようです。 
   
注) 悲しいことにQemuだとマウスが動かないので、軽い改造なしで写経だけにとどめておきます。(´Ａ｀。)  


# メモ  
・マウスのデータの取得には、```EFI_SIMPLE_POINTER_PROTOCOL```を使用する。  

・Qemuでのハードディスクとみなしたディレクトリ下に作成されるNvVarsというファイルは、本来はUEFIによってNVRAMに保存されるBIOS設定変数を保管するためのファイル。  

# 注  
参考文献の著者の方が公開しているビルド済みバイナリのRead.txtで確認をしたのですが、EFI_SIMPLE_POINTER_PROTOCOLは動かないようです。  

# 参考文献  
>http://yuma.ohgami.jp/UEFI-Bare-Metal-Programming/main_4.html  
