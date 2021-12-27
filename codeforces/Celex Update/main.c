#include <stdio.h>

int main()
{
	int t, x1, x2, y1, y2;
	unsigned long long r;

	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &x1);
		scanf("%d", &y1);
		scanf("%d", &x2);
		scanf("%d", &y2);
		
		r = y2 - y1;
		r *= x2 - x1;
		printf("%llu\n", r + 1);
	}
	return (0);
}
