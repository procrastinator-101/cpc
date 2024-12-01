#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
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

int findLeastNumOfUniqueInts(vector<int>& arr, int k)
{
	map<int, int> occurences;
	multiset<int> frequencies;

	for (int i = 0; i < arr.size(); i++)
	{
		occurences[arr[i]]++;
	}
	for (map<int, int>::iterator it = occurences.begin(); it != occurences.end(); ++it)
	{
		frequencies.insert(it->second);
	}
	for (multiset<int>::iterator it, next = frequencies.begin();
		 next != frequencies.end(); )
	{
		it = next++;
		if (k >= *it)
		{
			k -= *it;
			frequencies.erase(it);
		}
		else
			break;
	}
	// for (multiset<int>::iterator it = frequencies.begin(); it != frequencies.end(); ++it)
	// {
	// 	cout << *it << " | ";
	// }
	// cout << endl;
	// cout << endl << k << " " << frequencies.size() << endl;
	return frequencies.size();
}

int main(int argc, char** argv)
{
	vector<int> nums;
	for (int i = 1; i < argc - 1; i++)
		nums.push_back(atoi(argv[i]));
	long long ret = findLeastNumOfUniqueInts(nums, atoi(argv[argc - 1]));
	cout << endl << "========================================" << endl;
	cout << ret;
	cout << endl << "========================================" << endl;
	return 0;
}