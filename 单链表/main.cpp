#define _CRT_SECURE_NO_WARNINGS 1

#include"main.h"

void menu()
{
	printf("###############################\n");
	printf("######  1.print           #####\n");
	printf("###############################\n");
	printf("###############################\n");
	printf("######      0.   exit     #####\n");
	printf("###############################\n");
}

enum zgwd
{
	EXIT,
	PRINT
};


void testpushback()
{
	SLL* plist = NULL;
	SLLpushback(&plist,1);
	SLLprint(plist);
	SLLpushfront(&plist,2);
	SLLpushfront(&plist,3);
	SLLpushfront(&plist,4);
	SLL_find_print(plist, 400);
	SLLpushfront2(&plist, 100);
	SLLprint(plist);
	SLL*pos=SLL_findpos(plist, 1);
	SLL_inset(&plist, pos, 2);
	SLLprint(plist);
	SLL_pos_del(&plist, pos);
	SLLprint(plist);
	SLLpopfront(&plist);
	SLL_destory(&plist);
	SLLprint(plist);
}



void test()
{
	int input = 10;
	do
	{
	    menu();
		printf("请选择喵~\n");
		scanf("%d", &input);
		switch (input)
		{
		case PRINT :
		{
			 break;
		}
		default:
		{
			printf("选择错误喵~，重新选择\n");
			break;
		}
		}


	} while (input);
}


int main()
{
	/*test();*/
	testpushback();
	return 0;
}