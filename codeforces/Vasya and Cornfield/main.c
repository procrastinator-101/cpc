#include <stdio.h>

int main()
{
	int n, d, m, x, y;

	scanf("%d", &n);
	scanf("%d", &d);
	scanf("%d", &m);
	while (m--)
	{
		scanf("%d", &x);
		scanf("%d", &y);
		if (y < -x + d || y > -x + 2 * n - d || y > x + d || y < x - d)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return (0);
}
