#pragma once
#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int  STDataType;

typedef struct Stack
{
	STDataType* a;
	int top;
	int capacity;
}ST;


//初始化栈
void StackIint(ST* ps);

//销毁栈
void Stackdestory(ST* pc);

//push
void StackPush(ST* ps, STDataType x);

//pop
void StackPop(ST* ps);

//取栈顶数据
STDataType Stacktop(ST* ps);

//有多少数据
int StackSize(ST* ps);

//判断是否为空
bool StackEmpty(ST* ps);
 
int minStackGetMin(ST* obj);













