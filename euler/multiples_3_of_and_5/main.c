#include <stdio.h>

int main()
{
	int i;
	int sum;

	i = 0;
	sum = 0;
	while (++i < 1000)
		if (i % 5 == 0 || i % 3 == 0)
			sum += i;
	printf("%d\n", sum);
	return (0);
}
