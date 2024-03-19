#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
  typedef long long ll;
  ll totalCost(vector<int> &costs, int k, int n) {
    ll ans = 0;
    int sz = costs.size();
    int to = min(k, sz - 2 * n);
    priority_queue<int, vector<int>, greater<int>> l, r;
    int il = 0, ir = sz - 1;
    for (int i = 0; i < to; i++) {
      while (l.size() < n) {
        l.push(costs[il++]);
      }
      while (r.size() < n) {
        r.push(costs[ir--]);
      }
      int tl = l.top(), tr = r.top();
      if (tl <= tr) {
        ans += tl;
        l.pop();
      } else {
        ans += tr;
        r.pop();
      }
    }
    for (int i = il; i <= ir; i++) {
      l.push(costs[i]);
    }
    while (!r.empty()) {
      l.push(r.top());
      r.pop();
    }
    int from = max(0, to);
    for (int i = from; i < k; i++) {
      ans += l.top();
      l.pop();
    }

    return ans;
  }
};
