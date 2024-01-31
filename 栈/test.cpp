#define _CRT_SECURE_NO_WARNINGS 1
#include"main.h"


//初始化单链表
void StackIint(ST* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->capacity = 0;
	ps->top = 0;
}

//销毁栈
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

//取栈顶数据
STDataType Stacktop(ST* ps)
{
	assert(!StackEmpty(ps));
	return ps->a[ps->top - 1];
}

//有多少数据
int StackSize(ST* ps)
{
	assert(!StackEmpty(ps));
	return ps->top;
}
//判断是否为空
bool StackEmpty(ST* ps)
{
	return ps->top == 0;
}
