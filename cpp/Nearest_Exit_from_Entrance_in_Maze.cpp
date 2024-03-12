#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
  struct Step {
    int x, y, dist;
  };

  bool isValid(vector<vector<char>> &maze, vector<vector<bool>> &v, int i,
               int j, int m, int n) {
    return i >= 0 and i < n and j >= 0 and j < m and !v[i][j] and
           maze[i][j] == '.';
  }

  int nearestExit(vector<vector<char>> &maze, vector<int> &entrance) {
    int n = maze.size();
    int m = maze[0].size();
    vector<vector<bool>> v(n, vector<bool>(m, false));

    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};
    int x = entrance[0], y = entrance[1];

    queue<Step> q;
    q.push({x, y, 0});
    v[x][y] = true;

    while (!q.empty()) {
      Step l = q.front();
      q.pop();
      int i = l.x, j = l.y, d = l.dist;
      if (((i == 0 || i == n - 1) || (j == 0 || j == m - 1)) and
          maze[i][j] == '.') {
        if (!(i == x and j == y)) {
          return d;
        }
      }

      for (int k = 0; k < 4; k++) {
        int ni = i + dx[k], nj = j + dy[k];
        if (isValid(maze, v, ni, nj, m, n)) {
          v[ni][nj] = true;
          q.push({ni, nj, d + 1});
        }
      }
    }

    return -1;
  }
};
