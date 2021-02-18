#include"game.h"

void clean(char board[cross][vertical], int cro, int ver)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < cross; i++)
	{
		for (j = 0; j < vertical; j++)
		{
			board[i][j] = ' ';
		}
	}
}

void boa(char board[cross][vertical], int cro, int ver)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < cross; i++)
	{
		for (j = 0; j < vertical; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < vertical-1)
			{
				printf("|");
			}
		}
		printf("\n");
		if(i<cross-1)
			for (j = 0; j < vertical; j++)
			{
				printf("---");
				if (j < vertical - 1)
				{
					printf("|");
				}
			}
		printf("\n");
	}
}

void play(char board[cross][vertical], int cro, int ver)
{
	printf("\n\n");
	int i = 1;
	int j = 1;
	printf("轮到玩家走\n");
	while (1)
	{
		printf("请输入坐标：>");
		scanf_s("%d%d", &i, & j);
		if (1 <= i && i <= cross && 1 <= j && j <= vertical)
		{
			if (board[i - 1][j - 1] == ' ')
			{
				board[i - 1][j - 1] = '*';
				break;
			}
			else
				printf("该坐标已被占\n");
		}
		else
		{
			printf("输入错误\n");
		}
	}
}

void computer(char board[cross][vertical], int cro, int ver)
{
	printf("\n\n");
	printf("电脑走\n");
	while (1)
	{
		int i = rand() % 3;
		int j = rand() % 3;
		if (board[i][j] == ' ')
		{
			board[i][j] = '#';
			break;
		}
	}
}

int whowin(char board[cross][vertical], int cro, int ver)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < cross; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] == '*')
			return 11;
		else if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] == '#')
			return 12;
		else if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] == '*')
			return 11;
		else if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] == '#')
			return 12;
	}
	for (i = 0; i < 1; i++)
	{
		if (board[i][i] == board[i + 1][i + 1] && board[i + 1][i + 1] == board[i + 2][i + 2] && board[i + 1][i + 1] == '*')
			return 11;
		else if (board[i][i] == board[i + 1][i + 1] && board[i + 1][i + 1] == board[i + 2][i + 2] && board[i + 1][i + 1] == '#')
			return 12;
		else if (board[i][i + 2] == board[i + 1][i + 1] && board[i + 1][i + 1] == board[i + 2][i] && board[i + 1][i + 1] == '*')
			return 11;
		else if (board[i][i + 2] == board[i + 1][i + 1] && board[i + 1][i + 1] == board[i + 2][i] && board[i + 1][i + 1] == '#')
			return 12;
	}
	int count = 0;
	for (i = 0; i < cross; i++)
	{
		for (j = 0; j < vertical; j++)
		{
			if (board[i][j] != ' ')
				count++;
		}
	}
	return count;
}

char judge(char board[cross][vertical], int cro, int ver)
{
	int res = 0;
	res = whowin(board, cro, ver);
	if (res == 11)
	{
		printf("玩家赢\n");
		return 'E';
	}
	else if (res == 12)
	{
		printf("电脑赢\n");
		return 'E';
	}
	else if (res == 9)
	{
		printf("平局\n");
		return 'E';
	}
	return 'G';
}
