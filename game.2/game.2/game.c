#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"
void InitBoard(char Board[ROW][COL], int row, int col)
{
	int i = 0; 
	int j = 0;
	for (i = 0;i < row;i++)
	{
		for (j = 0;j < col;j++)
		{
			Board[i][j] = ' ';
		}
	}
}
void DisplayBoard(char Board[ROW][COL], int row, int col)
{
	/*int i = 0;
	for (i = 0;i < row;i++)
	{
		int j = 0;
			printf(" %c | %c | %c\n",Board[i][0], Board[i][1],Board[i][2]);
			if (i < row - 1)
			{
				printf("---|---|---\n");
			}
	}*/
	int i = 0;
	for (i = 0;i < row;i++)
	{
		int j = 0;
		for (j = 0;j < col;j++)
		{
			if (j < col - 1)
			{
				printf(" %c |", Board[i][j]);
			}
			else
			{
				printf(" %c  ", Board[i][j]);
			}

		}
		printf("\n");
		if (i < row - 1)
		{
			for (j = 0;j < col;j++)
			{
				if (j < col - 1)
				{
					printf("---|");
				}
				else
				{
					printf("---");
				}
			}
		}
		printf("\n");
	}
}
void PlayerMove(char Board[ROW][COL], int row, int col)
{
	int r = 0;
	int c = 0;
	while (1) {
		scanf("%d %d", &r, &c);
		if (Board[r-1][c-1] == ' ')
		{
			Board[r-1][c-1] = '*';
			break;
		}
		else
		{
			printf("坐标已经被输入，请重新输入！\n");
		}
	}
}
void ComputerMove(char Board[ROW][COL], int row, int col)
{
	while (1) {
		int r = rand() % row;
		int c = rand() % col;
		if (Board[r][c] == ' ')
		{
			Board[r][c] = '#';
			break;
		}
	}

}
char Is_Full(char Board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	int judge = 0;
	for (i = 0;i < row;i++)
	{
		for (j = 0;j < col;j++)
		{
			if (Board[i][j] == ' ')
			{
				judge++;
			}
		}
	}
	if (judge == 0)
	{
		return 'Q';
	}
	else
		return ' ';
	return ' ';
}
char Is_Win(char Board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row;i++)
	{
		if (Board[i][0] == Board[i][1] && Board[i][1]== Board[i][2] && Board[i][2]!=' ')
		{
			return Board[i][0];
		}
	}
	for (j = 0;j < col;j++)
	{
		if (Board[0][j] == Board[1][j] && Board[1][j] == Board[2][j] && Board[2][j] != ' ')
			return Board[0][j];
	}
	if (Board[0][0] == Board[1][1] && Board[1][1] == Board[2][2] && Board[1][1] != ' ')
	{
		return Board[0][0];
	}
	else if (Board[0][2] == Board[1][1] && Board[1][1] == Board[2][0] && Board[2][0] != ' ')
	{
		return Board[2][0];
	}
	char ab = Is_Full(Board, ROW, COL);
	if (ab == 'Q')
	{
		return 'Q';
	}
	else
		return ' ';
	return ' ';
}