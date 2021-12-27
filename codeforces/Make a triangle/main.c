#include <stdio.h>

int main()
{
	int a;
	int	b;
	int c;

	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &c);
	if (a < b)
	{
		int temp;
		temp = a;
		a = b;
		b = temp;
	}
	if (a < c)
	{
		int temp;
		temp = a;
		a = c;
		c = temp;
	}
	int i = 0;
	while (a >= b + c + i)
		i++;
	printf("%d\n", i);
	return (0);
}
