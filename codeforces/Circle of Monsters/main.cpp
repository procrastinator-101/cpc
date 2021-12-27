#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;

int main()
{
	int t, i, n, ci, ni;
	long long r, mn, first;
	long long a[3], b[3];

	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		r = 0;
		mn = LLONG_MAX;
		first = 0;
		ci = 0;
		ni = 1;
		scanf("%lld%lld", a, b);
		a[2] = a[0];
		b[2] = b[0];
		for (i = 0; i < n; i++, ci = !ci, ni = !ni)
		{
			if (i < n - 1)
				scanf("%lld%lld", a + ni, b + ni);
			else
				ni = 2;
			first = a[ni] - max(0ll, a[ni] - b[ci]);
			r += a[ni] - min(a[ni], b[ci]);
			mn = min(mn, first);
		}
		r += mn;
		cout << r << endl;
	}
	return (0);
}
