#include <iostream>
#include <vector>


# define MOD	1000000007

using namespace std;

int main()
{
	int n;

	cin >> n;
	int arr[n];
	vector < int > heights[n];

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		if (i > 0)
		{
			if (i != 2)
				heights[i - 1].push_back(arr[i]);
			if (i != n - 2)
				heights[i].push_back(arr[i - 1]);
		}
	}
	heights[1].push_back(arr[0]);
	heights[n - 2].push_back(arr[n - 1]);
	unsigned int ret = 0;
	
	for (int i = 0; i < n; i++)
	{
		if (heights[i].size() == 2 && heights[i][0] == heights[i][1])
			heights[i].pop_back();
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < heights[i].size(); j++)
			cout << heights[i][j] << " ";
		cout << endl;
	}
	for (int i = 0; i < n; i++)
	{
		if (i < n - 2 && heights[i].size() == 2)
		{
			if (heights[i + 2].size() == 1)
			{
				if (heights[i][0] == heights[i + 2][0])
				{
					heights[i][0] = heights[i][1];
					heights[i].pop_back();
				}
				else if (heights[i][1] == heights[i + 2][0])
					heights[i].pop_back();
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < heights[i].size(); j++)
			cout << heights[i][j] << " ";
		cout << endl;
	}
}