#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

typedef int SLDataType;

#define N 1000


//线性表
typedef struct SeqList
{
	SLDataType*a;
	int size;  //有多少个
	int capacity;//数据实际能存储容量的大小
}SL;


//接口函数
void SeqListInit(SL* pc);

void SeqListPushback(SL* pc, SLDataType x);

void SeqlistPopback(SL* pc);

void SeqlistPushfront(SL* pc, SLDataType x);

void SeqlistPopfront(SL* pc);

void SeqlistPopfront(SL* pc);

//插入数字
void Seqlistinsert(SL* pc,int pos,SLDataType x);

//删除指定数字
void Seqlistdelet(SL* pc, SLDataType x);

//删除指定下标
void Seqlistdelet(SL* pc, SLDataType x);

//查找数字()
int Seqlistfind_bydata(SL* pc, SLDataType x);

//查找下标()
void Seqlistfind_bysub(SL* pc, SLDataType);

//打印
void print(SL*pc);

//free
void SeqlistDestory(SL* pc);