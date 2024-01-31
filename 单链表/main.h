#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

//单链表的英文  Single linked list

typedef int SLLdatatype;

typedef struct SListNode
{
	SLLdatatype  data;
	struct SListNode*next;
}SLL;


//打印
void SLLprint(SLL* phead);

//尾部存储 
void SLLpushback(SLL**phead,SLLdatatype x);

//头部存储
void SLLpushfront(SLL** phead, SLLdatatype x);

void SLLpushfront2(SLL** phead, SLLdatatype x);


//尾部删除
void SLLpopback(SLL** phead);


//头部删除
void SLLpopfront(SLL** phead);


//查找
void SLL_find_print(SLL* phead, SLLdatatype x);

//查下标
SLL* SLL_findpos(SLL* phead, SLLdatatype x);

//  指定位置插入
void SLL_inset(SLL** phead, SLL* pos, SLLdatatype x);

//指定位置删除
void SLL_pos_del(SLL** phead, SLL* pos);

//销毁链表
void SLL_destory(SLL* *phead);















