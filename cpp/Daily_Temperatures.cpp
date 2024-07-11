#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> dailyTemperatures(vector<int> &t) {
    vector<int> ans(t.size());
    stack<int> s;
    for (int i = 0; i < t.size(); i++) {
      while (!s.empty() && t[i] > t[s.top()]) {
        ans[s.top()] = i - s.top();
        s.pop();
      }
      s.push(i);
    }
    return ans;
  }
};
