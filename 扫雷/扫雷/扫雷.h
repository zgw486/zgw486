#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define row 9
#define col 9
#define rows 11
#define cols 11
#define EASR_COUNT 10


//��ʼ������
void initboard(char ROW[][rows],  int R, int C,char set);

//��ӡ����
void print(char arr[][rows], int R, int C);

//������
void setmine(char arr[][cols], int R, int C);

//�Ų���
void findmine(char mine[][cols], char show[][cols], int R, int C);

