#include <cmath>
#include <cstddef>
#include <iterator>
#include <string>
#include <iostream>
#include <stack>
#include <vector>
#include <climits>
#include <algorithm>


using namespace std;

int nextStep(vector<int>& nums, int start, int end)
{
	int	ret = start;
	for (int i = start + 1; i < end && i < nums.size(); i++)
	{
		if (nums[ret] <= nums[i])
			ret = i;
	}
	return ret;
}

int jump(vector<int>& nums)
{
	int	i;
	int	k;
	int	ret = 0;
	int	dist = 0;
	for (i = 0; i < nums.size() - 1;)
	{
		if (nums[i] + i >= nums.size() - 1)
			return ret;
		k = i + 1;
		dist = nums[i];
		for (int j = i + 1; j < nums.size() && j < nums[i] + i; j++)
		{
			if (nums[i] + nums[j] >= dist)
			{
				k = j;
				dist = nums[i] + nums[j];
			}
			if (i + dist >= nums.size() - 1)
				return ret + 2;
		}
		i = k;
		ret++;
	}
	return ret;
}

int main()
{
	vector<int> vec = {1,2,1,1,1};
	cout << jump(vec) << endl;
}