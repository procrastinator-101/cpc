#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

vector<int> dailyTemperatures(vector<int> &temperatures) {
  vector<int> closestTemp(101, 0);
  vector<int> ret(temperatures.size(), 0);

  for (int i = temperatures.size() - 1; i >= 0; i--) {
	ret[i] = closestTemp[temperatures[i]] - (closestTemp[temperatures[i]] ? i : 0);
    for (int j = 30; j < temperatures[i]; j++)
      closestTemp[j] = i;
  }
  return ret;
}

int main(int argc, char **argv) {
//   int temps[] = {73, 74, 75, 71, 69, 72, 76, 73};
  int temps[] = {30,40,50,60};

  vector<int> temperatures(temps, temps + sizeof(temps) / sizeof(int));
  vector<int> ret = dailyTemperatures(temperatures);

  cout << "-----------------------------------------------------" << endl;
  for (int i = 0; i < ret.size(); i++)
    cout << ret[i] << ",";
  cout << endl
       << "-----------------------------------------------------" << endl;
  return 0;
}
