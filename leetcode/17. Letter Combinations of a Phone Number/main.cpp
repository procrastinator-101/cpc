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

void generateCombination(vector<string>& combinations, string letters[], string& digits, int idx, string sequence)
{
	if (idx >= digits.size())
	{
		if (!sequence.empty())
			combinations.push_back(sequence);
		return;
	}
	int letter = atoi(digits.substr(idx, 1).c_str()) - 2;
	// cout << letter << endl;
	for (int i = 0; i < letters[letter].size(); i++)
	{
		sequence.push_back(letters[letter][i]);
		generateCombination(combinations, letters, digits, idx + 1, sequence);
		sequence.pop_back();
	}
}

vector<string> letterCombinations(string digits)
{
	vector<string> ret;
	string letters[] = { "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

	generateCombination(ret, letters, digits, 0, "");
	return ret;
}

int main(int argc, char** argv)
{
	vector<string> ret = letterCombinations("23");
	cout << endl << "========================================" << endl;
	for (int i = 0; i < ret.size(); i++)
		cout << ret[i] << endl;
	cout << endl << "========================================" << endl;
	return 0;
}