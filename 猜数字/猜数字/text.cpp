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
		printf("�������miao->");
		scanf("%d", &num);
		if (num > i)
		{
			count += 1;
			printf("�´�����\n");
		}
		else if (num < i)
		{
			count += 1;
			printf("��С����\n");
		}
		else
		{
			break;
		}
	}
	printf("�¶�����~,�����%d��\n",count+1);
}



void test()
{
	int input = 10;
	do
	{
		menu();
		printf("��ѡ����->");
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
			printf("�˳���Ϸ��~");
			break;
		}
		default:
		{
			printf("ѡ�������~������ѡ��\n");
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











