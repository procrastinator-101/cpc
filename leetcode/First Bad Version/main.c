#include <stdio.h>
#include <stdbool.h>

#define F 5000
#define MINI 4

bool isBadVersion(int version)
{
	if (version > MINI)
		return (1);
	return (0);
}

int firstBadVersion(int n)
{
	int	middle;
	int	lower_bound;
	int	upper_bound;

	lower_bound = 1;
	upper_bound = n;
	while (lower_bound != upper_bound)
	{
		middle = lower_bound + (upper_bound - lower_bound) / 2;
		if (isBadVersion(middle))
			upper_bound = middle;
		else
			lower_bound = middle + 1;
	}
	return (upper_bound);
}

int main()
{
	printf("a = %d\n", firstBadVersion(F));
	return (0);
}
