#include <algorithm>
#include <vector>
using namespace std;

bool ascFirst(vector<int> &u, vector<int> &v) { return u[0] < v[0]; }

class Solution {
public:
  int findMinArrowShots(vector<vector<int>> &p) {
    sort(p.begin(), p.end(), ascFirst);
    int res = 1, b = p[0][0], e = p[0][1], l = p.size();
    for (int i = 1; i < l; i++) {
      if (p[i][0] >= e) {
        res++;
        b = p[i][0], e = p[i][1];
      }

      e = min(e, p[i][1]);
    }

    return res;
  }
};
