#include <iostream>

using namespace std;

int main()
{
	int t, n, i, s;

	cin >> t;
	while (t--)
	{
		cin >> n;
		if (n % 4)
			cout << "NO" << endl;
		else
		{
			s = 0;
			cout << "YES" << endl;
			for (i = 2; i <= n; i += 2)
			{
				s += i;
				cout << i << ' ';
			}
			for (i = 1; i < n - 1; i += 2)
			{
				s -= i;
				cout << i << ' ';
			}
			cout << s << endl;
		}
	}
	return (0);
}
