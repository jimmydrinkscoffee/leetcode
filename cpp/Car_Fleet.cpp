#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  int carFleet(int tg, vector<int> &pos, vector<int> &spd) {
    int ans = 0;
    vector<pair<int, float>> v;
    for (int i = 0; i < pos.size(); i++) {
      v.push_back({pos[i], ((float)tg - pos[i]) / spd[i]});
    }
    sort(v.begin(), v.end());
    int i = v.size() - 1;
    while (i >= 0) {
      float t = v[i].second;
      ans++;
      while (--i >= 0 && v[i].second <= t) {
      }
    }
    return ans;
  }
};
