#define _CRT_SECURE_NO_WARNINGS 1
#include"main.h"


void test1()
{
	ST ad;
	StackIint(&ad);
	StackPush(&ad, 1);
	StackPush(&ad, 2);
	printf("有这么多个元素%d\n", StackSize(&ad));
	StackPush(&ad, 3);
	printf("%d\n", minStackGetMin(&ad));
	StackPush(&ad, 4);
	while (!StackEmpty(&ad))
	{
		printf("%d ", Stacktop(&ad));
		StackPop(&ad);
	}
	StackIint(&ad);
}


int main()
{
	test1();
	int i = 0;
	return 0;
}