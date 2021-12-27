#include <stdio.h>

int main()
{
	int n, c, t, r, temp, count;

	r = 0;
	count = 0;
	scanf("%d", &n);
	scanf("%d", &t);
	scanf("%d", &c);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &temp);
		if (temp <= t)
		{
			count++;
			if (count >= c)
				r++;
		}
		else
			count = 0;
	}
	printf("%d\n", r);
}
