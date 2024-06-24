#include <string>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  bool isPalindrome(string &s) { return sol2(s); }

  bool sol2(string &s) {
    int len = s.length();
    int l = 0, r = len - 1;
    while (l < r) {
      if (!isalnum(s[l])) {
        l++;
      } else if (!isalnum(s[r])) {
        r--;
      } else if (tolower(s[l]) != tolower(s[r])) {
        return false;
      } else {
        l++, r--;
      }
    }
    return true;
  }

  bool sol1(string &s) {
    int i = 0, j = s.length() - 1;
    while (i < j) {
      while (i <= s.length() - 1 && !isalnum(s[i])) {
        i++;
      }
      while (j >= 0 && !isalnum(s[j])) {
        j--;
      }
      if (i >= s.length() || j < 0) {
        return true;
      }
      if (tolower(s[i]) != tolower(s[j])) {
        return false;
      }
      i++, j--;
    }
    return true;
  }
};
