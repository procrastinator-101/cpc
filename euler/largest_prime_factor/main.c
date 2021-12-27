#include <stdio.h>

int is_prime(unsigned long long n)
{
	unsigned long long i;

	if (n % 5 == 0 || n % 2 == 0 || n % 3 == 0)
		return (0);
	i = 1;
	while (++i < n / 2)
		if (n % i == 0)
			return (1);
	return (0);
}

int main()
{
	unsigned long long val;
	unsigned long long i;

	val = 600851475143;
	i = val / 2;
	while (--i)
	{
		if (val % i == 0 && is_prime(i))
		{
			printf("%llu\n", i);
			return (0);
		}
	}
	return (0);
}
