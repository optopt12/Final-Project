#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <math.h>


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