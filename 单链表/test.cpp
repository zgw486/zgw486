#define _CRT_SECURE_NO_WARNINGS 1
#include"main.h"



SLL* creatnode( SLLdatatype x)
{
	SLL* newnode = (SLL*)malloc(sizeof(SLL));
	if (newnode == NULL)
	{
		perror("malloc");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}


//打印
void SLLprint(SLL* phead)
{
	/*SLL* cur = phead;*/
	while (phead != NULL)
	{
		printf("%d ", phead->data);
		phead = phead->next;
	}
	printf("->NULL\n");
}


void SLLpushback(SLL**phead,SLLdatatype x)
{
	SLL* newnode = (SLL*)malloc(sizeof(SLL));
	newnode->data = x;
	newnode->next = NULL;
	if (*phead == NULL)
	{
		*phead = newnode;
	}
	else
	{
		SLL* tail = *phead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}
}


void SLLpushfront(SLL** phead, SLLdatatype x)
{
	SLL* newnode = (SLL*)malloc(sizeof(SLL));
	newnode->data = x;
	newnode->next = NULL;
	if (phead == NULL)
	{
		*phead = newnode;
	}
	else
	{
		newnode->next = *phead;
		*phead = newnode;
	}

}

void SLLpushfront2(SLL** phead, SLLdatatype x)
{
	SLL* newnode = creatnode(x);
	newnode->next = *phead;
	*phead = newnode;
}



//尾部删除
void SLLpopback(SLL** phead){
	SLL*tail = *phead;
	SLL* str = NULL;
	if (*phead==NULL)
	{
		return ;
	}
	if (tail->next ==NULL)
	{
		free(tail);
		*phead = NULL;

	}
	else
	{
		while (tail->next!=NULL)
		{
			str = tail;
			tail = tail->next;
		}
		free(tail);
		tail = NULL;
		str->next = NULL;
		
	}
}


//头部删除
void SLLpopfront(SLL** phead)
{
	if (*phead == NULL)
	{
		return;
	}
	if ((*phead)->next == NULL)
	{
		*phead = NULL;
	}
	else
	{
		SLL* front = *phead;
		(*phead)=(*phead)->next;
		free(front);
		front = NULL;
	}
}

//找加打印
void SLL_find_print(SLL* phead, SLLdatatype x)
{
	if (phead == NULL)
	{
		return;
	}
	while (phead->data!=x)
	{
		if (phead->next== NULL)
		{
			break;
		}
		phead = phead->next;
	}
	if (phead->next == NULL)
	{
		printf("找不到喵~\n");
	}
	else
	{
		printf("%d\n", phead->data);
	}
}

//查下标
SLL* SLL_findpos(SLL* phead, SLLdatatype x)
{
	if (phead == NULL)
	{
		return NULL;
	}
	else
	{
		while (phead)
		{
			if (phead->data == x)
			{
				return phead;
			}
			phead = phead->next;

		}
	}
	printf("找不到\n");
	return NULL;
}

//  指定位置插入
void SLL_inset(SLL** phead, SLL* pos, SLLdatatype x)
{
	if (*phead == NULL)
	{
		return;
	}
	else
	{
		SLL* find = *phead;
		while (find)
		{
			if (find->next == pos)
			{
				SLL* newnode = creatnode(x);
				newnode->next = find->next;
				find->next = newnode;
				return;
			}
			find = find->next;
		}
	}
}

//指定位置删除
void SLL_pos_del(SLL** phead, SLL* pos)
{
	if (*phead == NULL)
	{
       		return;
	}
	else
	{
		SLL* find = *phead;
		SLL* findpos = NULL;
		while (find)
		{
			if (find->next == pos)
			{
				findpos = find->next;
				find->next = findpos->next;
				free(findpos);
				findpos = NULL;
				return;
			}
			find = find->next;
		}
	}

}

//销毁链表
void SLL_destory(SLL** phead)
{
	if (*phead == NULL)
	{
		return;
	}
	else
	{   
		while ((*phead)->next!=NULL)
		{
			SLL* tailpos = *phead;
			SLL* tail = NULL;
			while (tailpos->next != NULL)
			{
				tail = tailpos;
				tailpos = tailpos->next;
			}
			free(tailpos);
			tail->next = NULL;
			tailpos = NULL;
		}
		free(*phead);
		*phead = NULL;
	}
}






















