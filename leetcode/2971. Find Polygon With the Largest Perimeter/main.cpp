#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <limits.h>
#include <map>
#include <set>
#include <stack>
#include <stdio.h>
#include <string.h>
#include <string>
#include <strings.h>
#include <utility>
#include <vector>
using namespace std;

long long largestPerimeter(vector<int>& nums)
{
	long long ret;
	long long sum;

	ret = -1;
	sort(nums.begin(), nums.end());
	sum = nums[0] + nums[1];
	for (int i = 2; i < nums.size(); i++)
	{
		if (nums[i] < sum)
			ret = nums[i] + sum;
		sum += nums[i];
	}
	return ret;
}

int main(int argc, char** argv)
{
	vector<int> nums;
	for (int i = 1; i < argc; i++)
		nums.push_back(atoi(argv[i]));
	long long ret = largestPerimeter(nums);
	cout << endl << "========================================" << endl;
	cout << ret << " ";
	cout << endl << "========================================" << endl;
	return 0;
}