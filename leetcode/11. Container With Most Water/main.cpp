#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int maxArea(vector<int>& heights)
{
	int ret;
	int right;

	right = 1;
	for (int i = 2; i < heights.size(); i++)
	{
		// int dist   = i - right;
		// int height = heights[i] - heights[right];
		if (i - right + heights[i] - heights[right] >= 0)
			right = i;
	}
	ret = 0;
	for (int i = 0, qty; i < right; i++)
	{
		qty = min(heights[i], heights[right]) * (right - i);
		if (qty > ret)
			ret = qty;
	}
	// cout << left << " " << right << endl;

	return ret;
}

int main()
{
	// vector<int> nums = { 1, 2, 4, 3 };
	// vector<int> nums = { 1, 8, 6, 2, 5, 4, 8, 3, 7 };
	vector<int> nums = { 2, 3, 4, 5, 18, 17, 6 };

	int ret = maxArea(nums);
	for (int i = 0; i < nums.size(); i++)
		cout << nums[i] << " ";
	cout << endl;
	cout << ret << endl;
	return 0;
}