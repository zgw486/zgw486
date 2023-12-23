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
			printf("���ݳɹ�\n");
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

//��̬�汾
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


//��̬ 
//void addgra(gra* pc)
//{
//	if (pc->size == 1000)
//	{
//		printf("���ʧ����~���ڴ�����");
//		return;
//	}
//	printf("��������->");
//	scanf("%s", pc->data[pc->size].name);
//	printf("����ѧ��->");
//	scanf("%s", pc->data[pc->size].num);
//	printf("��������->");
//	scanf("%d", &pc->data[pc->size].agg);
//	printf("����绰->");
//	scanf("%s", pc->data[pc->size].ph);
//	printf("�����ܷ�->");
//	scanf("%d", &pc->data[pc->size].core);
//	pc->size++;
//	printf("��ӳɹ�\n");
//}

//��̬
void addgra(gra* pc)
{
	//����
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
			printf("���ݳɹ�\n");
		}
	}
	printf("��������->");
	scanf("%s", pc->data[pc->size].name);
	printf("����ѧ��->");
	scanf("%s", pc->data[pc->size].num);
	printf("��������->");
	scanf("%d", &pc->data[pc->size].agg);
	printf("����绰->");
	scanf("%s", pc->data[pc->size].ph);
	printf("�����ܷ�->");
	scanf("%d", &pc->data[pc->size].core);
	pc->size++;
	printf("��ӳɹ�\n");
}




void print(gra* pc)
{
	printf("--��ӡ��Ϣ--\n");
	printf("����\t\tѧ��\t\t����\t\t�绰\t\t\t�ܷ�\n");
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
		printf("û��ɾ����ѧ��\n");
		return ;
	}
	char  nam[20];
	printf("������ѧ������->");
	scanf("%s", nam);
	int i = 0;
	i = find_byname(pc, nam);
	if (i == -1)
	{
		printf("û������~!\n");
	}
	else
	{
		int j = 0;
		for (j = i; j < pc->size; j++)
		{
			pc->data[j] = pc->data[j + 1];
		}
		pc->size--;
		printf("ɾ���ɹ�\n");
	}
}


void searchgra(gra* pc)
{
	char nam[20];
	printf("������ѧ������->");
	scanf("%s", nam);
	int i = 0;
	i = find_byname(pc, nam);
	if (i == -1)
	{
		printf("û������~\n");
		return;
	}
	else
	{
		printf("����\t\tѧ��\t\t����\t\t�绰\t\t\t�ܷ�\n");
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
	printf("������ѧ������\n");
	scanf("%s", nam);
	int i = find_byname(pc, nam);
	if (i == -1)
	{
		printf("û�и�ѧ����Ϣ\n");
	}
	else
	{
		printf("��������->");
		scanf("%s", pc->data[i].name);
		printf("����ѧ��->");
		scanf("%s", pc->data[i].num);
		printf("��������->");
		scanf("%d", &pc->data[i].agg);
		printf("����绰->");
		scanf("%s", pc->data[i].ph);
		printf("�����ܷ�->");
		scanf("%d", &pc->data[i].core);
		printf("�޸ĳɹ�\n");
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