// Shift-JIS, CR+LF

///////////////////////////////////////////////////////////
// ファイル : main.c                                     //
// 著者     : masuda                                     //
// 作成日時 : 2023/10/07 - 2023/10/07                    //
// 説明     : main関数の場所。                           //
//            入力データの読み込み、入力データの表示、学 //
//            習済みのネットワークの読み込み、ネットワー //
//            クの順伝播、出力結果の出力の順番で行う。   //
///////////////////////////////////////////////////////////

// 必要ライブラリのインポート
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "function.h"

int main(int argc, char *argv[]) {
	unsigned char img[256];
	int i;
	
	// ソフト起動時のテキスト表示
	startPrint();
	
	// コマンドライン引数が適切かどうか
	int chk = inputCheck(argc, argv[1]);
	if(chk != 0) {
		inputErrorPrint01();
		return 1;
	}
	
	// 入力データ読み込み
	inputImage(img, argv[1]);

	// 入力データ表示
	for(i = 0; i < 16; i++) {
		displayImage(img, i);
		printf("\n");
	}
	
	// 推論をするか否か，したく無い場合プログラムを正常終了
	char c[1];
	printf("\nDo you want to input this data? (Y/N):");
	scanf("%s", c);
	if(c[0] != 'Y' && c[0] != 'y') {
		normalExit01();
		return 0;
	}
	printf("Running...");
		
	// ネットワークの入力、順伝播，softmax
	float result[9];
	chk = judge(img, result);
	if(chk != 0) {
		return 1;
	}
	printf("Done.\n\nResult\n");
	
	// 画面をリセット
	// cleanScreen();

	// 入力画像，出力結果の表示
	char label[9] = "SOFTMEDIA";
	for(i = 0; i < 16; i++) {
		displayImage(img, i);
		if(i < 9) {
			resultGraph(label[i], result[i]);
		}
		printf("\n");
	}
	
	puts("\nDone.");
	return 0;
}
