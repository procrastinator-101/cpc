#include <cstdlib>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int evalOperation(int a, int b, string &operand) {
  if (operand == "*")
    return a * b;
  if (operand == "-")
    return a - b;
  if (operand == "+")
    return a + b;
  return a / b;
}

int evalRPN(vector<string> &tokens) {
  int ops[2];
  stack<int> operands;
  string operators("+-/*");

  for (int i = 0; i < tokens.size(); i++) {
    cout << "token : " << tokens[i] << endl;
    if (operators.find(tokens[i]) == string::npos) {
      operands.push(atoi(tokens[i].c_str()));
    } else {
      ops[1] = operands.top();
      operands.pop();
      ops[0] = operands.top();
      operands.pop();
      cout << ops[0] << " " << tokens[i] << " " << ops[1] << " = "
           << evalOperation(ops[0], ops[1], tokens[i]) << endl;
      operands.push(evalOperation(ops[0], ops[1], tokens[i]));
    }
  }
  return operands.top();
}

int main(int argc, char **argv) {
  vector<string> tokens;

  for (int i = 1; i < argc; i++) {
    tokens.push_back(argv[i]);
  }
  cout << evalRPN(tokens) << endl;
  return 0;
}
