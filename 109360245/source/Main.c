#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <math.h>



int map_1[16][16] = {
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,4,1,0,0,4,1},
	{1,0,0,1,1,1,1,1,1,1,1,1,0,0,0,1},
	{1,0,0,1,0,0,2,0,0,0,0,0,0,1,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,1,2,1,1,1,1,1,0,1,0,1},
	{1,1,1,0,0,1,0,0,0,1,0,0,0,0,0,1},
	{1,4,1,0,0,1,0,0,0,1,0,0,0,0,0,1},
	{1,0,1,0,0,1,0,0,3,0,0,1,0,0,0,1},
	{1,0,1,0,0,0,0,0,0,2,0,1,0,1,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1,0,1,2,1},
	{1,0,0,0,0,0,1,0,1,1,1,1,0,1,0,1},
	{1,0,1,1,1,0,1,0,1,0,0,0,0,0,0,1},
	{1,0,1,1,1,0,1,0,2,0,0,1,1,1,0,1},
	{1,4,0,0,0,0,1,0,1,0,0,1,1,1,4,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},


};

int ui()
{
	printf("*************************************\n"
		"*     遊玩前請詳細閱讀公開說明書    *\n"
		"*        請按WASD控制上下左右       *\n"
		"*         請按R重新開始遊戲         *\n"
		"*      **請使用小寫英文遊玩**     *\n"
		"*                                   *\n"
		"*         請按任意鍵開始遊戲        *\n"
		"*************************************\n");
}

int Congratulations()
{
	system("mode con cols=150 lines=22");
	printf("         CCCCCC	\n"
		"	CCCCCCC                                               TT                LLL              TT       III                             !!!  !!! \n"
		"	CC   CC                                               TT                LLL              TT       III                             !!!  !!! \n"
		"	CC        OOOOO   NNNNNN    GGGGGG     RRRR  AAAAA    TTTTTTT  UU   UU  LLL     AAAAA    TTTTTTT        OOOOO   NNNNNN    SSSSSS  !!!  !!! \n"
		"	CC	 OOOOOOO  NNNNNNN  GGGGGGG   RRRR       AAAA  TTTTTTT  UU   UU  LLL        AAAA  TTTTTTT  III  OOOOOOO  NNNNNNN  SS    S  !!!  !!! \n"
		"	CC	 OO   OO  NN   NN  GG   GG  RRRR      AAAAAA  TT       UU   UU  LLL      AAAAAA  TT       III  OO   OO  NN   NN  SSSSS     !    ! \n"
		"	CC   CC  OO   OO  NN   NN  GG   GG  RR       AA   AA  TT       UU   UU  LLL     AA   AA  TT       III  OO   OO  NN   NN    SSSS    \n"
		"        CCCCCCC  OOOOOOO  NN   NN  GGGGGGG  RR       AA   AA  TTTTTTT  UUUUUUU  LLLLLL  AA   AA  TTTTTTT  III  OOOOOOO  NN   NN  S    SS  !!!  !!!\n"
		"  	 CCCCCC   OOOOO	  NN   NN   GGGGGG  RR        AAAAAA   TTTTTT   UUUUU    LLLLL   AAAAAA   TTTTTT  III   OOOOO   MM   NN  SSSSSS   !!!  !!! \n"
		"		                       GGG\n"
		"                                    GGGGG \n"
		"\n"
		"\n"
		"       ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■▲    ▲■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n"
		"       ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■▲▲■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■  \n"
		"       ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■▼▼■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n"
		"       ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■▼    ▼■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	return 0;
}


int donuts() {
	system("mode con cols=90 lines=30");
	float A = 0, B = 0;
	float i, j;
	int k;
	float z[1760];
	char b[1760];
	printf("\x1b[2J");
	for (;;) {
		memset(b, 32, 1760);
		memset(z, 0, 7040);
		for (j = 0; j < 6.28; j += 0.07) {
			for (i = 0; i < 6.28; i += 0.02) {
				float c = sin(i);
				float d = cos(j);
				float e = sin(A);
				float f = sin(j);
				float g = cos(A);
				float h = d + 2;
				float D = 1 / (c * h * e + f * g + 5);
				float l = cos(i);
				float m = cos(B);
				float n = sin(B);
				float t = c * h * g - f * e;
				int x = 40 + 30 * D * (l * h * m - t * n);
				int y = 12 + 15 * D * (l * h * n + t * m);
				int o = x + 80 * y;
				int N = 8 * ((f * e - c * d * g) * m - c * d * e - f * g - l * d * n);
				if (22 > y && y > 0 && x > 0 && 80 > x && D > z[o]) {
					z[o] = D;
					b[o] = ".,-~:;=!*#$@"[N > 0 ? N : 0];
				}
			}
		}
		printf("\x1b[H");
		for (k = 0; k < 1761; k++) {
			putchar(k % 80 ? b[k] : 10);
			A += 0.00004;
			B += 0.00002;
		}
	}
	return 0;
}