#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

//�������Ӣ��  Single linked list

typedef int SLLdatatype;

typedef struct SListNode
{
	SLLdatatype  data;
	struct SListNode*next;
}SLL;


//��ӡ
void SLLprint(SLL* phead);

//β���洢 
void SLLpushback(SLL**phead,SLLdatatype x);

//ͷ���洢
void SLLpushfront(SLL** phead, SLLdatatype x);

void SLLpushfront2(SLL** phead, SLLdatatype x);


//β��ɾ��
void SLLpopback(SLL** phead);


//ͷ��ɾ��
void SLLpopfront(SLL** phead);


//����
void SLL_find_print(SLL* phead, SLLdatatype x);

//���±�
SLL* SLL_findpos(SLL* phead, SLLdatatype x);

//  ָ��λ�ò���
void SLL_inset(SLL** phead, SLL* pos, SLLdatatype x);

//ָ��λ��ɾ��
void SLL_pos_del(SLL** phead, SLL* pos);

//��������
void SLL_destory(SLL* *phead);















