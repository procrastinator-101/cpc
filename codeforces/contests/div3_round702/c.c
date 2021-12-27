#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int	t;
	unsigned long long x;
	unsigned long long i;
	unsigned long long j;
	unsigned long long end;

	cin >> t;
	while (t--)
	{
		cin >> x;
		end = ceil(exp(log(x) / 3));
		j = 0;
		//cout << "end = " << end << endl;
		for (i = 0; i < end; i++)
		{
			for (j = 0; j < end; j++)
				if (i * i * i + j * j * j == x)
				{
					//cout << "x = " << x << "\ta = " << i << "\tb = " << j << endl;
					cout << "YES" << endl;
					break ;
				}
			if (j <  end)
				break;
		}
		if (j == end)
			cout << "NO" << endl;
		
	}
	return (0);
}
