#include <algorithm>
#include <limits.h>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  int maxProfit(vector<int> &prices, int fee) { return tab(prices, fee); }

private:
  int recursive(vector<int> &p, int f, int l, int i, int hold, int cash) {
    if (i >= l) {
      return cash;
    }

    if (hold == 0 || p[i] <= hold) {
      return recursive(p, f, l, i + 1, p[i], cash);
    }

    int sell = recursive(p, f, l, i + 1, 0, cash + p[i] - hold - f);
    int move = recursive(p, f, l, i + 1, hold, cash);

    return max(sell, move);
  }

  int recursive_v2(vector<int> &p, int f, int l, int i, int hold) {
    if (i >= l) {
      return 0;
    }

    if (hold == 0 || p[i] <= hold) {
      return recursive_v2(p, f, l, i + 1, p[i]);
    }

    int sell = p[i] - hold - f + recursive_v2(p, f, l, i + 1, 0);
    int skip = recursive_v2(p, f, l, i + 1, hold);

    return max(sell, skip);
  }

  int mem(vector<int> &p, int f) {
    vector<vector<int>> v(p.size(), vector<int>(2, INT_MIN));
    return mem_rec(p, v, f, 0, 0);
  }

  int mem_rec(vector<int> &p, vector<vector<int>> &profits, int f, int i,
              int hold) {
    if (i >= p.size()) {
      return 0;
    }

    auto shouldBuy = hold == 0 || p[i] < hold;
    if (shouldBuy) {
      if (profits[i][shouldBuy] != INT_MIN) {
        return profits[i][shouldBuy];
      }

      return profits[i][shouldBuy] = mem_rec(p, profits, f, i + 1, p[i]);
    }

    return profits[i][shouldBuy] =
               max(p[i] - hold - f + mem_rec(p, profits, f, i + 1, 0),
                   mem_rec(p, profits, f, i + 1, hold));
  }

  int tab(vector<int> &p, int &f) {
    int vTrue = 0, vFalse = 0;
    for (int i = p.size() - 1; i >= 0; i--) {
      int nextTrue = max(-p[i] + vFalse, vTrue);
      int nextFalse = max(p[i] - f + vTrue, vFalse);
      vTrue = nextTrue, vFalse = nextFalse;
    }
    return vTrue;
  }

  int naiveSol(vector<int> &prices, int fee) {
    int l = prices.size();
    queue<pair<int, int>> q;
    q.push({prices[0], 0});
    int prevMaxProf = 0;
    for (int i = 1; i < l; i++) {
      int curMaxProf = 0;
      int sz = q.size();
      for (int j = 0; j < sz; j++) {
        pair<int, int> p = q.front();
        q.pop();

        if (p.first == 0 && p.second < prevMaxProf) {
          continue;
        }

        if (p.first >= prices[i] || p.first == 0) {
          curMaxProf = max(curMaxProf, p.second);
          q.push({prices[i], p.second});
          continue;
        }

        q.push(p);

        int prof = prices[i] - p.first - fee;
        if (prof > 0) {
          q.push({0, p.second + prof});
          curMaxProf = max(curMaxProf, p.second + prof);
        } else {
          curMaxProf = max(curMaxProf, p.second);
        }
      }
      prevMaxProf = curMaxProf;
    }

    return prevMaxProf;
  }
};
