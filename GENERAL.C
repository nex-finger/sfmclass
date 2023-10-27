// Shift-JIS, CR+LF

///////////////////////////////////////////////////////////
// �t�@�C�� : general.c                                  //
// ����     : masuda                                     //
// �쐬���� : 2023/10/08 - 2023/10/07                    //
// ����     : �G���Ȋ֐��̏W�܂�B                       //
//            ��̊֐���������Ȃ���΂����ɋL�q�B     //
///////////////////////////////////////////////////////////

// �K�v���C�u�����̃C���|�[�g
#include <stdio.h>
#include "function.h"

void waitKey() {
	puts("���s����ɂ͉����L�[�������Ă�������...");
	getchar();
}

int inputCheck(int cnt, char *pass) {
	// �R�}���h���C�������̐����K�؂ł͂Ȃ�
	if(cnt != 2) {
		// �R�}���h���C������������Ȃ������葽��������
		inputErrorPrint01();
		return 1;
	}
	
	// �R�}���h���C�����͂̉摜���K�؂�
	int chk_flg = imageCheck(pass);
	
	if(chk_flg == 1) {
		// �摜�t�@�C���̃p�X�����݂��Ȃ�
		imageErrorPrint01();
		return 1;
	}
	else if(chk_flg == 2) {
		// �摜�t�@�C���T�C�Y����
		imageErrorPrint02();
		return 1;
	}
	else if(chk_flg == 3) {
		// �t�@�C���g���q�s���v
		imageErrorPrint03();
		return 1;
	}
	else if(chk_flg == 4) {
		// �𑜓x�s���v
		imageErrorPrint04();
		return 1;
	}
	else if(chk_flg == 5) {
		// �r�b�g�̐[���s���v
		imageErrorPrint05();
		return 1;
	}
	else if(chk_flg == 2) {
		// ��f�f�[�^�s��
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