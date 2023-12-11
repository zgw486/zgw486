#define _CRT_SECURE_NO_WARNINGS 1
#include"扫雷.h"

void initboard(char arr[][cols], int R, int C, char set)
{
    int i = 0;
    int j = 0;
    
    for (i = 0; i < R; i++)
    {;
        for (j = 0; j < C; j++)
        {
            arr[i][j] = set;
        }
    }
}


void print(char arr[][cols], int R, int C)
{
    int i = 0;
    for (i = 0; i <= R; i++)
    {
        printf("%d ", i);
    }
    printf("\n");
    for (i = 1; i <= R; i++)
    {
        printf("%d", i);
        int j = 0;
        for (j= 1; j <= C; j++)
        {
            printf(" %c", arr[i][j]);
        }
        printf("\n");
    }
}

void setmine(char arr[][cols], int count)
{
    int x = 0;
    int y = 0;
    while (count)
    {
        x = rand() % row + 1;
        y = rand() % col + 1;
        if (arr[x][y] == '0')
        {
            arr[x][y] = '1';
            count--;
        }
    }
}

int minecount(char mine[][rows],int x,int y)
{
    return mine[x - 1][y] + mine[x - 1][y - 1] + mine[x][y - 1] + mine[x + 1][y - 1] +
        mine[x + 1][y] + mine[x + 1][y + 1] + mine[x][y + 1] + mine[x - 1][y + 1]-8*'0';
}

void findmine(char show[][cols],char mine[][cols],int X,int Y)
{
    int x = 0;
    int y = 0;
    int z = 0;
    int count = 0;
    while (1)
    {
        printf("请输入x，y坐标->");
        scanf("%d %d", &x, &y);
        if (x >= 1 && x <= 9 && y >= 1 && y <= 9)
        {
            if(show[x][y] == '*')
            {
                if (mine[x][y] == '1')
                {
                    printf("炸死了喵~\n");
                    print(mine, row, col);
                    break;
                }
                else
                {
                    z = minecount(mine, x, y);
                    show[x][y] = '0' + z;
                    print(show, col, row);
                    count+=1;
                    if (count == ((col-48)*(row-48)-easy))
                    {
                        break;
                    }
                }
            }
            else
            {
                printf("已经走了这步喵\n");
            }
        }
        else 
        {
            printf("选择错误\n");
        }
    }
    if (count == 71)
    {
        printf("真厉害喵~！\n");
    }
}