#include <stdio.h>

int main()
{
	int t;
	scanf("%d", &t);

	while (t--)
	{
		int n;
		scanf("%d", &n);
		int ones;
		if (n % 2 == 0)
			ones = n / 2;
		else
		{
			ones = n / 2 - 1;
			printf("7");
		}
		while (ones--)
			printf("1");
		printf("\n");
	}
}
