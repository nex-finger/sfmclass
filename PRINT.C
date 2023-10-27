// Shift-JIS, CR+LF

///////////////////////////////////////////////////////////
// ファイル : print.c                                    //
// 著者     : masuda                                     //
// 作成日時 : 2023/10/07 - 2023/10/07                    //
// 説明     : print文が大量にある処理の集まり。          //
///////////////////////////////////////////////////////////

// 必要ライブラリのインポート
#include <stdio.h>
#include "function.h"

void startPrint() {
	puts("sfm.exe ver0.9.9");
	puts("Copyright (C) 2023 Softmedia, CIT.");
	puts("This is free software, There is NO warranty.");
	puts("");
}

void inputErrorPrint01() {
	perror("ERROR : Wrong number of arguments ");
	puts("Usage : SFMCLASS [inputpass.bmp]");
	puts("16x16 pixel, 24bit depth, 822bytes size ");
	puts("Program will stop.");
	puts("");
	waitKey();
}

void imageErrorPrint01() {
	perror("ERROR : non-exist input pass ");
	puts("Cannot find image.");
	puts("Program will stop.");
	puts("");
	waitKey();
}

void imageErrorPrint02() {
	perror("ERROR : Excess image data ");
	puts("You have to select .bmp with 16x16 pixels.");
	puts("Program will stop.");
	puts("");
	waitKey();
}

void imageErrorPrint03() {
	perror("ERROR : non-bmp file ");
	puts("You have to select .bmp with 16x16 pixels.");
	puts("Program will stop.");
	puts("");
	waitKey();
}

void imageErrorPrint04() {
	perror("ERROR : Incorrect resolution ");
	puts("You have to select .bmp with 16x16 pixels.");
	puts("Program will stop.");
	puts("");
	waitKey();
}

void imageErrorPrint05() {
	perror("ERROR : Incorrect depth ");
	puts("You have to set depth 24 bit(Full color)");
	puts("Program will stop.");
	puts("");
	waitKey();
}

void imageErrorPrint06() {
	perror("ERROR : Incorrect image ");
	puts("You have to set every pixel 0x00 or 0xFF");
	puts("Program will stop.");
	puts("");
	waitKey();
}

void cleanScreen() {
	int i;
	for(i = 0; i <= 25; i++) {
		printf("\n");
	}
}

void normalExit01() {
	printf("If you want to run, please type Y key.\n");
	puts("Program will stop.");
	puts("");
	waitKey();
}

void importErrorPrint01() {
	printf("Cannot open network files.");
	puts("Program will stop.");
	puts("");
	waitKey();
}

void memoryAllocError01() {
	printf("Cannot Memory Allocation.");
	puts("Program will stop.");
	puts("");
	waitKey();
}
