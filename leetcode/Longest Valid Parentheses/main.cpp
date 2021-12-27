#include <string>
#include <iostream>

using namespace std;

int longestValidParentheses(string s)
{
	int ret;
	int arr[s.size()];

	ret = 0;
	arr[0] = 0;
	for (int i = 1; i < s.size(); i++)
	{
		if (s[i] == '(')
			arr[i] = 0;
		else
		{
			if (s[i - 1] == '(')
				arr[i] = 2 + (i < 2 ? 0 : arr[i - 2]);
			else if (i - arr[i - 1] >= 1 && s[i - arr[i - 1] - 1] == '(')
				arr[i] = 2 + arr[i - 1] + (i - arr[i - 1] >= 2 ? arr[i - arr[i - 1] - 2] : 0);
			else
				arr[i] = 0;
		}
		if (ret < arr[i])
			ret = arr[i];
	}
	return ret;
}

int main()
{
	string str = "(()())";
	cout << longestValidParentheses(str) << endl;
	return 0;
}