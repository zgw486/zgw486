#define _CRT_SECURE_NO_WARNINGS 1
#include"main.h"


void Checkcapacity(SL* pc)
{
	if (pc->size == pc->capacity)
	{
		int newcapacity = pc->capacity == 0 ? 4 : pc->capacity * 2;
		SLDataType* str = (SLDataType*)realloc(pc->a, newcapacity * sizeof(SLDataType));
		if (str == NULL)
		{
			perror("realloc");
			exit(-1);
		}
	}
}

void print(SL* pc)
{
	int i = 0;
	for (i = 0; i < pc->size; i++)
	{
		printf("%d ", pc->a[i]);
	}
}


//回收空间
void SeqlistDestory(SL* pc)
{
	free(pc->a);
	pc->a = NULL;
	pc->capacity = pc->size = 0;
}



void SeqListInit(SL* pc)
{
	pc->a = NULL;
	pc->size = 0;
	pc->capacity = 0;
}

void SeqListPushback(SL* pc, SLDataType x)
{

	//如果没有空间或根本没有就增容：
	if (pc->size == pc->capacity)
	{
		int newcapacity = pc->capacity == 0 ? 4 : pc->capacity * 2;
		SLDataType* str = (SLDataType*)realloc(pc->a,newcapacity*sizeof(SLDataType));
		if (str == NULL)
		{
			perror("realloc");
			exit(-1);
		}
		pc->a = str;
		str = NULL;
		pc->capacity = newcapacity;
	}
	pc->a[pc->size] = x;
	pc->size++;
}



void SeqlistPopback(SL* pc)
{
	if (pc->size == 0)
	{
		printf("没有了喵~\n");
		return;
	}
	pc->a[pc->size - 1] = 0;
	pc->size--;
}

void SeqlistPushfront(SL* pc, SLDataType x)
{
	if (pc->size == pc->capacity)
	{
		int newcapacity = pc->capacity == 0 ? 4 : pc->capacity * 2;
		SLDataType* str = (SLDataType*)realloc(pc->a, newcapacity * sizeof(SLDataType));
		if (str == NULL)
		{
			perror("realloc");
			exit(-1);
		}
		pc->a = str;
		str = NULL;
		pc->capacity = newcapacity;
	}
	pc->size += 1;
	for (int i = pc->size; i>=0; i--)
	{
		pc->a[i+1] = pc->a[i];
	}
	pc->a[0]=x;
}

void SeqlistPopfront(SL* pc)
{
	if (pc->size == 0)
	{
		printf("没u删除的元素喵~\n");
	}
	int i = 1;
	for (i = i; i <= pc->size+1; i++)
	{
		pc->a[i - 1] = pc->a[i];
	}
	pc->size -= 1;
}

//插入数字
void Seqlistinsert(SL* pc, int pos, SLDataType x)
{
	Checkcapacity(pc);
	pc->size += 1;
	int i=pos;
	for (i = pos; i < pc->size; i++)
	{
		pc->a[i] = pc->a[i - 1];
	}
	pc->a[pos - 1] = x;
}

//查找数字()
int  Seqlistfind_bydata(SL* pc, SLDataType x)
{
	int i = 0;
	for (i; i < pc->size; i++)
	{
		if (pc->a[i] == x)
		{
			printf("返回第一个下标\n");
			return  i;
		}
	}
	printf("找不到\n");
	return -1;
}


//删除指定数字 
void Seqlistdelet(SL* pc, SLDataType x)
{
	int i = 0;
	for (i = 0; i < pc->size; i++)
	{
		if (x == pc->a[i])
		{
			for (i; i < pc->size; i++)
			{
				pc->a[i] = pc->a[i + 1];
       	    }
			pc->size--;
			break;
		}
	
	}
			printf("没这个数字哦\n");
			return;
}

