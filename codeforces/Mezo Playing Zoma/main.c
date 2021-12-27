#include <stdio.h>

int	main()
{
	int		n;
	int		l;
	int		r;
	char	c;

	scanf("%d", &n);
	l = 0;
	r = 0;
	while (n--)
	{
		scanf("%c", &c);
		if (c == 'L')
			l++;
		else
			r++;
	}
	printf("%d\n", l + r + 1);
	return (0);
}
