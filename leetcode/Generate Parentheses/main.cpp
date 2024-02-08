#include <cstdlib>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

void addSequence(vector<int> &path, vector<string> &parenthesis) {
  string sequence;
  for (int i = 0; i < path.size(); i++)
    sequence.push_back(path[i] == 1 ? '(' : ')');
  parenthesis.push_back(sequence);
}

void sequenceGenerator(int left, int idx, int n, vector<int> &path,
                       vector<string> &parenthesis) {
  if (idx == path.size()) {
    addSequence(path, parenthesis);
    return;
  }
//   cout << left << " " << idx << " ";
//   for (int i = 0; i < path.size(); i++)
//     cout << path[i];
//   cout << endl;
  if (path.size() >= 2 * left + 1) {
    path[idx] = 1;
    sequenceGenerator(left + 1, idx + 1, n, path, parenthesis);
  }
  if (2 * left - idx >= 1) {
    path[idx] = -1;
    sequenceGenerator(left, idx + 1, n, path, parenthesis);
  }
}

vector<string> generateParenthesis(int n) {
  vector<int> path(n * 2, 0);
  vector<string> ret;
  sequenceGenerator(0, 0, n, path, ret);
  return ret;
}

int main() {
  vector<string> ret;

  ret = generateParenthesis(6);
  for (int i = 0; i < ret.size(); i++)
    cout << ret[i] << endl;
  return 0;
}