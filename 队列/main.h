#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>



//  队列先进先出


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

//初始化
void QueueInit(Queue* pq);


//入队列
void QueuePush(Queue* pq,QUDataType x);

//出队列
void QueuePop(Queue* pq);

//取头数据
QUDataType QueueFront(Queue* pq);

//取尾数据
QUDataType QueueBack(Queue* pq);


//有几个数据

int QueueSize(Queue* pq);

//是否为空

bool QueueEmpty(Queue* pq);


//打印
void Print(Queue* pq);