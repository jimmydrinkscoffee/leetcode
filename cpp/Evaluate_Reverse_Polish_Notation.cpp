#include <cctype>
#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution {
private:
  int cal(int a, int b, string opr) {
    if (opr == "+") {
      return a + b;
    } else if (opr == "/") {
      return a / b;
    } else if (opr == "*") {
      return a * b;
    } else {
      return a - b;
    }
  }

public:
  int evalRPN(vector<string> &tokens) {
    stack<int> stk;
    for (auto const &t : tokens) {
      if (isdigit(t[t.length() - 1])) {
        stk.push(stoi(t));
      } else {
        int a = stk.top();
        stk.pop();
        int b = stk.top();
        stk.pop();
        stk.push(cal(b, a, t));
      }
    }
    return stk.top();
  }
};
