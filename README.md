# sfmclass
入力された画像がS, O, F, T, M, E, D, I, Aのいずれかを分類するプログラム

<div align="center">
<br>
<img src="https://img.shields.io/badge/licence-masuda-green">
<img src="https://img.shields.io/badge/university-CIT-green">
<img src="https://img.shields.io/badge/undergraduate-Computer%20Science-green">
<br>
<img src="https://img.shields.io/badge/Arduino-blue">
<img src="https://img.shields.io/badge/TK80-blue">
<img src="https://img.shields.io/badge/Kansas%20City%20standard%20(KCS)-blue">
<br>
<img src="https://img.shields.io/badge/c++-yellow">
<img src="https://img.shields.io/badge/Python-yellow">
<img src="https://img.shields.io/badge/8080assembry-yellow">
<br>

<table>
    <tbody>
        <td align="center">
            <img width="2000" height="0"><br>
            Status: <b>Unfinished</b><br>
            LatestUpdate: <b>2023/10/28</b><br>
            <img width="2000" height="0">
        </td>
    </tbody>
</table>
</div>

[概要](#概要)  
[つまずきそうな要素](#つまずきそうな要素)

## 概要
ソフトメディア研究会4回生のmasudaです  
今回SOFTMEDIAの文字分類タスクを解くプログラムをcで書きました  
c99準拠です  
windows98で動くことを念頭に置いているので現代的でない部分についてはご容赦お願いします  
Shift-JISフォーマットで書いているので，各自reopenしてください  

## つまずきそうな要素
### 入力画像について
今回のプロジェクトで使用した画像は  
https://drive.google.com/drive/folders/1cyQN5DRnSuMA-4IHmRmFte2F0zj-e2HE?usp=sharing  
で公開しています  
trainフォルダはネットワークの学習に用いられています  
testフォルダはネットワークの検証に用いられます  
また，これらの画像の解像度には制約があります  
拡張子bmp，解像度16x16，ビットの深さ24，各ピクセルはRGB000000もしくはRGBFFFFFFのどちらかである必要があります  
この制約に則るとひとつの画像データは822バイトになりますので，自分のデータを入力したいときはあらかじめプロパティからこれらの要素を確認してください

### makeについて
複数のcファイルをソースとして1つの実行ファイルを生成する場合，makefileを用いることが一般的です  
main.c, general.c, image.c, print.c, net.cの関数をfunction.hに記述しています  
makefileの書き方はレガシーなアレを含むので積極的に学ぶ必要はないと思います

### 実行時のコマンドライン引数
makeを実行すると実行可能ファイルsfm.exeが生成されます  
sfm.exeの実行時，引数として入力画像のパスを指定してください  
例：sfm img/test/0000s.bmp
