#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int t, n, sp, s;

	cin >> t;
	while (t--)
	{
		vector <int> r;
		cin >> n;
		for (int i = 1; i <= n; n -= i, i *= 2)
			r.push_back(i);
		if (n > 0)
		{
			r.push_back(n);
			sort(r.begin(), r.end());
		}
		cout << r.size() - 1 << endl;
		for (int i = 1; i < r.size(); i++)
		{
			cout << r[i] - r[i - 1];
			cout << (i < r.size() - 1 ? ' ' : '\n');
		}
	}
	return (0);
}
