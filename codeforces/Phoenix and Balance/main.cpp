#include <stdio.h>
#include <stdlib.h>


int main()
{
	int t, n;

	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		printf("%d\n", (1 << (n / 2 + 1)) - 2);
	}
	return (0);
}
