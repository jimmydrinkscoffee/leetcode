#include <string>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  int longestConsecutive(vector<int> &nums) {
    unordered_set<int> s;
    for (int n : nums) {
      s.insert(n);
    }
    int res = 0;
    for (int n : nums) {
      if (s.find(n) == s.end()) {
        continue;
      }
      int cnt = 1, sml = n - 1, lar = n + 1;
      while (s.find(sml) != s.end()) {
        s.erase(sml);
        cnt++, sml--;
      }
      while (s.find(lar) != s.end()) {
        s.erase(lar);
        cnt++, lar++;
      }
      res = max(res, cnt);
    }
    return res;
  }
};
