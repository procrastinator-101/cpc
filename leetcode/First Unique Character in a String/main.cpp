#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <limits.h>
#include <map>
#include <set>
#include <stack>
#include <stdio.h>
#include <string>
#include <string.h>
#include <utility>
#include <vector>

using namespace std;

int firstUniqChar(string s)
{
	int	arr[26];
	int count = 0;
	char uniq[26];

	memset(uniq, 0, sizeof(uniq));
	memset(arr, 0xff, sizeof(arr));
	for (int i = 0; i < s.size(); i++)
	{
		if (arr[s[i] - 'a'] == -1)
		{
			arr[s[i] - 'a'] = i;
			uniq[count++] = i;
		}
		else
			arr[s[i] - 'a'] = -2;
	}
	for (int i = 0; i < 26; i++)
	{
		if (arr[i] >= 0)
			return arr[i];
	}
	return 0;
}

int main()
{
	cout << firstUniqChar("leetcode") << endl;
	return (0);
}
