#define _CRT_SECURE_NO_WARNINGS 1
#include"main.h"



void TestSqlist1()
{
	SL s1;
	SeqListInit(&s1);
	SeqListPushback(&s1, 1);
	SeqListPushback(&s1, 2);
	SeqListPushback(&s1, 3);
	SeqListPushback(&s1, 4);
	SeqListPushback(&s1, 5);
	print(&s1);
	printf("\n");
	SeqlistPushfront(&s1, 10);
	SeqlistPushfront(&s1, 20);
	SeqlistPushfront(&s1, 30);
	SeqlistPushfront(&s1, 40);
	print(&s1);
	printf("\n");
	SeqlistPopfront(&s1);
	print(&s1);
	printf("\n");
	Seqlistinsert(&s1,1, 10);
	print(&s1);
	printf("\n");
	Seqlistdelet(&s1, 30);
	Seqlistdelet(&s1, 10);
	print(&s1);
	printf("\n");
	int i=Seqlistfind_bydata(&s1, 30);
	printf("%d  %d", i ,s1.a[i]);
	SeqlistDestory(&s1);
}

int main()
{
	TestSqlist1();
	return 0;
}