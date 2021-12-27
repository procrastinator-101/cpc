#include <stdio.h>
#include <string.h>

int main()
{
	int n, i, last_slash, index, action;
	char arg[201];
	char cmd[4];
	char path[10001];

	strcpy(path, "/");
	scanf("%d", &n);
	index = 0;
	while (n--)
	{
		scanf("%s", cmd);
		if (cmd[0] == 'c')
		{
			scanf("%s", arg);
			action = arg[0] == '.' ? 0 : 1;
			for (i = 0; arg[i];)
			{
				if (arg[i] == '/')
				{
					action = arg[i + 1] == '.' ? 0 : 1;
					if (i == 0)
						index = 0;
					else if (action && index)
						path[++index] = arg[i];
					i++;
				}
				if (action)
				{
					for (;arg[i] && arg[i] != '/'; i++)
						path[++index] = arg[i];
				}
				else
				{
					if (index > 0)
						path[index--] = 0;
					for (; index >= 0 && path[index] != '/'; index--)
						path[index] = 0;
					if (index > 0)
						path[index--] = 0;
					i += 2;
				}
			}
			if (index > 0)
				path[++index] = '/';
			path[index + 1] = 0;
		}
		else
			printf("%s\n", path);
	}
	return (0);
}
