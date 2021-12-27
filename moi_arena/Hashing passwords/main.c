#include <stdio.h>


char encrypt(char c, int key)
{
	if (c < 'A' || (c > 'Z' && c < 'a') || (c > 'z'))
		return (c);
	if (c < 91)
		return (c + key <= 'Z' ? c + key : c + key - 26);
	return (c + key <= 'z' ? c + key : c + key - 26);
}

int main()
{
	int t, n, x, zeros;
	char str[100001];

	scanf("%d", &t);
	while (t--)
	{
		scanf("%s", str);
		scanf("%d", &n);
		x = 1;
		zeros = 0;
		for (int i = 0; str[i]; i++)
		{
			if (str[i] > 48 && str[i] < 58)
			{
				x = (x * ((str[i] - 48) % n)) % n;
				str[i] = 48;
				zeros++;
			}
		}
		if (!zeros)
			x = 0;
		else
			x %= 26;
		for (int i = 0; str[i]; i++)
			str[i] = encrypt(str[i], x);
		printf("%s\n", str);
	}
	return (0);
}
