#include"game.h"
void menu()
{
	printf("#########################\n");
	printf("#####1.play  0.exit######\n");
	printf("#########################\n");
}

void game()
{
	char mine[ROWS][COLS] = {0};
	char show[ROWS][COLS] = {0};
	Init_board(mine,ROWS,COLS,'0');
	Init_board(show, ROWS, COLS,'*');
	Display_board(show, ROW, COL);
	set_mine(mine, ROW, COL, num_mine);
	Display_board(mine, ROW, COL);
	find_mine(mine, show, ROWS, COLS,ROW,COL, num_mine);//同时实现 找雷 打印 进程判断
}

int main()
{
	srand((unsigned)time(NULL));
	int input;
	do
	{
		menu();
		printf("请选择>:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			break;
		default:
			break;
		}
	} while (input);
}
