#define _CRT_SECURE_NO_WARNINGS 1
#include"main.h"

void test()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePop(&q);
	QueuePop(&q);
	QueuePop(&q);
	QueuePop(&q);
	int z = QueueEmpty(&q);
	printf("%d\n", z);
	z = QueueSize(&q);
	printf("%d\n", z);
}


int main()
{
	test();
	return 0;
}