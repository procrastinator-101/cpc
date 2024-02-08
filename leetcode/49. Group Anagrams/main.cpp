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

vector<vector<string>> groupAnagrams(vector<string>& strs)
{
	int k;
	int n = strs.size();
	int visited[n];
	int occurences[n][27];
	vector<vector<string>> ret;

	bzero(visited, sizeof(visited));
	bzero(occurences, sizeof(occurences));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < strs[i].size(); j++)
			occurences[i][strs[i][j] - 'a']++;
	}
	for (int j = 0; j < 27; j++)
			cout << (char)('a' + j) << " ";
		cout << endl;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 27; j++)
			cout << occurences[i][j]++ << " ";
		cout << endl;
	}
	for (int i = 0; i < n; i++)
	{
		if (visited[i])
			continue;
		vector<string> tmp(1, strs[i]);
		for (int j = i + 1; j < n; j++)
		{
			if (strs[i].size() != strs[j].size())
				continue;
			for (k = 0; k < 27; k++)
			{
				if (occurences[i][k] != occurences[j][k])
					break;
			}
			if (k == 27)
			{
				tmp.push_back(strs[j]);
				visited[j] = 1;
			}
		}
		cout << endl
			 << "==============================================" << endl;
		for (int j = 0; j < tmp.size(); j++)
		{
			cout << tmp[j] << ", ";
		}
		cout << endl
			 << "==============================================" << endl;
		ret.push_back(tmp);
	}
	return ret;
}

int main(int argc, char** argv)
{
	char arr[][4] = { "ray", "cod", "abe", "ned", "arc", "jar", "owl", "pop", "paw",
		"sky", "yup", "fed", "jul", "woo", "ado", "why", "ben", "mys", "den", "dem",
		"fat", "you", "eon", "sui", "oct", "asp", "ago", "lea", "sow", "hus", "fee",
		"yup", "eve", "red", "flo", "ids", "tic", "pup", "hag", "ito", "zoo" };
	vector<string> strs;
	cout << sizeof(arr) / 4 << endl;
	// for (int i = 1; i < argc; i++)
	// 	strs.push_back(argv[i]);
	for (int i = 0; i < sizeof(arr) / 4; i++)
		strs.push_back(arr[i]);
	// cout << sizeof(arr) / 4 << endl;
	vector<vector<string>> ret = groupAnagrams(strs);
	for (int i = 0; i < ret.size(); i++)
	{
		for (int j = 0; j < ret[i].size(); j++)
			cout << ret[i][j] << " , ";
		cout << endl;
	}

	return 0;
}