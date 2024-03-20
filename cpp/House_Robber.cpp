#include <vector>
using namespace std;

class Solution {
public:
  int rob(vector<int> &nums) {
    int l = nums.size();
    if (l == 1) {
      return nums[0];
    }

    int curMax = nums[0], robMax = max(nums[0], nums[1]), prevRob = nums[1];
    for (int i = 2; i < l; i++) {
      int cur = (curMax + nums[i]);
      robMax = max(robMax, cur);
      curMax = max(curMax, prevRob);
      prevRob = cur;
    }

    return robMax;
  }
};
