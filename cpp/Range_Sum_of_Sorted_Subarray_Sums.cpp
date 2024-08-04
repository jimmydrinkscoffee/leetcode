#include <algorithm>
#include <vector>
using namespace std;

#define MOD 1000000007

class Solution {
public:
  int rangeSum(vector<int> &nums, int n, int left, int right) {
    vector<int> v;
    for (int i = 0; i < n; i++) {
      int s = 0;
      for (int j = i; j < n; j++) {
        s += nums[j];
        v.push_back(s);
      }
    }
    sort(v.begin(), v.end());
    int ans = 0;
    for (int i = left - 1; i < right; i++) {
      ans = (ans + v[i] % MOD) % MOD;
    }
    return ans;
  }
};
