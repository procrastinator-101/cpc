#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

int generateNumber(int seed, int nbDigits) {
	int ret = seed;
	for (int i = 0; i < nbDigits; i++, seed++)
		ret = ret * 10 + seed + 1;
	return ret;
}

vector<int> sequentialDigits(int low, int high) {
	int	seed;
	int number;
	int tens[] = {1, 10, 100 ,1000, 10000, 100000, 1000000 , 10000000 , 100000000, 1000000000};
	int minDigits = log10(low);
	int maxDigits = log10(high);
	vector<int>	ret;;

	cout << "-----------------------------------------------------" << endl;
	cout << minDigits << " || " << maxDigits << " || " << endl;
	cout << endl << "-----------------------------------------------------" << endl;
	// return ret;
	for (int i = minDigits; i <= maxDigits; i++)
	{
		seed = low / tens[i];
		for (int j = seed > 0 ? seed : 1; j < 10 - i; j++)
		{
			number = generateNumber(j, i);
			cout << "-----------------------------------------------------" << endl;
			cout << j << " || " << number << " || " << endl;
			cout << endl << "-----------------------------------------------------" << endl;
			if (number > high)
				break;
			else if (number < low)
				continue;
			ret.push_back(number);
		}
	}
	return ret;
}

int main(int argc, char **argv) {
//   int low = 58;
//   int high = 155;
  int low = 1000;
  int high = 13000;

  vector<int> ret = sequentialDigits(low, high);
  cout << "-----------------------------------------------------" << endl;
  for (int i = 0; i < ret.size(); i++) {
    cout << ret[i] << endl;
  }
  cout << endl
       << "-----------------------------------------------------" << endl;
  return 0;
}
