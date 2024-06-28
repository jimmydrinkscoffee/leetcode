#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
  int trap(vector<int> &h) {
    if (h.size() <= 0) {
      return 0;
    }
    int l = 0, r = h.size() - 1;
    int ml = h[l], mr = h[r], ans = 0;
    while (l < r) {
      if (ml < mr) {
        l++;
        ml = max(ml, h[l]);
        ans += ml - h[l];
      } else {
        r--;
        mr = max(mr, h[r]);
        ans += mr - h[r];
      }
    }
    return ans;
  }
};
