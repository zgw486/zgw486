#define _CRT_SECURE_NO_WARNINGS 1
#include"snack.h"




void test()
{
	int ch = 0;
	do
	{
		Snake sn = { 0 };
		GameStart(&sn);
		GameRun(&sn);
		GameEed(&sn);
		Setpos(25, 12);
		printf("是否重新玩游戏喵~->\n");
		Setpos(25, 13);
		ch = getchar();
	} while(putchar(ch)=='y'||putchar(ch)=='Y');
}

int main()
{
	mciSendString("open scr//故乡的味道.wav", NULL, 0, NULL);
	mciSendString("play scr//故乡的味道.wav", NULL, 0, NULL);
	srand((unsigned int)time(NULL));
	setlocale(LC_ALL, "");
	test();
	return 0;
}