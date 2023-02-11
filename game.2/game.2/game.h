#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define ROW 3
#define COL 3
//创建二维数组
void InitBoard(char Board[ROW][COL], int row, int col);
//打印棋盘的函数
void DisplayBoard(char Board[ROW][COL], int row, int col);
//玩家下棋的函数
void PlayerMove(char Board[ROW][COL], int row, int col);
//电脑下棋的函数
void ComputerMove(char Board[ROW][COL], int row, int col);
//判断输赢
char Is_Win(char Board[ROW][COL], int row, int col);
//判断棋盘是否满了
char Is_Full(char Board[ROW][COL], int row, int col);