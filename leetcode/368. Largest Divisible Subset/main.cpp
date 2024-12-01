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

vector<int>	findsubset(vector<int>& nums, vector<vector<int>>& candidates, vector<vector<int>>& multipliers, int numIdx)
{
	vector<int>	tmp;
	vector<int>	ret;

	for (int i = 0; i < multipliers[numIdx].size(); i++)
	{
		if (candidates[multipliers[numIdx][i]].empty())
		{
			tmp = findsubset(nums, candidates, multipliers, multipliers[numIdx][i]);
			if (tmp.size() > ret.size())
				ret.swap(tmp);
		}
		else if (candidates[multipliers[numIdx][i]].size() > ret.size())
			ret = candidates[multipliers[numIdx][i]];
	}
	ret.insert(ret.begin(), nums[numIdx]);
	candidates[numIdx] = ret;
	return ret;
}
vector<int> largestDivisibleSubset(vector<int>& nums)
{
	vector<int> ret;
	vector<vector<int>>	candidates(nums.size());
	vector<vector<int>>	multipliers(nums.size());

	sort(nums.begin(), nums.end());
	for (int i = 0; i < nums.size(); i++)
	{
		for (int j = i + 1; j < nums.size(); j++)
		{
			if (nums[j] % nums[i] == 0)
				multipliers[i].push_back(j);
		}
	}

	vector<int>	tmp;

	for (int i = 0; i < nums.size(); i++)
	{
		if (candidates[i].empty())
		{
			tmp = findsubset(nums, candidates, multipliers, i);
			if (tmp.size() > ret.size())
				ret.swap(tmp);
		}
		else if (candidates[i].size() > ret.size())
			ret = candidates[i];
	}
	
	for (int i = 0; i < multipliers.size(); i++)
	{
		cout << nums[i] << " -->   ";
		for (int j = 0; j < multipliers[i].size(); j++)
		{
			cout << nums[multipliers[i][j]] << " ";
		}
		cout << endl;
	}
	return ret;
}

int main(int argc, char** argv)
{
	vector<int> nums;
	for (int i = 1; i < argc; i++)
		nums.push_back(atoi(argv[i]));
	vector<int> ret = largestDivisibleSubset(nums);
	cout << endl << "========================================" << endl;
	for (int i = 0; i < ret.size(); i++)
		cout << ret[i] << " ";
	cout << endl << "========================================" << endl;
	return 0;
}