#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> divideArray(vector<int> &nums, int k) {
  int size = nums.size();
  vector<vector<int>> ret(size / 3);
  sort(nums.begin(), nums.end());
  for (int i = 0; i < size; i += 3) {
    vector<int> arr(nums.begin() + i, nums.begin() + i + 3);
    if (arr[2] - arr[0] > k)
      return vector<vector<int>>();
    ret[i / 3] = arr;
  }
  return ret;
}

int main(int argc, char **argv) {
  int tmp[] = {1, 3, 3, 2, 7, 3};
  int k = 3;
  //   int tmp[] = {1,3,4,8,7,9,3,5,1}; int k = 2;

  vector<int> nums(tmp, tmp + sizeof(tmp) / sizeof(int));

  vector<vector<int>> ret = divideArray(nums, k);
  cout << "-----------------------------------------------------" << endl;
  for (int i = 0; i < ret.size(); i++) {
    cout << "[ ";
    for (int j = 0; j < ret[i].size(); j++)
      cout << ret[i][j] << " , ";
    cout << " ]" << endl;
  }
  cout << endl
       << "-----------------------------------------------------" << endl;
  return 0;
}
