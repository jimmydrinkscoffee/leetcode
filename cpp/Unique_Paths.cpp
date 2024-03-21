#include <vector>
using namespace std;

class Solution {
public:
  int uniquePaths(int m, int n) { return optimize(m, n); }

  int myObservation(int m, int n) {
    vector<vector<int>> v(m, vector<int>(n, 1));
    for (int i = 1; i < m; i++) {
      for (int j = 1; j < n; j++) {
        v[i][j] = v[i - 1][j] + v[i][j - 1];
      }
    }

    return v[m - 1][n - 1];
  }

  int optimize(int m, int n) {
    vector<int> v(n, 1);
    for (int i = 1; i < m; i++) {
      for (int j = 1; j < n; j++)
        v[j] += v[j - 1];
    }

    return v[n - 1];
  }
};
