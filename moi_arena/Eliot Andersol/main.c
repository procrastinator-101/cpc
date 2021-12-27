#include <stdio.h>

int main()
{
	int t, n, x, y, z, a, b, c, d, p;

	p = scanf("%d", &t);
	while (t--)
	{
		p = scanf("%d", &n);

		p = scanf("%d", &x);
		p = scanf("%d", &y);
		p = scanf("%d", &z);
		x *= x;
		y *= y;
		z *= z;
		a = x + y;
		b = x + z;
		c = y + z;
		d = x + y + z;
		for (int i = 1; i < n; i++)
		{
			p = scanf("%d", &x);
			p = scanf("%d", &y);
			p = scanf("%d", &z);
		
			if (p)
				p = p;
			
			x *= x;
			y *= y;
			z *= z;

			if (a != -1 && x + y != a)
				a = -1;
			if (b != -1 && x + z != b)
				b = -1;
			if (c != -1 && y + z != c)
				c = -1;
			if (d != -1 && x + y + z != d)
				d = -1;
			//printf("a = %d b = %d c = %d d = %d\n", a, b, c, d);
		}
		if ((a != -1 || b != -1 || c != -1) && d == -1)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return (0);
}
