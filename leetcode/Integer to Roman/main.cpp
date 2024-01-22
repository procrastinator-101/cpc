#include <cstddef>
#include <string>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

string intToRoman(int num)
{
	int		i;
	int		idx;
	char	str[100] = {0};
	// int		idxes[7];
	char	romans[] = "MDCLXVI";
	int		decimals[7] = {1000, 500, 100, 50, 10, 5, 1};

	for (int j = 0, i = 0; j < 7; j += 2)
	{
		idx = num / decimals[j];
		num %= decimals[j];
		if (idx == 4)
		{
			str[i++] = romans[j];
			str[i++] = romans[j - 1];
		}
		else if (idx == 5)
			str[i++] = romans[j - 1];
		else if (idx == 9)
		{
			str[i++] = romans[j];
			str[i++] = romans[j - 2];
		}
		else
		{
			if (idx > 5)
			{
				str[i++] = romans[j - 1];
				idx -= 5;
			}
			for (int k = 0; k < idx; k++)
				str[i++] = romans[j];
		}
		// cout << str << endl;
	}
	return string(str);
}

int main()
{
	cout << intToRoman(1994) << endl;
}