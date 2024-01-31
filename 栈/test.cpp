#define _CRT_SECURE_NO_WARNINGS 1
#include"main.h"


//��ʼ��������
void StackIint(ST* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->capacity = 0;
	ps->top = 0;
}

//����ջ
void Stackdestory(ST* pc)
{
	assert(pc);
	free(pc->a);
	pc->a = NULL;
	pc->capacity = pc->top = 0;
}


//push
void StackPush(ST* ps, STDataType x)
{
	assert(ps);
	if (ps->capacity == ps->top)
	{
		ps->capacity =ps->capacity== 0 ? 4 : 2 * ps->capacity;
		STDataType* temp = (STDataType*)realloc(ps->a, sizeof(STDataType) * ps->capacity);
		if (temp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		ps->a = temp;
	}
		ps->a[ps->top] = x;
		ps->top += 1;

}

int minStackGetMin(ST* obj) {
	int i = 0;
	int min = obj->a[i];
	for (i = 1; i<obj->top; i++)
	{
		if (obj->a[i] < min)
		{
			min = obj->a[i];
		}
	}
	return min;
}

//pop
void StackPop(ST* ps)
{
	assert(ps->top > 0);
	ps->top--;
}

//ȡջ������
STDataType Stacktop(ST* ps)
{
	assert(!StackEmpty(ps));
	return ps->a[ps->top - 1];
}

//�ж�������
int StackSize(ST* ps)
{
	assert(!StackEmpty(ps));
	return ps->top;
}
//�ж��Ƿ�Ϊ��
bool StackEmpty(ST* ps)
{
	return ps->top == 0;
}
