// Shift-JIS, CR+LF

///////////////////////////////////////////////////////////
// ファイル : general.c                                  //
// 著者     : masuda                                     //
// 作成日時 : 2023/10/08 - 2023/10/07                    //
// 説明     : 雑多な関数の集まり。                       //
//            大体関数が見つからなければここに記述。     //
///////////////////////////////////////////////////////////

// 必要ライブラリのインポート
#include <stdio.h>
#include "function.h"

void waitKey() {
	puts("続行するには何かキーを押してください...");
	getchar();
}

int inputCheck(int cnt, char *pass) {
	// コマンドライン引数の数が適切ではない
	if(cnt != 2) {
		// コマンドライン引数が足りなかったり多すぎたり
		inputErrorPrint01();
		return 1;
	}
	
	// コマンドライン入力の画像が適切か
	int chk_flg = imageCheck(pass);
	
	if(chk_flg == 1) {
		// 画像ファイルのパスが存在しない
		imageErrorPrint01();
		return 1;
	}
	else if(chk_flg == 2) {
		// 画像ファイルサイズ超過
		imageErrorPrint02();
		return 1;
	}
	else if(chk_flg == 3) {
		// ファイル拡張子不合致
		imageErrorPrint03();
		return 1;
	}
	else if(chk_flg == 4) {
		// 解像度不合致
		imageErrorPrint04();
		return 1;
	}
	else if(chk_flg == 5) {
		// ビットの深さ不合致
		imageErrorPrint05();
		return 1;
	}
	else if(chk_flg == 2) {
		// 画素データ不良
		imageErrorPrint02();
		return 1;
	}
	
	return 0;
}

void resultGraph(char label, float result) {
	int j, d;
	
	printf(" %c %5.3f ", label, result);
	d = (int)(result * 30);
	for(j = 0; j < d; j++) {
		printf("+");
	}
}
