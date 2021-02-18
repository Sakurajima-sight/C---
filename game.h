#define cross 3
#define vertical 3

#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>

//清理棋盘
void clean(char board[cross][vertical], int cro, int ver);

//画棋盘
void boa(char board[cross][vertical], int cro, int ver);

//玩家输入
void play(char board[cross][vertical], int cro, int ver);

//电脑输入
void computer(char board[cross][vertical], int cro, int ver);

//判断输赢
char judge(char board[cross][vertical], int cro, int ver);
