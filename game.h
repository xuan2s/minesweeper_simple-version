#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROWS 11
#define COLS 11
#define ROW ROWS-2
#define COL COLS-2 
#define num_mine 80//雷的数量
void Init_board(char board[ROWS][COLS],int rows,int cols,char set);
void Display_board(char board[ROWS][COLS], int row,int col);
void set_mine(char board[ROWS][COLS], int row, int col,int num);
void find_mine(char mine[ROWS][COLS],char show[ROWS][COLS],int rows,int cols);
int mine_around(char mine[ROWS][COLS], int rows, int cols,int row,int col,int num);
