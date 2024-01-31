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


//��ʼ��ջ
void StackIint(ST* ps);

//����ջ
void Stackdestory(ST* pc);

//push
void StackPush(ST* ps, STDataType x);

//pop
void StackPop(ST* ps);

//ȡջ������
STDataType Stacktop(ST* ps);

//�ж�������
int StackSize(ST* ps);

//�ж��Ƿ�Ϊ��
bool StackEmpty(ST* ps);
 
int minStackGetMin(ST* obj);













