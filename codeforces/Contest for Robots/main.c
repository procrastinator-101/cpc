#include <stdio.h>

int main()
{
	int	i;
	int	n;
	int	r;
	int	b;
	int	num;

	scanf("%d", &n);
	r = 0;
	b = 0;
	for (int i = 0; i < n; i++, r += num)
		scanf("%d", &num);
	for (int i = 0; i < n; i++, b += num)
		scanf("%d", &num);

	return (0);
}
