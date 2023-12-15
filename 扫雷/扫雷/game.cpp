#define _CRT_SECURE_NO_WARNINGS 1
#include"扫雷.h"

void initboard(char ROW[][rows],  int R, int C,char set)
{
	int i = 0;
	for (i = 0; i < R; i++)
	{
		int j = 0;
		for (j = 0; j < C; j++)
		{
			ROW[i][j] = set;
		}
	
	}
}



void print(char arr[][rows], int R, int C)
{
	int i = 0;
	for (i = 0; i <=col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= R; i++)
	{
		int j = 1;
		printf("%d", i);
		for (j = 1; j <=C; j++)
		{
			printf(" %-1c", arr[i][j]);
		}
		printf("\n");
	}
}

void setmine(char arr[][cols], int R, int C)
{
	int count = EASR_COUNT;
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (arr[x][y] == '0')
		{
			arr[x][y] = '1';
			count--;
		}
	}
}


static int get_mine_conut(char mine[][cols], int x, int y)
{
	return mine[x - 1][y] + mine[x - 1][y - 1] + mine[x][y - 1] + mine[x + 1][y - 1]
		+ mine[x + 1][y] + mine[x + 1][y + 1] + mine[x][y + 1] + mine[x - 1][y +1]-8*'0';
}

 void findmine(char mine[][cols], char show[][cols], int R, int C)
{
	 int win = 0;
	 //1.输入坐标
	 //2.检查坐标是不是雷
	 //(1).是雷--被炸死，游戏结束
	 //(2).不是雷--统计周边有多少个雷--存储排查雷的信息到数组
	 while (win<row*col-EASR_COUNT)
	 {
		 printf("请输入要排查的坐标->");
		 int x = 0;
		 int y = 0;
		 scanf("%d %d", &x, &y);//(取值为1到9)
		 //判断合法性
		 if (x >= 1 && x <= 9 && y >= 1 && y <= 9)
		 {
			 if (mine[x][y] == '1')
			 {
				 printf("被炸死了喵~\n");
				 print(mine, row, col);
				 break;
			 }
			 else
			 {
				 //不是雷，统计坐标周围的雷的个数
				int count= get_mine_conut(mine, x, y);
				show[x][y] = count+'0';
				print(show, row, col);
				win++;
			 }
		 }
		 else
		 {
			 printf("坐标不合法喵~\n");
		 }
	 }
	 if (win == row * col - EASR_COUNT)
	 {
		 printf("恭喜喵~你太有耐心了，简直就是卡密撒嘛");
	 }
 }