#include <iostream>

using namespace std;

int main()
{
	int n, a, sec, r, l;
	char c;

	cin >> n;
	a = 0;
	sec = 0;
	r = 0;
	l = 0;
	while (n--)
	{
		cin >> c;
		a = c == '(' ? a + 1 : a - 1;
		r = c == '(' ? r + 1 : r;
		l = c == ')' ? l + 1 : l;
		if (a < 0 || (!a && c == '('))
			sec++;
	}
	cout << (l == r ? sec : -1) << endl;
	return (0);
}
