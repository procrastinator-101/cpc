#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int t;
	int	ret;
	int	size;
	int	next;
	int	holder;
	int	largest;
	int	smallest;

	cin >> t;
	while (t--)
	{
		ret = 0;
		cin >> size;
		cin >> holder;
		for (int i = 1; i < size; i++)
		{
			cin >> next;
			smallest = min(next, holder); 
			largest = max(next, holder);
			while (largest > smallest * 2)
			{
				//cout << "s = " << smallest << "\tl = " << largest << endl;
				smallest *= 2;
				ret++;
			}
			holder = next;
		}
		cout << ret << endl;
	}
	return (0);
}
