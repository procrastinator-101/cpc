#include <cstddef>
#include <string>
#include <iostream>

using namespace std;

int reverse(int x)
{
	int ret = 0;
	int msd = x % 10;

	while (x > 10 || x < -10)
	{
		ret = ret * 10 + x % 10;
		x /= 10;
	}
	cout << msd << " " << ret << " " << x << endl;
	// if (ret < 0)
	// {
	// 	if ((msd < -2 && ret <= -100000000) || (msd == -2 && ret <= -147483648))
	// 		return 0;
	// }
	// else if ((msd > 2 && ret >= 100000000) || (msd == 2 && ret >= 147483647))
	// 	return 0;
	if (ret < -214748364 || (ret == -214748364 && x == -9))
		return 0;
	if (ret > 214748364 || (ret == 214748364 && x > 7))
		return 0;
	return ret * 10 + x % 10;
}


int main()
{

	cout << reverse(-2147483412) << endl;
}