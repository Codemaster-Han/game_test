//三子棋游戏
//思路：1分析三子棋棋盘的横竖特点：进行棋盘打印；
//2、玩游戏项目开始——电脑操作和玩家操作
//3、游戏胜负判断——玩家赢，电脑赢，平局，棋盘满了但没有胜负

#include "game.h"

void Menu_Game()
{
	printf("************************************************\n");
	printf("****************      1.开始游戏       *********\n");
	printf("****************      0.结束游戏       *********\n");
	printf("************************************************\n");
}

int main()
{
	int n;
	char Checkerboard[ROW][COL] = { 0 };
	srand((int)time(NULL));
	do
	{
		Menu_Game();
		printf("请输入您的选择：\n");
		scanf("%d",&n);

		switch (n)
		{
		case 1:
			Game(Checkerboard, ROW, COL);
			break;
		case 0:
			printf("游戏结束\n");
			break;
		default:
			printf("输入错误，请重新输入\n");
			break;
		}

	} while (n);

	return 0;
}


