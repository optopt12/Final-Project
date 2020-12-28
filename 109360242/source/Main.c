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