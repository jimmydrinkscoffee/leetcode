#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
  bool isIsomorphic(string s, string t) {
    unordered_map<char, char> m1, m2;
    for (int i = s.length() - 1; i >= 0; i--) {
      if (m1.find(s[i]) == m1.end() && m2.find(t[i]) == m2.end()) {
        m1[s[i]] = t[i];
        m2[t[i]] = s[i];
      } else if (m1[s[i]] != m2[t[i]]) {
        return false;
      }
    }

    return true;
  }
};
