#include <iostream>

using namespace std;

int main()
{
	int t, n, k, i, s, temp;

	cin >> t;
	while (t--)
	{
		cin >> n >> k;
		int sums[n];
		vector <int> num;
		for (i = 0; i < n; i++)
		{
			cin >> temp;
			num.push_back(temp);
			sums[i] = temp + (i < 1 ? 0 : sums[i - 1]);
		}
		s = sums[k - 1];
		if (s <= *max_element(num.bein(), num.end()))
		{
			cout << -1 << endl;
			continue ;
		}
		for (i = 1; i < n + 1 - k; i++)
		{
			temp = sums[i + k - 1] - sums[i - 1] - s;
			if (temp > 0)
				num.insert(num.begin() + i + offset + 1, temp);
			else if (temp < 0)
				num.insert(num.begin() + i + offset + 1, -temp);

		}
	}
}
