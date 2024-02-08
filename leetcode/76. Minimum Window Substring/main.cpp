#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <limits.h>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;


string minWindow(string s, string t)
{
	int len;
	int end;
	int pivot;
	int count;
	int minLen;
	vector<int> meta(128, 0);

	if (s.empty() || t.empty() || s.length() < t.length())
	{
		return "";
	}
	minLen = s.size() + 1;
	for (int start = -1; start < (int)s.size();)
	{
		count = t.size();
		for (int j = 0; j < t.size(); j++)
			meta[t[j]]++;
		cout << "hh" << endl;
		for (int i = 0; i < t.size(); i++)
			cout << t[i] << " : " << meta[t[i]] << endl;
		for (start = start + 1; start < s.size() && meta[s[start]] <= 0; start++)
			;
		for (end = start; end < s.size() && count > 0; end++)
		{
			if (meta[s[end]] > 0)
			{
				meta[s[end]]--;
				count--;
			}
		}
		if (!count)
		{
			len = end - start;
			if (len < minLen)
			{
				minLen = len;
				pivot  = start;
			}
			cout << pivot << " " << len << endl;
		}
		else
			break;
	}
	return minLen == s.size() + 1 ? "" : s.substr(pivot, minLen);
}

string solminWindow(string s, string t)
{
	if (s.empty() || t.empty() || s.length() < t.length())
	{
		return "";
	}

	vector<int> map(128, 0);
	int count = t.length();
	int start = 0, end = 0, minLen = INT_MAX, startIndex = 0;
	/// UPVOTE !
	for (char c : t)
	{
		map[c]++;
	}

	while (end < s.length())
	{
		if (map[s[end++]]-- > 0)
		{
			count--;
		}
		cout << "=================================================" << endl;
		cout << "count : " << count << endl;
		for (int i = 0; i < t.size(); i++)
			cout << t[i] << " : " << map[t[i]] << endl;
		cout << "=================================================" << endl;
		while (count == 0)
		{
			if (end - start < minLen)
			{
				startIndex = start;
				minLen	   = end - start;
			}

			if (map[s[start++]]++ == 0)
			{
				count++;
			}
			cout << "----------------------------------------" << endl;
			cout << "count : " << count << endl;
			for (int i = 0; i < t.size(); i++)
				cout << t[i] << " : " << map[t[i]] << endl;
			cout << "----------------------------------------" << endl;
		}
	}

	return minLen == INT_MAX ? "" : s.substr(startIndex, minLen);
}

int main(int argc, char** argv)
{
	if (argc < 3)
		return 0;
	// cout << minWindow(argv[1], argv[2]) << endl;
	cout << solminWindow(argv[1], argv[2]) << endl;
	return 0;
}
