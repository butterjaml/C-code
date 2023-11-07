#define _CRT_SECURE_NO_WARNINGS	1
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void game();
void printboard(char board[][11]);
void initialmine(char board[11][11], char m);
void setmine(char board[11][11]);
void findmine(char show[][11], char mine[][11]);
int minecount(char mine[][11], int i, int j);
void explode(char mine[][11], char show[][11], int i, int j);
int stop(char show[][11]);
int stopyfy(char show[][11]);
