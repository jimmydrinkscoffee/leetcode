#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  int minDistance(string word1, string word2) { return mem(word1, word2); }

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
};
