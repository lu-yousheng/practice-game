#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void menu()
{
	printf("**********************************\n");
	printf("*************  1.play  ***********\n");
	printf("*************  0.exit  ***********\n");
	printf("**********************************\n");
}
void game()
{
	//创建两个二维数组，一个是放雷的，一个是显示的
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };

	//初始化这两个数组 
	InitBoard(mine, ROWS, COLS,'0');
	InitBoard(show, ROWS, COLS, '*');

	//打印棋盘
	//DispalyBoard(mine, ROW, COL);
	DispalyBoard(show, ROW, COL);

	//布置雷
	SetMine(mine, ROW, COL);
	//DispalyBoard(mine, ROW, COL);

	//排除雷
	FindMine(mine, show, ROWS, COLS);
}
int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("请输入->");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("扫雷\n");
			game();
			break;
		case 0:
			break;
		default:
			printf("选择错误，请重新输入->");
			break;
		}
	} while (input);
	return 0;
}