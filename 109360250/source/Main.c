#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <math.h>


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