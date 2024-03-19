#include <queue>
#include <vector>
using namespace std;

class Solution {
private:
  int n, m;

  bool isValid(vector<vector<int>> &grid, int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m && grid[i][j] == 1;
  }

public:
  int orangesRotting(vector<vector<int>> &grid) {
    n = grid.size(), m = grid[0].size();
    queue<pair<int, int>> q;
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};
    int cnt = 0;
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[i].size(); j++) {
        cnt += grid[i][j] > 0;
        if (grid[i][j] == 2) {
          q.push(make_pair(i, j));
        }
      }
    }
    cnt -= q.size();
    if (cnt == 0) {
      return 0;
    }
    int step = 1;
    while (q.size() > 0) {
      int l = q.size();
      for (int x = 0; x < l; x++) {
        auto pos = q.front();
        q.pop();

        for (int k = 0; k < 4; k++) {
          int i = pos.first + dx[k], j = pos.second + dy[k];
          if (isValid(grid, i, j)) {
            grid[i][j] = 2;
            cnt--;
            q.push(make_pair(i, j));
          }
        }
      }

      if (cnt == 0) {
        return step;
      }
      step++;
    }

    return cnt == 0 ? step : -1;
  }
};
