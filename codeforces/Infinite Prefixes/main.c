#include <stdio.h>

int vabs(int a)
{
	return (a < 0 ? -a : a);
}

int solve_this_test(char *str, int zeros, int ones, int x, int n)
{
	int	i;
	int	j;
	int r;
	int temp;
	int	diff;
	int	start;

	r = 0;
	diff = zeros - ones;
	if (!diff)
		return (-1);
	start = x / vabs(diff);
	i = start < 1 ? 0 : start - 1;
	while (i < start + 1)
	{
		temp = diff * i;
		j = 0;
		while (j < n)
		{
			if (str[j] == '0')
				temp++;
			else
				temp--;
			if (temp == x)
				r++;
			j++;
		}
		i++;
	}
	if (x == 0)
		r++;
	return (r);
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n;
		int i;
		int x;

		scanf("%d", &n);
		scanf("%d", &i);
		x = i < 0 ? -i : i;

		char str[n];
		int	zeros = 0;
		int ones = 0;
		scanf("%c", str);
		i = 0;
		while (i < n)
		{
			scanf("%c", str + i);
			if (str[i] == '0')
				zeros++;
			else
				ones++;
			i++;
		}
		printf("%d\n", solve_this_test(str, zeros, ones, x, n)); 
	}
}
