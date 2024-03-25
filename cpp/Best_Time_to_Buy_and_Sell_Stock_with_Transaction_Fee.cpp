#include <algorithm>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  int maxProfit(vector<int> &prices, int fee) {
    return recursive(prices, fee, prices.size(), 0, 0, 0);
  }

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

  int memoization(vector<int> &p, int f, int l, int i, int hold, int cash) {}

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
