#include <vector>
using namespace std;

class Solution {
public:
  vector<int> countBits(int n) {
    vector<int> res{0};
    if (n == 0) {
      return res;
    }
    res.push_back(1);
    if (n == 1) {
      return res;
    }
    res.push_back(1);
    if (n == 2) {
      return res;
    }
    res.push_back(2);
    int next = 4, i = 4;
    while (i <= n) {
      int tg = i + next / 2;
      for (; i < tg && i <= n; i++) {
        res.push_back(res[i - next / 2]);
      }
      tg += next / 2;
      for (; i < tg && i <= n; i++) {
        res.push_back(res[i - next / 2] + 1);
      }
      i = tg, next *= 2;
    }
    return res;
  }
};
