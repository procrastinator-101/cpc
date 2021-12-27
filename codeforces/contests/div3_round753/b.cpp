#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int t;
	long long int x, ret, n;

	cin >> t;

	while (t--)
	{
		cin >> x >> n;
		if (n % 2)
			ret = ((n + 1) / 2) % 2 ? -n : n + 1;
		else
		 	ret = ((n + 1) / 2) % 2;
		if (x % 2)
			ret = x - ret;
		else
			ret = x + ret;
		cout << ret << endl;
	}
	return 0;
}
