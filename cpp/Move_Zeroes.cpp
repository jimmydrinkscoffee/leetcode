#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  void moveZeroes(vector<int> &n) {
    int l = 0;
    while (l < n.size() && n[l] != 0) {
      l++;
    }

    for (int i = l + 1; i < n.size(); i++) {
      if (n[i] != 0) {
        swap(n[l], n[i]);
        l++;
      }
    }
  }

  void myBad(vector<int> &n) {
    int z = 0, i = n.size() - 1;
    while (i >= 0) {
      if (n[i] == 0) {
        n.erase(n.begin() + i);
        z++;
      }
    }
    while (i-- > 0) {
      n.push_back(0);
    }
  }
};
