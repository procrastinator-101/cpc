#include <algorithm>
#include <cstdlib>
#include <ios>
#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <math.h>
#include <iomanip>


using namespace std;

void	logs(vector<int>& arr, vector<vector<int>>	margins) {
	cout << left << setw(3 * arr.size() + 1) << setfill('=') << "" << setfill(' ') << endl;
	for (int i = 0; i < arr.size(); i++)
		cout << setw(3) << arr[i];
	cout << endl << left << setw(3 * arr.size() + 1) << setfill('=') << "" << setfill(' ') << endl;
	for (int i = 0; i < margins.size(); i++)
	{
		for (int j = 0; j < margins[i].size(); j++)
			cout << setw(3) << margins[i][j];
		cout << endl << left << setw(3 * arr.size() + 1) << setfill('=') << "" << setfill(' ') << endl;
	}


}

int maxSumAfterPartitioning(vector<int>& arr, int k) {
	int		newAlpha;
	int		alpha;
	vector<vector<int>>	margins;
	for (int i = 0; i < arr.size(); i++)
	{
		alpha = 0;
		vector<int>	temp(arr.size(), 0);
		// cout << endl << "====================================================" << endl;
		for (int j = 0; j < k && i + j < arr.size(); j++)
		{
			newAlpha = max(arr[i + j], alpha);
			temp[i + j] = newAlpha * (j + 1) - alpha * j;
			alpha = newAlpha;
			// cout << "sum : " << sum << " arr[i + j] : " << arr[i + j] << " temp[i + j] : " << temp[i + j] << endl;
		}
		// cout << endl << "====================================================" << endl;
		margins.push_back(temp);
	}
	logs(arr, margins);
	return 0;
}

int main(int argc, char **argv) {
	// int nums[] = {1,4,1,5,7,3,6,1,9,9,3}; int k = 4;
	int nums[] = {1,15,7,9,2,5,10}; int k = 3;
  vector<int> arr(nums, nums + sizeof(nums) / sizeof(int));
  int ret = maxSumAfterPartitioning(arr, k);
  
  return 0;
}
