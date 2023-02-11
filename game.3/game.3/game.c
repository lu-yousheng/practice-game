#include"game.h"
void InitBoard(char Board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0;i < rows;i++)
	{
		for (j = 0;j < cols;j++)
		{
			Board[i][j] = set;
		}
	}
}
void DispalyBoard(char Board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("==========É¨À×===========\n");
	int c = 0;
	for (c = 0;c <= col;c++)
	{
		printf("%d ", c);
	}
	printf("\n");
	for (i = 1;i <= row;i++)
	{
		printf("%d ", i);
		for (j = 1;j <= col;j++)
		{
			printf("%c ", Board[i][j]);
		}
		printf("\n");
	}
	printf("==========É¨À×===========\n");
}
void SetMine(char Board[ROWS][COLS], int row, int col)
{
	int count = Easy_Count;
	while (count != 0)
	{
		int r = rand() % row + 1;
		int c = rand() % col + 1;
		if (Board[r][c] == '0')
		{
			Board[r][c] = '1';
			count--;
		}
	}
}
 get_mine_count(char mine[ROWS][COLS], int x, int y)
{

	 return mine[x - 1][y - 1] +
		 mine[x][y - 1] +
		 mine[x + 1][y - 1] +
		 mine[x][y + 1] +
		 mine[x + 1][y + 1] +
		 mine[x + 1][y] +
		 mine[x - 1][y + 1] +
		 mine[x - 1][y] - 8 * 48;
}
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int rows, int cols)
{
	int x = 0;
	int y = 0;
	printf("ÊäÈë×ø±ê->\n");
	int count = ROW * COL - Easy_Count;
	while (count!=0)
	{
		scanf("%d %d", &x, &y);
		if (x > 0 && x <= ROW && y > 0 && y < COL)
		{
			if (mine[x][y] == '1')
			{
				show[x][y] = '1';
				printf("°¡Å¶£¬Äã±»Õ¨ÁË\nÓÎÏ·½áÊø");
				DispalyBoard(show, ROW, COL);
				break;
			}
			else if (mine[x][y] == '0')
			{
				int win = get_mine_count(mine, x, y);
				show[x][y] = win+'0';
				count--;
				DispalyBoard(show, ROW, COL);
			}
		}
		else
		{
			printf("ÊäÈë×ø±ê´íÎó£¬ÇëÖØÐÂÊäÈë£¡\n");
		}
	}
	if(count == 0)
	{ 
		printf("¹§Ï²Äã£¬ÅÅÀ×³É¹¦£¡\n");
	}
}