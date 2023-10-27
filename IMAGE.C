// Shift-JIS, CR+LF

///////////////////////////////////////////////////////////
// �t�@�C�� : image.c                                    //
// ����     : masuda                                     //
// �쐬���� : 2023/10/08 - 2023/10/08                    //
// ����     : �摜�����Ɋւ���֐��B                     //
///////////////////////////////////////////////////////////

// �K�v���C�u�����̃C���|�[�g
#include <stdio.h>
#include "function.h"

int imageCheck(char *pass) {
	// �t�@�C���̓ǂݍ���
	FILE *fp = fopen(pass, "rb");
	
	if(fp == NULL) {
		// �摜�t�@�C���̃p�X�����݂��Ȃ�
		return 1;
	}
	
	// 16x16��24�r�b�gbmp�̃f�[�^�T�C�Y�͏��822
	unsigned char bin[822];
	unsigned char byte;
	
	// �t�@�C���̃T�C�Y���擾
	fseek(fp, 0, SEEK_END);
	int file_size = ftell(fp);
	// printf("%d\n", file_size);
	
	// �摜�t�@�C���`�F�b�N
	if(file_size != 822) {
		fclose(fp);
		return 2;
	}
	
	int cnt = 0;
	// �|�C���^��擪��
	fseek(fp, 0, SEEK_SET);
	// �z��ɕۑ�����
	while(cnt < 822) {
		byte = fgetc(fp);
		bin[cnt] = byte;
		// printf("%02x ", bin[cnt]);
		cnt++;
	}
	
	// printf("%02x\n", bin[0]);
	// printf("%02x\n", bin[1]);
	
	fclose(fp);
	
	// bmp�t�@�C����
	if((bin[0x00] != 0x42) || (bin[0x01] != 0x4D)) {
		return 3;
	}
	
	// �T�C�Y��16x16��
	if((bin[0x12] != 0x10) || (bin[0x16] != 0x10)) {
		return 4;
	}
	
	// �[����24�r�b�g��
	if((bin[0x1C] != 0x18) || (bin[0x1D] != 0x00)) {
		return 5;
	}
	
	// �f�[�^�����m�N����
	int i;
	for(i=56; i<820; i+=3) {
		if(bin[i] != 0x00 && bin[i] != 0xFF) {
			return 6;
		}
	}
	
	return 0;
}

void inputImage(char *img, char *pass){
	// �t�@�C���̓ǂݍ���
	FILE *fp = fopen(pass, "rb");
	
	unsigned char bin[822];
	unsigned char byte;
	int cnt = 0;
	
	// �z��ɕۑ�����
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
		// 0x00�������獕�A0xFF�������甒���_���v
		if(img[i] == 0x00) {
			printf("��");
		}
		else if(img[i] == 0x01) {
			printf("��");
		}
		else {
			// ��O�����C���ʂ�0x00��������0xff�Ȃ̂ł����͂Ȃ�Ȃ�
			printf("%02x", img[i]);
		}
		i++;
	}
}