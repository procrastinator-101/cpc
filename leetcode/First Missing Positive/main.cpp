#include <cmath>
#include <cstddef>
#include <string>
#include <iostream>
#include <stack>
#include <vector>
#include <climits>
#include <algorithm>


using namespace std;

// int firstMissingPositive(vector<int>& nums)
// {
// 	int     i;

// 	int size = *(max_element(nums.begin(), nums.end())) + 1;
// 	vector<bool> n(size, 0);
	
// 	cout << size << endl;
// 	for (i = 0; i < nums.size(); i++)
// 	{
// 		if (nums[i] >= 0)
// 			n[nums[i]] = 1;
// 	}
// 	for (i = 1; i < size && n[i]; i++)
// 		cout << n[i] << " ";
// 	cout << endl;
// 	return i;
	
// }

int firstMissingPositive(vector<int>& nums)
{
	sort(nums.begin(), nums.end());

	int ret = 1;
	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] > 0)
		{
			if (nums[i] > ret)
				return ret;
			else if (nums[i] == ret)
				ret++;
		}
	}
	return ret;
}

int main()
{
	vector<int> vec = {0,2,2,1,1};
	cout << firstMissingPositive(vec) << endl;
}