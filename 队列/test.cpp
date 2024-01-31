#define _CRT_SECURE_NO_WARNINGS 1
#include"main.h"

//初始化
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->head = NULL;
	pq->tail = NULL;
}

void QueueDestory(Queue* pq)
{
	assert(pq);
	QueueNode* cur = pq->head;
	while (cur!=NULL)
	{
		QueueNode* next = cur->next;
		free(cur);
		cur = next;
	}
	pq->head = NULL;
	pq->tail = NULL;

}

//入队列
void QueuePush(Queue* pq, QUDataType x)
{
	assert(pq);
	if (pq->head == NULL && pq->tail == NULL)
	{
		QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
		newnode->x = x;
		newnode->next = NULL;
		pq->head=newnode;
		pq->tail=newnode;
	}
	else
	{
		QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
		newnode->x = x;
		newnode->next = NULL;
		QueueNode* tail1 = NULL;
		tail1 = pq->tail;
		tail1->next = newnode;
		pq->tail = newnode;
	}
}

//出队列
void QueuePop(Queue* pq)
{
	assert(pq);
	if (pq->head ==NULL)
	{
		exit(-1);
	}
	QueueNode* head1 = pq->head->next;
	free(pq->head);
	pq->head = head1;
	if (pq->head == NULL)
	{
		pq->head = pq->tail = NULL;
	}
}

//取头数据
QUDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(pq->head);
	return pq->head->x;
}

//取尾数据
QUDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(pq->head);
	return pq->tail->x;
}

//有几个数据

int QueueSize(Queue* pq)
{
	assert(pq);
	int count = 0;
	QueueNode*pos = pq->head;
	while (pos != NULL)
	{
		count += 1;
		pos = pos->next;
	}
	return count;
}

//是否为空
bool QueueEmpty(Queue* pq)
{
	assert(pq);
	if (pq->head)
	{
		return false;
	}
	return true;
}

//打印
void Print(Queue* pq)
{
	assert(pq);
	assert(pq->head);
	QueueNode* pos = pq->head;
	while (pos != NULL)
	{
		printf("%d ", pos->x);
		pos = pos->next;
	}
 	printf("\n");
}                                        

typedef struct {
	Queue* q1;
	Queue* q2;
} MyStack;


MyStack* myStackCreate() {
	MyStack* st = (MyStack*)malloc(sizeof(MyStack));
	st->q1 = (QUEUE*)malloc(sizeof(QUEUE));
	st->q2 = (QUEUE*)malloc(sizeof(QUEUE));
	return st;
}

void myStackPush(MyStack* obj, int x) {
	if (!QueueEmpty(obj->q1))
	{
		QueuePush(obj->q1, x);
	}
	else
	{
		QueuePush(obj->q2, x);
	}
}

int myStackPop(MyStack* obj) {
	Queue* empty = obj->q1;
	Queue* noempty = obj->q2;
	if (!QueueEmpty(obj->q1))
	{
		empty = obj->q2;
		noempty = obj->q1;
	}
	int top = QueueBack(noempty);
	while (QueueSize(noempty) > 0)
	{
		QueuePush(empty, QueueFront(noempty));
		QueuePop(noempty);
	}
	return top;

}

int myStackTop(MyStack* obj) {
	if (!QueueEmpty(obj->q1))
	{
		return QueueBack(obj->q1);
	}
	return QueueBack(obj->q2);
}

bool myStackEmpty(MyStack* obj) {
	if (QueueEmpty(obj->q1) || QueueEmpty(obj->q2))
	{
		return false;
	}
	return true;

}

void myStackFree(MyStack* obj) {
	free(obj->q1);
	free(obj->q2);
	free(obj);
}