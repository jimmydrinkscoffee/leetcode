#include <algorithm>
#include <vector>
using namespace std;

bool ascFirst(vector<int> &u, vector<int> &v) { return u[0] < v[0]; }

class Solution {
public:
  int eraseOverlapIntervals(vector<vector<int>> &v) {
    sort(v.begin(), v.end(), ascFirst);
    int cur = 0, l = v.size(), res = 0;
    for (int i = 1; i < l; i++) {
      if (v[i][0] >= v[cur][1]) {
        cur = i;
        continue;
      }

      res++;
      if (v[i][1] < v[cur][1]) {
        cur = i;
      }
    }

    return res;
  }
};
