#include <string>
using namespace std;

class Solution {
public:
  string minRemoveToMakeValid(string &s) {
    int cnt = 0;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == '(') {
        cnt++;
      } else if (s[i] == ')') {
        cnt--;
      }
      if (cnt < 0) {
        s.erase(i, 1);
        cnt = 0, i--;
      }
    }
    int i = s.length() - 1;
    while (i >= 0 && cnt > 0) {
      while (i >= 0 && s[i] != '(') {
        i--;
      }
      if (i < 0) {
        return s;
      }
      s.erase(i, 1);
      cnt--;
    }
    return s;
  }
};
