#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int t;
	int	size;

	cin >> t;
	while (t--)
	{
		cin >> size;
		int	arr[size];
		int	nums[size];
		int	sums[size];
		vector <int> ret;
		for (int i = 0; i < size; i++)
		{
			cin >> arr[i];
			nums[i] = arr[i];
		}
		sort(arr, arr + size);
		sums[0] = 0;
		for (int i = 1; i < size; i++)
		{
			if (arr[i] != arr[i - 1])
				sums[i] = sums[i - 1] + arr[i - 1];
			else
				sums[i] = sums[i - 1];
		}
		for (int i = size - 1; i >= 0; i--)
		{
			if (arr[i] >= sums[i])
				ret.push_back(i + 1);
		}
		cout << ret.size() << endl;
		for (int i = ret.size() - 1; i >= 0; i--)
			cout << ret[i] << ' ';
		cout << endl;

	}
	return (0);
}
