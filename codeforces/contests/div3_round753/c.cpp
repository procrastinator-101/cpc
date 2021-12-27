#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int t, n, ret, last;

	cin >> t;
	while (t--)
	{
		cin >> n;
		int arr[n];
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		sort(arr, arr + n);
		ret = arr[0];
		last = arr[0];
		for (int i = 1; i < n; i++)
		{
			arr[i] -= last;
			if (arr[i] > ret)
				ret = arr[i];
			last += arr[i];
		}
		cout << ret << endl;
	}
	return 0;
}
