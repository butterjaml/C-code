#define _CRT_SECURE_NO_WARNINGS	1
#include"game.cpp"
char mine[11][11];
char show[11][11];
void game()
{
	
	initialmine(mine, '0');
	initialmine(show, '*');
	printboard(show);
	setmine(mine);
	printboard(mine);
	findmine(show,mine);
}
int main()
{
	int choice;
	printf("**************************\n");
	printf("******1.start game********\n");
	printf("******0.quit  game********\n");
	printf("**************************\n");
	printf("please enter the choice:");
	do {
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			game();
			if (stopyfy(show)  == 10) { printf("you win!lucky you!\nunlike me,i still can not figure out how to play this game\n"); }
			else { printf("game over,wanna try again?\nif your eyes are ok after reading those letters...\n"); }
			printf("enter you choice(1or0):");
			break;
		case 0:
			printf("end of the game\n");
			break;
		default:printf("please choose again\n");
			break;
		}
	} while (choice);
	return 0;
}
