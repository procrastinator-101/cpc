#include <iostream>

using namespace std;

int main()
{
	int t, i, j, offset, k;
	char str[10];

	str[9] = 0;
	cin >> t;
	while (t--)
	{
		i = 0;
		for (; i < 3; i++)
		{
			j = 0;
			for (; j < 3; j++, offset += 3)
			{
				k = 1;
				offset = i + j * 3;
				scanf("%s", str);
				for (; k < 10 && str[offset] == 48 + k; k++);
				str[offset] = 48 + k;
				cout << str << endl;
			}
		}
	}
	return (0);
}
