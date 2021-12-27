#include <iostream>

using namespace std;

int main()
{
	int n, m, k, a, b, mov;

	cin >> n >> m >> k;
	for (int i = 0; i < 2 * k; i++)
		cin >> a >> b;
	mov = n * m + n + m - 3;
	cout << mov << endl;
	for (int i = 0; i < n - 1; i++)
		cout << 'U';
	for (int i = 0; i < m - 1; i++)
		cout << 'L';
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m - 1; j++)
			cout << (i % 2 ? 'L' : 'R');
		cout << (i < n - 1 ? 'D' : '\n');
	}
	return (0);
}
