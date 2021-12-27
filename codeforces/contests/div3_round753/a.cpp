#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	string keyboard;
	string s;
	int t, dist, last, current;

	cin >> t;
	while (t--)
	{
		cin >> keyboard >> s;

		dist = 0;
		last = keyboard.find(s[0]);
		for (int i = 1; i < s.length(); i++)
		{
			current = keyboard.find(s[i]);
			dist += abs(last - current);
			last = current;
		}
		cout << dist << endl;
	}
	return 0;
}
