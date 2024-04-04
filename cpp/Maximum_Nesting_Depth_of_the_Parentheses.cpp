#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
  int maxDepth(string s) {
    int cur = 0, m = 0;
    for (char c : s) {
      if (c == '(') {
        cur++;
        m = max(m, cur);
      } else if (c == ')') {
        cur--;
      }
    }
    return m;
  }
};
