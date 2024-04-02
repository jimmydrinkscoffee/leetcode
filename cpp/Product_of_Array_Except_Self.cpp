#include <vector>
using namespace std;

class Solution {
public:
  vector<int> productExceptSelf(vector<int> &n) {
    int l = n.size();
    vector<int> v(l, 1);
    for (int i = 1; i < l; i++) {
      v[i] = v[i - 1] * n[i - 1];
    }
    int next = 1;
    for (int i = l - 2; i >= 0; i--) {
      next *= n[i + 1];
      v[i] = v[i] * next;
    }
    return v;
  }
};
