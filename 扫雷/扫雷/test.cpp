#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include"扫雷.h"
void menu()
{
	printf("########################\n");
	printf("####   1.  paly  #######\n");
	printf("####   0.  exit  #######\n");
	printf("########################\n");
}

void game()
{
	char mine[rows][cols] = { 0 };
	char show[rows][cols] = { 0 };
	//初始化棋盘
	initboard(mine, rows, cols, '0');//数组全部初始化为0
	initboard(show, rows, cols, '*'); //数组全部初始化为*
	printf("\n");

	//打印
	print(show, row, col);
	
	//布置雷
	setmine(mine, row, col);
	print(mine, row, col);
	//找雷
	findmine(mine, show, row, col);
	

}

void test()
{
	int input = 0;
	do
	{
		menu();
		printf("请选择->");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
		{
			printf("------扫雷------\n");
			game();
			break;
		}
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误,从新选择喵~\n");
			break;
		}

	} while (input);
}

int main(){
	srand((unsigned int)time(NULL));
	test();
	return 0;
}