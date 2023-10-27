#ifndef FUNCTION_H
#define FUNCTION_H

// contents of print.c
void startPrint();
void cleanScreen();
void inputErrorPrint01();
void imageErrorPrint01();
void imageErrorPrint02();
void imageErrorPrint03();
void imageErrorPrint04();
void imageErrorPrint05();
void imageErrorPrint06();
void normalExit01();
void importErrorPrint01();

// contents of general.c
void waitKey();
int inputCheck(int cnt, char *pass);
void resultGraph(char label, float result);

// contents of image.c
int imageCheck(char *pass);
void inputImage(char *img, char *pass);
void displayImage(char *img, int cnt);

// contents of net.c
int judge(char img[256], float result[9]);

#endif
