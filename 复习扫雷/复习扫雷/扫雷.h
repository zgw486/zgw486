#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define rows 100
#define cols 100
#define row  9
#define col  9
#define easy 10

//��ʼ�����̣�
void initboard(char arr[][cols], int R, int C, char set);
//��ӡ����
void print(char arr[][cols], int R, int C);
//�����ף�
void setmine(char arr[][cols], int count);

// ����
void findmine(char show[][cols],char mine[][rows],int X,int Y);