#include <stdio.h>
#include <string.h>

int main()
{
	int i, n, len;
	char t[101];

	scanf("%d", &n);
	while (n--)
	{
		scanf("%s", t);
		len = strlen(t);
		for (i = 1; i < len && t[i] == t[i - 1]; i++);
		if (i < len)
		{
			printf("%c", t[0]);
			for (i = 1; i < len; i++)
			{
				if (t[i] == t[i - 1])
						printf("%c", t[i - 1] == '0' ? '1' : '0');
				printf("%c", t[i]);
			}
			printf("\n");
		}
		else
			printf("%s\n", t);
	}
}
