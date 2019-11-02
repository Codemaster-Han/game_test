
#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void menu()
{
	printf("****************************\n");
	printf("****     1. play        ****\n");
	printf("****     0. exit        ****\n");
	printf("****************************\n");
}

//0 是数字0     '0'是指字符0，其ASCII值为48
//游戏初步框架
void game()
{
	char mine[ROWS][COLS] = { 0 };//雷的信息
	char show[ROWS][COLS] = { 0 };//显示排查出的雷的个数
	//初始化
	InitBoard(mine, ROWS, COLS, '0'); //后台界面——扫雷棋盘界面，有0和1  0代表不是雷，1代表是雷
	InitBoard(show, ROWS, COLS, '*'); //玩家界面——向玩家展示的棋盘界面

	Display(show, ROW, COL);//显示神秘的“*”，玩家界面
	//布置雷
	SetMine(mine, ROW, COL);
	Display(mine, ROW, COL);//显示1和0，雷的分布情况，后台界面 隐性
	//排查雷
	FindMine(mine, show, ROW, COL);
}


//程序初步框架
void Test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误\n");
			break;
		}
	} while (input);
}


//主程序从此处开始
int main()
{
	Test();
	return 0;
}