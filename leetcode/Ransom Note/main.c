#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int	count_character(char *str, char c)
{
	int i;
	int r;

	r = 0;
	i = -1;
	while (str[++i])
		if (str[i] == c)
			r++;
	return (r);
}

bool canConstruct(char *ransomNote, char *magazine)
{
	char	c;
	int		count1;
	int		count2;

	c = 96;
	while (++c < 123)
	{
		count1 = count_character(magazine, c);
		count2 = count_character(ransomNote, c);
		if (count2 > count1)
			return (0);
	}
	return (1);
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
	printf("r = %d\n", canConstruct(j, s));
	return (0);
}
