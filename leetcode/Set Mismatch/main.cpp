#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;
vector<int> findErrorNums(vector<int> &nums);

int main() {
//   int test1[] = {1, 2, 2, 4};
//   int test1[] = {1,1};
  int test1[] = {3, 2, 3, 4, 6, 5};
  int test2[] = {1, 5, 3, 2, 2, 7, 6, 4, 8, 9};

  vector<int> v1(test1, test1 + sizeof(test1) / sizeof(int));
  vector<int> v2(test2, test2 + sizeof(test2) / sizeof(int));

  vector<int> ret1 = findErrorNums(v1);
  for (int i = 0; i < ret1.size(); i++)
    cout << ret1[i] << " ";
  cout << endl;

  vector<int> ret2 = findErrorNums(v2);
  for (int i = 0; i < ret2.size(); i++)
    cout << ret2[i] << " ";
  cout << endl;
}

// void log(int num, int src, int offset, int repeated, int missing) {
//   cout << "nums : " << num << " src : " << src << " | offset : " << offset
//        << " | repeated : " << repeated << " missing : " << missing << endl;
// }
void log(int num, int src, int repeated, int missing) {
  cout << "nums : " << num << " src : " << src << " | repeated : " << repeated
       << " missing : " << missing << endl;
}

vector<int> findErrorNums(vector<int> &nums) {
  vector<int> ret(2, nums.size());

  sort(nums.begin(), nums.end());
  cout << endl << "--------------------------------" << endl;
  for (int i = 0; i < nums.size(); i++)
    cout << nums[i] << " ";
  cout << endl;
  for (int i = 1; i < nums.size() + 1; i++)
    cout << i << " ";
  cout << endl << "--------------------------------" << endl;
  for (int i = 0, j = 1; i < nums.size() && j < nums.size() + 1;) {
    log(nums[i], j, ret[0], ret[1]);
    if (nums[i] < j) {
      ret[0] = nums[i];
      i++;
    } else if (nums[i] > j) {
      ret[1] = j;
      j++;
    } else {
      i++;
      j++;
    }
	if (ret[0] != nums.size() && ret[1] != nums.size())
	break;
  }
  log(0, 0, ret[0], ret[1]);
  return ret;
}