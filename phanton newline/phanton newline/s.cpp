#define _CRT_SECURE_NO_WARNINGS	1
#include <stdio.h>
int main()
{
	char a,b;
	printf("please type a letter\n");
	scanf("%c", &a);
	printf("%d\n", a);
	printf("type another letter:\n");
	scanf("\n%c", &b);
	printf("%d", b);







	return 0;
}