#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, i, j, d, bound, odd, even;

	scanf("%d", &n);
	d = n / 2;
	odd = 1;
	even = 2;
	for (i = 0; i < n; i++)
	{
		bound = i <= n / 2 ? i : n - i - 1;
		for (j = 0; j < n; j++)
		{
			if (j >= d - bound && j <= d + bound)
			{
				printf("%d ", odd);
				odd += 2;
			}
			else
			{
				printf("%d ", even);
				even += 2;
			}
		}
		printf("\n");
	}
	return (0);
}
