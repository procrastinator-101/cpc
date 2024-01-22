#include <cmath>
#include <cstddef>
#include <string>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;
double myPow(double x, int n)
{
	long	p;
	double	ret;

	ret = 1;
	p = n;
	p = abs(p);

	while (p > 0)
	{
		if (p % 2)
		{
			ret *= x;
			p--;
		}
		else
		{
			x *= x;
			p /= 2;
		}
	}
	return (n < 0 ? 1 / ret : ret);
}

int main()
{
	cout << myPow(3, 7) << endl;
}