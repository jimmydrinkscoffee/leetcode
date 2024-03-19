#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  typedef long long ll;
  vector<int> successfulPairs(vector<int> &spells, vector<int> &potions,
                              long long success) {
    vector<int> res;
    sort(potions.begin(), potions.end());
    for (auto i = 0; i < spells.size(); i++) {
      auto tg = (double)success / spells[i];
      res.push_back(biggerThan(potions, atLeast(tg), 0, potions.size() - 1));
    }
    return res;
  }

  ll atLeast(double tg) {
    auto l = tg - (ll)tg;
    return l > 0 ? (ll)tg + 1 : tg;
  }

  int biggerThan(vector<int> &p, ll tg, int l, int r) {
    while (l <= r) {
      auto pv = l + (r - l) / 2;
      if (p[pv] < tg) {
        l = pv + 1;
      } else if (p[pv] > tg) {
        r = pv - 1;
      } else {
        if (pv > 0 && p[pv - 1] == tg) {
          return biggerThan(p, tg, l, pv - 1);
        }
        return p.size() - pv;
      }
    }
    return p.size() - l;
  }
};

int main(int argc, char const *argv[]) {
  auto s = Solution();
  auto v = vector<int>{25, 19, 30, 37, 14, 30, 38, 22, 38, 38, 26, 33,
                       34, 23, 40, 28, 15, 29, 36, 39, 39, 37, 32, 38,
                       8,  17, 39, 20, 4,  39, 39, 7,  30, 35, 29, 23};
  sort(v.begin(), v.end());
  cout << s.biggerThan(v, 317 / 14 + 1, 0, v.size()) << endl;
  return 0;
}
