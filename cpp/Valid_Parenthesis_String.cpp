#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  bool checkValidString(string &s) {
    vector<vector<int>> v(s.length(), vector<int>(s.length(), -1));
    return mem(s, v, 0, 0);
  }

  bool rec(string &s, int acc, int i) {
    if (i == s.length()) {
      return acc == 0;
    }

    if (s[i] == '(') {
      return rec(s, acc + 1, i + 1);
    }

    if (s[i] == ')') {
      if (acc == 0) {
        return false;
      }

      return rec(s, acc - 1, i + 1);
    }

    if (acc == 0) {
      return rec(s, acc, i + 1) || rec(s, acc + 1, i + 1);
    }

    return rec(s, acc - 1, i + 1) || rec(s, acc, i + 1) ||
           rec(s, acc + 1, i + 1);
  }

  int mem(string &s, vector<vector<int>> &v, int acc, int i) {
    if (i == s.length()) {
      return acc == 0;
    }

    if (v[i][acc] != -1) {
      return v[i][acc];
    }

    if (s[i] == '(') {
      v[i][acc] = mem(s, v, acc + 1, i + 1);
    } else if (s[i] == ')') {
      if (acc == 0) {
        v[i][acc] = false;
      } else {
        v[i][acc] = mem(s, v, acc - 1, i + 1);
      }
    } else {
      if (acc == 0) {
        v[i][acc] = mem(s, v, acc, i + 1) || mem(s, v, acc + 1, i + 1);
      } else {
        v[i][acc] = mem(s, v, acc - 1, i + 1) || mem(s, v, acc, i + 1) ||
                    mem(s, v, acc + 1, i + 1);
      }
    }

    return v[i][acc];
  }
};
