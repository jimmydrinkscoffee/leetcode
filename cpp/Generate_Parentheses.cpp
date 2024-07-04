#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  vector<string> generateParenthesis(int n) {
    vector<string> ans;
    recur(ans, "", n, n);
    return ans;
  }

  void recur(vector<string> &v, string cur, int l, int r) {
    if (l == 0) {
      for (int i = 0; i < r; i++) {
        cur += ")";
      }
      v.push_back(cur);
      return;
    }
    recur(v, cur + "(", l - 1, r);
    if (l < r) {
      recur(v, cur + ")", l, r - 1);
    }
  }
};
