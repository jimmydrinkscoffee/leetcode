#include <queue>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  int nearestExit(vector<vector<char>> &maze, vector<int> &entrance) {
    vector<vector<bool>> v;
    v.resize(maze.size(), vector<bool>(maze[0].size(), false));
    queue<pair<int, int>> q;
    v[entrance[0]][entrance[1]] = true;
    q.push(make_pair(entrance[0], entrance[1]));
    int l = q.size(), step = 1;
    while (l > 0) {
      for (auto i = 0; i < l; i++) {
        auto pos = q.front();
        q.pop();

        vector<pair<int, int>> nexts = {
            make_pair(pos.first + 1, pos.second),
            make_pair(pos.first - 1, pos.second),
            make_pair(pos.first, pos.second + 1),
            make_pair(pos.first, pos.second - 1),
        };

        for (auto p : nexts) {
          int x = p.first, y = p.second;
          if (!isValid(maze, x, y) || v[x][y]) {
            continue;
          }

          if (isExit(maze, x, y)) {
            return step;
          }

          v[x][y] = true;
          q.push(make_pair(x, y));
        }
      }
      step++;
      l = q.size();
    }

    return -1;
  }

private:
  bool isExit(vector<vector<char>> maze, int x, int y) {
    return x == 0 || y == maze[0].size() - 1 || y == 0 || x == maze.size() - 1;
  }

  bool isValid(vector<vector<char>> maze, int x, int y) {
    return x >= 0 && y >= 0 && y < maze[0].size() && x < maze.size() &&
           maze[x][y] == '.';
  }
};
