#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  int minDistance(string word1, string word2) { return optimize(word1, word2); }

private:
  int recursive(string &s1, string &s2, int i1, int i2) {
    if (i2 == s2.size()) {
      return s1.size() - i1;
    }

    if (i1 == s1.size()) {
      return s2.size() - i2;
    }

    if (s1[i1] == s2[i2]) {
      return recursive(s1, s2, i1 + 1, i2 + 1);
    }

    int del = 1 + recursive(s1, s2, i1 + 1, i2);
    int ins = 1 + recursive(s1, s2, i1, i2 + 1);
    int rep = 1 + recursive(s1, s2, i1 + 1, i2 + 1);

    return min(del, min(ins, rep));
  }

  int mem(string &s1, string &s2) {
    vector<vector<int>> v(s1.size(), vector<int>(s2.size(), -1));
    return mem_rec(v, s1, s2, 0, 0);
  }

  int mem_rec(vector<vector<int>> &v, string &s1, string &s2, int i1, int i2) {
    if (i2 == s2.size()) {
      return s1.size() - i1;
    }

    if (i1 == s1.size()) {
      return s2.size() - i2;
    }

    if (v[i1][i2] == -1) {
      if (s1[i1] == s2[i2]) {
        v[i1][i2] = mem_rec(v, s1, s2, i1 + 1, i2 + 1);
      } else {
        int del = mem_rec(v, s1, s2, i1 + 1, i2),
            ins = mem_rec(v, s1, s2, i1, i2 + 1),
            rep = mem_rec(v, s1, s2, i1 + 1, i2 + 1);
        v[i1][i2] = 1 + min(del, min(ins, rep));
      }
    }

    return v[i1][i2];
  }

  int tab(string &s1, string &s2) {
    vector<vector<int>> v(s1.size() + 1, vector<int>(s2.size() + 1, 0));
    for (int i = 0; i < s1.size(); i++) {
      v[i][s2.size()] = s1.size() - i;
    }
    for (int j = 0; j < s2.size(); j++) {
      v[s1.size()][j] = s2.size() - j;
    }
    for (int i = s1.size() - 1; i >= 0; i--) {
      for (int j = s2.size() - 1; j >= 0; j--) {
        if (s1[i] == s2[j]) {
          v[i][j] = v[i + 1][j + 1];
        } else {
          v[i][j] = 1 + min(v[i + 1][j + 1], min(v[i + 1][j], v[i][j + 1]));
        }
      }
    }
    return v[0][0];
  }

  int optimize(string &s1, string &s2) {
    int l1 = s1.size(), l2 = s2.size();
    vector<vector<int>> v(2, vector<int>(l2 + 1));
    for (int j = 0; j < l2; j++) {
      v[1][j] = l2 - j;
    }
    int cur = 1;
    for (int i = l1 - 1; i >= 0; i--) {
      cur = 1 - cur;
      v[cur][l2] = l1 - i;
      for (int j = l2 - 1; j >= 0; j--) {
        if (s1[i] == s2[j]) {
          v[cur][j] = v[1 - cur][j + 1];
        } else {
          v[cur][j] =
              1 + min(v[1 - cur][j + 1], min(v[1 - cur][j], v[cur][j + 1]));
        }
      }
    }
    return v[cur][0];
  }
};
