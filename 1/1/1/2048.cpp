// 1.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <windows.h>
#define left 37
#define up 38
#define right 39
#define down 40
int a[4][4] = { 0 };
void map();
void putNum();
void Move(int direction);
int canMove(int direction);
int main()
{
	int i, j;
	putNum();
	putNum();
	while (1)
	{
		printf("Press '↑↓←→' for direction\n");
		int direction;
		map();
		system("pause");
		if (!canMove(up) && !canMove(right) && !canMove(left) && !canMove(down))
		{
			printf("You lose!!!\n");
			break;
		}
		if (GetKeyState(left) < 0)
		{
			direction = left;
			if (canMove(direction) > 0)
			{
				Move(direction);
				putNum();
			}
			else
			{
				system("cls");
				continue;
			}
		}
		if (GetKeyState(up) < 0)
		{
			direction = up;
			if (canMove(direction) > 0)
			{
				Move(direction);
				putNum();
			}
			else
			{
				system("cls");
				continue;
			}
		}
		if (GetKeyState(right) < 0)
		{
			direction = right;
			if (canMove(direction) > 0)
			{
				Move(direction);
				putNum();
			}
			else
			{
				system("cls");
				continue;
			}
		}
		if (GetKeyState(down) < 0)
		{
			direction = down;
			if (canMove(direction) > 0)
			{
				Move(direction);
				putNum();
			}
			else
			{
				system("cls");
				continue;
			}
		}
		system("cls");
		for (i = 0; i < 4; i++)
		{
			for (j = 0; j < 4; j++)
				if (a[i][j] == 2048)
				{
					printf("You win!!!");
					break;
				}
		}
	}
	return 0;
}
int canMove(int direction)
{
	int i, j;
	switch (direction)
	{
	case up:
		for (i = 0; i < 4; i++) 
		{
			for (j = 3; j > 0; j--)
				if (a[j][i] && a[j][i] == a[j - 1][i])
					return 1;
		}
		break;
	case down:
		for (i = 0; i < 4; i++) 
		{
			for (j = 0; j < 3; j++)
				if (a[j][i] && a[j][i] == a[j + 1][i])
					return 1;
		}
		break;
	case left:
		for (i = 0; i < 4; i++) 
		{
			for (j = 0; j < 3; j++)
				if (a[i][j] != 0 && a[i][j] == a[i][j + 1])
					return 1;
		}
		break;
	case right:
		for (i = 0; i < 4; i++) 
		{
			for (j = 0; j < 3; j++)
				if (a[i][j] != 0 && a[i][j] == a[i][j + 1])
					return 1;
		}
		break;
	}
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
			if (!a[i][j])
				return 2;
	}
	return 0;
}
void Move(int direction)
{
	int i, j;
	switch (direction)
	{
	case up:
		for (i = 2; i > -1; i--)
		{
			for (j = 0; j < 4; j++)
				if (!a[i][j])
				{
					a[i][j] = a[i + 1][j];
					a[i + 1][j] = 0;
				}
				else
				{
					if (a[i][j] == a[i + 1][j])
					{
						a[i][j] = 2 * a[i][j];
						a[i + 1][j] = 0;
					}
				}
		}
		break;
	case down:
		for (i = 1; i < 4; i++)
		{
			for (j = 0; j < 4; j++)
				if (!a[i][j])
				{
					a[i][j] = a[i - 1][j];
					a[i - 1][j] = 0;
				}
				else
				{
					if (a[i][j] == a[i - 1][j])
					{
						a[i][j] = 2 * a[i][j];
						a[i - 1][j] = 0;
					}
				}
		}
		break;
	case left:
		for (i = 0; i < 4; i++)
		{
			for (j = 2; j > -1; j--)
				if (!a[i][j])
				{
					a[i][j] = a[i][j + 1];
					a[i][j + 1] = 0;
				}
				else
				{
					if (a[i][j] == a[i][j + 1])
					{
						a[i][j] = 2 * a[i][j];
						a[i][j + 1] = 0;
					}
				}
		}
		break;
	case right:
		for (i = 0; i < 4; i++)
		{
			for (j = 1; j < 4; j++)
				if (!a[i][j])
				{
					a[i][j] = a[i][j - 1];
					a[i][j - 1] = 0;
				}
				else
				{
					if (a[i][j] == a[i][j - 1])
					{
						a[i][j] = 2 * a[i][j];
						a[i][j - 1] = 0;
					}
				}
		}
		break;
	}
}
void putNum()
{
	int *p, *temp[16] = { 0 };
	int count = 0, i, j;
	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
			if (a[i][j] == 0)
			{
				temp[count] = &a[i][j];
				count++;
			}
	if (count)
	{
		p = temp[rand() % count];
		*p = rand() % 2 ? 2 : 4;
	}
}
void map() 
{
	int i, j;
	printf("*-------*-------*-------*-------*\n");
	for (i = 0; i<4; i++) {
		printf("|");
		for (j = 0; j<4; j++) {
			a[i][j] ? printf("%d", a[i][j]) : printf(" ");
			printf("\t|");
			if (j>2)
				printf("\n");
		}
		printf("*-------*-------*-------*-------*\n");
	}
}