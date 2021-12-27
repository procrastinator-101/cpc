#include <stdio.h>

int main()
{
	int n;
	int k;
	int val;
	int size;

	scanf("%d", &n);
	
	size = (n + 1) / 2;
	int m[n + 1];
	m[0] = 0;
	for (int i = 1; i < size + 1; i++)
	{
		scanf("%d", m + i);
		m[i] += m[i - 1];
	}
	scanf("%d", &val);
	for (int i = size + 1; i < n + 1; i++)
		m[i] = val + m[i - 1];
	k = 1;
	for (int i = 1; i < n + 1; i++)
	{
		if (m[i] < m[i - 1])
			k++;
		printf("%d ", m[i]);
	}
	printf("\n%d\n", k);
	return (0);
}

