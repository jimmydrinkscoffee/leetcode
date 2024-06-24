#include <algorithm>
#include <limits.h>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &n) {
    sort(n.begin(), n.end());
    int len = n.size();
    vector<vector<int>> ans;
    int prev = 100001;
    for (int i = 0; i < len - 2; i++) {
      if (n[i] == prev) {
        continue;
      }
      prev = n[i];
      int l = i + 1, r = len - 1, p = 100001;
      while (l < r) {
        if (n[l] + n[r] > -n[i]) {
          r--;
        } else if (n[l] + n[r] < -n[i]) {
          l++;
        } else {
          if (n[l] != p) {
            ans.push_back({n[i], n[l], n[r]});
            p = n[l];
          }
          l++, r--;
        }
      }
    }
    return ans;
  }
};
