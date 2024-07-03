class Solution {
private:
  inline int all(int n) { return (n * (n + 1)) / 2; }

public:
  int maxHeightOfTriangle(int r, int b) {
    int n = 0;
    while (true) {
      n++;
      int evens = 2 * all(n / 2);
      int odds = all(n) - evens;
      if ((evens <= r && odds <= b) || (evens <= b && odds <= r)) {
        continue;
      }
      return n - 1;
    }
  }
};
