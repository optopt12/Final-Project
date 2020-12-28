#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <math.h>

int x, y;
int map[16][16] = { 0 };
int stars();     // 星星的個數
int startobox();    // 箱子到了星星的位置的個數

int up();
int down();
int left();
int right();

int output();
int find();          //找到自己
int ui();    //輸出主界面
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
int output()
{
	for (x = 0; x < 16; x++)
	{
		for (y = 0; y < 16; y++)
		{
			if (map[x][y] == 1)
				printf("■"); //輸出磚塊的樣子
			if (map[x][y] == 3)
				printf("⊙"); //輸出自己的位置
			if (map[x][y] == 2)
				printf("□"); //輸出箱子
			if (map[x][y] == 4)
				printf("☆"); //輸出箱子要到的位置
			if (map[x][y] == 0)
				printf("  "); //輸出空白
			if (map[x][y] == 5)
				printf("★"); //輸出箱子到了該到的位置
		}
		printf("\n");
	}
	return 0;
}
int find()
{
	for (x = 0; x < 16; x++)
		for (y = 0; y < 16; y++)
		{
			if (map[x][y] == 3)
				return 0;
		}
	return 0;
}
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
//星星的個數
int star()
{
	int n = 0;
	for (x = 0; x < 16; x++)
		for (y = 0; y < 16; y++)
		{
			if (map[x][y] == 4)
				n++;
		}
	return n;
}
//箱子到了位置的個數
int startobox()
{
	int m = 0;
	for (x = 0; x < 16; x++)
		for (y = 0; y < 16; y++)
		{
			if (map[x][y] == 5)
				m++;
		}
	return m;
}
// 按w的時候的輸出結果
int up()
{
	if (map[x][y] == 3) //找到自己的位置
	{
		if (map[x - 1][y] == 0) //判斷下一格子是不是空
		{
			map[x - 1][y] = 3;
			map[x][y] = 0;
		}
		if (map[x - 1][y] == 2 && map[x - 2][y] == 4) /*判斷下一格子是不是箱子,下下個格子是不是箱子要到的地方*/
		{
			map[x][y] = 0;
			map[x - 1][y] = 3;
			map[x - 2][y] = 5;
		}
		if (map[x - 1][y] == 2 && map[x - 2][y] == 0) /*判斷下一格子是不是箱子,下下個格子是不是箱子要到的地方*/
		{
			map[x][y] = 0;
			map[x - 1][y] = 3;
			map[x - 2][y] = 2;
		}
	}
	return 0;
}
//按d的時候的輸出結果
int down()
{
	if (map[x][y] == 3)             //找到自己
	{
		if (map[x + 1][y] == 0)       //判斷下個格子是否空格
		{
			map[x + 1][y] = 3;
			map[x][y] = 0;
		}
		if (map[x + 1][y] == 2 && map[x + 2][y] == 4)  /*判斷下個格子是不是箱子且箱子後面的是不是星星*/
		{
			map[x][y] = 0;
			map[x + 1][y] = 3;
			map[x + 2][y] = 5;
		}
		if (map[x + 1][y] == 2 && map[x + 2][y] == 0)  /*判斷下個格子是不是箱子且箱子後面的是不是星星*/
		{
			map[x][y] = 0;
			map[x + 1][y] = 3;
			map[x + 2][y] = 2;
		}
	}
	return 0;
}
//按a的時候的輸出結果
int left()
{
	if (map[x][y] == 3)
	{
		if (map[x][y - 1] == 0)     //判斷下個格子是否空格
		{
			map[x][y - 1] = 3;
			map[x][y] = 0;
		}
		if (map[x][y - 1] == 2 && map[x][y - 2] == 4)    /*判斷下個格子是不是箱子且箱子後面的是不是星星*/
		{
			map[x][y] = 0;
			map[x][y - 1] = 3;
			map[x][y - 2] = 5;
		}
		if (map[x][y - 1] == 2 && map[x][y - 2] == 0) /*判斷下個格子是不是箱子且箱子後面的格子是不是空格*/
		{
			map[x][y] = 0;
			map[x][y - 1] = 3;
			map[x][y - 2] = 2;
		}
	}
	return 0;
}
//按d的時候的輸出結果
int right()
{
	if (map[x][y] == 3)
	{
		if (map[x][y + 1] == 0)     //判斷下個格子是否空格
		{
			map[x][y + 1] = 3;
			map[x][y] = 0;
		}
		if (map[x][y + 1] == 2 && map[x][y + 2] == 4)/*判斷下個格子是不是箱子且箱子後面的是不是星星*/
		{
			map[x][y] = 0;
			map[x][y + 1] = 3;
			map[x][y + 2] = 5;
		}
		if (map[x][y + 1] == 2 && map[x][y + 2] == 0)/*判斷下個格子是不是箱子且箱子後面的是不是星星*/
		{
			map[x][y] = 0;
			map[x][y + 1] = 3;
			map[x][y + 2] = 2;
		}
	}
	return 0;
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




int main()
{
	system("mode con cols=37 lines=9");
	int n, m;
	system("title 推箱子");    //給一個標題

	memcpy(map, map_1, sizeof(map_1));

	ui();

	_getch();

	system("cls");               //清屏

	n = star();

	while (1)
	{
		system("mode con cols=32 lines=17");
		system("cls");
		output();
		m = startobox();
		find();

		switch (_getch())
		{
		case 'w':up(); break;
		case 's':down(); break;
		case 'a':left(); break;
		case 'd':right(); break;
		case 'r':memcpy(map, map_1, sizeof(map_1)); break;
		}

		if (n == m)
		{
			system("cls");
			printf("*******************************\n"
				"*     PRESS  W  TO   WIN      *\n"
				"*     PRESS  D  TO  DONUTS    *\n"
				"*******************************\n");
			switch (_getch())
			{
			case 'w':system("cls"); Congratulations(); return 0; break;
			case 'd':donuts();
			}
		}
	}

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