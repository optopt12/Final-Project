#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <math.h>

int x, y;
int map[16][16] = { 0 };
int stars();     // �P�P���Ӽ�
int startobox();    // �c�l��F�P�P����m���Ӽ�

int up();
int down();
int left();
int right();

int output();
int find();          //���ۤv
int ui();    //��X�D�ɭ�
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
				printf("��"); //��X�j�����ˤl
			if (map[x][y] == 3)
				printf("��"); //��X�ۤv����m
			if (map[x][y] == 2)
				printf("��"); //��X�c�l
			if (map[x][y] == 4)
				printf("��"); //��X�c�l�n�쪺��m
			if (map[x][y] == 0)
				printf("  "); //��X�ť�
			if (map[x][y] == 5)
				printf("��"); //��X�c�l��F�Ө쪺��m
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
		"*     �C���e�иԲӾ\Ū���}������    *\n"
		"*        �Ы�WASD����W�U���k       *\n"
		"*         �Ы�R���s�}�l�C��         *\n"
		"*      **�ШϥΤp�g�^��C��**     *\n"
		"*                                   *\n"
		"*         �Ы����N��}�l�C��        *\n"
		"*************************************\n");
}
//�P�P���Ӽ�
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
//�c�l��F��m���Ӽ�
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
// ��w���ɭԪ���X���G
int up()
{
	if (map[x][y] == 3) //���ۤv����m
	{
		if (map[x - 1][y] == 0) //�P�_�U�@��l�O���O��
		{
			map[x - 1][y] = 3;
			map[x][y] = 0;
		}
		if (map[x - 1][y] == 2 && map[x - 2][y] == 4) /*�P�_�U�@��l�O���O�c�l,�U�U�Ӯ�l�O���O�c�l�n�쪺�a��*/
		{
			map[x][y] = 0;
			map[x - 1][y] = 3;
			map[x - 2][y] = 5;
		}
		if (map[x - 1][y] == 2 && map[x - 2][y] == 0) /*�P�_�U�@��l�O���O�c�l,�U�U�Ӯ�l�O���O�c�l�n�쪺�a��*/
		{
			map[x][y] = 0;
			map[x - 1][y] = 3;
			map[x - 2][y] = 2;
		}
	}
	return 0;
}
//��d���ɭԪ���X���G
int down()
{
	if (map[x][y] == 3)             //���ۤv
	{
		if (map[x + 1][y] == 0)       //�P�_�U�Ӯ�l�O�_�Ů�
		{
			map[x + 1][y] = 3;
			map[x][y] = 0;
		}
		if (map[x + 1][y] == 2 && map[x + 2][y] == 4)  /*�P�_�U�Ӯ�l�O���O�c�l�B�c�l�᭱���O���O�P�P*/
		{
			map[x][y] = 0;
			map[x + 1][y] = 3;
			map[x + 2][y] = 5;
		}
		if (map[x + 1][y] == 2 && map[x + 2][y] == 0)  /*�P�_�U�Ӯ�l�O���O�c�l�B�c�l�᭱���O���O�P�P*/
		{
			map[x][y] = 0;
			map[x + 1][y] = 3;
			map[x + 2][y] = 2;
		}
	}
	return 0;
}
//��a���ɭԪ���X���G
int left()
{
	if (map[x][y] == 3)
	{
		if (map[x][y - 1] == 0)     //�P�_�U�Ӯ�l�O�_�Ů�
		{
			map[x][y - 1] = 3;
			map[x][y] = 0;
		}
		if (map[x][y - 1] == 2 && map[x][y - 2] == 4)    /*�P�_�U�Ӯ�l�O���O�c�l�B�c�l�᭱���O���O�P�P*/
		{
			map[x][y] = 0;
			map[x][y - 1] = 3;
			map[x][y - 2] = 5;
		}
		if (map[x][y - 1] == 2 && map[x][y - 2] == 0) /*�P�_�U�Ӯ�l�O���O�c�l�B�c�l�᭱����l�O���O�Ů�*/
		{
			map[x][y] = 0;
			map[x][y - 1] = 3;
			map[x][y - 2] = 2;
		}
	}
	return 0;
}
//��d���ɭԪ���X���G
int right()
{
	if (map[x][y] == 3)
	{
		if (map[x][y + 1] == 0)     //�P�_�U�Ӯ�l�O�_�Ů�
		{
			map[x][y + 1] = 3;
			map[x][y] = 0;
		}
		if (map[x][y + 1] == 2 && map[x][y + 2] == 4)/*�P�_�U�Ӯ�l�O���O�c�l�B�c�l�᭱���O���O�P�P*/
		{
			map[x][y] = 0;
			map[x][y + 1] = 3;
			map[x][y + 2] = 5;
		}
		if (map[x][y + 1] == 2 && map[x][y + 2] == 0)/*�P�_�U�Ӯ�l�O���O�c�l�B�c�l�᭱���O���O�P�P*/
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
		"       ������������������������������������������������������������������    ��������������������������������������������������������������������\n"
		"       ������������������������������������������������������������������������������������������������������������������������������������������  \n"
		"       ������������������������������������������������������������������������������������������������������������������������������������������\n"
		"       ������������������������������������������������������������������    ��������������������������������������������������������������������\n");
	return 0;
}




int main()
{
	system("mode con cols=37 lines=9");
	int n, m;
	system("title ���c�l");    //���@�Ӽ��D

	memcpy(map, map_1, sizeof(map_1));

	ui();

	_getch();

	system("cls");               //�M��

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