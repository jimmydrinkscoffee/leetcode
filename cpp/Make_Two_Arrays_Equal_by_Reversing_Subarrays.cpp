#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  bool canBeEqual(vector<int> &target, vector<int> &arr) {
    unordered_map<int, int> m;
    int n = target.size();
    for (int i = 0; i < n; i++) {
      m[target[i]]--, m[arr[i]]++;
    }
    for (auto p : m) {
      if (p.second != 0) {
        return false;
      }
    }
    return true;
  }
};
