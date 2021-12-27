#include <stdio.h>

int main()
{
	int n, m, x, y, size_cols, size_rows;
	long long r;

	scanf("%d", &n);
	scanf("%d", &m);
	int cols[n];
	int rows[n];

	r = n;
	r *= n;
	size_cols = n;
	size_rows = n;
	for (int i = 0; i < n; i++)
	{
		cols[i] = 1;
		rows[i] = 1;
	}
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &x);
		scanf("%d", &y);
		y--;
		x--;
		if (cols[x])
		{
			cols[x] = 0;
			r -= size_rows;
			size_cols--;
		}
		if (rows[y])
		{
			rows[y] = 0;
			r -= size_cols;
			size_rows--;
		}
		printf("%lld ", r);
	}
}
