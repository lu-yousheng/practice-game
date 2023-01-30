#define _CRT_SECURE_NO_WARNINGS 1;
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void menu()
{
	printf("********************\n");
	printf("********1.paly******\n");
	printf("********2.exit******\n");
	printf("********************\n");
}
int game()
{

	int a = rand() % 100 + 1;
	int b = 0;
	printf("猜猜a是多少？->\n");
	while (a != b)
	{
		scanf("%d", &b);
		if (b > a)
		{
			printf("猜大了,请重新输入->\n");
		}

		else if (b < a)
		{
			printf("猜小了，请重新输入->\n");
		}

	}
	printf("猜对了，a是%d\n", a);
	return 0;
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择->\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("猜数字\n");
			game();
			break;
		case 2:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，请重新选择\n");
			break;
		}
	} while (input);
	return 0;
}