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

// bool compare(vector<int> a, vector<int> b)
// {
// 	return b[1] < a[1];
// }

struct myclass
{
	bool operator()(vector<int> a, vector<int> b)
	{
		return b[1] < a[1];
	}
} compare;

string frequencySort(string s)
{
	string ret;
	vector<int> arr[75];
	for (int i = 0; i < 75; i++)
	{
		arr[i].push_back('0' + i);
		arr[i].push_back(0);
	}
	for (int i = 0; i < s.size(); i++)
		arr[s[i] - '0'][1]++;
	sort(arr, arr + 75, compare);
	for (int i = 0; i < 75; i++)
	{
		ret.append(arr[i][1], arr[i][0]);
	}
	return ret;
}

int main(int argc, char** argv)
{
	if (argc > 1)
	{
		cout << frequencySort(argv[1]) << endl;
	}

	return 0;
}