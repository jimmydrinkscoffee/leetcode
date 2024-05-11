#include <algorithm>
#include <array>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
  double mincostToHireWorkers(vector<int> &q, vector<int> &w, int k) {
    const auto l = q.size();
    vector<array<double, 2>> v(l);
    for (auto i = 0; i < l; i++) {
      v[i] = {(double)w[i] / q[i], (double)q[i]};
    }
    sort(v.begin(), v.end());
    auto qlt = 0;
    priority_queue<int> pq;
    for (auto i = 0; i < k; i++) {
      qlt += v[i][1];
      pq.push(v[i][1]);
    }
    double ans = qlt * v[k - 1][0];
    for (auto i = k; i < l; i++) {
      pq.push(v[i][1]);
      qlt += v[i][1] - pq.top();
      pq.pop();
      ans = min(ans, qlt * v[i][0]);
    }
    return ans;
  }
};
