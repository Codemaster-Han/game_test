//��������Ϸ
//˼·��1�������������̵ĺ����ص㣺�������̴�ӡ��
//2������Ϸ��Ŀ��ʼ�������Բ�������Ҳ���
//3����Ϸʤ���жϡ������Ӯ������Ӯ��ƽ�֣��������˵�û��ʤ��

#include "game.h"

void Menu_Game()
{
	printf("************************************************\n");
	printf("****************      1.��ʼ��Ϸ       *********\n");
	printf("****************      0.������Ϸ       *********\n");
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
		printf("����������ѡ��\n");
		scanf("%d",&n);

		switch (n)
		{
		case 1:
			Game(Checkerboard, ROW, COL);
			break;
		case 0:
			printf("��Ϸ����\n");
			break;
		default:
			printf("�����������������\n");
			break;
		}

	} while (n);

	return 0;
}


