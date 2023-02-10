#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void menu()
{
	printf("************************\n");
	printf("*******   1.paly   *****\n");
	printf("*******   0.exit   *****\n");
	printf("************************\n");
}
void game()
{
	//存储数据，创建二维数组
	char Board[ROW][COL];

	//初始化数组
	InitBoard(Board, ROW, COL);

	//打印棋盘
	DisplayBoard(Board, ROW, COL);

	//玩法
	while (1)
	{
		//玩家下棋
		printf("玩家下棋，请输入坐标->\n");
		PlayerMove(Board, ROW, COL);
 		DisplayBoard(Board, ROW, COL);
		char abc = Is_Win(Board, ROW, COL);
		if (abc == '#')
		{
			printf("电脑赢了\n");
			break;
		}
		else if (abc == '*')
		{
			printf("玩家赢了\n");
			break;
		}
		else if (abc == 'Q')
		{
			printf("平局\n");
			break;
		}

		//电脑下棋
		printf("电脑下棋=>\n");
		ComputerMove(Board, ROW, COL);
		DisplayBoard(Board, ROW, COL);

		//判断是否输赢
		if (abc == '#')
		{
			printf("电脑赢了\n");
			break;
		}
		else if (abc == '*')
		{
			printf("玩家赢了\n");
			break;
		}
		else if (abc == 'Q')
		{
			printf("平局\n");
			break;
		}
	}
	DisplayBoard(Board, ROW, COL);


}
int main()
{
	srand((unsigned int)time(NULL));
	int input = 1;
	do
	{
		menu();
		printf("请选择->");
		//scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("三子棋\n");
  			game();
			break;
		case 0:
			break;
		default:
			printf("输入错误，请重新输入！\n");
			break;
		}
	} while (input);
	return 0;
}