#define ROW 3 //行数
#define COL 3//列数

#include "game.h"
#include <stdlib.h> 
#include <time.h> //随机数头文件

//初始化棋盘，使得棋盘置空
void Init_Checkerboard(char Checkerboard[ROW][COL], int row, int col)
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			Checkerboard[i][j] = ' ';
		}
	}
}

//显示棋盘网格虚线
void Show_Checkerboard(char Checkerboard[ROW][COL], int row, int col)
{
	int i, j;
	for (i = 0; i < row; i++)
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c ", Checkerboard[i][j]);
			if (j != col - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		for (j = 0; j < col; j++)
		{
			printf("---");
			if (j != col - 1)
			{
				printf("|");
			}
		}
		printf("\n");
	}
}
//玩家玩游戏
//棋子为“*”
void Player_Move(char Checkerboard[ROW][COL], int row, int col)
{
	int x, y;
	while (1)
	{
		printf("请输入您要下的位置（格式为）:数字+空格+数字\n");
		scanf("%d%d", &x,&y);
		if (x > 0 && x <= ROW && y > 0 && y <= COL)
		{

			if (Checkerboard[x - 1][y - 1] == ' ')
			{
				Checkerboard[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("该坐标已被输入\n");
			}
		}
		else
		{
			printf("输入错误，请重新输入\n");
		}
	}

}
//电脑玩游戏
//棋子为“#”
void Computer_Move(char Checkerboard[ROW][COL], int row, int col)
{
	int x, y;
	while (1)
	{
		x = rand() % ROW;
		y = rand() % COL;
		if (Checkerboard[x][y] == ' ')
		{
			Checkerboard[x][y] = '#';
			break;
		}
	}
}
//判断棋盘是否已满
char Full_Checkerboard(char Checkerboard[ROW][COL], int row, int col)
{
	int i, j;
	for (i = 0; i < row; i++)
	for (j = 0; j < col; j++)
	if (Checkerboard[i][j] == ' ')//判断位置是否为空
		return 'N';
	return 'F';
}
//判断游戏胜负——平局，玩家赢，电脑赢
char Win_Game(char Checkerboard[ROW][COL], int row, int col)
{
	int i, j, flag = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col - 1; j++)
		{
			if ((Checkerboard[i][j] == Checkerboard[i][j + 1]) && (Checkerboard[i][j] != ' '))
			{
				flag++;
			}
			else if (flag == CHESS_NUMBER - 1)
				return Checkerboard[i][j];
			else
			{
				flag = 0;
			}
		}
	}
	//判断行是否三子

	for (i = 0; i < row - 1; i++)
	{
		for (j = 0; j < col; j++)
		{
			if ((Checkerboard[i][j] == Checkerboard[i + 1][j]) && (Checkerboard[i][j] != ' '))
			{
				flag++;
			}
			else
			{
				flag = 0;
			}
			if (flag == CHESS_NUMBER - 1)
				return Checkerboard[i][j];
		}
	}
	//判断列是否三子 

	flag = 0;
	for (i = 0, j = 0; i < row - 1, j < col - 1; i++, j++)
	{
		if ((Checkerboard[i][j] == Checkerboard[i + 1][j + 1]) && (Checkerboard[i][j] != ' '))
		{
			flag++;
		}
		else
		{
			flag = 0;
		}
		if (flag == CHESS_NUMBER - 1)
			return Checkerboard[i][j];
	}
	//判断左对角线是否三子

	flag = 0;
	for (i = 0, j = row - 1; i < row - 1, j>0; i++, j--)
	{
		if ((Checkerboard[i][j] == Checkerboard[i + 1][j - 1]) && (Checkerboard[i][j] != ' '))
		{
			flag++;
		}
		else
		{
			flag = 0;
		}
		if (flag == CHESS_NUMBER - 1)
			return Checkerboard[i][j];
	}
	//判断右对角线是否三子

	if (Full_Checkerboard(Checkerboard, ROW, COL) == 'F')
		return 'F';
	//判断棋盘是否下满

	return 'N';
}
//游戏测试
void Game(char Checkerboard[ROW][COL], int row, int col)
{
	char flag = 'N';
	srand((unsigned int)time(NULL));
	//设置随机数 
	Init_Checkerboard(Checkerboard, ROW, COL);
	Show_Checkerboard(Checkerboard, ROW, COL);
	while (1)
	{
		printf("玩家请下棋\n");
		Player_Move(Checkerboard, ROW, COL);
		Show_Checkerboard(Checkerboard, ROW, COL);
		if ((flag = Win_Game(Checkerboard, ROW, COL)) != 'N')
			break;

		printf("电脑请下棋\n");
		Computer_Move(Checkerboard, ROW, COL);
		Show_Checkerboard(Checkerboard, ROW, COL);
		if ((flag = Win_Game(Checkerboard, ROW, COL)) != 'N')
			break;
	}
	if (flag == '*')
	{
		printf("\n恭喜你，玩家获胜\n");
	}
	else if (flag == '#')
	{
		printf("\n很遗憾：电脑获胜\n");
	}
	else if (flag == 'F')
	{
		printf("\n棋盘已满，平局\n");
	}
	printf("\n\n");
}





