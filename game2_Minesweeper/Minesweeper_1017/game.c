#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"
//初始化扫雷棋盘界面
void InitBoard(char  board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i<rows; i++)
	{
		for (j = 0; j<cols; j++)
		{
			board[i][j] = set;
		}
	}
}
//显示扫雷棋盘
void Display(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i <= col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
//随机“布雷”
void SetMine(char board[ROWS][COLS], int row, int col)
{
	int count = EASY_COUNT;
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}
//统计这个排雷坐标附近还有几个雷，然后进行显示
int GetMineCount(char board[ROWS][COLS], int x, int y)
{
	return board[x - 1][y] +
		board[x - 1][y - 1] +
		board[x][y - 1] +
		board[x + 1][y - 1] +
		board[x + 1][y] +
		board[x + 1][y + 1] +
		board[x][y + 1] +
		board[x - 1][y + 1] - 8 * '0';
}

 //排雷
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;
	while (win<row*col - EASY_COUNT)
	{
		printf("请输入排查的坐标:>");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("很遗憾，你被炸死了\n");
				Display(mine, row, col);
				break;
			}
			else
			{
				int count = GetMineCount(mine, x, y);//获得这个坐标附近还有几个雷的个数
				show[x][y] = count + '0';
				Display(show, row, col);
				win++;
			}
		}
		else
		{
			printf("坐标非法,请重新输入!\n");
		}
	}
	if (win == row*col - EASY_COUNT)
	{
		printf("恭喜你， 排雷成功\n");
		Display(mine, row, col);
	}
}

