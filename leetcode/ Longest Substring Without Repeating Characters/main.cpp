#include <cstddef>
#include <string>
#include <iostream>

using namespace std;

int lengthOfLongestSubstring(string s)
{
	int ret;
	int dist;
	bool arr[255];
	int index[255];

	ret = 0;
	dist = 0;
	for (int i = 0; i < 255; i++)
		arr[i] = 0;
	int i = 0, k = 0;
	for (; i < s.size(); i++)
	{
		if (arr[s[i]])
		{
			dist = i - k;
			for (int j = k; j < index[s[i]]; j++)
				arr[s[j]] = 0;
			k = index[s[i]] + 1;
			index[s[i]] = i;
			if (ret < dist)
				ret = dist;
		}
		else
		{
			arr[s[i]] = 1;
			index[s[i]] = i;
		}
	}
	if (!arr[i])
	{
		dist = i - k;
		if (ret < dist)
			ret = dist;
	}
	return ret;
}

int main()
{
	string s = "pwwkew";

	cout << lengthOfLongestSubstring(s) << endl;
}