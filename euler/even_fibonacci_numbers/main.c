#include <stdio.h>

int main()
{
	long				fibo1;
	long				fibo2;
	long				temp;
	unsigned long long	sum;

	sum = 2;
	fibo1 = 1;
	fibo2 = 2;

	while (fibo2 < 4000001)
	{
		temp = fibo2;
		fibo2 += fibo1;
		fibo1 = temp;
		if (fibo2 % 2 == 0)
			sum += fibo2;
	}
	printf("%llu", sum);
	return (0);
}
