#include <algorithm>
#include <stack>
#include <utility>
using namespace std;

class MinStack {
private:
  stack<pair<int, int>> stk;

public:
  MinStack() {}

  void push(int val) {
    if (stk.empty()) {
      stk.push({val, val});
    } else {
      stk.push({val, min(stk.top().second, val)});
    }
  }

  void pop() { stk.pop(); }

  int top() { return stk.top().first; }

  int getMin() { return stk.top().second; }
};
