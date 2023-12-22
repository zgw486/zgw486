#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<time.h>
#include<stdlib.h>


enum zgw
{
	EXIT,
	PLAY
};

void menu()
{
	printf("############################\n");
	printf("######    1. play     ######\n");
	printf("######    0. exit     ######\n");
	printf("############################\n");
}


void game()
{
	int count = 0;
	int i = rand() % 100 + 1;
	int num = 0;
	while (1)
	{
		printf("请猜数字miao->");
		scanf("%d", &num);
		if (num > i)
		{
			count += 1;
			printf("猜大了喵\n");
		}
		else if (num < i)
		{
			count += 1;
			printf("猜小了喵\n");
		}
		else
		{
			break;
		}
	}
	printf("猜对了喵~,你猜了%d次\n",count+1);
}



void test()
{
	int input = 10;
	do
	{
		menu();
		printf("请选择喵->");
		scanf("%d", &input);
		switch (input)
		{
		case PLAY:
		{
			game();
			break;
		}
		case EXIT:
		{
			printf("退出游戏喵~");
			break;
		}
		default:
		{
			printf("选择错误喵~，重现选择\n");
			break;
		}
		}
	} while (input);
}

int main()
{
	test();
	return 0;
}











