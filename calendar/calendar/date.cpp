#define _CRT_SECURE_NO_WARNINGS	1
#include <stdio.h>
int main()
{
	int y, m, d, w, e;

	scanf("%d %d %d", &y, &m, &d);
	if (m == 2)
	{
		if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
			e = 29;
		else
			e = 28;
	}
	if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
		e = 31;
	if (m == 4 || m == 6 || m == 9 || m == 11)
		e = 30;
	if (m == 1 || m == 2)
	{
		m = m + 12;
		y = y - 1;
		w = (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400 + 1) % 7 + 1;
	}
	if (2 < m)
		w = (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400 + 1) % 7;
	printf("%d\n%d", e, w);
	return 0;
}