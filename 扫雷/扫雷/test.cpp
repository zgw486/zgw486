#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include"ɨ��.h"
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
	//��ʼ������
	initboard(mine, rows, cols, '0');//����ȫ����ʼ��Ϊ0
	initboard(show, rows, cols, '*'); //����ȫ����ʼ��Ϊ*
	printf("\n");

	//��ӡ
	print(show, row, col);
	
	//������
	setmine(mine, row, col);
	print(mine, row, col);
	//����
	findmine(mine, show, row, col);
	

}

void test()
{
	int input = 0;
	do
	{
		menu();
		printf("��ѡ��->");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
		{
			printf("------ɨ��------\n");
			game();
			break;
		}
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����,����ѡ����~\n");
			break;
		}

	} while (input);
}

int main(){
	srand((unsigned int)time(NULL));
	test();
	return 0;
}