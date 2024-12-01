#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <iterator>
#include <limits.h>
#include <map>
#include <set>
#include <stack>
#include <stdexcept>
#include <stdio.h>
#include <string.h>
#include <string>
#include <strings.h>
#include <utility>
#include <vector>
using namespace std;

int furthestBuilding(vector<int>& heights, int bricks, int ladders)
{
	int i;
	long sum;
	long	sumBricks;
	multiset<int, greater<int>> sortedHeights;

	sum = 0;
	sumBricks = bricks;
	for (i = 1; i < heights.size(); i++)
	{
		if (heights[i] <= heights[i - 1])
			continue;
		sum += heights[i] - heights[i - 1];
		sortedHeights.insert(heights[i] - heights[i - 1]);
		if (sum > sumBricks)
		{
			if (ladders <= 0)
				return i - 1;
			sumBricks += *sortedHeights.begin();
			sortedHeights.erase(sortedHeights.begin());
			ladders--;
		}
	}
	return heights.size() - 1;
}

int main(int argc, char** argv)
{
	vector<int> nums;
	for (int i = 1; i < argc - 2; i++)
		nums.push_back(atoi(argv[i]));
	for (int i = 0; i < nums.size(); i++)
	{
		cout << nums[i] << " ";
	}
	cout << endl;
	long long ret = furthestBuilding(nums, atoi(argv[argc - 2]), atoi(argv[argc - 1]));
	cout << endl << "========================================" << endl;
	cout << ret;
	cout << endl << "========================================" << endl;
	return 0;
}