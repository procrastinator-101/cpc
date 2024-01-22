#include <cstddef>
#include <string>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

string longestPalindrome(string s)
{
	int		i;
	int		j;
	int		last;
	int		arr[2];
	string	ret;

	arr[0] = 0;
	arr[1] = 0;
	for (i = 0, last = 0; i < s.length();)
	{
		last = s.find(s[i], last + 1);
		if (last == s.npos)
		{
			i++;
			last = i;
			continue;
		}
		// cout << i << " " << last << " | " << s.substr(i, last - i + 1) << endl;
		if (last - i <= arr[1] - arr[0])
			continue;
		for (j = 1; i + j < last; j++)
		{
			if (s[i + j] != s[last - j])
				break;
		}
		// cout << s.substr(i, last - i + 1) << endl;
		if (i + j >= last)
		{
			arr[0] = i;
			arr[1] = last;
		}
	}
	return s.substr(arr[0], arr[1] - arr[0] + 1);
}

int main()
{
	// string s = "aacabdkacaa";
	string s = "cbbb";

	cout << longestPalindrome(s) << endl;
}