#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int t, n, c, r, size;

	cin >> t;
	while (t--)
	{
		cin >> n >> c;
		r = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> size;
			r += size / c + (size % c ? 1 : 0);
		}
		cout << r << endl;
	}


}
