#include <iostream>
#include <math.h>

using namespace std;

int msb(long long num)
{
	int i;
	int n;

	i = -1;
	n = sizeof(long long) * 8;
	while (++i < n && num >> i);
	return (i);
}

int main()
{
	int t;

	cin >> t;
	while (t--)
	{
		int n, p, sec;
		long long old, current, diff;

		sec = 0;
		cin >> n;
		cin >> old;
		for (int i = 1; i < n; i++)
		{
			cin >> current;
			diff = old - current;
			if (diff > 0)
			{
				p = msb(diff);
				if (p > sec)
					sec = p;
				current += diff;
			}
			old = current;
		}
		cout << sec << endl;
	}
	return (0);
}
