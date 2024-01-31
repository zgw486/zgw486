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


//���տռ�
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

	//���û�пռ�����û�о����ݣ�
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
		printf("û������~\n");
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
		printf("ûuɾ����Ԫ����~\n");
	}
	int i = 1;
	for (i = i; i <= pc->size+1; i++)
	{
		pc->a[i - 1] = pc->a[i];
	}
	pc->size -= 1;
}

//��������
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

//��������()
int  Seqlistfind_bydata(SL* pc, SLDataType x)
{
	int i = 0;
	for (i; i < pc->size; i++)
	{
		if (pc->a[i] == x)
		{
			printf("���ص�һ���±�\n");
			return  i;
		}
	}
	printf("�Ҳ���\n");
	return -1;
}


//ɾ��ָ������ 
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
			printf("û�������Ŷ\n");
			return;
}

