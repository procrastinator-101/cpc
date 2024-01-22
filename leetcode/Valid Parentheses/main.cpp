#include <cmath>
#include <cstddef>
#include <string>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;


bool    checkBracket(string& s, int *idx)
{
	if (s.length() == *idx + 1)
		return 1;
	char	left = s[*idx];
	(*idx)++;
	bool	ret = checkBracket(s, idx);
	cout << left << " " << ret << " " << *idx << endl;
	if (!ret)
		return 0;
	char	right = s[*idx];
	(*idx)++;
	cout << left << " " << right << " " << ret << " " << *idx << endl;
	if (left == '(' && right == ')')
		return 1;
	if (left == '{' && right == '}')
		return 1;
	if (left == '[' && right == ']')
		return 1;
	return 0;
}

bool	isValid(string s)
{
	stack<char>	brackets;

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '(' || s[i] == '{' || s[i] == '[')
			brackets.push(s[i]);
		else if (s[i] == ')' || s[i] == '}' || s[i] == ']')
		{
			if (brackets.empty())
				return false;
			if (brackets.top() == '(' && s[i] == ')')
				brackets.pop();
			else if (brackets.top() == '[' && s[i] == ']')
				brackets.pop();
			else if (brackets.top() == '{' && s[i] == '}')
				brackets.pop();
			else
				return false;
		}
	}
	return brackets.empty();
}

int main()
{
	cout << isValid("[({()})]") << endl;
}