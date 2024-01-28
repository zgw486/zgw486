#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<Windows.h>
#include<locale.h>
#include<time.h>
#include<mmsystem.h>


#pragma comment (lib,"winmm.lib")
#define KEY_PRESS(VK) ((GetAsyncKeyState(VK)&0x1) ? 1 : 0)
#define WALL L'��'
#define BODY L'��'
#define FOOD L'��'

//��ʼλ��
#define POS_X 24
#define POS_Y 5


enum GAME_STATUS
{
	OK=1,
	ESC,  //�����˳�
	KILL_BY_WALL,
	KILL_BY_SELF
};


//���ߵķ���
enum DIRECTION
{
	UP=1,
	DOWN,
	LEFT,
	RIGHT
};

//����ڵ�
typedef struct SnakeNode
{
	int x;
	int y;
	struct SnakeNode* next;
}SnakeNode,* pSnakeNode;

//̰����
typedef struct Snake
{
	pSnakeNode psnake;   // ά�������ߵ�ָ��
	pSnakeNode pfood;   // ָ��ʳ���ָ��
	int score;         // ����
	int foodwight;     // ʳ��ķ���
	int seelptime;     // ����ʱ�䣬�����ٶ�
	enum GAME_STATUES statues;  //״̬
	enum DIREACTION dir;
} Snake, * pSnake;


void GameStart(pSnake ps);

void CreatMap();

void InitSnake(pSnake ps);

//�����߽ڵ�
void InitSnake(pSnake ps);

//����ʳ�
void CreatFood(pSnake ps);

//������Ϸ
void GameRun(pSnake ps);

//��ӡ��Ϸ��Ϣ
void GameInPrint();

//�ߵ��ƶ�
void SnakeMove(pSnake ps);

//�ж���ͷ����һ���Ƿ���ʳ��
int IsFood(pSnake ps,pSnakeNode pnext);

//��ʳ��
void Eatfood(pSnake ps,pSnakeNode pnext);

//����ʳ��
void Notfood(pSnake ps, pSnakeNode pnext);

//ǽɱ
KillByWall(pSnake ps);
//��ɱ
KillBySelf(pSnake ps);

//��Ϸ����
GameEed(pSnake ps);

//��Ϸλ��
void Setpos(int x, int y);