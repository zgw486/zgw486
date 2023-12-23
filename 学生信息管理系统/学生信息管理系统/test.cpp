#define _CRT_SECURE_NO_WARNINGS 1
#include"main.h"
//void initgra(gra* pc)
//{
//	pc->size = 0;
//	memset(pc->data, 0, sizeof(pc->data));
//}
void addcp(gra* pc)
{
	if (pc->size == pc->capacity)
	{
		student* ptr = (student*)realloc(pc->data, (pc->capacity + ad) * sizeof(student));
		if (ptr == NULL)
		{
			perror("reallc");
			return;
		}
		else
		{
			pc->data = ptr;
			pc->capacity += 2;
			printf("扩容成功\n");
		}
	}
}


void loadcontact(gra* pc)
{
	FILE* pf = fopen("student.txt", "r");
	if (pf == NULL)
	{
		perror("load");
		return;
	}
	student tmp = { 0 };
	while (fread(&tmp, sizeof(student), 1, pf))
	{
		addcp(pc);
		pc->data[pc->size] = tmp;
		pc->size++;
	}
}

//动态版本
void initgra(gra* pc)
{
	pc->size = 0;
	pc->data = (student*)malloc(st * sizeof(student));
	if (pc == NULL)
	{
		perror("malloc");
		return;
	}
	pc->capacity = st;
}



//char name[max_name];
//char num[max_num];
//int agg;
//char ph[max_ph];
//int core


//静态 
//void addgra(gra* pc)
//{
//	if (pc->size == 1000)
//	{
//		printf("添加失败喵~！内存已满");
//		return;
//	}
//	printf("输入姓名->");
//	scanf("%s", pc->data[pc->size].name);
//	printf("输入学号->");
//	scanf("%s", pc->data[pc->size].num);
//	printf("输入年龄->");
//	scanf("%d", &pc->data[pc->size].agg);
//	printf("输入电话->");
//	scanf("%s", pc->data[pc->size].ph);
//	printf("输入总分->");
//	scanf("%d", &pc->data[pc->size].core);
//	pc->size++;
//	printf("添加成功\n");
//}

//动态
void addgra(gra* pc)
{
	//增容
	if (pc->size == pc->capacity)
	{
		student* ptr = (student*)realloc(pc->data, (pc->capacity + ad) * sizeof(student));
		if (ptr == NULL)
		{
			perror("reallc");
			return;
		}
		else
		{
			pc->data = ptr;
			pc->capacity += 2;
			printf("扩容成功\n");
		}
	}
	printf("输入姓名->");
	scanf("%s", pc->data[pc->size].name);
	printf("输入学号->");
	scanf("%s", pc->data[pc->size].num);
	printf("输入年龄->");
	scanf("%d", &pc->data[pc->size].agg);
	printf("输入电话->");
	scanf("%s", pc->data[pc->size].ph);
	printf("输入总分->");
	scanf("%d", &pc->data[pc->size].core);
	pc->size++;
	printf("添加成功\n");
}




void print(gra* pc)
{
	printf("--打印信息--\n");
	printf("姓名\t\t学号\t\t年龄\t\t电话\t\t\t总分\n");
	int i = 0;
	for (i =0; i < pc->size; i++)
	{
		printf("%-15s %-15s %-15d  %-22s %d\n"
			, pc->data[i].name
			, pc->data[i].num
			, pc->data[i].agg
			, pc->data[i].ph
			, pc->data[i].core);
	}
}


int find_byname(gra*pc,char*pa)
{
	int z = 0;
	int i = 0;
	for (i = 0; i < pc->size; i++)
	{
	  z = strcmp(pc->data[i].name, pa);
	   if (z == 0)
	   {
		return i;
	   }
	}
	return -1;
}


void delgra(gra* pc)
{
	if (pc->size == 0)
	{
		printf("没有删除的学生\n");
		return ;
	}
	char  nam[20];
	printf("请输入学生名字->");
	scanf("%s", nam);
	int i = 0;
	i = find_byname(pc, nam);
	if (i == -1)
	{
		printf("没这人喵~!\n");
	}
	else
	{
		int j = 0;
		for (j = i; j < pc->size; j++)
		{
			pc->data[j] = pc->data[j + 1];
		}
		pc->size--;
		printf("删除成功\n");
	}
}


void searchgra(gra* pc)
{
	char nam[20];
	printf("请输入学生名字->");
	scanf("%s", nam);
	int i = 0;
	i = find_byname(pc, nam);
	if (i == -1)
	{
		printf("没这人喵~\n");
		return;
	}
	else
	{
		printf("姓名\t\t学号\t\t年龄\t\t电话\t\t\t总分\n");
			printf("%-15s %-15s %-15d  %-22s %d\n"
				, pc->data[i].name
				, pc->data[i].num
				, pc->data[i].agg
				, pc->data[i].ph
				, pc->data[i].core);
	}
}

void modeify(gra* pc)
{
	char nam[20] = { 0 };
	printf("请输入学生名字\n");
	scanf("%s", nam);
	int i = find_byname(pc, nam);
	if (i == -1)
	{
		printf("没有该学生信息\n");
	}
	else
	{
		printf("输入姓名->");
		scanf("%s", pc->data[i].name);
		printf("输入学号->");
		scanf("%s", pc->data[i].num);
		printf("输入年龄->");
		scanf("%d", &pc->data[i].agg);
		printf("输入电话->");
		scanf("%s", pc->data[i].ph);
		printf("输入总分->");
		scanf("%d", &pc->data[i].core);
		printf("修改成功\n");
	}
}


void destorygra(gra* pc)
{
	free(pc->data);
	pc->data = NULL;
	pc->size = 0;
	pc->capacity = 0;
}


void writegra(gra* pc)
{
	FILE* pf = fopen("student.txt", "w");
	if (pf == NULL)
	{
		perror("fopen");
		return;
	}
	int i = 0;
	for (i = 0; i < pc->size; i++)
	{
		fwrite(pc->data+i, sizeof(student), 1, pf);
	}
	fclose(pf);
	pf = NULL;
}