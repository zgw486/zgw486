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
#define WALL L'□'
#define BODY L'●'
#define FOOD L'★'

//初始位置
#define POS_X 24
#define POS_Y 5


enum GAME_STATUS
{
	OK=1,
	ESC,  //正常退出
	KILL_BY_WALL,
	KILL_BY_SELF
};


//行走的方向
enum DIRECTION
{
	UP=1,
	DOWN,
	LEFT,
	RIGHT
};

//蛇身节点
typedef struct SnakeNode
{
	int x;
	int y;
	struct SnakeNode* next;
}SnakeNode,* pSnakeNode;

//贪吃蛇
typedef struct Snake
{
	pSnakeNode psnake;   // 维护整条蛇的指针
	pSnakeNode pfood;   // 指向食物的指针
	int score;         // 分数
	int foodwight;     // 食物的分数
	int seelptime;     // 休眠时间，控制速度
	enum GAME_STATUES statues;  //状态
	enum DIREACTION dir;
} Snake, * pSnake;


void GameStart(pSnake ps);

void CreatMap();

void InitSnake(pSnake ps);

//生成蛇节点
void InitSnake(pSnake ps);

//创建食物；
void CreatFood(pSnake ps);

//运行游戏
void GameRun(pSnake ps);

//打印游戏信息
void GameInPrint();

//蛇的移动
void SnakeMove(pSnake ps);

//判断蛇头的下一步是否是食物
int IsFood(pSnake ps,pSnakeNode pnext);

//吃食物
void Eatfood(pSnake ps,pSnakeNode pnext);

//不是食物
void Notfood(pSnake ps, pSnakeNode pnext);

//墙杀
KillByWall(pSnake ps);
//自杀
KillBySelf(pSnake ps);

//游戏结束
GameEed(pSnake ps);

//游戏位置
void Setpos(int x, int y);