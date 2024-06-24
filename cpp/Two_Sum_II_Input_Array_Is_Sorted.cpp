#include <string>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int> &n, int tg) {
    int len = n.size();
    int l = 0, r = len - 1;
    while (l < r) {
      if (n[l] + n[r] > tg) {
        r--;
      } else if (n[l] + n[r] < tg) {
        l++;
      } else {
        return {l + 1, r + 1};
      }
    }
    return {l + 1, r + 1};
  }
};
