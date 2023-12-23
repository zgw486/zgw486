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

//静态版本
//typedef struct gra
//{
//	student data[MAX];
//	int size;
//}gra;
//动态版本
typedef struct gra
{
	student* data;
	int size;
	int  capacity;
}gra;


//初始化
void initgra(gra* pc);
//添加
void addgra(gra* pc);
//打印
void print(gra* pc);
// 删除
void delgra(gra* pc);
//寻找 
void searchgra(gra* pc);
//重定义
void modeify(gra*pc);
//销毁 
void destorygra(gra* pc);
//保存信息 
void writegra(gra* pc);
//加载信息
void loadcontact(gra* pc);