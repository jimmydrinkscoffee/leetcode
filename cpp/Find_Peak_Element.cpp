#include <vector>
using namespace std;

class Solution {
public:
  int findPeakElement(vector<int> &nums) {
    int l = nums.size();
    if (l == 1) {
      return 0;
    }
    return go(nums, l, 0);
  }

  int go(vector<int> &v, int l, int i) {
    if (i == 0) {
      if (v[i + 1] < v[i]) {
        return 0;
      }
      return go(v, l, 1);
    }
    if (i == l - 1) {
      if (v[l - 2] < v[i]) {
        return i;
      }
      return go(v, l, l - 1);
    }
    if (v[i - 1] < v[i] && v[i + 1] < v[i]) {
      return i;
    }
    if (v[i - 1] > v[i]) {
      return go(v, l, i - 1);
    }
    return go(v, l, i + 1);
  }
};
