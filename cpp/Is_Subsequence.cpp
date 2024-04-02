#include <ios>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
  bool isSubsequence(string s, string t) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i = 0, j = 0;
    while (i < s.length() && j < t.length()) {
      while (j < t.length() && t[j] != s[i]) {
        j++;
      }
      if (j >= t.length() || t[j] != s[i]) {
        return false;
      }
      i++, j++;
    }
    return i == s.length();
  }
};
