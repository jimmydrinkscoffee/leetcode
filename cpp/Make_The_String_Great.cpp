#include <string>
using namespace std;

class Solution {
public:
  string makeGood(string &s) {
    string ans;
    for (int i = 0; i < s.length(); i++) {
      if (!ans.empty() && abs(ans[ans.size() - 1] - s[i]) == 32) {
        ans.pop_back();
      } else {
        ans.push_back(s[i]);
      }
    }

    return ans;
  }
};
