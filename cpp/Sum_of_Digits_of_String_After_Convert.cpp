#include <string>
using namespace std;

class Solution {
private:
  int cal(int n) {
    int ans = 0;
    while (n > 0) {
      ans += n % 10, n /= 10;
    }
    return ans;
  }

public:
  int getLucky(string s, int k) {
    int ans = 0;
    for (auto c : s) {
      ans += cal(c - 'a' + 1);
    }
    for (int i = 0; i < k - 1; i++) {
      ans = cal(ans);
    }
    return ans;
  }
};
