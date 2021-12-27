#include <iostream>
#include <algorithm>

using namespace std;

#define NEXT(x)	((x + 1) % 3)

int main()
{
	int	t;
	int	num;
	int	ret;
	int	size;

	cin >> t;
	while (t--)
	{
		int arr[] = {0,0,0};

		cin >> size;
		for (int i = 0; i < size; i++)
		{
			cin >> num;
			arr[num % 3]++;
		}
		size /= 3;
		arr[0] -= size;
		arr[1] -= size;
		arr[2] -= size;
		for (ret = 0; arr[0] || arr[1] || arr[2];)
		{
			for (int i = 0; i < 3; i++)
			{
				if (arr[i] > 0)
				{
					arr[i]--;
					arr[NEXT(i)]++;
					ret++;
				}
			}
		}
		cout << ret << endl;
	}
	return (0);
}
