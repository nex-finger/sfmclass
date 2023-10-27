// Shift-JIS, CR+LF

///////////////////////////////////////////////////////////
// ファイル : image.c                                    //
// 著者     : masuda                                     //
// 作成日時 : 2023/10/08 - 2023/10/08                    //
// 説明     : 画像処理に関する関数。                     //
///////////////////////////////////////////////////////////

// 必要ライブラリのインポート
#include <stdio.h>
#include "function.h"

int imageCheck(char *pass) {
	// ファイルの読み込み
	FILE *fp = fopen(pass, "rb");
	
	if(fp == NULL) {
		// 画像ファイルのパスが存在しない
		return 1;
	}
	
	// 16x16の24ビットbmpのデータサイズは常に822
	unsigned char bin[822];
	unsigned char byte;
	
	// ファイルのサイズを取得
	fseek(fp, 0, SEEK_END);
	int file_size = ftell(fp);
	// printf("%d\n", file_size);
	
	// 画像ファイルチェック
	if(file_size != 822) {
		fclose(fp);
		return 2;
	}
	
	int cnt = 0;
	// ポインタを先頭へ
	fseek(fp, 0, SEEK_SET);
	// 配列に保存する
	while(cnt < 822) {
		byte = fgetc(fp);
		bin[cnt] = byte;
		// printf("%02x ", bin[cnt]);
		cnt++;
	}
	
	// printf("%02x\n", bin[0]);
	// printf("%02x\n", bin[1]);
	
	fclose(fp);
	
	// bmpファイルか
	if((bin[0x00] != 0x42) || (bin[0x01] != 0x4D)) {
		return 3;
	}
	
	// サイズが16x16か
	if((bin[0x12] != 0x10) || (bin[0x16] != 0x10)) {
		return 4;
	}
	
	// 深さが24ビットか
	if((bin[0x1C] != 0x18) || (bin[0x1D] != 0x00)) {
		return 5;
	}
	
	// データがモノクロか
	int i;
	for(i=56; i<820; i+=3) {
		if(bin[i] != 0x00 && bin[i] != 0xFF) {
			return 6;
		}
	}
	
	return 0;
}

void inputImage(char *img, char *pass){
	// ファイルの読み込み
	FILE *fp = fopen(pass, "rb");
	
	unsigned char bin[822];
	unsigned char byte;
	int cnt = 0;
	
	// 配列に保存する
	while(cnt < 822) {
		byte = fgetc(fp);
		bin[cnt] = byte;
		cnt++;
	}
	
	int i;
	cnt = 0;
	int adrs = 240;
	
	for(i=56; i<820; i+=3) {
		if(bin[i] == 0x00) {
			img[adrs] = 1;
		}
		else {
			img[adrs] = 0;
		}
		cnt++;
		adrs++;
		if(cnt % 16 == 0) {
			adrs -= 32;
		}
	}
	
	fclose(fp);
}

void displayImage(char *img, int cnt) {
	int i = 16 * cnt;
	int j;
	for(j = 0; j < 16; j++) {
		// 0x00だったら黒、0xFFだったら白をダンプ
		if(img[i] == 0x00) {
			printf("□");
		}
		else if(img[i] == 0x01) {
			printf("■");
		}
		else {
			// 例外処理，普通は0x00もしくは0xffなのでこうはならない
			printf("%02x", img[i]);
		}
		i++;
	}
}
