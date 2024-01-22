#include <cstddef>
#include <string>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

string longestPalindrome(string str)
{
	int len = str.length() * 2 + 1;

	int		i, j, c, r, l, ret;
	int		p[len];
	string	s(len, '#');

	for (i = 1, j = 0; i < s.length(); i += 2, j++)
		s[i] = str[j];
	ret = l = r = c = 0;
	p[0] = 1;
	for (i = 0; i < s.length(); i++)
	{
		p[i] = p[l + i - c];
		//check if its within a palindrome
		if (p[c] > 2)
		{
			if (p[l + i - c] / 2 == i - c && r - i == i - l)
			{
				c = i;
				for (j = p[c]; c + j < s.length() && c - j >= 0; j++)
				{
					if (s[c + j] != s[c - j])
						break;
				}
				p[c] = j;
				l = c - j;
				r = c + j;
			}
		}
	}
	for (i = 0; i < len; i++)
		cout << p[i];// << " ";
	cout << endl;
	return s;
}

int main()
{
	// string s = "aacabdkacaa";
	string s = "cbb";

	cout << longestPalindrome(s) << endl;
}