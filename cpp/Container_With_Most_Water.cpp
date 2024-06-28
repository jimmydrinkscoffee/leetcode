#include <algorithm>
#include <limits.h>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  int maxArea(vector<int> &h) {
    int i = 0, j = h.size() - 1, ans = 0;
    while (i < j) {
      ans = max(ans, min(h[i], h[j]) * (j - i));
      if (h[i] < h[j]) {
        i++;
      } else {
        j--;
      }
    }
    return ans;
  }
};
