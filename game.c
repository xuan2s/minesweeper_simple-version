#include"game.h"

void Init_board(char board[ROWS][COLS], int rows, int cols,char set)
{
	int i;
	int j;
	for (i = 0;i < rows;i++)
	{
		for (j = 0;j < cols;j++)
			board[i][j] = set;
	}
}

void set_mine(char board[ROWS][COLS], int row, int col,int num)
{
	int num_of_mine=num;
	while (num_of_mine)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			num_of_mine--;
		}
	}
}

void Display_board(char board[ROWS][COLS], int row, int col)
{
	int i;
	int j;
	for (j = 0;j <=col;j++)
	{
		printf(" %d", j);
	}
	printf("\n");
	for (i = 1;i <= row;i++)
	{
		printf(" %d", i);
		for (j = 1;j <= col;j++)
		{
			printf(" %c", board[i][j]);
		}
		printf("\n");
	}
}

int mine_around(char mine[ROWS][COLS], int x, int y)
{
				return mine[x - 1][y - 1] +
					mine[x - 1][y] +
					mine[x - 1][y + 1] +
					mine[x][y - 1] +
					mine[x][y + 1] +
					mine[x + 1][y - 1] +
					mine[x + 1][y] +
					mine[x + 1][y + 1] - 8 * '0';
}

void find_mine(char mine[ROWS][COLS], char show[ROWS][COLS], int rows, int cols,int row,int col,int num)
{
	int count=row*col-num;
	while(count)
	{
		int x;
		int y;
		printf("请输入坐标>:");
		scanf("%d %d", &x, &y);
		if (x > 0 && x <= row && y > 0 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("很遗憾，你已被炸死\n");
				Display_board(mine, ROW, COL);
				break;
			}
			else
			{
				int ret = mine_around(mine, x, y);
				show[x][y] = ret + '0';
				Display_board(show, ROW, COL);
				count--;
			}
		}
		else
			printf("输入错误，请从新输入\n");
	}
	if (count == 0)
	{
		printf("恭喜你，游戏胜利\n");
	}
}
