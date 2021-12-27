#include <stdio.h>
#include <string.h>

void	ft_swap(char *a, char *b)
{
	char temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_bubble_sort(char *str, int len)
{
	int i;
	int j;

	i = -1;
	while (++i < len)
	{
		j = -1;
		while (++j < len - i - 1)
		{
			if (str[j] > str[j + 1])
				ft_swap(str + j, str + j + 1);
		}
	}
}

int	ft_iterative_binsearch(char *arr, int size, char val)
{
	int	l;
	int	h;
	int	mid;

	l = 0;
	h = size - 1;
	while (l <= h)
	{
		mid = l + (h - l) / 2;
		if (arr[mid] == val)
			return (mid);
		else if (arr[mid] < val)
			l = mid + 1;
		else
			h = mid - 1;
	}
	return (-1);
}

int numJewelsInStones(char * J, char * S)
{
	int i;
	int r;
	int len;

	len = strlen(J);
	ft_bubble_sort(J, len);
	r = 0;
	i = -1;
	while (S[++i])
		if (ft_iterative_binsearch(J, len, S[i]) != -1)
			r++;
	return (r);
}

int main()
{
	int		size_j;
	int		size_s;
	char	j[50];
	char	s[50];

	size_j = scanf("%s", j);
	size_s = scanf("%s", s);
	//j[size_j - 1] = 0;
	//s[size_s - 1] = 0;
	printf("j = %s|\n", j);
	printf("s = %s|\n", s);
	printf("r = %d\n", numJewelsInStones(j, s));
	return (0);
}
