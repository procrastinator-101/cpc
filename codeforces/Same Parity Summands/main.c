#include <stdio.h>

int main()
{
	int t, n, k, parity;

	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		scanf("%d", &k);

		if (n % 2 && (k > n || k % 2 == 0))
		{
			printf("NO\n");
			continue ;
		}
		else if (n % 2 == 0 && ((k * 2 > n && k % 2) || (k > n && k % 2 == 0)))
		{
			printf("NO\n");
			continue ;
		}
		printf("YES\n");
		parity = (n / k + n % k) % 2;
		while (n > 0)
		{
			printf("%d ", n / k + ((n / k) % 2 != parity));
			n -= n / k + ((n / k) % 2 != parity);
			k--;
			//printf("n = %d k = %d\n", n, k);
		}
		printf("\n");
	}
	return (0);
}
