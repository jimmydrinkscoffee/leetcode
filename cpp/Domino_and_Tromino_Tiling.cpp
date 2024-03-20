class Solution {
public:
  typedef long long ll;
  int numTilings(int n) {
    if (n <= 2) {
      return n;
    }
    if (n == 3) {
      return 5;
    }
    ll t1 = 1, t2 = 2, t3 = 5, m = 1e9 + 7;
    for (int i = 4; i <= n; i++) {
      int tnext = (((t3 % m) * 2) % m + t1 % m) % m;
      t1 = t2;
      t2 = t3;
      t3 = tnext;
    }
    return t3 % m;
  }
};
