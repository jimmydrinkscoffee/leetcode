#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

class Solution {
public:
  int minEatingSpeed(vector<int> &piles, int h) {
    int l = 1, r = *max_element(piles.begin(), piles.end());
    int res = 0;
    while (l <= r) {
      int pv = l + (r - l) / 2;
      long long t = 0;
      for (int p : piles) {
        t += ceil((double)p / pv);
      }
      if (t <= h) {
        r = pv - 1;
        res = pv;
      } else {
        l = pv + 1;
      }
    }

    return res;
  }
};
