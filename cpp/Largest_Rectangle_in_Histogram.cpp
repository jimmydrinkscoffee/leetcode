#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
  int largestRectangleArea(vector<int> &h) {
    h.push_back(0);
    int ans = 0;
    stack<int> s;
    for (int i = 0; i < h.size(); i++) {
      while (!s.empty() && h[s.top()] > h[i]) {
        int top = s.top();
        s.pop();
        ans = max(ans, h[top] * (s.empty() ? i : (i - s.top() - 1)));
      }
      s.push(i);
    }
    return ans;
  }
};
