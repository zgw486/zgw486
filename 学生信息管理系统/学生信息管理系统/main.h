#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define max_name 20
#define max_num 20
#define max_ph 20
#define MAX 1000
#define st  3
#define ad  2

typedef struct student
{
	char name[max_name];
	char num[max_num];
	int agg;
	char ph[max_ph];
	int core;
}student;

//��̬�汾
//typedef struct gra
//{
//	student data[MAX];
//	int size;
//}gra;
//��̬�汾
typedef struct gra
{
	student* data;
	int size;
	int  capacity;
}gra;


//��ʼ��
void initgra(gra* pc);
//���
void addgra(gra* pc);
//��ӡ
void print(gra* pc);
// ɾ��
void delgra(gra* pc);
//Ѱ�� 
void searchgra(gra* pc);
//�ض���
void modeify(gra*pc);
//���� 
void destorygra(gra* pc);
//������Ϣ 
void writegra(gra* pc);
//������Ϣ
void loadcontact(gra* pc);