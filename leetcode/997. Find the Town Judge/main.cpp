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

int findJudge(int n, vector<vector<int>>& trust)
{
	int	ret;
	map<int, int>	candidates;

	for (int i = 1; i <= n; i++)
		candidates[i] = 0;
	for (int i = 0; i < trust.size(); i++)
	{
		candidates[trust[i][0]] = INT_MIN;
		candidates[trust[i][1]]++;
	}
	ret = -1;
	for (map<int, int>::iterator it = candidates.begin(); it != candidates.end(); ++it)
	{
		cout << it->first << " : " << it->second << endl;
		if (it->second == n - 1)
		{
			if (ret == -1)
				ret = it->first;
			else
				return -1;
		}
	}
	return ret;
}

int main(int argc, char** argv)
{
	// int data[][2] = { { 0, 10 }, { 1, 5 }, { 2, 7 }, { 3, 4 } }; int n = 2;
	int data[][2] = { { 1, 20 }, { 2, 10 }, { 3, 5 }, { 4, 9 }, { 6, 8 } };
	int n		  = 3;
	vector<vector<int>> trust;

	for (int i = 0; i < sizeof(data) / (sizeof(int) * 2); i++)
	{
		vector<int> tmp;
		tmp.push_back(data[i][0]);
		tmp.push_back(data[i][1]);
		trust.push_back(tmp);
	}
	for (int i = 0; i < trust.size(); i++)
	{
		for (int j = 0; j < trust[i].size(); j++)
			cout << trust[i][j] << " ";
		cout << endl;
	}
	int ret = findJudge(n, trust);
	cout << endl << "========================================" << endl;
	cout << ret;
	cout << endl << "========================================" << endl;
	return 0;
}