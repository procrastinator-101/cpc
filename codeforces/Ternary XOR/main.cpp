#include <iostream>

using namespace std;

int main()
{
	int t, n, i, k;

	cin >> t;
	while (t--)
	{
		cin >> n;
		char a[n + 1];
		char b[n + 1];
		char c[n + 1];
		a[n] = 0;
		b[n] = 0;
		c[n] = 0;
		scanf("%s", c);
		k = 0;
		for (i = 0; i < n; i++)
		{
			if (k)
			{
				a[i] = '0';
				b[i] = c[i];
			}
			else
			{
				if (c[i] == '2')
				{
					a[i] = '1';
					b[i] = '1';
				}
				else if (c[i] == '0')
				{
					a[i] = '0';
					b[i] = '0';
				}
				else if (c[i] == '1')
				{
					a[i] = '1';
					b[i] = '0';
					k = 1;
				}
			}
		}
		cout << a << endl << b << endl;
	}
	return (0);
}
