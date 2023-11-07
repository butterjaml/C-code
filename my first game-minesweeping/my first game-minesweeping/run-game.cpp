#define _CRT_SECURE_NO_WARNINGS	1
#include"game.cpp"
 
void initialmine(char board[11][11], char m) {
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 11; j++) {
			board[i][j] = m;

		}
	}


}
void printboard(char board[][11]) {

	printf("--------------------\n");
	for (int i = 0; i < 10; i++) {
		printf("%d ", i);
	}printf("\n");
	for (int i = 1; i<10; i++)
	{
		printf("%d ", i);
		for (int j = 1; j < 10; j++) {
			printf("%c ", board[i][j]);

		}printf("\n");
	}
	printf("--------------------\n");

}

void setmine(char board[11][11]) {
	int count = 11;
	srand((unsigned)time(NULL));
	while (count) {
		int i, j;
		i = rand() % 9 + 1;
		j = rand() % 9 + 1;
		if (board[i][j] != 1) { board[i][j] = '1'; count--; }
	}

}


int minecount(char mine[][11],int i, int j) {

	int num = mine[i - 1][j - 1] + mine[i - 1][j + 1] + mine[i - 1][j] + mine[i + 1][j] + mine[i][j + 1] + mine[i][j - 1] + mine[i + 1][j + 1] + mine[i + 1][j - 1] - 8 * '0';
	
	return num;
}

void findmine(char show[][11], char mine[][11]) {

	int  i, j;
	
	 while (stop(show))
	 {
		


	 
		 printf("enter coordinate:\n");
		 scanf("%d%d", &i, &j);
		 if (i < 0 || i>10 || j < 0|| j>10)
		 {
			 printf("illegal input,please try again:\n");
		 }
		 else {
			 if (mine[i][j] == '1')
			 {
				 
				 printf("booooom!!!\n"); 
				 printboard(mine);
	
				 break;
			 }

			 else {
				 
				 explode(mine,show,  i,  j);

				 printboard(show);



			 }
		 }



	 }


}


void explode(char mine[][11], char show[][11], int i, int j) {
	
	int count = minecount(mine, i, j);
	if (count == 0) {
		int x = 0;
		show[i][j] = count + '0';
		for (x = i - 1; x <= i + 1; x++) {
			int y = 0;
			for (y = j - 1; y <= j + 1; y++) {
				if (show[x][y] == '*') {

					explode(mine, show, x, y);
				}

			}
		}
	

	}
	else { show[i][j] = count + '0'; }
	

}
int stopyfy(char show[][11]) {
	int count=0;
	for (int i = 1; i < 10; i++) {
		for (int j = 1; j < 10; j++) {
			if (show[i][j] == '*') { count++; }

		}
	}

	return count;
}
int stop(char show[][11]) {
	
	if (stopyfy(show) == 10) { return 0; }
	else { return 1; }
}