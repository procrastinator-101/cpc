#include <iostream>

using namespace std;

int main()
{
	int t, a, b, c, d, x, y, x1, y1, x2, y2;

	cin >> t;
	while (t--)
	{
		cin >> a >> b >> c >> d >> x >> y >> x1 >> y1 >> x2 >> y2;
		if (abs(a - b) > (a < b ? x2 - x : x - x1))
		{
			cout << "NO" << endl;
			continue;
		}
		if (abs(c -d) > (c < d ? y2 - y : y - y1))
		{
            cout << "NO" << endl;
            continue;
        }
		if (((a || b) && (x == x2 && x == x1)) || ((c || d) && (y == y2 && y == y1)))
		{
            cout << "NO" << endl;
            continue;
        }
		cout << "YES" << endl;
	}
	return (0);
}
