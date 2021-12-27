#include <stdio.h>

int main()
{
	int t, n, m, r;

	scanf("%d", &t);

	while (t--)
	{
		scanf("%d", &n);
		scanf("%d", &m);
	
		r = n * m + 1;
		printf("%d\n", r / 2);
	}
	return (0);
}
