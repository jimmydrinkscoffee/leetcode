class Solution {
public:
  int minFlips(int a, int b, int c) {
    int res = 0;
    for (int i = 0; i < 32; i++) {
      res += c % 2 == 0 ? (a % 2 + b % 2) : (a % 2 == 0 && b % 2 == 0);
      a /= 2, b /= 2, c /= 2;
    }

    return res;
  }
};
