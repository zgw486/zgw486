#define _CRT_SECURE_NO_WARNINGS 1
#include"扫雷.h"



void game()
{
	//初始化棋盘;
	char mine[rows][cols] = { 0 };
	//看的部分
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
		printf("请选择nya~->");
		scanf("%d", &input);
		switch(input)
		{
		case 1:
			printf("----扫雷-----\n");
			game(); break;
		case 0:
			printf("退出游戏喵~");
			break;
		default:
			printf("选择错误喵~重选吧\n");
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