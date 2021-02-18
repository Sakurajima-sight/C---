#include"game.h"

void menu()
{
	printf("*****************************\n");
	printf("***** 1. play	0. exit *****\n");
	printf("*****************************\n");
}

void game()
{
	char board[cross][vertical] = { 0 };
	int cro = cross;
	int ver = vertical;
	char in = { 0 };
	clean(board, cro, ver);
	while (1)
	{
		computer(board, cro, ver);
		boa(board, cro, ver);
		in = judge(board, cro, ver);
		if (in == 'E')
			break;
		play(board, cro, ver);
		boa(board, cro, ver);
		in = judge(board, cro, ver);
		if (in == 'E')
			break;
	}
}

void theme()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("请输入：>");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("已退出程序\n");
			break;
		default:
			printf("输入错误\n");
			break;
		}
	} while (input);
}

int main()
{
	theme();
	return 0;
}
