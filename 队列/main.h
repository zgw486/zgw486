#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>



//  �����Ƚ��ȳ�


typedef int QUDataType;

 typedef struct QueueNode
{
	struct QueueNode* next;
	QUDataType x;
}QueueNode;

typedef struct QUEUE
{
	QueueNode* head;
	QueueNode* tail;
}Queue;

//��ʼ��
void QueueInit(Queue* pq);


//�����
void QueuePush(Queue* pq,QUDataType x);

//������
void QueuePop(Queue* pq);

//ȡͷ����
QUDataType QueueFront(Queue* pq);

//ȡβ����
QUDataType QueueBack(Queue* pq);


//�м�������

int QueueSize(Queue* pq);

//�Ƿ�Ϊ��

bool QueueEmpty(Queue* pq);


//��ӡ
void Print(Queue* pq);