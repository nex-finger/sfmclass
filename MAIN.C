// Shift-JIS, CR+LF

///////////////////////////////////////////////////////////
// �t�@�C�� : main.c                                     //
// ����     : masuda                                     //
// �쐬���� : 2023/10/07 - 2023/10/07                    //
// ����     : main�֐��̏ꏊ�B                           //
//            ���̓f�[�^�̓ǂݍ��݁A���̓f�[�^�̕\���A�w //
//            �K�ς݂̃l�b�g���[�N�̓ǂݍ��݁A�l�b�g���[ //
//            �N�̏��`�d�A�o�͌��ʂ̏o�͂̏��Ԃōs���B   //
///////////////////////////////////////////////////////////

// �K�v���C�u�����̃C���|�[�g
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "function.h"

int main(int argc, char *argv[]) {
	unsigned char img[256];
	int i;
	
	// �\�t�g�N�����̃e�L�X�g�\��
	startPrint();
	
	// �R�}���h���C���������K�؂��ǂ���
	int chk = inputCheck(argc, argv[1]);
	if(chk != 0) {
		inputErrorPrint01();
		return 1;
	}
	
	// ���̓f�[�^�ǂݍ���
	inputImage(img, argv[1]);

	// ���̓f�[�^�\��
	for(i = 0; i < 16; i++) {
		displayImage(img, i);
		printf("\n");
	}
	
	// ���_�����邩�ۂ��C�����������ꍇ�v���O�����𐳏�I��
	char c[1];
	printf("\nDo you want to input this data? (Y/N):");
	scanf("%s", c);
	if(c[0] != 'Y' && c[0] != 'y') {
		normalExit01();
		return 0;
	}
	printf("Running...");
		
	// �l�b�g���[�N�̓��́A���`�d�Csoftmax
	float result[9];
	chk = judge(img, result);
	if(chk != 0) {
		return 1;
	}
	printf("Done.\n\nResult\n");
	
	// ��ʂ����Z�b�g
	// cleanScreen();

	// ���͉摜�C�o�͌��ʂ̕\��
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