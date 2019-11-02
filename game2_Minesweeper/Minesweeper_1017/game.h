#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 9  //原始棋盘的行数
#define COL 9

#define ROWS ROW+2  //假设的棋盘比原始棋盘扩大一圈，行列各加2
#define COLS COL+2

#define EASY_COUNT 9  //布置雷的个数

void InitBoard(char  board[ROWS][COLS], int rows, int cols, char set);
void Display(char board[ROWS][COLS], int row, int col);
void SetMine(char board[ROWS][COLS], int row, int col);
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);