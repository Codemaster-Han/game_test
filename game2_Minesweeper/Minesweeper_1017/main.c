
#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void menu()
{
	printf("****************************\n");
	printf("****     1. play        ****\n");
	printf("****     0. exit        ****\n");
	printf("****************************\n");
}

//0 ������0     '0'��ָ�ַ�0����ASCIIֵΪ48
//��Ϸ�������
void game()
{
	char mine[ROWS][COLS] = { 0 };//�׵���Ϣ
	char show[ROWS][COLS] = { 0 };//��ʾ�Ų�����׵ĸ���
	//��ʼ��
	InitBoard(mine, ROWS, COLS, '0'); //��̨���桪��ɨ�����̽��棬��0��1  0�������ף�1��������
	InitBoard(show, ROWS, COLS, '*'); //��ҽ��桪�������չʾ�����̽���

	Display(show, ROW, COL);//��ʾ���صġ�*������ҽ���
	//������
	SetMine(mine, ROW, COL);
	Display(mine, ROW, COL);//��ʾ1��0���׵ķֲ��������̨���� ����
	//�Ų���
	FindMine(mine, show, ROW, COL);
}


//����������
void Test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����\n");
			break;
		}
	} while (input);
}


//������Ӵ˴���ʼ
int main()
{
	Test();
	return 0;
}