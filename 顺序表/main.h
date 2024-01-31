#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

typedef int SLDataType;

#define N 1000


//���Ա�
typedef struct SeqList
{
	SLDataType*a;
	int size;  //�ж��ٸ�
	int capacity;//����ʵ���ܴ洢�����Ĵ�С
}SL;


//�ӿں���
void SeqListInit(SL* pc);

void SeqListPushback(SL* pc, SLDataType x);

void SeqlistPopback(SL* pc);

void SeqlistPushfront(SL* pc, SLDataType x);

void SeqlistPopfront(SL* pc);

void SeqlistPopfront(SL* pc);

//��������
void Seqlistinsert(SL* pc,int pos,SLDataType x);

//ɾ��ָ������
void Seqlistdelet(SL* pc, SLDataType x);

//ɾ��ָ���±�
void Seqlistdelet(SL* pc, SLDataType x);

//��������()
int Seqlistfind_bydata(SL* pc, SLDataType x);

//�����±�()
void Seqlistfind_bysub(SL* pc, SLDataType);

//��ӡ
void print(SL*pc);

//free
void SeqlistDestory(SL* pc);