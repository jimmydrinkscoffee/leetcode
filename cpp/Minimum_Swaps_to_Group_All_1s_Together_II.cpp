#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

class Solution {
public:
  int minSwaps(vector<int> &nums) {
    int n1 = count(nums.begin(), nums.end(), 1);
    int cnt = count(nums.begin(), nums.begin() + n1, 1);
    int n = nums.size(), mx = cnt;
    for (int i = n1; i < n + n1; i++) {
      cnt += nums[i % n] - nums[(i - n1 + n) % n];
      mx = max(mx, cnt);
    }
    return n1 - mx;
  }
};
