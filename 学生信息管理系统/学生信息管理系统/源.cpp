#define _CRT_SECURE_NO_WARNINGS 1
#include"main.h"

void menu()
{
	printf("###################################\n");
	printf("######  1.add    2.del     ########\n");
	printf("######  3.search 4.modeify ########\n");
	printf("######  5.sort   6.print   ########\n");
	printf("######        0.exit       ########\n");
	printf("###################################\n");
}

enum optirns
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODEIFY,
	SORT,
	PRINT
};

void test()
{
     
	gra contact;
	initgra(&contact);
	loadcontact(&contact);
	int input = 10;
	while (input)
	{
		menu();
		printf("��ѡ����~\n");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
		{
			addgra(&contact);
			break;
		}
		case DEL:
		{
			delgra(&contact);
			break;
		}
		case SEARCH:
		{
			searchgra(&contact);
			break;
		}
		case MODEIFY:
		{
			modeify(&contact);
			break;
		}
		case SORT:
		{
			break;
		}
		case PRINT:
		{
			print(&contact);
			break;
		}
		case EXIT:
		{
			writegra(&contact);
			destorygra(&contact);
			printf("����ɹ�");
			printf("�˳�������~");
			break;
		}
		default:
			printf("ѡ�����,����ѡ��please��~\n");
			break;
		}
	}
}


int main()
{
	test();
	return 0;
}