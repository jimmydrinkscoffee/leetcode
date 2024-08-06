#include <algorithm>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  int minimumPushes(string word) {
    unordered_map<char, int> m;
    for (auto c : word) {
      m[c]++;
    }
    vector<pair<char, int>> v(m.begin(), m.end());
    sort(v.begin(), v.end(),
         [](auto a, auto b) { return a.second > b.second; });
    int n = v.size(), ans = 0;
    for (int i = 0; i < n; i++) {
      ans += (i / 8 + 1) * v[i].second;
    }
    return ans;
  }
};
