#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int holder;

	holder = *a;
	*a = *b;
	*b = holder;
}

void	solve_this_test(int *coins, int n)
{
	int	holder;
	int remainder;

	holder = (coins[2] * 2) - (coins[0] + coins[1]);
	if (n >= holder)
	{
		if ((n - holder) % 3)
			printf("NO\n");
		else
			printf("YES\n");
	}
	else
		printf("NO\n");
}

int	main()
{
	int t;
	int coins[3];
	scanf("%d", &t);
	while (t--)
	{
		int n;
		scanf("%d", coins);
		scanf("%d", coins + 1);
		if (coins[1] < coins[0])
			ft_swap(coins + 1, coins);
		scanf("%d", coins + 2);
		if (coins[2] < coins[1])
			ft_swap(coins + 1, coins + 2);
		scanf("%d", &n);
		solve_this_test((int *)coins, n);
	}
	return (0);
}
