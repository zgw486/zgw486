#define _CRT_SECURE_NO_WARNINGS 1
#include"ɨ��.h"



void game()
{
	//��ʼ������;
	char mine[rows][cols] = { 0 };
	//���Ĳ���
	char show[rows][cols] = { 0 };
	initboard(mine, rows, cols, '0');
	initboard(show, rows, cols, '*');

	print(show, row, col);
	//print(mine, row, col);
	setmine(mine, easy);
	//print(mine, row, col);
	findmine(show,mine, row, col);
}

void menu()
{
	printf("###############################\n");
	printf("#####  1.   play     ##########\n");
	printf("#####  2.   exit     ##########\n");
	printf("###############################\n");
}

void test()
{
	int input = 0;
	do
	{
		menu();
		printf("��ѡ��nya~->");
		scanf("%d", &input);
		switch(input)
		{
		case 1:
			printf("----ɨ��-----\n");
			game(); break;
		case 0:
			printf("�˳���Ϸ��~");
			break;
		default:
			printf("ѡ�������~��ѡ��\n");
			break;
		}
	} while (input);
}

int main()
{
	srand((unsigned int)time(NULL));
	test();
	return 0;
}