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