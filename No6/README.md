# BareMetalUefi7  
画像表示とUEFIアプリの終了、マウスの拡大をやるようです。  

# インストールやコマンド関連  

画像のフォーマット変換  
```bash
sudo apt install imagemagick
```


# 使用するプロトコル  

# メモ  
・QemuではUEFIオリジナルのblt関数は動作したが、参考文献の著者のPCだと動作しなかったためか自前で変換を行っている。 

・UEFIアプリケーションから抜け出してブートメニューに戻る方法は、無限ループの識別子をFALSEにすることで実現　　

・Qemuだとviewコマンドの実装あたりで、エラーを踏んじゃうようなので、2つディレクリを作成し、片方にexitコマンド（GUI関連はなし）を実装したものを置きます。  

# 参考・引用文献  
>http://yuma.ohgami.jp/UEFI-Bare-Metal-Programming/appendix.html  
