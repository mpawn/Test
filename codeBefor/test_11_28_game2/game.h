#define _CRT_SECURE_NO_WARNINGS
#define ROW 9
#define COL 9
#define ROWS 11
#define COLS 11
#define EASY_COUNT 10

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set);

void DisplayBoard(char board[ROWS][COLS], int row, int col);

void SetMine(char board[ROWS][COLS], int row, int col);

void FindMine(char mind[ROWS][COLS], char show[ROWS][COLS], int row, int col);

int get_mine_count(char board[ROWS][COLS], int x, int y);