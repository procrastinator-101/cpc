#include <stdio.h>

int firstUniqChar(char * s)
{
	int i, j;

	for (i = 0; s[i]; i++)
	{
		for (j = 0; s[j]; j++)
			if (s[i] == s[j] && i != j)
				break ;
		if (!s[j])
			return (i);
	}
	return (-1);
}

int main()
{
	printf("r = %d\n", firstUniqChar("cc"));
	return (0);
}
