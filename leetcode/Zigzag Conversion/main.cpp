#include <cstddef>
#include <string>
#include <iostream>

using namespace std;

string convert(string s, int numRows)
{
	string	ret = s;

	int	zig = numRows - 2 > 0 ? numRows - 2 : 0;
	int	comboSize = numRows + zig;
	int	nbCombo = s.length() / comboSize;
	int	lastComboSize = s.length() % comboSize;
	int lastRowSize = lastComboSize > numRows ? numRows : lastComboSize;
	int	lastzigzagSize = lastComboSize - lastRowSize;

	cout << zig << " " << comboSize << " " << nbCombo << " " << lastComboSize << endl;
	for (int i = 0, j = 0; i < numRows && j < s.length(); i++)
	{
		for (int k = 0; k < nbCombo; k++)
		{
			ret[j++] = s[k * comboSize + i];
			cout << k * comboSize + i << " ";
			if (i != 0 && i != numRows - 1)
			{
				ret[j++] = s[(k + 1) * comboSize - i];
				cout << (k + 1) * comboSize - i << "z ";
			}
		}
		if (lastRowSize > 0)
		{
			ret[j++] = s[nbCombo * comboSize + i];
			cout << nbCombo * comboSize + i << "l ";
			lastRowSize--;
		}
		if (i != 0 && i != numRows - 1 && lastzigzagSize > zig - i)
		{
			ret[j++] = s[(nbCombo + 1) * comboSize - i];
			cout << (nbCombo + 1) * comboSize - i << "lz ";
			lastzigzagSize--;
		}
	}
	cout << endl;
	return ret;
}
int main()
{
	string s = "abc";

	cout << convert(s, 3) << endl;
}