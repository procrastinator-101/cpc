#include <iostream>
#include <stdio.h>

using namespace std;

namespace solution
{
	int go_home(int s, int u[][2])
	{
		int r;
		int temp;
		int done;

		r = 0;
		done = 0;
		while (1)
		{
			for (int i = 0; i < s; i++)
			{
				if (u[i][0] != u[i][1])
				{
					temp = u[i][1] - 1;
					done++;
					u[i][1] = u[temp][1];
					u[temp][1] = temp + 1;
					r++;
				}
			}
			if (done <= 1)
				return (r);
			done = 0;
		}
		return (r);
	}
}

int main()
{
	int n, s, a, b, d, r;
	char str[3];

	cin >> n >> s;

	int u[s][2];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < s; j++)
		{
			cin >> a;
			d = scanf("%2s", str);
			if (d)
				d = d;
			cin >> b;
			u[a - 1][0] = a;
			u[a - 1][1] = b;
		}
		cout << solution::go_home(s, u) << endl;
	}
	return (0);
}
