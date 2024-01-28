#define _CRT_SECURE_NO_WARNINGS 1
#include"snack.h"

void Setpos(int x, int y)
{
	//光标设置
	COORD pos = { x,y };
	//获取句柄
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(handle, pos);
}

void Welcome()
{
	Setpos(35, 10);
	printf("欢迎来到游戏,按空格停止游戏\n");
	Setpos(38, 20);
	system("pause");
	system("cls");
	Setpos(15, 10);
	printf("用←↑→↓控制蛇，f3是加速，f4是减速\n");
	Setpos(15, 11);
	printf("加速能得到更高的分数\n");
	Setpos(38, 20);
	system("pause");
	system("cls");
}

//开始游戏
void GameStart(pSnake ps)
{
	//设置控制台信息
	system("mode con cols=100 lines=30");
	system("title 贪吃蛇");
	
	//隐藏光标
	CONSOLE_CURSOR_INFO cursor = { 0 };
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleCursorInfo(handle, &cursor);
	cursor.bVisible = false;
	SetConsoleCursorInfo(handle, &cursor);
	//打印欢迎信息
	Welcome();
	//生成地图
	CreatMap();
	//生成蛇节点
	InitSnake(ps);


	//生成食物
	CreatFood(ps);
}

//打印地图
void CreatMap()
{
	Setpos(0, 0);
	int i = 0;
	for (i = 0; i <= 56; i+=2)
	{
		wprintf(L"%lc", WALL);
	}
	//下
	//左；
	Setpos(0, i);
	for (i = 1; i <= 25; i++)
	{
		Setpos(0, i);
		wprintf(L"%lc", WALL);
	}
	for (i = 1; i <= 25; i++)
	{
		Setpos(56, i);
		wprintf(L"%lc", WALL);
	}
	Setpos(0, 26);
	for (i = 0; i <= 56; i += 2)
	{
		wprintf(L"%lc", WALL);
	}

}

void InitSnake(pSnake ps)
{
	pSnakeNode cur= NULL;
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		cur = (pSnakeNode)malloc(sizeof(SnakeNode));
		if (cur == NULL)
		{
			perror("malloc:");
			exit(-1);
		}
		cur->next = NULL;
		cur->x = i * 2 + POS_X;
		cur->y = POS_Y;
		if (ps->psnake == NULL)
		{
			ps->psnake = cur;
		}
		else
		{
			cur->next = ps->psnake;
			ps->psnake = cur;
		}
	}
	//打印🐍节点
	cur = ps->psnake;
	while (cur)
	{
		Setpos(cur->x,cur->y);
		wprintf(L"%lc", BODY);
		cur = cur->next;
	}
	ps->foodwight=10;
	ps->pfood = NULL;
	ps->dir = RIGHT;
	ps->statues = OK;
	ps->seelptime = 200;
	ps->score = 0;
}


//创建食物；
void CreatFood(pSnake ps)
{
	//创建食物
	int x = 0;
	int y = 0;
	again:
	do
	{
		 x = rand() % 53 + 2;
		 y = rand() % 24 +1;
	} while (x%2!=0);
	pSnakeNode cur = ps->psnake;
	while (cur)
	{
		if (x==cur->x && cur->y == y)
		{
			goto again;
		}
		cur = cur->next;
	}
	pSnakeNode pos = (pSnakeNode)malloc(sizeof(SnakeNode));
	pos->x = x;
	pos->y = y;
	pos->next = NULL;
	ps->pfood =pos;
	Setpos(x,y);
	wprintf(L"%lc",FOOD);
}

void pause()
{
	while (1)
	{
		Sleep(200);
		if (KEY_PRESS(VK_SPACE))
		{
			break;
		}
	}
}


//判断蛇头的下一步是否是食物
int IsFood(pSnake ps,pSnakeNode pnext)
{
	if (ps->pfood->x == pnext->x&&ps->pfood->y == pnext->y)
	{
		return 1;
	}
	return 0;
}


void SnakeMove(pSnake ps)
{
	pSnakeNode pnext = (pSnakeNode)malloc(sizeof(SnakeNode));
	if (pnext == NULL)
	{
		perror("malooc:");
		exit(-1);
	}
	pnext->next = NULL;
	switch (ps->dir)
	{
	case UP:
		pnext->x = ps->psnake->x;
		pnext->y = ps->psnake->y - 1;
		break;
	case DOWN:
		pnext->x = ps->psnake->x;
		pnext->y = ps ->psnake->y + 1;
		break;
	case LEFT:
		pnext->x = ps->psnake->x-2;
		pnext->y = ps->psnake->y;
		break;
	case RIGHT:
		pnext->x = ps->psnake->x+2;
		pnext->y = ps->psnake->y;
		break;
	}
	if (IsFood(ps,pnext))
	{
		//吃食物
		Eatfood(ps, pnext);
	}
	else
	{
		//不是食物
		Notfood(ps, pnext);

	}
}

//吃食物
void Eatfood(pSnake ps, pSnakeNode pnext)
{
	pnext->next = ps->psnake;
	ps->psnake = pnext;
	pSnakeNode cur = ps->psnake;
	while (cur)
	{
		Setpos(cur->x, cur->y);
		wprintf(L"%lc", BODY);
		cur = cur->next;
	}
	ps->score += ps->foodwight;
	free(ps->pfood);                 
	CreatFood(ps);
}

//不是食物
void Notfood(pSnake ps, pSnakeNode pnext)
{
	pnext->next = ps->psnake;
	ps->psnake = pnext;
	pSnakeNode cur=ps->psnake;
	while (cur->next->next)
	{
		Setpos(cur->x, cur->y);
		wprintf(L"%lc", BODY);
		cur = cur->next;
	}
	Setpos(cur->next->x, cur->next->y);
	printf("  ");
	free(cur->next);
	cur->next = NULL;
}


//运行游戏
void GameRun(pSnake ps)
{
	//打印帮助信息
	GameInPrint();
	//检测按键
	do
	{
		Setpos(62, 10);
		printf("当前分数为:%d",ps->score);
		Setpos(62, 11);
		printf("当前食物分数 为:%2d", ps->foodwight);
		if (KEY_PRESS(VK_UP)&& ps->dir!=DOWN)
		{
			ps->dir = UP;
		}
		else if (KEY_PRESS(VK_DOWN) && ps->dir != UP)
		{
			ps->dir = DOWN;
		}
		else if (KEY_PRESS(VK_LEFT ) && ps->dir != RIGHT)
		{
			ps->dir = LEFT;
		}
		else if (KEY_PRESS(VK_RIGHT)&&ps->dir!=LEFT)
		{
			ps->dir = RIGHT;
		}
		else if (KEY_PRESS(VK_ESCAPE))
		{
			ps->statues = ESC;
			break;
		}
		else if(KEY_PRESS(VK_SPACE))
		{
			pause();
		}
		else if(KEY_PRESS(VK_F3))
		{
			if (ps->seelptime >= 70)
			{
				ps->foodwight += 2;
				ps->seelptime -= 30;
			}
		}
		else if (KEY_PRESS(VK_F4))
		{
			if (ps->foodwight > 2)
			{
				ps->foodwight -= 2;
				ps->seelptime += 30;
			}
		}
		Sleep(ps->seelptime);
		SnakeMove(ps);
		//墙杀
		KillByWall(ps);
			//自杀
		KillBySelf(ps);
	} while (ps->statues==OK);
	//睡眠一下
}

void GameInPrint()
{
	Setpos(62, 13);
	printf("1.不能穿墙，不能将头碰到自己");
	Setpos(62, 14);
	printf("2.用←↑→↓控制蛇，空格停止游戏");
	Setpos(62, 15);
	printf("f3加速，f4减速");
}


//墙杀
KillByWall(pSnake ps)
{
	if (ps->psnake->x == 0 || ps->psnake->x == 56 || ps->psnake->y == 0 || ps->psnake->y == 26)
	{
		ps->statues = KILL_BY_WALL;
	}
}
//自杀
KillBySelf(pSnake ps)
{
	pSnakeNode cur = ps->psnake->next;
	while (cur)
	{
		if (cur->x == ps->psnake->x && cur->y == ps->psnake->y)
		{
			ps->statues = KILL_BY_SELF;
			break;
		}
		cur = cur->next;
	}
}


//游戏结束
GameEed(pSnake ps)
{
	Setpos(30,12);
	switch (ps->statues)
	{
	case ESC:
		printf("正常退出喵~");
		break;
	case KILL_BY_SELF:
		printf("撞到自己了nya~");
		break;
	case KILL_BY_WALL:
		printf("被墙杀死miao~");
		break;
	}
	pSnakeNode cur = ps->psnake;
	while (cur)
	{
		pSnakeNode del = cur;
		cur = cur->next;
		free(del);
	}
	free(ps->pfood);
}