#pragma once
#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<time.h>
#include<stdlib.h>

//定义字符
#define ROW 9 //这是需要用到的棋盘
#define COL 9
#define ROWS ROW+2  //这是整个全部的棋盘
#define COLS COL+2
#define Easy_Count 10

//函数声明
void InitBoard(char Board[ROWS][COLS], int rows, int cols, char set);//初始化棋盘
void DispalyBoard(char Board[ROWS][COLS], int row, int col);//打印棋盘
void SetMine(char Board[ROWS][COLS], int row, int col);//布置雷
void FindMine(char mine[ROWS][COLS],char show[ROWS][COLS], int rows, int cols);//排查雷