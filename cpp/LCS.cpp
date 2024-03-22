#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  int longestCommonSubsequence(string &s1, string &s2) {
    return optimizeSpace(s1, s2);
  }

private:
  int recursive(string s1, string s2, int l1, int l2, int i1, int i2) {
    if (i1 == l1 || i2 == l2) {
      return 0;
    }

    if (s1[i1] == s2[i2]) {
      return 1 + recursive(s1, s2, l1, l2, i1 + 1, i2 + 1);
    }

    return max(recursive(s1, s2, l1, l2, i1 + 1, i2),
               recursive(s1, s2, l1, l2, i1, i2 + 1));
  }

  int memoization(string s1, string s2) {
    int l1 = s1.length(), l2 = s2.length();
    vector<vector<int>> v(l1, vector<int>(l2, -1));
    return memoizationRec(s1, s2, s1.length(), s2.length(), 0, 0, v);
  }

  int memoizationRec(string s1, string s2, int l1, int l2, int i1, int i2,
                     vector<vector<int>> &v) {
    if (i1 >= l1 || i2 >= l2) {
      return 0;
    }
    if (v[i1][i2] < 0) {
      if (s1[i1] == s2[i2]) {
        v[i1][i2] = 1 + memoizationRec(s1, s2, l1, l2, i1 + 1, i2 + 1, v);
      } else {
        v[i1][i2] = max(memoizationRec(s1, s2, l1, l2, i1 + 1, i2, v),
                        memoizationRec(s1, s2, l1, l2, i1, i2 + 1, v));
      }
    }
    return v[i1][i2];
  }

  int iterativeTabulation(string s1, string s2) {
    int l1 = s1.length(), l2 = s2.length();
    vector<vector<int>> v(l1 + 1, vector<int>(l2 + 1, 0));
    for (int i = l1 - 1; i >= 0; i--) {
      for (int j = l2 - 1; j >= 0; j--) {
        if (s1[i] == s2[j]) {
          v[i][j] = 1 + v[i + 1][j + 1];
        } else {
          v[i][j] = max(v[i][j + 1], v[i + 1][j]);
        }
      }
    }
    return v[0][0];
  }

  int optimizeSpace(string &s1, string &s2) {
    int l1 = s1.length(), l2 = s2.length();
    int cur[l2 + 1], prev[l2 + 1];
    memset(cur, 0, sizeof(cur));
    memset(prev, 0, sizeof(prev));
    for (int i = l1 - 1; i >= 0; i--) {
      for (int j = l2 - 1; j >= 0; j--) {
        if (s1[i] == s2[j]) {
          cur[j] = 1 + prev[j + 1];
        } else {
          cur[j] = max(prev[j], cur[j + 1]);
        }
      }
      memcpy(prev, cur, sizeof(cur));
    }
    return prev[0];
  }
};
